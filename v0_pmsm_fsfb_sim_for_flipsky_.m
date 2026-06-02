clear
clc
format long;
%% PMSM Parameters
Rs = 0.72;
R = Rs;
Ld = 0.4e-3; %H
Lq = Ld;
L = Lq;

Lambda_m = 0.0426; %Flux Linkage [Wb]
P = 8; % Number of Poles
J = 0.00036179; %0.9*0.7*0.01; %Inertia [Kg.mˆ2]
Bv = 9.444e-5; %Viscous friction or damping [Nm.s/rad]

%% State Space PMSM
A = [
        -R/L, 0, 0;
        0, -R/L, -P*Lambda_m/(2*L);
        0, 3*P*Lambda_m/(4*J), -Bv/J;
    ];
B = [
        1/L, 0;
        0, 1/L;
        0, 0;
    ];
C = [
        1, 0, 0;
        0, 0, 1;
    ]; 
E = [0; 0; -1/J];

%% EKF Parameters initialize
Ts = 1e-4; % <= 5e-4
Ts_ov = 1e-6;
X03 = [0; 0; 0];
X04 = 1e-2*[1; 1; 1; 0];
Qd = 1e-4*diag([0.5, 0.5, 5, 0.5]);
Rd = 1e-2*diag([0.5, 0.5, 5]);
Pk0 = 5e-4*diag([1e-3, 1e-2, 0.2, 0.01]);
% Pk0 = 5e-1*eye(4);


%% Controllability

% Controllability matrix
Con = ctrb(A, B);

% Compute rank
rank_Con = rank(Con);
n = size(A, 1);

% Display results
% disp('Controllability Matrix:');
% disp(Con);
fprintf('Rank of controllability matrix: %d (out of %d states)\n', rank_Con, n);

if rank_Con == n
    disp('The system is FULLY CONTROLLABLE.');
else
    fprintf('The system is PARTIALLY CONTROLLABLE.\n');
    fprintf('Only %d out of %d states can be controlled.\n', rank_Con, n);
end

%% Full state feedback control with Integrator          
% Augmented system
n = size(A, 1);          % Original state size = 3
m = size(C, 1);          % Number of outputs = number of integrators = 2

Ai = [
        A, zeros(n, m);
        -C, zeros(m, m);
    ];

Bi = [
        B;
        zeros(m, size(B,2))
    ];


% Desired poles
% You choose the closed-loop poles. Example:
xi = 1;       % damping ratio       
f = 7; %1 < f < 5
wn = 2*pi*f/xi; % wn = 2*pi*f/xi % natural frequency

% Choose one fast real pole and two complex poles for each input
lambda1 = -90;                                      % real pole
lambda2 = -xi*wn + wn*sqrt(xi^2 - 1);          % real or complex
lambda3 = -xi*wn - wn*sqrt(xi^2 - 1);

% Add two more poles for integrator dynamics (make them slower or same range)
lambda4 = -100;
lambda5 = -100;

desired_poles = [lambda1 lambda2 lambda3 lambda4 lambda5];

% Pole placement
K = place(Ai, Bi, desired_poles);

Kx  = K(:, 1:n);        % Feedback gain for original state
Ki = -K(:, n+1:end);    % Feedback gain for integrators

% Simulink or simulation setup
% Control law: u = -Kx*X + Ki*X_i
% Integrator dynamics: dot(X_i) = Yr - C*X

disp('Pole desired Lambda = ');
disp(desired_poles);

disp('State feedback gain Kx = ');
disp(Kx);

disp('Integrator gain Ki = ');
disp(Ki);


%% SVPWM
Ts_pwm = 1e-4;
Vdc = 48*sqrt(3);

%% Optimization
Rc = 56.33; %Rc = (Vph_rms/sqrt(3))^2/(0.02*rated_power)
Tc = 0.001;

