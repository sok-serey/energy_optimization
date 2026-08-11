/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing_types.h
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

#ifndef testing_types_h_
#define testing_types_h_
#include "rtwtypes.h"
#include "MW_c2000SPI.h"
#ifndef struct_tag_X3nhL3sVVdEpin6phQ7ajF
#define struct_tag_X3nhL3sVVdEpin6phQ7ajF

struct tag_X3nhL3sVVdEpin6phQ7ajF
{
  boolean_T matlabCodegenIsDeleted;
  int32_T isInitialized;
  boolean_T isSetupComplete;
  MW_Handle_Type MW_SPI_HANDLE;
};

#endif                                 /* struct_tag_X3nhL3sVVdEpin6phQ7ajF */

#ifndef typedef_codertarget_tic2000_blocks_SP_T
#define typedef_codertarget_tic2000_blocks_SP_T

typedef struct tag_X3nhL3sVVdEpin6phQ7ajF codertarget_tic2000_blocks_SP_T;

#endif                             /* typedef_codertarget_tic2000_blocks_SP_T */

/* Parameters for system: '<S50>/Two inputs CRL' */
typedef struct P_TwoinputsCRL_testing_T_ P_TwoinputsCRL_testing_T;

/* Parameters for system: '<Root>/Speed Control' */
typedef struct P_SpeedControl_testing_T_ P_SpeedControl_testing_T;

/* Parameters (default storage) */
typedef struct P_testing_T_ P_testing_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_testing_T RT_MODEL_testing_T;

#endif                                 /* testing_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
