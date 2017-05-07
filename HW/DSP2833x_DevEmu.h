/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_DevEmu.h                                             **
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
// Checkin $Date: April 15, 2009   10:05:17 $
//###########################################################################
//
// FILE:   DSP2833x_DevEmu.h
//
// TITLE:  DSP2833x Device Emulation Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_DEV_EMU_H
#define DSP2833x_DEV_EMU_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Std_Types.h"
//---------------------------------------------------------------------------
// Device Emulation Register Bit Definitions:
//
// Device Configuration Register Bit Definitions
struct DEVICECNF_BITS  {     // bits  description
   uint16 rsvd1:3;           // 2:0   reserved
   uint16 VMAPS:1;           // 3     VMAP Status
   uint16 rsvd2:1;           // 4     reserved
   uint16 XRSn:1;            // 5     XRSn Signal Status
   uint16 rsvd3:10;          // 15:6
   uint16 rsvd4:3;           // 18:16
   uint16 ENPROT:1;          // 19    Enable/Disable pipeline protection
   uint16 rsvd5:7;           // 26:20 reserved
   uint16 TRSTN:1;           // 27    Status of TRSTn signal
   uint16 rsvd6:4;           // 31:28 reserved
};

union DEVICECNF_REG {
   uint32                 all;
   struct DEVICECNF_BITS  bit;
};

// CLASSID
struct CLASSID_BITS   {  // bits  description
   uint16 CLASSNO:8;     // 7:0   Class Number
   uint16 PARTTYPE:8;    // 15:8  Part Type
};

union CLASSID_REG {
   uint16               all;
   struct CLASSID_BITS  bit;
};

struct DEV_EMU_REGS {
   union DEVICECNF_REG DEVICECNF;  // device configuration
   union CLASSID_REG   CLASSID;    // Class ID
   uint16              REVID;      // Device ID
   uint16              PROTSTART;  // Write-Read protection start
   uint16              PROTRANGE;  // Write-Read protection range
   uint16              rsvd2[202];
};

// PARTID
struct PARTID_BITS   {  // bits  description
   uint16 PARTNO:8;     // 7:0   Part Number
   uint16 PARTTYPE:8;   // 15:8  Part Type
};

union PARTID_REG {
   uint16               all;
   struct PARTID_BITS   bit;
};

struct PARTID_REGS {
   union PARTID_REG PARTID; // Part ID
};



//---------------------------------------------------------------------------
// Device Emulation Register References & Function Declarations:
//
extern volatile struct DEV_EMU_REGS DevEmuRegs;
extern volatile struct PARTID_REGS PartIdRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_DEV_EMU_H definition

//===========================================================================
// End of file.
//===========================================================================

/* EOF */
