% Model         :   PMSM Field Oriented Control
% Description   :   Set Parameters for PMSM Field Oriented Control
% File name     :   mcb_pmsm_foc_qep_f28379d_SIUnit_data.m
% Copyright 2020-2025 The MathWorks, Inc.
%% Set PWM Switching frequency
PWM_frequency 	= 20e3;    %Hz          // converter s/w freq
T_pwm           = 1/PWM_frequency;  %s  // PWM switching time period
%% Set Sample Times
Ts          	= T_pwm;        %sec        // Sample time step for controller
Ts_simulink     = T_pwm/2;      %sec        // Simulation time step for model simulation
Ts_motor        = T_pwm/2;      %Sec        // Simulation sample time
Ts_inverter     = T_pwm/2;      %sec        // Simulation time step for average value inverter
Ts_speed        = 10*Ts;        %Sec        // Sample time for speed controller
%% Set data type for controller & code-gen
dataType = 'single';            % Floating point code-generation, Fixed point is not supported.
%% System Parameters // Hardware parameters
% Motor parameters
pmsm = mcb.getPMSMParameters('Teknic2310P');
pmsm.PositionOffset = 0.1665;     % Offset value obtained from QEP offset example
%% Target & Inverter Parameters
target = mcb.getProcessorParameters('F28379D',PWM_frequency);
target.comport = '<Select a port...>';
% target.comport = 'COM3';       % Uncomment and update the appropriate serial port
inverter = mcb.getInverterParameters('BoostXL-DRV8305');
% Enable automatic calibration of ADC offset for current measurement
inverter.ADCOffsetCalibEnable = 1; % Enable: 1, Disable:0
% If automatic ADC offset calibration is disabled, uncomment and update the
% offset values below manually
inverter.CtSensAOffset = 2309;      % ADC Offset for phase current A
inverter.CtSensBOffset = 2304;      % ADC Offset for phase current B
% Update inverter.ISenseMax based for the chosen motor and target
inverter = mcb.updateInverterParameters(pmsm,inverter,target);
% Max and min ADC counts for current sense offsets
inverter.CtSensOffsetMax = 2500; % Maximum permitted ADC counts for current sense offset
inverter.CtSensOffsetMin = 1500; % Minimum permitted ADC counts for current sense offset
%% Derive Characteristics
pmsm.N_base = mcb.getMotorBaseSpeed(pmsm,inverter); %rpm // Base speed of motor at given Vdc
% mcb.PMSMCharacteristics(pmsm,inverter);
%% Controller design // Get ballpark values!
%Considering inverter board resistance for gain calculation
motor = pmsm;
motor.Rs = pmsm.Rs + inverter.R_board;
%Low-pass IIR-Filter coefficient connected to Speed Measurement output
LPFltCoeff = 0.01;
PI_params = mcb.calcFOCGains(motor,Ts,Ts_speed,SpdLPFltCoeff=LPFltCoeff);
%Updating delays for simulation
PI_params.delay_Currents    = int32(Ts/Ts_simulink);
PI_params.delay_Position    = int32(Ts/Ts_simulink);
% mcb.getMotorControlAnalysis(pmsm,inverter,PU_System,PI_params,Ts,Ts_speed);

%% State-Feedback Current Controller Design (FSFB + integral servo, Option B)
% After dq-decoupling, each axis is an identical first-order plant:
%     di/dt = -Rs_eff/L * i + 1/L * V
% Design one servo gain (state feedback K + integral Ki) and reuse for both axes.
Rs_eff = motor.Rs;          % stator + board resistance [Ohm]
L_dq   = pmsm.Ld;           % Ld = Lq for surface PMSM [H]

% Per-axis clean (decoupled) plant
A_fsfb = -Rs_eff / L_dq;
B_fsfb =  1 / L_dq;

% Augment with integrator on tracking error:  states = [i ; Z], Z = integral(i_ref - i)
Aa_fsfb = [A_fsfb  0;
           -1      0];
Ba_fsfb = [B_fsfb; 0];

% Desired current-loop bandwidth (rad/s). ~1/15 of PWM freq; raise later if stable.
wc_current = 2000;                              % [rad/s]
poles_fsfb = [-wc_current, -1.2*wc_current];    % two closed-loop poles
Ka_fsfb    = place(Aa_fsfb, Ba_fsfb, poles_fsfb);

% Gains used by the Simulink Current_Controllers subsystem
K  = Ka_fsfb(1);        % state-feedback gain on measured current  (scalar, element-wise on [id iq])
Ki = -Ka_fsfb(2);       % integral gain                              (scalar, element-wise on [id iq])

% Decoupling feedforward parameters (used by the "decouple" MATLAB Function block)
p_polepairs = pmsm.p;   % pole pairs (=4 for Teknic 2310P)
lambda_pm   = pmsm.FluxPM;  % PM flux linkage [Wb]

%% State-Feedback Speed Controller Design -> mapped to PI block gains
% Speed plant (iq is the control input, wm the state):
%     d(wm)/dt = -Bv/J * wm + (3*p*lambda)/(2J) * iq - (1/J)*TL
% FSFB+integral is mathematically identical to a PI for this first-order plant,
% so we design gains by pole placement and feed them into the existing PI block:
%     Kp (P input)      = Ks   (state-feedback gain)
%     Ki (I*Ts input)   = Kis * Ts_speed
Jm   = pmsm.J;          % rotor inertia [kg*m^2]
Bv   = pmsm.B;          % viscous friction [N*m*s]
pp   = pmsm.p;          % pole pairs (=4)
lam  = pmsm.FluxPM;     % PM flux linkage [Wb]

% Speed plant
A_s = -Bv / Jm;
B_s = (3 * pp * lam) / (2 * Jm);

% Augment with integrator on speed error: states = [wm ; Zs], Zs = integral(wm_ref - wm)
Aa_s = [A_s  0;
        -1   0];
Ba_s = [B_s; 0];

% Speed-loop bandwidth: MUST be well below current loop (2000 rad/s).
% ~10x slower for cascade stability. Start at 200 rad/s.
wc_speed = 50;                                  % [rad/s]
poles_s  = [-wc_speed, -1.2*wc_speed];
Kas      = place(Aa_s, Ba_s, poles_s);

Ks  = Kas(1);        % state-feedback gain on measured speed
Kis = -Kas(2);       % integral gain

% Map to the PI block inputs (P and I*Ts):
Speed_Kp    = Ks;                 % -> feed into the P input (-C- block)
Speed_Ki_Ts = Kis * Ts_speed;     % -> feed into the I*Ts input (-C- block)

%% State-Feedback Position Controller Design (SI units, proportional)
% Position plant is a pure integrator:  d(theta)/dt = wm  ->  A = 0, B = 1.
% With one state (theta), full state feedback reduces to proportional control:
%     speed_ref = Kp_pos * (theta_ref - theta)     [theta in rad, speed_ref in rad/s]
% Pole placement puts the single closed-loop pole at -wc_pos, giving Kp_pos = wc_pos.
% wc_pos MUST be slower than the speed loop (50 rad/s). ~5-10x slower. Start at 8.
wc_pos = 8;                              % [rad/s] position-loop bandwidth
Kp_pos = wc_pos;                         % proportional gain: rad error -> rad/s command

% Speed limit during positioning [rad/s] (Saturation block on the position-loop output).
PosCtrlSpeedLimit = 43;                  % [rad/s]  (~410 rpm; adjust to taste)

% Maximum travel limit [rad]: +/- 5 revolutions.
PosCtrlPosLimit = 5 * 2*pi;              % [rad]

%% Displaying model variables
disp(pmsm);
disp(inverter);
disp(target);
fprintf('FSFB current-loop gains:  K = %.4f,  Ki = %.2f  (wc = %d rad/s)\n', K, Ki, wc_current);
fprintf('FSFB speed-loop  gains:  Speed_Kp = %.5f,  Speed_Ki_Ts = %.6f  (Ks=%.4f, Kis=%.2f, wc=%d rad/s)\n', ...
         Speed_Kp, Speed_Ki_Ts, Ks, Kis, wc_speed);
fprintf('FSFB position-loop gain: Kp_pos = %.2f (wc = %d rad/s), speed limit = %.0f rad/s\n', ...
         Kp_pos, wc_pos, PosCtrlSpeedLimit);