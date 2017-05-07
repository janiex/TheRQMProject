/*
 * File: ISO2631_All_GenerationTemplate.c
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

#include "ISO2631_All_GenerationTemplate.h"
#include "ISO2631_All_GenerationTemplate_private.h"
#include "IO.h"
/*
//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioCtrlRegsFile")
#else
#pragma DATA_SECTION(GpioCtrlRegs,"GpioCtrlRegsFile");
#endif
volatile struct GPIO_CTRL_REGS GpioCtrlRegs;

//----------------------------------------
#ifdef __cplusplus
#pragma DATA_SECTION("GpioDataRegsFile")
#else
#pragma DATA_SECTION(GpioDataRegs,"GpioDataRegsFile");
#endif
volatile struct GPIO_DATA_REGS GpioDataRegs;
*/
#define  EALLOW asm(" EALLOW")
#define  EDIS   asm(" EDIS")

//#define SWITCH_LED_ON()		EALLOW;\
//		GpioDataRegs.GPASET.bit.GPIO9 = 1;\		
//		EDIS
//		
//#define SWITCH_LED_OFF()		EALLOW;\
//		GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;\		
//		EDIS
		
#define cSWITCH ((real_T)6)
/* Block states (auto storage) */
D_Work_ISO2631_All_GenerationTe ISO2631_All_GenerationTem_DWork;
/* Debug variables */
real_T InputBuffer[10] = {0, 0.00188464031722077, 0.00628188735329749, 0.0131914790955888, 0.0226125130540358, 0.0345427920810054, 0.0489779328073037, 0.0659102376281471, 0.0853273320577452, 0.107210570603253};
real_T OutputBuffer[10];
real_T *pIn = &InputBuffer[0];
real_T *pOut = &OutputBuffer[0];
void Rte_IWrite_Runnable_BandPass_Step_FilterOut_FilterOut(real_T u)
{
	*pOut++ = u;
}
real_T Rte_IRead_BandPass_Runnable_BandPass_Step_ISO2631_Ctrl_ISO2631_Ctrl(void)
{
	return cSWITCH;
}

real_T Rte_IRead_BandPass_Runnable_BandPass_Step_ISO2631_in_ISO2631_in(void)
{
	return *pIn++;
}
/* Model step function */
void Runnable_BandPass_Step(void)
{
  real_T denAccum;
  real_T denAccum_0;
  real_T denAccum_1;
  real_T denAccum_2;
  real_T denAccum_3;
  real_T denAccum_4;
  real_T denAccum_5;
  real_T denAccum_6;
  real_T denAccum_7;
  real_T denAccum_8;
  real_T denAccum_9;
  real_T rtb_TmpSignalConversionAtISO2_i;
  real_T rtb_MultiportSwitch;

  /* SignalConversion: '<Root>/TmpSignal ConversionAtISO2631_inOutport2' incorporates:
   *  Inport: '<Root>/ISO2631_in'
   */
  rtb_TmpSignalConversionAtISO2_i =
    Rte_IRead_Runnable_BandPass_Step_ISO2631_in_ISO2631_in();

  /* DiscreteFilter: '<S2>/Band Pass Filter' */
  denAccum = ((((rtb_TmpSignalConversionAtISO2_i -
                 ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator[1] *
                 ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[0]) -
                ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator[2] *
                ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[1]) -
               ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator[3] *
               ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[2]) -
              ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator[4] *
              ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator[0];

  /* DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_0 = ((((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator
                       [0] * denAccum +
                       ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator
                       [1] *
                       ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[0])
                      + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator[
                      2] *
                      ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[1])
                     + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator
                     [3] *
                     ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[2]) +
                    ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator[4] *
                    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[3]) -
                   ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_g
                   [1] *
                   ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele
                   [0]) -
                  ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_g
                  [2] *
                  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele
                  [1]) -
                 ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_g[
                 3] *
                 ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[
                 2]) -
                ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_g
                [4] *
                ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele
                [3]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_g[0];

  /* DiscreteFilter: '<S3>/Band Pass Filter' */
  denAccum_1 = ((((rtb_TmpSignalConversionAtISO2_i -
                   ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_e
                   [1] *
                   ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[0]) -
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_e[2]
                  * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[1])
                 - ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_e
                 [3] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[2])
                - ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_e[4]
                * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_e[0];

  /* DiscreteFilter: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_2 = ((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_n
                     [0] * denAccum_1 +
                     ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_n
                     [1] *
                     ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[0])
                    + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_n[
                    2] *
                    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[1])
                   + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_n
                   [3] *
                   ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[2]) +
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_n[4] *
                  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[3]) -
                 ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_o[
                 1] *
                 ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[
                 0]) -
                ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_o
                [2] *
                ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o
                [1]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_o[0];

  /* DiscreteFilter: '<S4>/Band Pass Filter' */
  denAccum_3 = ((((rtb_TmpSignalConversionAtISO2_i -
                   ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_h
                   [1] *
                   ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[0]) -
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_h[2]
                  * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[1])
                 - ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_h
                 [3] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[2])
                - ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_h[4]
                * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_h[0];

  /* DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_4 =
    ((((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_e[0] *
            denAccum_3 +
            ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_e[1] *
            ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[0]) +
           ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_e[2] *
           ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[1]) +
          ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_e[3] *
          ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[2]) +
         ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_e[4] *
         ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[3]) -
        ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_j[1] *
        ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[0]) -
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_j[2] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[1]) -
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_j[3] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[2]) -
     ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_j[4] *
     ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[3]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_j[0];

  /* DiscreteFilter: '<S5>/Band Pass Filter' */
  denAccum_5 = ((((rtb_TmpSignalConversionAtISO2_i -
                   ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_en[
                   1] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h
                   [0]) -
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_en
                  [2] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h
                  [1]) -
                 ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_en[3]
                 * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[2]) -
                ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_en[4]
                * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_en[0];

  /* DiscreteFilter: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_6 =
    ((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_na[0] *
          denAccum_5 +
          ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_na[1] *
          ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[0]) +
         ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_na[2] *
         ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[1]) +
        ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_na[3] *
        ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[2]) +
       ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_na[4] *
       ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[3]) -
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_a[1] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[0]) -
     ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_a[2] *
     ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[1]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_a[0];

  /* DiscreteFilter: '<S6>/Band Pass Filter' */
  denAccum_7 = ((((rtb_TmpSignalConversionAtISO2_i -
                   ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_hj[
                   1] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m
                   [0]) -
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_hj
                  [2] * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m
                  [1]) -
                 ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_hj[3]
                 * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[2]) -
                ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_hj[4]
                * ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_hj[0];

  /* DiscreteFilter: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_8 = ((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_d
                     [0] * denAccum_7 +
                     ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_d
                     [1] *
                     ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[0])
                    + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_d[
                    2] *
                    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[1])
                   + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_d
                   [3] *
                   ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[2]) +
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_d[4] *
                  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[3]) -
                 ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fi[
                 1] *
                 ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[
                 0]) -
                ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fi
                [2] *
                ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb
                [1]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fi[0];

  /* DiscreteFilter: '<S7>/Band Pass Filter' */
  rtb_TmpSignalConversionAtISO2_i = ((((rtb_TmpSignalConversionAtISO2_i -
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_b[1] *
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[0]) -
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_b[2] *
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[1]) -
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_b[3] *
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[2]) -
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_b[4] *
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[3]) /
    ISO2631_All_GenerationTemplat_P.BandPassFilter_Denominator_b[0];

  /* DiscreteFilter: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  denAccum_9 = ((((((ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_i
                     [0] * rtb_TmpSignalConversionAtISO2_i +
                     ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_i
                     [1] *
                     ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[0])
                    + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_i[
                    2] *
                    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[1])
                   + ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_i
                   [3] *
                   ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[2]) +
                  ISO2631_All_GenerationTemplat_P.BandPassFilter_Numerator_i[4] *
                  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[3]) -
                 ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_jz[
                 1] *
                 ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[
                 0]) -
                ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_jz
                [2] *
                ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h
                [1]) /
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_jz[0];

  /* MultiPortSwitch: '<S1>/Multiport Switch' incorporates:
   *  Inport: '<Root>/ISO2631_Ctrl'
   *  SignalConversion: '<Root>/TmpSignal ConversionAtISO2631_CtrlOutport2'
   */
  switch ((int16_T)Rte_IRead_Runnable_BandPass_Step_ISO2631_Ctrl_ISO2631_Ctrl())
  {
   case 1L:
    rtb_MultiportSwitch =
      (((ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_i[0] *
         denAccum_0 +
         ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_i[1] *
         ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[0]) +
        ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_i[2] *
        ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[1]) +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_i[3] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[2]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_i[4] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[3];
    break;

   case 2L:
    rtb_MultiportSwitch =
      (ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_n[0] *
       denAccum_2 +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_n[1] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[0]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_n[2] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[1];
    break;

   case 3L:
    rtb_MultiportSwitch =
      (((ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_e[0] *
         denAccum_4 +
         ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_e[1] *
         ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[0]) +
        ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_e[2] *
        ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[1]) +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_e[3] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[2]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_e[4] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[3];
    break;

   case 4L:
    rtb_MultiportSwitch =
      (ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_k[0] *
       denAccum_6 +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_k[1] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[0]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_k[2] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[1];
    break;

   case 5L:
    rtb_MultiportSwitch =
      (ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fk[0] *
       denAccum_8 +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fk[1] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[0]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_fk[2] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[1];
    break;

   default:
    rtb_MultiportSwitch =
      (ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_ez[0] *
       denAccum_9 +
       ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_ez[1] *
       ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[0]) +
      ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_ez[2] *
      ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[1];
    break;
  }

  /* SignalConversion: '<Root>/TmpSignal ConversionAtFilterOutInport2' */
  Rte_IWrite_Runnable_BandPass_Step_FilterOut_FilterOut(rtb_MultiportSwitch);

  /* Update for DiscreteFilter: '<S2>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[0] = denAccum;

  /* Update for DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[3] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[2];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[2] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[1];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[0] =
    denAccum_0;

  /* Update for DiscreteFilter: '<S3>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[0] = denAccum_1;

  /* Update for DiscreteFilter: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[0] =
    denAccum_2;

  /* Update for DiscreteFilter: '<S4>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[0] = denAccum_3;

  /* Update for DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[3] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[2];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[2] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[1];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[0] =
    denAccum_4;

  /* Update for DiscreteFilter: '<S5>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[0] = denAccum_5;

  /* Update for DiscreteFilter: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[0] =
    denAccum_6;

  /* Update for DiscreteFilter: '<S6>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[0] = denAccum_7;

  /* Update for DiscreteFilter: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[0] =
    denAccum_8;

  /* Update for DiscreteFilter: '<S7>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[3] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[2];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[2] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[1];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[1] =
    ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[0];
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[0] =
    rtb_TmpSignalConversionAtISO2_i;

  /* Update for DiscreteFilter: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[1] =
    ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[0];
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[0] =
    denAccum_9;
}

/* Model initialize function */
void Runnable_BandPass_Init(void)
{
  /* InitializeConditions for DiscreteFilter: '<S2>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAccele;

  /* InitializeConditions for DiscreteFilter: '<S3>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_f;

  /* InitializeConditions for DiscreteFilter: '<S2>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAccele;

  /* InitializeConditions for DiscreteFilter: '<S3>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_f;

  /* InitializeConditions for DiscreteFilter: '<S2>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[2] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAccele;

  /* InitializeConditions for DiscreteFilter: '<S3>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_f;

  /* InitializeConditions for DiscreteFilter: '<S2>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates;

  /* InitializeConditions for DiscreteFilter: '<S2>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAccele[3] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAccele;

  /* InitializeConditions for DiscreteFilter: '<S3>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_e[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_f;

  /* InitializeConditions for DiscreteFilter: '<S3>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_f;
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_o[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_f;

  /* InitializeConditions for DiscreteFilter: '<S4>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_b;

  /* InitializeConditions for DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_h;

  /* InitializeConditions for DiscreteFilter: '<S5>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_e;

  /* InitializeConditions for DiscreteFilter: '<S4>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_b;

  /* InitializeConditions for DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_h;

  /* InitializeConditions for DiscreteFilter: '<S5>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_e;

  /* InitializeConditions for DiscreteFilter: '<S4>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_b;

  /* InitializeConditions for DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[2] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_h;

  /* InitializeConditions for DiscreteFilter: '<S5>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_e;

  /* InitializeConditions for DiscreteFilter: '<S4>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_i[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_b;

  /* InitializeConditions for DiscreteFilter: '<S4>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_l[3] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcce_h;

  /* InitializeConditions for DiscreteFilter: '<S5>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_h[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_e;

  /* InitializeConditions for DiscreteFilter: '<S5>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_gu;
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_j[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_gu;

  /* InitializeConditions for DiscreteFilter: '<S6>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_d;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_d;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_d;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_m[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_d;

  /* InitializeConditions for DiscreteFilter: '<S6>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_e5;
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcc_lb[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_e5;

  /* InitializeConditions for DiscreteFilter: '<S7>/Band Pass Filter' */
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[0] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_o;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[1] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_o;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[2] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_o;
  ISO2631_All_GenerationTem_DWork.BandPassFilter_DSTATE_a[3] =
    ISO2631_All_GenerationTemplat_P.BandPassFilter_InitialStates_o;

  /* InitializeConditions for DiscreteFilter: '<S7>/weighting transfer function (Acceleration-velocity transition + Upward step filter)' */
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[0] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_ey;
  ISO2631_All_GenerationTem_DWork.weightingtransferfunctionAcce_h[1] =
    ISO2631_All_GenerationTemplat_P.weightingtransferfunctionAcc_ey;
}

void InitPorts(void)
{
	EALLOW;
	// Set necessary pins as outputs
	GpioCtrlRegs.GPADIR.all = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;	// peripheral explorer: LED LD1 at GPIO9	
	GpioCtrlRegs.GPADIR.bit.GPIO11 = 1; // peripheral explorer: LED LD2 at GPIO11
	GpioCtrlRegs.GPBDIR.all = 0;		// GPIO63-32 as inputs
	GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;	// peripheral explorer: LED LD3 at GPIO34
	GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1; // peripheral explorer: LED LD4 at GPIO49
	//Switch off all LEDs
	GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
	GpioDataRegs.GPACLEAR.bit.GPIO11 = 1;
	GpioDataRegs.GPBCLEAR.bit.GPIO34 = 1;
	GpioDataRegs.GPBCLEAR.bit.GPIO49 = 1;
	EDIS;
}

void ProcessISO2631()
{
	volatile int i;
	InitPorts();
	memset(
			(D_Work_ISO2631_All_GenerationTe*)&ISO2631_All_GenerationTem_DWork,
			 0,
			 sizeof(ISO2631_All_GenerationTem_DWork)
			 );
	Runnable_BandPass_Init();
	
        
	for(i = 0; i< 10; i++)
	{
		EALLOW;
	    GpioDataRegs.GPASET.bit.GPIO9 = 1; 		
	    EDIS;
		Runnable_BandPass_Step();
		EALLOW;
        GpioDataRegs.GPACLEAR.bit.GPIO9 = 1;
        EDIS; 
	}
	
	while(1)
	{
		i++;
	}
}
/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
