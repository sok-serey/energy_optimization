/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.h
 *
 * Code generated for Simulink model 'testing'.
 *
 * Model version                  : 1.46
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Tue Aug 11 13:47:40 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef testing_h_
#define testing_h_
#ifndef testing_COMMON_INCLUDES_
#define testing_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "rtw_extmode.h"
#include "sysran_types.h"
#include "rtw_continuous.h"
#include "rtw_solver.h"
#include "ext_mode.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                                 /* testing_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "testing_types.h"
#include "rt_nonfinite.h"
#include "rtGetNaN.h"
#include <string.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetFinalTime
#define rtmGetFinalTime(rtm)           ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetRTWExtModeInfo
#define rtmGetRTWExtModeInfo(rtm)      ((rtm)->extModeInfo)
#endif

#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
#define rtmGetStopRequested(rtm)       ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
#define rtmSetStopRequested(rtm, val)  ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
#define rtmGetStopRequestedPtr(rtm)    (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetTFinal
#define rtmGetTFinal(rtm)              ((rtm)->Timing.tFinal)
#endif

#ifndef rtmGetTPtr
#define rtmGetTPtr(rtm)                (&)
#endif

extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void initBoardEnd(void);

/* Block states (default storage) for system '<S71>/If Action Subsystem' */
typedef struct {
  int16_T IfActionSubsystem_SubsysRanBC;/* '<S71>/If Action Subsystem' */
} DW_IfActionSubsystem_testing_T;

/* Block states (default storage) for system '<S71>/If Action Subsystem1' */
typedef struct {
  int16_T IfActionSubsystem1_SubsysRanBC;/* '<S71>/If Action Subsystem1' */
} DW_IfActionSubsystem1_testing_T;

/* Block signals for system '<S147>/SPI Master Transfer' */
typedef struct {
  uint16_T SPIMasterTransfer;          /* '<S147>/SPI Master Transfer' */
} B_SPIMasterTransfer_testing_T;

/* Block states (default storage) for system '<S147>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SP_T obj; /* '<S147>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S147>/SPI Master Transfer' */
} DW_SPIMasterTransfer_testing_T;

/* Block signals for system '<Root>/Speed Control' */
typedef struct {
  real32_T Switch;                     /* '<S158>/Switch' */
  real32_T Sum;                        /* '<S157>/Sum' */
} B_SpeedControl_testing_T;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S157>/Scope' */

  real32_T Delay_DSTATE;               /* '<S217>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S197>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S197>/Integrator' */
  boolean_T icLoad;                    /* '<S217>/Delay' */
} DW_SpeedControl_testing_T;

/* Block signals (default storage) */
typedef struct {
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T Add1;                       /* '<S152>/Add1' */
  real32_T Add1_g;                     /* '<S155>/Add1' */
  real32_T abs_dP_trace;               /* '<Root>/Abs' */
  real32_T Switch[2];                  /* '<Root>/Switch' */
  real32_T RT1;                        /* '<Root>/RT1' */
  real32_T trP;                        /* '<Root>/MATLAB Function2' */
  real32_T Ks;                         /* '<Root>/MATLAB Function1' */
  real32_T Kis;                        /* '<Root>/MATLAB Function1' */
  real32_T x[4];                       /* '<Root>/MATLAB Function' */
  real32_T Add1_f;                     /* '<S112>/Add1' */
  real32_T Add;                        /* '<S118>/Add' */
  real32_T GetCurrents[2];             /* '<S103>/Get Currents' */
  real32_T OutportBufferForIq_measure; /* '<S3>/Control_System' */
  real32_T Add1_h;                     /* '<S104>/Add1' */
  real32_T PWM_Duty_Cycles[3];         /* '<S15>/Switch4' */
  real32_T Eps;                        /* '<S80>/Ramp Generator' */
  real32_T Sum1[3];                    /* '<S78>/Sum1' */
  real32_T Sum[3];                     /* '<S25>/Sum' */
  real32_T algDD_o1;                   /* '<S56>/algDD' */
  real32_T algDD_o2;                   /* '<S56>/algDD' */
  uint16_T ADC_A_IN0;                  /* '<S141>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S141>/ADC_B_IN0' */
  uint16_T eQEP_o1;                    /* '<S101>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S101>/eQEP' */
  uint16_T ADC_C_IN2;                  /* '<S101>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S101>/ADC_B_IN2' */
  uint16_T Switch_o;                   /* '<S139>/Switch' */
  boolean_T AND;                       /* '<Root>/AND' */
  boolean_T AND_l;                     /* '<S106>/AND' */
  boolean_T Switch_k;                  /* '<S133>/Switch' */
  B_SpeedControl_testing_T SpeedControl;/* '<Root>/Speed Control' */
  B_SPIMasterTransfer_testing_T SPIMasterTransfer1;/* '<S147>/SPI Master Transfer' */
  B_SPIMasterTransfer_testing_T SPIMasterTransfer;/* '<S147>/SPI Master Transfer' */
} B_testing_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T lastSin;                      /* '<Root>/Sine Wave' */
  real_T lastCos;                      /* '<Root>/Sine Wave' */
  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<Root>/Scope' */

  struct {
    void *LoggedData[3];
  } Scope1_PWORK;                      /* '<Root>/Scope1' */

  real32_T UnitDelay_DSTATE[4];        /* '<Root>/Unit Delay' */
  real32_T UnitDelay1_DSTATE[16];      /* '<Root>/Unit Delay1' */
  real32_T Delay_DSTATE;               /* '<S152>/Delay' */
  real32_T Delay_DSTATE_d;             /* '<S155>/Delay' */
  real32_T UD_DSTATE;                  /* '<S4>/UD' */
  real32_T UnitDelay3_DSTATE[2];       /* '<Root>/Unit Delay3' */
  real32_T Delay_DSTATE_n;             /* '<S112>/Delay' */
  real32_T Delay_DSTATE_l;             /* '<S104>/Delay' */
  real32_T Delay1_DSTATE;              /* '<S104>/Delay1' */
  real32_T RampGenerator_DSTATE;       /* '<S80>/Ramp Generator' */
  real32_T Delay_DSTATE_h;             /* '<S79>/Delay' */
  real32_T DiscreteTimeIntegrator_DSTATE[2];/* '<S22>/Discrete-Time Integrator' */
  uint32_T Delay_DSTATE_b[20];         /* '<S109>/Delay' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  volatile real32_T RT7_Buffer[2];     /* '<Root>/RT7' */
  volatile real32_T RT8_Buffer[2];     /* '<Root>/RT8' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  real32_T Speed_ref;                  /* '<Root>/Data Store Memory4' */
  real32_T DiscreteTimeIntegrator_PREV_U[2];/* '<S22>/Discrete-Time Integrator' */
  int32_T systemEnable;                /* '<Root>/Sine Wave' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S149>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_a;    /* '<S139>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S139>/Digital Output1' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S133>/DRV830x Enable' */
  uint32_T ClosedLoopControl_PREV_T;   /* '<S15>/Closed Loop Control' */
  uint16_T Delay3_DSTATE;              /* '<S106>/Delay3' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  volatile int16_T RT7_ActiveBufIdx;   /* '<Root>/RT7' */
  volatile int16_T RT7_semaphoreTaken; /* '<Root>/RT7' */
  volatile int16_T RT8_ActiveBufIdx;   /* '<Root>/RT8' */
  volatile int16_T RT8_semaphoreTaken; /* '<Root>/RT8' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T CircBufIdx;                 /* '<S109>/Delay' */
  int16_T DefaultADCOffset_SubsysRanBC;/* '<S137>/Default ADC Offset' */
  int16_T ADCGainSetting_SubsysRanBC;  /* '<S139>/ADC Gain Setting' */
  int16_T CalculateADCOffset_SubsysRanBC;/* '<S137>/Calculate ADC Offset ' */
  int16_T IfActionSubsystem3_SubsysRanBC;/* '<S138>/If Action Subsystem3' */
  int16_T IfActionSubsystem2_SubsysRanBC;/* '<S138>/If Action Subsystem2' */
  int16_T IfActionSubsystem1_SubsysRanBC;/* '<S138>/If Action Subsystem1' */
  int16_T IfActionSubsystem_SubsysRanBC;/* '<S138>/If Action Subsystem' */
  int16_T IfActionSubsystem_SubsysRanBC_g;/* '<S141>/If Action Subsystem' */
  int16_T CurrentControl_SubsysRanBC;  /* '<Root>/Current Control' */
  int16_T PositionResetAtIndex_SubsysRanB;/* '<S108>/PositionResetAtIndex' */
  int16_T PositionNoReset_SubsysRanBC; /* '<S108>/PositionNoReset' */
  int16_T IfActionSubsystem1_SubsysRanB_i;/* '<S117>/If Action Subsystem1' */
  int16_T IfActionSubsystem_SubsysRanBC_a;/* '<S117>/If Action Subsystem' */
  int16_T IndexFinder_SubsysRanBC;     /* '<S102>/IndexFinder' */
  int16_T CalculatePosition_SubsysRanBC;/* '<S102>/Calculate Position' */
  int16_T OpenLoopStartUp_SubsysRanBC; /* '<S15>/Open Loop Start-Up' */
  int16_T ClosedLoopControl_SubsysRanBC;/* '<S15>/Closed Loop Control' */
  int16_T DQEquivalence_SubsysRanBC;   /* '<S32>/D-Q Equivalence' */
  int16_T Passthrough_SubsysRanBC;     /* '<S35>/Passthrough' */
  int16_T Limiter_SubsysRanBC;         /* '<S35>/Limiter' */
  int16_T DorQAxisPriority_SubsysRanBC;/* '<S32>/D or Q Axis Priority' */
  int16_T limitRef2_SubsysRanBC;       /* '<S42>/limitRef2' */
  int16_T passThrough_SubsysRanBC;     /* '<S42>/passThrough' */
  uint16_T DiscreteTimeIntegrator_SYSTEM_E;/* '<S22>/Discrete-Time Integrator' */
  boolean_T icLoad;                    /* '<S152>/Delay' */
  boolean_T icLoad_m;                  /* '<S155>/Delay' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T doneDoubleBufferReInit;    /* '<Root>/MATLAB Function2' */
  boolean_T doneDoubleBufferReInit_m;  /* '<Root>/MATLAB Function1' */
  boolean_T doneDoubleBufferReInit_e;  /* '<Root>/MATLAB Function' */
  boolean_T icLoad_j;                  /* '<S112>/Delay' */
  boolean_T icLoad_i;                  /* '<S79>/Delay' */
  boolean_T ClosedLoopControl_RESET_ELAPS_T;/* '<S15>/Closed Loop Control' */
  boolean_T doneDoubleBufferReInit_a;  /* '<S22>/MATLAB Function' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S15>/Open Loop Start-Up' */
  boolean_T ClosedLoopControl_MODE;    /* '<S15>/Closed Loop Control' */
  DW_SpeedControl_testing_T SpeedControl;/* '<Root>/Speed Control' */
  DW_SPIMasterTransfer_testing_T SPIMasterTransfer1;/* '<S147>/SPI Master Transfer' */
  DW_SPIMasterTransfer_testing_T SPIMasterTransfer;/* '<S147>/SPI Master Transfer' */
  DW_IfActionSubsystem1_testing_T IfActionSubsystem1_ju;/* '<S95>/If Action Subsystem1' */
  DW_IfActionSubsystem_testing_T IfActionSubsystem_b;/* '<S95>/If Action Subsystem' */
  DW_IfActionSubsystem1_testing_T IfActionSubsystem1_j;/* '<S71>/If Action Subsystem1' */
  DW_IfActionSubsystem_testing_T IfActionSubsystem_o;/* '<S71>/If Action Subsystem' */
} DW_testing_T;

/* Parameters for system: '<S50>/Two inputs CRL' */
struct P_TwoinputsCRL_testing_T_ {
  uint16_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S52>/Offset'
                                        */
  uint16_T Switch_Threshold;           /* Computed Parameter: Switch_Threshold
                                        * Referenced by: '<S52>/Switch'
                                        */
};

/* Parameters for system: '<Root>/Speed Control' */
struct P_SpeedControl_testing_T_ {
  real32_T DiscretePIControllerwithantiwin;
                              /* Mask Parameter: DiscretePIControllerwithantiwin
                               * Referenced by:
                               *   '<S204>/Saturation'
                               *   '<S189>/DeadZone'
                               */
  real32_T DiscretePIControllerwithantiw_p;
                              /* Mask Parameter: DiscretePIControllerwithantiw_p
                               * Referenced by:
                               *   '<S204>/Saturation'
                               *   '<S189>/DeadZone'
                               */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S187>/Constant1'
                                        */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S160>/a'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S160>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S160>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S160>/OneMinusFilterConstant'
                              */
  real32_T Id_ref_Value;               /* Computed Parameter: Id_ref_Value
                                        * Referenced by: '<S14>/Id_ref'
                                        */
  real32_T IC_Value;                   /* Computed Parameter: IC_Value
                                        * Referenced by: '<S160>/IC'
                                        */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S160>/UseInputPort'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S160>/Switch1'
                                        */
  real32_T Clamping_zero_Value;       /* Computed Parameter: Clamping_zero_Value
                                       * Referenced by: '<S187>/Clamping_zero'
                                       */
  real32_T Ki2_Value;                  /* Computed Parameter: Ki2_Value
                                        * Referenced by: '<S157>/Ki2'
                                        */
  real32_T Integrator_gainval;         /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S197>/Integrator'
                                        */
  boolean_T Reset_Value;               /* Computed Parameter: Reset_Value
                                        * Referenced by: '<S160>/Reset'
                                        */
  int16_T Constant_Value;              /* Computed Parameter: Constant_Value
                                        * Referenced by: '<S187>/Constant'
                                        */
  int16_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S187>/Constant2'
                                        */
  int16_T Constant3_Value;             /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S187>/Constant3'
                                        */
  int16_T Constant4_Value;             /* Computed Parameter: Constant4_Value
                                        * Referenced by: '<S187>/Constant4'
                                        */
};

/* Parameters (default storage) */
struct P_testing_T_ {
  real32_T K;                          /* Variable: K
                                        * Referenced by: '<S22>/Gain1'
                                        */
  real32_T Ki;                         /* Variable: Ki
                                        * Referenced by: '<S22>/Gain'
                                        */
  real32_T Ts;                         /* Variable: Ts
                                        * Referenced by: '<S80>/Sample_Time'
                                        */
  real32_T DiscreteDerivative_ICPrevScaled;
                              /* Mask Parameter: DiscreteDerivative_ICPrevScaled
                               * Referenced by: '<S4>/UD'
                               */
  real32_T MechanicaltoElectricalPosition_;
                              /* Mask Parameter: MechanicaltoElectricalPosition_
                               * Referenced by: '<S122>/Number of pole pairs'
                               */
  real32_T CompareToConstant1_const; /* Mask Parameter: CompareToConstant1_const
                                      * Referenced by: '<S2>/Constant'
                                      */
  real32_T CompareToConstant_const;   /* Mask Parameter: CompareToConstant_const
                                       * Referenced by: '<S1>/Constant'
                                       */
  uint16_T CompareToConstant_const_g;
                                    /* Mask Parameter: CompareToConstant_const_g
                                     * Referenced by: '<S38>/Constant'
                                     */
  uint16_T CompareToConstant1_const_p;
                                   /* Mask Parameter: CompareToConstant1_const_p
                                    * Referenced by: '<S39>/Constant'
                                    */
  uint16_T CompareToConstant_const_j;
                                    /* Mask Parameter: CompareToConstant_const_j
                                     * Referenced by: '<S113>/Constant'
                                     */
  uint16_T CompareToConstant1_const_n;
                                   /* Mask Parameter: CompareToConstant1_const_n
                                    * Referenced by: '<S114>/Constant'
                                    */
  real_T Constant_Value;               /* Expression: inverter.EnableLogic
                                        * Referenced by: '<S133>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S133>/Switch'
                                        */
  real_T Constant_Value_l;             /* Expression: 8
                                        * Referenced by: '<S138>/Constant'
                                        */
  real_T Constant_Value_b;             /* Expression: inverter.EnableLogic
                                        * Referenced by: '<S139>/Constant'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 0
                                        * Referenced by: '<S139>/Switch'
                                        */
  real_T ADCCalibrationEnable_Value;/* Expression: inverter.ADCOffsetCalibEnable
                                     * Referenced by: '<S137>/ADC Calibration Enable'
                                     */
  real_T Constant2_Value;              /* Expression: 100
                                        * Referenced by: '<Root>/Constant2'
                                        */
  real_T SineWave_Amp;                 /* Expression: 100
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Bias;                /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Freq;                /* Expression: 5
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Phase;               /* Expression: 0
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_Hsin;                /* Computed Parameter: SineWave_Hsin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_HCos;                /* Computed Parameter: SineWave_HCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PSin;                /* Computed Parameter: SineWave_PSin
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  real_T SineWave_PCos;                /* Computed Parameter: SineWave_PCos
                                        * Referenced by: '<Root>/Sine Wave'
                                        */
  int32_T GetADCVoltage_Gain;          /* Computed Parameter: GetADCVoltage_Gain
                                        * Referenced by: '<S103>/Get ADC Voltage'
                                        */
  real32_T one_by_sqrt3_Gain;          /* Computed Parameter: one_by_sqrt3_Gain
                                        * Referenced by: '<S31>/one_by_sqrt3'
                                        */
  real32_T Constant_Value_e;           /* Computed Parameter: Constant_Value_e
                                        * Referenced by: '<S44>/Constant'
                                        */
  real32_T Gain_Gain;                  /* Computed Parameter: Gain_Gain
                                        * Referenced by: '<S44>/Gain'
                                        */
  real32_T Switch1_Threshold;          /* Computed Parameter: Switch1_Threshold
                                        * Referenced by: '<S44>/Switch1'
                                        */
  real32_T Switch_Threshold_i;         /* Computed Parameter: Switch_Threshold_i
                                        * Referenced by: '<S44>/Switch'
                                        */
  real32_T Gain_Gain_d;                /* Computed Parameter: Gain_Gain_d
                                        * Referenced by: '<S42>/Gain'
                                        */
  real32_T Constant_Value_h;           /* Computed Parameter: Constant_Value_h
                                        * Referenced by: '<S46>/Constant'
                                        */
  real32_T ReplaceInport_satLim_Value;
                               /* Computed Parameter: ReplaceInport_satLim_Value
                                * Referenced by: '<S32>/ReplaceInport_satLim'
                                */
  real32_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S36>/Constant3'
                                        */
  real32_T Iq_Y0;                      /* Computed Parameter: Iq_Y0
                                        * Referenced by: '<S19>/Iq'
                                        */
  real32_T Duty_abc_Y0;                /* Computed Parameter: Duty_abc_Y0
                                        * Referenced by: '<S19>/Duty_abc'
                                        */
  real32_T Kalpha_Gain;                /* Computed Parameter: Kalpha_Gain
                                        * Referenced by: '<S30>/Kalpha'
                                        */
  real32_T Kbeta_Gain;                 /* Computed Parameter: Kbeta_Gain
                                        * Referenced by: '<S30>/Kbeta'
                                        */
  real32_T sine_table_values_Value[1002];
                                  /* Computed Parameter: sine_table_values_Value
                                   * Referenced by: '<S69>/sine_table_values'
                                   */
  real32_T convert_pu_Gain;            /* Computed Parameter: convert_pu_Gain
                                        * Referenced by: '<S71>/convert_pu'
                                        */
  real32_T Constant_Value_bi;          /* Computed Parameter: Constant_Value_bi
                                        * Referenced by: '<S73>/Constant'
                                        */
  real32_T indexing_Gain;              /* Computed Parameter: indexing_Gain
                                        * Referenced by: '<S69>/indexing'
                                        */
  real32_T DiscreteTimeIntegrator_gainval;
                           /* Computed Parameter: DiscreteTimeIntegrator_gainval
                            * Referenced by: '<S22>/Discrete-Time Integrator'
                            */
  real32_T DiscreteTimeIntegrator_IC;
                                /* Computed Parameter: DiscreteTimeIntegrator_IC
                                 * Referenced by: '<S22>/Discrete-Time Integrator'
                                 */
  real32_T Constant_Value_g;           /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S25>/Constant'
                                        */
  real32_T Ka_Gain;                    /* Computed Parameter: Ka_Gain
                                        * Referenced by: '<S68>/Ka'
                                        */
  real32_T one_by_two_Gain;            /* Computed Parameter: one_by_two_Gain
                                        * Referenced by: '<S68>/one_by_two'
                                        */
  real32_T sqrt3_by_two_Gain;          /* Computed Parameter: sqrt3_by_two_Gain
                                        * Referenced by: '<S68>/sqrt3_by_two'
                                        */
  real32_T Kb_Gain;                    /* Computed Parameter: Kb_Gain
                                        * Referenced by: '<S68>/Kb'
                                        */
  real32_T Kc_Gain;                    /* Computed Parameter: Kc_Gain
                                        * Referenced by: '<S68>/Kc'
                                        */
  real32_T one_by_two_Gain_f;          /* Computed Parameter: one_by_two_Gain_f
                                        * Referenced by: '<S62>/one_by_two'
                                        */
  real32_T Gain_Gain_k;                /* Computed Parameter: Gain_Gain_k
                                        * Referenced by: '<S61>/Gain'
                                        */
  real32_T Normalize05to05_Gain;     /* Computed Parameter: Normalize05to05_Gain
                                      * Referenced by: '<S25>/Normalize [-0.5 to 0.5]'
                                      */
  real32_T Bias1_Value;                /* Computed Parameter: Bias1_Value
                                        * Referenced by: '<S79>/Bias1'
                                        */
  real32_T Bias2_Value;                /* Computed Parameter: Bias2_Value
                                        * Referenced by: '<S79>/Bias2'
                                        */
  real32_T _Value;                     /* Computed Parameter: _Value
                                        * Referenced by: '<S20>/ '
                                        */
  real32_T Duty_abc_Y0_i;              /* Computed Parameter: Duty_abc_Y0_i
                                        * Referenced by: '<S20>/Duty_abc'
                                        */
  real32_T Constant_Value_h2;          /* Computed Parameter: Constant_Value_h2
                                        * Referenced by: '<S77>/Constant'
                                        */
  real32_T Ramp_Timesec1_Value;       /* Computed Parameter: Ramp_Timesec1_Value
                                       * Referenced by: '<S20>/Ramp_Time (sec)1'
                                       */
  real32_T rpm2freq_Gain;              /* Computed Parameter: rpm2freq_Gain
                                        * Referenced by: '<S20>/rpm2freq'
                                        */
  real32_T RampGenerator_gainval;   /* Computed Parameter: RampGenerator_gainval
                                     * Referenced by: '<S80>/Ramp Generator'
                                     */
  real32_T RampGenerator_IC;           /* Computed Parameter: RampGenerator_IC
                                        * Referenced by: '<S80>/Ramp Generator'
                                        */
  real32_T RampGenerator_UpperSat; /* Computed Parameter: RampGenerator_UpperSat
                                    * Referenced by: '<S80>/Ramp Generator'
                                    */
  real32_T RampGenerator_LowerSat; /* Computed Parameter: RampGenerator_LowerSat
                                    * Referenced by: '<S80>/Ramp Generator'
                                    */
  real32_T Vbyf_Gain;                  /* Computed Parameter: Vbyf_Gain
                                        * Referenced by: '<S20>/V-by-f'
                                        */
  real32_T Correction_Factor_sinePWM_Gain;
                           /* Computed Parameter: Correction_Factor_sinePWM_Gain
                            * Referenced by: '<S20>/Correction_Factor_sinePWM'
                            */
  real32_T Saturation_UpperSat;       /* Computed Parameter: Saturation_UpperSat
                                       * Referenced by: '<S20>/Saturation'
                                       */
  real32_T Saturation_LowerSat;       /* Computed Parameter: Saturation_LowerSat
                                       * Referenced by: '<S20>/Saturation'
                                       */
  real32_T sine_table_values_Value_b[1002];
                                /* Computed Parameter: sine_table_values_Value_b
                                 * Referenced by: '<S93>/sine_table_values'
                                 */
  real32_T position_increment_Gain;
                                  /* Computed Parameter: position_increment_Gain
                                   * Referenced by: '<S20>/position_increment'
                                   */
  real32_T InputGain_Value;            /* Computed Parameter: InputGain_Value
                                        * Referenced by: '<S79>/InputGain'
                                        */
  real32_T Offset_Value;               /* Computed Parameter: Offset_Value
                                        * Referenced by: '<S79>/Offset'
                                        */
  real32_T Switch1_Threshold_e;       /* Computed Parameter: Switch1_Threshold_e
                                       * Referenced by: '<S79>/Switch1'
                                       */
  real32_T Switch2_Threshold;          /* Computed Parameter: Switch2_Threshold
                                        * Referenced by: '<S79>/Switch2'
                                        */
  real32_T OutputGain_Value;           /* Computed Parameter: OutputGain_Value
                                        * Referenced by: '<S79>/OutputGain'
                                        */
  real32_T Direction_Threshold;       /* Computed Parameter: Direction_Threshold
                                       * Referenced by: '<S20>/Direction'
                                       */
  real32_T convert_pu_Gain_c;          /* Computed Parameter: convert_pu_Gain_c
                                        * Referenced by: '<S95>/convert_pu'
                                        */
  real32_T Constant_Value_d;           /* Computed Parameter: Constant_Value_d
                                        * Referenced by: '<S97>/Constant'
                                        */
  real32_T indexing_Gain_o;            /* Computed Parameter: indexing_Gain_o
                                        * Referenced by: '<S93>/indexing'
                                        */
  real32_T Ka_Gain_l;                  /* Computed Parameter: Ka_Gain_l
                                        * Referenced by: '<S87>/Ka'
                                        */
  real32_T one_by_two_Gain_j;          /* Computed Parameter: one_by_two_Gain_j
                                        * Referenced by: '<S87>/one_by_two'
                                        */
  real32_T sqrt3_by_two_Gain_h;       /* Computed Parameter: sqrt3_by_two_Gain_h
                                       * Referenced by: '<S87>/sqrt3_by_two'
                                       */
  real32_T Kb_Gain_g;                  /* Computed Parameter: Kb_Gain_g
                                        * Referenced by: '<S87>/Kb'
                                        */
  real32_T Kc_Gain_h;                  /* Computed Parameter: Kc_Gain_h
                                        * Referenced by: '<S87>/Kc'
                                        */
  real32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S78>/Constant'
                                        */
  real32_T Normalize_Gain;             /* Computed Parameter: Normalize_Gain
                                        * Referenced by: '<S78>/Normalize'
                                        */
  real32_T One_Value;                  /* Computed Parameter: One_Value
                                        * Referenced by: '<S80>/One'
                                        */
  real32_T Ramp_Timesec_Value;         /* Computed Parameter: Ramp_Timesec_Value
                                        * Referenced by: '<S20>/Ramp_Time (sec)'
                                        */
  real32_T Constant1_Value;            /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<S104>/Constant1'
                                        */
  real32_T Constant_Value_a;           /* Computed Parameter: Constant_Value_a
                                        * Referenced by: '<S104>/Constant'
                                        */
  real32_T Switch_Threshold_k;         /* Computed Parameter: Switch_Threshold_k
                                        * Referenced by: '<S104>/Switch'
                                        */
  real32_T Pos_Y0;                     /* Computed Parameter: Pos_Y0
                                        * Referenced by: '<S104>/Pos'
                                        */
  real32_T Delay_InitialCondition; /* Computed Parameter: Delay_InitialCondition
                                    * Referenced by: '<S104>/Delay'
                                    */
  real32_T Switch1_Threshold_o;       /* Computed Parameter: Switch1_Threshold_o
                                       * Referenced by: '<S104>/Switch1'
                                       */
  real32_T Delay1_InitialCondition;
                                  /* Computed Parameter: Delay1_InitialCondition
                                   * Referenced by: '<S104>/Delay1'
                                   */
  real32_T SpeedGain_Gain;
                  /* Expression: single(2*pi)/(20*SampleTimeAsync(1)*4294967296)
                   * Referenced by: '<S109>/SpeedGain'
                   */
  real32_T a_Value;                    /* Computed Parameter: a_Value
                                        * Referenced by: '<S105>/a'
                                        */
  real32_T One_Value_n;                /* Computed Parameter: One_Value_n
                                        * Referenced by: '<S105>/One'
                                        */
  real32_T FilterConstant_Value;     /* Computed Parameter: FilterConstant_Value
                                      * Referenced by: '<S105>/FilterConstant'
                                      */
  real32_T OneMinusFilterConstant_Value;
                             /* Computed Parameter: OneMinusFilterConstant_Value
                              * Referenced by: '<S105>/OneMinusFilterConstant'
                              */
  real32_T Constant_Value_fl;          /* Computed Parameter: Constant_Value_fl
                                        * Referenced by: '<S119>/Constant'
                                        */
  real32_T Constant1_Value_f;          /* Computed Parameter: Constant1_Value_f
                                        * Referenced by: '<S116>/Constant1'
                                        */
  real32_T IndexOffset_Value;          /* Computed Parameter: IndexOffset_Value
                                        * Referenced by: '<S17>/IndexOffset'
                                        */
  real32_T Scale_to_PWM_Counter_PRD_Gain;
                            /* Computed Parameter: Scale_to_PWM_Counter_PRD_Gain
                             * Referenced by: '<S133>/Scale_to_PWM_Counter_PRD'
                             */
  real32_T Duty_Cycles_Y0;             /* Computed Parameter: Duty_Cycles_Y0
                                        * Referenced by: '<S3>/Duty_Cycles'
                                        */
  real32_T Speed_meas_Y0;              /* Computed Parameter: Speed_meas_Y0
                                        * Referenced by: '<S3>/Speed_meas'
                                        */
  real32_T MechPos_Cont_Y0;            /* Computed Parameter: MechPos_Cont_Y0
                                        * Referenced by: '<S3>/MechPos_Cont'
                                        */
  real32_T Iq_measure_Y0;              /* Computed Parameter: Iq_measure_Y0
                                        * Referenced by: '<S3>/Iq_measure'
                                        */
  real32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S130>/Constant'
                                        */
  real32_T IC_Value;                   /* Computed Parameter: IC_Value
                                        * Referenced by: '<S105>/IC'
                                        */
  real32_T PositionToCount_Gain;     /* Computed Parameter: PositionToCount_Gain
                                      * Referenced by: '<S109>/PositionToCount'
                                      */
  real32_T UseInputPort_Value;         /* Computed Parameter: UseInputPort_Value
                                        * Referenced by: '<S105>/UseInputPort'
                                        */
  real32_T Switch1_Threshold_a;       /* Computed Parameter: Switch1_Threshold_a
                                       * Referenced by: '<S105>/Switch1'
                                       */
  real32_T Multiply_Gain;              /* Computed Parameter: Multiply_Gain
                                        * Referenced by: '<S118>/Multiply'
                                        */
  real32_T Multiply1_Gain;             /* Computed Parameter: Multiply1_Gain
                                        * Referenced by: '<S118>/Multiply1'
                                        */
  real32_T GetCurrents_Gain;           /* Computed Parameter: GetCurrents_Gain
                                        * Referenced by: '<S103>/Get Currents'
                                        */
  real32_T a_Value_c;                  /* Computed Parameter: a_Value_c
                                        * Referenced by: '<S8>/a'
                                        */
  real32_T One_Value_o;                /* Computed Parameter: One_Value_o
                                        * Referenced by: '<S8>/One'
                                        */
  real32_T FilterConstant_Value_f; /* Computed Parameter: FilterConstant_Value_f
                                    * Referenced by: '<S8>/FilterConstant'
                                    */
  real32_T OneMinusFilterConstant_Value_b;
                           /* Computed Parameter: OneMinusFilterConstant_Value_b
                            * Referenced by: '<S8>/OneMinusFilterConstant'
                            */
  real32_T a_Value_f;                  /* Computed Parameter: a_Value_f
                                        * Referenced by: '<S9>/a'
                                        */
  real32_T One_Value_n5;               /* Computed Parameter: One_Value_n5
                                        * Referenced by: '<S9>/One'
                                        */
  real32_T FilterConstant_Value_n; /* Computed Parameter: FilterConstant_Value_n
                                    * Referenced by: '<S9>/FilterConstant'
                                    */
  real32_T OneMinusFilterConstant_Value_k;
                           /* Computed Parameter: OneMinusFilterConstant_Value_k
                            * Referenced by: '<S9>/OneMinusFilterConstant'
                            */
  real32_T IC_Value_m;                 /* Computed Parameter: IC_Value_m
                                        * Referenced by: '<S8>/IC'
                                        */
  real32_T UnitDelay_InitialCondition[4];
                               /* Computed Parameter: UnitDelay_InitialCondition
                                * Referenced by: '<Root>/Unit Delay'
                                */
  real32_T UnitDelay1_InitialCondition[16];
                              /* Computed Parameter: UnitDelay1_InitialCondition
                               * Referenced by: '<Root>/Unit Delay1'
                               */
  real32_T RT2_InitialCondition;     /* Computed Parameter: RT2_InitialCondition
                                      * Referenced by: '<Root>/RT2'
                                      */
  real32_T RT7_InitialCondition;     /* Computed Parameter: RT7_InitialCondition
                                      * Referenced by: '<Root>/RT7'
                                      */
  real32_T RT8_InitialCondition;     /* Computed Parameter: RT8_InitialCondition
                                      * Referenced by: '<Root>/RT8'
                                      */
  real32_T UseInputPort_Value_f;     /* Computed Parameter: UseInputPort_Value_f
                                      * Referenced by: '<S8>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_f;       /* Computed Parameter: Switch1_Threshold_f
                                       * Referenced by: '<S8>/Switch1'
                                       */
  real32_T IC_Value_n;                 /* Computed Parameter: IC_Value_n
                                        * Referenced by: '<S9>/IC'
                                        */
  real32_T UseInputPort_Value_n;     /* Computed Parameter: UseInputPort_Value_n
                                      * Referenced by: '<S9>/UseInputPort'
                                      */
  real32_T Switch1_Threshold_n;       /* Computed Parameter: Switch1_Threshold_n
                                       * Referenced by: '<S9>/Switch1'
                                       */
  real32_T TSamp_WtEt;                 /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S4>/TSamp'
                                        */
  real32_T UnitDelay3_InitialCondition[2];
                              /* Computed Parameter: UnitDelay3_InitialCondition
                               * Referenced by: '<Root>/Unit Delay3'
                               */
  real32_T RT1_InitialCondition;     /* Computed Parameter: RT1_InitialCondition
                                      * Referenced by: '<Root>/RT1'
                                      */
  real32_T DataStoreMemory4_InitialValue;
                            /* Computed Parameter: DataStoreMemory4_InitialValue
                             * Referenced by: '<Root>/Data Store Memory4'
                             */
  uint32_T Delay_InitialCondition_g;
                                 /* Computed Parameter: Delay_InitialCondition_g
                                  * Referenced by: '<S109>/Delay'
                                  */
  int16_T offset_Value[4];             /* Computed Parameter: offset_Value
                                        * Referenced by: '<S69>/offset'
                                        */
  int16_T offset_Value_j[4];           /* Computed Parameter: offset_Value_j
                                        * Referenced by: '<S93>/offset'
                                        */
  int16_T ResetMode_Value;             /* Computed Parameter: ResetMode_Value
                                        * Referenced by: '<S108>/ResetMode'
                                        */
  uint16_T ReplaceInport_satMethod_Value;
                            /* Computed Parameter: ReplaceInport_satMethod_Value
                             * Referenced by: '<S32>/ReplaceInport_satMethod'
                             */
  uint16_T ChosenMethod_Value;         /* Computed Parameter: ChosenMethod_Value
                                        * Referenced by: '<S36>/ChosenMethod'
                                        */
  uint16_T Offset_Value_j;             /* Computed Parameter: Offset_Value_j
                                        * Referenced by: '<S57>/Offset'
                                        */
  uint16_T Switch_Threshold_j;         /* Computed Parameter: Switch_Threshold_j
                                        * Referenced by: '<S57>/Switch'
                                        */
  uint16_T enableInportSatMethod_Value;
                              /* Computed Parameter: enableInportSatMethod_Value
                               * Referenced by: '<S36>/enableInportSatMethod'
                               */
  uint16_T enableInportSatLim_Value;
                                 /* Computed Parameter: enableInportSatLim_Value
                                  * Referenced by: '<S36>/enableInportSatLim'
                                  */
  uint16_T Delay3_InitialCondition;
                                  /* Computed Parameter: Delay3_InitialCondition
                                   * Referenced by: '<S106>/Delay3'
                                   */
  uint16_T Constant_Value_ep;          /* Computed Parameter: Constant_Value_ep
                                        * Referenced by: '<S129>/Constant'
                                        */
  uint16_T stop_Value;                 /* Computed Parameter: stop_Value
                                        * Referenced by: '<S133>/stop'
                                        */
  uint16_T Out1_Y0;                    /* Computed Parameter: Out1_Y0
                                        * Referenced by: '<S146>/Out1'
                                        */
  uint16_T Out2_Y0;                    /* Computed Parameter: Out2_Y0
                                        * Referenced by: '<S146>/Out2'
                                        */
  uint16_T Memory_InitialCondition;
                                  /* Computed Parameter: Memory_InitialCondition
                                   * Referenced by: '<S146>/Memory'
                                   */
  uint16_T Memory1_InitialCondition;
                                 /* Computed Parameter: Memory1_InitialCondition
                                  * Referenced by: '<S146>/Memory1'
                                  */
  uint16_T ForIterator_IterationLimit;
                               /* Computed Parameter: ForIterator_IterationLimit
                                * Referenced by: '<S141>/For Iterator'
                                */
  uint16_T Constant_Value_hg;          /* Computed Parameter: Constant_Value_hg
                                        * Referenced by: '<S143>/Constant'
                                        */
  uint16_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S145>/Constant1'
                                        */
  uint16_T Constant1_Value_j;          /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S138>/Constant1'
                                        */
  uint16_T Constant2_Value_k;          /* Computed Parameter: Constant2_Value_k
                                        * Referenced by: '<S138>/Constant2'
                                        */
  uint16_T Constant_Value_k;           /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S140>/Constant'
                                        */
  uint16_T Constant1_Value_h;          /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S140>/Constant1'
                                        */
  uint16_T uPWM_Mode_Value;            /* Expression: 0x3A16
                                        * Referenced by: '<S6>/6PWM_Mode'
                                        */
  uint16_T ADC_Gain_Setting_Value;     /* Expression: inverter.SPI_Gain_Setting
                                        * Referenced by: '<S6>/ADC_Gain_Setting'
                                        */
  uint16_T DRV830xEnable_Value;       /* Computed Parameter: DRV830xEnable_Value
                                       * Referenced by: '<S139>/DRV830x Enable'
                                       */
  uint16_T RunTimeMeasurement_Value;
                                 /* Computed Parameter: RunTimeMeasurement_Value
                                  * Referenced by: '<S139>/RunTimeMeasurement'
                                  */
  uint16_T RED_LED_Value;              /* Computed Parameter: RED_LED_Value
                                        * Referenced by: '<S7>/RED_LED'
                                        */
  uint16_T DataStoreMemory1_InitialValue;
                            /* Computed Parameter: DataStoreMemory1_InitialValue
                             * Referenced by: '<Root>/Data Store Memory1'
                             */
  uint16_T DataStoreMemory2_InitialValue;
                            /* Computed Parameter: DataStoreMemory2_InitialValue
                             * Referenced by: '<Root>/Data Store Memory2'
                             */
  uint16_T DataStoreMemory7_InitialValue;
                            /* Computed Parameter: DataStoreMemory7_InitialValue
                             * Referenced by: '<Root>/Data Store Memory7'
                             */
  boolean_T Out1_Y0_c;                 /* Computed Parameter: Out1_Y0_c
                                        * Referenced by: '<S106>/Out1'
                                        */
  boolean_T Delay_InitialCondition_h;
                                 /* Computed Parameter: Delay_InitialCondition_h
                                  * Referenced by: '<S102>/Delay'
                                  */
  boolean_T Reset_Value;               /* Computed Parameter: Reset_Value
                                        * Referenced by: '<S105>/Reset'
                                        */
  boolean_T Constant1_Value_i;         /* Computed Parameter: Constant1_Value_i
                                        * Referenced by: '<Root>/Constant1'
                                        */
  boolean_T Reset_Value_j;             /* Computed Parameter: Reset_Value_j
                                        * Referenced by: '<S8>/Reset'
                                        */
  boolean_T Reset_Value_i;             /* Computed Parameter: Reset_Value_i
                                        * Referenced by: '<S9>/Reset'
                                        */
  boolean_T DataStoreMemory29_InitialValue;
                           /* Computed Parameter: DataStoreMemory29_InitialValue
                            * Referenced by: '<Root>/Data Store Memory29'
                            */
  boolean_T DataStoreMemory3_InitialValue;
                            /* Computed Parameter: DataStoreMemory3_InitialValue
                             * Referenced by: '<Root>/Data Store Memory3'
                             */
  uint16_T Constant_Value_as;          /* Computed Parameter: Constant_Value_as
                                        * Referenced by: '<S116>/Constant'
                                        */
  uint16_T Switch_Threshold_h;         /* Computed Parameter: Switch_Threshold_h
                                        * Referenced by: '<S116>/Switch'
                                        */
  uint16_T ManualSwitch_CurrentSetting;
                              /* Computed Parameter: ManualSwitch_CurrentSetting
                               * Referenced by: '<Root>/Manual Switch'
                               */
  P_SpeedControl_testing_T SpeedControl;/* '<Root>/Speed Control' */
  P_TwoinputsCRL_testing_T TwoinputsCRL_p;/* '<S90>/Two inputs CRL' */
  P_TwoinputsCRL_testing_T TwoinputsCRL;/* '<S50>/Two inputs CRL' */
};

/* Real-time Model Data Structure */
struct tag_RTM_testing_T {
  const char_T *errorStatus;
  RTWExtModeInfo *extModeInfo;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    uint32_T clockTick0;
    uint16_T rtmL2HLastBufWr;
    uint32_T rtmL2HDbBufClockTick[2];
    uint16_T clockTick1;
    uint32_T clockTick2;
    uint32_T clockTick3;
    uint16_T rtmDbBufReadBuf3;
    uint16_T rtmDbBufWriteBuf3;
    boolean_T rtmDbBufLastBufWr3;
    uint32_T rtmDbBufClockTick3[2];
    struct {
      uint16_T TID[2];
    } TaskCounters;

    time_T tFinal;
    boolean_T stopRequestedFlag;
  } Timing;
};

/* Block parameters (default storage) */
extern P_testing_T testing_P;

/* Block signals (default storage) */
extern B_testing_T testing_B;

/* Block states (default storage) */
extern DW_testing_T testing_DW;

/* Model entry point functions */
extern void testing_initialize(void);
extern void testing_step(void);
extern void testing_terminate(void);

/* Real-time Model object */
extern RT_MODEL_testing_T *const testing_M;
void InitAdcC (void);
extern uint16_T MW_adcCInitFlag;
void config_ADCC_SOC2 (void);
void InitAdcB (void);
extern uint16_T MW_adcBInitFlag;
void config_ADCB_SOC2 (void);
void config_ADCB_SOC0 (void);
void config_ADCC_SOC0 (void);
extern volatile boolean_T stopRequested;
extern volatile boolean_T runModel;

#ifdef __cpluscplus

extern "C"
{

#endif

  interrupt void ADCB1_INT(void);
  void testing_configure_interrupts (void);
  void testing_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S31>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Duplicate' : Unused code path elimination
 * Block '<S43>/Data Type Propagation' : Unused code path elimination
 * Block '<S44>/Data Type Duplicate' : Unused code path elimination
 * Block '<S46>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S36>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S37>/Sqrt' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate' : Unused code path elimination
 * Block '<S51>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate' : Unused code path elimination
 * Block '<S56>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S58>/Data Type Duplicate' : Unused code path elimination
 * Block '<S58>/Vc' : Unused code path elimination
 * Block '<S68>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Data Type Propagation' : Unused code path elimination
 * Block '<S74>/Data Type Duplicate' : Unused code path elimination
 * Block '<S75>/Data Type Duplicate' : Unused code path elimination
 * Block '<S77>/Data Type Duplicate' : Unused code path elimination
 * Block '<S87>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate' : Unused code path elimination
 * Block '<S91>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S93>/Data Type Duplicate' : Unused code path elimination
 * Block '<S93>/Data Type Propagation' : Unused code path elimination
 * Block '<S98>/Data Type Duplicate' : Unused code path elimination
 * Block '<S99>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/BooleanTypeCast' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S79>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S79>/Data Type Propagation' : Unused code path elimination
 * Block '<S79>/InpGainDatatype' : Unused code path elimination
 * Block '<S79>/OutGainDatatype' : Unused code path elimination
 * Block '<S79>/Reset' : Unused code path elimination
 * Block '<S105>/Data Type Duplicate' : Unused code path elimination
 * Block '<S116>/Data Type Duplicate' : Unused code path elimination
 * Block '<S107>/ReplaceInport_Npp' : Unused code path elimination
 * Block '<S108>/ReplaceInport_CountsPerRev' : Unused code path elimination
 * Block '<S108>/ReplaceInport_OneByCountsPerRev' : Unused code path elimination
 * Block '<S109>/Data Type Duplicate' : Unused code path elimination
 * Block '<S4>/Data Type Duplicate' : Unused code path elimination
 * Block '<S8>/Data Type Duplicate' : Unused code path elimination
 * Block '<S9>/Data Type Duplicate' : Unused code path elimination
 * Block '<Root>/RT3' : Unused code path elimination
 * Block '<Root>/RT4' : Unused code path elimination
 * Block '<S157>/Ki1' : Unused code path elimination
 * Block '<S157>/Kp1' : Unused code path elimination
 * Block '<S160>/Data Type Duplicate' : Unused code path elimination
 * Block '<S69>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S93>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S20>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S105>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S8>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S9>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S160>/Cast To Boolean' : Eliminate redundant data type conversion
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'testing'
 * '<S1>'   : 'testing/Compare To Constant'
 * '<S2>'   : 'testing/Compare To Constant1'
 * '<S3>'   : 'testing/Current Control'
 * '<S4>'   : 'testing/Discrete Derivative'
 * '<S5>'   : 'testing/HWI_ADCB1_INT'
 * '<S6>'   : 'testing/Hardware Init'
 * '<S7>'   : 'testing/Heartbeat LED'
 * '<S8>'   : 'testing/IIR Filter'
 * '<S9>'   : 'testing/IIR Filter1'
 * '<S10>'  : 'testing/Inverter and Motor - Plant Model'
 * '<S11>'  : 'testing/MATLAB Function'
 * '<S12>'  : 'testing/MATLAB Function1'
 * '<S13>'  : 'testing/MATLAB Function2'
 * '<S14>'  : 'testing/Speed Control'
 * '<S15>'  : 'testing/Current Control/Control_System'
 * '<S16>'  : 'testing/Current Control/HW_Inputs'
 * '<S17>'  : 'testing/Current Control/Input Scaling'
 * '<S18>'  : 'testing/Current Control/Inverter'
 * '<S19>'  : 'testing/Current Control/Control_System/Closed Loop Control'
 * '<S20>'  : 'testing/Current Control/Control_System/Open Loop Start-Up'
 * '<S21>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform'
 * '<S22>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers'
 * '<S23>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S24>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform'
 * '<S25>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM'
 * '<S26>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S27>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant'
 * '<S28>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb'
 * '<S29>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S30>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input'
 * '<S31>'  : 'testing/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S32>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S33>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/MATLAB Function'
 * '<S34>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority'
 * '<S35>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S36>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Inport or Dialog Selection'
 * '<S37>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S38>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/Compare To Constant'
 * '<S39>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/Compare To Constant1'
 * '<S40>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/flipInputs'
 * '<S41>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/flipInputs1'
 * '<S42>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter'
 * '<S43>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/limitRef1'
 * '<S44>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/limitRef2'
 * '<S45>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/passThrough'
 * '<S46>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S47>'  : 'testing/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S48>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant'
 * '<S49>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb'
 * '<S50>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform'
 * '<S51>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL'
 * '<S52>'  : 'testing/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S53>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform/Variant'
 * '<S54>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb'
 * '<S55>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform'
 * '<S56>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S57>'  : 'testing/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S58>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator'
 * '<S59>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method'
 * '<S60>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input'
 * '<S61>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method/SVPWM'
 * '<S62>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S63>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S64>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S65>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S66>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S67>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S68>'  : 'testing/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S69>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S70>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S71>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S72>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S73>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S74>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S75>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S76>'  : 'testing/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S77>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S78>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/Convert to Duty Cycles'
 * '<S79>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/Position Generator'
 * '<S80>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/Ramp Generator'
 * '<S81>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S82>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S83>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized'
 * '<S84>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant'
 * '<S85>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb'
 * '<S86>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S87>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S88>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant'
 * '<S89>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb'
 * '<S90>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform'
 * '<S91>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL'
 * '<S92>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S93>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup'
 * '<S94>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/Interpolation'
 * '<S95>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp'
 * '<S96>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/datatype'
 * '<S97>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S98>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S99>'  : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S100>' : 'testing/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S101>' : 'testing/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S102>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed'
 * '<S103>' : 'testing/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S104>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Calculate Position'
 * '<S105>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S106>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder'
 * '<S107>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S108>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S109>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S110>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S111>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S112>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S113>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant'
 * '<S114>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant1'
 * '<S115>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S116>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S117>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S118>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S119>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S120>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S121>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S122>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S123>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S124>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S125>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S126>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S127>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S128>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S129>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S130>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S131>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S132>' : 'testing/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S133>' : 'testing/Current Control/Inverter/Code Generation'
 * '<S134>' : 'testing/HWI_ADCB1_INT/ECSoC'
 * '<S135>' : 'testing/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S136>' : 'testing/Hardware Init/Variant Subsystem'
 * '<S137>' : 'testing/Hardware Init/Variant Subsystem/Code Generation'
 * '<S138>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S139>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S140>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S141>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S142>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S143>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S144>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S145>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S146>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S147>' : 'testing/Hardware Init/Variant Subsystem/Code Generation/DRV Enable/ADC Gain Setting'
 * '<S148>' : 'testing/Heartbeat LED/Heartbeat LED'
 * '<S149>' : 'testing/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S150>' : 'testing/IIR Filter/IIR Filter'
 * '<S151>' : 'testing/IIR Filter/IIR Filter/Low-pass'
 * '<S152>' : 'testing/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S153>' : 'testing/IIR Filter1/IIR Filter'
 * '<S154>' : 'testing/IIR Filter1/IIR Filter/Low-pass'
 * '<S155>' : 'testing/IIR Filter1/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S156>' : 'testing/Inverter and Motor - Plant Model/Codegeneration'
 * '<S157>' : 'testing/Speed Control/PI_Controller_Speed'
 * '<S158>' : 'testing/Speed Control/Subsystem'
 * '<S159>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S160>' : 'testing/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S161>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S162>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S163>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S164>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S165>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S166>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S167>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S168>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S169>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S170>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S171>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S172>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S173>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S174>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S175>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S176>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S177>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S178>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S179>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S180>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S181>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S182>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S183>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S184>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S185>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S186>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S187>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S188>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S189>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S190>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S191>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S192>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S193>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S194>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S195>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S196>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S197>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S198>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S199>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S200>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S201>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S202>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S203>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S204>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S205>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S206>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S207>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S208>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S209>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S210>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S211>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S212>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S213>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S214>' : 'testing/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S215>' : 'testing/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S216>' : 'testing/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S217>' : 'testing/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* testing_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
