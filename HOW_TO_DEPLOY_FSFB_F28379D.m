%% HOW_TO_DEPLOY_FSFB_F28379D.m
%  Step-by-step instructions to deploy Full State Feedback + Integral
%  PMSM speed controller on F28379D LaunchPad + DRV8305 inverter.
%
%  This is a GUIDE script -- read the comments, run sections manually.

%% =========================================================
%  STEP 1 -- Generate controller gains and build Simulink model
%% =========================================================
%  Run the parameter script to compute Kx, Ki gains:
%
%    >> mcb_pmsm_fsfb_f28379d_param
%
%  Then build the Simulink model:
%
%    >> build_mcb_pmsm_fsfb_f28379d
%
%  This creates  mcb_pmsm_fsfb_f28379d.slx  in the current folder.

%% =========================================================
%  STEP 2 -- Verify in simulation before hardware
%% =========================================================
%  Open the model and run in NORMAL simulation mode first.
%  The PMSM_Plant subsystem provides a continuous state-space
%  plant so you can see the closed-loop step response.
%
%  Check:
%    - Speed ramps from 0 to Speed_rated (~300 rad/s) without oscillation
%    - Id stays near 0 (MTPA condition)
%    - Vd, Vq do not saturate permanently
%
%  If response is too slow/aggressive, edit the pole locations in
%  mcb_pmsm_fsfb_f28379d_param.m  (Section 7) and re-run.

%% =========================================================
%  STEP 3 -- Hardware target configuration in Simulink
%% =========================================================
%  In the model:
%    Model Settings -> Hardware Implementation:
%        Device vendor:  Texas Instruments
%        Device type:    C2000 / F28379D
%
%    Model Settings -> Code Generation:
%        System target:  ert.tlc
%        Language:       C
%        Toolchain:      Texas Instruments Code Composer Studio
%
%  Enable External Mode for real-time tuning + monitoring from host.

%% =========================================================
%  STEP 4 -- Replace simulation blocks with C2000 hardware blocks
%% =========================================================
%  Open mcb_pmsm_fsfb_f28379d.slx and make these replacements:

%  A) Current sensing (inside Current_Sensing subsystem):
%     REMOVE:  Inport "ia", Inport "ib"
%     ADD:     Two C2000 ADC blocks (from C2000 Peripherals library)
%                ADC_A (ia) -> SOC0
%                ADC_B (ib) -> SOC1
%              Scale raw ADC counts to Amperes using your shunt + gain:
%                Ia [A] = (ADC_count - 2048) * I_shunt_gain

%  B) Speed / position sensing (inside Speed_Sensing subsystem):
%     REMOVE:  Inport "QEP_count" + manual difference logic
%     ADD:     C2000 eQEP block (EQEP1 or EQEP2)
%                Position mode: Quadrature count
%                Lines per revolution: 1000 (match Inv.QEP_lines)
%              The eQEP block directly outputs count and speed if
%              using the Motor Control Blockset eQEP driver.

%  C) PWM output (inside SVPWM_GateDrive subsystem):
%     REMOVE:  Outports DutyA, DutyB, DutyC
%     ADD:     Three C2000 ePWM blocks (ePWM1, ePWM2, ePWM3)
%                Carrier frequency: 1/Ts_pwm = 20 kHz
%                Mode: Up-down counting (center-aligned)
%                Dead-band: ~0.5 µs (hardware adjustable)
%              Connect DutyA/B/C to the compare register inputs.

%  D) Gate enable / fault monitoring:
%     ADD:     GPIO output to DRV8305 ENABLE pin
%     ADD:     GPIO input  to DRV8305 nFAULT pin -> trigger motor stop

%% =========================================================
%  STEP 5 -- Tune on hardware with External Mode
%% =========================================================
%  Connect F28379D to PC via USB / XDS110.
%  In Simulink: Simulation -> Mode -> External
%  Click "Connect to Target", then "Run".
%
%  Tunable parameters (set as Simulink.Parameter objects):
%    - omega_ref  (from References/Omega_ref step block)
%    - Kx         (inside FSFB_Controller/Gain_Kx)
%    - Ki         (inside FSFB_Controller/Gain_Ki)
%
%  Monitor signals with Scope blocks or Data Inspector in External Mode.

%% =========================================================
%  STEP 6 -- Standalone deploy
%% =========================================================
%  Once happy with tuning:
%    Simulation -> Mode -> Normal (disconnect External Mode)
%    Build -> Deploy to Hardware  (Ctrl+B)
%
%  Flash the generated .out to the F28379D.
%  The motor will run autonomously on reset.

%% =========================================================
%  CONTROL LAW SUMMARY (reference)
%% =========================================================
%
%  States:    x  = [id,  iq,  omega]'     (d-axis current, q-axis current, speed)
%  Inputs:    u  = [Vd,  Vq ]'            (d-axis voltage, q-axis voltage)
%  Outputs:   y  = [id,  omega]'          (controlled outputs)
%  Reference: yr = [id_ref, omega_ref]'   (= [0, omega_cmd])
%
%  Integrator:
%    xi_dot = yr - C*x    => xi = integral of tracking error
%
%  Control law:
%    u = -Kx * x  +  Ki * xi
%
%  where:
%    Kx = FSFB.Kx   [2x3]  -- state feedback matrix
%    Ki = FSFB.Ki   [2x2]  -- integral gain matrix
%
%  Both Kx and Ki are computed by place(Ai, Bi, desired_poles)
%  and stored in FSFB struct after running the param script.
%
%  Anti-windup: discrete integrators are clamped to
%    xi_id    in  [xi_id_min,    xi_id_max]
%    xi_omega in  [xi_omega_min, xi_omega_max]

fprintf('Read comments in this file for deployment instructions.\n');
