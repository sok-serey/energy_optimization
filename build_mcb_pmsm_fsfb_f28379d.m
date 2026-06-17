%% build_mcb_pmsm_fsfb_f28379d.m
%  Programmatically creates mcb_pmsm_fsfb_f28379d.slx
%  PMSM FOC with Full State Feedback + Integral controller
%  Target: TI F28379D LaunchPad + DRV8305 inverter
%
%  STEP 1: Run  mcb_pmsm_fsfb_f28379d_param.m  first
%  STEP 2: Run this script to build/update the Simulink model
%  STEP 3: Open and verify mcb_pmsm_fsfb_f28379d.slx
%  STEP 4: Deploy to F28379D via Embedded Coder

%% -------------------------------------------------------
%  Guard: param script must be run first
%% -------------------------------------------------------
if ~exist('FSFB','var') || ~exist('Motor','var')
    error('Run mcb_pmsm_fsfb_f28379d_param.m first.');
end

mdl = 'mcb_pmsm_fsfb_f28379d';

%% -------------------------------------------------------
%  Close & delete old model if it exists
%% -------------------------------------------------------
if bdIsLoaded(mdl), close_system(mdl, 0); end
if exist([mdl '.slx'], 'file'), delete([mdl '.slx']); end

%% -------------------------------------------------------
%  Create new model
%% -------------------------------------------------------
new_system(mdl);
open_system(mdl);

% Set solver to fixed-step discrete (required for C2000 codegen)
set_param(mdl, ...
    'Solver',         'FixedStepDiscrete', ...
    'FixedStep',      num2str(Inv.Ts_pwm), ...
    'StopTime',       '2', ...
    'SystemTargetFile','ert.tlc');

fprintf('Model %s created.\n', mdl);

%% =======================================================
%  TOP-LEVEL SUBSYSTEMS
%  Layout (left to right):
%    [References] -> [FSFB Controller] -> [SVPWM + Gate Drive]
%                                        [Plant (simulation only)]
%                 <- [Sensing / Feedback] <-
%% =======================================================

%  Helper: add a Subsystem block and return its path
addSS = @(name, pos) add_block('built-in/Subsystem', ...
    [mdl '/' name], 'Position', pos);

%% --- Top-level subsystem positions (x1 y1 x2 y2) ------
addSS('References',           [ 30  200  130  300]);
addSS('FSFB_Controller',      [200  150  400  350]);
addSS('SVPWM_GateDrive',      [500  150  680  350]);
addSS('Current_Sensing',      [200  420  400  520]);
addSS('Speed_Sensing',        [500  420  680  520]);
addSS('PMSM_Plant',           [500  580  680  680]);  % sim only

%% --- Connect top-level signals -------------------------
% References -> FSFB_Controller
add_line(mdl, 'References/1',      'FSFB_Controller/1', 'autorouting','on'); % id_ref
add_line(mdl, 'References/2',      'FSFB_Controller/2', 'autorouting','on'); % omega_ref

% FSFB_Controller -> SVPWM_GateDrive
add_line(mdl, 'FSFB_Controller/1', 'SVPWM_GateDrive/1', 'autorouting','on'); % Vd*
add_line(mdl, 'FSFB_Controller/2', 'SVPWM_GateDrive/2', 'autorouting','on'); % Vq*
add_line(mdl, 'FSFB_Controller/3', 'SVPWM_GateDrive/3', 'autorouting','on'); % theta_e

% Current_Sensing -> FSFB_Controller
add_line(mdl, 'Current_Sensing/1', 'FSFB_Controller/3', 'autorouting','on'); % id
add_line(mdl, 'Current_Sensing/2', 'FSFB_Controller/4', 'autorouting','on'); % iq

% Speed_Sensing -> FSFB_Controller
add_line(mdl, 'Speed_Sensing/1',   'FSFB_Controller/5', 'autorouting','on'); % omega
add_line(mdl, 'Speed_Sensing/2',   'FSFB_Controller/6', 'autorouting','on'); % theta_e

fprintf('Top-level connections done.\n');

%% =======================================================
%  SUBSYSTEM: References
%  Outputs: [id_ref, omega_ref]
%% =======================================================
ref = [mdl '/References'];
delete_block([ref '/In1']);  % remove default port

% Id reference = constant 0 (MTPA for surface PMSM)
add_block('built-in/Constant', [ref '/Id_ref'], ...
    'Value', '0', 'Position', [30 80 110 120]);

% Speed reference = step from 0 to Speed_rated
add_block('built-in/Step', [ref '/Omega_ref'], ...
    'Time',        '0.1', ...
    'Before',      '0', ...
    'After',       num2str(Speed_rated), ...
    'Position',    [30 160 110 200]);

% Rate limiter on speed reference (ramp up gently)
add_block('built-in/RateLimiter', [ref '/SpeedRamp'], ...
    'RisingSlew',  num2str(Speed_rated * 5), ...  % 5 s ramp from 0 to rated
    'FallingSlew', num2str(-Speed_rated * 5), ...
    'Position',    [150 155 230 205]);

% Output ports
add_block('built-in/Outport', [ref '/id_ref'],    'Port','1','Position',[280  90 310 110]);
add_block('built-in/Outport', [ref '/omega_ref'], 'Port','2','Position',[310 165 340 185]);

add_line(ref, 'Id_ref/1',    'id_ref/1');
add_line(ref, 'Omega_ref/1', 'SpeedRamp/1');
add_line(ref, 'SpeedRamp/1', 'omega_ref/1');

fprintf('References subsystem built.\n');

%% =======================================================
%  SUBSYSTEM: FSFB_Controller
%
%  Inputs:  1=id_ref, 2=omega_ref, 3=id, 4=iq, 5=omega, 6=theta_e
%  Outputs: 1=Vd_cmd, 2=Vq_cmd, 3=theta_e (pass-through for SVPWM)
%
%  Control law (discrete, forward-Euler integrator):
%    e_id    = id_ref    - id
%    e_omega = omega_ref - omega
%    xi_id[k+1]    = xi_id[k]    + Ts * e_id
%    xi_omega[k+1] = xi_omega[k] + Ts * e_omega
%    [Vd]   =  -Kx * [id; iq; omega]  +  Ki * [xi_id; xi_omega]
%    [Vq]
%% =======================================================
ctrl = [mdl '/FSFB_Controller'];
for k = 1:6, try delete_block([ctrl '/In'  num2str(k)]); catch, end; end
for k = 1:3, try delete_block([ctrl '/Out' num2str(k)]); catch, end; end

% --- Input ports ---
ports_in = {'id_ref','omega_ref','id','iq','omega','theta_e'};
ypos = 50;
for k = 1:6
    add_block('built-in/Inport', [ctrl '/' ports_in{k}], ...
        'Port', num2str(k), 'Position', [20, ypos, 50, ypos+20]);
    ypos = ypos + 70;
end

% --- Output ports ---
add_block('built-in/Outport', [ctrl '/Vd_cmd'],  'Port','1','Position',[650  80  680 100]);
add_block('built-in/Outport', [ctrl '/Vq_cmd'],  'Port','2','Position',[650 160  680 180]);
add_block('built-in/Outport', [ctrl '/theta_e'], 'Port','3','Position',[650 380  680 400]);

% --- Error signals ---
% e_id = id_ref - id
add_block('built-in/Sum', [ctrl '/e_id_sum'], ...
    'Inputs','+-','Position',[150  60  180  90]);
add_line(ctrl, 'id_ref/1',  'e_id_sum/1');
add_line(ctrl, 'id/1',      'e_id_sum/2');

% e_omega = omega_ref - omega
add_block('built-in/Sum', [ctrl '/e_omega_sum'], ...
    'Inputs','+-','Position',[150 200  180 230]);
add_line(ctrl, 'omega_ref/1', 'e_omega_sum/1');
add_line(ctrl, 'omega/1',     'e_omega_sum/2');

% --- Discrete integrators with anti-windup (Forward-Euler) ---
% xi_id integrator
add_block('simulink/Discrete/Discrete-Time Integrator', [ctrl '/IntXi_id'], ...
    'IntegratorMethod',   'Forward Euler', ...
    'gainval',            '1', ...
    'SampleTime',         num2str(Inv.Ts_pwm), ...
    'UpperSaturationLimit', num2str(FSFB.xi_id_max), ...
    'LowerSaturationLimit', num2str(FSFB.xi_id_min), ...
    'AntiWindupMode',     'Clamping', ...
    'Position',           [230  55  310  95]);

add_line(ctrl, 'e_id_sum/1', 'IntXi_id/1');

% xi_omega integrator
add_block('simulink/Discrete/Discrete-Time Integrator', [ctrl '/IntXi_omega'], ...
    'IntegratorMethod',   'Forward Euler', ...
    'gainval',            '1', ...
    'SampleTime',         num2str(Inv.Ts_pwm), ...
    'UpperSaturationLimit', num2str(FSFB.xi_omega_max), ...
    'LowerSaturationLimit', num2str(FSFB.xi_omega_min), ...
    'AntiWindupMode',     'Clamping', ...
    'Position',           [230 195  310 235]);

add_line(ctrl, 'e_omega_sum/1', 'IntXi_omega/1');

% --- Mux state vector x = [id; iq; omega] ---
add_block('built-in/Mux', [ctrl '/Mux_x'], ...
    'Inputs','3','Position',[150 290  155 370]);
add_line(ctrl, 'id/1',    'Mux_x/1');
add_line(ctrl, 'iq/1',    'Mux_x/2');
add_line(ctrl, 'omega/1', 'Mux_x/3');

% --- Mux integrator vector xi = [xi_id; xi_omega] ---
add_block('built-in/Mux', [ctrl '/Mux_xi'], ...
    'Inputs','2','Position',[350 115  355 185]);
add_line(ctrl, 'IntXi_id/1',    'Mux_xi/1');
add_line(ctrl, 'IntXi_omega/1', 'Mux_xi/2');

% --- Gain: -Kx * x  (2x3 matrix gain) ---
add_block('built-in/Gain', [ctrl '/Gain_Kx'], ...
    'Gain',             mat2str(-FSFB.Kx), ...
    'Multiplication',   'Matrix(K*u)', ...
    'Position',         [230 290  310 370]);
add_line(ctrl, 'Mux_x/1', 'Gain_Kx/1');

% --- Gain: Ki * xi  (2x2 matrix gain) ---
add_block('built-in/Gain', [ctrl '/Gain_Ki'], ...
    'Gain',             mat2str(FSFB.Ki), ...
    'Multiplication',   'Matrix(K*u)', ...
    'Position',         [400 115  480 185]);
add_line(ctrl, 'Mux_xi/1', 'Gain_Ki/1');

% --- Sum: u = -Kx*x + Ki*xi ---
add_block('built-in/Sum', [ctrl '/Sum_ctrl'], ...
    'Inputs','++','Position',[530 200  560 280]);
add_line(ctrl, 'Gain_Kx/1', 'Sum_ctrl/1');
add_line(ctrl, 'Gain_Ki/1', 'Sum_ctrl/2');

% --- Demux output [Vd; Vq] ---
add_block('built-in/Demux', [ctrl '/Demux_uv'], ...
    'Outputs','2','Position',[590 210  595 270]);
add_line(ctrl, 'Sum_ctrl/1', 'Demux_uv/1');

% --- Voltage saturation (protect inverter) ---
add_block('built-in/Saturate', [ctrl '/Sat_Vd'], ...
    'UpperLimit', num2str( Vdc/sqrt(3)), ...
    'LowerLimit', num2str(-Vdc/sqrt(3)), ...
    'Position',   [620  65  650 105]);
add_block('built-in/Saturate', [ctrl '/Sat_Vq'], ...
    'UpperLimit', num2str( Vdc/sqrt(3)), ...
    'LowerLimit', num2str(-Vdc/sqrt(3)), ...
    'Position',   [620 145  650 185]);

add_line(ctrl, 'Demux_uv/1', 'Sat_Vd/1');
add_line(ctrl, 'Demux_uv/2', 'Sat_Vq/1');
add_line(ctrl, 'Sat_Vd/1',   'Vd_cmd/1');
add_line(ctrl, 'Sat_Vq/1',   'Vq_cmd/1');

% Pass theta_e straight through
add_line(ctrl, 'theta_e/1',  'theta_e/1');

fprintf('FSFB_Controller subsystem built.\n');

%% =======================================================
%  SUBSYSTEM: SVPWM_GateDrive
%  Inputs:  1=Vd_cmd, 2=Vq_cmd, 3=theta_e
%  Outputs: 1-6 = PWM duty cycles (or gate signals)
%
%  Structure:
%    [Vd, Vq, theta_e] -> Inverse Park -> Alpha/Beta
%                      -> SVPWM (sector + duty) -> Duty A/B/C
%% =======================================================
svpwm = [mdl '/SVPWM_GateDrive'];
for k=1:3, try delete_block([svpwm '/In'  num2str(k)]); catch, end; end
for k=1:6, try delete_block([svpwm '/Out' num2str(k)]); catch, end; end

% Inputs
add_block('built-in/Inport',[svpwm '/Vd_cmd'], 'Port','1','Position',[20  50  50  70]);
add_block('built-in/Inport',[svpwm '/Vq_cmd'], 'Port','2','Position',[20 120  50 140]);
add_block('built-in/Inport',[svpwm '/theta_e'],'Port','3','Position',[20 190  50 210]);

% Inverse Park: [Valpha; Vbeta] = [cos -sin; sin cos] * [Vd; Vq]
add_block('built-in/MATLAB Function',[svpwm '/InvPark'], ...
    'Position',[150  60 280 200]);
% Set the MATLAB function body via mask
set_param([svpwm '/InvPark'], 'MATLABFcnType', 'Embedded MATLAB function');

% Use a pre-written Fcn block approach instead (more codegen-friendly)
delete_block([svpwm '/InvPark']);
add_block('built-in/Fcn',[svpwm '/Valpha'], ...
    'Expr', 'u(1)*cos(u(3)) - u(2)*sin(u(3))', ...
    'Position',[150  60 280 100]);
add_block('built-in/Fcn',[svpwm '/Vbeta'], ...
    'Expr', 'u(1)*sin(u(3)) + u(2)*cos(u(3))', ...
    'Position',[150 130 280 170]);

% Mux [Vd,Vq,theta] for Fcn inputs
add_block('built-in/Mux',[svpwm '/MuxPark'],'Inputs','3','Position',[80 60 85 210]);
add_line(svpwm,'Vd_cmd/1', 'MuxPark/1');
add_line(svpwm,'Vq_cmd/1', 'MuxPark/2');
add_line(svpwm,'theta_e/1','MuxPark/3');
add_line(svpwm,'MuxPark/1','Valpha/1');
add_line(svpwm,'MuxPark/1','Vbeta/1');

% SVPWM block: use Motor Control Blockset if available, else manual
% Check if Motor Control Blockset is available
mcb_available = ~isempty(ver('mcb'));
if mcb_available
    add_block('mcb_library/SVPWM',[svpwm '/SVPWM_Block'],'Position',[350 80 470 190]);
    add_line(svpwm,'Valpha/1','SVPWM_Block/1');
    add_line(svpwm,'Vbeta/1', 'SVPWM_Block/2');
    % Add constant for Vdc
    add_block('built-in/Constant',[svpwm '/Vdc_const'],'Value',num2str(Inv.Vdc),'Position',[300 50 330 80]);
    add_line(svpwm,'Vdc_const/1','SVPWM_Block/3');
else
    % Manual SVPWM: compute duty cycles using standard algorithm
    % Ta = 0.5 + Valpha/Vdc,  Tb/Tc from sector logic (simplified sinusoidal approx)
    add_block('built-in/Fcn',[svpwm '/Da'], ...
        'Expr', 'min(max(0.5 + u(1)/u(3), 0), 1)', 'Position',[350  60 480  90]);
    add_block('built-in/Fcn',[svpwm '/Db'], ...
        'Expr', 'min(max(0.5 + (-0.5*u(1)+sqrt(3)/2*u(2))/u(3), 0), 1)', 'Position',[350 110 480 140]);
    add_block('built-in/Fcn',[svpwm '/Dc'], ...
        'Expr', 'min(max(0.5 + (-0.5*u(1)-sqrt(3)/2*u(2))/u(3), 0), 1)', 'Position',[350 160 480 190]);

    add_block('built-in/Mux',[svpwm '/MuxSVPWM'],'Inputs','3','Position',[310 60 315 200]);
    add_line(svpwm,'Valpha/1','MuxSVPWM/1');
    add_line(svpwm,'Vbeta/1', 'MuxSVPWM/2');
    add_block('built-in/Constant',[svpwm '/Vdc_c'],'Value',num2str(Inv.Vdc),'Position',[270 180 300 210]);
    add_line(svpwm,'Vdc_c/1','MuxSVPWM/3');
    add_line(svpwm,'MuxSVPWM/1','Da/1');
    add_line(svpwm,'MuxSVPWM/1','Db/1');
    add_line(svpwm,'MuxSVPWM/1','Dc/1');
end

% Output ports: duty cycle A, B, C (top/bottom from complementary logic)
add_block('built-in/Outport',[svpwm '/DutyA'],'Port','1','Position',[560  60 590  80]);
add_block('built-in/Outport',[svpwm '/DutyB'],'Port','2','Position',[560 120 590 140]);
add_block('built-in/Outport',[svpwm '/DutyC'],'Port','3','Position',[560 180 590 200]);
if mcb_available
    add_line(svpwm,'SVPWM_Block/1','DutyA/1');
    add_line(svpwm,'SVPWM_Block/2','DutyB/1');
    add_line(svpwm,'SVPWM_Block/3','DutyC/1');
else
    add_line(svpwm,'Da/1','DutyA/1');
    add_line(svpwm,'Db/1','DutyB/1');
    add_line(svpwm,'Dc/1','DutyC/1');
end

fprintf('SVPWM_GateDrive subsystem built.\n');

%% =======================================================
%  SUBSYSTEM: Current_Sensing
%  Represents Clarke + Park transform applied to ia, ib
%  In the F28379D example, the ADC reads ia and ib.
%  Outputs: id, iq  (in rotating dq frame)
%% =======================================================
cs = [mdl '/Current_Sensing'];
for k=1:3, try delete_block([cs '/In'  num2str(k)]); catch, end; end
for k=1:2, try delete_block([cs '/Out' num2str(k)]); catch, end; end

add_block('built-in/Inport',[cs '/ia'],     'Port','1','Position',[20  50 50  70]);
add_block('built-in/Inport',[cs '/ib'],     'Port','2','Position',[20 120 50 140]);
add_block('built-in/Inport',[cs '/theta_e'],'Port','3','Position',[20 190 50 210]);

% Clarke transform: alpha = ia,  beta = (ia + 2*ib)/sqrt(3)
add_block('built-in/Fcn',[cs '/Ialpha'],'Expr','u(1)',             'Position',[130  50 230  80]);
add_block('built-in/Fcn',[cs '/Ibeta'], 'Expr','(u(1)+2*u(2))/sqrt(3)', 'Position',[130 110 230 140]);

add_block('built-in/Mux',[cs '/MuxAB'],'Inputs','2','Position',[80 50 85 150]);
add_line(cs,'ia/1','MuxAB/1');
add_line(cs,'ib/1','MuxAB/2');
add_line(cs,'MuxAB/1','Ialpha/1');
add_line(cs,'MuxAB/1','Ibeta/1');

% Park transform: id = Ialpha*cos(theta) + Ibeta*sin(theta)
%                 iq = -Ialpha*sin(theta) + Ibeta*cos(theta)
add_block('built-in/Mux',[cs '/MuxClark'],'Inputs','3','Position',[280 50 285 220]);
add_line(cs,'Ialpha/1','MuxClark/1');
add_line(cs,'Ibeta/1', 'MuxClark/2');
add_line(cs,'theta_e/1','MuxClark/3');

add_block('built-in/Fcn',[cs '/id_out'],'Expr','u(1)*cos(u(3))+u(2)*sin(u(3))', 'Position',[330  60 470  90]);
add_block('built-in/Fcn',[cs '/iq_out'],'Expr','-u(1)*sin(u(3))+u(2)*cos(u(3))','Position',[330 130 470 160]);
add_line(cs,'MuxClark/1','id_out/1');
add_line(cs,'MuxClark/1','iq_out/1');

add_block('built-in/Outport',[cs '/id'],'Port','1','Position',[520  65 550  85]);
add_block('built-in/Outport',[cs '/iq'],'Port','2','Position',[520 135 550 155]);
add_line(cs,'id_out/1','id/1');
add_line(cs,'iq_out/1','iq/1');

fprintf('Current_Sensing subsystem built.\n');

%% =======================================================
%  SUBSYSTEM: Speed_Sensing
%  QEP decoder: converts encoder counts to omega [rad/s] and theta_e [rad]
%  In hardware: use C2000 QEP block from MCB or target library
%% =======================================================
ss = [mdl '/Speed_Sensing'];
for k=1:1, try delete_block([ss '/In'  num2str(k)]); catch, end; end
for k=1:2, try delete_block([ss '/Out' num2str(k)]); catch, end; end

add_block('built-in/Inport',[ss '/QEP_count'],'Port','1','Position',[20 100 50 120]);

% Mechanical speed: omega = d(theta)/dt, approximated by delta_count/Ts * (2*pi / QEP_max)
%  In discrete: omega[k] = (count[k] - count[k-1]) / Ts * (2*pi/QEP_max)
add_block('simulink/Discrete/Unit Delay',[ss '/PrevCount'],'SampleTime',num2str(Inv.Ts_pwm),'Position',[130  90 200 130]);
add_line(ss,'QEP_count/1','PrevCount/1');

add_block('built-in/Sum',[ss '/DeltaCount'],'Inputs','+-','Position',[250 90 280 130]);
add_line(ss,'QEP_count/1','DeltaCount/1');
add_line(ss,'PrevCount/1','DeltaCount/2');

K_speed = (2*pi) / (4 * Inv.QEP_lines * Inv.Ts_pwm);
add_block('built-in/Gain',[ss '/SpeedGain'],'Gain',num2str(K_speed),'Position',[320 90 400 130]);
add_line(ss,'DeltaCount/1','SpeedGain/1');

% Electrical angle: theta_e = (P/2) * theta_mech = count * (2*pi / QEP_max) * (P/2)
K_theta = (2*pi / (4*Inv.QEP_lines)) * (Motor.P/2);
add_block('built-in/Gain',[ss '/ThetaGain'],'Gain',num2str(K_theta),'Position',[130 180 210 220]);
add_block('built-in/Math',[ss '/Mod2pi'], ...
    'Operator','mod','Position',[250 175 330 225]);
add_block('built-in/Constant',[ss '/TwoPi'],'Value','2*pi','Position',[200 240 260 270]);
add_line(ss,'QEP_count/1','ThetaGain/1');
add_line(ss,'ThetaGain/1','Mod2pi/1');
add_line(ss,'TwoPi/1',    'Mod2pi/2');

add_block('built-in/Outport',[ss '/omega'],  'Port','1','Position',[460  95 490 115]);
add_block('built-in/Outport',[ss '/theta_e'],'Port','2','Position',[400 185 430 205]);
add_line(ss,'SpeedGain/1','omega/1');
add_line(ss,'Mod2pi/1',   'theta_e/1');

fprintf('Speed_Sensing subsystem built.\n');

%% =======================================================
%  SUBSYSTEM: PMSM_Plant  (simulation verification only)
%  Continuous PMSM model: dx/dt = A*x + B*u
%  Use for SIL/PIL or to verify control in simulation
%% =======================================================
plant = [mdl '/PMSM_Plant'];
for k=1:3, try delete_block([plant '/In'  num2str(k)]); catch, end; end
for k=1:3, try delete_block([plant '/Out' num2str(k)]); catch, end; end

add_block('built-in/Inport',[plant '/Vd'],'Port','1','Position',[20  60 50  80]);
add_block('built-in/Inport',[plant '/Vq'],'Port','2','Position',[20 130 50 150]);
add_block('built-in/Inport',[plant '/TL'],'Port','3','Position',[20 200 50 220]);

% State-space block
add_block('built-in/StateSpace',[plant '/PMSM_SS'], ...
    'A', mat2str(A), ...
    'B', mat2str([B, E]), ...
    'C', mat2str(eye(3)), ...
    'D', mat2str(zeros(3,3)), ...
    'X0','[0;0;0]', ...
    'Position',[200 100 360 240]);

add_block('built-in/Mux',[plant '/MuxU'],'Inputs','3','Position',[120 60 125 240]);
add_line(plant,'Vd/1','MuxU/1');
add_line(plant,'Vq/1','MuxU/2');
add_line(plant,'TL/1','MuxU/3');
add_line(plant,'MuxU/1','PMSM_SS/1');

add_block('built-in/Outport',[plant '/id'],   'Port','1','Position',[450  90 480 110]);
add_block('built-in/Outport',[plant '/iq'],   'Port','2','Position',[450 155 480 175]);
add_block('built-in/Outport',[plant '/omega'],'Port','3','Position',[450 220 480 240]);

add_block('built-in/Demux',[plant '/DemuxX'],'Outputs','3','Position',[400 100 405 240]);
add_line(plant,'PMSM_SS/1','DemuxX/1');
add_line(plant,'DemuxX/1','id/1');
add_line(plant,'DemuxX/2','iq/1');
add_line(plant,'DemuxX/3','omega/1');

fprintf('PMSM_Plant subsystem built.\n');

%% =======================================================
%  Add Scope for monitoring
%% =======================================================
add_block('built-in/Scope',[mdl '/Scope_Speed'], ...
    'NumInputPorts','2','Position',[780 160 830 210]);
add_block('built-in/Scope',[mdl '/Scope_Current'],'Position',[780 260 830 310]);

%% =======================================================
%  Save model
%% =======================================================
Simulink.BlockDiagram.arrangeSystem(mdl);
save_system(mdl, [mdl '.slx']);
fprintf('\n=== Model saved as %s.slx ===\n', mdl);
fprintf('Next steps:\n');
fprintf('  1. Open %s.slx and verify the block diagram\n', mdl);
fprintf('  2. For hardware deployment, replace:\n');
fprintf('     - Current_Sensing/ia, ib  ->  ADC blocks from C2000 target library\n');
fprintf('     - Speed_Sensing/QEP_count ->  eQEP block from C2000 target library\n');
fprintf('     - SVPWM_GateDrive output  ->  ePWM blocks from C2000 target library\n');
fprintf('     - Enable External Mode for host communication\n');
fprintf('  3. Set Hardware Implementation to TI C2000 F28379D\n');
fprintf('  4. Build and Deploy\n');
