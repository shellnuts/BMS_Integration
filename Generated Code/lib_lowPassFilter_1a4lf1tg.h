/*
 * File: lib_lowPassFilter_1a4lf1tg.h
 *
 * Code generated for Simulink model 'Model1'.
 *
 * Model version                  : 1.47
 * Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
 * C/C++ source code generated on : Tue Dec 29 13:46:53 2020
 */

#ifndef RTW_HEADER_lib_lowPassFilter_1a4lf1tg_h_
#define RTW_HEADER_lib_lowPassFilter_1a4lf1tg_h_

/* Shared type includes */
#include "rtwtypes.h"

/* Block signals and states (default storage) for system 'lib_lowPassFilter' ('lib_BMS_2019b:371') */
typedef struct {
  float32_T y0_DSTATE;                  /* 'y0' ('lib_BMS_2019b:378') */
  uint8_T icLoad;                      /* 'y0' ('lib_BMS_2019b:378') */
} DW_lib_lowPassFilter_1a4lf1tg;

extern void lib_lowPassFilter_1a4lf1tg_Init(DW_lib_lowPassFilter_1a4lf1tg
  *localDW);
extern void lib_lowPassFilter_1a4lf1tg(const float32_T *rtu_u, const float32_T
  *rtu_filCoeff, const float32_T *rtu_x0, float32_T *rty_y,
  DW_lib_lowPassFilter_1a4lf1tg *localDW);

#endif                            /* RTW_HEADER_lib_lowPassFilter_1a4lf1tg_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
