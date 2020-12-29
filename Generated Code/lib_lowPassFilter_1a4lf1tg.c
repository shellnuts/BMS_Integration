/*
 * File: lib_lowPassFilter_1a4lf1tg.c
 *
 * Code generated for Simulink model 'Model1'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec 29 13:46:53 2020
 */

#include "lib_lowPassFilter_1a4lf1tg.h"

/* System initialize for atomic system: 'lib_lowPassFilter' ('lib_BMS_2019b:371') */
void lib_lowPassFilter_1a4lf1tg_Init(DW_lib_lowPassFilter_1a4lf1tg *localDW)
{
  /* InitializeConditions for Delay: 'y0' ('lib_BMS_2019b:378') */
  localDW->icLoad = 1U;
}

/* Output and update for atomic system: 'lib_lowPassFilter' ('lib_BMS_2019b:371') */
void lib_lowPassFilter_1a4lf1tg(const float32_T *rtu_u, const float32_T
  *rtu_filCoeff, const float32_T *rtu_x0, float32_T *rty_y,
  DW_lib_lowPassFilter_1a4lf1tg *localDW)
{
  /* Delay: 'y0' ('lib_BMS_2019b:378') */
  if (localDW->icLoad != 0) {
    localDW->y0_DSTATE = *rtu_x0;
  }

  /* Sum: 'Add1' ('lib_BMS_2019b:376') incorporates:
   *  Constant: 'Constant' ('lib_BMS_2019b:377')
   *  Delay: 'y0' ('lib_BMS_2019b:378')
   *  Product: 'Product' ('lib_BMS_2019b:379')
   *  Product: 'Product1' ('lib_BMS_2019b:380')
   *  Sum: 'Add' ('lib_BMS_2019b:375')
   */
  *rty_y = (1.0F - *rtu_filCoeff) * *rtu_u + localDW->y0_DSTATE * *rtu_filCoeff;

  /* Update for Delay: 'y0' ('lib_BMS_2019b:378') */
  localDW->icLoad = 0U;
  localDW->y0_DSTATE = *rty_y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
