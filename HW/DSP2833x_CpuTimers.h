/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_CpuTimers.h                                          **
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
// Checkin $Date: March 20, 2007   15:33:42 $
//###########################################################################
//
// FILE:    DSP2833x_CpuTimers.h
//
// TITLE:   DSP2833x CPU 32-bit Timers Register Definitions.
//
// NOTES:   CpuTimer1 and CpuTimer2 are reserved for use with DSP BIOS and
//          other realtime operating systems.
//
//          Do not use these two timers in your application if you ever plan
//          on integrating DSP-BIOS or another realtime OS.
//
//          For this reason, comment out the code to manipulate these two timers
//          if using DSP-BIOS or another realtime OS.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_CPU_TIMERS_H
#define DSP2833x_CPU_TIMERS_H

#ifdef __cplusplus
extern "C" {
#endif
#include "Std_Types.h"
//---------------------------------------------------------------------------
// CPU Timer Register Bit Definitions:
//
//
// TCR: Control register bit definitions:
struct  TCR_BITS {          // bits  description
   uint16    rsvd1:4;       // 3:0   reserved
   uint16    TSS:1;         // 4     Timer Start/Stop
   uint16    TRB:1;         // 5     Timer reload
   uint16    rsvd2:4;       // 9:6   reserved
   uint16    SOFT:1;        // 10    Emulation modes
   uint16    FREE:1;        // 11
   uint16    rsvd3:2;       // 12:13 reserved
   uint16    TIE:1;         // 14    Output enable
   uint16    TIF:1;         // 15    Interrupt flag
};

union TCR_REG {
   uint16           all;
   struct TCR_BITS  bit;
};

// TPR: Pre-scale low bit definitions:
struct  TPR_BITS {        // bits  description
   uint16     TDDR:8;     // 7:0   Divide-down low
   uint16     PSC:8;      // 15:8  Prescale counter low
};

union TPR_REG {
   uint16           all;
   struct TPR_BITS  bit;
};

// TPRH: Pre-scale high bit definitions:
struct  TPRH_BITS {       // bits  description
   uint16     TDDRH:8;      // 7:0   Divide-down high
   uint16     PSCH:8;       // 15:8  Prescale counter high
};

union TPRH_REG {
   uint16           all;
   struct TPRH_BITS bit;
};

// TIM, TIMH: Timer register definitions:
struct TIM_REG {
   uint16  LSW;
   uint16  MSW;
};

union TIM_GROUP {
   uint32          all;
   struct TIM_REG  half;
};

// PRD, PRDH: Period register definitions:
struct PRD_REG {
   uint16  LSW;
   uint16  MSW;
};

union PRD_GROUP {
   uint32          all;
   struct PRD_REG  half;
};

//---------------------------------------------------------------------------
// CPU Timer Register File:
//
struct CPUTIMER_REGS {
   union TIM_GROUP TIM;   // Timer counter register
   union PRD_GROUP PRD;   // Period register
   union TCR_REG   TCR;   // Timer control register
   uint16          rsvd1; // reserved
   union TPR_REG   TPR;   // Timer pre-scale low
   union TPRH_REG  TPRH;  // Timer pre-scale high
};

//---------------------------------------------------------------------------
// CPU Timer Support Variables:
//
struct CPUTIMER_VARS {
   volatile struct  CPUTIMER_REGS  *RegsAddr;
   uint32    InterruptCount;
   float   CPUFreqInMHz;
   float   PeriodInUSec;
};



extern volatile struct CPUTIMER_REGS CpuTimer0Regs;
extern struct CPUTIMER_VARS CpuTimer0;

// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS. Comment out CpuTimer1 and CpuTimer2 if using DSP BIOS or other RTOS
extern volatile struct CPUTIMER_REGS CpuTimer1Regs;
extern volatile struct CPUTIMER_REGS CpuTimer2Regs;

extern struct CPUTIMER_VARS CpuTimer1;
extern struct CPUTIMER_VARS CpuTimer2;

//---------------------------------------------------------------------------
// Usefull Timer Operations:
//
// Start Timer:
#define StartCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 0

// Stop Timer:
#define StopCpuTimer0()   CpuTimer0Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define ReloadCpuTimer0() CpuTimer0Regs.TCR.bit.TRB = 1

// Read 32-Bit Timer Value:
#define ReadCpuTimer0Counter() CpuTimer0Regs.TIM.all

// Read 32-Bit Period Value:
#define ReadCpuTimer0Period() CpuTimer0Regs.PRD.all

// CpuTimer 1 and CpuTimer2 are reserved for DSP BIOS & other RTOS
// Do not use these two timers if you ever plan on integrating
// DSP-BIOS or another realtime OS.
//
// For this reason, comment out the code to manipulate these two timers
// if using DSP-BIOS or another realtime OS.

// Start Timer:
#define StartCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 0
#define StartCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 0


// Stop Timer:
#define StopCpuTimer1()   CpuTimer1Regs.TCR.bit.TSS = 1
#define StopCpuTimer2()   CpuTimer2Regs.TCR.bit.TSS = 1

// Reload Timer With period Value:
#define ReloadCpuTimer1() CpuTimer1Regs.TCR.bit.TRB = 1
#define ReloadCpuTimer2() CpuTimer2Regs.TCR.bit.TRB = 1

// Read 32-Bit Timer Value:
#define ReadCpuTimer1Counter() CpuTimer1Regs.TIM.all
#define ReadCpuTimer2Counter() CpuTimer2Regs.TIM.all

// Read 32-Bit Period Value:
#define ReadCpuTimer1Period() CpuTimer1Regs.PRD.all
#define ReadCpuTimer2Period() CpuTimer2Regs.PRD.all


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_CPU_TIMERS_H definition


//===========================================================================
// End of file.
//===========================================================================

/* EOF */