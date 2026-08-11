/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * File: testing.c
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

#include "testing.h"
#include "rtwtypes.h"
#include "testing_private.h"
#include <math.h>
#include "rt_nonfinite.h"
#include <string.h>
#include "xcp.h"
#include "ext_mode.h"

extmodeSimulationTime_T currentTime = (extmodeSimulationTime_T) 0;

/* Block signals (default storage) */
B_testing_T testing_B;

/* Block states (default storage) */
DW_testing_T testing_DW;

/* Real-time model */
static RT_MODEL_testing_T testing_M_;
RT_MODEL_testing_T *const testing_M = &testing_M_;
static void rate_scheduler(void);

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcCInitFlag = 0;

#endif

#ifndef __TMS320C28XX_CLA__

uint16_T MW_adcBInitFlag = 0;

#endif

/*
 *         This function updates active task flag for each subrate.
 *         The function is called at model base rate, hence the
 *         generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (testing_M->Timing.TaskCounters.TID[1])++;
  if ((testing_M->Timing.TaskCounters.TID[1]) > 3999) {/* Sample time: [2.0s, 0.0s] */
    testing_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S50>/Two inputs CRL'
 *    '<S90>/Two inputs CRL'
 */
void testing_TwoinputsCRL(real32_T rtu_Ds, real32_T rtu_Qs, real32_T rtu_sin,
  real32_T rtu_cos, real32_T *rty_Alpha, real32_T *rty_Beta,
  P_TwoinputsCRL_testing_T *localP)
{
  /* Switch: '<S52>/Switch' incorporates:
   *  Constant: '<S52>/Offset'
   */
  if (localP->Offset_Value > localP->Switch_Threshold) {
    /* AlgorithmDescriptorDelegate generated from: '<S51>/a16' incorporates:
     *  Product: '<S51>/dcos'
     *  Product: '<S51>/dsin'
     *  Product: '<S51>/qcos'
     *  Product: '<S51>/qsin'
     *  Sum: '<S51>/sum_alpha'
     *  Sum: '<S51>/sum_beta'
     *  UnaryMinus: '<S52>/Unary_Minus'
     */
    *rty_Alpha = rtu_Qs * rtu_cos + rtu_Ds * rtu_sin;
    *rty_Beta = -(rtu_Ds * rtu_cos - rtu_Qs * rtu_sin);
  } else {
    /* AlgorithmDescriptorDelegate generated from: '<S51>/a16' incorporates:
     *  Product: '<S51>/dcos'
     *  Product: '<S51>/dsin'
     *  Product: '<S51>/qcos'
     *  Product: '<S51>/qsin'
     *  Sum: '<S51>/sum_alpha'
     *  Sum: '<S51>/sum_beta'
     */
    *rty_Alpha = rtu_Ds * rtu_cos - rtu_Qs * rtu_sin;
    *rty_Beta = rtu_Qs * rtu_cos + rtu_Ds * rtu_sin;
  }

  /* End of Switch: '<S52>/Switch' */
}

/*
 * Output and update for action system:
 *    '<S71>/If Action Subsystem'
 *    '<S95>/If Action Subsystem'
 */
void testing_IfActionSubsystem(real32_T rtu_In1, real32_T *rty_Out1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S74>/Convert_uint16' */
  tmp = (real32_T)floor(rtu_In1);
  if (rtIsNaNF(tmp) || rtIsInfF(tmp)) {
    tmp = 0.0F;
  } else {
    tmp = (real32_T)fmod(tmp, 65536.0);
  }

  /* Sum: '<S74>/Sum' incorporates:
   *  DataTypeConversion: '<S74>/Convert_back'
   *  DataTypeConversion: '<S74>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(tmp < 0.0F ? -(int16_T)(uint16_T)-tmp :
    (int16_T)(uint16_T)tmp);
}

/*
 * Output and update for action system:
 *    '<S71>/If Action Subsystem1'
 *    '<S95>/If Action Subsystem1'
 */
void testing_IfActionSubsystem1(real32_T rtu_In1, real32_T *rty_Out1)
{
  real32_T tmp;

  /* DataTypeConversion: '<S75>/Convert_uint16' */
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

  /* Sum: '<S75>/Sum' incorporates:
   *  DataTypeConversion: '<S75>/Convert_back'
   *  DataTypeConversion: '<S75>/Convert_uint16'
   */
  *rty_Out1 = rtu_In1 - (real32_T)(tmp < 0.0F ? -(int16_T)(uint16_T)-tmp :
    (int16_T)(uint16_T)tmp);
}

/* System initialize for function-call system: '<Root>/Current Control' */
void testing_CurrentControl_Init(void)
{
  int16_T i;

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  testing_M->Timing.clockTick2 = testing_M->
    Timing.rtmL2HDbBufClockTick[testing_M->Timing.rtmL2HLastBufWr];

  /* Start for S-Function (c280xqep): '<S101>/eQEP' */
  config_QEP_eQEP1((uint32_T)65535U,(uint32_T)0, (uint32_T)0, (uint32_T)0,
                   (uint16_T)0, (uint16_T)448, (uint16_T)8232, (uint16_T)32768,
                   (uint16_T)119,(uint16_T)0);

  /* Start for S-Function (c280xgpio_do): '<S133>/DRV830x Enable' */
  EALLOW;
  GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
  GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
  EDIS;

  /* Start for S-Function (c2802xpwm): '<S133>/ePWM1' */
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

  /* Start for S-Function (c2802xpwm): '<S133>/ePWM2' */
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

  /* Start for S-Function (c2802xpwm): '<S133>/ePWM3' */
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

  /* InitializeConditions for Delay: '<S109>/Delay' */
  for (i = 0; i < 20; i++) {
    testing_DW.Delay_DSTATE_b[i] = testing_P.Delay_InitialCondition_g;
  }

  testing_DW.CircBufIdx = 0U;

  /* End of InitializeConditions for Delay: '<S109>/Delay' */

  /* InitializeConditions for Delay: '<S112>/Delay' */
  testing_DW.icLoad_j = true;

  /* SystemInitialize for Enabled SubSystem: '<S102>/IndexFinder' */
  /* InitializeConditions for Delay: '<S106>/Delay3' */
  testing_DW.Delay3_DSTATE = testing_P.Delay3_InitialCondition;

  /* SystemInitialize for Logic: '<S106>/AND' incorporates:
   *  Outport: '<S106>/Out1'
   */
  testing_B.AND_l = testing_P.Out1_Y0_c;

  /* End of SystemInitialize for SubSystem: '<S102>/IndexFinder' */

  /* SystemInitialize for Enabled SubSystem: '<S102>/Calculate Position' */
  /* InitializeConditions for Delay: '<S104>/Delay' */
  testing_DW.Delay_DSTATE_l = testing_P.Delay_InitialCondition;

  /* InitializeConditions for Delay: '<S104>/Delay1' */
  testing_DW.Delay1_DSTATE = testing_P.Delay1_InitialCondition;

  /* SystemInitialize for Sum: '<S104>/Add1' incorporates:
   *  Outport: '<S104>/Pos'
   */
  testing_B.Add1_h = testing_P.Pos_Y0;

  /* End of SystemInitialize for SubSystem: '<S102>/Calculate Position' */
  /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
  testing_DW.DiscreteTimeIntegrator_DSTATE[0] =
    testing_P.DiscreteTimeIntegrator_IC;
  testing_DW.DiscreteTimeIntegrator_PREV_U[0] = 0.0F;
  testing_DW.DiscreteTimeIntegrator_DSTATE[1] =
    testing_P.DiscreteTimeIntegrator_IC;
  testing_DW.DiscreteTimeIntegrator_PREV_U[1] = 0.0F;

  /* SystemInitialize for AlgorithmDescriptorDelegate generated from: '<S56>/a16' incorporates:
   *  Outport: '<S19>/Iq'
   */
  testing_B.algDD_o2 = testing_P.Iq_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/Closed Loop Control' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Open Loop Start-Up' */
  /* InitializeConditions for DiscreteIntegrator: '<S80>/Ramp Generator' */
  testing_DW.RampGenerator_DSTATE = testing_P.RampGenerator_IC;

  /* InitializeConditions for Delay: '<S79>/Delay' */
  testing_DW.icLoad_i = true;

  /* End of SystemInitialize for SubSystem: '<S15>/Open Loop Start-Up' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Closed Loop Control' */
  /* SystemInitialize for Sum: '<S25>/Sum' incorporates:
   *  Outport: '<S19>/Duty_abc'
   */
  testing_B.Sum[0] = testing_P.Duty_abc_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/Closed Loop Control' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Open Loop Start-Up' */
  /* SystemInitialize for Sum: '<S78>/Sum1' incorporates:
   *  Outport: '<S20>/Duty_abc'
   */
  testing_B.Sum1[0] = testing_P.Duty_abc_Y0_i;

  /* End of SystemInitialize for SubSystem: '<S15>/Open Loop Start-Up' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Closed Loop Control' */
  /* SystemInitialize for Sum: '<S25>/Sum' incorporates:
   *  Outport: '<S19>/Duty_abc'
   */
  testing_B.Sum[1] = testing_P.Duty_abc_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/Closed Loop Control' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Open Loop Start-Up' */
  /* SystemInitialize for Sum: '<S78>/Sum1' incorporates:
   *  Outport: '<S20>/Duty_abc'
   */
  testing_B.Sum1[1] = testing_P.Duty_abc_Y0_i;

  /* End of SystemInitialize for SubSystem: '<S15>/Open Loop Start-Up' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Closed Loop Control' */
  /* SystemInitialize for Sum: '<S25>/Sum' incorporates:
   *  Outport: '<S19>/Duty_abc'
   */
  testing_B.Sum[2] = testing_P.Duty_abc_Y0;

  /* End of SystemInitialize for SubSystem: '<S15>/Closed Loop Control' */

  /* SystemInitialize for Enabled SubSystem: '<S15>/Open Loop Start-Up' */
  /* SystemInitialize for Sum: '<S78>/Sum1' incorporates:
   *  Outport: '<S20>/Duty_abc'
   */
  testing_B.Sum1[2] = testing_P.Duty_abc_Y0_i;

  /* End of SystemInitialize for SubSystem: '<S15>/Open Loop Start-Up' */
  /* End of SystemInitialize for SubSystem: '<S3>/Control_System' */

  /* SystemInitialize for Sum: '<S112>/Add1' incorporates:
   *  Outport: '<S3>/Speed_meas'
   */
  testing_B.Add1_f = testing_P.Speed_meas_Y0;

  /* SystemInitialize for SignalConversion generated from: '<S3>/Iq_measure' incorporates:
   *  Outport: '<S3>/Iq_measure'
   */
  testing_B.OutportBufferForIq_measure = testing_P.Iq_measure_Y0;
}

/* System reset for function-call system: '<Root>/Current Control' */
void testing_CurrentControl_Reset(void)
{
  int16_T i;

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  testing_M->Timing.clockTick2 = testing_M->
    Timing.rtmL2HDbBufClockTick[testing_M->Timing.rtmL2HLastBufWr];

  /* InitializeConditions for Delay: '<S102>/Delay' */
  testing_B.AND_l = testing_P.Delay_InitialCondition_h;

  /* InitializeConditions for Delay: '<S109>/Delay' */
  for (i = 0; i < 20; i++) {
    testing_DW.Delay_DSTATE_b[i] = testing_P.Delay_InitialCondition_g;
  }

  testing_DW.CircBufIdx = 0U;

  /* End of InitializeConditions for Delay: '<S109>/Delay' */

  /* InitializeConditions for Delay: '<S112>/Delay' */
  testing_DW.icLoad_j = true;
}

/* Disable for function-call system: '<Root>/Current Control' */
void testing_CurrentControl_Disable(void)
{
  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  testing_M->Timing.clockTick2 = testing_M->
    Timing.rtmL2HDbBufClockTick[testing_M->Timing.rtmL2HLastBufWr];

  /* Disable for Atomic SubSystem: '<S3>/Control_System' */
  /* Disable for Enabled SubSystem: '<S15>/Closed Loop Control' */
  testing_DW.ClosedLoopControl_MODE = false;

  /* End of Disable for SubSystem: '<S15>/Closed Loop Control' */

  /* Disable for Enabled SubSystem: '<S15>/Open Loop Start-Up' */
  if (testing_DW.OpenLoopStartUp_MODE) {
    /* Disable for DiscreteIntegrator: '<S80>/Ramp Generator' */
    testing_DW.RampGenerator_DSTATE = testing_B.Eps;
    testing_DW.OpenLoopStartUp_MODE = false;
  }

  /* End of Disable for SubSystem: '<S15>/Open Loop Start-Up' */
  /* End of Disable for SubSystem: '<S3>/Control_System' */
}

/* Output and update for function-call system: '<Root>/Current Control' */
void testing_CurrentControl(void)
{
  real32_T rtb_Add;
  real32_T rtb_Add2;
  real32_T rtb_Kbeta;
  real32_T rtb_Kc_h;
  real32_T rtb_Product;
  real32_T rtb_Product_k;
  real32_T rtb_Sum1_j;
  uint32_T ClosedLoopControl_ELAPS_T;
  uint32_T rtb_PositionToCount;
  uint32_T rtb_Sum_a_idx_1;
  uint32_T rtb_Sum_a_idx_3;
  uint16_T rtb_Switch1_b[3];
  uint16_T rtb_Merge_e;
  uint16_T rtb_Sum3_m;
  boolean_T tmp;

  /* Asynchronous task reads absolute time. Data (absolute time)
     transfers from low priority task (base rate) to high priority
     task (asynchronous rate). Double buffers are used to ensure
     data integrity.
     -- rtmL2HLastBufWr is the buffer index that is written last.
   */
  testing_M->Timing.clockTick2 = testing_M->
    Timing.rtmL2HDbBufClockTick[testing_M->Timing.rtmL2HLastBufWr];

  /* S-Function (c280xqep): '<S101>/eQEP' */
  {
    testing_B.eQEP_o1 = EQep1Regs.QPOSCNT;/*eQEP Position Counter*/
    testing_B.eQEP_o2 = EQep1Regs.QPOSILAT;
         /* The position-counter value is latched into this register on an IEL*/
  }

  /* Outputs for Enabled SubSystem: '<S102>/IndexFinder' incorporates:
   *  EnablePort: '<S106>/Enable'
   */
  /* Logic: '<S102>/NOT' incorporates:
   *  Delay: '<S102>/Delay'
   */
  if (!testing_B.AND_l) {
    /* Logic: '<S106>/AND' incorporates:
     *  Constant: '<S113>/Constant'
     *  Constant: '<S114>/Constant'
     *  Delay: '<S106>/Delay3'
     *  RelationalOperator: '<S113>/Compare'
     *  RelationalOperator: '<S114>/Compare'
     */
    testing_B.AND_l = ((testing_DW.Delay3_DSTATE ==
                        testing_P.CompareToConstant_const_j) &&
                       (testing_B.eQEP_o2 > testing_P.CompareToConstant1_const_n));

    /* Update for Delay: '<S106>/Delay3' */
    testing_DW.Delay3_DSTATE = testing_B.eQEP_o2;
    testing_DW.IndexFinder_SubsysRanBC = 4;
  }

  /* End of Logic: '<S102>/NOT' */
  /* End of Outputs for SubSystem: '<S102>/IndexFinder' */

  /* DataStoreWrite: '<S102>/Data Store Write' */
  testing_DW.EnClosedLoop = testing_B.AND_l;

  /* If: '<S108>/If1' incorporates:
   *  Constant: '<S108>/ResetMode'
   */
  if (testing_P.ResetMode_Value > 0) {
    /* Outputs for IfAction SubSystem: '<S108>/PositionNoReset' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Sum: '<S124>/Sum3' */
    rtb_Sum3_m = testing_B.eQEP_o1 - testing_B.eQEP_o2;

    /* Sum: '<S124>/Sum7' incorporates:
     *  Constant: '<S129>/Constant'
     */
    rtb_Merge_e = rtb_Sum3_m + testing_P.Constant_Value_ep;

    /* MinMax: '<S124>/MinMax' */
    if (rtb_Sum3_m <= rtb_Merge_e) {
      rtb_Merge_e = rtb_Sum3_m;
    }

    /* End of MinMax: '<S124>/MinMax' */
    /* End of Outputs for SubSystem: '<S108>/PositionNoReset' */

    /* Update for IfAction SubSystem: '<S108>/PositionNoReset' incorporates:
     *  ActionPort: '<S124>/Action Port'
     */
    /* Update for If: '<S108>/If1' */
    testing_DW.PositionNoReset_SubsysRanBC = 4;

    /* End of Update for SubSystem: '<S108>/PositionNoReset' */
  } else {
    /* Outputs for IfAction SubSystem: '<S108>/PositionResetAtIndex' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* SignalConversion generated from: '<S125>/Count' */
    rtb_Merge_e = testing_B.eQEP_o1;

    /* End of Outputs for SubSystem: '<S108>/PositionResetAtIndex' */

    /* Update for IfAction SubSystem: '<S108>/PositionResetAtIndex' incorporates:
     *  ActionPort: '<S125>/Action Port'
     */
    /* Update for If: '<S108>/If1' */
    testing_DW.PositionResetAtIndex_SubsysRanB = 4;

    /* End of Update for SubSystem: '<S108>/PositionResetAtIndex' */
  }

  /* End of If: '<S108>/If1' */

  /* Product: '<S108>/Product' incorporates:
   *  Constant: '<S130>/Constant'
   *  DataTypeConversion: '<S127>/DTC'
   */
  rtb_Product = (real32_T)rtb_Merge_e * testing_P.Constant_Value_c;

  /* Outputs for Enabled SubSystem: '<S102>/Calculate Position' incorporates:
   *  EnablePort: '<S104>/Enable'
   */
  if (testing_B.AND_l) {
    /* Sum: '<S104>/Add' incorporates:
     *  Delay: '<S104>/Delay'
     */
    rtb_Add = rtb_Product - testing_DW.Delay_DSTATE_l;

    /* Switch: '<S104>/Switch1' incorporates:
     *  Constant: '<S104>/Constant'
     *  Constant: '<S104>/Constant1'
     *  Sum: '<S104>/zero crossing in  Anti CW direction'
     *  Sum: '<S104>/zero crossing in  CW direction'
     *  Switch: '<S104>/Switch'
     */
    if (rtb_Add > testing_P.Switch1_Threshold_o) {
      rtb_Add += testing_P.Constant1_Value;
    } else if (!(rtb_Add > testing_P.Switch_Threshold_k)) {
      rtb_Add += testing_P.Constant_Value_a;
    }

    /* Sum: '<S104>/Add1' incorporates:
     *  Delay: '<S104>/Delay1'
     *  Switch: '<S104>/Switch1'
     */
    testing_B.Add1_h = rtb_Add + testing_DW.Delay1_DSTATE;

    /* Update for Delay: '<S104>/Delay' */
    testing_DW.Delay_DSTATE_l = rtb_Product;

    /* Update for Delay: '<S104>/Delay1' */
    testing_DW.Delay1_DSTATE = testing_B.Add1_h;
    testing_DW.CalculatePosition_SubsysRanBC = 4;
  }

  /* End of Outputs for SubSystem: '<S102>/Calculate Position' */

  /* Gain: '<S109>/PositionToCount' */
  rtb_Add = testing_P.PositionToCount_Gain * rtb_Product;
  if (rtb_Add < 0.0F) {
    rtb_Add = (real32_T)ceil(rtb_Add);
  } else {
    rtb_Add = (real32_T)floor(rtb_Add);
  }

  if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
    rtb_Add = 0.0F;
  } else {
    rtb_Add = (real32_T)fmod(rtb_Add, 4.294967296E+9);
  }

  rtb_PositionToCount = rtb_Add < 0.0F ? (uint32_T)-(int32_T)(uint32_T)-rtb_Add :
    (uint32_T)rtb_Add;

  /* End of Gain: '<S109>/PositionToCount' */

  /* Switch: '<S112>/Switch' incorporates:
   *  Constant: '<S105>/IC'
   *  Constant: '<S105>/Reset'
   *  DataTypeConversion: '<S132>/DTC'
   *  Delay: '<S109>/Delay'
   *  Gain: '<S109>/SpeedGain'
   *  Sum: '<S109>/SpeedCount'
   */
  if (testing_P.Reset_Value) {
    rtb_Product_k = testing_P.IC_Value;
  } else {
    rtb_Product_k = (real32_T)((int32_T)rtb_PositionToCount - (int32_T)
      testing_DW.Delay_DSTATE_b[testing_DW.CircBufIdx]) *
      testing_P.SpeedGain_Gain;
  }

  /* End of Switch: '<S112>/Switch' */

  /* Switch: '<S105>/Switch1' incorporates:
   *  Constant: '<S105>/FilterConstant'
   *  Constant: '<S105>/One'
   *  Constant: '<S105>/OneMinusFilterConstant'
   *  Constant: '<S105>/UseInputPort'
   *  Constant: '<S105>/a'
   *  Sum: '<S105>/Sum'
   */
  if (testing_P.UseInputPort_Value > testing_P.Switch1_Threshold_a) {
    rtb_Add = testing_P.a_Value;
    rtb_Kc_h = testing_P.One_Value_n - testing_P.a_Value;
  } else {
    rtb_Add = testing_P.FilterConstant_Value;
    rtb_Kc_h = testing_P.OneMinusFilterConstant_Value;
  }

  /* End of Switch: '<S105>/Switch1' */

  /* Product: '<S112>/Product' */
  rtb_Product_k *= rtb_Add;

  /* Delay: '<S112>/Delay' incorporates:
   *  Constant: '<S105>/IC'
   */
  if (testing_DW.icLoad_j) {
    testing_DW.Delay_DSTATE_n = testing_P.IC_Value;
  }

  /* Sum: '<S112>/Add1' incorporates:
   *  Delay: '<S112>/Delay'
   *  Product: '<S112>/Product1'
   */
  testing_B.Add1_f = rtb_Kc_h * testing_DW.Delay_DSTATE_n + rtb_Product_k;

  /* Switch: '<S116>/Switch' incorporates:
   *  Constant: '<S116>/Constant'
   *  Constant: '<S116>/Constant1'
   *  Constant: '<S17>/IndexOffset'
   */
  if (testing_P.Constant_Value_as > testing_P.Switch_Threshold_h) {
    rtb_Add = testing_P.Constant1_Value_f;
  } else {
    rtb_Add = testing_P.IndexOffset_Value;
  }

  /* End of Switch: '<S116>/Switch' */

  /* If: '<S117>/If' */
  if (rtb_Product <= rtb_Add) {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Sum: '<S119>/Add' incorporates:
     *  Constant: '<S119>/Constant'
     */
    rtb_Product = (rtb_Product + testing_P.Constant_Value_fl) - rtb_Add;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem' */

    /* Update for IfAction SubSystem: '<S117>/If Action Subsystem' incorporates:
     *  ActionPort: '<S119>/Action Port'
     */
    /* Update for If: '<S117>/If' */
    testing_DW.IfActionSubsystem_SubsysRanBC_a = 4;

    /* End of Update for SubSystem: '<S117>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S117>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Sum: '<S120>/Add' */
    rtb_Product -= rtb_Add;

    /* End of Outputs for SubSystem: '<S117>/If Action Subsystem1' */

    /* Update for IfAction SubSystem: '<S117>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S120>/Action Port'
     */
    /* Update for If: '<S117>/If' */
    testing_DW.IfActionSubsystem1_SubsysRanB_i = 4;

    /* End of Update for SubSystem: '<S117>/If Action Subsystem1' */
  }

  /* End of If: '<S117>/If' */

  /* Gain: '<S122>/Number of pole pairs' */
  rtb_Product *= testing_P.MechanicaltoElectricalPosition_;

  /* Sum: '<S118>/Add' incorporates:
   *  Gain: '<S118>/Multiply'
   *  Gain: '<S118>/Multiply1'
   *  Rounding: '<S118>/Floor'
   */
  testing_B.Add = rtb_Product - (real32_T)floor(testing_P.Multiply_Gain *
    rtb_Product) * testing_P.Multiply1_Gain;

  /* S-Function (c2802xadc): '<S101>/ADC_C_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    testing_B.ADC_C_IN2 = (AdccResultRegs.ADCRESULT0);
  }

  /* S-Function (c2802xadc): '<S101>/ADC_B_IN2' */
  {
    /*  Internal Reference Voltage : Fixed scale 0 to 3.3 V range.  */
    /*  External Reference Voltage : Allowable ranges of VREFHI(ADCINA0) = 3.3 and VREFLO(tied to ground) = 0  */
    testing_B.ADC_B_IN2 = (AdcbResultRegs.ADCRESULT0);
  }

  /* Gain: '<S103>/Get Currents' incorporates:
   *  DataStoreRead: '<S103>/Data Store Read1'
   *  DataStoreRead: '<S103>/Data Store Read2'
   *  DataTypeConversion: '<S103>/Data Type Conversion'
   *  Gain: '<S103>/Get ADC Voltage'
   *  Sum: '<S103>/Add'
   */
  testing_B.GetCurrents[0] = (real32_T)testing_P.GetADCVoltage_Gain *
    4.54747351E-13F * (real32_T)((int32_T)testing_B.ADC_C_IN2 -
    testing_DW.IaOffset) * testing_P.GetCurrents_Gain;
  testing_B.GetCurrents[1] = (real32_T)testing_P.GetADCVoltage_Gain *
    4.54747351E-13F * (real32_T)((int32_T)testing_B.ADC_B_IN2 -
    testing_DW.IbOffset) * testing_P.GetCurrents_Gain;

  /* Outputs for Atomic SubSystem: '<S3>/Control_System' */
  /* Outputs for Enabled SubSystem: '<S15>/Open Loop Start-Up' incorporates:
   *  EnablePort: '<S20>/Enable'
   */
  /* Outputs for Enabled SubSystem: '<S15>/Closed Loop Control' incorporates:
   *  EnablePort: '<S19>/Enable'
   */
  if (testing_B.AND_l) {
    if (!testing_DW.ClosedLoopControl_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      testing_DW.DiscreteTimeIntegrator_DSTATE[0] =
        testing_P.DiscreteTimeIntegrator_IC;
      testing_DW.DiscreteTimeIntegrator_PREV_U[0] = 0.0F;
      testing_DW.DiscreteTimeIntegrator_DSTATE[1] =
        testing_P.DiscreteTimeIntegrator_IC;
      testing_DW.DiscreteTimeIntegrator_PREV_U[1] = 0.0F;
      testing_DW.ClosedLoopControl_RESET_ELAPS_T = true;

      /* Enable for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 1U;
      testing_DW.ClosedLoopControl_MODE = true;
    }

    if (testing_DW.ClosedLoopControl_RESET_ELAPS_T) {
      ClosedLoopControl_ELAPS_T = 0UL;
    } else {
      ClosedLoopControl_ELAPS_T = testing_M->Timing.clockTick2 -
        testing_DW.ClosedLoopControl_PREV_T;
    }

    testing_DW.ClosedLoopControl_PREV_T = testing_M->Timing.clockTick2;
    testing_DW.ClosedLoopControl_RESET_ELAPS_T = false;

    /* Outputs for Atomic SubSystem: '<S30>/Two phase CRL wrap' */
    /* Gain: '<S30>/Kalpha' incorporates:
     *  AlgorithmDescriptorDelegate generated from: '<S31>/a16'
     */
    rtb_Kc_h = testing_P.Kalpha_Gain * testing_B.GetCurrents[0];

    /* Gain: '<S30>/Kbeta' incorporates:
     *  Gain: '<S31>/one_by_sqrt3'
     *  Sum: '<S31>/a_plus_2b'
     */
    rtb_Kbeta = ((testing_B.GetCurrents[0] + testing_B.GetCurrents[1]) +
                 testing_B.GetCurrents[1]) * testing_P.one_by_sqrt3_Gain *
      testing_P.Kbeta_Gain;

    /* End of Outputs for SubSystem: '<S30>/Two phase CRL wrap' */

    /* Gain: '<S71>/convert_pu' */
    rtb_Add = testing_P.convert_pu_Gain * testing_B.Add;

    /* If: '<S71>/If' incorporates:
     *  Constant: '<S73>/Constant'
     *  RelationalOperator: '<S73>/Compare'
     */
    if (rtb_Add < testing_P.Constant_Value_bi) {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      testing_IfActionSubsystem(rtb_Add, &rtb_Product);

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S75>/Action Port'
       */
      testing_IfActionSubsystem1(rtb_Add, &rtb_Product);

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem1' */
    }

    /* End of If: '<S71>/If' */

    /* Gain: '<S69>/indexing' */
    rtb_Product *= testing_P.indexing_Gain;

    /* DataTypeConversion: '<S69>/Get_Integer' */
    if (rtb_Product < 0.0F) {
      rtb_Add = (real32_T)ceil(rtb_Product);
    } else {
      rtb_Add = (real32_T)floor(rtb_Product);
    }

    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = (real32_T)fmod(rtb_Add, 65536.0);
    }

    rtb_Merge_e = rtb_Add < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_Add :
      (uint16_T)rtb_Add;

    /* End of DataTypeConversion: '<S69>/Get_Integer' */

    /* Sum: '<S69>/Sum' incorporates:
     *  Constant: '<S69>/offset'
     */
    rtb_Sum_a_idx_1 = (uint32_T)testing_P.offset_Value[1] + rtb_Merge_e;
    rtb_Sum_a_idx_3 = (uint32_T)testing_P.offset_Value[3] + rtb_Merge_e;

    /* Sum: '<S69>/Sum2' incorporates:
     *  DataTypeConversion: '<S69>/Data Type Conversion1'
     */
    rtb_Add = rtb_Product - (real32_T)rtb_Merge_e;

    /* Sum: '<S70>/Sum4' incorporates:
     *  Constant: '<S69>/offset'
     *  Constant: '<S69>/sine_table_values'
     *  Product: '<S70>/Product'
     *  Selector: '<S69>/Lookup'
     *  Sum: '<S69>/Sum'
     *  Sum: '<S70>/Sum3'
     */
    rtb_Product = (testing_P.sine_table_values_Value[(int16_T)((uint32_T)
      testing_P.offset_Value[0] + rtb_Merge_e)] -
                   testing_P.sine_table_values_Value[(int16_T)rtb_Sum_a_idx_1]) *
      rtb_Add + testing_P.sine_table_values_Value[(int16_T)rtb_Sum_a_idx_1];

    /* Sum: '<S70>/Sum6' incorporates:
     *  Constant: '<S69>/offset'
     *  Constant: '<S69>/sine_table_values'
     *  Product: '<S70>/Product1'
     *  Selector: '<S69>/Lookup'
     *  Sum: '<S69>/Sum'
     *  Sum: '<S70>/Sum5'
     */
    rtb_Product_k = (testing_P.sine_table_values_Value[(int16_T)((uint32_T)
      testing_P.offset_Value[2] + rtb_Merge_e)] -
                     testing_P.sine_table_values_Value[(int16_T)rtb_Sum_a_idx_3])
      * rtb_Add + testing_P.sine_table_values_Value[(int16_T)rtb_Sum_a_idx_3];

    /* Outputs for Atomic SubSystem: '<S55>/Two inputs CRL' */
    /* Switch: '<S57>/Switch' incorporates:
     *  Constant: '<S57>/Offset'
     */
    if (testing_P.Offset_Value_j > testing_P.Switch_Threshold_j) {
      /* AlgorithmDescriptorDelegate generated from: '<S56>/a16' incorporates:
       *  Product: '<S56>/asin'
       *  Product: '<S56>/bcos'
       *  Sum: '<S56>/sum_Qs'
       *  UnaryMinus: '<S57>/Unary_Minus'
       */
      testing_B.algDD_o1 = -(rtb_Kbeta * rtb_Product_k - rtb_Kc_h * rtb_Product);

      /* AlgorithmDescriptorDelegate generated from: '<S56>/a16' incorporates:
       *  Product: '<S56>/acos'
       *  Product: '<S56>/bsin'
       *  Sum: '<S56>/sum_Ds'
       */
      testing_B.algDD_o2 = rtb_Kc_h * rtb_Product_k + rtb_Kbeta * rtb_Product;
    } else {
      /* AlgorithmDescriptorDelegate generated from: '<S56>/a16' incorporates:
       *  Product: '<S56>/acos'
       *  Product: '<S56>/bsin'
       *  Sum: '<S56>/sum_Ds'
       */
      testing_B.algDD_o1 = rtb_Kc_h * rtb_Product_k + rtb_Kbeta * rtb_Product;

      /* AlgorithmDescriptorDelegate generated from: '<S56>/a16' incorporates:
       *  Product: '<S56>/asin'
       *  Product: '<S56>/bcos'
       *  Sum: '<S56>/sum_Qs'
       */
      testing_B.algDD_o2 = rtb_Kbeta * rtb_Product_k - rtb_Kc_h * rtb_Product;
    }

    /* End of Switch: '<S57>/Switch' */
    /* End of Outputs for SubSystem: '<S55>/Two inputs CRL' */
    /* Switch: '<S36>/Switch1' incorporates:
     *  Constant: '<S32>/ReplaceInport_satMethod'
     *  Constant: '<S36>/ChosenMethod'
     *  Constant: '<S36>/enableInportSatMethod'
     */
    if (testing_P.enableInportSatMethod_Value != 0U) {
      rtb_Merge_e = testing_P.ReplaceInport_satMethod_Value;
    } else {
      rtb_Merge_e = testing_P.ChosenMethod_Value;
    }

    /* End of Switch: '<S36>/Switch1' */

    /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
    rtb_Add = testing_P.DiscreteTimeIntegrator_gainval * (real32_T)
      ClosedLoopControl_ELAPS_T;
    if (testing_DW.DiscreteTimeIntegrator_SYSTEM_E == 0U) {
      /* DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */
      testing_DW.DiscreteTimeIntegrator_DSTATE[0] += rtb_Add *
        testing_DW.DiscreteTimeIntegrator_PREV_U[0];
      testing_DW.DiscreteTimeIntegrator_DSTATE[1] += rtb_Add *
        testing_DW.DiscreteTimeIntegrator_PREV_U[1];
    }

    /* End of DiscreteIntegrator: '<S22>/Discrete-Time Integrator' */

    /* MATLAB Function: '<S22>/MATLAB Function' */
    rtb_Kc_h = 4.0F * testing_B.Add1_f;

    /* Sum: '<S22>/Sum1' incorporates:
     *  Gain: '<S22>/Gain'
     *  Gain: '<S22>/Gain1'
     *  MATLAB Function: '<S22>/MATLAB Function'
     *  Sum: '<S22>/Sum'
     */
    rtb_Add = (testing_P.Ki * testing_DW.DiscreteTimeIntegrator_DSTATE[0] -
               testing_P.K * testing_B.algDD_o1) + -rtb_Kc_h * 0.0002F *
      testing_B.algDD_o2;
    rtb_Kc_h = (rtb_Kc_h * 0.0002F * testing_B.algDD_o1 + rtb_Kc_h * 0.0064F) +
      (testing_P.Ki * testing_DW.DiscreteTimeIntegrator_DSTATE[1] - testing_P.K *
       testing_B.algDD_o2);

    /* Sum: '<S37>/Sum1' incorporates:
     *  Product: '<S37>/Product'
     *  Product: '<S37>/Product1'
     */
    rtb_Sum1_j = rtb_Add * rtb_Add + rtb_Kc_h * rtb_Kc_h;

    /* Switch: '<S36>/Switch' incorporates:
     *  Constant: '<S32>/ReplaceInport_satLim'
     *  Constant: '<S36>/Constant3'
     *  Constant: '<S36>/enableInportSatLim'
     */
    if (testing_P.enableInportSatLim_Value != 0U) {
      rtb_Kbeta = testing_P.ReplaceInport_satLim_Value;
    } else {
      rtb_Kbeta = testing_P.Constant3_Value;
    }

    /* End of Switch: '<S36>/Switch' */

    /* Product: '<S36>/Product' */
    rtb_Add2 = rtb_Kbeta * rtb_Kbeta;

    /* If: '<S32>/If' incorporates:
     *  If: '<S35>/If'
     *  RelationalOperator: '<S35>/Relational Operator'
     */
    if ((rtb_Merge_e == 1U) || (rtb_Merge_e == 2U)) {
      /* Outputs for IfAction SubSystem: '<S32>/D or Q Axis Priority' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* Switch: '<S34>/Switch' incorporates:
       *  Constant: '<S38>/Constant'
       *  RelationalOperator: '<S38>/Compare'
       */
      if (rtb_Merge_e == testing_P.CompareToConstant_const_g) {
        rtb_Sum1_j = rtb_Add;
        rtb_Add = rtb_Kc_h;
      } else {
        rtb_Sum1_j = rtb_Kc_h;
      }

      /* End of Switch: '<S34>/Switch' */

      /* Switch: '<S43>/Switch2' incorporates:
       *  RelationalOperator: '<S43>/LowerRelop1'
       */
      if (rtb_Sum1_j > rtb_Kbeta) {
        rtb_Sum1_j = rtb_Kbeta;
      } else {
        /* Gain: '<S42>/Gain' */
        rtb_Kc_h = testing_P.Gain_Gain_d * rtb_Kbeta;

        /* Switch: '<S43>/Switch' incorporates:
         *  RelationalOperator: '<S43>/UpperRelop'
         */
        if (rtb_Sum1_j < rtb_Kc_h) {
          rtb_Sum1_j = rtb_Kc_h;
        }

        /* End of Switch: '<S43>/Switch' */
      }

      /* End of Switch: '<S43>/Switch2' */

      /* Sum: '<S42>/Sum' incorporates:
       *  Product: '<S42>/Product'
       */
      rtb_Kc_h = rtb_Add2 - rtb_Sum1_j * rtb_Sum1_j;

      /* If: '<S42>/If' incorporates:
       *  Product: '<S42>/Product2'
       *  RelationalOperator: '<S42>/Relational Operator'
       *  Switch: '<S44>/Switch'
       *  Switch: '<S44>/Switch1'
       */
      if (rtb_Kc_h >= rtb_Add * rtb_Add) {
        /* Outputs for IfAction SubSystem: '<S42>/passThrough' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* SignalConversion generated from: '<S45>/ref2' */
        rtb_Kc_h = rtb_Add;

        /* End of Outputs for SubSystem: '<S42>/passThrough' */

        /* Update for IfAction SubSystem: '<S42>/passThrough' incorporates:
         *  ActionPort: '<S45>/Action Port'
         */
        /* Update for If: '<S42>/If' */
        testing_DW.passThrough_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S42>/passThrough' */
      } else {
        /* Outputs for IfAction SubSystem: '<S42>/limitRef2' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        if (rtb_Add >= testing_P.Switch_Threshold_i) {
          /* Switch: '<S44>/Switch1' incorporates:
           *  Constant: '<S44>/Constant'
           */
          if (!(rtb_Kc_h > testing_P.Switch1_Threshold)) {
            rtb_Kc_h = testing_P.Constant_Value_e;
          }

          /* Switch: '<S44>/Switch' incorporates:
           *  Sqrt: '<S44>/Sqrt'
           *  Switch: '<S44>/Switch1'
           */
          rtb_Kc_h = (real32_T)sqrt(rtb_Kc_h);
        } else {
          if (!(rtb_Kc_h > testing_P.Switch1_Threshold)) {
            /* Switch: '<S44>/Switch1' incorporates:
             *  Constant: '<S44>/Constant'
             */
            rtb_Kc_h = testing_P.Constant_Value_e;
          }

          /* Switch: '<S44>/Switch' incorporates:
           *  Gain: '<S44>/Gain'
           *  Sqrt: '<S44>/Sqrt'
           *  Switch: '<S44>/Switch1'
           */
          rtb_Kc_h = testing_P.Gain_Gain * (real32_T)sqrt(rtb_Kc_h);
        }

        /* End of Outputs for SubSystem: '<S42>/limitRef2' */

        /* Update for IfAction SubSystem: '<S42>/limitRef2' incorporates:
         *  ActionPort: '<S44>/Action Port'
         */
        /* Update for If: '<S42>/If' incorporates:
         *  Switch: '<S44>/Switch1'
         */
        testing_DW.limitRef2_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S42>/limitRef2' */
      }

      /* End of If: '<S42>/If' */

      /* Switch: '<S34>/Switch1' incorporates:
       *  Constant: '<S39>/Constant'
       *  RelationalOperator: '<S39>/Compare'
       */
      if (rtb_Merge_e == testing_P.CompareToConstant1_const_p) {
        rtb_Add = rtb_Sum1_j;
      } else {
        rtb_Add = rtb_Kc_h;
        rtb_Kc_h = rtb_Sum1_j;
      }

      /* End of Switch: '<S34>/Switch1' */
      /* End of Outputs for SubSystem: '<S32>/D or Q Axis Priority' */

      /* Update for IfAction SubSystem: '<S32>/D or Q Axis Priority' incorporates:
       *  ActionPort: '<S34>/Action Port'
       */
      /* Update for If: '<S32>/If' */
      testing_DW.DorQAxisPriority_SubsysRanBC = 4;

      /* End of Update for SubSystem: '<S32>/D or Q Axis Priority' */
    } else {
      /* Outputs for IfAction SubSystem: '<S32>/D-Q Equivalence' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      if (rtb_Sum1_j > rtb_Add2) {
        /* Outputs for IfAction SubSystem: '<S35>/Limiter' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        /* If: '<S35>/If' incorporates:
         *  Product: '<S46>/Divide'
         *  Product: '<S46>/Product'
         *  Sqrt: '<S46>/Square Root'
         *  Switch: '<S46>/Switch'
         */
        rtb_Add2 = (real32_T)sqrt(rtb_Sum1_j);
        rtb_Add = rtb_Add * rtb_Kbeta / rtb_Add2;
        rtb_Kc_h = rtb_Kc_h * rtb_Kbeta / rtb_Add2;

        /* End of Outputs for SubSystem: '<S35>/Limiter' */

        /* Update for IfAction SubSystem: '<S35>/Limiter' incorporates:
         *  ActionPort: '<S46>/Action Port'
         */
        /* Update for If: '<S35>/If' */
        testing_DW.Limiter_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S35>/Limiter' */
      } else {
        /* Update for IfAction SubSystem: '<S35>/Passthrough' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        /* Update for If: '<S35>/If' */
        testing_DW.Passthrough_SubsysRanBC = 4;

        /* End of Update for SubSystem: '<S35>/Passthrough' */
      }

      /* End of Outputs for SubSystem: '<S32>/D-Q Equivalence' */

      /* Update for IfAction SubSystem: '<S32>/D-Q Equivalence' incorporates:
       *  ActionPort: '<S35>/Action Port'
       */
      /* Update for If: '<S32>/If' */
      testing_DW.DQEquivalence_SubsysRanBC = 4;

      /* End of Update for SubSystem: '<S32>/D-Q Equivalence' */
    }

    /* End of If: '<S32>/If' */

    /* Outputs for Atomic SubSystem: '<S50>/Two inputs CRL' */
    testing_TwoinputsCRL(rtb_Add, rtb_Kc_h, rtb_Product, rtb_Product_k,
                         &rtb_Add2, &rtb_Kbeta, &testing_P.TwoinputsCRL);

    /* End of Outputs for SubSystem: '<S50>/Two inputs CRL' */

    /* Gain: '<S68>/Ka' */
    rtb_Add = testing_P.Ka_Gain * rtb_Add2;

    /* Gain: '<S68>/one_by_two' */
    rtb_Product_k = testing_P.one_by_two_Gain * rtb_Add2;

    /* Gain: '<S68>/sqrt3_by_two' */
    rtb_Product = testing_P.sqrt3_by_two_Gain * rtb_Kbeta;

    /* Gain: '<S68>/Kb' incorporates:
     *  Sum: '<S68>/add_b'
     */
    rtb_Kbeta = (rtb_Product - rtb_Product_k) * testing_P.Kb_Gain;

    /* Gain: '<S68>/Kc' incorporates:
     *  Sum: '<S68>/add_c'
     */
    rtb_Product_k = ((0.0F - rtb_Product_k) - rtb_Product) * testing_P.Kc_Gain;

    /* MinMax: '<S62>/Max' incorporates:
     *  MinMax: '<S62>/Min'
     */
    tmp = rtIsNaNF(rtb_Kbeta);
    if ((rtb_Add >= rtb_Kbeta) || tmp) {
      rtb_Product = rtb_Add;
    } else {
      rtb_Product = rtb_Kbeta;
    }

    /* MinMax: '<S62>/Min' */
    if ((rtb_Add <= rtb_Kbeta) || tmp) {
      rtb_Kc_h = rtb_Add;
    } else {
      rtb_Kc_h = rtb_Kbeta;
    }

    /* MinMax: '<S62>/Max' incorporates:
     *  MinMax: '<S62>/Min'
     */
    tmp = !rtIsNaNF(rtb_Product_k);
    if ((!(rtb_Product >= rtb_Product_k)) && tmp) {
      rtb_Product = rtb_Product_k;
    }

    /* MinMax: '<S62>/Min' */
    if ((!(rtb_Kc_h <= rtb_Product_k)) && tmp) {
      rtb_Kc_h = rtb_Product_k;
    }

    /* Gain: '<S62>/one_by_two' incorporates:
     *  MinMax: '<S62>/Max'
     *  MinMax: '<S62>/Min'
     *  Sum: '<S62>/Add'
     */
    rtb_Add2 = (rtb_Product + rtb_Kc_h) * testing_P.one_by_two_Gain_f;

    /* Sum: '<S25>/Sum' incorporates:
     *  Constant: '<S25>/Constant'
     *  Gain: '<S25>/Normalize [-0.5 to 0.5]'
     *  Gain: '<S61>/Gain'
     *  Sum: '<S61>/Add1'
     *  Sum: '<S61>/Add2'
     *  Sum: '<S61>/Add3'
     */
    testing_B.Sum[0] = (rtb_Add + rtb_Add2) * testing_P.Gain_Gain_k *
      testing_P.Normalize05to05_Gain + testing_P.Constant_Value_g;
    testing_B.Sum[1] = (rtb_Kbeta + rtb_Add2) * testing_P.Gain_Gain_k *
      testing_P.Normalize05to05_Gain + testing_P.Constant_Value_g;
    testing_B.Sum[2] = (rtb_Add2 + rtb_Product_k) * testing_P.Gain_Gain_k *
      testing_P.Normalize05to05_Gain + testing_P.Constant_Value_g;

    /* Update for DiscreteIntegrator: '<S22>/Discrete-Time Integrator' incorporates:
     *  Sum: '<S22>/Add'
     */
    testing_DW.DiscreteTimeIntegrator_SYSTEM_E = 0U;
    testing_DW.DiscreteTimeIntegrator_PREV_U[0] = testing_B.RT2[0] -
      testing_B.algDD_o1;
    testing_DW.DiscreteTimeIntegrator_PREV_U[1] = testing_B.RT2[1] -
      testing_B.algDD_o2;
    testing_DW.ClosedLoopControl_SubsysRanBC = 4;
    if (testing_DW.OpenLoopStartUp_MODE) {
      /* Disable for DiscreteIntegrator: '<S80>/Ramp Generator' */
      testing_DW.RampGenerator_DSTATE = testing_B.Eps;
      testing_DW.OpenLoopStartUp_MODE = false;
    }

    /* Switch: '<S15>/Switch4' */
    testing_B.PWM_Duty_Cycles[0] = testing_B.Sum[0];
    testing_B.PWM_Duty_Cycles[1] = testing_B.Sum[1];
    testing_B.PWM_Duty_Cycles[2] = testing_B.Sum[2];
  } else {
    testing_DW.ClosedLoopControl_MODE = false;
    if (!testing_DW.OpenLoopStartUp_MODE) {
      /* InitializeConditions for DiscreteIntegrator: '<S80>/Ramp Generator' */
      testing_DW.RampGenerator_DSTATE = testing_P.RampGenerator_IC;

      /* InitializeConditions for Delay: '<S79>/Delay' */
      testing_DW.icLoad_i = true;
      testing_DW.OpenLoopStartUp_MODE = true;
    }

    /* DiscreteIntegrator: '<S80>/Ramp Generator' incorporates:
     *  DataStoreRead: '<S20>/Data Store Read1'
     *  Logic: '<S80>/NOT'
     */
    if (!testing_DW.Enable) {
      testing_DW.RampGenerator_DSTATE = testing_P.RampGenerator_IC;
    }

    /* DiscreteIntegrator: '<S80>/Ramp Generator' */
    testing_B.Eps = testing_DW.RampGenerator_DSTATE;

    /* Abs: '<S20>/Abs' incorporates:
     *  Constant: '<S20>/Ramp_Time (sec)1'
     *  Gain: '<S20>/rpm2freq'
     *  Product: '<S20>/Product'
     */
    rtb_Product = fabsf(testing_P.rpm2freq_Gain * testing_P.Ramp_Timesec1_Value *
                        testing_B.Eps);

    /* Gain: '<S20>/V-by-f' */
    rtb_Product_k = testing_P.Vbyf_Gain * rtb_Product;

    /* Product: '<S79>/Product' incorporates:
     *  Constant: '<S79>/InputGain'
     *  Gain: '<S20>/position_increment'
     */
    rtb_Kc_h = testing_P.position_increment_Gain * rtb_Product *
      testing_P.InputGain_Value;

    /* Delay: '<S79>/Delay' */
    if (testing_DW.icLoad_i) {
      /* Sum: '<S79>/Sum' incorporates:
       *  Constant: '<S79>/InputGain'
       *  Constant: '<S79>/Offset'
       *  Product: '<S79>/Product1'
       *  Sum: '<S79>/Sum1'
       */
      testing_DW.Delay_DSTATE_h = testing_P.Offset_Value *
        testing_P.InputGain_Value - rtb_Kc_h;
    }

    /* Sum: '<S79>/Sum' incorporates:
     *  Delay: '<S79>/Delay'
     */
    testing_DW.Delay_DSTATE_h += rtb_Kc_h;

    /* Switch: '<S79>/Switch1' */
    if (!(testing_DW.Delay_DSTATE_h > testing_P.Switch1_Threshold_e)) {
      /* Sum: '<S79>/Sum' incorporates:
       *  Constant: '<S79>/Bias1'
       *  Sum: '<S79>/Sum2'
       */
      testing_DW.Delay_DSTATE_h += testing_P.Bias1_Value;
    }

    /* End of Switch: '<S79>/Switch1' */

    /* Switch: '<S79>/Switch2' */
    if (testing_DW.Delay_DSTATE_h >= testing_P.Switch2_Threshold) {
      /* Sum: '<S79>/Sum' incorporates:
       *  Constant: '<S79>/Bias2'
       *  Sum: '<S79>/Sum3'
       */
      testing_DW.Delay_DSTATE_h += testing_P.Bias2_Value;
    }

    /* End of Switch: '<S79>/Switch2' */

    /* Switch: '<S20>/Direction' incorporates:
     *  Constant: '<S20>/ '
     *  Constant: '<S79>/OutputGain'
     *  DataStoreRead: '<S20>/Data Store Read'
     *  Product: '<S79>/Product2'
     *  Sum: '<S20>/Sum'
     */
    if (testing_DW.Speed_ref > testing_P.Direction_Threshold) {
      rtb_Kc_h = testing_DW.Delay_DSTATE_h * testing_P.OutputGain_Value;
    } else {
      rtb_Kc_h = testing_P._Value - testing_DW.Delay_DSTATE_h *
        testing_P.OutputGain_Value;
    }

    /* End of Switch: '<S20>/Direction' */

    /* Gain: '<S95>/convert_pu' */
    rtb_Product = testing_P.convert_pu_Gain_c * rtb_Kc_h;

    /* If: '<S95>/If' incorporates:
     *  Constant: '<S97>/Constant'
     *  RelationalOperator: '<S97>/Compare'
     */
    if (rtb_Product < testing_P.Constant_Value_d) {
      /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem' incorporates:
       *  ActionPort: '<S98>/Action Port'
       */
      testing_IfActionSubsystem(rtb_Product, &rtb_Kc_h);

      /* End of Outputs for SubSystem: '<S95>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S95>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S99>/Action Port'
       */
      testing_IfActionSubsystem1(rtb_Product, &rtb_Kc_h);

      /* End of Outputs for SubSystem: '<S95>/If Action Subsystem1' */
    }

    /* End of If: '<S95>/If' */

    /* Gain: '<S93>/indexing' */
    rtb_Kc_h *= testing_P.indexing_Gain_o;

    /* DataTypeConversion: '<S93>/Get_Integer' */
    if (rtb_Kc_h < 0.0F) {
      rtb_Add = (real32_T)ceil(rtb_Kc_h);
    } else {
      rtb_Add = (real32_T)floor(rtb_Kc_h);
    }

    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = (real32_T)fmod(rtb_Add, 65536.0);
    }

    rtb_Merge_e = rtb_Add < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_Add :
      (uint16_T)rtb_Add;

    /* End of DataTypeConversion: '<S93>/Get_Integer' */

    /* Sum: '<S93>/Sum2' incorporates:
     *  DataTypeConversion: '<S93>/Data Type Conversion1'
     */
    rtb_Add = rtb_Kc_h - (real32_T)rtb_Merge_e;

    /* Product: '<S94>/Product' incorporates:
     *  Constant: '<S93>/offset'
     *  Constant: '<S93>/sine_table_values'
     *  Selector: '<S93>/Lookup'
     *  Sum: '<S93>/Sum'
     *  Sum: '<S94>/Sum3'
     */
    rtb_Product = (testing_P.sine_table_values_Value_b[(int16_T)((uint32_T)
      testing_P.offset_Value_j[0] + rtb_Merge_e)] -
                   testing_P.sine_table_values_Value_b[(int16_T)((uint32_T)
      testing_P.offset_Value_j[1] + rtb_Merge_e)]) * rtb_Add;

    /* Gain: '<S20>/Correction_Factor_sinePWM' */
    rtb_Kc_h = testing_P.Correction_Factor_sinePWM_Gain * rtb_Product_k;

    /* Saturate: '<S20>/Saturation' */
    if (rtb_Kc_h > testing_P.Saturation_UpperSat) {
      rtb_Kc_h = testing_P.Saturation_UpperSat;
    } else if (rtb_Kc_h < testing_P.Saturation_LowerSat) {
      rtb_Kc_h = testing_P.Saturation_LowerSat;
    }

    /* Outputs for Atomic SubSystem: '<S90>/Two inputs CRL' */
    /* Constant: '<S77>/Constant' incorporates:
     *  Constant: '<S93>/offset'
     *  Constant: '<S93>/sine_table_values'
     *  Product: '<S94>/Product1'
     *  Saturate: '<S20>/Saturation'
     *  Selector: '<S93>/Lookup'
     *  Sum: '<S93>/Sum'
     *  Sum: '<S94>/Sum4'
     *  Sum: '<S94>/Sum5'
     *  Sum: '<S94>/Sum6'
     *  UnaryMinus: '<S77>/Unary Minus'
     */
    testing_TwoinputsCRL(testing_P.Constant_Value_h2, -rtb_Kc_h, rtb_Product +
                         testing_P.sine_table_values_Value_b[(int16_T)((uint32_T)
      testing_P.offset_Value_j[1] + rtb_Merge_e)],
                         (testing_P.sine_table_values_Value_b[(int16_T)
                          ((uint32_T)testing_P.offset_Value_j[2] + rtb_Merge_e)]
                          - testing_P.sine_table_values_Value_b[(int16_T)
                          ((uint32_T)testing_P.offset_Value_j[3] + rtb_Merge_e)])
                         * rtb_Add + testing_P.sine_table_values_Value_b
                         [(int16_T)((uint32_T)testing_P.offset_Value_j[3] +
      rtb_Merge_e)], &rtb_Product_k, &rtb_Product, &testing_P.TwoinputsCRL_p);

    /* End of Outputs for SubSystem: '<S90>/Two inputs CRL' */

    /* Gain: '<S87>/one_by_two' */
    rtb_Kc_h = testing_P.one_by_two_Gain_j * rtb_Product_k;

    /* Gain: '<S87>/sqrt3_by_two' */
    rtb_Product *= testing_P.sqrt3_by_two_Gain_h;

    /* Sum: '<S78>/Sum1' incorporates:
     *  Constant: '<S78>/Constant'
     *  Gain: '<S78>/Normalize'
     *  Gain: '<S87>/Ka'
     *  Gain: '<S87>/Kb'
     *  Gain: '<S87>/Kc'
     *  Sum: '<S87>/add_b'
     *  Sum: '<S87>/add_c'
     */
    testing_B.Sum1[0] = testing_P.Ka_Gain_l * rtb_Product_k *
      testing_P.Normalize_Gain + testing_P.Constant_Value_f;
    testing_B.Sum1[1] = (rtb_Product - rtb_Kc_h) * testing_P.Kb_Gain_g *
      testing_P.Normalize_Gain + testing_P.Constant_Value_f;
    testing_B.Sum1[2] = ((0.0F - rtb_Kc_h) - rtb_Product) * testing_P.Kc_Gain_h *
      testing_P.Normalize_Gain + testing_P.Constant_Value_f;

    /* Update for DiscreteIntegrator: '<S80>/Ramp Generator' incorporates:
     *  Constant: '<S20>/Ramp_Time (sec)'
     *  Constant: '<S80>/One'
     *  Gain: '<S80>/Sample_Time'
     *  Product: '<S80>/Divide'
     */
    testing_DW.RampGenerator_DSTATE += testing_P.One_Value /
      testing_P.Ramp_Timesec_Value * testing_P.Ts *
      testing_P.RampGenerator_gainval;
    if (testing_DW.RampGenerator_DSTATE > testing_P.RampGenerator_UpperSat) {
      testing_DW.RampGenerator_DSTATE = testing_P.RampGenerator_UpperSat;
    } else if (testing_DW.RampGenerator_DSTATE <
               testing_P.RampGenerator_LowerSat) {
      testing_DW.RampGenerator_DSTATE = testing_P.RampGenerator_LowerSat;
    }

    /* End of Update for DiscreteIntegrator: '<S80>/Ramp Generator' */

    /* Update for Delay: '<S79>/Delay' */
    testing_DW.icLoad_i = false;
    testing_DW.OpenLoopStartUp_SubsysRanBC = 4;

    /* Switch: '<S15>/Switch4' */
    testing_B.PWM_Duty_Cycles[0] = testing_B.Sum1[0];
    testing_B.PWM_Duty_Cycles[1] = testing_B.Sum1[1];
    testing_B.PWM_Duty_Cycles[2] = testing_B.Sum1[2];
  }

  /* End of Outputs for SubSystem: '<S15>/Closed Loop Control' */
  /* End of Outputs for SubSystem: '<S15>/Open Loop Start-Up' */
  /* Switch: '<S133>/Switch' incorporates:
   *  Constant: '<S133>/Constant'
   */
  if (testing_P.Constant_Value > testing_P.Switch_Threshold) {
    /* Switch: '<S133>/Switch' incorporates:
     *  DataStoreRead: '<S133>/Enable'
     */
    testing_B.Switch_k = testing_DW.Enable;
  } else {
    /* Switch: '<S133>/Switch' incorporates:
     *  DataStoreRead: '<S133>/Enable'
     *  Logic: '<S133>/NOT'
     */
    testing_B.Switch_k = !testing_DW.Enable;
  }

  /* End of Switch: '<S133>/Switch' */

  /* S-Function (c280xgpio_do): '<S133>/DRV830x Enable' */
  {
    if (testing_B.Switch_k) {
      GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
    } else {
      GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
    }
  }

  /* Switch: '<S133>/Switch1' incorporates:
   *  Constant: '<S133>/stop'
   *  DataStoreRead: '<S133>/Enable'
   *  Gain: '<S133>/Scale_to_PWM_Counter_PRD'
   */
  if (testing_DW.Enable) {
    /* Gain: '<S133>/Scale_to_PWM_Counter_PRD' */
    rtb_Add = testing_P.Scale_to_PWM_Counter_PRD_Gain *
      testing_B.PWM_Duty_Cycles[0];
    if (rtb_Add < 0.0F) {
      rtb_Add = (real32_T)ceil(rtb_Add);
    } else {
      rtb_Add = (real32_T)floor(rtb_Add);
    }

    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = (real32_T)fmod(rtb_Add, 65536.0);
    }

    rtb_Switch1_b[0] = rtb_Add < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_Add :
      (uint16_T)rtb_Add;

    /* Gain: '<S133>/Scale_to_PWM_Counter_PRD' */
    rtb_Add = testing_P.Scale_to_PWM_Counter_PRD_Gain *
      testing_B.PWM_Duty_Cycles[1];
    if (rtb_Add < 0.0F) {
      rtb_Add = (real32_T)ceil(rtb_Add);
    } else {
      rtb_Add = (real32_T)floor(rtb_Add);
    }

    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = (real32_T)fmod(rtb_Add, 65536.0);
    }

    rtb_Switch1_b[1] = rtb_Add < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_Add :
      (uint16_T)rtb_Add;

    /* Gain: '<S133>/Scale_to_PWM_Counter_PRD' */
    rtb_Add = testing_P.Scale_to_PWM_Counter_PRD_Gain *
      testing_B.PWM_Duty_Cycles[2];
    if (rtb_Add < 0.0F) {
      rtb_Add = (real32_T)ceil(rtb_Add);
    } else {
      rtb_Add = (real32_T)floor(rtb_Add);
    }

    if (rtIsNaNF(rtb_Add) || rtIsInfF(rtb_Add)) {
      rtb_Add = 0.0F;
    } else {
      rtb_Add = (real32_T)fmod(rtb_Add, 65536.0);
    }

    rtb_Switch1_b[2] = rtb_Add < 0.0F ? (uint16_T)-(int16_T)(uint16_T)-rtb_Add :
      (uint16_T)rtb_Add;
  } else {
    rtb_Switch1_b[0] = testing_P.stop_Value;
    rtb_Switch1_b[1] = testing_P.stop_Value;
    rtb_Switch1_b[2] = testing_P.stop_Value;
  }

  /* End of Switch: '<S133>/Switch1' */

  /* S-Function (c2802xpwm): '<S133>/ePWM1' */
  uint16_T tbprdValue1Outputs = EPwm1Regs.TBPRD;

  /*-- Update CMPA value for ePWM1 --*/
  {
    EPwm1Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_b[0]);
  }

  /* S-Function (c2802xpwm): '<S133>/ePWM2' */
  uint16_T tbprdValue2Outputs = EPwm2Regs.TBPRD;

  /*-- Update CMPA value for ePWM2 --*/
  {
    EPwm2Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_b[1]);
  }

  /* S-Function (c2802xpwm): '<S133>/ePWM3' */
  uint16_T tbprdValue3Outputs = EPwm3Regs.TBPRD;

  /*-- Update CMPA value for ePWM3 --*/
  {
    EPwm3Regs.CMPA.bit.CMPA = (uint16_T)(rtb_Switch1_b[2]);
  }

  /* SignalConversion generated from: '<S3>/Iq_measure' */
  testing_B.OutportBufferForIq_measure = testing_B.algDD_o2;

  /* Update for Delay: '<S109>/Delay' */
  testing_DW.Delay_DSTATE_b[testing_DW.CircBufIdx] = rtb_PositionToCount;
  if (testing_DW.CircBufIdx < 19U) {
    testing_DW.CircBufIdx++;
  } else {
    testing_DW.CircBufIdx = 0U;
  }

  /* End of Update for Delay: '<S109>/Delay' */

  /* Update for Delay: '<S112>/Delay' */
  testing_DW.icLoad_j = false;
  testing_DW.Delay_DSTATE_n = testing_B.Add1_f;
  testing_DW.CurrentControl_SubsysRanBC = 4;
}

/* System initialize for atomic system: */
void testing_SPIMasterTransfer_Init(DW_SPIMasterTransfer_testing_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Start for MATLABSystem: '<S147>/SPI Master Transfer' */
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
void testing_SPIMasterTransfer(uint16_T rtu_0, B_SPIMasterTransfer_testing_T
  *localB, DW_SPIMasterTransfer_testing_T *localDW)
{
  uint16_T status;

  /* MATLABSystem: '<S147>/SPI Master Transfer' */
  MW_SPI_SetSlaveSelect(localDW->obj.MW_SPI_HANDLE, 0U, true);
  status = MW_SPI_SetFormat(localDW->obj.MW_SPI_HANDLE, 16U, MW_SPI_MODE_0,
    MW_SPI_MOST_SIGNIFICANT_BIT_FIRST);
  if (status == 0U) {
    MW_SPI_MasterWriteRead_8bits(localDW->obj.MW_SPI_HANDLE, &rtu_0,
      &localB->SPIMasterTransfer, 1UL);
  }

  /* End of MATLABSystem: '<S147>/SPI Master Transfer' */
}

/* Termination for atomic system: */
void testing_SPIMasterTransfer_Term(DW_SPIMasterTransfer_testing_T *localDW)
{
  uint32_T SPIPinsLoc;

  /* Terminate for MATLABSystem: '<S147>/SPI Master Transfer' */
  if (!localDW->obj.matlabCodegenIsDeleted) {
    localDW->obj.matlabCodegenIsDeleted = true;
    if ((localDW->obj.isInitialized == 1L) && localDW->obj.isSetupComplete) {
      SPIPinsLoc = MW_UNDEFINED_VALUE;
      MW_SPI_Close(localDW->obj.MW_SPI_HANDLE, SPIPinsLoc, SPIPinsLoc,
                   SPIPinsLoc, MW_UNDEFINED_VALUE);
    }
  }

  /* End of Terminate for MATLABSystem: '<S147>/SPI Master Transfer' */
}

/* System initialize for atomic system: '<Root>/Speed Control' */
void testing_SpeedControl_Init(DW_SpeedControl_testing_T *localDW,
  P_SpeedControl_testing_T *localP)
{
  /* InitializeConditions for Delay: '<S217>/Delay' */
  localDW->icLoad = true;

  /* InitializeConditions for DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Constant: '<S157>/Ki2'
   */
  localDW->Integrator_DSTATE = localP->Ki2_Value;
  localDW->Integrator_PrevResetState = 0;
}

/* Output and update for atomic system: '<Root>/Speed Control' */
void testing_SpeedControl(real32_T rtu_Speed_Ref, real32_T rtu_Speed_Meas,
  real32_T rtu_In1, real32_T rtu_In2, real32_T *rty_IdqRef, real32_T
  *rty_IdqRef_f, const boolean_T *rtd_EnClosedLoop, const boolean_T *rtd_Enable,
  B_SpeedControl_testing_T *localB, DW_SpeedControl_testing_T *localDW,
  P_SpeedControl_testing_T *localP)
{
  real32_T rtb_Switch1_k_idx_0;
  real32_T rtb_Switch1_k_idx_1;
  real32_T tmp;
  int16_T rtb_Switch1_g;
  int16_T tmp_0;
  boolean_T rtb_AND;
  boolean_T rtb_RelationalOperator_o;

  /* Logic: '<S158>/AND' incorporates:
   *  DataStoreRead: '<S158>/Data Store Read'
   *  DataStoreRead: '<S158>/Data Store Read1'
   */
  rtb_AND = ((*rtd_EnClosedLoop) && (*rtd_Enable));

  /* Switch: '<S158>/Switch' */
  if (rtb_AND) {
    /* Switch: '<S158>/Switch' */
    localB->Switch = rtu_Speed_Ref;
  } else {
    /* Switch: '<S158>/Switch' */
    localB->Switch = rtu_Speed_Meas;
  }

  /* End of Switch: '<S158>/Switch' */
  /* Constant: '<S14>/Id_ref' */
  *rty_IdqRef = localP->Id_ref_Value;

  /* Switch: '<S160>/Switch1' incorporates:
   *  Constant: '<S160>/FilterConstant'
   *  Constant: '<S160>/One'
   *  Constant: '<S160>/OneMinusFilterConstant'
   *  Constant: '<S160>/UseInputPort'
   *  Constant: '<S160>/a'
   *  Sum: '<S160>/Sum'
   */
  if (localP->UseInputPort_Value > localP->Switch1_Threshold) {
    rtb_Switch1_k_idx_0 = localP->a_Value;
    rtb_Switch1_k_idx_1 = localP->One_Value - localP->a_Value;
  } else {
    rtb_Switch1_k_idx_0 = localP->FilterConstant_Value;
    rtb_Switch1_k_idx_1 = localP->OneMinusFilterConstant_Value;
  }

  /* End of Switch: '<S160>/Switch1' */

  /* Delay: '<S217>/Delay' */
  if (localDW->icLoad) {
    /* Sum: '<S217>/Add1' incorporates:
     *  Constant: '<S160>/IC'
     */
    localDW->Delay_DSTATE = localP->IC_Value;
  }

  /* Switch: '<S217>/Switch' incorporates:
   *  Constant: '<S160>/IC'
   *  Constant: '<S160>/Reset'
   */
  if (localP->Reset_Value) {
    tmp = localP->IC_Value;
  } else {
    tmp = localB->Switch;
  }

  /* Sum: '<S217>/Add1' incorporates:
   *  Delay: '<S217>/Delay'
   *  Product: '<S217>/Product'
   *  Product: '<S217>/Product1'
   *  Switch: '<S217>/Switch'
   */
  localDW->Delay_DSTATE = tmp * rtb_Switch1_k_idx_0 + rtb_Switch1_k_idx_1 *
    localDW->Delay_DSTATE;

  /* Sum: '<S157>/Sum' */
  localB->Sum = localDW->Delay_DSTATE - rtu_Speed_Meas;

  /* Logic: '<S157>/Logical Operator' incorporates:
   *  DataStoreRead: '<S157>/Data Store Read1'
   */
  rtb_AND = !*rtd_Enable;

  /* DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Constant: '<S157>/Ki2'
   */
  if (rtb_AND || (localDW->Integrator_PrevResetState != 0)) {
    localDW->Integrator_DSTATE = localP->Ki2_Value;
  }

  /* Sum: '<S206>/Sum' incorporates:
   *  DiscreteIntegrator: '<S197>/Integrator'
   *  Product: '<S202>/PProd Out'
   */
  rtb_Switch1_k_idx_0 = localB->Sum * rtu_In1 + localDW->Integrator_DSTATE;

  /* DeadZone: '<S189>/DeadZone' */
  if (rtb_Switch1_k_idx_0 > localP->DiscretePIControllerwithantiw_p) {
    rtb_Switch1_k_idx_1 = rtb_Switch1_k_idx_0 -
      localP->DiscretePIControllerwithantiw_p;
  } else if (rtb_Switch1_k_idx_0 >= localP->DiscretePIControllerwithantiwin) {
    rtb_Switch1_k_idx_1 = 0.0F;
  } else {
    rtb_Switch1_k_idx_1 = rtb_Switch1_k_idx_0 -
      localP->DiscretePIControllerwithantiwin;
  }

  /* End of DeadZone: '<S189>/DeadZone' */

  /* RelationalOperator: '<S187>/Relational Operator' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   */
  rtb_RelationalOperator_o = (localP->Clamping_zero_Value != rtb_Switch1_k_idx_1);

  /* Switch: '<S187>/Switch1' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   *  Constant: '<S187>/Constant'
   *  Constant: '<S187>/Constant2'
   *  RelationalOperator: '<S187>/fix for DT propagation issue'
   */
  if (rtb_Switch1_k_idx_1 > localP->Clamping_zero_Value) {
    rtb_Switch1_g = localP->Constant_Value;
  } else {
    rtb_Switch1_g = localP->Constant2_Value;
  }

  /* End of Switch: '<S187>/Switch1' */

  /* Product: '<S194>/IProd Out' */
  rtb_Switch1_k_idx_1 = localB->Sum * rtu_In2;

  /* Saturate: '<S204>/Saturation' */
  if (rtb_Switch1_k_idx_0 > localP->DiscretePIControllerwithantiw_p) {
    *rty_IdqRef_f = localP->DiscretePIControllerwithantiw_p;
  } else if (rtb_Switch1_k_idx_0 < localP->DiscretePIControllerwithantiwin) {
    *rty_IdqRef_f = localP->DiscretePIControllerwithantiwin;
  } else {
    *rty_IdqRef_f = rtb_Switch1_k_idx_0;
  }

  /* End of Saturate: '<S204>/Saturation' */

  /* Update for Delay: '<S217>/Delay' */
  localDW->icLoad = false;

  /* Switch: '<S187>/Switch2' incorporates:
   *  Constant: '<S187>/Clamping_zero'
   *  Constant: '<S187>/Constant3'
   *  Constant: '<S187>/Constant4'
   *  RelationalOperator: '<S187>/fix for DT propagation issue1'
   */
  if (rtb_Switch1_k_idx_1 > localP->Clamping_zero_Value) {
    tmp_0 = localP->Constant3_Value;
  } else {
    tmp_0 = localP->Constant4_Value;
  }

  /* Switch: '<S187>/Switch' incorporates:
   *  Constant: '<S187>/Constant1'
   *  Logic: '<S187>/AND3'
   *  RelationalOperator: '<S187>/Equal1'
   *  Switch: '<S187>/Switch1'
   *  Switch: '<S187>/Switch2'
   */
  if (rtb_RelationalOperator_o && (rtb_Switch1_g == tmp_0)) {
    rtb_Switch1_k_idx_1 = localP->Constant1_Value;
  }

  /* Update for DiscreteIntegrator: '<S197>/Integrator' incorporates:
   *  Switch: '<S187>/Switch'
   */
  localDW->Integrator_DSTATE += localP->Integrator_gainval * rtb_Switch1_k_idx_1;
  localDW->Integrator_PrevResetState = (int16_T)rtb_AND;
}

/* Model step function */
void testing_step(void)
{
  real_T lastSin_tmp;
  real32_T Ak[16];
  real32_T Ak_0[16];
  real32_T P[16];
  real32_T Wk[4];
  real32_T Ak_1;
  real32_T Ak_2;
  real32_T Ak_3;
  real32_T Ak_4;
  real32_T B_safe;
  real32_T rtb_RT7;
  real32_T rtb_RT8;
  int16_T b_I[16];
  int16_T y_tmp[4];
  int16_T y_tmp_0[4];
  int16_T Ak_tmp;
  int16_T Ak_tmp_0;
  int16_T i;
  int16_T i_0;
  int16_T y_tmp_1;
  int16_T y_tmp_tmp;
  static const int16_T e[4] = { 1, 0, 0, 0 };

  static const real32_T c[16] = { 5.0E-8F, 0.0F, 0.0F, 0.0F, 0.0F, 5.0E-9F, 0.0F,
    0.0F, 0.0F, 0.0F, 5.0E-9F, 0.0F, 0.0F, 0.0F, 0.0F, 5.0E-11F };

  /* DataStoreWrite: '<Root>/Data Store Write' incorporates:
   *  Constant: '<Root>/Constant1'
   */
  testing_DW.Enable = testing_P.Constant1_Value_i;

  /* RateTransition: '<Root>/RT7' */
  testing_DW.RT7_semaphoreTaken = testing_DW.RT7_ActiveBufIdx;
  rtb_RT7 = testing_DW.RT7_Buffer[testing_DW.RT7_semaphoreTaken];

  /* RateTransition: '<Root>/RT8' */
  testing_DW.RT8_semaphoreTaken = testing_DW.RT8_ActiveBufIdx;
  rtb_RT8 = testing_DW.RT8_Buffer[testing_DW.RT8_semaphoreTaken];

  /* MATLAB Function: '<Root>/MATLAB Function' incorporates:
   *  UnitDelay: '<Root>/Unit Delay'
   *  UnitDelay: '<Root>/Unit Delay1'
   */
  if (rtIsNaNF(testing_DW.UnitDelay_DSTATE[0])) {
    B_safe = (rtNaNF);
  } else if (testing_DW.UnitDelay_DSTATE[0] < 0.0F) {
    B_safe = -1.0F;
  } else {
    B_safe = (testing_DW.UnitDelay_DSTATE[0] > 0.0F);
  }

  testing_B.x[0] = ((-testing_DW.UnitDelay_DSTATE[1] *
                     testing_DW.UnitDelay_DSTATE[0] + rtb_RT8 *
                     testing_DW.UnitDelay_DSTATE[2]) -
                    testing_DW.UnitDelay_DSTATE[3] * B_safe) * 0.0005F +
    testing_DW.UnitDelay_DSTATE[0];
  testing_B.x[1] = testing_DW.UnitDelay_DSTATE[1];
  testing_B.x[2] = testing_DW.UnitDelay_DSTATE[2];
  testing_B.x[3] = testing_DW.UnitDelay_DSTATE[3];
  for (i = 0; i < 16; i++) {
    b_I[i] = 0;
  }

  b_I[0] = 1;
  b_I[5] = 1;
  b_I[10] = 1;
  b_I[15] = 1;
  Wk[0] = 0.0005F * -testing_DW.UnitDelay_DSTATE[1];
  Wk[1] = 0.0005F * -testing_DW.UnitDelay_DSTATE[0];
  Wk[2] = 0.0005F * rtb_RT8;
  if (rtIsNaNF(testing_DW.UnitDelay_DSTATE[0])) {
    B_safe = (rtNaNF);
  } else if (testing_DW.UnitDelay_DSTATE[0] < 0.0F) {
    B_safe = -1.0F;
  } else {
    B_safe = (testing_DW.UnitDelay_DSTATE[0] > 0.0F);
  }

  Wk[3] = 0.0005F * -B_safe;
  for (i = 0; i < 4; i++) {
    Ak_tmp = i << 2U;
    Ak[Ak_tmp] = (real32_T)b_I[Ak_tmp] + Wk[i];
    Ak[Ak_tmp + 1] = b_I[Ak_tmp + 1];
    Ak[Ak_tmp + 2] = b_I[Ak_tmp + 2];
    Ak[Ak_tmp + 3] = b_I[Ak_tmp + 3];
    Ak_0[Ak_tmp] = 0.0F;
    Ak_0[Ak_tmp + 1] = 0.0F;
    Ak_0[Ak_tmp + 2] = 0.0F;
    Ak_0[Ak_tmp + 3] = 0.0F;
  }

  for (i = 0; i < 4; i++) {
    Ak_tmp = i << 2U;
    Ak_1 = Ak_0[Ak_tmp];
    Ak_2 = Ak_0[Ak_tmp + 1];
    Ak_3 = Ak_0[Ak_tmp + 2];
    Ak_4 = Ak_0[Ak_tmp + 3];
    for (i_0 = 0; i_0 < 4; i_0++) {
      B_safe = testing_DW.UnitDelay1_DSTATE[Ak_tmp + i_0];
      Ak_tmp_0 = i_0 << 2U;
      Ak_1 += Ak[Ak_tmp_0] * B_safe;
      Ak_2 += Ak[Ak_tmp_0 + 1] * B_safe;
      Ak_3 += Ak[Ak_tmp_0 + 2] * B_safe;
      Ak_4 += Ak[Ak_tmp_0 + 3] * B_safe;
    }

    Ak_0[Ak_tmp + 3] = Ak_4;
    Ak_0[Ak_tmp + 2] = Ak_3;
    Ak_0[Ak_tmp + 1] = Ak_2;
    Ak_0[Ak_tmp] = Ak_1;
  }

  for (i_0 = 0; i_0 < 4; i_0++) {
    Ak_1 = Ak_0[i_0 + 4];
    Ak_2 = Ak_0[i_0];
    Ak_3 = Ak_0[i_0 + 8];
    Ak_4 = Ak_0[i_0 + 12];
    for (i = 0; i < 4; i++) {
      Ak_tmp = (i << 2U) + i_0;
      P[Ak_tmp] = (((Ak[i + 4] * Ak_1 + Ak_2 * Ak[i]) + Ak[i + 8] * Ak_3) + Ak[i
                   + 12] * Ak_4) + c[Ak_tmp];
    }

    y_tmp[i_0] = e[i_0];
    y_tmp_0[i_0] = e[i_0];
    Wk[i_0] = 0.0F;
  }

  B_safe = 0.0F;
  i_0 = y_tmp_0[0];
  Ak_tmp = y_tmp_0[1];
  Ak_tmp_0 = y_tmp_0[2];
  y_tmp_1 = y_tmp_0[3];
  for (i = 0; i < 4; i++) {
    y_tmp_tmp = i << 2U;
    Ak_1 = (((P[y_tmp_tmp] * (real32_T)i_0 + Wk[i]) + P[y_tmp_tmp + 1] *
             (real32_T)Ak_tmp) + P[y_tmp_tmp + 2] * (real32_T)Ak_tmp_0) +
      P[y_tmp_tmp + 3] * (real32_T)y_tmp_1;
    Wk[i] = Ak_1;
    B_safe += Ak_1 * (real32_T)y_tmp[i];
  }

  Ak_1 = 0.0F;
  i_0 = y_tmp[1];
  Ak_tmp = y_tmp[0];
  Ak_tmp_0 = y_tmp[2];
  y_tmp_1 = y_tmp[3];
  for (i = 0; i < 4; i++) {
    Wk[i] = (((P[i + 4] * (real32_T)i_0 + P[i] * (real32_T)Ak_tmp) + P[i + 8] *
              (real32_T)Ak_tmp_0) + P[i + 12] * (real32_T)y_tmp_1) / (B_safe +
      0.01F);
    Ak_1 += (real32_T)y_tmp_0[i] * testing_B.x[i];
  }

  B_safe = rtb_RT7 - (0.0F * rtb_RT8 + Ak_1);
  for (i = 0; i < 4; i++) {
    testing_B.x[i] += Wk[i] * B_safe;
    i_0 = y_tmp_0[i];
    Ak_tmp = i << 2U;
    Ak[Ak_tmp] = Wk[0] * (real32_T)i_0;
    Ak[Ak_tmp + 1] = Wk[1] * (real32_T)i_0;
    Ak[Ak_tmp + 2] = Wk[2] * (real32_T)i_0;
    Ak[Ak_tmp + 3] = Wk[3] * (real32_T)i_0;
  }

  for (i = 0; i < 4; i++) {
    B_safe = Ak[i + 4];
    rtb_RT7 = Ak[i];
    rtb_RT8 = Ak[i + 8];
    Ak_1 = Ak[i + 12];
    for (i_0 = 0; i_0 < 4; i_0++) {
      Ak_tmp = i_0 << 2U;
      Ak_tmp_0 = Ak_tmp + i;
      testing_DW.UnitDelay1_DSTATE[Ak_tmp_0] = P[Ak_tmp_0] - (((P[Ak_tmp + 1] *
        B_safe + P[Ak_tmp] * rtb_RT7) + P[Ak_tmp + 2] * rtb_RT8) + P[Ak_tmp + 3]
        * Ak_1);
    }
  }

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* MATLAB Function: '<Root>/MATLAB Function1' */
  if (testing_B.x[2] <= 1000.0F) {
    B_safe = testing_B.x[2];
  } else {
    B_safe = 1000.0F;
  }

  testing_B.Ks = (110.0F - testing_B.x[1]) / B_safe;
  testing_B.Kis = 3000.0F / B_safe * 0.0005F;

  /* End of MATLAB Function: '<Root>/MATLAB Function1' */

  /* Switch: '<S8>/Switch1' incorporates:
   *  Constant: '<S8>/FilterConstant'
   *  Constant: '<S8>/One'
   *  Constant: '<S8>/OneMinusFilterConstant'
   *  Constant: '<S8>/UseInputPort'
   *  Constant: '<S8>/a'
   *  Sum: '<S8>/Sum'
   */
  if (testing_P.UseInputPort_Value_f > testing_P.Switch1_Threshold_f) {
    rtb_RT7 = testing_P.a_Value_c;
    rtb_RT8 = testing_P.One_Value_o - testing_P.a_Value_c;
  } else {
    rtb_RT7 = testing_P.FilterConstant_Value_f;
    rtb_RT8 = testing_P.OneMinusFilterConstant_Value_b;
  }

  /* End of Switch: '<S8>/Switch1' */

  /* Delay: '<S152>/Delay' incorporates:
   *  Constant: '<S8>/IC'
   */
  if (testing_DW.icLoad) {
    testing_DW.Delay_DSTATE = testing_P.IC_Value_m;
  }

  /* Switch: '<S152>/Switch' incorporates:
   *  Constant: '<S8>/IC'
   *  Constant: '<S8>/Reset'
   */
  if (testing_P.Reset_Value_j) {
    B_safe = testing_P.IC_Value_m;
  } else {
    B_safe = testing_B.Ks;
  }

  /* Sum: '<S152>/Add1' incorporates:
   *  Delay: '<S152>/Delay'
   *  Product: '<S152>/Product'
   *  Product: '<S152>/Product1'
   *  Switch: '<S152>/Switch'
   */
  testing_B.Add1 = B_safe * rtb_RT7 + rtb_RT8 * testing_DW.Delay_DSTATE;

  /* Switch: '<S9>/Switch1' incorporates:
   *  Constant: '<S9>/FilterConstant'
   *  Constant: '<S9>/One'
   *  Constant: '<S9>/OneMinusFilterConstant'
   *  Constant: '<S9>/UseInputPort'
   *  Constant: '<S9>/a'
   *  Sum: '<S9>/Sum'
   */
  if (testing_P.UseInputPort_Value_n > testing_P.Switch1_Threshold_n) {
    rtb_RT7 = testing_P.a_Value_f;
    rtb_RT8 = testing_P.One_Value_n5 - testing_P.a_Value_f;
  } else {
    rtb_RT7 = testing_P.FilterConstant_Value_n;
    rtb_RT8 = testing_P.OneMinusFilterConstant_Value_k;
  }

  /* End of Switch: '<S9>/Switch1' */

  /* Delay: '<S155>/Delay' incorporates:
   *  Constant: '<S9>/IC'
   */
  if (testing_DW.icLoad_m) {
    testing_DW.Delay_DSTATE_d = testing_P.IC_Value_n;
  }

  /* Switch: '<S155>/Switch' incorporates:
   *  Constant: '<S9>/IC'
   *  Constant: '<S9>/Reset'
   */
  if (testing_P.Reset_Value_i) {
    B_safe = testing_P.IC_Value_n;
  } else {
    B_safe = testing_B.Kis;
  }

  /* Sum: '<S155>/Add1' incorporates:
   *  Delay: '<S155>/Delay'
   *  Product: '<S155>/Product'
   *  Product: '<S155>/Product1'
   *  Switch: '<S155>/Switch'
   */
  testing_B.Add1_g = B_safe * rtb_RT7 + rtb_RT8 * testing_DW.Delay_DSTATE_d;

  /* MATLAB Function: '<Root>/MATLAB Function2' */
  testing_B.trP = (testing_DW.UnitDelay1_DSTATE[5] +
                   testing_DW.UnitDelay1_DSTATE[10]) +
    testing_DW.UnitDelay1_DSTATE[15];

  /* SampleTimeMath: '<S4>/TSamp'
   *
   * About '<S4>/TSamp':
   *  y = u * K where K = 1 / ( w * Ts )
   *   */
  B_safe = testing_B.trP * testing_P.TSamp_WtEt;

  /* Abs: '<Root>/Abs' incorporates:
   *  Sum: '<S4>/Diff'
   *  UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/Diff':
   *
   *  Add in CPU
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  testing_B.abs_dP_trace = fabsf(B_safe - testing_DW.UD_DSTATE);

  /* Logic: '<Root>/AND' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S2>/Constant'
   *  RelationalOperator: '<S1>/Compare'
   *  RelationalOperator: '<S2>/Compare'
   */
  testing_B.AND = ((testing_B.abs_dP_trace < testing_P.CompareToConstant1_const)
                   && (testing_B.trP < testing_P.CompareToConstant_const));

  /* Switch: '<Root>/Switch' */
  if (testing_B.AND) {
    /* Switch: '<Root>/Switch' */
    testing_B.Switch[0] = testing_B.Add1;
    testing_B.Switch[1] = testing_B.Add1_g;
  } else {
    /* Switch: '<Root>/Switch' incorporates:
     *  UnitDelay: '<Root>/Unit Delay3'
     */
    testing_B.Switch[0] = testing_DW.UnitDelay3_DSTATE[0];
    testing_B.Switch[1] = testing_DW.UnitDelay3_DSTATE[1];
  }

  /* End of Switch: '<Root>/Switch' */
  /* Sin: '<Root>/Sine Wave' */
  if (testing_DW.systemEnable != 0L) {
    lastSin_tmp = ((testing_M->Timing.clockTick0) * 0.0005);
    testing_DW.lastSin = sin(testing_P.SineWave_Freq * lastSin_tmp);
    testing_DW.lastCos = cos(testing_P.SineWave_Freq * lastSin_tmp);
    testing_DW.systemEnable = 0L;
  }

  /* RateTransition: '<Root>/RT1' */
  testing_DW.RT1_semaphoreTaken = testing_DW.RT1_ActiveBufIdx;

  /* RateTransition: '<Root>/RT1' */
  testing_B.RT1 = testing_DW.RT1_Buffer[testing_DW.RT1_semaphoreTaken];

  /* ManualSwitch: '<Root>/Manual Switch' incorporates:
   *  Constant: '<Root>/Constant2'
   *  Sin: '<Root>/Sine Wave'
   */
  if (testing_P.ManualSwitch_CurrentSetting == 1U) {
    lastSin_tmp = ((testing_DW.lastSin * testing_P.SineWave_PCos +
                    testing_DW.lastCos * testing_P.SineWave_PSin) *
                   testing_P.SineWave_HCos + (testing_DW.lastCos *
      testing_P.SineWave_PCos - testing_DW.lastSin * testing_P.SineWave_PSin) *
                   testing_P.SineWave_Hsin) * testing_P.SineWave_Amp +
      testing_P.SineWave_Bias;
  } else {
    lastSin_tmp = testing_P.Constant2_Value;
  }

  /* Outputs for Atomic SubSystem: '<Root>/Speed Control' */
  /* DataTypeConversion: '<Root>/Data Type Conversion' incorporates:
   *  ManualSwitch: '<Root>/Manual Switch'
   */
  testing_SpeedControl((real32_T)lastSin_tmp, testing_B.RT1, testing_B.Switch[0],
                       testing_B.Switch[1], &rtb_RT7, &rtb_RT8,
                       &testing_DW.EnClosedLoop, &testing_DW.Enable,
                       &testing_B.SpeedControl, &testing_DW.SpeedControl,
                       &testing_P.SpeedControl);

  /* End of Outputs for SubSystem: '<Root>/Speed Control' */
  if (testing_M->Timing.TaskCounters.TID[1] == 0) {
    /* Outputs for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* S-Function (c280xgpio_do): '<S149>/Digital Output' incorporates:
     *  Constant: '<S7>/RED_LED'
     */
    {
      GpioDataRegs.GPBTOGGLE.bit.GPIO34 = (uint16_T)(testing_P.RED_LED_Value !=
        0);
    }

    /* End of Outputs for SubSystem: '<Root>/Heartbeat LED' */
  }

  /* Update for UnitDelay: '<Root>/Unit Delay' */
  testing_DW.UnitDelay_DSTATE[0] = testing_B.x[0];
  testing_DW.UnitDelay_DSTATE[1] = testing_B.x[1];
  testing_DW.UnitDelay_DSTATE[2] = testing_B.x[2];
  testing_DW.UnitDelay_DSTATE[3] = testing_B.x[3];

  /* Update for RateTransition: '<Root>/RT2' */
  testing_DW.RT2_Buffer[(testing_DW.RT2_ActiveBufIdx == 0) << 1U] = rtb_RT7;
  testing_DW.RT2_Buffer[1 + ((testing_DW.RT2_ActiveBufIdx == 0) << 1U)] =
    rtb_RT8;
  testing_DW.RT2_ActiveBufIdx = (testing_DW.RT2_ActiveBufIdx == 0);

  /* Update for Delay: '<S152>/Delay' */
  testing_DW.icLoad = false;
  testing_DW.Delay_DSTATE = testing_B.Add1;

  /* Update for Delay: '<S155>/Delay' */
  testing_DW.icLoad_m = false;
  testing_DW.Delay_DSTATE_d = testing_B.Add1_g;

  /* Update for UnitDelay: '<S4>/UD'
   *
   * Block description for '<S4>/UD':
   *
   *  Store in Global RAM
   */
  testing_DW.UD_DSTATE = B_safe;

  /* Update for UnitDelay: '<Root>/Unit Delay3' */
  testing_DW.UnitDelay3_DSTATE[0] = testing_B.Switch[0];
  testing_DW.UnitDelay3_DSTATE[1] = testing_B.Switch[1];

  /* Update for Sin: '<Root>/Sine Wave' */
  lastSin_tmp = testing_DW.lastSin;
  testing_DW.lastSin = testing_DW.lastSin * testing_P.SineWave_HCos +
    testing_DW.lastCos * testing_P.SineWave_Hsin;
  testing_DW.lastCos = testing_DW.lastCos * testing_P.SineWave_HCos -
    lastSin_tmp * testing_P.SineWave_Hsin;

  {                                    /* Sample time: [0.0005s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((testing_M->Timing.clockTick0 * 1) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(0, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  if (testing_M->Timing.TaskCounters.TID[1] == 0) {/* Sample time: [2.0s, 0.0s] */
    extmodeErrorCode_T errorCode = EXTMODE_SUCCESS;
    extmodeSimulationTime_T extmodeTime = (extmodeSimulationTime_T)
      ((testing_M->Timing.clockTick1 * 4000) + 0);

    /* Trigger External Mode event */
    errorCode = extmodeEvent(1, extmodeTime);
    if (errorCode != EXTMODE_SUCCESS) {
      /* Code to handle External Mode event errors
         may be added here */
    }
  }

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The resolution of this integer timer is 0.0005, which is the step size
   * of the task. Size of "clockTick0" ensures timer will not overflow during the
   * application lifespan selected.
   */
  testing_M->Timing.clockTick0++;
  if (testing_M->Timing.TaskCounters.TID[1] == 0) {
    /* Update absolute timer for sample time: [2.0s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The resolution of this integer timer is 2.0, which is the step size
     * of the task. Size of "clockTick1" ensures timer will not overflow during the
     * application lifespan selected.
     */
    testing_M->Timing.clockTick1++;
  }

  switch (testing_M->Timing.rtmDbBufReadBuf3) {
   case 0:
    testing_M->Timing.rtmDbBufWriteBuf3 = 1;
    break;

   case 1:
    testing_M->Timing.rtmDbBufWriteBuf3 = 0;
    break;

   default:
    testing_M->Timing.rtmDbBufWriteBuf3 = !testing_M->Timing.rtmDbBufLastBufWr3;
    break;
  }

  testing_M->Timing.rtmDbBufClockTick3[testing_M->Timing.rtmDbBufWriteBuf3] =
    testing_M->Timing.clockTick0;
  testing_M->Timing.rtmDbBufLastBufWr3 = testing_M->Timing.rtmDbBufWriteBuf3;
  testing_M->Timing.rtmDbBufWriteBuf3 = 0xFF;

  {
    /* Base rate updates double buffers of absolute time for
       asynchronous task. Double buffers are used to ensure
       data integrity when asynchronous task reads absolute
       time.
       -- rtmL2HLastBufWr is the buffer index that is written last.
     */
    boolean_T bufIdx = !(testing_M->Timing.rtmL2HLastBufWr != 0U);
    testing_M->Timing.rtmL2HDbBufClockTick[bufIdx] =
      testing_M->Timing.clockTick0;
    testing_M->Timing.rtmL2HLastBufWr = bufIdx ? 1U : 0U;
  }

  rate_scheduler();
}

/* Model initialize function */
void testing_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)testing_M, 0,
                sizeof(RT_MODEL_testing_T));
  rtmSetTFinal(testing_M, -1);

  /* External mode info */
  testing_M->Sizes.checksums[0] = (3113599311U);
  testing_M->Sizes.checksums[1] = (1412393645U);
  testing_M->Sizes.checksums[2] = (3936621295U);
  testing_M->Sizes.checksums[3] = (699280530U);

  {
    static const sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE;
    static RTWExtModeInfo rt_ExtModeInfo;
    static const sysRanDType *systemRan[80];
    testing_M->extModeInfo = (&rt_ExtModeInfo);
    rteiSetSubSystemActiveVectorAddresses(&rt_ExtModeInfo, systemRan);
    systemRan[0] = &rtAlwaysEnabled;
    systemRan[1] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[2] = (sysRanDType *)&testing_DW.DorQAxisPriority_SubsysRanBC;
    systemRan[3] = (sysRanDType *)&testing_DW.limitRef2_SubsysRanBC;
    systemRan[4] = (sysRanDType *)&testing_DW.limitRef2_SubsysRanBC;
    systemRan[5] = (sysRanDType *)&testing_DW.limitRef2_SubsysRanBC;
    systemRan[6] = (sysRanDType *)&testing_DW.passThrough_SubsysRanBC;
    systemRan[7] = (sysRanDType *)&testing_DW.DorQAxisPriority_SubsysRanBC;
    systemRan[8] = (sysRanDType *)&testing_DW.Limiter_SubsysRanBC;
    systemRan[9] = (sysRanDType *)&testing_DW.Limiter_SubsysRanBC;
    systemRan[10] = (sysRanDType *)&testing_DW.Passthrough_SubsysRanBC;
    systemRan[11] = (sysRanDType *)&testing_DW.DQEquivalence_SubsysRanBC;
    systemRan[12] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[13] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[14] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[15] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[16] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[17] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[18] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[19] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[20] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[21] = (sysRanDType *)
      &testing_DW.IfActionSubsystem_o.IfActionSubsystem_SubsysRanBC;
    systemRan[22] = (sysRanDType *)
      &testing_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC;
    systemRan[23] = (sysRanDType *)&testing_DW.ClosedLoopControl_SubsysRanBC;
    systemRan[24] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[25] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[26] = (sysRanDType *)
      &testing_DW.IfActionSubsystem_b.IfActionSubsystem_SubsysRanBC;
    systemRan[27] = (sysRanDType *)
      &testing_DW.IfActionSubsystem1_ju.IfActionSubsystem1_SubsysRanBC;
    systemRan[28] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[29] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[30] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[31] = (sysRanDType *)&testing_DW.OpenLoopStartUp_SubsysRanBC;
    systemRan[32] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[33] = (sysRanDType *)&testing_DW.CalculatePosition_SubsysRanBC;
    systemRan[34] = (sysRanDType *)&testing_DW.CalculatePosition_SubsysRanBC;
    systemRan[35] = (sysRanDType *)&testing_DW.CalculatePosition_SubsysRanBC;
    systemRan[36] = (sysRanDType *)&testing_DW.CalculatePosition_SubsysRanBC;
    systemRan[37] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[38] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[39] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[40] = (sysRanDType *)&testing_DW.IndexFinder_SubsysRanBC;
    systemRan[41] = (sysRanDType *)&testing_DW.IfActionSubsystem_SubsysRanBC_a;
    systemRan[42] = (sysRanDType *)&testing_DW.IfActionSubsystem1_SubsysRanB_i;
    systemRan[43] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[44] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[45] = (sysRanDType *)&testing_DW.PositionNoReset_SubsysRanBC;
    systemRan[46] = (sysRanDType *)&testing_DW.PositionResetAtIndex_SubsysRanB;
    systemRan[47] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[48] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[49] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[50] = (sysRanDType *)&testing_DW.CurrentControl_SubsysRanBC;
    systemRan[51] = (sysRanDType *)&testing_DW.IfActionSubsystem_SubsysRanBC_g;
    systemRan[52] = (sysRanDType *)&testing_DW.CalculateADCOffset_SubsysRanBC;
    systemRan[53] = (sysRanDType *)&testing_DW.IfActionSubsystem_SubsysRanBC;
    systemRan[54] = (sysRanDType *)&testing_DW.IfActionSubsystem1_SubsysRanBC;
    systemRan[55] = (sysRanDType *)&testing_DW.IfActionSubsystem2_SubsysRanBC;
    systemRan[56] = (sysRanDType *)&testing_DW.IfActionSubsystem3_SubsysRanBC;
    systemRan[57] = (sysRanDType *)&testing_DW.CalculateADCOffset_SubsysRanBC;
    systemRan[58] = (sysRanDType *)&testing_DW.ADCGainSetting_SubsysRanBC;
    systemRan[59] = (sysRanDType *)&testing_DW.ADCGainSetting_SubsysRanBC;
    systemRan[60] = (sysRanDType *)&testing_DW.ADCGainSetting_SubsysRanBC;
    systemRan[61] = (sysRanDType *)&testing_DW.DefaultADCOffset_SubsysRanBC;
    systemRan[62] = &rtAlwaysEnabled;
    systemRan[63] = &rtAlwaysEnabled;
    systemRan[64] = &rtAlwaysEnabled;
    systemRan[65] = &rtAlwaysEnabled;
    systemRan[66] = &rtAlwaysEnabled;
    systemRan[67] = &rtAlwaysEnabled;
    systemRan[68] = &rtAlwaysEnabled;
    systemRan[69] = &rtAlwaysEnabled;
    systemRan[70] = &rtAlwaysEnabled;
    systemRan[71] = &rtAlwaysEnabled;
    systemRan[72] = &rtAlwaysEnabled;
    systemRan[73] = &rtAlwaysEnabled;
    systemRan[74] = &rtAlwaysEnabled;
    systemRan[75] = &rtAlwaysEnabled;
    systemRan[76] = &rtAlwaysEnabled;
    systemRan[77] = &rtAlwaysEnabled;
    systemRan[78] = &rtAlwaysEnabled;
    systemRan[79] = &rtAlwaysEnabled;
    rteiSetModelMappingInfoPtr(testing_M->extModeInfo,
      &testing_M->SpecialInfo.mappingInfo);
    rteiSetChecksumsPtr(testing_M->extModeInfo, testing_M->Sizes.checksums);
    rteiSetTFinalTicks(testing_M->extModeInfo, -1);
  }

  /* block I/O */
  (void) memset(((void *) &testing_B), 0,
                sizeof(B_testing_T));

  /* states (dwork) */
  (void) memset((void *)&testing_DW, 0,
                sizeof(DW_testing_T));

  {
    real_T tmp;
    int16_T i;
    uint16_T Memory1_PreviousInput;
    uint16_T Memory_PreviousInput;
    uint16_T Sum1_a;
    uint16_T Sum_h;
    uint16_T s141_iter;
    testing_M->Timing.rtmDbBufReadBuf3 = 0xFF;
    testing_M->Timing.rtmDbBufWriteBuf3 = 0xFF;
    testing_M->Timing.rtmDbBufLastBufWr3 = 0;

    /* Start for Product: '<S138>/Divide' incorporates:
     *  DataStoreMemory: '<Root>/Data Store Memory1'
     */
    testing_DW.IaOffset = testing_P.DataStoreMemory1_InitialValue;

    /* Start for Product: '<S138>/Divide1' incorporates:
     *  DataStoreMemory: '<Root>/Data Store Memory2'
     */
    testing_DW.IbOffset = testing_P.DataStoreMemory2_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory29' */
    testing_DW.Enable = testing_P.DataStoreMemory29_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory3' */
    testing_DW.EnClosedLoop = testing_P.DataStoreMemory3_InitialValue;

    /* Start for DataStoreMemory: '<Root>/Data Store Memory4' */
    testing_DW.Speed_ref = testing_P.DataStoreMemory4_InitialValue;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay' */
    testing_DW.UnitDelay_DSTATE[0] = testing_P.UnitDelay_InitialCondition[0];
    testing_DW.UnitDelay_DSTATE[1] = testing_P.UnitDelay_InitialCondition[1];
    testing_DW.UnitDelay_DSTATE[2] = testing_P.UnitDelay_InitialCondition[2];
    testing_DW.UnitDelay_DSTATE[3] = testing_P.UnitDelay_InitialCondition[3];

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */
    for (i = 0; i < 16; i++) {
      testing_DW.UnitDelay1_DSTATE[i] = testing_P.UnitDelay1_InitialCondition[i];
    }

    /* End of InitializeConditions for UnitDelay: '<Root>/Unit Delay1' */

    /* InitializeConditions for RateTransition: '<Root>/RT2' */
    testing_DW.RT2_Buffer[0] = testing_P.RT2_InitialCondition;
    testing_DW.RT2_Buffer[1] = testing_P.RT2_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT7' */
    testing_DW.RT7_Buffer[0] = testing_P.RT7_InitialCondition;

    /* InitializeConditions for RateTransition: '<Root>/RT8' */
    testing_DW.RT8_Buffer[0] = testing_P.RT8_InitialCondition;

    /* InitializeConditions for Delay: '<S152>/Delay' */
    testing_DW.icLoad = true;

    /* InitializeConditions for Delay: '<S155>/Delay' */
    testing_DW.icLoad_m = true;

    /* InitializeConditions for UnitDelay: '<S4>/UD'
     *
     * Block description for '<S4>/UD':
     *
     *  Store in Global RAM
     */
    testing_DW.UD_DSTATE = testing_P.DiscreteDerivative_ICPrevScaled;

    /* InitializeConditions for UnitDelay: '<Root>/Unit Delay3' */
    testing_DW.UnitDelay3_DSTATE[0] = testing_P.UnitDelay3_InitialCondition[0];
    testing_DW.UnitDelay3_DSTATE[1] = testing_P.UnitDelay3_InitialCondition[1];

    /* InitializeConditions for RateTransition: '<Root>/RT1' */
    testing_DW.RT1_Buffer[0] = testing_P.RT1_InitialCondition;

    /* SystemInitialize for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' incorporates:
     *  SubSystem: '<Root>/Current Control'
     */
    testing_CurrentControl_Init();

    /* SystemInitialize for Atomic SubSystem: '<Root>/Speed Control' */
    testing_SpeedControl_Init(&testing_DW.SpeedControl, &testing_P.SpeedControl);

    /* End of SystemInitialize for SubSystem: '<Root>/Speed Control' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Heartbeat LED' */
    /* Start for S-Function (c280xgpio_do): '<S149>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPBMUX1.all &= 0xFFFFFFCFU;
    GpioCtrlRegs.GPBDIR.all |= 0x4U;
    EDIS;

    /* End of SystemInitialize for SubSystem: '<Root>/Heartbeat LED' */

    /* SystemInitialize for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Start for S-Function (c280xgpio_do): '<S139>/Digital Output' */
    EALLOW;
    GpioCtrlRegs.GPDMUX2.all &= 0xFCFFFFFFU;
    GpioCtrlRegs.GPDDIR.all |= 0x10000000U;
    EDIS;

    /* Start for S-Function (c280xgpio_do): '<S139>/Digital Output1' */
    EALLOW;
    GpioCtrlRegs.GPAMUX2.all &= 0xFFFFCFFFU;
    GpioCtrlRegs.GPADIR.all |= 0x400000U;
    EDIS;
    testing_SPIMasterTransfer_Init(&testing_DW.SPIMasterTransfer);
    testing_SPIMasterTransfer_Init(&testing_DW.SPIMasterTransfer1);

    /* End of SystemInitialize for SubSystem: '<S139>/ADC Gain Setting' */

    /* SystemInitialize for IfAction SubSystem: '<S141>/If Action Subsystem' */
    /* InitializeConditions for Memory: '<S146>/Memory' */
    Memory_PreviousInput = testing_P.Memory_InitialCondition;

    /* InitializeConditions for Memory: '<S146>/Memory1' */
    Memory1_PreviousInput = testing_P.Memory1_InitialCondition;

    /* SystemInitialize for Sum: '<S146>/Sum' incorporates:
     *  Outport: '<S146>/Out1'
     */
    Sum_h = testing_P.Out1_Y0;

    /* SystemInitialize for Sum: '<S146>/Sum1' incorporates:
     *  Outport: '<S146>/Out2'
     */
    Sum1_a = testing_P.Out2_Y0;

    /* End of SystemInitialize for SubSystem: '<S141>/If Action Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S138>/For Iterator Subsystem' */
    /* End of SystemInitialize for SubSystem: '<S137>/Calculate ADC Offset ' */
    /* End of SystemInitialize for SubSystem: '<Root>/Hardware Init' */
    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.IfActionSubsystem_SubsysRanBC_g);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.IfActionSubsystem_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.IfActionSubsystem1_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.IfActionSubsystem2_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.IfActionSubsystem3_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.CalculateADCOffset_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.ADCGainSetting_SubsysRanBC);

    /* Reset subsysRan breadcrumbs */
    srClearBC(testing_DW.DefaultADCOffset_SubsysRanBC);

    /* Outputs for Atomic SubSystem: '<Root>/Hardware Init' */
    /* Outputs for Enabled SubSystem: '<S139>/ADC Gain Setting' incorporates:
     *  EnablePort: '<S147>/Enable'
     */
    /* Constant: '<S139>/Constant' */
    if (testing_P.Constant_Value_b > 0.0) {
      /* Constant: '<S6>/6PWM_Mode' */
      testing_SPIMasterTransfer(testing_P.uPWM_Mode_Value,
        &testing_B.SPIMasterTransfer, &testing_DW.SPIMasterTransfer);

      /* Constant: '<S6>/ADC_Gain_Setting' */
      testing_SPIMasterTransfer(testing_P.ADC_Gain_Setting_Value,
        &testing_B.SPIMasterTransfer1, &testing_DW.SPIMasterTransfer1);
      srUpdateBC(testing_DW.ADCGainSetting_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S139>/ADC Gain Setting' */

    /* Switch: '<S139>/Switch' incorporates:
     *  Constant: '<S139>/Constant'
     */
    if (testing_P.Constant_Value_b > testing_P.Switch_Threshold_f) {
      /* Switch: '<S139>/Switch' incorporates:
       *  Constant: '<S139>/DRV830x Enable'
       */
      testing_B.Switch_o = testing_P.DRV830xEnable_Value;
    } else {
      /* Switch: '<S139>/Switch' incorporates:
       *  Constant: '<S139>/DRV830x Enable'
       *  Logic: '<S139>/NOT'
       */
      testing_B.Switch_o = (uint16_T)(testing_P.DRV830xEnable_Value == 0U);
    }

    /* End of Switch: '<S139>/Switch' */

    /* S-Function (c280xgpio_do): '<S139>/Digital Output' */
    {
      if (testing_B.Switch_o) {
        GpioDataRegs.GPDSET.bit.GPIO124 = 1U;
      } else {
        GpioDataRegs.GPDCLEAR.bit.GPIO124 = 1U;
      }
    }

    /* S-Function (c280xgpio_do): '<S139>/Digital Output1' incorporates:
     *  Constant: '<S139>/RunTimeMeasurement'
     */
    {
      if (testing_P.RunTimeMeasurement_Value) {
        GpioDataRegs.GPASET.bit.GPIO22 = 1U;
      } else {
        GpioDataRegs.GPACLEAR.bit.GPIO22 = 1U;
      }
    }

    /* Outputs for Enabled SubSystem: '<S137>/Calculate ADC Offset ' incorporates:
     *  EnablePort: '<S138>/Enable'
     */
    /* Constant: '<S137>/ADC Calibration Enable' */
    if (testing_P.ADCCalibrationEnable_Value > 0.0) {
      /* Outputs for Iterator SubSystem: '<S138>/For Iterator Subsystem' incorporates:
       *  ForIterator: '<S141>/For Iterator'
       */
      for (s141_iter = 1U; s141_iter <= testing_P.ForIterator_IterationLimit;
           s141_iter++) {
        /* S-Function (c2802xadc): '<S141>/ADC_A_IN0' */
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

          testing_B.ADC_A_IN0 = (AdccResultRegs.ADCRESULT2);
        }

        /* S-Function (c2802xadc): '<S141>/ADC_B_IN0' */
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

          testing_B.ADC_B_IN0 = (AdcbResultRegs.ADCRESULT2);
        }

        /* If: '<S141>/If' */
        if (s141_iter > 8U) {
          /* Outputs for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          /* Sum: '<S146>/Sum' incorporates:
           *  Memory: '<S146>/Memory'
           */
          Sum_h = testing_B.ADC_A_IN0 + Memory_PreviousInput;

          /* Sum: '<S146>/Sum1' incorporates:
           *  Memory: '<S146>/Memory1'
           */
          Sum1_a = testing_B.ADC_B_IN0 + Memory1_PreviousInput;

          /* Update for Memory: '<S146>/Memory' */
          Memory_PreviousInput = Sum_h;

          /* Update for Memory: '<S146>/Memory1' */
          Memory1_PreviousInput = Sum1_a;

          /* End of Outputs for SubSystem: '<S141>/If Action Subsystem' */

          /* Update for IfAction SubSystem: '<S141>/If Action Subsystem' incorporates:
           *  ActionPort: '<S146>/Action Port'
           */
          /* Update for If: '<S141>/If' */
          srUpdateBC(testing_DW.IfActionSubsystem_SubsysRanBC_g);

          /* End of Update for SubSystem: '<S141>/If Action Subsystem' */
        }

        /* End of If: '<S141>/If' */
      }

      /* End of Outputs for SubSystem: '<S138>/For Iterator Subsystem' */

      /* Product: '<S138>/Divide' incorporates:
       *  Constant: '<S138>/Constant'
       */
      tmp = floor((real_T)Sum_h / testing_P.Constant_Value_l);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 65536.0);
      }

      /* Product: '<S138>/Divide' */
      testing_DW.IaOffset = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp :
        (uint16_T)tmp;

      /* If: '<S138>/If' incorporates:
       *  Constant: '<S138>/Constant1'
       *  Constant: '<S138>/Constant2'
       */
      if ((testing_DW.IaOffset > testing_P.Constant2_Value_k) &&
          (testing_DW.IaOffset < testing_P.Constant1_Value_j)) {
        /* Update for IfAction SubSystem: '<S138>/If Action Subsystem' incorporates:
         *  ActionPort: '<S142>/Action Port'
         */
        /* Update for If: '<S138>/If' */
        srUpdateBC(testing_DW.IfActionSubsystem_SubsysRanBC);

        /* End of Update for SubSystem: '<S138>/If Action Subsystem' */
      } else {
        /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Product: '<S138>/Divide' incorporates:
         *  Constant: '<S143>/Constant'
         *  DataStoreWrite: '<S143>/Data Store Write1'
         */
        testing_DW.IaOffset = testing_P.Constant_Value_hg;

        /* End of Outputs for SubSystem: '<S138>/If Action Subsystem1' */

        /* Update for IfAction SubSystem: '<S138>/If Action Subsystem1' incorporates:
         *  ActionPort: '<S143>/Action Port'
         */
        /* Update for If: '<S138>/If' */
        srUpdateBC(testing_DW.IfActionSubsystem1_SubsysRanBC);

        /* End of Update for SubSystem: '<S138>/If Action Subsystem1' */
      }

      /* End of If: '<S138>/If' */

      /* Product: '<S138>/Divide1' incorporates:
       *  Constant: '<S138>/Constant'
       */
      tmp = floor((real_T)Sum1_a / testing_P.Constant_Value_l);
      if (rtIsNaN(tmp) || rtIsInf(tmp)) {
        tmp = 0.0;
      } else {
        tmp = fmod(tmp, 65536.0);
      }

      /* Product: '<S138>/Divide1' */
      testing_DW.IbOffset = tmp < 0.0 ? (uint16_T)-(int16_T)(uint16_T)-tmp :
        (uint16_T)tmp;

      /* If: '<S138>/If1' incorporates:
       *  Constant: '<S138>/Constant1'
       *  Constant: '<S138>/Constant2'
       */
      if ((testing_DW.IbOffset > testing_P.Constant2_Value_k) &&
          (testing_DW.IbOffset < testing_P.Constant1_Value_j)) {
        /* Update for IfAction SubSystem: '<S138>/If Action Subsystem2' incorporates:
         *  ActionPort: '<S144>/Action Port'
         */
        /* Update for If: '<S138>/If1' */
        srUpdateBC(testing_DW.IfActionSubsystem2_SubsysRanBC);

        /* End of Update for SubSystem: '<S138>/If Action Subsystem2' */
      } else {
        /* Outputs for IfAction SubSystem: '<S138>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S145>/Action Port'
         */
        /* Product: '<S138>/Divide1' incorporates:
         *  Constant: '<S145>/Constant1'
         *  DataStoreWrite: '<S145>/Data Store Write2'
         */
        testing_DW.IbOffset = testing_P.Constant1_Value_k;

        /* End of Outputs for SubSystem: '<S138>/If Action Subsystem3' */

        /* Update for IfAction SubSystem: '<S138>/If Action Subsystem3' incorporates:
         *  ActionPort: '<S145>/Action Port'
         */
        /* Update for If: '<S138>/If1' */
        srUpdateBC(testing_DW.IfActionSubsystem3_SubsysRanBC);

        /* End of Update for SubSystem: '<S138>/If Action Subsystem3' */
      }

      /* End of If: '<S138>/If1' */
      srUpdateBC(testing_DW.CalculateADCOffset_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S137>/Calculate ADC Offset ' */

    /* Outputs for Enabled SubSystem: '<S137>/Default ADC Offset' incorporates:
     *  EnablePort: '<S140>/Enable'
     */
    /* Logic: '<S137>/NOT' incorporates:
     *  Constant: '<S137>/ADC Calibration Enable'
     */
    if (!(testing_P.ADCCalibrationEnable_Value != 0.0)) {
      /* Product: '<S138>/Divide' incorporates:
       *  Constant: '<S140>/Constant'
       *  DataStoreWrite: '<S140>/Data Store Write1'
       */
      testing_DW.IaOffset = testing_P.Constant_Value_k;

      /* Product: '<S138>/Divide1' incorporates:
       *  Constant: '<S140>/Constant1'
       *  DataStoreWrite: '<S140>/Data Store Write2'
       */
      testing_DW.IbOffset = testing_P.Constant1_Value_h;
      srUpdateBC(testing_DW.DefaultADCOffset_SubsysRanBC);
    }

    /* End of Logic: '<S137>/NOT' */
    /* End of Outputs for SubSystem: '<S137>/Default ADC Offset' */
    /* End of Outputs for SubSystem: '<Root>/Hardware Init' */
    /* Enable for Sin: '<Root>/Sine Wave' */
    testing_DW.systemEnable = 1L;
  }
}

/* Model terminate function */
void testing_terminate(void)
{
  /* Terminate for Atomic SubSystem: '<Root>/Hardware Init' */
  /* Terminate for Enabled SubSystem: '<S139>/ADC Gain Setting' */
  testing_SPIMasterTransfer_Term(&testing_DW.SPIMasterTransfer);
  testing_SPIMasterTransfer_Term(&testing_DW.SPIMasterTransfer1);
}

void testing_configure_interrupts(void)
{
  /* Register interrupt service routine */
  HWI_TIC28x_ConfigureIRQ(33,&ADCB1_INT,0);
  HWI_TIC28x_EnableIRQ(33);
}

/* Hardware Interrupt Block: '<S135>/Hardware Interrupt' */
interrupt void ADCB1_INT(void)
{
  volatile unsigned int PIEIER1_stack_save = PieCtrlRegs.PIEIER1.all;
  PieCtrlRegs.PIEIER1.all &= ~66;
                              /*disable group1 lower/equal priority interrupts*/
  asm(" RPT #5 || NOP");               /*wait 5 cycles        */
  IFR &= ~1;      /*eventually disable lower/equal priority pending interrupts*/
  PieCtrlRegs.PIEACK.all = 1;
                   /*ACK to allow other interrupts from the same group to fire*/
  IER |= 1;
  EINT;

  /* Event: Default Event */
  if (1 == runModel) {
    {
      int16_T tmp;

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.passThrough_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.limitRef2_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.DorQAxisPriority_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.Limiter_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.Passthrough_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.DQEquivalence_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.IfActionSubsystem_o.IfActionSubsystem_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.IfActionSubsystem1_j.IfActionSubsystem1_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.ClosedLoopControl_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.OpenLoopStartUp_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.CalculatePosition_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.IndexFinder_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.IfActionSubsystem_SubsysRanBC_a);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.IfActionSubsystem1_SubsysRanB_i);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.PositionNoReset_SubsysRanBC);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.PositionResetAtIndex_SubsysRanB);

      /* Reset subsysRan breadcrumbs */
      srClearBC(testing_DW.CurrentControl_SubsysRanBC);

      /* RateTransition: '<Root>/RT2' */
      tmp = testing_DW.RT2_ActiveBufIdx << 1U;
      testing_B.RT2[0] = testing_DW.RT2_Buffer[tmp];
      testing_B.RT2[1] = testing_DW.RT2_Buffer[tmp + 1];

      /* S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */
      testing_CurrentControl();

      /* End of Outputs for S-Function (HardwareInterrupt_sfun): '<S135>/Hardware Interrupt' */

      /* RateTransition: '<Root>/RT7' */
      testing_DW.RT7_Buffer[testing_DW.RT7_semaphoreTaken == 0] =
        testing_B.Add1_f;
      testing_DW.RT7_ActiveBufIdx = (testing_DW.RT7_semaphoreTaken == 0);

      /* RateTransition: '<Root>/RT8' */
      testing_DW.RT8_Buffer[testing_DW.RT8_semaphoreTaken == 0] =
        testing_B.OutportBufferForIq_measure;
      testing_DW.RT8_ActiveBufIdx = (testing_DW.RT8_semaphoreTaken == 0);

      /* RateTransition: '<Root>/RT1' */
      testing_DW.RT1_Buffer[testing_DW.RT1_semaphoreTaken == 0] =
        testing_B.Add1_f;
      testing_DW.RT1_ActiveBufIdx = (testing_DW.RT1_semaphoreTaken == 0);
    }

    currentTime = (extmodeSimulationTime_T) testing_M->Timing.clockTick0;
    extmodeEvent(2,currentTime);
  }

  /* Clear occurred EOC event event */
  AdcbRegs.ADCINTFLGCLR.bit.ADCINT1= 1;

  /* Clear occurred Overflow event event */
  AdcbRegs.ADCINTOVFCLR.bit.ADCINT1= 1;
  DINT;
  /* disable global interrupts during context switch, CPU will enable global interrupts after exiting ISR */
  PieCtrlRegs.PIEIER1.all = PIEIER1_stack_save;
                                   /*restore PIEIER register that was modified*/
  HWI_TIC28x_AcknowledgeIrq(33);
}

void testing_unconfigure_interrupts (void)
{
  HWI_TIC28x_DisableIRQ(33);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
