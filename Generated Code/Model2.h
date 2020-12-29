/*
 * File: Model2.h
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

#ifndef RTW_HEADER_Model2_h_
#define RTW_HEADER_Model2_h_
#include "rtwtypes.h"
#ifndef Model2_COMMON_INCLUDES_
# define Model2_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Model2_COMMON_INCLUDES_ */

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_voltage_
#define DEFINED_TYPEDEF_FOR_voltage_

typedef struct {
  float32_T a;
  float32_T b;
} voltage;

#endif

/* Block signals and states (default storage) for system '<S2>/lib_lowPassFilter' */
#ifndef Model2_MDLREF_HIDE_CHILD_

typedef struct {
  float32_T y0_DSTATE;                 /* '<S4>/y0' */
  uint8_T icLoad;                      /* '<S4>/y0' */
} Model2_DW_lib_lowPassFilter;

#endif                                 /*Model2_MDLREF_HIDE_CHILD_*/

/* Block signals and states (default storage) for model 'Model2' */
#ifndef Model2_MDLREF_HIDE_CHILD_

typedef struct {
  Model2_DW_lib_lowPassFilter lib_lowPassFilter_o;/* '<S2>/lib_lowPassFilter' */
} Model2_DW_fw;

#endif                                 /*Model2_MDLREF_HIDE_CHILD_*/

/* Model block global parameters (default storage) */
extern float32_T rtP_P_Model2_gain;    /* Variable: P_Model2_gain
                                        * Referenced by: '<S2>/lib_Model2_func1'
                                        */
extern void Model2_Init(void);
extern void Model2_Model2_main(const float32_T *rtu_soc_perc, const float32_T
  *rtu_Rp_mohm, const voltage *rtu_vlt_mV, const float32_T *rtu_Temp_degC,
  float32_T *rty_soh);

#ifndef Model2_MDLREF_HIDE_CHILD_

extern void Model2_lib_Model2_func1(const float32_T *rtu_x, float32_T *rty_y,
  float32_T rtp_gain);
extern void Model2_lib_lowPassFilter_Init(Model2_DW_lib_lowPassFilter *localDW);
extern void Model2_lib_lowPassFilter(const float32_T *rtu_u, const float32_T
  *rtu_filCoeff, const float32_T *rtu_x0, float32_T *rty_y,
  Model2_DW_lib_lowPassFilter *localDW);

#endif                                 /*Model2_MDLREF_HIDE_CHILD_*/

#ifndef Model2_MDLREF_HIDE_CHILD_

/* Block states (default storage) */
extern Model2_DW_fw Model2_DW_d;

#endif                                 /*Model2_MDLREF_HIDE_CHILD_*/

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
 * '<Root>' : 'Model2'
 * '<S1>'   : 'Model2/Initialize Function'
 * '<S2>'   : 'Model2/Subsystem'
 * '<S3>'   : 'Model2/Subsystem/lib_Model2_func1'
 * '<S4>'   : 'Model2/Subsystem/lib_lowPassFilter'
 */
#endif                                 /* RTW_HEADER_Model2_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
