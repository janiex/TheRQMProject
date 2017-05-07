/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_ECap.h                                               **
**                                                                            **
**  Copyright (C) none (open standard)                                        **
**                                                                            **
**  TARGET    : Delfino TMS320F28335                                          **
**                                                                            **
**  COMPILER  : CCS                                                           **
**                                                                            **
**  PROJECT   : Open Source OSEK                                              **
**                                                                            **
**  AUTHOR    : Kristian Dilov                                                **
**                                                                            **
**  PURPOSE   : Scientific Research                                           **
**                                                                            **
**  REMARKS   : None                                                          **
**                                                                            **
**  PLATFORM DEPENDANT [yes/no]: yes                                          **
**                                                                            **
**  TO BE CHANGED BY USER [yes/no]: no                                        **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
**                      Author Identity                                       **
********************************************************************************
**                                                                            **
** Initials     Name                       Organization                       **
** --------     -------------------------  -----------------------------------**
** KD           Kristian Dilov             TU-Sofia                           **
**                                                                            **
*******************************************************************************/
/*******************************************************************************
** This file is genereted on: 9.3.2017 22:04:47                               **
**                                                                            **
*******************************************************************************/
#include "Identification.h"
#if(MAGIC_NUMBER != 30511208)
    #error "Inplausible genereted source files"
#endif /* (MAGIC_NUMBER != 30511208 */
// TI File $Revision: /main/1 $
// Checkin $Date: August 18, 2006   13:52:07 $
//###########################################################################
//
// FILE:   DSP2833x_ECap.h
//
// TITLE:  DSP2833x Enhanced Capture Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_ECAP_H
#define DSP2833x_ECAP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture control register 1 bit definitions */                                    
struct ECCTL1_BITS {          // bits   description
   uint16 CAP1POL:1;          // 0      Capture Event 1 Polarity select
   uint16 CTRRST1:1;          // 1      Counter Reset on Capture Event 1
   uint16 CAP2POL:1;          // 2      Capture Event 2 Polarity select
   uint16 CTRRST2:1;          // 3      Counter Reset on Capture Event 2
   uint16 CAP3POL:1;          // 4      Capture Event 3 Polarity select
   uint16 CTRRST3:1;          // 5      Counter Reset on Capture Event 3
   uint16 CAP4POL:1;          // 6      Capture Event 4 Polarity select
   uint16 CTRRST4:1;          // 7      Counter Reset on Capture Event 4
   uint16 CAPLDEN:1;          // 8      Enable Loading CAP1-4 regs on a Cap Event
   uint16 PRESCALE:5;         // 13:9   Event Filter prescale select
   uint16 FREE_SOFT:2;        // 15:14  Emulation mode
};

union ECCTL1_REG {
   uint16              all;
   struct ECCTL1_BITS  bit;
};


// In V1.1 the STOPVALUE bit field was changed to 
// STOP_WRAP.  This correlated to a silicon change from
// F2833x Rev 0 to Rev A. 
//----------------------------------------------------
// Capture control register 2 bit definitions */                                    
struct ECCTL2_BITS {          // bits   description
   uint16 CONT_ONESHT:1;      // 0      Continuous or one-shot
   uint16 STOP_WRAP:2;        // 2:1    Stop value for one-shot, Wrap for continuous
   uint16 REARM:1;            // 3      One-shot re-arm
   uint16 TSCTRSTOP:1;        // 4      TSCNT counter stop
   uint16 SYNCI_EN:1;         // 5      Counter sync-in select
   uint16 SYNCO_SEL:2;        // 7:6    Sync-out mode
   uint16 SWSYNC:1;           // 8      SW forced counter sync
   uint16 CAP_APWM:1;         // 9      CAP/APWM operating mode select
   uint16 APWMPOL:1;          // 10     APWM output polarity select
   uint16 rsvd1:5;            // 15:11  
};


union ECCTL2_REG {
   uint16              all;
   struct ECCTL2_BITS  bit;
};


//----------------------------------------------------
// ECAP interrupt enable register bit definitions */                                    
struct ECEINT_BITS {          // bits   description
   uint16 rsvd1:1;            // 0      reserved
   uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Enable
   uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Enable
   uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Enable
   uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Enable         
   uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Enable
   uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Enable
   uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Enable
   uint16 rsvd2:8;            // 15:8   reserved
};


union ECEINT_REG {
   uint16              all;
   struct ECEINT_BITS  bit;
};

//----------------------------------------------------
// ECAP interrupt flag register bit definitions */                                    
struct ECFLG_BITS {           // bits   description
   uint16 INT:1;              // 0      Global Flag
   uint16 CEVT1:1;            // 1      Capture Event 1 Interrupt Flag
   uint16 CEVT2:1;            // 2      Capture Event 2 Interrupt Flag
   uint16 CEVT3:1;            // 3      Capture Event 3 Interrupt Flag
   uint16 CEVT4:1;            // 4      Capture Event 4 Interrupt Flag         
   uint16 CTROVF:1;           // 5      Counter Overflow Interrupt Flag
   uint16 CTR_EQ_PRD:1;       // 6      Period Equal Interrupt Flag
   uint16 CTR_EQ_CMP:1;       // 7      Compare Equal Interrupt Flag
   uint16 rsvd2:8;            // 15:8   reserved
};


union ECFLG_REG {
   uint16              all;
   struct ECFLG_BITS   bit;
};


//----------------------------------------------------

struct ECAP_REGS {
   uint32              TSCTR;    // Time stamp counter 
   uint32              CTRPHS;   // Counter phase
   uint32              CAP1;     // Capture 1 
   uint32              CAP2;     // Capture 2    
   uint32              CAP3;     // Capture 3 
   uint32              CAP4;     // Capture 4   
   uint16              rsvd1[8]; // reserved
   union   ECCTL1_REG  ECCTL1;   // Capture Control Reg 1
   union   ECCTL2_REG  ECCTL2;   // Capture Control Reg 2
   union   ECEINT_REG  ECEINT;   // ECAP interrupt enable
   union   ECFLG_REG   ECFLG;    // ECAP interrupt flags
   union   ECFLG_REG   ECCLR;    // ECAP interrupt clear
   union   ECEINT_REG  ECFRC;    // ECAP interrupt force
   uint16              rsvd2[6]; // reserved   
};

    
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct ECAP_REGS ECap1Regs;
extern volatile struct ECAP_REGS ECap2Regs;
extern volatile struct ECAP_REGS ECap3Regs;
extern volatile struct ECAP_REGS ECap4Regs;
extern volatile struct ECAP_REGS ECap5Regs;
extern volatile struct ECAP_REGS ECap6Regs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_ECAP_H definition

//===========================================================================
// End of file.
//===========================================================================

/* EOF */
