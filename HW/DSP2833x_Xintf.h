/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_Xintf.h                                              **
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
// TI File $Revision: /main/4 $
// Checkin $Date: July 27, 2009   13:57:25 $
//###########################################################################
//
// FILE:   DSP2833x_Xintf.h
//
// TITLE:  DSP2833x Device External Interface Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_XINTF_H
#define DSP2833x_XINTF_H


#ifdef __cplusplus
extern "C" {
#endif


// XINTF timing register bit definitions:
struct XTIMING_BITS {    // bits  description
   uint16 XWRTRAIL:2;    // 1:0   Write access trail timing
   uint16 XWRACTIVE:3;   // 4:2   Write access active timing
   uint16 XWRLEAD:2;     // 6:5   Write access lead timing
   uint16 XRDTRAIL:2;    // 8:7   Read access trail timing
   uint16 XRDACTIVE:3;   // 11:9  Read access active timing
   uint16 XRDLEAD:2;     // 13:12 Read access lead timing
   uint16 USEREADY:1;    // 14    Extend access using HW waitstates
   uint16 READYMODE:1;   // 15    Ready mode
   uint16 XSIZE:2;       // 17:16 XINTF bus width - must be written as 11b
   uint16 rsvd1:4;       // 21:18 reserved
   uint16 X2TIMING:1;    // 22    Double lead/active/trail timing
   uint16 rsvd3:9;       // 31:23 reserved
};

union XTIMING_REG {
   uint32               all;
   struct XTIMING_BITS  bit;
};

// XINTF control register bit definitions:
struct XINTCNF2_BITS {    // bits  description
   uint16 WRBUFF:2;       // 1:0   Write buffer depth
   uint16 CLKMODE:1;      // 2     Ratio for XCLKOUT with respect to XTIMCLK
   uint16 CLKOFF:1;       // 3     Disable XCLKOUT
   uint16 rsvd1:2;        // 5:4   reserved
   uint16 WLEVEL:2;       // 7:6   Current level of the write buffer
   uint16 rsvd2:1;        // 8     reserved
   uint16 HOLD:1;         // 9     Hold enable/disable
   uint16 HOLDS:1;        // 10    Current state of HOLDn input
   uint16 HOLDAS:1;       // 11    Current state of HOLDAn output
   uint16 rsvd3:4;        // 15:12 reserved
   uint16 XTIMCLK:3;      // 18:16 Ratio for XTIMCLK
   uint16 rsvd4:13;       // 31:19 reserved
};

union XINTCNF2_REG {
   uint32                all;
   struct XINTCNF2_BITS  bit;
};

// XINTF bank switching register bit definitions:
struct XBANK_BITS {      // bits  description
   uint16  BANK:3;       // 2:0   Zone for which banking is enabled
   uint16  BCYC:3;       // 5:3   XTIMCLK cycles to add
   uint16  rsvd:10;      // 15:6  reserved
};

union XBANK_REG {
   uint16             all;
   struct XBANK_BITS  bit;
};

struct XRESET_BITS {
    uint16  XHARDRESET:1;
    uint16  rsvd1:15;
};

union XRESET_REG {
    uint16            all;
    struct XRESET_BITS bit;
};


//---------------------------------------------------------------------------
// XINTF Register File:
//
struct XINTF_REGS {
   union XTIMING_REG XTIMING0;
   uint32  rsvd1[5];
   union XTIMING_REG XTIMING6;
   union XTIMING_REG XTIMING7;
   uint32  rsvd2[2];
   union XINTCNF2_REG XINTCNF2;
   uint32  rsvd3;
   union XBANK_REG    XBANK;
   uint16  rsvd4;
   uint16  XREVISION;
   uint16  rsvd5[2];
   union XRESET_REG   XRESET;
};

//---------------------------------------------------------------------------
// XINTF External References & Function Declarations:
//
extern volatile struct XINTF_REGS XintfRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_XINTF_H definition

//===========================================================================
// No more.
//===========================================================================

/* EOF */
