/*
 * File: Model1.h
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

#ifndef RTW_HEADER_Model1_h_
#define RTW_HEADER_Model1_h_
#include "rtwtypes.h"
#ifndef Model1_COMMON_INCLUDES_
# define Model1_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Model1_COMMON_INCLUDES_ */

/* Child system includes */
#ifndef Model1_MDLREF_HIDE_CHILD_
#include "lib_lowPassFilter_GMw2l0ml.h"
#endif                                 /*Model1_MDLREF_HIDE_CHILD_*/

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_voltage_
#define DEFINED_TYPEDEF_FOR_voltage_

typedef struct {
  float32_T a;
  float32_T b;
} voltage;

#endif

/* Block signals and states (default storage) for model 'Model1' */
#ifndef Model1_MDLREF_HIDE_CHILD_

typedef struct {
  DW_lib_lowPassFilter_GMw2l0ml lib_lowPassFilter_i;/* '<S2>/lib_lowPassFilter' */
  float32_T x;                         /* '<S2>/Unit Delay' */
} Model1_DW_fw;

#endif                                 /*Model1_MDLREF_HIDE_CHILD_*/

/* Model block global parameters (default storage) */
extern float32_T rtP_P_Model1_gain;    /* Variable: P_Model1_gain
                                        * Referenced by: '<S2>/lib_Model1_func1'
                                        */
extern void Model1_Init(float32_T *rty_Rp_mohm);
extern void Model1_Model1_main(const float32_T *rtu_Temp_degC, const float32_T
  *rtu_Icur_mA, const float32_T *rtu_CapFade_abs, float32_T *rty_soc_perc,
  float32_T *rty_Vp_mV, voltage *rty_Vlt_mV);

#ifndef Model1_MDLREF_HIDE_CHILD_

extern float32_T Model1_lib_Model1_func1(const float32_T *rtu_x, float32_T
  rtp_gain);

#endif                                 /*Model1_MDLREF_HIDE_CHILD_*/

#ifndef Model1_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern Model1_DW_fw Model1_DW_i;

#endif                                 /*Model1_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Model1'
 * '<S1>'   : 'Model1/Initialize Function'
 * '<S2>'   : 'Model1/Subsystem'
 * '<S3>'   : 'Model1/Subsystem/lib_Model1_func1'
 * '<S4>'   : 'Model1/Subsystem/lib_lowPassFilter'
 */
#endif                                 /* RTW_HEADER_Model1_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
