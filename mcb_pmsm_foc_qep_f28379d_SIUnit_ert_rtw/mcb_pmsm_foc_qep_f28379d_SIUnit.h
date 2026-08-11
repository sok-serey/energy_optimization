/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_qep_f28379d_SIUnit.h
 *
 * Code generated for Simulink model 'mcb_pmsm_foc_qep_f28379d_SIUnit'.
 *
 * Model version                  : 11.0
 * Simulink Coder version         : 25.2 (R2025b) 28-Jul-2025
 * C/C++ source code generated on : Wed Jul 29 15:11:25 2026
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef mcb_pmsm_foc_qep_f28379d_SIUnit_h_
#define mcb_pmsm_foc_qep_f28379d_SIUnit_h_
#ifndef mcb_pmsm_foc_qep_f28379d_SIUnit_COMMON_INCLUDES_
#define mcb_pmsm_foc_qep_f28379d_SIUnit_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "c2000BoardSupport.h"
#include "MW_f2837xD_includes.h"
#include "DSP28xx_SciUtil.h"
#include "string.h"
#include "IQmathLib.h"
#include "MW_SPI.h"
#endif                    /* mcb_pmsm_foc_qep_f28379d_SIUnit_COMMON_INCLUDES_ */

#include "MW_c2000ISR.h"
#include "mcb_pmsm_foc_qep_f28379d_SIUnit_types.h"
#include <string.h>
#include "rt_nonfinite.h"
#include <stddef.h>
#include "MW_target_hardware_resources.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
#define rtmGetErrorStatus(rtm)         ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
#define rtmSetErrorStatus(rtm, val)    ((rtm)->errorStatus = (val))
#endif

#ifndef rtmStepTask
#define rtmStepTask(rtm, idx)          ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmTaskCounter
#define rtmTaskCounter(rtm, idx)       ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#define mcb_pmsm_foc_qep_f28379d_SIUnit_M (mcb_pmsm_foc_qep_f28379d_SIU_M)

extern void init_SCIFrame(void);

// to prevent re-entrancy in SCI transmit function
extern uint16_T checkSCITransmitInProgressA;
extern uint32_T frameA1Count;
extern uint16_T frameA1Transmitted;
extern void init_SCI(void);
extern void init_SCI_GPIO(void);
extern void config_ePWMSyncSource(void);
extern void config_ePWM_GPIO (void);
extern void config_ePWM_TBSync (void);
extern void config_ePWM_XBAR(void);
extern void initBoardEnd(void);

/* Block states (default storage) for system '<S268>/SPI Master Transfer' */
typedef struct {
  codertarget_tic2000_blocks_SP_T obj; /* '<S268>/SPI Master Transfer' */
  boolean_T objisempty;                /* '<S268>/SPI Master Transfer' */
} DW_SPIMasterTransfer_mcb_pmsm_T;

/* Block states (default storage) for system '<Root>/Speed Control' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S337>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S317>/Integrator' */
  int16_T Integrator_PrevResetState;   /* '<S317>/Integrator' */
  boolean_T icLoad;                    /* '<S337>/Delay' */
} DW_SpeedControl_mcb_pmsm_foc__T;

/* Block signals (default storage) */
typedef struct {
  uint32_T IndexVector;                /* '<S242>/Index Vector' */
  real32_T RT2[2];                     /* '<Root>/RT2' */
  real32_T SCIReceive[2];              /* '<S276>/SCI Receive' */
  real32_T Add1;                       /* '<S217>/Add1' */
  real32_T Eps;                        /* '<S186>/Ramp Generator' */
  real32_T Sum1[3];                    /* '<S184>/Sum1' */
  real32_T Idq_ref[2];                 /* '<S14>/Idq_ref' */
  real32_T Kp1;                        /* '<S29>/Kp1' */
  real32_T Ki1;                        /* '<S28>/Ki1' */
  real32_T Sum[3];                     /* '<S20>/Sum' */
  real32_T algDD_o1;
  real32_T algDD_o2;
  uint16_T ADC_A_IN0;                  /* '<S262>/ADC_A_IN0' */
  uint16_T ADC_B_IN0;                  /* '<S262>/ADC_B_IN0' */
  uint16_T Sum_p;                      /* '<S267>/Sum' */
  uint16_T Sum1_b;                     /* '<S267>/Sum1' */
  uint16_T eQEP_o1;                    /* '<S207>/eQEP' */
  uint16_T eQEP_o2;                    /* '<S207>/eQEP' */
  uint16_T ADC_C_IN2;                  /* '<S207>/ADC_C_IN2' */
  uint16_T ADC_B_IN2;                  /* '<S207>/ADC_B_IN2' */
  uint16_T Switch;                     /* '<S260>/Switch' */
  boolean_T AND;                       /* '<S211>/AND' */
  boolean_T Switch_c;                  /* '<S238>/Switch' */
} B_mcb_pmsm_foc_qep_f28379d_SI_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real32_T Delay_DSTATE;               /* '<S217>/Delay' */
  real32_T RampGenerator_DSTATE;       /* '<S186>/Ramp Generator' */
  real32_T Delay_DSTATE_a;             /* '<S185>/Delay' */
  real32_T Integrator_DSTATE;          /* '<S136>/Integrator' */
  real32_T Integrator_DSTATE_o;        /* '<S81>/Integrator' */
  uint32_T Delay_DSTATE_i[20];         /* '<S214>/Delay' */
  volatile real32_T RT_Buffer[2];      /* '<Root>/RT' */
  volatile real32_T RT1_Buffer[2];     /* '<Root>/RT1' */
  volatile real32_T RT2_Buffer[4];     /* '<Root>/RT2' */
  real32_T Speed_ref;                  /* '<Root>/Data Store Memory4' */
  int32_T DigitalOutput_FRAC_LEN;      /* '<S270>/Digital Output' */
  int32_T DigitalOutput_FRAC_LEN_h;    /* '<S260>/Digital Output' */
  int32_T DigitalOutput1_FRAC_LEN;     /* '<S260>/Digital Output1' */
  int32_T DRV830xEnable_FRAC_LEN;      /* '<S238>/DRV830x Enable' */
  uint16_T Output_DSTATE;              /* '<S244>/Output' */
  uint16_T Delay3_DSTATE;              /* '<S211>/Delay3' */
  volatile int16_T RT_ActiveBufIdx;    /* '<Root>/RT' */
  volatile int16_T RT1_ActiveBufIdx;   /* '<Root>/RT1' */
  volatile int16_T RT1_semaphoreTaken; /* '<Root>/RT1' */
  volatile int16_T RT2_ActiveBufIdx;   /* '<Root>/RT2' */
  uint16_T IaOffset;                   /* '<Root>/Data Store Memory1' */
  uint16_T IbOffset;                   /* '<Root>/Data Store Memory2' */
  uint16_T Debug_signals;              /* '<Root>/Data Store Memory7' */
  uint16_T Memory_PreviousInput;       /* '<S267>/Memory' */
  uint16_T Memory1_PreviousInput;      /* '<S267>/Memory1' */
  uint16_T CircBufIdx;                 /* '<S214>/Delay' */
  int16_T Integrator_PrevResetState;   /* '<S136>/Integrator' */
  int16_T Integrator_PrevResetState_n; /* '<S81>/Integrator' */
  boolean_T Enable;                    /* '<Root>/Data Store Memory29' */
  boolean_T EnClosedLoop;              /* '<Root>/Data Store Memory3' */
  boolean_T icLoad;                    /* '<S217>/Delay' */
  boolean_T icLoad_d;                  /* '<S185>/Delay' */
  boolean_T OpenLoopStartUp_MODE;      /* '<S8>/Open Loop Start-Up' */
  boolean_T ClosedLoopControl_MODE;    /* '<S8>/Closed Loop Control' */
  DW_SpeedControl_mcb_pmsm_foc__T SpeedControl;/* '<Root>/Speed Control' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer1;/* '<S268>/SPI Master Transfer' */
  DW_SPIMasterTransfer_mcb_pmsm_T SPIMasterTransfer;/* '<S268>/SPI Master Transfer' */
} DW_mcb_pmsm_foc_qep_f28379d_S_T;

/* Invariant block signals (default storage) */
typedef struct {
  const uint32_T Width;                /* '<S241>/Width' */
} ConstB_mcb_pmsm_foc_qep_f2837_T;

/* Constant parameters (default storage) */
typedef struct {
  /* Pooled Parameter (Expression: )
   * Referenced by:
   *   '<S175>/sine_table_values'
   *   '<S199>/sine_table_values'
   */
  real32_T pooled6[1002];
} ConstP_mcb_pmsm_foc_qep_f2837_T;

/* Real-time Model Data Structure */
struct tag_RTM_mcb_pmsm_foc_qep_f283_T {
  const char_T * volatile errorStatus;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint16_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals (default storage) */
extern B_mcb_pmsm_foc_qep_f28379d_SI_T mcb_pmsm_foc_qep_f28379d_SIUn_B;

/* Block states (default storage) */
extern DW_mcb_pmsm_foc_qep_f28379d_S_T mcb_pmsm_foc_qep_f28379d_SIU_DW;
extern const ConstB_mcb_pmsm_foc_qep_f2837_T mcb_pmsm_foc_qep_f28379d_ConstB;/* constant block i/o */

/* Constant parameters (default storage) */
extern const ConstP_mcb_pmsm_foc_qep_f2837_T mcb_pmsm_foc_qep_f28379d_ConstP;

/* External function called from main */
extern void mcb_pmsm_foc_qep_f28379d_SIUnit_SetEventsForThisBaseStep(boolean_T
  *eventFlags);

/* Model entry point functions */
extern void mcb_pmsm_foc_qep_f28379d_SIUnit_initialize(void);
extern void mcb_pmsm_foc_qep_f28379d_SIUnit_step0(void);/* Sample time: [0.0005s, 0.0s] */
extern void mcb_pmsm_foc_qep_f28379d_SIUnit_step1(void);/* Sample time: [0.5s, 0.0s] */
extern void mcb_pmsm_foc_qep_f28379d_SIUnit_terminate(void);

/* Real-time Model object */
extern RT_MODEL_mcb_pmsm_foc_qep_f28_T *const mcb_pmsm_foc_qep_f28379d_SIU_M;
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
  interrupt void SCIA_RX_INT(void);
  void mcb_pmsm_foc_qep_f28379d_SIUnit_configure_interrupts (void);
  void mcb_pmsm_foc_qep_f28379d_SIUnit_unconfigure_interrupts (void);

#ifdef __cpluscplus

}

#endif

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S26>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Duplicate' : Unused code path elimination
 * Block '<S39>/Data Type Propagation' : Unused code path elimination
 * Block '<S40>/Data Type Duplicate' : Unused code path elimination
 * Block '<S42>/Data Type Duplicate' : Unused code path elimination
 * Block '<S27>/Data Type Duplicate' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S32>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S33>/Sqrt' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate' : Unused code path elimination
 * Block '<S157>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate' : Unused code path elimination
 * Block '<S162>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S164>/Data Type Duplicate' : Unused code path elimination
 * Block '<S164>/Vc' : Unused code path elimination
 * Block '<S174>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Duplicate' : Unused code path elimination
 * Block '<S175>/Data Type Propagation' : Unused code path elimination
 * Block '<S180>/Data Type Duplicate' : Unused code path elimination
 * Block '<S181>/Data Type Duplicate' : Unused code path elimination
 * Block '<S183>/Data Type Duplicate' : Unused code path elimination
 * Block '<S193>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate' : Unused code path elimination
 * Block '<S197>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S199>/Data Type Duplicate' : Unused code path elimination
 * Block '<S199>/Data Type Propagation' : Unused code path elimination
 * Block '<S204>/Data Type Duplicate' : Unused code path elimination
 * Block '<S205>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/BooleanTypeCast' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate1' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate2' : Unused code path elimination
 * Block '<S185>/Data Type Duplicate3' : Unused code path elimination
 * Block '<S185>/Data Type Propagation' : Unused code path elimination
 * Block '<S185>/InpGainDatatype' : Unused code path elimination
 * Block '<S185>/OutGainDatatype' : Unused code path elimination
 * Block '<S185>/Reset' : Unused code path elimination
 * Block '<S210>/Data Type Duplicate' : Unused code path elimination
 * Block '<S221>/Data Type Duplicate' : Unused code path elimination
 * Block '<S212>/ReplaceInport_Npp' : Unused code path elimination
 * Block '<S213>/ReplaceInport_CountsPerRev' : Unused code path elimination
 * Block '<S213>/ReplaceInport_OneByCountsPerRev' : Unused code path elimination
 * Block '<S214>/Data Type Duplicate' : Unused code path elimination
 * Block '<S244>/Data Type Propagation' : Unused code path elimination
 * Block '<S248>/FixPt Data Type Duplicate' : Unused code path elimination
 * Block '<S249>/FixPt Data Type Duplicate1' : Unused code path elimination
 * Block '<S268>/Display' : Unused code path elimination
 * Block '<S268>/Display1' : Unused code path elimination
 * Block '<Root>/RT3' : Unused code path elimination
 * Block '<Root>/RT4' : Unused code path elimination
 * Block '<S280>/Data Type Duplicate' : Unused code path elimination
 * Block '<S25>/Kalpha' : Eliminated nontunable gain of 1
 * Block '<S25>/Kbeta' : Eliminated nontunable gain of 1
 * Block '<S174>/Ka' : Eliminated nontunable gain of 1
 * Block '<S174>/Kb' : Eliminated nontunable gain of 1
 * Block '<S174>/Kc' : Eliminated nontunable gain of 1
 * Block '<S175>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S193>/Ka' : Eliminated nontunable gain of 1
 * Block '<S193>/Kb' : Eliminated nontunable gain of 1
 * Block '<S193>/Kc' : Eliminated nontunable gain of 1
 * Block '<S199>/Get_FractionVal' : Eliminate redundant data type conversion
 * Block '<S15>/Data Type Conversion2' : Eliminate redundant data type conversion
 * Block '<S210>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S274>/Data Type Conversion4' : Eliminate redundant data type conversion
 * Block '<S280>/Cast To Boolean' : Eliminate redundant data type conversion
 * Block '<S32>/enableInportSatLim' : Unused code path elimination
 * Block '<S32>/enableInportSatMethod' : Unused code path elimination
 * Block '<S27>/ReplaceInport_satLim' : Unused code path elimination
 * Block '<S27>/ReplaceInport_satMethod' : Unused code path elimination
 * Block '<S158>/Offset' : Unused code path elimination
 * Block '<S158>/Unary_Minus' : Unused code path elimination
 * Block '<S163>/Offset' : Unused code path elimination
 * Block '<S163>/Unary_Minus' : Unused code path elimination
 * Block '<S198>/Offset' : Unused code path elimination
 * Block '<S198>/Unary_Minus' : Unused code path elimination
 * Block '<S210>/One' : Unused code path elimination
 * Block '<S210>/Reset' : Unused code path elimination
 * Block '<S210>/Sum' : Unused code path elimination
 * Block '<S210>/UseInputPort' : Unused code path elimination
 * Block '<S210>/a' : Unused code path elimination
 * Block '<S221>/Constant' : Unused code path elimination
 * Block '<S221>/Constant1' : Unused code path elimination
 * Block '<S238>/Constant' : Unused code path elimination
 * Block '<S238>/NOT' : Unused code path elimination
 * Block '<S260>/NOT' : Unused code path elimination
 * Block '<S280>/One' : Unused code path elimination
 * Block '<S280>/Reset' : Unused code path elimination
 * Block '<S280>/Sum' : Unused code path elimination
 * Block '<S280>/UseInputPort' : Unused code path elimination
 * Block '<S280>/a' : Unused code path elimination
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
 * '<Root>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit'
 * '<S1>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control'
 * '<S2>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt'
 * '<S3>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init'
 * '<S4>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Heartbeat LED'
 * '<S5>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Inverter and Motor - Plant Model'
 * '<S6>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive'
 * '<S7>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control'
 * '<S8>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System'
 * '<S9>'   : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Debug_signals'
 * '<S10>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/HW_Inputs'
 * '<S11>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling'
 * '<S12>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Inverter'
 * '<S13>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx'
 * '<S14>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control'
 * '<S15>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up'
 * '<S16>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform'
 * '<S17>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers'
 * '<S18>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform'
 * '<S19>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform'
 * '<S20>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM'
 * '<S21>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup'
 * '<S22>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant'
 * '<S23>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb'
 * '<S24>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform'
 * '<S25>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input'
 * '<S26>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Clarke Transform/Variant/mcb/Clarke Transform/Two phase input/Two phase CRL wrap'
 * '<S27>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter'
 * '<S28>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id'
 * '<S29>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq'
 * '<S30>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority'
 * '<S31>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence'
 * '<S32>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Inport or Dialog Selection'
 * '<S33>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/Magnitude_calc'
 * '<S34>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/Compare To Constant'
 * '<S35>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/Compare To Constant1'
 * '<S36>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/flipInputs'
 * '<S37>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/flipInputs1'
 * '<S38>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter'
 * '<S39>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/limitRef1'
 * '<S40>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/limitRef2'
 * '<S41>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D or Q Axis Priority/limiter/passThrough'
 * '<S42>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Limiter'
 * '<S43>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/DQ Limiter/D-Q Equivalence/Passthrough'
 * '<S44>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset'
 * '<S45>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S46>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S47>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S48>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S49>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S50>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S51>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S52>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S53>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S54>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S55>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S56>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S57>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S58>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S59>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S60>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S61>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S62>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S63>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S64>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S65>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S66>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S67>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S68>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S69>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S70>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S71>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S72>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S73>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S74>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S75>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S76>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S77>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S78>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S79>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S80>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S81>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S82>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S83>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S84>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S85>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S86>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S87>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S88>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S89>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S90>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S91>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S92>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S93>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S94>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S95>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S96>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S97>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S98>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Id/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S99>'  : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset'
 * '<S100>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S101>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S102>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S103>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S104>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S105>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S106>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S107>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S108>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S109>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S110>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S111>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S112>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S113>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S114>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S115>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S116>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S117>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S118>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S119>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S120>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S121>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S122>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S123>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S124>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S125>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S126>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S127>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S128>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S129>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S130>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S131>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S132>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S133>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S134>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S135>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S136>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S137>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S138>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S139>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S140>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S141>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S142>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S143>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S144>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S145>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S146>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S147>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S148>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S149>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S150>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S151>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S152>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S153>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Current_Controllers/PI_Controller_Iq/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S154>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant'
 * '<S155>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb'
 * '<S156>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform'
 * '<S157>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL'
 * '<S158>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S159>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform/Variant'
 * '<S160>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb'
 * '<S161>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform'
 * '<S162>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform/Two inputs CRL'
 * '<S163>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Park Transform/Variant/mcb/Park Transform/Two inputs CRL/Switch_Axis'
 * '<S164>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator'
 * '<S165>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method'
 * '<S166>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input'
 * '<S167>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method/SVPWM'
 * '<S168>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Modulation method/SVPWM/Half(Vmin+Vmax)'
 * '<S169>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta'
 * '<S170>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform'
 * '<S171>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant'
 * '<S172>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb'
 * '<S173>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S174>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/SVPWM/Space Vector Generator/Voltage Input/Valphabeta/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S175>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup'
 * '<S176>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/Interpolation'
 * '<S177>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp'
 * '<S178>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype'
 * '<S179>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S180>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S181>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S182>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Closed Loop Control/Sine-Cosine Lookup/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S183>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator'
 * '<S184>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/Convert to Duty Cycles'
 * '<S185>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/Position Generator'
 * '<S186>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/Ramp Generator'
 * '<S187>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform'
 * '<S188>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform'
 * '<S189>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized'
 * '<S190>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant'
 * '<S191>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb'
 * '<S192>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform'
 * '<S193>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Clarke Transform/Variant/mcb/Inverse Clarke Transform/Two phase input'
 * '<S194>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant'
 * '<S195>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb'
 * '<S196>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform'
 * '<S197>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL'
 * '<S198>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/Inverse Park Transform/Variant/mcb/Inverse Park Transform/Two inputs CRL/Switch_Axis'
 * '<S199>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup'
 * '<S200>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/Interpolation'
 * '<S201>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp'
 * '<S202>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/datatype'
 * '<S203>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/Compare To Zero'
 * '<S204>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/If Action Subsystem'
 * '<S205>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/WrapUp/If Action Subsystem1'
 * '<S206>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Control_System/Open Loop Start-Up/3-Phase Sine Voltage Generator/SinCos Embedded Optimized/Sine-Cosine Lookup/datatype/datatype no change'
 * '<S207>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/HW_Inputs/Sensor Driver Blocks (codegen)'
 * '<S208>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed'
 * '<S209>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/Calculate Phase Currents'
 * '<S210>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter'
 * '<S211>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder'
 * '<S212>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position'
 * '<S213>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder'
 * '<S214>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement'
 * '<S215>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter'
 * '<S216>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass'
 * '<S217>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IIR Filter/IIR Filter/Low-pass/IIR Low Pass Filter'
 * '<S218>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant'
 * '<S219>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/IndexFinder/Compare To Constant1'
 * '<S220>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec'
 * '<S221>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point'
 * '<S222>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset'
 * '<S223>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec'
 * '<S224>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem'
 * '<S225>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Compensate Offset/If Action Subsystem1'
 * '<S226>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem'
 * '<S227>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Mechanical to Electrical Position/MechToElec/floating-point/Mech To Elec/Variant Subsystem/Dialog'
 * '<S228>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle'
 * '<S229>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset'
 * '<S230>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionResetAtIndex'
 * '<S231>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem'
 * '<S232>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/DT_Handle/floating-point'
 * '<S233>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem'
 * '<S234>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/PositionNoReset/Variant Subsystem/Dialog'
 * '<S235>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Quadrature Decoder/Variant Subsystem/Dialog'
 * '<S236>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle'
 * '<S237>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Input Scaling/ Calculate Position and Speed/Speed Measurement/DT_Handle/floating-point'
 * '<S238>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/Inverter/Code Generation'
 * '<S239>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation'
 * '<S240>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx'
 * '<S241>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging'
 * '<S242>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/While Iterator Subsystem'
 * '<S243>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Conditioning_Tx/Data_Type_Float'
 * '<S244>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited'
 * '<S245>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/Data'
 * '<S246>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/End'
 * '<S247>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/Start'
 * '<S248>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Increment Real World'
 * '<S249>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Current Control/SCI_Tx/Code Generation/Data_Logging/Counter Limited/Wrap To Zero'
 * '<S250>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation'
 * '<S251>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_ADCB1_INT'
 * '<S252>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_SCIA_RX_INT'
 * '<S253>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC'
 * '<S254>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_ADCB1_INT/ECSoC/ECSimCodegen'
 * '<S255>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC'
 * '<S256>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/HW Interrupt/Code generation/HWI_SCIA_RX_INT/ECSoC/ECSimCodegen'
 * '<S257>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem'
 * '<S258>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation'
 * '<S259>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset '
 * '<S260>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/DRV Enable'
 * '<S261>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Default ADC Offset'
 * '<S262>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem'
 * '<S263>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem'
 * '<S264>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem1'
 * '<S265>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem2'
 * '<S266>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /If Action Subsystem3'
 * '<S267>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/Calculate ADC Offset /For Iterator Subsystem/If Action Subsystem'
 * '<S268>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Hardware Init/Variant Subsystem/Code Generation/DRV Enable/ADC Gain Setting'
 * '<S269>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Heartbeat LED/Heartbeat LED'
 * '<S270>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Heartbeat LED/Heartbeat LED/Code generation'
 * '<S271>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Inverter and Motor - Plant Model/Codegeneration'
 * '<S272>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive/Data_Conditioning_Rx'
 * '<S273>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive/SCI_Rx'
 * '<S274>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive/unParse'
 * '<S275>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive/Data_Conditioning_Rx/Data_Type_Float'
 * '<S276>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Serial Receive/SCI_Rx/Code Generation'
 * '<S277>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed'
 * '<S278>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/Subsystem'
 * '<S279>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset'
 * '<S280>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Zero_Cancellation'
 * '<S281>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup'
 * '<S282>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain'
 * '<S283>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative'
 * '<S284>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter'
 * '<S285>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs'
 * '<S286>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain'
 * '<S287>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain'
 * '<S288>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk'
 * '<S289>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator'
 * '<S290>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs'
 * '<S291>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy'
 * '<S292>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain'
 * '<S293>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy'
 * '<S294>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain'
 * '<S295>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal'
 * '<S296>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation'
 * '<S297>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk'
 * '<S298>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum'
 * '<S299>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk'
 * '<S300>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode'
 * '<S301>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum'
 * '<S302>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral'
 * '<S303>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain'
 * '<S304>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal'
 * '<S305>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal'
 * '<S306>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal'
 * '<S307>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel'
 * '<S308>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone'
 * '<S309>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Anti-windup/Disc. Clamping Parallel/Dead Zone/Enabled'
 * '<S310>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/D Gain/Disabled'
 * '<S311>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/External Derivative/Disabled'
 * '<S312>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter/Disabled'
 * '<S313>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Filter ICs/Disabled'
 * '<S314>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/I Gain/External Parameters'
 * '<S315>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain/Passthrough'
 * '<S316>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Ideal P Gain Fdbk/Disabled'
 * '<S317>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator/Discrete'
 * '<S318>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Integrator ICs/External IC'
 * '<S319>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Copy/Disabled wSignal Specification'
 * '<S320>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/N Gain/Disabled'
 * '<S321>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/P Copy/Disabled'
 * '<S322>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Parallel P Gain/External Parameters'
 * '<S323>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Reset Signal/External Reset'
 * '<S324>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation/Enabled'
 * '<S325>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Saturation Fdbk/Disabled'
 * '<S326>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum/Sum_PI'
 * '<S327>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Sum Fdbk/Disabled'
 * '<S328>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode/Disabled'
 * '<S329>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tracking Mode Sum/Passthrough'
 * '<S330>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Integral/TsSignalSpecification'
 * '<S331>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/Tsamp - Ngain/Passthrough'
 * '<S332>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/postSat Signal/Forward_Path'
 * '<S333>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preInt Signal/Internal PreInt'
 * '<S334>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Discrete PI Controller  with anti-windup & reset/preSat Signal/Forward_Path'
 * '<S335>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter'
 * '<S336>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass'
 * '<S337>' : 'mcb_pmsm_foc_qep_f28379d_SIUnit/Speed Control/PI_Controller_Speed/Zero_Cancellation/IIR Filter/Low-pass/IIR Low Pass Filter'
 */
#endif                                 /* mcb_pmsm_foc_qep_f28379d_SIUnit_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
