/*
 * File: Model2.c
 *
 * Code generated for Simulink model 'Model2'.
 *
 * Model version                  : 1.43
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec 29 14:10:35 2020
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "Model2.h"

/* Block states (default storage) */
Model2_DW_fw Model2_DW_d;

/* Output and update for atomic system: '<S2>/lib_Model2_func1' */
void Model2_lib_Model2_func1(const float32_T *rtu_x, float32_T *rty_y, float32_T
  rtp_gain)
{
  /* Sum: '<S3>/Add' incorporates:
   *  Gain: '<S3>/Gain'
   */
  *rty_y = rtp_gain * *rtu_x + *rtu_x;
}

/* System initialize for atomic system: '<S2>/lib_lowPassFilter' */
void Model2_lib_lowPassFilter_Init(Model2_DW_lib_lowPassFilter *localDW)
{
  /* InitializeConditions for Delay: '<S4>/y0' */
  localDW->icLoad = 1U;
}

/* Output and update for atomic system: '<S2>/lib_lowPassFilter' */
void Model2_lib_lowPassFilter(const float32_T *rtu_u, const float32_T
  *rtu_filCoeff, const float32_T *rtu_x0, float32_T *rty_y,
  Model2_DW_lib_lowPassFilter *localDW)
{
  /* Delay: '<S4>/y0' */
  if (localDW->icLoad != 0) {
    localDW->y0_DSTATE = *rtu_x0;
  }

  /* Sum: '<S4>/Add1' incorporates:
   *  Constant: '<S4>/Constant'
   *  Delay: '<S4>/y0'
   *  Product: '<S4>/Product'
   *  Product: '<S4>/Product1'
   *  Sum: '<S4>/Add'
   */
  *rty_y = (1.0F - *rtu_filCoeff) * *rtu_u + localDW->y0_DSTATE * *rtu_filCoeff;

  /* Update for Delay: '<S4>/y0' */
  localDW->icLoad = 0U;
  localDW->y0_DSTATE = *rty_y;
}

/* System initialize for referenced model: 'Model2' */
void Model2_Init(void)
{
  /* SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Model2_main' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* SystemInitialize for Atomic SubSystem: '<S2>/lib_lowPassFilter' */
  Model2_lib_lowPassFilter_Init(&Model2_DW_d.lib_lowPassFilter_o);

  /* End of SystemInitialize for SubSystem: '<S2>/lib_lowPassFilter' */
  /* End of SystemInitialize for RootInportFunctionCallGenerator generated from: '<Root>/Model2_main' */
}

/* Output and update for referenced model: 'Model2' */
void Model2_Model2_main(const float32_T *rtu_soc_perc, const float32_T
  *rtu_Rp_mohm, const voltage *rtu_vlt_mV, const float32_T *rtu_Temp_degC,
  float32_T *rty_soh)
{
  float32_T rtb_Add1;
  float32_T rtb_Add;

  /* RootInportFunctionCallGenerator generated from: '<Root>/Model2_main' incorporates:
   *  SubSystem: '<Root>/Subsystem'
   */
  /* Outputs for Atomic SubSystem: '<S2>/lib_lowPassFilter' */
  Model2_lib_lowPassFilter(&rtu_vlt_mV->a, rtu_soc_perc, rtu_Rp_mohm, &rtb_Add1,
    &Model2_DW_d.lib_lowPassFilter_o);

  /* End of Outputs for SubSystem: '<S2>/lib_lowPassFilter' */

  /* Outputs for Atomic SubSystem: '<S2>/lib_Model2_func1' */
  Model2_lib_Model2_func1(rtu_Temp_degC, &rtb_Add, rtP_P_Model2_gain);

  /* End of Outputs for SubSystem: '<S2>/lib_Model2_func1' */

  /* Sum: '<S2>/Add' */
  *rty_soh = rtb_Add1 + rtb_Add;

  /* End of Outputs for RootInportFunctionCallGenerator generated from: '<Root>/Model2_main' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
