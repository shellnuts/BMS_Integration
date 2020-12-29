/*
 * File: BMS_Integration.h
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

#ifndef RTW_HEADER_BMS_Integration_h_
#define RTW_HEADER_BMS_Integration_h_
#include "rtwtypes.h"
#ifndef BMS_Integration_COMMON_INCLUDES_
# define BMS_Integration_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* BMS_Integration_COMMON_INCLUDES_ */

/* Child system includes */
#define Model1_MDLREF_HIDE_CHILD_
#include "Model1.h"
#define Model2_MDLREF_HIDE_CHILD_
#include "Model2.h"

/* Model Code Variants */

/* Macros for accessing real-time model data structure */

/* Forward declaration for rtModel */
typedef struct BMS_Integration_tag_RTM BMS_Integration_RT_MODEL;

#ifndef DEFINED_TYPEDEF_FOR_voltage_
#define DEFINED_TYPEDEF_FOR_voltage_

typedef struct {
  float32_T a;
  float32_T b;
} voltage;

#endif

/* Block signals and states (default storage) for system '<Root>' */
typedef struct {
  voltage Vlt_mV;                      /* '<Root>/Model' */
  float32_T soc_perc;                  /* '<Root>/Model' */
  float32_T Vp_mV;                     /* '<Root>/Model' */
  float32_T soh;                       /* '<Root>/Merge' */
  float32_T Rp_mohm;                   /* '<Root>/Model' */
  int8_T If_ActiveSubsystem;           /* '<Root>/If' */
} BMS_Integration_DW;

/* External inputs (root inport signals with default storage) */
typedef struct {
  float32_T Temp_degC;                 /* '<Root>/Temp_degC' */
  float32_T Icur_mA;                   /* '<Root>/Icur_mA' */
  float32_T CapFade_abs;               /* '<Root>/CapFade_abs' */
  float32_T schedule_flag;             /* '<Root>/schedule_flag' */
} BMS_Integration_ExtU;

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  float32_T soh;                       /* '<Root>/soh' */
  float32_T Vp_mV;                     /* '<Root>/Vp_mV' */
} BMS_Integration_ExtY;

/* Real-time Model Data Structure */
struct BMS_Integration_tag_RTM {
  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    struct {
      uint32_T TID[2];
    } TaskCounters;
  } Timing;
};

/* Block signals and states (default storage) */
extern BMS_Integration_DW BMS_Integration_DW_l;

/* External inputs (root inport signals with default storage) */
extern BMS_Integration_ExtU BMS_Integration_U;

/* External outputs (root outports fed by signals with default storage) */
extern BMS_Integration_ExtY BMS_Integration_Y;

/* Model block global parameters (default storage) */
extern float32_T rtP_P_Model1_gain;    /* Variable: P_Model1_gain
                                        * Referenced by: '<Root>/Model'
                                        */
extern float32_T rtP_P_Model2_gain;    /* Variable: P_Model2_gain
                                        * Referenced by: '<Root>/Model1'
                                        */

/* Model entry point functions */
extern void bbb_initialize(void);
extern void bbb_step(void);

/* Real-time Model object */
extern BMS_Integration_RT_MODEL *const BMS_Integration_M;

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
 * '<Root>' : 'BMS_Integration'
 * '<S1>'   : 'BMS_Integration/If Action Subsystem'
 * '<S2>'   : 'BMS_Integration/If Action Subsystem1'
 */
#endif                                 /* RTW_HEADER_BMS_Integration_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
