/*
 * File: Model1.c
 *
 * Code generated for Simulink model 'Model1'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec 29 15:06:19 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Model1.h"

/* Block states (default storage) */
Model1_DW_fw Model1_DW_i;

/* Output and update for atomic system: '<S2>/lib_Model1_func1' */
float32_T Model1_lib_Model1_func1(const float32_T *rtu_x, float32_T rtp_gain)
{
  /* Product: '<S3>/Divide' incorporates:
   *  Constant: '<S3>/Constant'
   *  Gain: '<S3>/Gain'
   */
  return rtp_gain * *rtu_x / 2.0F;
}

/* System initialize for referenced model: 'Model1' */
void Model1_Init(float32_T *rty_Rp_mohm)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Model1_main' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* SystemInitialize for Atomic SubSystem: '<S2>/lib_lowPassFilter' */
  lib_lowPassFilter_GMw2l0ml_Init(&Model1_DW_i.lib_lowPassFilter_i);

  /* End of SystemInitialize for SubSystem: '<S2>/lib_lowPassFilter' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Model1_main' */

  /* Outputs for Atomic SubSystem: '<Root>/Initialize Function' */
  /* StateWriter: '<S1>/State Writer' */
  Model1_DW_i.x = 20.0F;

  /* SignalConversion: '<S1>/Signal Conversion' */
  *rty_Rp_mohm = 20.0F;

  /* End of Outputs for SubSystem: '<Root>/Initialize Function' */
}

/* Output and update for referenced model: 'Model1' */
void Model1_Model1_main(const float32_T *rtu_Temp_degC, const float32_T
  *rtu_Icur_mA, const float32_T *rtu_CapFade_abs, float32_T *rty_soc_perc,
  float32_T *rty_Vp_mV, voltage *rty_Vlt_mV)
{
  float32_T rtb_Divide;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Model1_main' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Outputs for Atomic SubSystem: '<S2>/lib_lowPassFilter' */
  lib_lowPassFilter_GMw2l0ml(rtu_Temp_degC, rtu_Icur_mA, rtu_CapFade_abs,
    rty_soc_perc, &Model1_DW_i.lib_lowPassFilter_i);

  /* End of Outputs for SubSystem: '<S2>/lib_lowPassFilter' */

  /* Outputs for Atomic SubSystem: '<S2>/lib_Model1_func1' */
  rtb_Divide = Model1_lib_Model1_func1(rtu_CapFade_abs, rtP_P_Model1_gain);

  /* End of Outputs for SubSystem: '<S2>/lib_Model1_func1' */

  /* BusCreator: '<S2>/Bus Creator' */
  rty_Vlt_mV->a = *rty_soc_perc;
  rty_Vlt_mV->b = rtb_Divide;

  /* UnitDelay: '<S2>/Unit Delay' */
  *rty_Vp_mV = Model1_DW_i.x;

  /* Update for UnitDelay: '<S2>/Unit Delay' incorporates:
   *  Constant: '<S2>/Constant'
   */
  Model1_DW_i.x = 1.0F;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Model1_main' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
