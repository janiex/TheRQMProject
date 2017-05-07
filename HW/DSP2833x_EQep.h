/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_EQep.h                                               **
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
// Checkin $Date: August 18, 2006   13:52:13 $
//###########################################################################
//
// FILE:   DSP2833x_EQep.h
//
// TITLE:  DSP2833x Enhanced Quadrature Encoder Pulse Module 
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_EQEP_H
#define DSP2833x_EQEP_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Capture decoder control register bit definitions */                                    
struct QDECCTL_BITS {         // bits   description
   uint16 rsvd1:5;            // 4:0    reserved
   uint16 QSP:1;              // 5      QEPS input polarity
   uint16 QIP:1;              // 6      QEPI input polarity
   uint16 QBP:1;              // 7      QEPB input polarity
   uint16 QAP:1;              // 8      QEPA input polarity
   uint16 IGATE:1;            // 9      Index pulse gating option
   uint16 SWAP:1;             // 10     CLK/DIR signal source for Position Counter
   uint16 XCR:1;              // 11     External clock rate
   uint16 SPSEL:1;            // 12     Sync output pin select
   uint16 SOEN:1;             // 13     Enable position compare sync
   uint16 QSRC:2;             // 15:14  Position counter source
};

union QDECCTL_REG {
   uint16              all;
   struct QDECCTL_BITS   bit;
};


//----------------------------------------------------
// QEP control register bit definitions */                                    
struct QEPCTL_BITS {           // bits   description
   uint16 WDE:1;               // 0      QEP watchdog enable
   uint16 UTE:1;               // 1      QEP unit timer enable
   uint16 QCLM:1;              // 2      QEP capture latch mode
   uint16 QPEN:1;              // 3      Quadrature position counter enable
   uint16 IEL:2;               // 5:4    Index event latch
   uint16 SEL:1;               // 6      Strobe event latch
   uint16 SWI:1;               // 7      Software init position counter
   uint16 IEI:2;               // 9:8    Index event init of position count
   uint16 SEI:2;               // 11:10  Strobe event init
   uint16 PCRM:2;              // 13:12  Position counter reset
   uint16 FREE_SOFT:2;         // 15:14  Emulation mode
};

union QEPCTL_REG {
   uint16               all;
   struct QEPCTL_BITS   bit;
};         


//----------------------------------------------------
// Quadrature capture control register bit definitions */                                    
struct QCAPCTL_BITS {          // bits   description
   uint16 UPPS:4;              // 3:0    Unit position pre-scale         
   uint16 CCPS:3;              // 6:4    QEP capture timer pre-scale
   uint16 rsvd1:8;             // 14:7   reserved
   uint16 CEN:1;               // 15     Enable QEP capture
};


union QCAPCTL_REG {
   uint16               all;
   struct QCAPCTL_BITS  bit;
}; 



//----------------------------------------------------
// Position compare control register bit definitions */                                    
struct QPOSCTL_BITS {          // bits   description
   uint16 PCSPW:12;            // 11:0   Position compare sync pulse width
   uint16 PCE:1;               // 12     Position compare enable/disable
   uint16 PCPOL:1;             // 13     Polarity of sync output
   uint16 PCLOAD:1;            // 14     Position compare of shadow load
   uint16 PCSHDW:1;            // 15     Position compare shadow enable
};

union QPOSCTL_REG {
   uint16               all;
   struct QPOSCTL_BITS  bit;
};         

//----------------------------------------------------
// QEP interrupt control register bit definitions */                                    
struct QEINT_BITS {          // bits   description
   uint16 rsvd1:1;           // 0      reserved
   uint16 PCE:1;             // 1      Position counter error
   uint16 QPE:1;             // 2      Quadrature phase error
   uint16 QDC:1;             // 3      Quadrature dir change
   uint16 WTO:1;             // 4      Watchdog timeout
   uint16 PCU:1;             // 5      Position counter underflow
   uint16 PCO:1;             // 6      Position counter overflow
   uint16 PCR:1;             // 7      Position compare ready
   uint16 PCM:1;             // 8      Position compare match
   uint16 SEL:1;             // 9      Strobe event latch
   uint16 IEL:1;             // 10     Event latch
   uint16 UTO:1;             // 11     Unit timeout
   uint16 rsvd2:4;           // 15:12  reserved
};


union QEINT_REG {
   uint16               all;
   struct QEINT_BITS    bit;
};


//----------------------------------------------------
// QEP interrupt status register bit definitions */                                    
struct QFLG_BITS {          // bits   description
   uint16 INT:1;            // 0      Global interrupt 
   uint16 PCE:1;            // 1      Position counter error
   uint16 PHE:1;            // 2      Quadrature phase error
   uint16 QDC:1;            // 3      Quadrature dir change
   uint16 WTO:1;            // 4      Watchdog timeout
   uint16 PCU:1;            // 5      Position counter underflow
   uint16 PCO:1;            // 6      Position counter overflow
   uint16 PCR:1;            // 7      Position compare ready
   uint16 PCM:1;            // 8      Position compare match
   uint16 SEL:1;            // 9      Strobe event latch
   uint16 IEL:1;            // 10     Event latch
   uint16 UTO:1;            // 11     Unit timeout
   uint16 rsvd2:4;          // 15:12  reserved
};


union QFLG_REG {
   uint16               all;
   struct QFLG_BITS     bit;
};

//----------------------------------------------------
// QEP interrupt force register bit definitions */                                    
struct QFRC_BITS {          // bits   description
   uint16 reserved:1;       // 0      Reserved
   uint16 PCE:1;            // 1      Position counter error
   uint16 PHE:1;            // 2      Quadrature phase error
   uint16 QDC:1;            // 3      Quadrature dir change
   uint16 WTO:1;            // 4      Watchdog timeout
   uint16 PCU:1;            // 5      Position counter underflow
   uint16 PCO:1;            // 6      Position counter overflow
   uint16 PCR:1;            // 7      Position compare ready
   uint16 PCM:1;            // 8      Position compare match
   uint16 SEL:1;            // 9      Strobe event latch
   uint16 IEL:1;            // 10     Event latch
   uint16 UTO:1;            // 11     Unit timeout
   uint16 rsvd2:4;          // 15:12  reserved
};


union QFRC_REG {
   uint16               all;
   struct QFRC_BITS     bit;
};

// V1.1 Added UPEVNT (bit 7) This reflects changes 
// made as of F2833x Rev A devices
//----------------------------------------------------
// QEP status register bit definitions */                                    
struct QEPSTS_BITS {          // bits   description
   uint16 PCEF:1;             // 0      Position counter error
   uint16 FIMF:1;             // 1      First index marker
   uint16 CDEF:1;             // 2      Capture direction error
   uint16 COEF:1;             // 3      Capture overflow error
   uint16 QDLF:1;             // 4      QEP direction latch
   uint16 QDF:1;              // 5      Quadrature direction
   uint16 FIDF:1;             // 6      Direction on first index marker
   uint16 UPEVNT:1;           // 7      Unit position event flag
   uint16 rsvd1:8;            // 15:8   reserved
};

union QEPSTS_REG {
   uint16               all;
   struct QEPSTS_BITS   bit;
};

//----------------------------------------------------

struct EQEP_REGS {
   uint32              QPOSCNT;   // Position counter 
   uint32              QPOSINIT;  // Position counter init
   uint32              QPOSMAX;   // Maximum position count
   uint32              QPOSCMP;   // Position compare
   uint32              QPOSILAT;  // Index position latch
   uint32              QPOSSLAT;  // Strobe position latch
   uint32              QPOSLAT;   // Position latch
   uint32              QUTMR;     // Unit timer
   uint32              QUPRD;     // Unit period
   uint16              QWDTMR;    // QEP watchdog timer
   uint16              QWDPRD;    // QEP watchdog period
   union  QDECCTL_REG  QDECCTL;   // Quadrature decoder control
   union  QEPCTL_REG   QEPCTL;    // QEP control 
   union  QCAPCTL_REG  QCAPCTL;   // Quadrature capture control     
   union  QPOSCTL_REG  QPOSCTL;   // Position compare control
   union  QEINT_REG    QEINT;     // QEP interrupt control        
   union  QFLG_REG     QFLG;      // QEP interrupt flag
   union  QFLG_REG     QCLR;      // QEP interrupt clear                   
   union  QFRC_REG     QFRC;      // QEP interrupt force                   
   union  QEPSTS_REG   QEPSTS;    // QEP status
   uint16              QCTMR;     // QEP capture timer
   uint16              QCPRD;     // QEP capture period
   uint16              QCTMRLAT;  // QEP capture latch
   uint16              QCPRDLAT;  // QEP capture period latch
   uint16              rsvd1[30]; // reserved
};

    
 

//---------------------------------------------------------------------------
// GPI/O External References & Function Declarations:
//
extern volatile struct EQEP_REGS EQep1Regs;
extern volatile struct EQEP_REGS EQep2Regs;



#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_EQEP_H definition

//===========================================================================
// End of file.
//===========================================================================

/* EOF */
