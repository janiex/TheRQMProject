/*
 * File: ISO2631_All_GenerationTemplate.h
 *
 * Real-Time Workshop code generated for Simulink model ISO2631_All_GenerationTemplate.
 *
 * Model version                        : 1.17
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sat Sep 06 13:19:54 2014
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sat Sep 06 13:19:55 2014
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_ISO2631_All_GenerationTemplate_h_
#define RTW_HEADER_ISO2631_All_GenerationTemplate_h_
#ifndef ISO2631_All_GenerationTemplate_COMMON_INCLUDES_
# define ISO2631_All_GenerationTemplate_COMMON_INCLUDES_
#include "rtwtypes.h"
#include "Rte_BandPass.h"
#endif                                 /* ISO2631_All_GenerationTemplate_COMMON_INCLUDES_ */

#include "ISO2631_All_GenerationTemplate_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((void*) 0)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((void) 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

#define ISO2631_All_GenerationTemplate_M (ISO2631_All_GenerationTempla_M)

/* Block states (auto storage) for system '<Root>' */
typedef struct tag_D_Work_ISO2631_All_Generati {
  real_T BandPassFilter_DSTATE[4];     /* '<S2>/Band Pass Filter' */
  real_T weightingtransferfunctionAccele[4];/* '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  real_T BandPassFilter_DSTATE_e[4];   /* '<S3>/Band Pass Filter' */
  real_T weightingtransferfunctionAcce_o[2];/* '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  real_T BandPassFilter_DSTATE_i[4];   /* '<S4>/Band Pass Filter' */
  real_T weightingtransferfunctionAcce_l[4];/* '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  real_T BandPassFilter_DSTATE_h[4];   /* '<S5>/Band Pass Filter' */
  real_T weightingtransferfunctionAcce_j[2];/* '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  real_T BandPassFilter_DSTATE_m[4];   /* '<S6>/Band Pass Filter' */
  real_T weightingtransferfunctionAcc_lb[2];/* '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  real_T BandPassFilter_DSTATE_a[4];   /* '<S7>/Band Pass Filter' */
  real_T weightingtransferfunctionAcce_h[2];/* '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
} D_Work_ISO2631_All_GenerationTe;

/* Parameters (auto storage) */
struct Parameters_ISO2631_All_Generati_ {
  real_T BandPassFilter_InitialStates; /* Expression: 0
                                        * Referenced by: '<S2>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Numerator[5];  /* Expression: [0.0638508113542868 1.33226762955019E-15 -0.127701622708578 4.2188474935756E-15 0.0638508113542855
                                          ]
                                        * Referenced by: '<S2>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Denominator[5];/* Expression: [1.0 -3.16470636644551 3.75293919582273 -2.01084465327318 0.422613437162517]
                                        * Referenced by: '<S2>/Band Pass Filter'
                                        */
  real_T weightingtransferfunctionAccele;/* Expression: 0
                                          * Referenced by: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcce_i[5];/* Expression: [0.0382312829345277 -0.0729444373075823 -0.0034621921267961 0.0729450727468253 -0.0347684553684901
                                               ]
                                             * Referenced by: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcce_g[5];/* Expression: [1.0 -3.85371908982878 5.57025894073329 -3.57917165034607 0.862634338641796
                                               ]
                                             * Referenced by: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T BandPassFilter_InitialStates_f;/* Expression: 0
                                         * Referenced by: '<S3>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Numerator_n[5];/* Expression: [0.0638508113542868 1.33226762955019e-15 -0.127701622708578 4.21884749357560e-15 0.0638508113542855]
                                        * Referenced by: '<S3>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Denominator_e[5];/* Expression: [1 -3.16470636644551 3.75293919582273 -2.01084465327318 0.422613437162517]
                                          * Referenced by: '<S3>/Band Pass Filter'
                                          */
  real_T weightingtransferfunctionAcce_f;/* Expression: 0
                                          * Referenced by: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcce_n[3];/* Expression: [0.00625998383111404 7.81740945390297e-05 -0.00618180973657412]
                                             * Referenced by: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcce_o[3];/* Expression: [1 -1.98009477313205 0.980251121321129]
                                             * Referenced by: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T BandPassFilter_InitialStates_b;/* Expression: 0
                                         * Referenced by: '<S4>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Numerator_e[5];/* Expression: [3.90490872548277e-06 1.33226762955019e-15 -7.80981745673870e-06 6.66133814775094e-15 3.90490872359539e-06]
                                        * Referenced by: '<S4>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Denominator_h[5];/* Expression: [1 -3.99369112814028 5.98109324158920 -3.98111308623633 0.993710972791352]
                                          * Referenced by: '<S4>/Band Pass Filter'
                                          */
  real_T weightingtransferfunctionAcce_h;/* Expression: 0
                                          * Referenced by: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcce_e[5];/* Expression: [6.16196311309381e-07 3.02496694359888e-10 -1.23209003710656e-06 -3.02301739196764e-10 6.15893909761134e-07]
                                             * Referenced by: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcce_j[5];/* Expression: [1 -3.99738721075116 5.99216592735038 -3.99217021978984 0.997391503191591]
                                             * Referenced by: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T BandPassFilter_InitialStates_e;/* Expression: 0
                                         * Referenced by: '<S5>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Numerator_na[5];/* Expression: [0.0638508113542868 1.33226762955019e-15 -0.127701622708578 4.21884749357560e-15 0.0638508113542855]
                                         * Referenced by: '<S5>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Denominator_en[5];/* Expression: [1 -3.16470636644551 3.75293919582273 -2.01084465327318 0.422613437162517
                                             ]
                                           * Referenced by: '<S5>/Band Pass Filter'
                                           */
  real_T weightingtransferfunctionAcc_gu;/* Expression: 0
                                          * Referenced by: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcce_k[3];/* Expression: [0.0247609605891664 0.00121410777362563 -0.0235468528155406]
                                             * Referenced by: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcce_a[3];/* Expression: [1 -1.92089271555639 0.923320931103639]
                                             * Referenced by: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T BandPassFilter_InitialStates_d;/* Expression: 0
                                         * Referenced by: '<S6>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Numerator_d[5];/* Expression: [0.0638508113542868 1.33226762955019e-15 -0.127701622708578 4.21884749357560e-15 0.0638508113542855]
                                        * Referenced by: '<S6>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Denominator_hj[5];/* Expression: [1 -3.16470636644551 3.75293919582273 -2.01084465327318 0.422613437162517]
                                           * Referenced by: '<S6>/Band Pass Filter'
                                           */
  real_T weightingtransferfunctionAcc_e5;/* Expression: 0
                                          * Referenced by: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcc_fk[3];/* Expression: [0.00313579418517251 1.96410717046014e-05 -0.00311615311346891]
                                             * Referenced by: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcc_fi[3];/* Expression: [1 -1.99003699198573 0.990076274129142]
                                             * Referenced by: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T BandPassFilter_InitialStates_o;/* Expression: 0
                                         * Referenced by: '<S7>/Band Pass Filter'
                                         */
  real_T BandPassFilter_Numerator_i[5];/* Expression: [0.0638508113542868 1.33226762955019e-15 -0.127701622708578 4.21884749357560e-15 0.0638508113542855]
                                        * Referenced by: '<S7>/Band Pass Filter'
                                        */
  real_T BandPassFilter_Denominator_b[5];/* Expression: [1 -3.16470636644551 3.75293919582273 -2.01084465327318 0.422613437162517]
                                          * Referenced by: '<S7>/Band Pass Filter'
                                          */
  real_T weightingtransferfunctionAcc_ey;/* Expression: 0
                                          * Referenced by: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                          */
  real_T weightingtransferfunctionAcc_ez[3];/* Expression: [0.994541131125826 -1.96311895053930 0.969122822764292]
                                             * Referenced by: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
  real_T weightingtransferfunctionAcc_jz[3];/* Expression: [1 -1.96284301122498 0.963939893204438]
                                             * Referenced by: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)'
                                             */
};

/* Block parameters (auto storage) */
extern Parameters_ISO2631_All_Generati ISO2631_All_GenerationTemplat_P;

/* Block states (auto storage) */
extern D_Work_ISO2631_All_GenerationTe ISO2631_All_GenerationTem_DWork;

/* Model step and init functions */
extern void Runnable_BandPass_Step(void);
extern void Runnable_BandPass_Init(void);

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
 * '<Root>' : ISO2631_All_GenerationTemplate
 * '<S1>'   : ISO2631_All_GenerationTemplate/ISO 2631
 * '<S2>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631 - Type1 Wk
 * '<S3>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631-Type2 Wd
 * '<S4>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631-Type3 Wf
 * '<S5>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631-Type4 Wc
 * '<S6>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631-Type5 We
 * '<S7>'   : ISO2631_All_GenerationTemplate/ISO 2631/ISO2631-Type6 Wj
 */
#endif                                 /* RTW_HEADER_ISO2631_All_GenerationTemplate_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
