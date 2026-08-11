%% mcb_pmsm_fsfb_f28379d_param.m
%  Motor parameters + Full State Feedback + Integral gain computation
%  for mcb_pmsm_fsfb_qep_f28379d.slx  (F28379D + DRV8305 target)
%
%  Two motor parameter sets are provided:
%    MOTOR_SELECT = 1  ->  Flipsky 6374 (your motor, 48 V)
%    MOTOR_SELECT = 2  ->  Teknic M-2310P (default MCB example motor, 24 V)
%  Change MOTOR_SELECT to match your hardware.

clear; clc; format long;
MOTOR_SELECT = 1;   % <-- change to 2 for Teknic MCB default motor

%% =========================================================
%  Motor Parameters
%% =========================================================
switch MOTOR_SELECT
    case 1  % Flipsky 6374 (your existing simulation motor)
        Rs       = 0.72;        % [Ohm]
        Ld       = 0.4e-3;      % [H]
        Lq       = Ld;
        Lambda_m = 0.0426;      % [Wb]
        P        = 8;           % poles
        J        = 3.6179e-4;   % [kg.m^2]
        Bv       = 9.444e-5;    % [N.m.s/rad]
        Vdc      = 48;          % [V]  DC bus
        Speed_rated = 300;      % [rad/s]  ~2865 RPM
        I_rated     = 10;       % [A]  rated q-axis current
        I_max       = 15;       % [A]  peak limit

    case 2  % Teknic M-2310P-LN-04K  (MCB example default)
        Rs       = 0.3819;
        Ld       = 0.2e-3;
        Lq       = Ld;
        Lambda_m = 0.01273;
        P        = 8;
        J        = 7.061e-6;
        Bv       = 2.636e-6;
        Vdc      = 24;
        Speed_rated = 1000;    % [rad/s]  ~9550 RPM
        I_rated     = 2.8;
        I_max       = 4.0;
end

L = Ld;  % surface PMSM

%% =========================================================
%  Inverter / Hardware Parameters
%% =========================================================
Ts_pwm   = 1/20000;     % PWM period [s]  (20 kHz -- matches MCB example)
Ts_ctrl  = Ts_pwm;      % control interrupt period

QEP_lines     = 1000;   % encoder lines per revolution
QEP_max_count = 4 * QEP_lines;  % quadrature

%% =========================================================
%  State-Space Model  x = [id, iq, omega]'
%  A, B, C, E  (same form used in your simulation models)
%% =========================================================
A = [ -Rs/L,           0,                  0;
       0,            -Rs/L,   -(P/2)*Lambda_m/L;
       0,   (3*(P/2)*Lambda_m)/(2*J),   -Bv/J ];

B = [ 1/L,  0;
       0,  1/L;
       0,   0 ];

C = [ 1, 0, 0;   % id  measured
      0, 0, 1 ]; % omega measured

E = [0; 0; -1/J];  % load-torque disturbance

%% =========================================================
%  Controllability Check
%% =========================================================
Con = ctrb(A, B);
n   = size(A,1);
r   = rank(Con);
fprintf('Controllability rank: %d / %d  ', r, n);
if r == n, disp('=> FULLY CONTROLLABLE');
else,      warning('Not fully controllable!'); end

%% =========================================================
%  Augmented System with Integrators
%  Augmented state: [id, iq, omega, xi_id, xi_omega]
%  xi_dot = yr - C*x   where  yr = [id_ref; omega_ref]
%% =========================================================
m = size(C,1);   % 2 integrators

Ai = [  A,          zeros(n,m);
       -C,          zeros(m,m) ];

Bi = [  B;
        zeros(m, size(B,2)) ];

%% =========================================================
%  Pole Placement
%
%  Bandwidth guidelines (rule of thumb for FOC on PMSM):
%    Current-loop BW  ~  1/10 of PWM freq  =>  2 kHz
%    Speed-loop BW    ~  1/10 of current BW =>  200 Hz
%    Integrator poles ~  2-5x speed-loop BW =>  400-1000 Hz
%
%  Expressed as real-axis poles (overdamped for robustness):
%    sigma_i  = 2*pi * f_current
%    sigma_s  = 2*pi * f_speed
%    sigma_xi = 2*pi * f_integrator
%% =========================================================
f_current    = 800;    % [Hz]  current-loop bandwidth
f_speed      =  60;    % [Hz]  speed-loop bandwidth
f_integrator =  90;    % [Hz]  integrator pole (faster than speed loop)

sigma_i  = 2*pi*f_current;
sigma_s  = 2*pi*f_speed;
sigma_xi = 2*pi*f_integrator;

% Five closed-loop poles for the 5-state augmented system
% Spread slightly to avoid repeated-pole conditioning issues
lambda1 = -sigma_i;           % fast (d-current)
lambda2 = -sigma_i * 1.2;     % fast (q-current, slightly different)
lambda3 = -sigma_s;           % speed loop
lambda4 = -sigma_s * 1.1;     % speed loop (spread)
lambda5 = -sigma_xi;          % integrator

desired_poles = [lambda1, lambda2, lambda3, lambda4, lambda5];

fprintf('\nDesired closed-loop poles:\n');
fprintf('  Current : %.1f, %.1f  rad/s\n', lambda1, lambda2);
fprintf('  Speed   : %.1f, %.1f  rad/s\n', lambda3, lambda4);
fprintf('  Integrat: %.1f          rad/s\n', lambda5);

% Pole placement
K  = place(Ai, Bi, desired_poles);

Kx =  K(:, 1:n);         % [2x3] state feedback gains
Ki = -K(:, n+1:end);     % [2x2] integral gains
%  Control law:  u = -Kx*x + Ki*xi

fprintf('\nKx (state feedback, [2x3]):\n'); disp(Kx);
fprintf('Ki (integral gain,   [2x2]):\n'); disp(Ki);

%% =========================================================
%  Verify Closed-Loop Stability
%% =========================================================
CL_eig = eig(Ai - Bi*K);
fprintf('Closed-loop eigenvalues:\n'); disp(CL_eig);
if all(real(CL_eig) < 0)
    disp('=> All eigenvalues in LHP: STABLE.');
else
    warning('Unstable closed-loop! Adjust pole locations.');
end

%% =========================================================
%  Integrator Anti-Windup Limits
%  (prevent integrator from accumulating beyond physical limits)
%% =========================================================
xi_id_max    =  I_max * 0.5;     % conservative: half current limit
xi_id_min    = -I_max * 0.5;
xi_omega_max =  Speed_rated * 3;
xi_omega_min = -Speed_rated * 3;

%% =========================================================
%  Pack into structs (Simulink workspace variables)
%% =========================================================
FSFB.Kx           = Kx;
FSFB.Ki           = Ki;
FSFB.Ts           = Ts_ctrl;
FSFB.xi_id_max    = xi_id_max;
FSFB.xi_id_min    = xi_id_min;
FSFB.xi_omega_max = xi_omega_max;
FSFB.xi_omega_min = xi_omega_min;

Motor.Rs       = Rs;
Motor.Ld       = Ld;
Motor.Lq       = Lq;
Motor.Lambda_m = Lambda_m;
Motor.P        = P;
Motor.J        = J;
Motor.Bv       = Bv;

Inv.Vdc        = Vdc;
Inv.I_max      = I_max;
Inv.Ts_pwm     = Ts_pwm;
Inv.QEP_lines  = QEP_lines;

fprintf('\n=== Parameters ready. Run replace_pid_with_fsfb.m to build model. ===\n');
