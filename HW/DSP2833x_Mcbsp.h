/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_Mcbsp.h                                              **
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
// TI File $Revision: /main/5 $
// Checkin $Date: May 14, 2008   16:30:31 $
//###########################################################################
//
// FILE:   DSP2833x_Mcbsp.h
//
// TITLE:  DSP2833x Device McBSP Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_MCBSP_H
#define DSP2833x_MCBSP_H

#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// McBSP Individual Register Bit Definitions:
//
// McBSP DRR2 register bit definitions:
struct  DRR2_BITS {       // bit   description
   uint16     HWLB:8;     // 16:23 High word low byte
   uint16     HWHB:8;     // 24:31 High word high byte
};

union DRR2_REG {
   uint16            all;
   struct DRR2_BITS  bit;
};

// McBSP DRR1 register bit definitions:
struct  DRR1_BITS {       // bit   description
   uint16     LWLB:8;     // 16:23 Low word low byte
   uint16     LWHB:8;     // 24:31 low word high byte
};

union DRR1_REG {
   uint16            all;
   struct DRR1_BITS  bit;
};

// McBSP DXR2 register bit definitions:
struct  DXR2_BITS {       // bit   description
   uint16     HWLB:8;     // 16:23 High word low byte
   uint16     HWHB:8;     // 24:31 High word high byte
};

union DXR2_REG {
   uint16            all;
   struct DXR2_BITS  bit;
};

// McBSP DXR1 register bit definitions:
struct  DXR1_BITS {       // bit   description
   uint16     LWLB:8;     // 16:23 Low word low byte
   uint16     LWHB:8;     // 24:31 low word high byte
};

union DXR1_REG {
   uint16              all;
   struct DXR1_BITS  bit;
};

// SPCR2 control register bit definitions:
struct  SPCR2_BITS {       // bit   description
   uint16     XRST:1;      // 0     transmit reset
   uint16     XRDY:1;      // 1     transmit ready
   uint16     XEMPTY:1;    // 2     Transmit empty
   uint16     XSYNCERR:1;  // 3     Transmit syn errorINT flag
   uint16     XINTM:2;     // 5:4   Transmit interrupt types
   uint16     GRST:1;      // 6     CLKG reset
   uint16     FRST:1;      // 7     Frame sync reset
   uint16     SOFT:1;      // 8     SOFT bit
   uint16     FREE:1;      // 9     FREE bit
   uint16     rsvd:6;      // 15:10 reserved
};

union SPCR2_REG {
   uint16               all;
   struct SPCR2_BITS  bit;
};

// SPCR1 control register bit definitions:
struct  SPCR1_BITS {       // bit   description
   uint16     RRST:1;      // 0     Receive reset
   uint16     RRDY:1;      // 1     Receive  ready
   uint16     RFULL:1;     // 2     Receive  full
   uint16     RSYNCERR:1;  // 7     Receive  syn error
   uint16     RINTM:2;     // 5:4   Receive  interrupt types
   uint16     ABIS:1;      // 6     ABIS mode select
   uint16     DXENA:1;     // 7     DX hi-z enable
   uint16     rsvd:3;      // 10:8  reserved
   uint16     CLKSTP:2;    // 12:11 CLKSTOP mode bit
   uint16     RJUST:2;     // 13:14 Right justified
   uint16     DLB:1;       // 15    Digital loop back
};

union SPCR1_REG {
   uint16              all;
   struct SPCR1_BITS bit;
};

// RCR2 control register bit definitions:
struct  RCR2_BITS {         // bit    description
   uint16     RDATDLY:2;    // 1:0    Receive data delay
   uint16     RFIG:1;       // 2      Receive  frame sync ignore
   uint16     RCOMPAND:2;   // 4:3    Receive  Companding Mode selects
   uint16     RWDLEN2:3;    // 7:5    Receive  word length
   uint16     RFRLEN2:7;    // 14:8   Receive  Frame sync
   uint16     RPHASE:1;     // 15     Receive Phase
};

union RCR2_REG {
   uint16           all;
   struct RCR2_BITS bit;
};

// RCR1 control register bit definitions:
struct  RCR1_BITS {         // bit   description
   uint16     rsvd1:5;      // 4:0   reserved
   uint16     RWDLEN1:3;    // 7:5   Receive word length
   uint16     RFRLEN1:7;    // 14:8  Receive frame length
   uint16     rsvd2:1;      // 15    reserved
};

union RCR1_REG {
   uint16           all;
   struct RCR1_BITS bit;
};

// XCR2 control register bit definitions:

struct  XCR2_BITS {         // bit    description
   uint16     XDATDLY:2;    // 1:0    Transmit data delay
   uint16     XFIG:1;       // 2      Transmit frame sync ignore
   uint16     XCOMPAND:2;   // 4:3    Transmit Companding Mode selects
   uint16     XWDLEN2:3;    // 7:5    Transmit  word length
   uint16     XFRLEN2:7;    // 14:8   Transmit  Frame sync
   uint16     XPHASE:1;     // 15     Transmit Phase
};

union XCR2_REG {
   uint16           all;
   struct XCR2_BITS bit;
};

// XCR1 control register bit definitions:
struct  XCR1_BITS {         // bit   description
   uint16     rsvd1:5;      // 4:0   reserved
   uint16     XWDLEN1:3;    // 7:5   Transmit word length
   uint16     XFRLEN1:7;    // 14:8  Transmit frame length
   uint16     rsvd2:1;      // 15    reserved
};

union XCR1_REG {
   uint16             all;
   struct XCR1_BITS bit;
};

// SRGR2 Sample rate generator control register bit definitions:
struct  SRGR2_BITS {        // bit  description
   uint16     FPER:12;      // 11:0 Frame period
   uint16     FSGM:1;       // 12   Frame sync generator mode
   uint16     CLKSM:1;      // 13   Sample rate generator mode
   uint16     rsvd:1;       // 14   reserved
   uint16     GSYNC:1;      // 15   CLKG sync
};

union  SRGR2_REG {
   uint16              all;
   struct  SRGR2_BITS  bit;
};

// SRGR1 control register bit definitions:
struct  SRGR1_BITS {        // bit   description
   uint16     CLKGDV:8;     // 7:0   CLKG divider
   uint16     FWID:8;       // 15:8  Frame width
};

union  SRGR1_REG {
   uint16              all;
   struct  SRGR1_BITS  bit;
};

// MCR2 Multichannel control register bit definitions:
struct  MCR2_BITS {         // bit   description
   uint16     XMCM:2;       // 1:0   Transmit multichannel mode
   uint16     XCBLK:3;      // 2:4   Transmit current block
   uint16     XPABLK:2;     // 5:6   Transmit partition A Block
   uint16     XPBBLK:2;     // 7:8   Transmit partition B Block
   uint16     XMCME:1;      // 9     Transmit multi-channel enhance mode
   uint16     rsvd:6;       // 15:10 reserved
};

union  MCR2_REG {
   uint16             all;
   struct  MCR2_BITS  bit;
};

// MCR1 Multichannel control register bit definitions:
struct  MCR1_BITS {         // bit   description
   uint16     RMCM:1;       // 0     Receive multichannel mode
   uint16     rsvd:1;       // 1     reserved
   uint16     RCBLK:3;      // 4:2   Receive current block
   uint16     RPABLK:2;     // 6:5   Receive partition A Block
   uint16     RPBBLK:2;     // 7:8   Receive partition B Block
   uint16     RMCME:1;      // 9     Receive multi-channel enhance mode
   uint16     rsvd1:6;      // 15:10 reserved
};

union  MCR1_REG {
   uint16             all;
   struct  MCR1_BITS  bit;
};

// RCERA control register bit definitions:
struct  RCERA_BITS {         // bit description
   uint16     RCEA0:1;       // 0   Receive Channel enable bit
   uint16     RCEA1:1;       // 1   Receive Channel enable bit
   uint16     RCEA2:1;       // 2   Receive Channel enable bit
   uint16     RCEA3:1;       // 3   Receive Channel enable bit
   uint16     RCEA4:1;       // 4   Receive Channel enable bit
   uint16     RCEA5:1;       // 5   Receive Channel enable bit
   uint16     RCEA6:1;       // 6   Receive Channel enable bit
   uint16     RCEA7:1;       // 7   Receive Channel enable bit
   uint16     RCEA8:1;       // 8   Receive Channel enable bit
   uint16     RCEA9:1;       // 9   Receive Channel enable bit
   uint16     RCEA10:1;      // 10  Receive Channel enable bit
   uint16     RCEA11:1;      // 11  Receive Channel enable bit
   uint16     RCEA12:1;      // 12  Receive Channel enable bit
   uint16     RCEA13:1;      // 13  Receive Channel enable bit
   uint16     RCEA14:1;      // 14  Receive Channel enable bit
   uint16     RCEA15:1;      // 15  Receive Channel enable bit
};

union RCERA_REG {
   uint16              all;
   struct  RCERA_BITS  bit;
};

// RCERB control register bit definitions:
struct  RCERB_BITS {         // bit description
   uint16     RCEB0:1;       // 0   Receive Channel enable bit
   uint16     RCEB1:1;       // 1   Receive Channel enable bit
   uint16     RCEB2:1;       // 2   Receive Channel enable bit
   uint16     RCEB3:1;       // 3   Receive Channel enable bit
   uint16     RCEB4:1;       // 4   Receive Channel enable bit
   uint16     RCEB5:1;       // 5   Receive Channel enable bit
   uint16     RCEB6:1;       // 6   Receive Channel enable bit
   uint16     RCEB7:1;       // 7   Receive Channel enable bit
   uint16     RCEB8:1;       // 8   Receive Channel enable bit
   uint16     RCEB9:1;       // 9   Receive Channel enable bit
   uint16     RCEB10:1;      // 10  Receive Channel enable bit
   uint16     RCEB11:1;      // 11  Receive Channel enable bit
   uint16     RCEB12:1;      // 12  Receive Channel enable bit
   uint16     RCEB13:1;      // 13  Receive Channel enable bit
   uint16     RCEB14:1;      // 14  Receive Channel enable bit
   uint16     RCEB15:1;      // 15  Receive Channel enable bit
};

union RCERB_REG {
   uint16              all;
   struct  RCERB_BITS  bit;
};

// XCERA control register bit definitions:
struct  XCERA_BITS {         // bit description
   uint16     XCERA0:1;       // 0   Receive Channel enable bit
   uint16     XCERA1:1;       // 1   Receive Channel enable bit
   uint16     XCERA2:1;       // 2   Receive Channel enable bit
   uint16     XCERA3:1;       // 3   Receive Channel enable bit
   uint16     XCERA4:1;       // 4   Receive Channel enable bit
   uint16     XCERA5:1;       // 5   Receive Channel enable bit
   uint16     XCERA6:1;       // 6   Receive Channel enable bit
   uint16     XCERA7:1;       // 7   Receive Channel enable bit
   uint16     XCERA8:1;       // 8   Receive Channel enable bit
   uint16     XCERA9:1;       // 9   Receive Channel enable bit
   uint16     XCERA10:1;      // 10  Receive Channel enable bit
   uint16     XCERA11:1;      // 11  Receive Channel enable bit
   uint16     XCERA12:1;      // 12  Receive Channel enable bit
   uint16     XCERA13:1;      // 13  Receive Channel enable bit
   uint16     XCERA14:1;      // 14  Receive Channel enable bit
   uint16     XCERA15:1;      // 15  Receive Channel enable bit
};

union XCERA_REG {
   uint16              all;
   struct  XCERA_BITS  bit;
};

// XCERB control register bit definitions:
struct  XCERB_BITS {         // bit description
   uint16     XCERB0:1;       // 0   Receive Channel enable bit
   uint16     XCERB1:1;       // 1   Receive Channel enable bit
   uint16     XCERB2:1;       // 2   Receive Channel enable bit
   uint16     XCERB3:1;       // 3   Receive Channel enable bit
   uint16     XCERB4:1;       // 4   Receive Channel enable bit
   uint16     XCERB5:1;       // 5   Receive Channel enable bit
   uint16     XCERB6:1;       // 6   Receive Channel enable bit
   uint16     XCERB7:1;       // 7   Receive Channel enable bit
   uint16     XCERB8:1;       // 8   Receive Channel enable bit
   uint16     XCERB9:1;       // 9   Receive Channel enable bit
   uint16     XCERB10:1;      // 10  Receive Channel enable bit
   uint16     XCERB11:1;      // 11  Receive Channel enable bit
   uint16     XCERB12:1;      // 12  Receive Channel enable bit
   uint16     XCERB13:1;      // 13  Receive Channel enable bit
   uint16     XCERB14:1;      // 14  Receive Channel enable bit
   uint16     XCERB15:1;      // 15  Receive Channel enable bit
};

union XCERB_REG {
   uint16              all;
   struct  XCERB_BITS  bit;
};

// PCR control register bit definitions:
struct  PCR_BITS {          // bit description
   uint16     CLKRP:1;       // 0   Receive Clock polarity
   uint16     CLKXP:1;       // 1   Transmit clock polarity
   uint16     FSRP:1;        // 2   Receive Frame synchronization polarity
   uint16     FSXP:1;        // 3   Transmit Frame synchronization polarity
   uint16     DR_STAT:1;     // 4   DR pin status - reserved for this McBSP
   uint16     DX_STAT:1;     // 5   DX pin status - reserved for this McBSP
   uint16     CLKS_STAT:1;   // 6   CLKS pin status - reserved for 28x -McBSP
   uint16     SCLKME:1;      // 7   Enhanced sample clock mode selection bit.
   uint16     CLKRM:1;       // 8   Receiver Clock Mode
   uint16     CLKXM:1;       // 9   Transmitter Clock Mode.
   uint16     FSRM:1;        // 10  Receive Frame Synchronization Mode
   uint16     FSXM:1;        // 11  Transmit Frame Synchronization Mode
   uint16     RIOEN:1;       // 12  General Purpose I/O Mode - reserved in this 28x-McBSP
   uint16     XIOEN:1;       // 13  General Purpose I/O Mode - reserved in this 28x-McBSP
   uint16     IDEL_EN:1;     // 14  reserved in this 28x-McBSP
   uint16     rsvd:1  ;      // 15  reserved
};

union PCR_REG {
   uint16            all;
   struct  PCR_BITS  bit;
};

// RCERC control register bit definitions:
struct  RCERC_BITS {         // bit description
   uint16     RCEC0:1;       // 0   Receive Channel enable bit
   uint16     RCEC1:1;       // 1   Receive Channel enable bit
   uint16     RCEC2:1;       // 2   Receive Channel enable bit
   uint16     RCEC3:1;       // 3   Receive Channel enable bit
   uint16     RCEC4:1;       // 4   Receive Channel enable bit
   uint16     RCEC5:1;       // 5   Receive Channel enable bit
   uint16     RCEC6:1;       // 6   Receive Channel enable bit
   uint16     RCEC7:1;       // 7   Receive Channel enable bit
   uint16     RCEC8:1;       // 8   Receive Channel enable bit
   uint16     RCEC9:1;       // 9   Receive Channel enable bit
   uint16     RCEC10:1;      // 10  Receive Channel enable bit
   uint16     RCEC11:1;      // 11  Receive Channel enable bit
   uint16     RCEC12:1;      // 12  Receive Channel enable bit
   uint16     RCEC13:1;      // 13  Receive Channel enable bit
   uint16     RCEC14:1;      // 14  Receive Channel enable bit
   uint16     RCEC15:1;      // 15  Receive Channel enable bit
};

union RCERC_REG {
   uint16              all;
   struct  RCERC_BITS  bit;
};

// RCERD control register bit definitions:
struct  RCERD_BITS {         // bit description
   uint16     RCED0:1;       // 0   Receive Channel enable bit
   uint16     RCED1:1;       // 1   Receive Channel enable bit
   uint16     RCED2:1;       // 2   Receive Channel enable bit
   uint16     RCED3:1;       // 3   Receive Channel enable bit
   uint16     RCED4:1;       // 4   Receive Channel enable bit
   uint16     RCED5:1;       // 5   Receive Channel enable bit
   uint16     RCED6:1;       // 6   Receive Channel enable bit
   uint16     RCED7:1;       // 7   Receive Channel enable bit
   uint16     RCED8:1;       // 8   Receive Channel enable bit
   uint16     RCED9:1;       // 9   Receive Channel enable bit
   uint16     RCED10:1;      // 10  Receive Channel enable bit
   uint16     RCED11:1;      // 11  Receive Channel enable bit
   uint16     RCED12:1;      // 12  Receive Channel enable bit
   uint16     RCED13:1;      // 13  Receive Channel enable bit
   uint16     RCED14:1;      // 14  Receive Channel enable bit
   uint16     RCED15:1;      // 15  Receive Channel enable bit
};

union RCERD_REG {
   uint16              all;
   struct  RCERD_BITS  bit;
};

// XCERC control register bit definitions:
struct  XCERC_BITS {         // bit description
   uint16     XCERC0:1;       // 0   Receive Channel enable bit
   uint16     XCERC1:1;       // 1   Receive Channel enable bit
   uint16     XCERC2:1;       // 2   Receive Channel enable bit
   uint16     XCERC3:1;       // 3   Receive Channel enable bit
   uint16     XCERC4:1;       // 4   Receive Channel enable bit
   uint16     XCERC5:1;       // 5   Receive Channel enable bit
   uint16     XCERC6:1;       // 6   Receive Channel enable bit
   uint16     XCERC7:1;       // 7   Receive Channel enable bit
   uint16     XCERC8:1;       // 8   Receive Channel enable bit
   uint16     XCERC9:1;       // 9   Receive Channel enable bit
   uint16     XCERC10:1;      // 10  Receive Channel enable bit
   uint16     XCERC11:1;      // 11  Receive Channel enable bit
   uint16     XCERC12:1;      // 12  Receive Channel enable bit
   uint16     XCERC13:1;      // 13  Receive Channel enable bit
   uint16     XCERC14:1;      // 14  Receive Channel enable bit
   uint16     XCERC15:1;      // 15  Receive Channel enable bit
};

union XCERC_REG {
   uint16              all;
   struct  XCERC_BITS  bit;
};

// XCERD control register bit definitions:
struct  XCERD_BITS {         // bit description
   uint16     XCERD0:1;       // 0   Receive Channel enable bit
   uint16     XCERD1:1;       // 1   Receive Channel enable bit
   uint16     XCERD2:1;       // 2   Receive Channel enable bit
   uint16     XCERD3:1;       // 3   Receive Channel enable bit
   uint16     XCERD4:1;       // 4   Receive Channel enable bit
   uint16     XCERD5:1;       // 5   Receive Channel enable bit
   uint16     XCERD6:1;       // 6   Receive Channel enable bit
   uint16     XCERD7:1;       // 7   Receive Channel enable bit
   uint16     XCERD8:1;       // 8   Receive Channel enable bit
   uint16     XCERD9:1;       // 9   Receive Channel enable bit
   uint16     XCERD10:1;      // 10  Receive Channel enable bit
   uint16     XCERD11:1;      // 11  Receive Channel enable bit
   uint16     XCERD12:1;      // 12  Receive Channel enable bit
   uint16     XCERD13:1;      // 13  Receive Channel enable bit
   uint16     XCERD14:1;      // 14  Receive Channel enable bit
   uint16     XCERD15:1;      // 15  Receive Channel enable bit
};

union XCERD_REG {
   uint16              all;
   struct  XCERD_BITS  bit;
};

// RCERE control register bit definitions:
struct  RCERE_BITS {         // bit description
   uint16     RCEE0:1;       // 0   Receive Channel enable bit
   uint16     RCEE1:1;       // 1   Receive Channel enable bit
   uint16     RCEE2:1;       // 2   Receive Channel enable bit
   uint16     RCEE3:1;       // 3   Receive Channel enable bit
   uint16     RCEE4:1;       // 4   Receive Channel enable bit
   uint16     RCEE5:1;       // 5   Receive Channel enable bit
   uint16     RCEE6:1;       // 6   Receive Channel enable bit
   uint16     RCEE7:1;       // 7   Receive Channel enable bit
   uint16     RCEE8:1;       // 8   Receive Channel enable bit
   uint16     RCEE9:1;       // 9   Receive Channel enable bit
   uint16     RCEE10:1;      // 10  Receive Channel enable bit
   uint16     RCEE11:1;      // 11  Receive Channel enable bit
   uint16     RCEE12:1;      // 12  Receive Channel enable bit
   uint16     RCEE13:1;      // 13  Receive Channel enable bit
   uint16     RCEE14:1;      // 14  Receive Channel enable bit
   uint16     RCEE15:1;      // 15  Receive Channel enable bit
};

union RCERE_REG {
   uint16              all;
   struct  RCERE_BITS  bit;
};

// RCERF control register bit definitions:
struct  RCERF_BITS {         // bit   description
   uint16     RCEF0:1;       // 0   Receive Channel enable bit
   uint16     RCEF1:1;       // 1   Receive Channel enable bit
   uint16     RCEF2:1;       // 2   Receive Channel enable bit
   uint16     RCEF3:1;       // 3   Receive Channel enable bit
   uint16     RCEF4:1;       // 4   Receive Channel enable bit
   uint16     RCEF5:1;       // 5   Receive Channel enable bit
   uint16     RCEF6:1;       // 6   Receive Channel enable bit
   uint16     RCEF7:1;       // 7   Receive Channel enable bit
   uint16     RCEF8:1;       // 8   Receive Channel enable bit
   uint16     RCEF9:1;       // 9   Receive Channel enable bit
   uint16     RCEF10:1;      // 10  Receive Channel enable bit
   uint16     RCEF11:1;      // 11  Receive Channel enable bit
   uint16     RCEF12:1;      // 12  Receive Channel enable bit
   uint16     RCEF13:1;      // 13  Receive Channel enable bit
   uint16     RCEF14:1;      // 14  Receive Channel enable bit
   uint16     RCEF15:1;      // 15  Receive Channel enable bit
};

union RCERF_REG {
   uint16              all;
   struct  RCERF_BITS  bit;
};

// XCERE control register bit definitions:
struct  XCERE_BITS {         // bit description
   uint16     XCERE0:1;       // 0   Receive Channel enable bit
   uint16     XCERE1:1;       // 1   Receive Channel enable bit
   uint16     XCERE2:1;       // 2   Receive Channel enable bit
   uint16     XCERE3:1;       // 3   Receive Channel enable bit
   uint16     XCERE4:1;       // 4   Receive Channel enable bit
   uint16     XCERE5:1;       // 5   Receive Channel enable bit
   uint16     XCERE6:1;       // 6   Receive Channel enable bit
   uint16     XCERE7:1;       // 7   Receive Channel enable bit
   uint16     XCERE8:1;       // 8   Receive Channel enable bit
   uint16     XCERE9:1;       // 9   Receive Channel enable bit
   uint16     XCERE10:1;      // 10  Receive Channel enable bit
   uint16     XCERE11:1;      // 11  Receive Channel enable bit
   uint16     XCERE12:1;      // 12  Receive Channel enable bit
   uint16     XCERE13:1;      // 13  Receive Channel enable bit
   uint16     XCERE14:1;      // 14  Receive Channel enable bit
   uint16     XCERE15:1;      // 15  Receive Channel enable bit
};

union XCERE_REG {
   uint16              all;
   struct  XCERE_BITS  bit;
};

// XCERF control register bit definitions:
struct  XCERF_BITS {         // bit description
   uint16     XCERF0:1;       // 0   Receive Channel enable bit
   uint16     XCERF1:1;       // 1   Receive Channel enable bit
   uint16     XCERF2:1;       // 2   Receive Channel enable bit
   uint16     XCERF3:1;       // 3   Receive Channel enable bit
   uint16     XCERF4:1;       // 4   Receive Channel enable bit
   uint16     XCERF5:1;       // 5   Receive Channel enable bit
   uint16     XCERF6:1;       // 6   Receive Channel enable bit
   uint16     XCERF7:1;       // 7   Receive Channel enable bit
   uint16     XCERF8:1;       // 8   Receive Channel enable bit
   uint16     XCERF9:1;       // 9   Receive Channel enable bit
   uint16     XCERF10:1;      // 10  Receive Channel enable bit
   uint16     XCERF11:1;      // 11  Receive Channel enable bit
   uint16     XCERF12:1;      // 12  Receive Channel enable bit
   uint16     XCERF13:1;      // 13  Receive Channel enable bit
   uint16     XCERF14:1;      // 14  Receive Channel enable bit
   uint16     XCERF15:1;      // 15  Receive Channel enable bit
};

union XCERF_REG {
   uint16              all;
   struct  XCERF_BITS  bit;
};

// RCERG control register bit definitions:
struct  RCERG_BITS {         // bit description
   uint16     RCEG0:1;       // 0   Receive Channel enable bit
   uint16     RCEG1:1;       // 1   Receive Channel enable bit
   uint16     RCEG2:1;       // 2   Receive Channel enable bit
   uint16     RCEG3:1;       // 3   Receive Channel enable bit
   uint16     RCEG4:1;       // 4   Receive Channel enable bit
   uint16     RCEG5:1;       // 5   Receive Channel enable bit
   uint16     RCEG6:1;       // 6   Receive Channel enable bit
   uint16     RCEG7:1;       // 7   Receive Channel enable bit
   uint16     RCEG8:1;       // 8   Receive Channel enable bit
   uint16     RCEG9:1;       // 9   Receive Channel enable bit
   uint16     RCEG10:1;      // 10  Receive Channel enable bit
   uint16     RCEG11:1;      // 11  Receive Channel enable bit
   uint16     RCEG12:1;      // 12  Receive Channel enable bit
   uint16     RCEG13:1;      // 13  Receive Channel enable bit
   uint16     RCEG14:1;      // 14  Receive Channel enable bit
   uint16     RCEG15:1;      // 15  Receive Channel enable bit
};

union RCERG_REG {
   uint16              all;
   struct  RCERG_BITS  bit;
};

// RCERH control register bit definitions:
struct  RCERH_BITS {         // bit description
   uint16     RCEH0:1;       // 0   Receive Channel enable bit
   uint16     RCEH1:1;       // 1   Receive Channel enable bit
   uint16     RCEH2:1;       // 2   Receive Channel enable bit
   uint16     RCEH3:1;       // 3   Receive Channel enable bit
   uint16     RCEH4:1;       // 4   Receive Channel enable bit
   uint16     RCEH5:1;       // 5   Receive Channel enable bit
   uint16     RCEH6:1;       // 6   Receive Channel enable bit
   uint16     RCEH7:1;       // 7   Receive Channel enable bit
   uint16     RCEH8:1;       // 8   Receive Channel enable bit
   uint16     RCEH9:1;       // 9   Receive Channel enable bit
   uint16     RCEH10:1;      // 10  Receive Channel enable bit
   uint16     RCEH11:1;      // 11  Receive Channel enable bit
   uint16     RCEH12:1;      // 12  Receive Channel enable bit
   uint16     RCEH13:1;      // 13  Receive Channel enable bit
   uint16     RCEH14:1;      // 14  Receive Channel enable bit
   uint16     RCEH15:1;      // 15  Receive Channel enable bit
};

union RCERH_REG {
   uint16              all;
   struct  RCERH_BITS  bit;
};

// XCERG control register bit definitions:
struct  XCERG_BITS {         // bit description
   uint16     XCERG0:1;       // 0   Receive Channel enable bit
   uint16     XCERG1:1;       // 1   Receive Channel enable bit
   uint16     XCERG2:1;       // 2   Receive Channel enable bit
   uint16     XCERG3:1;       // 3   Receive Channel enable bit
   uint16     XCERG4:1;       // 4   Receive Channel enable bit
   uint16     XCERG5:1;       // 5   Receive Channel enable bit
   uint16     XCERG6:1;       // 6   Receive Channel enable bit
   uint16     XCERG7:1;       // 7   Receive Channel enable bit
   uint16     XCERG8:1;       // 8   Receive Channel enable bit
   uint16     XCERG9:1;       // 9   Receive Channel enable bit
   uint16     XCERG10:1;      // 10  Receive Channel enable bit
   uint16     XCERG11:1;      // 11  Receive Channel enable bit
   uint16     XCERG12:1;      // 12  Receive Channel enable bit
   uint16     XCERG13:1;      // 13  Receive Channel enable bit
   uint16     XCERG14:1;      // 14  Receive Channel enable bit
   uint16     XCERG15:1;      // 15  Receive Channel enable bit
};

union XCERG_REG {
   uint16              all;
   struct  XCERG_BITS  bit;
};

// XCERH control register bit definitions:
struct  XCERH_BITS {         // bit description
   uint16     XCEH0:1;       // 0   Receive Channel enable bit
   uint16     XCEH1:1;       // 1   Receive Channel enable bit
   uint16     XCEH2:1;       // 2   Receive Channel enable bit
   uint16     XCEH3:1;       // 3   Receive Channel enable bit
   uint16     XCEH4:1;       // 4   Receive Channel enable bit
   uint16     XCEH5:1;       // 5   Receive Channel enable bit
   uint16     XCEH6:1;       // 6   Receive Channel enable bit
   uint16     XCEH7:1;       // 7   Receive Channel enable bit
   uint16     XCEH8:1;       // 8   Receive Channel enable bit
   uint16     XCEH9:1;       // 9   Receive Channel enable bit
   uint16     XCEH10:1;      // 10  Receive Channel enable bit
   uint16     XCEH11:1;      // 11  Receive Channel enable bit
   uint16     XCEH12:1;      // 12  Receive Channel enable bit
   uint16     XCEH13:1;      // 13  Receive Channel enable bit
   uint16     XCEH14:1;      // 14  Receive Channel enable bit
   uint16     XCEH15:1;      // 15  Receive Channel enable bit
};

union XCERH_REG {
   uint16              all;
   struct  XCERH_BITS  bit;
};


// McBSP Interrupt enable register for RINT/XINT
struct  MFFINT_BITS {       // bits description
    uint16     XINT:1;      // 0    XINT  interrupt enable
    uint16     rsvd1:1;     // 1    reserved
    uint16     RINT:1;      // 2    RINT  interrupt enable
    uint16     rsvd2:13;    // 15:3 reserved
};

union MFFINT_REG {
   uint16              all;
   struct MFFINT_BITS  bit;
};


//---------------------------------------------------------------------------
// McBSP Register File:
//
struct  MCBSP_REGS {
   union DRR2_REG    DRR2;       // MCBSP Data receive register bits 31-16
   union DRR1_REG    DRR1;       // MCBSP Data receive register bits 15-0
   union DXR2_REG    DXR2;       // MCBSP Data transmit register bits 31-16
   union DXR1_REG    DXR1;       // MCBSP Data transmit register bits 15-0
   union SPCR2_REG   SPCR2;      // MCBSP control register bits 31-16
   union SPCR1_REG   SPCR1;      // MCBSP control register bits 15-0
   union RCR2_REG    RCR2;       // MCBSP receive control register bits 31-16
   union RCR1_REG    RCR1;       // MCBSP receive control register bits 15-0
   union XCR2_REG    XCR2;       // MCBSP transmit control register bits 31-16
   union XCR1_REG    XCR1;       // MCBSP transmit control register bits 15-0
   union SRGR2_REG   SRGR2;      // MCBSP sample rate gen register bits 31-16
   union SRGR1_REG   SRGR1;      // MCBSP sample rate gen register bits 15-0
   union MCR2_REG    MCR2;       // MCBSP multichannel register bits 31-16
   union MCR1_REG    MCR1;       // MCBSP multichannel register bits 15-0
   union RCERA_REG   RCERA;      // MCBSP Receive channel enable partition A
   union RCERB_REG   RCERB;      // MCBSP Receive channel enable partition B
   union XCERA_REG   XCERA;      // MCBSP Transmit channel enable partition A
   union XCERB_REG   XCERB;      // MCBSP Transmit channel enable partition B
   union PCR_REG     PCR;        // MCBSP Pin control register bits 15-0
   union RCERC_REG   RCERC;      // MCBSP Receive channel enable partition C
   union RCERD_REG   RCERD;      // MCBSP Receive channel enable partition D
   union XCERC_REG   XCERC;      // MCBSP Transmit channel enable partition C
   union XCERD_REG   XCERD;      // MCBSP Transmit channel enable partition D
   union RCERE_REG   RCERE;      // MCBSP Receive channel enable partition E
   union RCERF_REG   RCERF;      // MCBSP Receive channel enable partition F
   union XCERE_REG   XCERE;      // MCBSP Transmit channel enable partition E
   union XCERF_REG   XCERF;      // MCBSP Transmit channel enable partition F
   union RCERG_REG   RCERG;      // MCBSP Receive channel enable partition G
   union RCERH_REG   RCERH;      // MCBSP Receive channel enable partition H
   union XCERG_REG   XCERG;      // MCBSP Transmit channel enable partition G
   union XCERH_REG   XCERH;      // MCBSP Transmit channel enable partition H
   uint16            rsvd1[4];   // reserved
   union MFFINT_REG  MFFINT;     // MCBSP Interrupt enable register for RINT/XINT
   uint16            rsvd2;      // reserved
};

//---------------------------------------------------------------------------
// McBSP External References & Function Declarations:
//
extern volatile struct MCBSP_REGS McbspaRegs;
extern volatile struct MCBSP_REGS McbspbRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_MCBSP_H definition

//===========================================================================
// No more.
//===========================================================================

/* EOF */
