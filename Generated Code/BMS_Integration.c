/*
 * File: BMS_Integration.c
 *
 * Code generated for Simulink model 'BMS_Integration'.
 *
 * Model version                  : 1.44
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec 29 13:56:41 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "BMS_Integration.h"
000
/* Block signals and states (default storage) */
BMS_Integration_DW BMS_Integration_DW_l;

/* External inputs (root inport signals with default storage) */
BMS_Integration_ExtU BMS_Integration_U;

/* External outputs (root outports fed by signals with default storage) */
BMS_Integration_ExtY BMS_Integration_Y;

/* Real-time model */
BMS_Integration_RT_MODEL BMS_Integration_M_;
BMS_Integration_RT_MODEL *const BMS_Integration_M = &BMS_Integration_M_;
static void rate_scheduler(void);

/*
 *   This function updates active task flag for each subrate.
 * The function is called at model base rate, hence the
 * generated code self-manages all its subrates.
 */
static void rate_scheduler(void)
{
  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (BMS_Integration_M->Timing.TaskCounters.TID[1])++;
  if ((BMS_Integration_M->Timing.TaskCounters.TID[1]) > 9) {/* Sample time: [0.01s, 0.0s] */
    BMS_Integration_M->Timing.TaskCounters.TID[1] = 0;
  }
}

/* Model step function */
void bbb_step(void)
{
  int8_T rtPrevAction;
  int8_T rtAction;
  if (BMS_Integration_M->Timing.TaskCounters.TID[1] == 0) {
    /* S-Function (fcncallgen): '<Root>/Function-Call Generator1' */
    /* ModelReference: '<Root>/Model' incorporates:
     *  Inport: '<Root>/CapFade_abs'
     *  Inport: '<Root>/Icur_mA'
     *  Inport: '<Root>/Temp_degC'
     */
    Model1_Model1_main(&BMS_Integration_U.Temp_degC, &BMS_Integration_U.Icur_mA,
                       &BMS_Integration_U.CapFade_abs,
                       &BMS_Integration_DW_l.soc_perc,
                       &BMS_Integration_DW_l.Vp_mV, &BMS_Integration_DW_l.Vlt_mV);

    /* End of Outputs for S-Function (fcncallgen): '<Root>/Function-Call Generator1' */

    /* If: '<Root>/If' incorporates:
     *  Constant: '<Root>/Constant'
     *  Inport: '<Root>/schedule_flag'
     *  Inport: '<S2>/In1'
     */
    rtPrevAction = BMS_Integration_DW_l.If_ActiveSubsystem;
    rtAction = (int8_T)!(BMS_Integration_U.schedule_flag > 0.0F);
    BMS_Integration_DW_l.If_ActiveSubsystem = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    }

    if (rtAction == 0) {
      if (rtAction != rtPrevAction) {
      }

      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem' incorporates:
       *  ActionPort: '<S1>/Action Port'
       */
      /* S-Function (fcncallgen): '<S1>/Function-Call Generator' */
      /* ModelReference: '<Root>/Model1' incorporates:
       *  Inport: '<Root>/Temp_degC'
       */
      Model2_Model2_main(&BMS_Integration_DW_l.soc_perc,
                         &BMS_Integration_DW_l.Rp_mohm,
                         &BMS_Integration_DW_l.Vlt_mV,
                         &BMS_Integration_U.Temp_degC, &BMS_Integration_DW_l.soh);

      /* End of Outputs for S-Function (fcncallgen): '<S1>/Function-Call Generator' */
      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<Root>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S2>/Action Port'
       */
      BMS_Integration_DW_l.soh = 1.0F;

      /* End of Outputs for SubSystem: '<Root>/If Action Subsystem1' */
    }

    /* End of If: '<Root>/If' */

    /* Outport: '<Root>/soh' */
    BMS_Integration_Y.soh = BMS_Integration_DW_l.soh;

    /* Outport: '<Root>/Vp_mV' */
    BMS_Integration_Y.Vp_mV = BMS_Integration_DW_l.Vp_mV;
  }

  rate_scheduler();
}

/* Model initialize function */
void bbb_initialize(void)
{
  /* Start for If: '<Root>/If' */
  BMS_Integration_DW_l.If_ActiveSubsystem = -1;

  /* SystemInitialize for ModelReference: '<Root>/Model' incorporates:
   *  Inport: '<Root>/CapFade_abs'
   *  Inport: '<Root>/Icur_mA'
   *  Inport: '<Root>/Temp_degC'
   */
  Model1_Init(&BMS_Integration_DW_l.Rp_mohm);

  /* SystemInitialize for ModelReference: '<Root>/Model1' incorporates:
   *  Inport: '<Root>/Temp_degC'
   */
  Model2_Init();
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
