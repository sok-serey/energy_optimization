/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: mcb_pmsm_foc_qep_f28379d_SIUnit.c
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

#include "mcb_pmsm_foc_qep_f28379d_SIUnit.h"
#include "rtwtypes.h"
#include "mcb_pmsm_foc_qep_f28379d_SIUnit_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>

/* Block signals (default storage) */
B_mcb_pmsm_foc_qep_f28379d_SI_T mcb_pmsm_foc_qep_f28379d_SIUn_B;

/* Block states (default storage) */
DW_mcb_pmsm_foc_qep_f28379d_S_T mcb_pmsm_foc_qep_f28379d_SIU_DW;

/* Real-time model */
static RT_MODEL_mcb_pmsm_foc_qep_f28_T mcb_pmsm_foc_qep_f28379d_SIU_M_;
RT_MODEL_mcb_pmsm_foc_qep_f28_T *const mcb_pmsm_foc_qep_f28379d_SIU_M =
  &mcb_pmsm_foc_qep_f28379d_SIU_M_;
static void rate_monotonic_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/*
 * Set which subrates need to run this base step (base rate always runs).
 * This function must be called prior to calling the model step function
 * in order to remember which rates need to run this base step.  The
 * buffering of events allows for overlapping preemption.
 */
void mcb_pmsm_foc_qep_f28379d_SIUnit_SetEventsForThisBaseStep(boolean_T
  *eventFlags)
{
  /* Task runs when its counter is zero, computed via rtmStepTask macro */
  eventFlags[1] = ((boolean_T)rtmStepTask(mcb_pmsm_foc_qep_f28379d_SIU_M, 1));
}

/*
 *         This function updates active task flag for each subrate
 *         and rate transition flags for tasks that exchange data.
 *         The function assumes rate-monotonic multitasking scheduler.
 *         The function must be called at model base rate so that
 *         the generated code self-manages all its subrates and rate
 *         transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (mcb_pmsm_foc_qep_f28379d_SIU_M->Timing.TaskCounters.TID[1])++;
  if ((mcb_pmsm_foc_qep_f28379d_SIU_M->Timing.TaskCounters.TID[1]) > 999) {/* Sample time: [0.5s, 0.0s] */
    mcb_pmsm_foc_qep_f28379d_SIU_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S156>/Two inputs CRL'
 *    '<S196>/Two inputs CRL'
 */
void mcb_pmsm_foc_q_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T
  rtu_sin, real32_T rtu_cos, real32_T *rty_Alpha, real32_T *rty_Beta)
{
  /* AlgorithmDescriptorDelegate generated from: '<S157>/a16' incorporates:
   *  Product: '<S157>/dcos'
   *  Product: '<S157>/dsin'
   *  Product: '<S157>/qcos'
   *  Product: '<S157>/qsin'
   *  Sum: '<S157>/sum_alpha'
   *  Sum: '<S157>/sum_beta'
   */
  *rty_Alpha = rtu_Ds * rtu_cos - rtu_Qs * rtu_sin;
  *rty_Beta = rtu_Qs * rtu_cos + rtu_Ds * rtu_sin;
}

/*
 * Output and update for action system:
 *    '<S177>/If Action Subsystem'
 *    '<S201>/If Action Subsystem'
 */
real32_T mcb_pmsm__IfActionSubsystem(real32_T rtu_In1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S180>/Convert_uint16' */
  tmp = (real32_T)floor(rtu_In1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* Sum: '<S180>/Sum' incorporates:
   *  DataTypeConversion: '<S180>/Convert_back'
   *  DataTypeConversion: '<S180>/Convert_uint16'
   */
  return rtu_In1 - (real32_T)(tmp < 0.0F ? -(int16_T)(uint16_T)-tmp : (int16_T)
    (uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S177>/If Action Subsystem1'
 *    '<S201>/If Action Subsystem1'
 */
real32_T mcb_pmsm_IfActionSubsystem1(real32_T rtu_In1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S181>/Convert_uint16' */
  if (rtu_In1 < 0.0F) {
    tmp = (real32_T)ceil(rtu_In1);
  } else {
    tmp = (real32_T)floor(rtu_In1);
  }

  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* Sum: '<S181>/Sum' incorporates:
   *  DataTypeConversion: '<S181>/Convert_back'
   *  DataTypeConversion: '<S181>/Convert_uint16'
   */
  return rtu_In1 - (real32_T)(tmp < 0.0F ? -(int16_T)(uint16_T)-tmp : (int16_T)
    (uint16_T)tmp);
}

/* System initialize for function-call system: '<Root>/Current Control' */
void mcb_pms_CurrentControl_Init(void)
{
  /* Start for S-Function (c280xqep): '<S207>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c280xgpio_do): '<S238>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM1' */
  real32_T tbprdValue1 = (real32_T)EPwm1Regs.TBPRD;

  /*** Initialize ePWM1 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm1Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm1Regs.TBCTL.bit.SYNCOSEL             = 1U;          -- Sync Output Select

       EPwm1Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm1Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm1Regs.TBCTL.bit.PHSEN                = 0U;          -- Phase Load Enable
       EPwm1Regs.TBCTL.bit.PHSDIR               = 0U;          -- Phase Direction Bit
       EPwm1Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm1Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm1Regs.TBCTL.all = (EPwm1Regs.TBCTL.all & ~0x3FFFU) | 0x12U;
    EPwm1Regs.TBCTL2.all = (EPwm1Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm1Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm1Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm1Regs.TBPHS.all = (EPwm1Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm1Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm1Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm1Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm1Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm1Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm1Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm1Regs.CMPCTL.all = (EPwm1Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm1Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm1Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm1Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm1Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm1Regs.CMPCTL2.all = (EPwm1Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm1Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm1Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm1Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm1Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm1Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm1Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm1Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm1Regs.AQSFRC.all = (EPwm1Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm1Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm1Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm1Regs.AQCSFRC.all = (EPwm1Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm1Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm1Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm1Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm1Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm1Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm1Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm1Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm1Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm1Regs.DBCTL.all = (EPwm1Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm1Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm1Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm1Regs.ETSEL.bit.SOCAEN               = 1U;          -- Start of Conversion A Enable
       EPwm1Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM1SOC Period Select
       EPwm1Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm1Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm1Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM1SOCB Period Select
       EPwm1Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm1Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM1INTn Enable
       EPwm1Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm1Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm1Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM1INTn Period Select
       EPwm1Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm1Regs.ETSEL.all = (EPwm1Regs.ETSEL.all & ~0xFF7FU) | 0x1A01U;
    EPwm1Regs.ETPS.all = (EPwm1Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm1Regs.ETSOCPS.all = (EPwm1Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm1Regs.ETINTPS.all = (EPwm1Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm1Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm1Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm1Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm1Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm1Regs.PCCTL.all = (EPwm1Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm1Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm1Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1A
       EPwm1Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM1B
       EPwm1Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM1A action on DCAEVT1
       EPwm1Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM1A action on DCAEVT2
       EPwm1Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM1B action on DCBEVT1
       EPwm1Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM1B action on DCBEVT2
     */
    EPwm1Regs.TZCTL.all = (EPwm1Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm1Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm1Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm1Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm1Regs.TZEINT.all = (EPwm1Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm1Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm1Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm1Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm1Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm1Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm1Regs.DCACTL.all = (EPwm1Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm1Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm1Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm1Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm1Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm1Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm1Regs.DCBCTL.all = (EPwm1Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm1Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm1Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm1Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm1Regs.DCTRIPSEL.all = (EPwm1Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm1Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm1Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm1Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm1Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm1Regs.TZDCSEL.all = (EPwm1Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm1Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm1Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm1Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm1Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm1Regs.DCFCTL.all = (EPwm1Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm1Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm1Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm1Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm1Regs.DCCAPCTL.all = (EPwm1Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm1Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm1Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm1Regs.HRCNFG.all = (EPwm1Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm1Regs.EPWMXLINK.bit.TBPRDLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPALINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPBLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPCLINK = 0U;
    EPwm1Regs.EPWMXLINK.bit.CMPDLINK = 0U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm1Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm1Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm1Regs.HRPCTL.all = (EPwm1Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM2' */
  real32_T tbprdValue2 = (real32_T)EPwm2Regs.TBPRD;

  /*** Initialize ePWM2 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm2Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm2Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm2Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm2Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm2Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm2Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm2Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm2Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm2Regs.TBCTL.all = (EPwm2Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm2Regs.TBCTL2.all = (EPwm2Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm2Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm2Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm2Regs.TBPHS.all = (EPwm2Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm2Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm2Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm2Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm2Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm2Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm2Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm2Regs.CMPCTL.all = (EPwm2Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm2Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm2Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm2Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm2Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm2Regs.CMPCTL2.all = (EPwm2Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm2Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm2Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm2Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm2Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm2Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm2Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm2Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm2Regs.AQSFRC.all = (EPwm2Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm2Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm2Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm2Regs.AQCSFRC.all = (EPwm2Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm2Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm2Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm2Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm2Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm2Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm2Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm2Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm2Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm2Regs.DBCTL.all = (EPwm2Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm2Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm2Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm2Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm2Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM2SOC Period Select
       EPwm2Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm2Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm2Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM2SOCB Period Select
       EPwm2Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm2Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM2INTn Enable
       EPwm2Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm2Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm2Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM2INTn Period Select
       EPwm2Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm2Regs.ETSEL.all = (EPwm2Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm2Regs.ETPS.all = (EPwm2Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm2Regs.ETSOCPS.all = (EPwm2Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm2Regs.ETINTPS.all = (EPwm2Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm2Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm2Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm2Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm2Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm2Regs.PCCTL.all = (EPwm2Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm2Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm2Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2A
       EPwm2Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM2B
       EPwm2Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM2A action on DCAEVT1
       EPwm2Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM2A action on DCAEVT2
       EPwm2Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM2B action on DCBEVT1
       EPwm2Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM2B action on DCBEVT2
     */
    EPwm2Regs.TZCTL.all = (EPwm2Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm2Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm2Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm2Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm2Regs.TZEINT.all = (EPwm2Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm2Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm2Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm2Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm2Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm2Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm2Regs.DCACTL.all = (EPwm2Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm2Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm2Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm2Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm2Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm2Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm2Regs.DCBCTL.all = (EPwm2Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm2Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm2Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm2Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm2Regs.DCTRIPSEL.all = (EPwm2Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm2Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm2Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm2Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm2Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm2Regs.TZDCSEL.all = (EPwm2Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm2Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm2Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm2Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm2Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm2Regs.DCFCTL.all = (EPwm2Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm2Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm2Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm2Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm2Regs.DCCAPCTL.all = (EPwm2Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm2Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm2Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm2Regs.HRCNFG.all = (EPwm2Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm2Regs.EPWMXLINK.bit.TBPRDLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPALINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPBLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPCLINK = 1U;
    EPwm2Regs.EPWMXLINK.bit.CMPDLINK = 1U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm2Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm2Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm2Regs.HRPCTL.all = (EPwm2Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* Start for S-Function (c2802xpwm): '<S238>/ePWM3' */
  real32_T tbprdValue3 = (real32_T)EPwm3Regs.TBPRD;

  /*** Initialize ePWM3 modules ***/
  {
    /*  -- Time Base Control Register
       EPwm3Regs.TBCTL.bit.CTRMODE              = 2U;          -- Counter Mode
       EPwm3Regs.TBCTL.bit.SYNCOSEL             = 0U;          -- Sync Output Select

       EPwm3Regs.TBCTL.bit.PRDLD                = 0U;          -- Shadow select

       EPwm3Regs.TBCTL2.bit.PRDLDSYNC           = 0U;          -- Shadow select

       EPwm3Regs.TBCTL.bit.PHSEN                = 1U;          -- Phase Load Enable
       EPwm3Regs.TBCTL.bit.PHSDIR               = 1U;          -- Phase Direction Bit
       EPwm3Regs.TBCTL.bit.HSPCLKDIV            = 0U;          -- High Speed TBCLK Pre-scaler
       EPwm3Regs.TBCTL.bit.CLKDIV               = 0U;          -- Time Base Clock Pre-scaler
     */
    EPwm3Regs.TBCTL.all = (EPwm3Regs.TBCTL.all & ~0x3FFFU) | 0x2006U;
    EPwm3Regs.TBCTL2.all = (EPwm3Regs.TBCTL2.all & ~0xC000U) | 0x0U;

    /*-- Setup Time-Base (TB) Submodule --*/
    EPwm3Regs.TBPRD = 5000U;           // Time Base Period Register

    /* -- Time-Base Phase Register
       EPwm3Regs.TBPHS.bit.TBPHS               = 0U;          -- Phase offset register
     */
    EPwm3Regs.TBPHS.all = (EPwm3Regs.TBPHS.all & ~0xFFFF0000U) | 0x0U;

    // Time Base Counter Register
    EPwm3Regs.TBCTR = 0x0000U;         /* Clear counter*/

    /*-- Setup Counter_Compare (CC) Submodule --*/
    /*	-- Counter Compare Control Register

       EPwm3Regs.CMPCTL.bit.LOADASYNC           = 0U;          -- Active Compare A Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADBSYNC           = 0U;          -- Active Compare B Load SYNC Option
       EPwm3Regs.CMPCTL.bit.LOADAMODE           = 0U;          -- Active Compare A Load
       EPwm3Regs.CMPCTL.bit.LOADBMODE           = 0U;          -- Active Compare B Load
       EPwm3Regs.CMPCTL.bit.SHDWAMODE           = 0U;          -- Compare A Register Block Operating Mode
       EPwm3Regs.CMPCTL.bit.SHDWBMODE           = 0U;          -- Compare B Register Block Operating Mode
     */
    EPwm3Regs.CMPCTL.all = (EPwm3Regs.CMPCTL.all & ~0x3C5FU) | 0x0U;

    /* EPwm3Regs.CMPCTL2.bit.SHDWCMODE           = 0U;          -- Compare C Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.SHDWDMODE           = 0U;          -- Compare D Register Block Operating Mode
       EPwm3Regs.CMPCTL2.bit.LOADCSYNC           = 0U;          -- Active Compare C Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADDSYNC           = 0U;          -- Active Compare D Load SYNC Option
       EPwm3Regs.CMPCTL2.bit.LOADCMODE           = 0U;          -- Active Compare C Load
       EPwm3Regs.CMPCTL2.bit.LOADDMODE           = 0U;          -- Active Compare D Load
     */
    EPwm3Regs.CMPCTL2.all = (EPwm3Regs.CMPCTL2.all & ~0x3C5FU) | 0x0U;
    EPwm3Regs.CMPA.bit.CMPA = 2501U;   // Counter Compare A Register
    EPwm3Regs.CMPB.bit.CMPB = 2501U;   // Counter Compare B Register
    EPwm3Regs.CMPC = 32000U;           // Counter Compare C Register
    EPwm3Regs.CMPD = 32000U;           // Counter Compare D Register

    /*-- Setup Action-Qualifier (AQ) Submodule --*/
    EPwm3Regs.AQCTLA.all = 144U;
                               // Action Qualifier Control Register For Output A
    EPwm3Regs.AQCTLB.all = 2310U;
                               // Action Qualifier Control Register For Output B

    /*	-- Action Qualifier Software Force Register
       EPwm3Regs.AQSFRC.bit.RLDCSF              = 0U;          -- Reload from Shadow Options
     */
    EPwm3Regs.AQSFRC.all = (EPwm3Regs.AQSFRC.all & ~0xC0U) | 0x0U;

    /*	-- Action Qualifier Continuous S/W Force Register
       EPwm3Regs.AQCSFRC.bit.CSFA               = 0U;          -- Continuous Software Force on output A
       EPwm3Regs.AQCSFRC.bit.CSFB               = 0U;          -- Continuous Software Force on output B
     */
    EPwm3Regs.AQCSFRC.all = (EPwm3Regs.AQCSFRC.all & ~0xFU) | 0x0U;

    /*-- Setup Dead-Band Generator (DB) Submodule --*/
    /*	-- Dead-Band Generator Control Register
       EPwm3Regs.DBCTL.bit.OUT_MODE             = 3U;          -- Dead Band Output Mode Control
       EPwm3Regs.DBCTL.bit.IN_MODE              = 0U;          -- Dead Band Input Select Mode Control
       EPwm3Regs.DBCTL.bit.POLSEL               = 2U;          -- Polarity Select Control
       EPwm3Regs.DBCTL.bit.HALFCYCLE            = 0U;          -- Half Cycle Clocking Enable
       EPwm3Regs.DBCTL.bit.SHDWDBREDMODE        = 0U;          -- DBRED shadow mode
       EPwm3Regs.DBCTL.bit.SHDWDBFEDMODE        = 0U;          -- DBFED shadow mode
       EPwm3Regs.DBCTL.bit.LOADREDMODE          = 4U;        -- DBRED load
       EPwm3Regs.DBCTL.bit.LOADFEDMODE          = 4U;        -- DBFED load
     */
    EPwm3Regs.DBCTL.all = (EPwm3Regs.DBCTL.all & ~0x8FFFU) | 0xBU;
    EPwm3Regs.DBRED.bit.DBRED = (uint16_T)(15.0);
                         // Dead-Band Generator Rising Edge Delay Count Register
    EPwm3Regs.DBFED.bit.DBFED = (uint16_T)(15.0);
                        // Dead-Band Generator Falling Edge Delay Count Register

    /*-- Setup Event-Trigger (ET) Submodule --*/
    /*	-- Event Trigger Selection and Pre-Scale Register
       EPwm3Regs.ETSEL.bit.SOCAEN               = 0U;          -- Start of Conversion A Enable
       EPwm3Regs.ETSEL.bit.SOCASELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCASEL              = 2U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1U;          -- EPWM3SOC Period Select
       EPwm3Regs.ETSOCPS.bit.SOCAPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.SOCBEN               = 0U;          -- Start of Conversion B Enable
       EPwm3Regs.ETSEL.bit.SOCBSELCMP           = 0U;
       EPwm3Regs.ETSEL.bit.SOCBSEL              = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.SOCPSSEL              = 1;          -- EPWM3SOCB Period Select
       EPwm3Regs.ETSOCPS.bit.SOCBPRD2           = 1U;
       EPwm3Regs.ETSEL.bit.INTEN                = 0U;          -- EPWM3INTn Enable
       EPwm3Regs.ETSEL.bit.INTSELCMP            = 0U;
       EPwm3Regs.ETSEL.bit.INTSEL               = 1U;          -- Start of Conversion A Select
       EPwm3Regs.ETPS.bit.INTPSSEL              = 1U;          // EPWM3INTn Period Select
       EPwm3Regs.ETINTPS.bit.INTPRD2            = 1U;
     */
    EPwm3Regs.ETSEL.all = (EPwm3Regs.ETSEL.all & ~0xFF7FU) | 0x1201U;
    EPwm3Regs.ETPS.all = (EPwm3Regs.ETPS.all & ~0x30U) | 0x30U;
    EPwm3Regs.ETSOCPS.all = (EPwm3Regs.ETSOCPS.all & ~0xF0FU) | 0x101U;
    EPwm3Regs.ETINTPS.all = (EPwm3Regs.ETINTPS.all & ~0xFU) | 0x1U;

    /*-- Setup PWM-Chopper (PC) Submodule --*/
    /*	-- PWM Chopper Control Register
       EPwm3Regs.PCCTL.bit.CHPEN                = 0U;          -- PWM chopping enable
       EPwm3Regs.PCCTL.bit.CHPFREQ              = 0U;          -- Chopping clock frequency
       EPwm3Regs.PCCTL.bit.OSHTWTH              = 0U;          -- One-shot pulse width
       EPwm3Regs.PCCTL.bit.CHPDUTY              = 0U;          -- Chopping clock Duty cycle
     */
    EPwm3Regs.PCCTL.all = (EPwm3Regs.PCCTL.all & ~0x7FFU) | 0x0U;

    /*-- Set up Trip-Zone (TZ) Submodule --*/
    EALLOW;
    EPwm3Regs.TZSEL.all = 0U;          // Trip Zone Select Register

    /*	-- Trip Zone Control Register
       EPwm3Regs.TZCTL.bit.TZA                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3A
       EPwm3Regs.TZCTL.bit.TZB                  = 3U;          -- TZ1 to TZ6 Trip Action On EPWM3B
       EPwm3Regs.TZCTL.bit.DCAEVT1              = 3U;          -- EPWM3A action on DCAEVT1
       EPwm3Regs.TZCTL.bit.DCAEVT2              = 3U;          -- EPWM3A action on DCAEVT2
       EPwm3Regs.TZCTL.bit.DCBEVT1              = 3U;          -- EPWM3B action on DCBEVT1
       EPwm3Regs.TZCTL.bit.DCBEVT2              = 3U;          -- EPWM3B action on DCBEVT2
     */
    EPwm3Regs.TZCTL.all = (EPwm3Regs.TZCTL.all & ~0xFFFU) | 0xFFFU;

    /*	-- Trip Zone Enable Interrupt Register
       EPwm3Regs.TZEINT.bit.OST                 = 0U;          -- Trip Zones One Shot Int Enable
       EPwm3Regs.TZEINT.bit.CBC                 = 0U;          -- Trip Zones Cycle By Cycle Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT1             = 0U;          -- Digital Compare A Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCAEVT2             = 0U;          -- Digital Compare A Event 2 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT1             = 0U;          -- Digital Compare B Event 1 Int Enable
       EPwm3Regs.TZEINT.bit.DCBEVT2             = 0U;          -- Digital Compare B Event 2 Int Enable
     */
    EPwm3Regs.TZEINT.all = (EPwm3Regs.TZEINT.all & ~0x7EU) | 0x0U;

    /*	-- Digital Compare A Control Register
       EPwm3Regs.DCACTL.bit.EVT1SYNCE           = 0U;          -- DCAEVT1 SYNC Enable
       EPwm3Regs.DCACTL.bit.EVT1SOCE            = 1U;          -- DCAEVT1 SOC Enable
       EPwm3Regs.DCACTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCAEVT1 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT1SRCSEL          = 0U;          -- DCAEVT1 Source Signal
       EPwm3Regs.DCACTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCAEVT2 Force Sync Signal
       EPwm3Regs.DCACTL.bit.EVT2SRCSEL          = 0U;          -- DCAEVT2 Source Signal
     */
    EPwm3Regs.DCACTL.all = (EPwm3Regs.DCACTL.all & ~0x30FU) | 0x4U;

    /*	-- Digital Compare B Control Register
       EPwm3Regs.DCBCTL.bit.EVT1SYNCE           = 0U;          -- DCBEVT1 SYNC Enable
       EPwm3Regs.DCBCTL.bit.EVT1SOCE            = 0U;          -- DCBEVT1 SOC Enable
       EPwm3Regs.DCBCTL.bit.EVT1FRCSYNCSEL      = 0U;          -- DCBEVT1 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT1SRCSEL          = 0U;          -- DCBEVT1 Source Signal
       EPwm3Regs.DCBCTL.bit.EVT2FRCSYNCSEL      = 0U;          -- DCBEVT2 Force Sync Signal
       EPwm3Regs.DCBCTL.bit.EVT2SRCSEL          = 0U;          -- DCBEVT2 Source Signal
     */
    EPwm3Regs.DCBCTL.all = (EPwm3Regs.DCBCTL.all & ~0x30FU) | 0x0U;

    /*	-- Digital Compare Trip Select Register
       EPwm3Regs.DCTRIPSEL.bit.DCAHCOMPSEL      = 0U;          -- Digital Compare A High COMP Input Select

       EPwm3Regs.DCTRIPSEL.bit.DCALCOMPSEL      = 1U;          -- Digital Compare A Low COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBHCOMPSEL      = 0U;          -- Digital Compare B High COMP Input Select
       EPwm3Regs.DCTRIPSEL.bit.DCBLCOMPSEL      = 1U;          -- Digital Compare B Low COMP Input Select
     */
    EPwm3Regs.DCTRIPSEL.all = (EPwm3Regs.DCTRIPSEL.all & ~ 0xFFFFU) | 0x1010U;

    /*	-- Trip Zone Digital Comparator Select Register
       EPwm3Regs.TZDCSEL.bit.DCAEVT1            = 0U;          -- Digital Compare Output A Event 1
       EPwm3Regs.TZDCSEL.bit.DCAEVT2            = 0U;          -- Digital Compare Output A Event 2
       EPwm3Regs.TZDCSEL.bit.DCBEVT1            = 0U;          -- Digital Compare Output B Event 1
       EPwm3Regs.TZDCSEL.bit.DCBEVT2            = 0U;          -- Digital Compare Output B Event 2
     */
    EPwm3Regs.TZDCSEL.all = (EPwm3Regs.TZDCSEL.all & ~0xFFFU) | 0x0U;

    /*	-- Digital Compare Filter Control Register
       EPwm3Regs.DCFCTL.bit.BLANKE              = 0U;          -- Blanking Enable/Disable
       EPwm3Regs.DCFCTL.bit.PULSESEL            = 1U;          -- Pulse Select for Blanking & Capture Alignment
       EPwm3Regs.DCFCTL.bit.BLANKINV            = 0U;          -- Blanking Window Inversion
       EPwm3Regs.DCFCTL.bit.SRCSEL              = 0U;          -- Filter Block Signal Source Select
     */
    EPwm3Regs.DCFCTL.all = (EPwm3Regs.DCFCTL.all & ~0x3FU) | 0x10U;
    EPwm3Regs.DCFOFFSET = 0U;          // Digital Compare Filter Offset Register
    EPwm3Regs.DCFWINDOW = 0U;          // Digital Compare Filter Window Register

    /*	-- Digital Compare Capture Control Register
       EPwm3Regs.DCCAPCTL.bit.CAPE              = 0U;          -- Counter Capture Enable
     */
    EPwm3Regs.DCCAPCTL.all = (EPwm3Regs.DCCAPCTL.all & ~0x1U) | 0x0U;

    /*	-- HRPWM Configuration Register
       EPwm3Regs.HRCNFG.bit.SWAPAB              = 0U;          -- Swap EPWMA and EPWMB Outputs Bit
       EPwm3Regs.HRCNFG.bit.SELOUTB             = 0U;          -- EPWMB Output Selection Bit
     */
    EPwm3Regs.HRCNFG.all = (EPwm3Regs.HRCNFG.all & ~0xA0U) | 0x0U;

    /* Update the Link Registers with the link value for all the Compare values and TBPRD */
    /* No error is thrown if the ePWM register exists in the model or not */
    EPwm3Regs.EPWMXLINK.bit.TBPRDLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPALINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPBLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPCLINK = 2U;
    EPwm3Regs.EPWMXLINK.bit.CMPDLINK = 2U;

    /* SYNCPER - Peripheral synchronization output event
       EPwm3Regs.HRPCTL.bit.PWMSYNCSEL            = 0U;          -- EPWMSYNCPER selection
       EPwm3Regs.HRPCTL.bit.PWMSYNCSELX           = 0U;          --  EPWMSYNCPER selection
     */
    EPwm3Regs.HRPCTL.all = (EPwm3Regs.HRPCTL.all & ~0x72U) | 0x0U;
    EDIS;
  }

  /* InitializeConditions for Delay: '<S214>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S217>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad = true;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Control_System' */
  /* SystemInitialize for Enabled SubSystem: '<S8>/Closed Loop Control' */
  /* Start for Constant: '<S29>/Kp1' */
  mcb_pmsm_foc_qep_f28379d_SIUn_B.Kp1 = 0.0F;

  /* Start for Constant: '<S28>/Ki1' */
  mcb_pmsm_foc_qep_f28379d_SIUn_B.Ki1 = 0.0F;

  /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE = 0.0F;
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState = 0;

  /* InitializeConditions for DiscreteIntegrator: '<S81>/Integrator' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE_o = 0.0F;
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState_n = 0;

  /* End of SystemInitialize for SubSystem: '<S8>/Closed Loop Control' */

  /* SystemInitialize for Enabled SubSystem: '<S8>/Open Loop Start-Up' */
  /* InitializeConditions for DiscreteIntegrator: '<S186>/Ramp Generator' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE = 0.0F;

  /* InitializeConditions for Delay: '<S185>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad_d = true;

  /* End of SystemInitialize for SubSystem: '<S8>/Open Loop Start-Up' */
  /* End of SystemInitialize for SubSystem: '<S1>/Control_System' */
}

/* System reset for function-call system: '<Root>/Current Control' */
void mcb_pm_CurrentControl_Reset(void)
{
  /* InitializeConditions for Delay: '<S214>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx = 0U;

  /* InitializeConditions for Delay: '<S217>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad = true;
}

/* Disable for function-call system: '<Root>/Current Control' */
#if (__C29_ARCH == 1)

__attribute__((section(“.TI.ramfunc”), noinline))
#else
#pragma CODE_SECTION (mcb__CurrentControl_Disable, "ramfuncs")
#endif
  void mcb__CurrentControl_Disable(void)
{
  /* Disable for Atomic SubSystem: '<S1>/Control_System' */
  /* Disable for Enabled SubSystem: '<S8>/Closed Loop Control' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.ClosedLoopControl_MODE = false;

  /* End of Disable for SubSystem: '<S8>/Closed Loop Control' */

  /* Disable for Enabled SubSystem: '<S8>/Open Loop Start-Up' */
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S186>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE =
      mcb_pmsm_foc_qep_f28379d_SIUn_B.Eps;
    mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S8>/Open Loop Start-Up' */
  /* End of Disable for SubSystem: '<S1>/Control_System' */
}

/* Output and update for function-call system: '<Root>/Current Control' */
#if (__C29_ARCH == 1)

__attribute__((section(“.TI.ramfunc”), noinline))
#else
#pragma CODE_SECTION (mcb_pmsm_foc_CurrentControl, "ramfuncs")
#endif
  void mcb_pmsm_foc_CurrentControl(void)
{
  /* local block i/o variables */
  uint32_T rtb_BytePack[2];
  real32_T tmp[9];
  real32_T rtb_Switch_oz[2];
  real32_T rtb_Add2;
  real32_T rtb_GetADCVoltage_idx_0;
  real32_T rtb_GetADCVoltage_idx_1;
  real32_T rtb_Product;
  real32_T rtb_Saturation_g;
  real32_T rtb_Sum1_p;
  real32_T rtb_Sum4_l;
  real32_T rtb_Sum6_j;
  real32_T rtb_add_b;
  real32_T rtb_add_c;
  real32_T rtb_algDD_o1;
  real32_T rtb_sqrt3_by_two;
  real32_T tmp_0;
  uint32_T rtb_SCI_Tx_Data[3];
  uint32_T rtb_Add;
  uint32_T rtb_SCI_Tx_Iteration;
  int16_T s242_iter;
  int16_T tmp_1;
  uint16_T rtb_Switch1_lr[3];
  uint16_T rtb_MultiportSwitch_idx_1;
  uint16_T rtb_Sum3_j;
  boolean_T rtb_LogicalOperator;
  boolean_T rtb_LogicalOperator_f;
  boolean_T tmp_2;

  /* S-Function (c280xqep): '<S207>/eQEP' */
  {
    mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o2 = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Outputs for Enabled SubSystem: '<S208>/IndexFinder' incorporates:
   *  EnablePort: '<S211>/Enable'
   */
  /* Logic: '<S208>/NOT' incorporates:
   *  Delay: '<S208>/Delay'
   */
  if (!mcb_pmsm_foc_qep_f28379d_SIUn_B.AND) {
    /* Logic: '<S211>/AND' incorporates:
     *  Constant: '<S218>/Constant'
     *  Constant: '<S219>/Constant'
     *  Delay: '<S211>/Delay3'
     *  RelationalOperator: '<S218>/Compare'
     *  RelationalOperator: '<S219>/Compare'
     */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.AND =
      ((mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay3_DSTATE == 0U) &&
       (mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o2 > 0U));

    /* Update for Delay: '<S211>/Delay3' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay3_DSTATE =
      mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o2;
  }

  /* End of Logic: '<S208>/NOT' */
  /* End of Outputs for SubSystem: '<S208>/IndexFinder' */

  /* DataStoreWrite: '<S208>/Data Store Write' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.EnClosedLoop =
    mcb_pmsm_foc_qep_f28379d_SIUn_B.AND;

  /* Outputs for IfAction SubSystem: '<S213>/PositionNoReset' incorporates:
   *  ActionPort: '<S229>/Action Port'
   */
  /* If: '<S213>/If1' incorporates:
   *  Constant: '<S234>/Constant'
   *  Constant: '<S235>/Constant'
   *  DataTypeConversion: '<S232>/DTC'
   *  MinMax: '<S229>/MinMax'
   *  Product: '<S213>/Product'
   *  Sum: '<S229>/Sum3'
   *  Sum: '<S229>/Sum7'
   */
  rtb_Sum3_j = mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o1 -
    mcb_pmsm_foc_qep_f28379d_SIUn_B.eQEP_o2;
  if (rtb_Sum3_j > rtb_Sum3_j + 4000U) {
    rtb_Sum3_j += 4000U;
  }

  rtb_Product = (real32_T)rtb_Sum3_j * 0.00157079601F;

  /* End of If: '<S213>/If1' */
  /* End of Outputs for SubSystem: '<S213>/PositionNoReset' */

  /* Gain: '<S214>/PositionToCount' */
  tmp_0 = (real32_T)fmod((real32_T)floor(6.83563648E+8F * rtb_Product),
    4.294967296E+9);

  /* Delay: '<S217>/Delay' incorporates:
   *  Constant: '<S210>/IC'
   */
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad) {
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE = 0.0F;
  }

  /* Sum: '<S217>/Add1' incorporates:
   *  DataTypeConversion: '<S237>/DTC'
   *  Delay: '<S214>/Delay'
   *  Delay: '<S217>/Delay'
   *  Gain: '<S214>/PositionToCount'
   *  Gain: '<S214>/SpeedGain'
   *  Product: '<S217>/Product'
   *  Product: '<S217>/Product1'
   *  Sum: '<S214>/SpeedCount'
   */
  mcb_pmsm_foc_qep_f28379d_SIUn_B.Add1 = (real32_T)((int32_T)(uint32_T)tmp_0 -
    (int32_T)
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_i[mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx])
    * 1.46291814E-6F * 0.01F + 0.99F *
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE;

  /* If: '<S222>/If' incorporates:
   *  Constant: '<S11>/IndexOffset'
   *  Constant: '<S224>/Constant'
   *  Gain: '<S227>/Number of pole pairs'
   *  Sum: '<S224>/Add'
   *  Sum: '<S225>/Add'
   *  Switch: '<S221>/Switch'
   */
  if (rtb_Product <= 1.04615033F) {
    /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem' incorporates:
     *  ActionPort: '<S224>/Action Port'
     */
    rtb_add_c = (rtb_Product + 6.28318548F) - 1.04615033F;

    /* End of Outputs for SubSystem: '<S222>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S222>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S225>/Action Port'
     */
    rtb_add_c = rtb_Product - 1.04615033F;

    /* End of Outputs for SubSystem: '<S222>/If Action Subsystem1' */
  }

  rtb_Product = 4.0F * rtb_add_c;

  /* End of If: '<S222>/If' */

  /* Sum: '<S223>/Add' incorporates:
   *  Gain: '<S223>/Multiply'
   *  Gain: '<S223>/Multiply1'
   *  Rounding: '<S223>/Floor'
   */
  rtb_Product -= (real32_T)floor(0.159154937F * rtb_Product) * 6.28318548F;

  /* S-Function (c2802xadc): '<S207>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S207>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* Gain: '<S209>/Get Currents' incorporates:
   *  DataStoreRead: '<S209>/Data Store Read1'
   *  DataStoreRead: '<S209>/Data Store Read2'
   *  DataTypeConversion: '<S209>/Data Type Conversion'
   *  Gain: '<S209>/Get ADC Voltage'
   *  Sum: '<S209>/Add'
   */
  rtb_GetADCVoltage_idx_0 = (real32_T)((int32_T)
    mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_C_IN2 -
    mcb_pmsm_foc_qep_f28379d_SIU_DW.IaOffset) * 0.000732600747F * 14.2857141F;
  rtb_GetADCVoltage_idx_1 = (real32_T)((int32_T)
    mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_B_IN2 -
    mcb_pmsm_foc_qep_f28379d_SIU_DW.IbOffset) * 0.000732600747F * 14.2857141F;

  /* Outputs for Atomic SubSystem: '<S1>/Control_System' */
  /* Outputs for Enabled SubSystem: '<S8>/Open Loop Start-Up' incorporates:
   *  EnablePort: '<S15>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S8>/Closed Loop Control' incorporates:
   *  EnablePort: '<S14>/Enable'
   */
  if (mcb_pmsm_foc_qep_f28379d_SIUn_B.AND) {
    if (!mcb_pmsm_foc_qep_f28379d_SIU_DW.ClosedLoopControl_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S136>/Integrator' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE =
        mcb_pmsm_foc_qep_f28379d_SIUn_B.Kp1;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState = 0;

      /* InitializeConditions for DiscreteIntegrator: '<S81>/Integrator' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE_o =
        mcb_pmsm_foc_qep_f28379d_SIUn_B.Ki1;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState_n = 0;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.ClosedLoopControl_MODE = true;
    }

    /* Outputs for Atomic SubSystem: '<S25>/Two phase CRL wrap' */
    /* Gain: '<S26>/one_by_sqrt3' incorporates:
     *  Sum: '<S26>/a_plus_2b'
     */
    rtb_add_b = ((rtb_GetADCVoltage_idx_0 + rtb_GetADCVoltage_idx_1) +
                 rtb_GetADCVoltage_idx_1) * 0.577350259F;

    /* End of Outputs for SubSystem: '<S25>/Two phase CRL wrap' */

    /* SignalConversion generated from: '<S14>/Idq_ref' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[0] =
      mcb_pmsm_foc_qep_f28379d_SIUn_B.RT2[0];
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[1] =
      mcb_pmsm_foc_qep_f28379d_SIUn_B.RT2[1];

    /* Gain: '<S177>/convert_pu' */
    rtb_sqrt3_by_two = 0.159154937F * rtb_Product;

    /* If: '<S177>/If' incorporates:
     *  Constant: '<S179>/Constant'
     *  RelationalOperator: '<S179>/Compare'
     */
    if (rtb_sqrt3_by_two < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S177>/If Action Subsystem' incorporates:
       *  ActionPort: '<S180>/Action Port'
       */
      rtb_algDD_o1 = mcb_pmsm__IfActionSubsystem(rtb_sqrt3_by_two);

      /* End of Outputs for SubSystem: '<S177>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S177>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S181>/Action Port'
       */
      rtb_algDD_o1 = mcb_pmsm_IfActionSubsystem1(rtb_sqrt3_by_two);

      /* End of Outputs for SubSystem: '<S177>/If Action Subsystem1' */
    }

    /* End of If: '<S177>/If' */

    /* Gain: '<S175>/indexing' */
    rtb_algDD_o1 *= 800.0F;

    /* DataTypeConversion: '<S175>/Get_Integer' */
    if (rtb_algDD_o1 < 0.0F) {
      rtb_add_c = (real32_T)ceil(rtb_algDD_o1);
    } else {
      rtb_add_c = (real32_T)floor(rtb_algDD_o1);
    }

    if (rtIsNaNF(rtb_add_c) || rtIsInfF(rtb_add_c)) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c = (real32_T)fmod(rtb_add_c, 65536.0);
    }

    rtb_Sum3_j = rtb_add_c < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_add_c :
      (uint16_T)rtb_add_c;

    /* End of DataTypeConversion: '<S175>/Get_Integer' */

    /* Sum: '<S175>/Sum2' incorporates:
     *  DataTypeConversion: '<S175>/Data Type Conversion1'
     */
    rtb_sqrt3_by_two = rtb_algDD_o1 - (real32_T)rtb_Sum3_j;

    /* Sum: '<S176>/Sum4' incorporates:
     *  Constant: '<S175>/offset'
     *  Constant: '<S175>/sine_table_values'
     *  Product: '<S176>/Product'
     *  Selector: '<S175>/Lookup'
     *  Sum: '<S175>/Sum'
     *  Sum: '<S176>/Sum3'
     */
    rtb_Sum4_l = (mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)(rtb_Sum3_j +
      1UL)] - mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)rtb_Sum3_j]) *
      rtb_sqrt3_by_two + mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)
      rtb_Sum3_j];

    /* Sum: '<S176>/Sum6' incorporates:
     *  Constant: '<S175>/offset'
     *  Constant: '<S175>/sine_table_values'
     *  Product: '<S176>/Product1'
     *  Selector: '<S175>/Lookup'
     *  Sum: '<S175>/Sum'
     *  Sum: '<S176>/Sum5'
     */
    rtb_Sum6_j = (mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)(rtb_Sum3_j +
      201UL)] - mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)(rtb_Sum3_j +
      200UL)]) * rtb_sqrt3_by_two + mcb_pmsm_foc_qep_f28379d_ConstP.pooled6
      [(int16_T)(rtb_Sum3_j + 200UL)];

    /* Outputs for Atomic SubSystem: '<S161>/Two inputs CRL' */
    /* Outputs for Atomic SubSystem: '<S25>/Two phase CRL wrap' */
    /* Switch: '<S163>/Switch' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S26>/a16'
     *  Product: '<S162>/acos'
     *  Product: '<S162>/asin'
     *  Product: '<S162>/bcos'
     *  Product: '<S162>/bsin'
     *  Sum: '<S162>/sum_Ds'
     *  Sum: '<S162>/sum_Qs'
     */
    rtb_Switch_oz[0] = rtb_GetADCVoltage_idx_0 * rtb_Sum6_j + rtb_add_b *
      rtb_Sum4_l;
    rtb_Switch_oz[1] = rtb_add_b * rtb_Sum6_j - rtb_GetADCVoltage_idx_0 *
      rtb_Sum4_l;

    /* End of Outputs for SubSystem: '<S25>/Two phase CRL wrap' */

    /* AlgorithmDescriptorDelegate generated from: '<S162>/a16' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o1 = rtb_Switch_oz[0];

    /* AlgorithmDescriptorDelegate generated from: '<S162>/a16' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o2 = rtb_Switch_oz[1];

    /* End of Outputs for SubSystem: '<S161>/Two inputs CRL' */

    /* Sum: '<S29>/Sum' */
    rtb_sqrt3_by_two = mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[1] -
      mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o2;

    /* Logic: '<S29>/Logical Operator' incorporates:
     *  DataStoreRead: '<S29>/Data Store Read1'
     */
    rtb_LogicalOperator = !mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable;

    /* Constant: '<S29>/Kp1' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Kp1 = 0.0F;

    /* DiscreteIntegrator: '<S136>/Integrator' */
    if (rtb_LogicalOperator ||
        (mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState != 0)) {
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE = 0.0F;
    }

    /* Sum: '<S145>/Sum' incorporates:
     *  Constant: '<S29>/Kp'
     *  DiscreteIntegrator: '<S136>/Integrator'
     *  Product: '<S141>/PProd Out'
     */
    rtb_algDD_o1 = rtb_sqrt3_by_two * 2.0F +
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE;

    /* Saturate: '<S143>/Saturation' */
    if (rtb_algDD_o1 > 13.8564062F) {
      rtb_add_b = 13.8564062F;
    } else if (rtb_algDD_o1 < -13.8564062F) {
      rtb_add_b = -13.8564062F;
    } else {
      rtb_add_b = rtb_algDD_o1;
    }

    /* End of Saturate: '<S143>/Saturation' */

    /* Sum: '<S28>/Sum' */
    rtb_Add2 = mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[0] -
      mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o1;

    /* Logic: '<S28>/Logical Operator' incorporates:
     *  DataStoreRead: '<S28>/Data Store Read1'
     */
    rtb_LogicalOperator_f = !mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable;

    /* Constant: '<S28>/Ki1' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Ki1 = 0.0F;

    /* DiscreteIntegrator: '<S81>/Integrator' */
    if (rtb_LogicalOperator_f ||
        (mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState_n != 0)) {
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE_o = 0.0F;
    }

    /* Sum: '<S90>/Sum' incorporates:
     *  Constant: '<S28>/Kp'
     *  DiscreteIntegrator: '<S81>/Integrator'
     *  Product: '<S86>/PProd Out'
     */
    rtb_add_c = rtb_Add2 * 2.0F +
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE_o;

    /* Saturate: '<S88>/Saturation' */
    if (rtb_add_c > 13.8564062F) {
      rtb_Saturation_g = 13.8564062F;
    } else if (rtb_add_c < -13.8564062F) {
      rtb_Saturation_g = -13.8564062F;
    } else {
      rtb_Saturation_g = rtb_add_c;
    }

    /* End of Saturate: '<S88>/Saturation' */

    /* Sum: '<S33>/Sum1' incorporates:
     *  Product: '<S33>/Product'
     *  Product: '<S33>/Product1'
     */
    rtb_Sum1_p = rtb_Saturation_g * rtb_Saturation_g + rtb_add_b * rtb_add_b;

    /* Outputs for IfAction SubSystem: '<S27>/D-Q Equivalence' incorporates:
     *  ActionPort: '<S31>/Action Port'
     */
    /* If: '<S31>/If' incorporates:
     *  If: '<S27>/If'
     *  RelationalOperator: '<S31>/Relational Operator'
     */
    if (rtb_Sum1_p > 173.279984F) {
      /* Outputs for IfAction SubSystem: '<S31>/Limiter' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Sqrt: '<S42>/Square Root' */
      rtb_Sum1_p = (real32_T)sqrt(rtb_Sum1_p);

      /* Product: '<S42>/Divide' incorporates:
       *  Constant: '<S32>/Constant3'
       *  Product: '<S42>/Product'
       *  Switch: '<S32>/Switch'
       *  Switch: '<S42>/Switch'
       */
      rtb_Switch_oz[0] = rtb_Saturation_g * 13.1635857F / rtb_Sum1_p;
      rtb_Switch_oz[1] = rtb_add_b * 13.1635857F / rtb_Sum1_p;

      /* End of Outputs for SubSystem: '<S31>/Limiter' */
    } else {
      /* Outputs for IfAction SubSystem: '<S31>/Passthrough' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* SignalConversion generated from: '<S43>/dqRef' */
      rtb_Switch_oz[0] = rtb_Saturation_g;
      rtb_Switch_oz[1] = rtb_add_b;

      /* End of Outputs for SubSystem: '<S31>/Passthrough' */
    }

    /* End of If: '<S31>/If' */
    /* End of Outputs for SubSystem: '<S27>/D-Q Equivalence' */

    /* DeadZone: '<S73>/DeadZone' */
    if (rtb_add_c > 13.8564062F) {
      rtb_add_c -= 13.8564062F;
    } else if (rtb_add_c >= -13.8564062F) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c -= -13.8564062F;
    }

    /* End of DeadZone: '<S73>/DeadZone' */

    /* Product: '<S78>/IProd Out' incorporates:
     *  Constant: '<S28>/Ki'
     */
    rtb_Add2 *= 0.182166666F;

    /* Switch: '<S71>/Switch1' incorporates:
     *  Constant: '<S71>/Clamping_zero'
     *  Constant: '<S71>/Constant'
     *  Constant: '<S71>/Constant2'
     *  RelationalOperator: '<S71>/fix for DT propagation issue'
     */
    if (rtb_add_c > 0.0F) {
      s242_iter = 1;
    } else {
      s242_iter = -1;
    }

    /* Switch: '<S71>/Switch2' incorporates:
     *  Constant: '<S71>/Clamping_zero'
     *  Constant: '<S71>/Constant3'
     *  Constant: '<S71>/Constant4'
     *  RelationalOperator: '<S71>/fix for DT propagation issue1'
     */
    if (rtb_Add2 > 0.0F) {
      tmp_1 = 1;
    } else {
      tmp_1 = -1;
    }

    /* Switch: '<S71>/Switch' incorporates:
     *  Constant: '<S71>/Clamping_zero'
     *  Constant: '<S71>/Constant1'
     *  Logic: '<S71>/AND3'
     *  RelationalOperator: '<S71>/Equal1'
     *  RelationalOperator: '<S71>/Relational Operator'
     *  Switch: '<S71>/Switch1'
     *  Switch: '<S71>/Switch2'
     */
    if ((rtb_add_c != 0.0F) && (s242_iter == tmp_1)) {
      rtb_Saturation_g = 0.0F;
    } else {
      rtb_Saturation_g = rtb_Add2;
    }

    /* End of Switch: '<S71>/Switch' */

    /* DeadZone: '<S128>/DeadZone' */
    if (rtb_algDD_o1 > 13.8564062F) {
      rtb_algDD_o1 -= 13.8564062F;
    } else if (rtb_algDD_o1 >= -13.8564062F) {
      rtb_algDD_o1 = 0.0F;
    } else {
      rtb_algDD_o1 -= -13.8564062F;
    }

    /* End of DeadZone: '<S128>/DeadZone' */

    /* Product: '<S133>/IProd Out' incorporates:
     *  Constant: '<S29>/Ki'
     */
    rtb_sqrt3_by_two *= 0.182166666F;

    /* Switch: '<S126>/Switch1' incorporates:
     *  Constant: '<S126>/Clamping_zero'
     *  Constant: '<S126>/Constant'
     *  Constant: '<S126>/Constant2'
     *  RelationalOperator: '<S126>/fix for DT propagation issue'
     */
    if (rtb_algDD_o1 > 0.0F) {
      s242_iter = 1;
    } else {
      s242_iter = -1;
    }

    /* Switch: '<S126>/Switch2' incorporates:
     *  Constant: '<S126>/Clamping_zero'
     *  Constant: '<S126>/Constant3'
     *  Constant: '<S126>/Constant4'
     *  RelationalOperator: '<S126>/fix for DT propagation issue1'
     */
    if (rtb_sqrt3_by_two > 0.0F) {
      tmp_1 = 1;
    } else {
      tmp_1 = -1;
    }

    /* Switch: '<S126>/Switch' incorporates:
     *  Constant: '<S126>/Clamping_zero'
     *  Constant: '<S126>/Constant1'
     *  Logic: '<S126>/AND3'
     *  RelationalOperator: '<S126>/Equal1'
     *  RelationalOperator: '<S126>/Relational Operator'
     *  Switch: '<S126>/Switch1'
     *  Switch: '<S126>/Switch2'
     */
    if ((rtb_algDD_o1 != 0.0F) && (s242_iter == tmp_1)) {
      rtb_algDD_o1 = 0.0F;
    } else {
      rtb_algDD_o1 = rtb_sqrt3_by_two;
    }

    /* End of Switch: '<S126>/Switch' */

    /* Outputs for Atomic SubSystem: '<S156>/Two inputs CRL' */
    mcb_pmsm_foc_q_TwoinputsCRL(rtb_Switch_oz[0], rtb_Switch_oz[1], rtb_Sum4_l,
      rtb_Sum6_j, &rtb_add_b, &rtb_Add2);

    /* End of Outputs for SubSystem: '<S156>/Two inputs CRL' */

    /* Gain: '<S174>/one_by_two' */
    rtb_add_c = 0.5F * rtb_add_b;

    /* Gain: '<S174>/sqrt3_by_two' */
    rtb_Add2 *= 0.866025388F;

    /* Sum: '<S174>/add_b' */
    rtb_sqrt3_by_two = rtb_Add2 - rtb_add_c;

    /* Sum: '<S174>/add_c' */
    rtb_add_c = (0.0F - rtb_add_c) - rtb_Add2;

    /* MinMax: '<S168>/Max' incorporates:
     *  MinMax: '<S168>/Min'
     */
    tmp_2 = rtIsNaNF(rtb_sqrt3_by_two);
    if ((rtb_add_b >= rtb_sqrt3_by_two) || tmp_2) {
      rtb_Sum4_l = rtb_add_b;
    } else {
      rtb_Sum4_l = rtb_sqrt3_by_two;
    }

    /* MinMax: '<S168>/Min' */
    if ((rtb_add_b <= rtb_sqrt3_by_two) || tmp_2) {
      rtb_Sum6_j = rtb_add_b;
    } else {
      rtb_Sum6_j = rtb_sqrt3_by_two;
    }

    /* MinMax: '<S168>/Max' incorporates:
     *  MinMax: '<S168>/Min'
     */
    tmp_2 = !rtIsNaNF(rtb_add_c);
    if ((!(rtb_Sum4_l >= rtb_add_c)) && tmp_2) {
      rtb_Sum4_l = rtb_add_c;
    }

    /* MinMax: '<S168>/Min' */
    if ((!(rtb_Sum6_j <= rtb_add_c)) && tmp_2) {
      rtb_Sum6_j = rtb_add_c;
    }

    /* Gain: '<S168>/one_by_two' incorporates:
     *  MinMax: '<S168>/Max'
     *  MinMax: '<S168>/Min'
     *  Sum: '<S168>/Add'
     */
    rtb_Add2 = (rtb_Sum4_l + rtb_Sum6_j) * -0.5F;

    /* Sum: '<S20>/Sum' incorporates:
     *  Constant: '<S20>/Constant'
     *  Gain: '<S167>/Gain'
     *  Gain: '<S20>/Normalize [-0.5 to 0.5]'
     *  Sum: '<S167>/Add1'
     *  Sum: '<S167>/Add2'
     *  Sum: '<S167>/Add3'
     */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[0] = (rtb_add_b + rtb_Add2) *
      1.15470052F * 0.0360843912F + 0.5F;
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[1] = (rtb_sqrt3_by_two + rtb_Add2) *
      1.15470052F * 0.0360843912F + 0.5F;
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[2] = (rtb_Add2 + rtb_add_c) *
      1.15470052F * 0.0360843912F + 0.5F;

    /* Update for DiscreteIntegrator: '<S136>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE += rtb_algDD_o1;
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState = (int16_T)
      rtb_LogicalOperator;

    /* Update for DiscreteIntegrator: '<S81>/Integrator' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_DSTATE_o += rtb_Saturation_g;
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Integrator_PrevResetState_n = (int16_T)
      rtb_LogicalOperator_f;
    if (mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE) {
      /* Disable for DiscreteIntegrator: '<S186>/Ramp Generator' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE =
        mcb_pmsm_foc_qep_f28379d_SIUn_B.Eps;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE = false;
    }
  } else {
    mcb_pmsm_foc_qep_f28379d_SIU_DW.ClosedLoopControl_MODE = false;
    if (!mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S186>/Ramp Generator' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE = 0.0F;

      /* InitializeConditions for Delay: '<S185>/Delay' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad_d = true;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.OpenLoopStartUp_MODE = true;
    }

    /* DiscreteIntegrator: '<S186>/Ramp Generator' incorporates:
     *  DataStoreRead: '<S15>/Data Store Read1'
     *  Logic: '<S186>/NOT'
     */
    if (!mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable) {
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* DiscreteIntegrator: '<S186>/Ramp Generator' */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Eps =
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE;

    /* Abs: '<S15>/Abs' incorporates:
     *  Constant: '<S15>/Ramp_Time (sec)1'
     *  Gain: '<S15>/rpm2freq'
     *  Product: '<S15>/Product'
     */
    rtb_add_b = fabsf(54.760006F * mcb_pmsm_foc_qep_f28379d_SIUn_B.Eps);

    /* Product: '<S185>/Product' incorporates:
     *  Constant: '<S185>/InputGain'
     *  Gain: '<S15>/position_increment'
     */
    rtb_sqrt3_by_two = 0.000314159261F * rtb_add_b * 0.159154937F;

    /* Delay: '<S185>/Delay' */
    if (mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad_d) {
      /* Sum: '<S185>/Sum' incorporates:
       *  Constant: '<S185>/InputGain'
       *  Constant: '<S185>/Offset'
       *  Product: '<S185>/Product1'
       *  Sum: '<S185>/Sum1'
       */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a = 0.0F - rtb_sqrt3_by_two;
    }

    /* Sum: '<S185>/Sum' incorporates:
     *  Delay: '<S185>/Delay'
     */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a += rtb_sqrt3_by_two;

    /* Switch: '<S185>/Switch1' */
    if (!(mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a > 0.0F)) {
      /* Sum: '<S185>/Sum' incorporates:
       *  Constant: '<S185>/Bias1'
       *  Sum: '<S185>/Sum2'
       */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a++;
    }

    /* End of Switch: '<S185>/Switch1' */

    /* Switch: '<S185>/Switch2' */
    if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a >= 1.0F) {
      /* Sum: '<S185>/Sum' incorporates:
       *  Sum: '<S185>/Sum3'
       */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a--;
    }

    /* End of Switch: '<S185>/Switch2' */

    /* Switch: '<S15>/Direction' incorporates:
     *  Constant: '<S15>/ '
     *  Constant: '<S185>/OutputGain'
     *  DataStoreRead: '<S15>/Data Store Read'
     *  Product: '<S185>/Product2'
     *  Sum: '<S15>/Sum'
     */
    if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Speed_ref > 0.0F) {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a * 6.28318548F;
    } else {
      rtb_add_c = 6.28318548F - mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_a *
        6.28318548F;
    }

    /* Gain: '<S201>/convert_pu' incorporates:
     *  Switch: '<S15>/Direction'
     */
    rtb_sqrt3_by_two = 0.159154937F * rtb_add_c;

    /* If: '<S201>/If' incorporates:
     *  Constant: '<S203>/Constant'
     *  RelationalOperator: '<S203>/Compare'
     */
    if (rtb_sqrt3_by_two < 0.0F) {
      /* Outputs for IfAction SubSystem: '<S201>/If Action Subsystem' incorporates:
       *  ActionPort: '<S204>/Action Port'
       */
      rtb_sqrt3_by_two = mcb_pmsm__IfActionSubsystem(rtb_sqrt3_by_two);

      /* End of Outputs for SubSystem: '<S201>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S201>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S205>/Action Port'
       */
      rtb_sqrt3_by_two = mcb_pmsm_IfActionSubsystem1(rtb_sqrt3_by_two);

      /* End of Outputs for SubSystem: '<S201>/If Action Subsystem1' */
    }

    /* End of If: '<S201>/If' */

    /* Gain: '<S199>/indexing' */
    rtb_sqrt3_by_two *= 800.0F;

    /* DataTypeConversion: '<S199>/Get_Integer' */
    if (rtb_sqrt3_by_two < 0.0F) {
      rtb_add_c = (real32_T)ceil(rtb_sqrt3_by_two);
    } else {
      rtb_add_c = (real32_T)floor(rtb_sqrt3_by_two);
    }

    if (rtIsNaNF(rtb_add_c) || rtIsInfF(rtb_add_c)) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c = (real32_T)fmod(rtb_add_c, 65536.0);
    }

    rtb_Sum3_j = rtb_add_c < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_add_c :
      (uint16_T)rtb_add_c;

    /* End of DataTypeConversion: '<S199>/Get_Integer' */

    /* Sum: '<S199>/Sum2' incorporates:
     *  DataTypeConversion: '<S199>/Data Type Conversion1'
     */
    rtb_add_c = rtb_sqrt3_by_two - (real32_T)rtb_Sum3_j;

    /* Product: '<S200>/Product1' incorporates:
     *  Constant: '<S199>/offset'
     *  Constant: '<S199>/sine_table_values'
     *  Selector: '<S199>/Lookup'
     *  Sum: '<S199>/Sum'
     *  Sum: '<S200>/Sum5'
     */
    rtb_sqrt3_by_two = (mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)
                        (rtb_Sum3_j + 201UL)] -
                        mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)
                        (rtb_Sum3_j + 200UL)]) * rtb_add_c;

    /* Gain: '<S15>/Correction_Factor_sinePWM' incorporates:
     *  Gain: '<S15>/V-by-f'
     */
    rtb_add_b = 0.00365230092F * rtb_add_b * 1.15470052F;

    /* Saturate: '<S15>/Saturation' */
    if (rtb_add_b > 0.95F) {
      rtb_add_b = 0.95F;
    } else if (rtb_add_b < 0.15F) {
      rtb_add_b = 0.15F;
    }

    /* Outputs for Atomic SubSystem: '<S196>/Two inputs CRL' */
    /* Constant: '<S183>/Constant' incorporates:
     *  Constant: '<S199>/offset'
     *  Constant: '<S199>/sine_table_values'
     *  Product: '<S200>/Product'
     *  Saturate: '<S15>/Saturation'
     *  Selector: '<S199>/Lookup'
     *  Sum: '<S199>/Sum'
     *  Sum: '<S200>/Sum3'
     *  Sum: '<S200>/Sum4'
     *  Sum: '<S200>/Sum5'
     *  Sum: '<S200>/Sum6'
     *  UnaryMinus: '<S183>/Unary Minus'
     */
    mcb_pmsm_foc_q_TwoinputsCRL(0.0F, -rtb_add_b,
      (mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)(rtb_Sum3_j + 1UL)] -
       mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)rtb_Sum3_j]) * rtb_add_c
      + mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)rtb_Sum3_j],
      rtb_sqrt3_by_two + mcb_pmsm_foc_qep_f28379d_ConstP.pooled6[(int16_T)
      (rtb_Sum3_j + 200UL)], &rtb_algDD_o1, &rtb_sqrt3_by_two);

    /* End of Outputs for SubSystem: '<S196>/Two inputs CRL' */

    /* Gain: '<S193>/one_by_two' */
    rtb_add_c = 0.5F * rtb_algDD_o1;

    /* Gain: '<S193>/sqrt3_by_two' */
    rtb_sqrt3_by_two *= 0.866025388F;

    /* Sum: '<S184>/Sum1' incorporates:
     *  Constant: '<S184>/Constant'
     *  Gain: '<S184>/Normalize'
     *  Sum: '<S193>/add_b'
     *  Sum: '<S193>/add_c'
     */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[0] = rtb_add_c + 0.5F;
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[1] = (rtb_sqrt3_by_two - rtb_add_c) *
      0.5F + 0.5F;
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[2] = ((0.0F - rtb_add_c) -
      rtb_sqrt3_by_two) * 0.5F + 0.5F;

    /* Update for DiscreteIntegrator: '<S186>/Ramp Generator' incorporates:
     *  Constant: '<S15>/Ramp_Time (sec)'
     *  Constant: '<S186>/One'
     *  Gain: '<S186>/Sample_Time'
     *  Product: '<S186>/Divide'
     */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE += 1.66666669E-5F;
    if (mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE > 1.0F) {
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE = 1.0F;
    } else if (mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE < 0.0F) {
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RampGenerator_DSTATE = 0.0F;
    }

    /* End of Update for DiscreteIntegrator: '<S186>/Ramp Generator' */

    /* Update for Delay: '<S185>/Delay' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad_d = false;
  }

  /* End of Outputs for SubSystem: '<S8>/Closed Loop Control' */
  /* End of Outputs for SubSystem: '<S8>/Open Loop Start-Up' */
  /* End of Outputs for SubSystem: '<S1>/Control_System' */

  /* MultiPortSwitch: '<S9>/Multiport Switch' incorporates:
   *  Constant: '<S9>/Ia_Pos'
   *  Constant: '<S9>/Iab'
   *  Constant: '<S9>/Id_control'
   *  Constant: '<S9>/Iq_control'
   *  Constant: '<S9>/speed_control'
   *  DataStoreRead: '<S9>/Data Store Read'
   */
  switch (mcb_pmsm_foc_qep_f28379d_SIU_DW.Debug_signals) {
   case 1:
    rtb_Sum3_j = 1U;
    rtb_MultiportSwitch_idx_1 = 2U;
    break;

   case 2:
    rtb_Sum3_j = 5U;
    rtb_MultiportSwitch_idx_1 = 6U;
    break;

   case 3:
    rtb_Sum3_j = 7U;
    rtb_MultiportSwitch_idx_1 = 8U;
    break;

   case 4:
    rtb_Sum3_j = 3U;
    rtb_MultiportSwitch_idx_1 = 4U;
    break;

   default:
    rtb_Sum3_j = 3U;
    rtb_MultiportSwitch_idx_1 = 9U;
    break;
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* SignalConversion generated from: '<S9>/Selector' incorporates:
   *  DataStoreRead: '<S9>/Data Store Read1'
   *  Gain: '<S9>/rad//s to RPM'
   */
  tmp[0] = mcb_pmsm_foc_qep_f28379d_SIU_DW.Speed_ref;
  tmp[1] = 9.54929638F * mcb_pmsm_foc_qep_f28379d_SIUn_B.Add1;
  tmp[2] = rtb_GetADCVoltage_idx_0;
  tmp[3] = rtb_GetADCVoltage_idx_1;
  tmp[4] = mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[0];
  tmp[5] = mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o1;
  tmp[6] = mcb_pmsm_foc_qep_f28379d_SIUn_B.Idq_ref[1];
  tmp[7] = mcb_pmsm_foc_qep_f28379d_SIUn_B.algDD_o2;
  tmp[8] = rtb_Product;

  /* Selector: '<S9>/Selector' */
  rtb_Switch_oz[0] = tmp[(int16_T)rtb_Sum3_j - 1];
  rtb_Switch_oz[1] = tmp[(int16_T)rtb_MultiportSwitch_idx_1 - 1];

  /* S-Function (any2byte_svd): '<S243>/Byte Pack' */

  /* Pack: <S243>/Byte Pack */
  {
    uint32_T MW_outputPortOffset = 0U;
    uint16_T MW_inputPortWidth = 0U;

    /* Packed output data type - uint32_T */
    void* packData = &rtb_BytePack[0];

    /* Packing the values of Input 1 */
    /* Input data type - real32_T, size - 2 */
    {
      MW_inputPortWidth = (uint16_T)2 * sizeof(real32_T);
      memcpy((void *)&(((uint16_T *)packData)[MW_outputPortOffset]), (void*)
             &rtb_Switch_oz[0], MW_inputPortWidth);
    }
  }

  /* If: '<S241>/If' incorporates:
   *  UnitDelay: '<S244>/Output'
   */
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Output_DSTATE == 0U) {
    /* Outputs for IfAction SubSystem: '<S241>/Start' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    /* SignalConversion generated from: '<S247>/Data_out' incorporates:
     *  Constant: '<S247>/Start'
     *  SignalConversion generated from: '<S247>/Data'
     */
    rtb_SCI_Tx_Data[0] = 1397969747UL;
    rtb_SCI_Tx_Data[1] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[2] = rtb_BytePack[1];

    /* Bias: '<S247>/Bias' */
    rtb_SCI_Tx_Iteration = mcb_pmsm_foc_qep_f28379d_ConstB.Width;

    /* End of Outputs for SubSystem: '<S241>/Start' */
  } else if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Output_DSTATE == 599U) {
    /* Outputs for IfAction SubSystem: '<S241>/End' incorporates:
     *  ActionPort: '<S246>/Action Port'
     */
    /* SignalConversion generated from: '<S246>/Data_out' incorporates:
     *  Constant: '<S246>/End'
     *  SignalConversion generated from: '<S246>/Data'
     */
    rtb_SCI_Tx_Data[0] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[1] = rtb_BytePack[1];
    rtb_SCI_Tx_Data[2] = 1162167621UL;

    /* Bias: '<S246>/Bias' */
    rtb_SCI_Tx_Iteration = mcb_pmsm_foc_qep_f28379d_ConstB.Width;

    /* End of Outputs for SubSystem: '<S241>/End' */
  } else {
    /* Outputs for IfAction SubSystem: '<S241>/Data' incorporates:
     *  ActionPort: '<S245>/Action Port'
     */
    /* SignalConversion generated from: '<S245>/Data_out' incorporates:
     *  Constant: '<S245>/Dummy'
     *  SignalConversion generated from: '<S245>/Data'
     */
    rtb_SCI_Tx_Data[0] = rtb_BytePack[0];
    rtb_SCI_Tx_Data[1] = rtb_BytePack[1];
    rtb_SCI_Tx_Data[2] = 0UL;

    /* Outputs for IfAction SubSystem: '<S241>/End' incorporates:
     *  ActionPort: '<S246>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S241>/Start' incorporates:
     *  ActionPort: '<S247>/Action Port'
     */
    /* SignalConversion generated from: '<S245>/Data_width' incorporates:
     *  Bias: '<S246>/Bias'
     *  Bias: '<S247>/Bias'
     */
    rtb_SCI_Tx_Iteration = mcb_pmsm_foc_qep_f28379d_ConstB.Width - 1UL;

    /* End of Outputs for SubSystem: '<S241>/Start' */
    /* End of Outputs for SubSystem: '<S241>/End' */
    /* End of Outputs for SubSystem: '<S241>/Data' */
  }

  /* End of If: '<S241>/If' */

  /* Outputs for Iterator SubSystem: '<S239>/While Iterator Subsystem' incorporates:
   *  WhileIterator: '<S242>/While Iterator'
   */
  /* MultiPortSwitch: '<S242>/Index Vector' */
  s242_iter = 0;
  do {
    mcb_pmsm_foc_qep_f28379d_SIUn_B.IndexVector = rtb_SCI_Tx_Data[s242_iter];

    {
      if (checkSCITransmitInProgressA != 1U) {
        checkSCITransmitInProgressA = 1U;
        int16_T errFlgHeader = NOERROR;
        int16_T errFlgData = NOERROR;
        int16_T errFlgTail = NOERROR;
        errFlgData = scia_xmit((uchar_T*)
          &mcb_pmsm_foc_qep_f28379d_SIUn_B.IndexVector, 4, 4);
        checkSCITransmitInProgressA = 0U;
      }
    }

    rtb_Add = (rtb_SCI_Tx_Iteration - (uint32_T)(s242_iter + 1)) + 1UL;
    s242_iter++;
  } while (rtb_Add != 0UL);

  /* End of Outputs for SubSystem: '<S239>/While Iterator Subsystem' */

  /* Switch: '<S238>/Switch' incorporates:
   *  DataStoreRead: '<S238>/Enable'
   */
  mcb_pmsm_foc_qep_f28379d_SIUn_B.Switch_c =
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable;

  /* S-Function (c280xgpio_do): '<S238>/DRV830x Enable' */
  {
    if (mcb_pmsm_foc_qep_f28379d_SIUn_B.Switch_c) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S238>/Switch1' incorporates:
   *  Constant: '<S238>/stop'
   *  DataStoreRead: '<S238>/Enable'
   *  Gain: '<S238>/Scale_to_PWM_Counter_PRD'
   */
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable) {
    /* Outputs for Atomic SubSystem: '<S1>/Control_System' */
    /* Switch: '<S8>/Switch4' */
    if (mcb_pmsm_foc_qep_f28379d_SIUn_B.AND) {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[0];
    } else {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[0];
    }

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' incorporates:
     *  Switch: '<S8>/Switch4'
     */
    rtb_Product = 5000.0F * rtb_add_c;

    /* End of Outputs for SubSystem: '<S1>/Control_System' */
    if (rtb_Product < 0.0F) {
      rtb_add_c = (real32_T)ceil(rtb_Product);
    } else {
      rtb_add_c = (real32_T)floor(rtb_Product);
    }

    if (rtIsNaNF(rtb_add_c) || rtIsInfF(rtb_add_c)) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c = (real32_T)fmod(rtb_add_c, 65536.0);
    }

    rtb_Switch1_lr[0] = rtb_add_c < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
      -rtb_add_c : (uint16_T)rtb_add_c;

    /* Outputs for Atomic SubSystem: '<S1>/Control_System' */
    /* Switch: '<S8>/Switch4' incorporates:
     *  Gain: '<S238>/Scale_to_PWM_Counter_PRD'
     */
    if (mcb_pmsm_foc_qep_f28379d_SIUn_B.AND) {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[1];
    } else {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[1];
    }

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' incorporates:
     *  Switch: '<S8>/Switch4'
     */
    rtb_Product = 5000.0F * rtb_add_c;

    /* End of Outputs for SubSystem: '<S1>/Control_System' */
    if (rtb_Product < 0.0F) {
      rtb_add_c = (real32_T)ceil(rtb_Product);
    } else {
      rtb_add_c = (real32_T)floor(rtb_Product);
    }

    if (rtIsNaNF(rtb_add_c) || rtIsInfF(rtb_add_c)) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c = (real32_T)fmod(rtb_add_c, 65536.0);
    }

    rtb_Switch1_lr[1] = rtb_add_c < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
      -rtb_add_c : (uint16_T)rtb_add_c;

    /* Outputs for Atomic SubSystem: '<S1>/Control_System' */
    /* Switch: '<S8>/Switch4' incorporates:
     *  Gain: '<S238>/Scale_to_PWM_Counter_PRD'
     */
    if (mcb_pmsm_foc_qep_f28379d_SIUn_B.AND) {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum[2];
    } else {
      rtb_add_c = mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1[2];
    }

    /* Gain: '<S238>/Scale_to_PWM_Counter_PRD' incorporates:
     *  Switch: '<S8>/Switch4'
     */
    rtb_Product = 5000.0F * rtb_add_c;

    /* End of Outputs for SubSystem: '<S1>/Control_System' */
    if (rtb_Product < 0.0F) {
      rtb_add_c = (real32_T)ceil(rtb_Product);
    } else {
      rtb_add_c = (real32_T)floor(rtb_Product);
    }

    if (rtIsNaNF(rtb_add_c) || rtIsInfF(rtb_add_c)) {
      rtb_add_c = 0.0F;
    } else {
      rtb_add_c = (real32_T)fmod(rtb_add_c, 65536.0);
    }

    rtb_Switch1_lr[2] = rtb_add_c < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
      -rtb_add_c : (uint16_T)rtb_add_c;
  } else {
    rtb_Switch1_lr[0] = 0U;
    rtb_Switch1_lr[1] = 0U;
    rtb_Switch1_lr[2] = 0U;
  }

  /* End of Switch: '<S238>/Switch1' */

  /* S-Function (c2802xpwm): '<S238>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_lr[0]);
  }

  /* S-Function (c2802xpwm): '<S238>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_lr[1]);
  }

  /* S-Function (c2802xpwm): '<S238>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_lr[2]);
  }

  /* Update for Delay: '<S214>/Delay' incorporates:
   *  Gain: '<S214>/PositionToCount'
   */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE_i[mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx]
    = (uint32_T)tmp_0;
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx < 19U) {
    mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx++;
  } else {
    mcb_pmsm_foc_qep_f28379d_SIU_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S214>/Delay' */

  /* Update for Delay: '<S217>/Delay' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.icLoad = false;
  mcb_pmsm_foc_qep_f28379d_SIU_DW.Delay_DSTATE =
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Add1;

  /* Switch: '<S249>/FixPt Switch' incorporates:
   *  Constant: '<S248>/FixPt Constant'
   *  Sum: '<S248>/FixPt Sum1'
   *  UnitDelay: '<S244>/Output'
   */
  if (mcb_pmsm_foc_qep_f28379d_SIU_DW.Output_DSTATE + 1U > 599U) {
    /* Update for UnitDelay: '<S244>/Output' incorporates:
     *  Constant: '<S249>/Constant'
     */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Output_DSTATE = 0U;
  } else {
    /* Update for UnitDelay: '<S244>/Output' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Output_DSTATE++;
  }

  /* End of Switch: '<S249>/FixPt Switch' */
}

/* System initialize for atomic system: */
void mcb__SPIMasterTransfer_Init(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S268>/SPI Master Transfer' */
  localDW->obj.matlabCodegenIsDeleted = false;
  localDW->objisempty = true;
  localDW->obj.isInitialized = 1L;
  SPIPinsLoc = MW_UNDEFINED_VALUE;
  localDW->obj.MW_SPI_HANDLE = MW_SPI_Open(0UL, SPIPinsLoc, SPIPinsLoc,
    SPIPinsLoc, MW_UNDEFINED_VALUE, true, 0U);
  MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
                   MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  localDW->obj.isSetupComplete = true;
}

/* Output and update for atomic system: */
void mcb_pmsm__SPIMasterTransfer(uint16_T rtu_0, DW_SPIMasterTransfer_mcb_pmsm_T
  *localDW)
{
  uint16_T rdDataRaw;

  /* MATLABSystem: '<S268>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  rdDataRaw = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (rdDataRaw == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0, &rdDataRaw,
      1UL);
  }

  /* End of MATLABSystem: '<S268>/SPI Master Transfer' */
}

/* Termination for atomic system: */
void mcb__SPIMasterTransfer_Term(DW_SPIMasterTransfer_mcb_pmsm_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S268>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S268>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void mcb_pmsm__SpeedControl_Init(DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  /* InitializeConditions for Delay: '<S337>/Delay' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteIntegrator: '<S317>/Integrator' incorporates:
   *  Constant: '<S277>/Ki2'
   */
  localDW->Integrator_DSTATE = 0.0F;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void mcb_pmsm_foc_q_SpeedControl(real32_T rtu_Speed_Ref, real32_T rtu_Speed_Meas,
  real32_T *rty_IdqRef, real32_T *rty_IdqRef_f, const boolean_T
  *rtd_EnClosedLoop, const boolean_T *rtd_Enable,
  DW_SpeedControl_mcb_pmsm_foc__T *localDW)
{
  real32_T rtb_DeadZone;
  real32_T rtb_IProdOut;
  real32_T rtb_Sum_hn;
  int16_T tmp;
  int16_T tmp_0;
  boolean_T rtb_LogicalOperator_m;

  /* Constant: '<S7>/Id_ref' */
  *rty_IdqRef = 0.0F;

  /* Delay: '<S337>/Delay' */
  if (localDW->icLoad) {
    /* Sum: '<S337>/Add1' incorporates:
     *  Constant: '<S280>/IC'
     */
    localDW->Delay_DSTATE = 0.0F;
  }

  /* Switch: '<S278>/Switch' incorporates:
   *  DataStoreRead: '<S278>/Data Store Read'
   *  DataStoreRead: '<S278>/Data Store Read1'
   *  Gain: '<S278>/RPM to rad//s'
   *  Logic: '<S278>/AND'
   */
  if ((*rtd_EnClosedLoop) && (*rtd_Enable)) {
    rtb_IProdOut = 0.104719758F * rtu_Speed_Ref;
  } else {
    rtb_IProdOut = rtu_Speed_Meas;
  }

  /* Sum: '<S337>/Add1' incorporates:
   *  Delay: '<S337>/Delay'
   *  Product: '<S337>/Product'
   *  Product: '<S337>/Product1'
   *  Switch: '<S278>/Switch'
   */
  localDW->Delay_DSTATE = rtb_IProdOut * 0.1F + 0.9F * localDW->Delay_DSTATE;

  /* Sum: '<S277>/Sum' */
  rtb_IProdOut = localDW->Delay_DSTATE - rtu_Speed_Meas;

  /* Logic: '<S277>/Logical Operator' incorporates:
   *  DataStoreRead: '<S277>/Data Store Read1'
   */
  rtb_LogicalOperator_m = !*rtd_Enable;

  /* DiscreteIntegrator: '<S317>/Integrator' incorporates:
   *  Constant: '<S277>/Ki2'
   */
  if (rtb_LogicalOperator_m || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = 0.0F;
  }

  /* Sum: '<S326>/Sum' incorporates:
   *  Constant: '<S277>/Kp1'
   *  DiscreteIntegrator: '<S317>/Integrator'
   *  Product: '<S322>/PProd Out'
   */
  rtb_Sum_hn = rtb_IProdOut * 0.0166539736F + localDW->Integrator_DSTATE;

  /* DeadZone: '<S309>/DeadZone' incorporates:
   *  Saturate: '<S324>/Saturation'
   */
  if (rtb_Sum_hn > 21.4285717F) {
    rtb_DeadZone = rtb_Sum_hn - 21.4285717F;
    *rty_IdqRef_f = 21.4285717F;
  } else {
    if (rtb_Sum_hn >= -21.4285717F) {
      rtb_DeadZone = 0.0F;
    } else {
      rtb_DeadZone = rtb_Sum_hn - -21.4285717F;
    }

    if (rtb_Sum_hn < -21.4285717F) {
      *rty_IdqRef_f = -21.4285717F;
    } else {
      *rty_IdqRef_f = rtb_Sum_hn;
    }
  }

  /* End of DeadZone: '<S309>/DeadZone' */

  /* Product: '<S314>/IProd Out' incorporates:
   *  Constant: '<S277>/Ki1'
   */
  rtb_IProdOut *= 0.000376786746F;

  /* Update for Delay: '<S337>/Delay' */
  localDW->icLoad = false;

  /* Switch: '<S307>/Switch1' incorporates:
   *  Constant: '<S307>/Clamping_zero'
   *  Constant: '<S307>/Constant'
   *  Constant: '<S307>/Constant2'
   *  RelationalOperator: '<S307>/fix for DT propagation issue'
   */
  if (rtb_DeadZone > 0.0F) {
    tmp = 1;
  } else {
    tmp = -1;
  }

  /* Switch: '<S307>/Switch2' incorporates:
   *  Constant: '<S307>/Clamping_zero'
   *  Constant: '<S307>/Constant3'
   *  Constant: '<S307>/Constant4'
   *  RelationalOperator: '<S307>/fix for DT propagation issue1'
   */
  if (rtb_IProdOut > 0.0F) {
    tmp_0 = 1;
  } else {
    tmp_0 = -1;
  }

  /* Switch: '<S307>/Switch' incorporates:
   *  Constant: '<S307>/Clamping_zero'
   *  Constant: '<S307>/Constant1'
   *  Logic: '<S307>/AND3'
   *  RelationalOperator: '<S307>/Equal1'
   *  RelationalOperator: '<S307>/Relational Operator'
   *  Switch: '<S307>/Switch1'
   *  Switch: '<S307>/Switch2'
   */
  if ((rtb_DeadZone != 0.0F) && (tmp == tmp_0)) {
    rtb_IProdOut = 0.0F;
  }

  /* Update for DiscreteIntegrator: '<S317>/Integrator' incorporates:
   *  Switch: '<S307>/Switch'
   */
  localDW->Integrator_DSTATE += rtb_IProdOut;
  localDW->Integrator_PrevResetState = (int16_T)rtb_LogicalOperator_m;
}

/* Model step function for TID0 */
void mcb_pmsm_foc_qep_f28379d_SIUnit_step0(void) /* Sample time: [0.0005s, 0.0s] */
{
  real32_T rtb_Id_ref;
  real32_T rtb_RT;
  real32_T rtb_RT1;
  real32_T rtb_Saturation_f;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* RateTransition: '<Root>/RT' */
  rtb_RT =
    mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_Buffer[mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_ActiveBufIdx];

  /* RateTransition: '<Root>/RT1' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_semaphoreTaken =
    mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_ActiveBufIdx;
  rtb_RT1 =
    mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_Buffer[mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_semaphoreTaken];

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  mcb_pmsm_foc_q_SpeedControl(rtb_RT, rtb_RT1, &rtb_Id_ref, &rtb_Saturation_f,
    &mcb_pmsm_foc_qep_f28379d_SIU_DW.EnClosedLoop,
    &mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable,
    &mcb_pmsm_foc_qep_f28379d_SIU_DW.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */

  /* RateTransition: '<Root>/RT2' */
  mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_Buffer
    [(mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_ActiveBufIdx == 0) << 1U] = rtb_Id_ref;
  mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_Buffer[1 +
    ((mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_ActiveBufIdx == 0) << 1U)] =
    rtb_Saturation_f;
  mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_ActiveBufIdx =
    (mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_ActiveBufIdx == 0);
}

/* Model step function for TID1 */
void mcb_pmsm_foc_qep_f28379d_SIUnit_step1(void) /* Sample time: [0.5s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
  /* S-Function (c280xgpio_do): '<S270>/Digital Output' incorporates:
   *  Constant: '<S4>/RED_LED'
   */
  {
    GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)((1U) != 0);
  }

  /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
}

/* Model initialize function */
void mcb_pmsm_foc_qep_f28379d_SIUnit_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)mcb_pmsm_foc_qep_f28379d_SIU_M, 0,
                sizeof(RT_MODEL_mcb_pmsm_foc_qep_f28_T));

  /* block I/O */
  (void) memset(((void *) &mcb_pmsm_foc_qep_f28379d_SIUn_B), 0,
                sizeof(B_mcb_pmsm_foc_qep_f28379d_SI_T));

  /* states (dwork) */
  (void) memset((void *)&mcb_pmsm_foc_qep_f28379d_SIU_DW, 0,
                sizeof(DW_mcb_pmsm_foc_qep_f28379d_S_T));

  {
    int16_T tmp;
    uint16_T s262_iter;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory1' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.IaOffset = 2309U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory2' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.IbOffset = 2304U;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory7' */
    mcb_pmsm_foc_qep_f28379d_SIU_DW.Debug_signals = 5U;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S254>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    mcb_pms_CurrentControl_Init();

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S256>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Serial Receive'
     */
    /* System initialize for function-call system: '<Root>/Serial Receive' */

    /* Start for S-Function (c28xsci_rx): '<S276>/SCI Receive' */

    /* Initialize out port */
    {
      mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[0] = (real32_T)0.0;
      mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[1] = (real32_T)0.0;
    }

    /*Configure Timer2 when blocking mode is enabled and Timeout is not inf*/
    {
      /* InitCpuTimers() - CPU Timers are also initialized in
       * MW_c28xx_board.c in the generated code.
       */
      CpuTimer2Regs.PRD.all = 0xFFFFFFFFU;/* max Period*/
      CpuTimer2Regs.TIM.all = 0xFFFFFFFFU;/* set Ctr*/
      CpuTimer2Regs.TPR.all = 0x00U;   /* no prescaler    */
      StartCpuTimer2();
    }

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    mcb_pmsm__SpeedControl_Init(&mcb_pmsm_foc_qep_f28379d_SIU_DW.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S270>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S260>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S260>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x400000U;
    EDIS;

    /* SystemInitialize for Enabled SubSystem: '<S260>/ADC Gain Setting' */
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer);
    mcb__SPIMasterTransfer_Init
      (&mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<S260>/ADC Gain Setting' */

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Enabled SubSystem: '<S260>/ADC Gain Setting' incorporates:
     *  EnablePort: '<S268>/Enable'
     */
    /* Constant: '<S3>/6PWM_Mode' */
    mcb_pmsm__SPIMasterTransfer(14870U,
      &mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer);

    /* Constant: '<S3>/ADC_Gain_Setting' */
    mcb_pmsm__SPIMasterTransfer(20480U,
      &mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer1);

    /* End of Outputs for SubSystem: '<S260>/ADC Gain Setting' */

    /* Switch: '<S260>/Switch' incorporates:
     *  Constant: '<S260>/DRV830x Enable'
     */
    mcb_pmsm_foc_qep_f28379d_SIUn_B.Switch = 1U;

    /* S-Function (c280xgpio_do): '<S260>/Digital Output' */
    {
      if (mcb_pmsm_foc_qep_f28379d_SIUn_B.Switch) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* S-Function (c280xgpio_do): '<S260>/Digital Output1' incorporates:
     *  Constant: '<S260>/RunTimeMeasurement'
     */
    {
      if ((1U)) {
        GpioDataRegs.GPASET.bit.GPIO22 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S258>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S259>/Enable'
     */
    /* Outputs for Iterator SubSystem: '<S259>/For Iterator Subsystem' incorporates:
     *  ForIterator: '<S262>/For Iterator'
     */
    for (s262_iter = 1U; s262_iter < 17U; s262_iter++) {
      /* S-Function (c2802xadc): '<S262>/ADC_A_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdccRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
      }

      /* S-Function (c2802xadc): '<S262>/ADC_B_IN0' */
      {
        /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
        /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
        AdcbRegs.ADCSOCFRC1.bit.SOC2 = 1U;

        /* Wait for the period of Sampling window and EOC result to be latched after trigger */
#ifndef __TMS320C28XX_CLA__

        asm(" RPT #75|| NOP");

#endif

#ifdef __TMS320C28XX_CLA__

        real32_T wait_index;
        for (wait_index= 12; wait_index > 0; wait_index--)
          __mnop();

#endif

        mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
      }

      /* If: '<S262>/If' */
      if (s262_iter > 8U) {
        /* Outputs for IfAction SubSystem: '<S262>/If Action Subsystem' incorporates:
         *  ActionPort: '<S267>/Action Port'
         */
        /* Sum: '<S267>/Sum' incorporates:
         *  Memory: '<S267>/Memory'
         */
        mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum_p =
          mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_A_IN0 +
          mcb_pmsm_foc_qep_f28379d_SIU_DW.Memory_PreviousInput;

        /* Sum: '<S267>/Sum1' incorporates:
         *  Memory: '<S267>/Memory1'
         */
        mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1_b =
          mcb_pmsm_foc_qep_f28379d_SIUn_B.ADC_B_IN0 +
          mcb_pmsm_foc_qep_f28379d_SIU_DW.Memory1_PreviousInput;

        /* Update for Memory: '<S267>/Memory' */
        mcb_pmsm_foc_qep_f28379d_SIU_DW.Memory_PreviousInput =
          mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum_p;

        /* Update for Memory: '<S267>/Memory1' */
        mcb_pmsm_foc_qep_f28379d_SIU_DW.Memory1_PreviousInput =
          mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1_b;

        /* End of Outputs for SubSystem: '<S262>/If Action Subsystem' */
      }

      /* End of If: '<S262>/If' */
    }

    /* End of Outputs for SubSystem: '<S259>/For Iterator Subsystem' */

    /* Product: '<S259>/Divide' incorporates:
     *  Constant: '<S259>/Constant'
     */
    tmp = (int16_T)floor((real_T)mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum_p / 8.0);

    /* If: '<S259>/If' incorporates:
     *  Constant: '<S259>/Constant1'
     *  Constant: '<S259>/Constant2'
     *  Product: '<S259>/Divide'
     */
    if ((tmp > 1500) && (tmp < 2500)) {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem' incorporates:
       *  ActionPort: '<S263>/Action Port'
       */
      /* DataStoreWrite: '<S263>/Data Store Write1' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.IaOffset = (uint16_T)tmp;

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S264>/Action Port'
       */
      /* DataStoreWrite: '<S264>/Data Store Write1' incorporates:
       *  Constant: '<S264>/Constant'
       */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.IaOffset = 2309U;

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem1' */
    }

    /* End of If: '<S259>/If' */

    /* Product: '<S259>/Divide1' incorporates:
     *  Constant: '<S259>/Constant'
     */
    tmp = (int16_T)floor((real_T)mcb_pmsm_foc_qep_f28379d_SIUn_B.Sum1_b / 8.0);

    /* If: '<S259>/If1' incorporates:
     *  Constant: '<S259>/Constant1'
     *  Constant: '<S259>/Constant2'
     *  Product: '<S259>/Divide1'
     */
    if ((tmp > 1500) && (tmp < 2500)) {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem2' incorporates:
       *  ActionPort: '<S265>/Action Port'
       */
      /* DataStoreWrite: '<S265>/Data Store Write2' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.IbOffset = (uint16_T)tmp;

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem2' */
    } else {
      /* Outputs for IfAction SubSystem: '<S259>/If Action Subsystem3' incorporates:
       *  ActionPort: '<S266>/Action Port'
       */
      /* DataStoreWrite: '<S266>/Data Store Write2' incorporates:
       *  Constant: '<S266>/Constant1'
       */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.IbOffset = 2304U;

      /* End of Outputs for SubSystem: '<S259>/If Action Subsystem3' */
    }

    /* End of If: '<S259>/If1' */
    /* End of Outputs for SubSystem: '<S258>/Calculate ADC Offset ' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
  }
}

/* Model terminate function */
void mcb_pmsm_foc_qep_f28379d_SIUnit_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Enabled SubSystem: '<S260>/ADC Gain Setting' */
  mcb__SPIMasterTransfer_Term(&mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer);
  mcb__SPIMasterTransfer_Term
    (&mcb_pmsm_foc_qep_f28379d_SIU_DW.SPIMasterTransfer1);

  /* End of Terminate for SubSystem: '<S260>/ADC Gain Setting' */
  /* End of Terminate for SubSystem: '<Root>/Hardware Init' */
}

void mcb_pmsm_foc_qep_f28379d_SIUnit_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,0);
  HWI_TIC28x_EnableIRQ(33);

  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(96,&SCIA_RX_INT,2);
  HWI_TIC28x_EnableIRQ(96);
}

/* Hardware Interrupt Block: '<S254>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  volatile unsigned int PIEIER9_stack_save = PieCtrlRegs.PIEIER9.all;
  PieCtrlRegs.PIEIER1.all &= ~66;
                              /*disable group1 lower/equal priority interrupts*/
  PieCtrlRegs.PIEIER9.all &= ~1;
                              /*disable group9 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~257;    /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 257;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T tmp;

      /* RateTransition: '<Root>/RT2' */
      tmp = mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_ActiveBufIdx << 1U;
      mcb_pmsm_foc_qep_f28379d_SIUn_B.RT2[0] =
        mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_Buffer[tmp];
      mcb_pmsm_foc_qep_f28379d_SIUn_B.RT2[1] =
        mcb_pmsm_foc_qep_f28379d_SIU_DW.RT2_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S254>/Hardware Interrupt' */
      mcb_pmsm_foc_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S254>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT1' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_Buffer[mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_semaphoreTaken
        == 0] = mcb_pmsm_foc_qep_f28379d_SIUn_B.Add1;
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_ActiveBufIdx =
        (mcb_pmsm_foc_qep_f28379d_SIU_DW.RT1_semaphoreTaken == 0);
    }
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  PieCtrlRegs.PIEIER9.all = PIEIER9_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

/* Hardware Interrupt Block: '<S256>/Hardware Interrupt' */
interrupt void SCIA_RX_INT(void)
{
  /* Event: Default Event */
  if (1 == runModel) {
    {
      /* S-Function (HardwareInterrupt_sfun): '<S256>/Hardware Interrupt' */

      /* Output and update for function-call system: '<Root>/Serial Receive' */
      {
        real32_T tmp;
        uint16_T rtb_DataTypeConversion2;

        /* S-Function (c28xsci_rx): '<S276>/SCI Receive' */
        {
          int16_T i;
          int16_T errFlg = NOERROR;
          uint16_T isHeadReceived = 1U;

          //get data as uint16 in recBuff
          uint16_T recbuff[4];
          for (i = 0; i < 4; i++) {
            recbuff[i] = 0U;
          }

          errFlg = NOERROR;

          /* Receiving data: For uint32 and uint16, rcvBuff will contain uint16 data */
          if (isHeadReceived) {
            errFlg = scia_rcv(recbuff, 8, 4);
            asm(" NOP");
            if ((errFlg == NOERROR) || (errFlg == PARTIALDATA)) {
              memcpy( &mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[0], recbuff,4);
            }
          }
        }

        /* DataTypeConversion: '<S275>/Data Type Conversion2' */
        if (mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[1] < 0.0F) {
          tmp = (real32_T)ceil(mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[1]);
        } else {
          tmp = (real32_T)floor(mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[1]);
        }

        if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
          tmp = 0.0F;
        } else {
          tmp = (real32_T)fmod(tmp, 65536.0);
        }

        rtb_DataTypeConversion2 = tmp < 0.0F ? (uint16_T)-(int16_T)(uint16_T)
          -tmp : (uint16_T)tmp;

        /* End of DataTypeConversion: '<S275>/Data Type Conversion2' */

        /* DataTypeConversion: '<S274>/Data Type Conversion3' incorporates:
         *  DataStoreWrite: '<S6>/Data Store Write'
         *  S-Function (sfix_bitop): '<S274>/Bitwise Operator'
         */
        mcb_pmsm_foc_qep_f28379d_SIU_DW.Enable = ((rtb_DataTypeConversion2 & 1U)
          != 0U);

        /* DataStoreWrite: '<S6>/Data Store Write1' */
        mcb_pmsm_foc_qep_f28379d_SIU_DW.Speed_ref =
          mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[0];

        /* ArithShift: '<S274>/Shift Arithmetic1' incorporates:
         *  DataStoreWrite: '<S6>/Data Store Write2'
         *  S-Function (sfix_bitop): '<S274>/Bitwise Operator1'
         */
        mcb_pmsm_foc_qep_f28379d_SIU_DW.Debug_signals = (rtb_DataTypeConversion2
          & 240U) >> 4U;
      }

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S256>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT' */
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_Buffer[mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_ActiveBufIdx
        == 0] = mcb_pmsm_foc_qep_f28379d_SIUn_B.SCIReceive[0];
      mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_ActiveBufIdx =
        (mcb_pmsm_foc_qep_f28379d_SIU_DW.RT_ActiveBufIdx == 0);
    }
  }

  /* Clear occurred Rx FIFO complete event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFINTCLR= 1;
  EDIS;

  /* Clear occurred Rx FIFO overflow event */
  EALLOW;
  SciaRegs.SCIFFRX.bit.RXFFOVRCLR= 1;
  EDIS;
  HWI_TIC28x_AcknowledgeIrq(96);
}

void mcb_pmsm_foc_qep_f28379d_SIUnit_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
  HWI_TIC28x_DisableIRQ(96);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
