/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_EPwm.h                                               **
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
// Checkin $Date: August 18, 2006   13:52:10 $
//###########################################################################
//
// FILE:   DSP2833x_EPwm.h
//
// TITLE:  DSP2833x Enhanced PWM Module Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_EPWM_H
#define DSP2833x_EPWM_H


#ifdef __cplusplus
extern "C" {
#endif

//----------------------------------------------------
// Time base control register bit definitions */                                    
struct TBCTL_BITS {          // bits   description
   uint16 CTRMODE:2;         // 1:0    Counter Mode
   uint16 PHSEN:1;           // 2      Phase load enable
   uint16 PRDLD:1;           // 3      Active period load
   uint16 SYNCOSEL:2;        // 5:4    Sync output select
   uint16 SWFSYNC:1;         // 6      Software force sync pulse
   uint16 HSPCLKDIV:3;       // 9:7    High speed time pre-scale
   uint16 CLKDIV:3;          // 12:10  Timebase clock pre-scale
   uint16 PHSDIR:1;          // 13     Phase Direction
   uint16 FREE_SOFT:2;       // 15:14  Emulation mode 
};

union TBCTL_REG {
   uint16              all;
   struct TBCTL_BITS   bit;
};

//----------------------------------------------------
// Time base status register bit definitions */                                    
struct TBSTS_BITS {          // bits   description
   uint16 CTRDIR:1;          // 0      Counter direction status
   uint16 SYNCI:1;           // 1      External input sync status
   uint16 CTRMAX:1;          // 2      Counter max latched status
   uint16 rsvd1:13;          // 15:3   reserved
};

union TBSTS_REG {
   uint16              all;
   struct TBSTS_BITS   bit;
};

//----------------------------------------------------
// Compare control register bit definitions */                                    
struct CMPCTL_BITS {          // bits   description
   uint16 LOADAMODE:2;        // 0:1    Active compare A
   uint16 LOADBMODE:2;        // 3:2    Active compare B
   uint16 SHDWAMODE:1;        // 4      Compare A block operating mode
   uint16 rsvd1:1;            // 5      reserved
   uint16 SHDWBMODE:1;        // 6      Compare B block operating mode
   uint16 rsvd2:1;            // 7      reserved
   uint16 SHDWAFULL:1;        // 8      Compare A Shadow registers full Status
   uint16 SHDWBFULL:1;        // 9      Compare B Shadow registers full Status
   uint16 rsvd3:6;            // 15:10  reserved
};


union CMPCTL_REG {
   uint16                all;
   struct CMPCTL_BITS    bit;
};

//----------------------------------------------------
// Action qualifier register bit definitions */                                    
struct AQCTL_BITS {           // bits   description
   uint16 ZRO:2;              // 1:0    Action Counter = Zero
   uint16 PRD:2;              // 3:2    Action Counter = Period
   uint16 CAU:2;              // 5:4    Action Counter = Compare A up
   uint16 CAD:2;              // 7:6    Action Counter = Compare A down
   uint16 CBU:2;              // 9:8    Action Counter = Compare B up
   uint16 CBD:2;              // 11:10  Action Counter = Compare B down
   uint16 rsvd:4;             // 15:12  reserved
};

union AQCTL_REG {
   uint16                all;
   struct AQCTL_BITS     bit;
};

//----------------------------------------------------
// Action qualifier SW force register bit definitions */                                    
struct AQSFRC_BITS {           // bits   description
   uint16 ACTSFA:2;            // 1:0    Action when One-time SW Force A invoked
   uint16 OTSFA:1;             // 2      One-time SW Force A output
   uint16 ACTSFB:2;            // 4:3    Action when One-time SW Force B invoked
   uint16 OTSFB:1;             // 5      One-time SW Force A output
   uint16 RLDCSF:2;            // 7:6    Reload from Shadow options
   uint16 rsvd1:8;             // 15:8   reserved
};

union AQSFRC_REG {
   uint16                 all;
   struct AQSFRC_BITS     bit;
};

//----------------------------------------------------
// Action qualifier continuous SW force register bit definitions */                                    
struct AQCSFRC_BITS {          // bits   description
   uint16 CSFA:2;              // 1:0    Continuous Software Force on output A
   uint16 CSFB:2;              // 3:2    Continuous Software Force on output B
   uint16 rsvd1:12;            // 15:4   reserved
};

union AQCSFRC_REG {
   uint16                  all;
   struct AQCSFRC_BITS     bit;
};


// As of version 1.1
// Changed the MODE bit-field to OUT_MODE
// Added the bit-field IN_MODE
// This corresponds to changes in silicon as of F2833x devices
// Rev A silicon.
//----------------------------------------------------
// Dead-band generator control register bit definitions                                    
struct DBCTL_BITS {          // bits   description
   uint16 OUT_MODE:2;      	 // 1:0    Dead Band Output Mode Control 
   uint16 POLSEL:2;          // 3:2    Polarity Select Control 
   uint16 IN_MODE:2;         // 5:4    Dead Band Input Select Mode Control
   uint16 rsvd1:10;          // 15:4   reserved
};

union DBCTL_REG {
   uint16                  all;
   struct DBCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone select register bit definitions                                   
struct TZSEL_BITS {           // bits   description
   uint16  CBC1:1;            // 0      TZ1 CBC select
   uint16  CBC2:1;            // 1      TZ2 CBC select
   uint16  CBC3:1;            // 2      TZ3 CBC select
   uint16  CBC4:1;            // 3      TZ4 CBC select
   uint16  CBC5:1;            // 4      TZ5 CBC select
   uint16  CBC6:1;            // 5      TZ6 CBC select
   uint16  rsvd1:2;           // 7:6    reserved
   uint16  OSHT1:1;           // 8      One-shot TZ1 select             
   uint16  OSHT2:1;           // 9      One-shot TZ2 select             
   uint16  OSHT3:1;           // 10     One-shot TZ3 select             
   uint16  OSHT4:1;           // 11     One-shot TZ4 select             
   uint16  OSHT5:1;           // 12     One-shot TZ5 select             
   uint16  OSHT6:1;           // 13     One-shot TZ6 select             
   uint16  rsvd2:2;           // 15:14  reserved
};

union TZSEL_REG {
   uint16                  all;
   struct TZSEL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZCTL_BITS {         // bits   description
   uint16 TZA:2;            // 1:0    TZ1 to TZ6 Trip Action On EPWMxA
   uint16 TZB:2;            // 3:2    TZ1 to TZ6 Trip Action On EPWMxB
   uint16 rsvd:12;          // 15:4   reserved
};

union TZCTL_REG {
   uint16                  all;
   struct TZCTL_BITS       bit;
};


//----------------------------------------------------
// Trip zone control register bit definitions */                                    
struct TZEINT_BITS {         // bits   description
   uint16  rsvd1:1;          // 0      reserved
   uint16  CBC:1;            // 1      Trip Zones Cycle By Cycle Int Enable
   uint16  OST:1;            // 2      Trip Zones One Shot Int Enable
   uint16  rsvd2:13;         // 15:3   reserved
};   


union TZEINT_REG {
   uint16                  all;
   struct TZEINT_BITS      bit;
};


//----------------------------------------------------
// Trip zone flag register bit definitions */                                    
struct TZFLG_BITS {         // bits   description
   uint16  INT:1;           // 0      Global status
   uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16  OST:1;           // 2      Trip Zones One Shot Int
   uint16  rsvd2:13;        // 15:3   reserved
};

union TZFLG_REG {
   uint16                  all;
   struct TZFLG_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag clear register bit definitions */                                    
struct TZCLR_BITS {         // bits   description
   uint16  INT:1;           // 0      Global status
   uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16  OST:1;           // 2      Trip Zones One Shot Int
   uint16  rsvd2:13;        // 15:3   reserved
};

union TZCLR_REG {
   uint16                  all;
   struct TZCLR_BITS       bit;
};

//----------------------------------------------------
// Trip zone flag force register bit definitions */                                    
struct TZFRC_BITS {         // bits   description
   uint16  rsvd1:1;         // 0      reserved
   uint16  CBC:1;           // 1      Trip Zones Cycle By Cycle Int
   uint16  OST:1;           // 2      Trip Zones One Shot Int
   uint16  rsvd2:13;        // 15:3   reserved
};

union TZFRC_REG {
   uint16                  all;
   struct TZFRC_BITS       bit;
};

//----------------------------------------------------
// Event trigger select register bit definitions */                                    
struct ETSEL_BITS {         // bits   description
   uint16  INTSEL:3;        // 2:0    EPWMxINTn Select
   uint16  INTEN:1;         // 3      EPWMxINTn Enable
   uint16  rsvd1:4;         // 7:4    reserved
   uint16  SOCASEL:3;       // 10:8   Start of conversion A Select
   uint16  SOCAEN:1;        // 11     Start of conversion A Enable
   uint16  SOCBSEL:3;       // 14:12  Start of conversion B Select
   uint16  SOCBEN:1;        // 15     Start of conversion B Enable
};

union ETSEL_REG {
   uint16                  all;
   struct ETSEL_BITS       bit;
};


//----------------------------------------------------
// Event trigger pre-scale register bit definitions */                                    
struct ETPS_BITS {         // bits   description
   uint16  INTPRD:2;       // 1:0    EPWMxINTn Period Select
   uint16  INTCNT:2;       // 3:2    EPWMxINTn Counter Register
   uint16  rsvd1:4;        // 7:4    reserved
   uint16  SOCAPRD:2;      // 9:8    EPWMxSOCA Period Select
   uint16  SOCACNT:2;      // 11:10  EPWMxSOCA Counter Register
   uint16  SOCBPRD:2;      // 13:12  EPWMxSOCB Period Select
   uint16  SOCBCNT:2;      // 15:14  EPWMxSOCB Counter Register
};

union ETPS_REG {
   uint16                  all;
   struct ETPS_BITS        bit;
};

//----------------------------------------------------
// Event trigger Flag register bit definitions */                                    
struct ETFLG_BITS {         // bits   description
   uint16  INT:1;           // 0	EPWMxINTn Flag
   uint16  rsvd1:1;         // 1	reserved
   uint16  SOCA:1;          // 2	EPWMxSOCA Flag
   uint16  SOCB:1;          // 3	EPWMxSOCB Flag
   uint16  rsvd2:12;        // 15:4	reserved
};

union ETFLG_REG {
   uint16                   all;
   struct ETFLG_BITS        bit;
};


//----------------------------------------------------
// Event trigger Clear register bit definitions */                                    
struct ETCLR_BITS {         // bits   description
   uint16  INT:1;           // 0	EPWMxINTn Clear
   uint16  rsvd1:1;         // 1	reserved
   uint16  SOCA:1;          // 2	EPWMxSOCA Clear
   uint16  SOCB:1;          // 3	EPWMxSOCB Clear
   uint16  rsvd2:12;        // 15:4	reserved
};

union ETCLR_REG {
   uint16                   all;
   struct ETCLR_BITS        bit;
};

//----------------------------------------------------
// Event trigger Force register bit definitions */                                    
struct ETFRC_BITS {         // bits   description
   uint16  INT:1;           // 0	EPWMxINTn Force
   uint16  rsvd1:1;         // 1	reserved
   uint16  SOCA:1;          // 2	EPWMxSOCA Force
   uint16  SOCB:1;          // 3	EPWMxSOCB Force
   uint16  rsvd2:12;        // 15:4	reserved
};

union ETFRC_REG {
   uint16                  all;
   struct ETFRC_BITS        bit;
};
//----------------------------------------------------
// PWM chopper control register bit definitions */                                    
struct PCCTL_BITS {         // bits   description
   uint16  CHPEN:1;         // 0      PWM chopping enable
   uint16  OSHTWTH:4;       // 4:1    One-shot pulse width
   uint16  CHPFREQ:3;       // 7:5    Chopping clock frequency
   uint16  CHPDUTY:3;       // 10:8   Chopping clock Duty cycle
   uint16  rsvd1:5;         // 15:11  reserved
};


union PCCTL_REG {
   uint16                  all;
   struct PCCTL_BITS       bit;
};

struct HRCNFG_BITS {       	// bits   description
   uint16  EDGMODE:2;     	// 1:0    Edge Mode select Bits
   uint16  CTLMODE:1;     	// 2      Control mode Select Bit
   uint16  HRLOAD:1;      	// 3      Shadow mode Select Bit
   uint16  rsvd1:12;      	// 15:4   reserved
};

union HRCNFG_REG {
   uint16                  	all;
   struct HRCNFG_BITS       bit;
};


struct TBPHS_HRPWM_REG {   	// bits   description
   uint16  TBPHSHR;     	// 15:0   Extension register for HRPWM Phase (8 bits)
   uint16  TBPHS;           // 31:16  Phase offset register
};

union TBPHS_HRPWM_GROUP {
   uint32                  all;
   struct TBPHS_HRPWM_REG  half;
};

struct CMPA_HRPWM_REG {   	// bits   description
   uint16  CMPAHR;     	    // 15:0   Extension register for HRPWM compare (8 bits)
   uint16  CMPA;            // 31:16  Compare A reg
};

union CMPA_HRPWM_GROUP {
   uint32                 all;
   struct CMPA_HRPWM_REG  half;
};


struct EPWM_REGS {
   union  TBCTL_REG           TBCTL;   // 
   union  TBSTS_REG           TBSTS;   // 
   union  TBPHS_HRPWM_GROUP   TBPHS;   // Union of TBPHS:TBPHSHR
   uint16                     TBCTR;   // Counter
   uint16                     TBPRD;   // Period register set 
   uint16                     rsvd1;   // 
   union  CMPCTL_REG          CMPCTL;  // Compare control
   union  CMPA_HRPWM_GROUP    CMPA;    // Union of CMPA:CMPAHR
   uint16                     CMPB;    // Compare B reg
   union  AQCTL_REG           AQCTLA;  // Action qual output A
   union  AQCTL_REG           AQCTLB;  // Action qual output B
   union  AQSFRC_REG          AQSFRC;  // Action qual SW force
   union  AQCSFRC_REG         AQCSFRC; // Action qualifier continuous SW force 
   union  DBCTL_REG           DBCTL;   // Dead-band control
   uint16                     DBRED;   // Dead-band rising edge delay
   uint16                     DBFED;   // Dead-band falling edge delay
   union  TZSEL_REG           TZSEL;   // Trip zone select
   uint16                     rsvd2;   
   union  TZCTL_REG           TZCTL;   // Trip zone control
   union  TZEINT_REG          TZEINT;  // Trip zone interrupt enable
   union  TZFLG_REG           TZFLG;   // Trip zone interrupt flags
   union  TZCLR_REG           TZCLR;   // Trip zone clear   
   union  TZFRC_REG    	      TZFRC;   // Trip zone force interrupt
   union  ETSEL_REG           ETSEL;   // Event trigger selection
   union  ETPS_REG            ETPS;    // Event trigger pre-scaler
   union  ETFLG_REG           ETFLG;   // Event trigger flags
   union  ETCLR_REG           ETCLR;   // Event trigger clear   
   union  ETFRC_REG           ETFRC;   // Event trigger force
   union  PCCTL_REG           PCCTL;   // PWM chopper control
   uint16                     rsvd3;   // 
   union  HRCNFG_REG          HRCNFG;  // HRPWM Config Reg
};
    
 

//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct EPWM_REGS EPwm1Regs;
extern volatile struct EPWM_REGS EPwm2Regs;
extern volatile struct EPWM_REGS EPwm3Regs;
extern volatile struct EPWM_REGS EPwm4Regs;
extern volatile struct EPWM_REGS EPwm5Regs;
extern volatile struct EPWM_REGS EPwm6Regs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_EPWM_H definition

//===========================================================================
// End of file.
//===========================================================================

/* EOF */
