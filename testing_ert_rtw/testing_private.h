/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing_private.h
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

#ifndef testing_private_h_
#define testing_private_h_
#include "rtwtypes.h"
#include "multiword_types.h"
#include "testing.h"
#include "testing_types.h"

/* Private macros used by the generated code to access rtModel */
#ifndef rtmSetTFinal
#define rtmSetTFinal(rtm, val)         ((rtm)->Timing.tFinal = (val))
#endif

#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFFFU) ) || ( SCHAR_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFU) ) || ( INT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFUL) ) || ( LONG_MAX != (0x7FFFFFFFL) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */
void config_QEP_eQEP1(uint32_T pcmaximumvalue, uint32_T pcInitialvalue, uint32_T
                      unittimerperiod, uint32_T comparevalue, uint16_T
                      watchdogtimer, uint16_T qdecctl, uint16_T qepctl, uint16_T
                      qposctl, uint16_T qcapctl, uint16_T qeint);
extern void testing_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, real32_T *rty_Alpha, real32_T *rty_Beta,
  P_TwoinputsCRL_testing_T *localP);
extern void testing_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1);
extern void testing_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1);
extern void testing_SPIMasterTransfer_Init(DW_SPIMasterTransfer_testing_T
  *localDW);
extern void testing_SPIMasterTransfer(uint16_T rtu_0,
  B_SPIMasterTransfer_testing_T *localB, DW_SPIMasterTransfer_testing_T *localDW);
extern void testing_SpeedControl_Init(DW_SpeedControl_testing_T *localDW,
  P_SpeedControl_testing_T *localP);
extern void testing_SpeedControl(real32_T rtu_Speed_Ref, real32_T rtu_Speed_Meas,
  real32_T rtu_In1, real32_T rtu_In2, real32_T *rty_IdqRef, real32_T
  *rty_IdqRef_f, const boolean_T *rtd_EnClosedLoop, const boolean_T *rtd_Enable,
  B_SpeedControl_testing_T *localB, DW_SpeedControl_testing_T *localDW,
  P_SpeedControl_testing_T *localP);
extern void testing_CurrentControl_Init(void);
extern void testing_CurrentControl_Reset(void);
extern void testing_CurrentControl_Disable(void);
extern void testing_CurrentControl(void);
extern void testing_SPIMasterTransfer_Term(DW_SPIMasterTransfer_testing_T
  *localDW);

#endif                                 /* testing_private_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
