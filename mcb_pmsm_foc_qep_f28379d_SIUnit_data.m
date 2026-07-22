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

%% Displaying model variables
disp(pmsm);
disp(inverter);
disp(target);

