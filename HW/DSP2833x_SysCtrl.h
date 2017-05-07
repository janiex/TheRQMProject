/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_SysCtrl.h                                            **
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
// Checkin $Date: May 12, 2008   09:34:58 $
//###########################################################################
//
// FILE:   DSP2833x_SysCtrl.h
//
// TITLE:  DSP2833x Device System Control Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_SYS_CTRL_H
#define DSP2833x_SYS_CTRL_H


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// System Control Individual Register Bit Definitions:
//


// PLL Status Register
struct PLLSTS_BITS   {    // bits  description
   uint16 PLLLOCKS:1;     // 0     PLL lock status
   uint16 rsvd1:1;        // 1     reserved
   uint16 PLLOFF:1;       // 2     PLL off bit
   uint16 MCLKSTS:1;      // 3     Missing clock status bit
   uint16 MCLKCLR:1;      // 4     Missing clock clear bit
   uint16 OSCOFF:1;       // 5     Oscillator clock off
   uint16 MCLKOFF:1;      // 6     Missing clock detect
   uint16 DIVSEL:2;       // 7     Divide Select
   uint16 rsvd2:7;        // 15:7  reserved
};

union PLLSTS_REG {
   uint16              all;
   struct PLLSTS_BITS  bit;
};

// High speed peripheral clock register bit definitions:
struct HISPCP_BITS  {   // bits  description
   uint16 HSPCLK:3;     // 2:0   Rate relative to SYSCLKOUT
   uint16 rsvd1:13;     // 15:3  reserved
};

union HISPCP_REG {
   uint16              all;
   struct HISPCP_BITS  bit;
};

// Low speed peripheral clock register bit definitions:
struct LOSPCP_BITS  {   // bits  description
   uint16 LSPCLK:3;     // 2:0   Rate relative to SYSCLKOUT
   uint16 rsvd1:13;     // 15:3  reserved
};

union LOSPCP_REG {
   uint16              all;
   struct LOSPCP_BITS  bit;
};

// Peripheral clock control register 0 bit definitions:
struct PCLKCR0_BITS  {   // bits  description
   uint16 rsvd1:2;       // 1:0   reserved
   uint16 TBCLKSYNC:1;   // 2     EWPM Module TBCLK enable/sync
   uint16 ADCENCLK:1;    // 3     Enable high speed clk to ADC
   uint16 I2CAENCLK:1;   // 4     Enable SYSCLKOUT to I2C-A
   uint16 SCICENCLK:1;   // 5     Enalbe low speed clk to SCI-C
   uint16 rsvd2:2;       // 7:6   reserved
   uint16 SPIAENCLK:1;   // 8     Enable low speed clk to SPI-A
   uint16 rsvd3:1;       // 9     reserved
   uint16 SCIAENCLK:1;   // 10    Enable low speed clk to SCI-A
   uint16 SCIBENCLK:1;   // 11    Enable low speed clk to SCI-B
   uint16 MCBSPAENCLK:1; // 12    Enable low speed clk to McBSP-A
   uint16 MCBSPBENCLK:1; // 13    Enable low speed clk to McBSP-B
   uint16 ECANAENCLK:1;  // 14    Enable system clk to eCAN-A
   uint16 ECANBENCLK:1;  // 15    Enable system clk to eCAN-B
};

union PCLKCR0_REG {
   uint16              all;
   struct PCLKCR0_BITS bit;
};

// Peripheral clock control register 1 bit definitions:
struct PCLKCR1_BITS  {    // bits  description
   uint16 EPWM1ENCLK:1;   // 0     Enable SYSCLKOUT to EPWM1
   uint16 EPWM2ENCLK:1;   // 1     Enable SYSCLKOUT to EPWM2
   uint16 EPWM3ENCLK:1;   // 2     Enable SYSCLKOUT to EPWM3
   uint16 EPWM4ENCLK:1;   // 3     Enable SYSCLKOUT to EPWM4
   uint16 EPWM5ENCLK:1;   // 4     Enable SYSCLKOUT to EPWM5
   uint16 EPWM6ENCLK:1;   // 5     Enable SYSCLKOUT to EPWM6
   uint16 rsvd1:2;        // 7:6   reserved
   uint16 ECAP1ENCLK:1;   // 8     Enable SYSCLKOUT to ECAP1
   uint16 ECAP2ENCLK:1;   // 9     Enable SYSCLKOUT to ECAP2
   uint16 ECAP3ENCLK:1;   // 10    Enable SYSCLKOUT to ECAP3
   uint16 ECAP4ENCLK:1;   // 11    Enable SYSCLKOUT to ECAP4
   uint16 ECAP5ENCLK:1;   // 12    Enable SYSCLKOUT to ECAP5
   uint16 ECAP6ENCLK:1;   // 13    Enable SYSCLKOUT to ECAP6
   uint16 EQEP1ENCLK:1;   // 14    Enable SYSCLKOUT to EQEP1
   uint16 EQEP2ENCLK:1;   // 15    Enable SYSCLKOUT to EQEP2
};

union PCLKCR1_REG {
   uint16              all;
   struct PCLKCR1_BITS bit;
};


// Peripheral clock control register 2 bit definitions:
struct PCLKCR3_BITS  {        // bits  description
   uint16 rsvd1:8;            // 7:0   reserved
   uint16 CPUTIMER0ENCLK:1;   // 8     Enable SYSCLKOUT to CPU-Timer 0
   uint16 CPUTIMER1ENCLK:1;   // 9     Enable SYSCLKOUT to CPU-Timer 1
   uint16 CPUTIMER2ENCLK:1;   // 10    Enable SYSCLKOUT to CPU-Timer 2
   uint16 DMAENCLK:1;         // 11    Enable the DMA clock
   uint16 XINTFENCLK:1;       // 12    Enable SYSCLKOUT to XINTF
   uint16 GPIOINENCLK:1;      //     Enable GPIO input clock
   uint16 rsvd2:2;            // 15:14 reserved
};

union PCLKCR3_REG {
   uint16              all;
   struct PCLKCR3_BITS bit;
};



// PLL control register bit definitions:
struct PLLCR_BITS {      // bits  description
   uint16 DIV:4;         // 3:0   Set clock ratio for the PLL
   uint16 rsvd1:12;      // 15:4  reserved
};

union PLLCR_REG {
   uint16             all;
   struct PLLCR_BITS  bit;
};

// Low Power Mode 0 control register bit definitions:
struct LPMCR0_BITS {     // bits  description
   uint16 LPM:2;         // 1:0   Set the low power mode
   uint16 QUALSTDBY:6;   // 7:2   Qualification
   uint16 rsvd1:7;       // 14:8  reserved
   uint16 WDINTE:1;      // 15    Enables WD to wake the device from STANDBY
};

union LPMCR0_REG {
   uint16              all;
   struct LPMCR0_BITS  bit;
};

// Dual-mapping configuration register bit definitions:
struct MAPCNF_BITS {     // bits  description
    uint16 MAPEPWM:1;    // 0     EPWM dual-map enable
    uint16 rsvd1:15;     // 15:1  reserved
};

union MAPCNF_REG {
	uint16             all;
	struct MAPCNF_BITS bit;
};

//---------------------------------------------------------------------------
// System Control Register File:
//
struct SYS_CTRL_REGS {
   uint16              rsvd1;     // 0
   union   PLLSTS_REG  PLLSTS;    // 1
   uint16              rsvd2[8];  // 2-9
   union   HISPCP_REG  HISPCP;    // 10: High-speed peripheral clock pre-scaler
   union   LOSPCP_REG  LOSPCP;    // 11: Low-speed peripheral clock pre-scaler
   union   PCLKCR0_REG PCLKCR0;   // 12: Peripheral clock control register
   union   PCLKCR1_REG PCLKCR1;   // 13: Peripheral clock control register
   union   LPMCR0_REG  LPMCR0;    // 14: Low-power mode control register 0
   uint16              rsvd3;     // 15: reserved
   union   PCLKCR3_REG PCLKCR3;   // 16: Peripheral clock control register
   union   PLLCR_REG   PLLCR;     // 17: PLL control register
   // No bit definitions are defined for SCSR because
   // a read-modify-write instruction can clear the WDOVERRIDE bit
   uint16              SCSR;      // 18: System control and status register
   uint16              WDCNTR;    // 19: WD counter register
   uint16              rsvd4;     // 20
   uint16              WDKEY;     // 21: WD reset key register
   uint16              rsvd5[3];  // 22-24
   // No bit definitions are defined for WDCR because
   // the proper value must be written to the WDCHK field
   // whenever writing to this register.
   uint16              WDCR;      // 25: WD timer control register
   uint16              rsvd6[4];  // 26-29
   union   MAPCNF_REG  MAPCNF;    // 30: Dual-mapping configuration register
   uint16              rsvd7[1];  // 31
};


/* --------------------------------------------------- */
/* CSM Registers                                       */
/*                                                     */
/* ----------------------------------------------------*/

/* CSM Status & Control register bit definitions */
struct  CSMSCR_BITS {      // bit   description
   uint16     SECURE:1;    // 0     Secure flag
   uint16     rsvd1:14;    // 14-1  reserved
   uint16     FORCESEC:1;  // 15    Force Secure control bit

};

/* Allow access to the bit fields or entire register */
union CSMSCR_REG {
   uint16             all;
   struct CSMSCR_BITS bit;
};

/* CSM Register File */
struct  CSM_REGS {
   uint16           KEY0;    // KEY reg bits 15-0
   uint16           KEY1;    // KEY reg bits 31-16
   uint16           KEY2;    // KEY reg bits 47-32
   uint16           KEY3;    // KEY reg bits 63-48
   uint16           KEY4;    // KEY reg bits 79-64
   uint16           KEY5;    // KEY reg bits 95-80
   uint16           KEY6;    // KEY reg bits 111-96
   uint16           KEY7;    // KEY reg bits 127-112
   uint16           rsvd1;   // reserved
   uint16           rsvd2;   // reserved
   uint16           rsvd3;   // reserved
   uint16           rsvd4;   // reserved
   uint16           rsvd5;   // reserved
   uint16           rsvd6;   // reserved
   uint16           rsvd7;   // reserved
   union CSMSCR_REG CSMSCR;  // CSM Status & Control register
};

/* Password locations */
struct  CSM_PWL {
   uint16   PSWD0;  // PSWD bits 15-0
   uint16   PSWD1;  // PSWD bits 31-16
   uint16   PSWD2;  // PSWD bits 47-32
   uint16   PSWD3;  // PSWD bits 63-48
   uint16   PSWD4;  // PSWD bits 79-64
   uint16   PSWD5;  // PSWD bits 95-80
   uint16   PSWD6;  // PSWD bits 111-96
   uint16   PSWD7;  // PSWD bits 127-112
};



/* Flash Registers */

#define FLASH_SLEEP   0x0000;
#define FLASH_STANDBY 0x0001;
#define FLASH_ACTIVE  0x0003;


/* Flash Option Register bit definitions */
struct  FOPT_BITS {       // bit   description
   uint16     ENPIPE:1;   // 0     Enable Pipeline Mode
   uint16     rsvd:15;    // 1-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOPT_REG {
   uint16           all;
   struct FOPT_BITS bit;
};

/* Flash Power Modes Register bit definitions */
struct  FPWR_BITS {       // bit   description
   uint16     PWR:2;      // 0-1   Power Mode bits
   uint16     rsvd:14;    // 2-15  reserved
};

/* Allow access to the bit fields or entire register */
union FPWR_REG {
   uint16           all;
   struct FPWR_BITS bit;
};


/* Flash Status Register bit definitions */
struct  FSTATUS_BITS {       // bit   description
   uint16     PWRS:2;        // 0-1   Power Mode Status bits
   uint16     STDBYWAITS:1;  // 2     Bank/Pump Sleep to Standby Wait Counter Status bits
   uint16     ACTIVEWAITS:1; // 3     Bank/Pump Standby to Active Wait Counter Status bits
   uint16     rsvd1:4;       // 4-7   reserved
   uint16     V3STAT:1;      // 8     VDD3V Status Latch bit
   uint16     rsvd2:7;       // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTATUS_REG {
   uint16              all;
   struct FSTATUS_BITS bit;
};

/* Flash Sleep to Standby Wait Counter Register bit definitions */
struct  FSTDBYWAIT_BITS {    // bit   description
   uint16     STDBYWAIT:9;   // 0-8   Bank/Pump Sleep to Standby Wait Count bits
   uint16     rsvd:7;        // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FSTDBYWAIT_REG {
   uint16                 all;
   struct FSTDBYWAIT_BITS bit;
};

/* Flash Standby to Active Wait Counter Register bit definitions */
struct  FACTIVEWAIT_BITS {   // bit   description
   uint16     ACTIVEWAIT:9;  // 0-8   Bank/Pump Standby to Active Wait Count bits
   uint16     rsvd:7;        // 9-15  reserved
};

/* Allow access to the bit fields or entire register */
union FACTIVEWAIT_REG {
   uint16                  all;
   struct FACTIVEWAIT_BITS bit;
};

/* Bank Read Access Wait State Register bit definitions */
struct  FBANKWAIT_BITS {     // bit   description
   uint16     RANDWAIT:4;    // 0-3   Flash Random Read Wait State bits
   uint16     rsvd1:4;       // 4-7   reserved
   uint16     PAGEWAIT:4;    // 8-11  Flash Paged Read Wait State bits
   uint16     rsvd2:4;       // 12-15 reserved
};

/* Allow access to the bit fields or entire register */
union FBANKWAIT_REG {
   uint16                all;
   struct FBANKWAIT_BITS bit;
};

/* OTP Read Access Wait State Register bit definitions */
struct  FOTPWAIT_BITS {      // bit   description
   uint16     OTPWAIT:5;     // 0-4   OTP Read Wait State bits
   uint16     rsvd:11;       // 5-15  reserved
};

/* Allow access to the bit fields or entire register */
union FOTPWAIT_REG {
   uint16               all;
   struct FOTPWAIT_BITS bit;
};


struct FLASH_REGS {
   union FOPT_REG        FOPT;        // Option Register
   uint16                rsvd1;       // reserved
   union FPWR_REG        FPWR;        // Power Modes Register
   union FSTATUS_REG     FSTATUS;     // Status Register
   union FSTDBYWAIT_REG  FSTDBYWAIT;  // Pump/Bank Sleep to Standby Wait State Register
   union FACTIVEWAIT_REG FACTIVEWAIT; // Pump/Bank Standby to Active Wait State Register
   union FBANKWAIT_REG   FBANKWAIT;   // Bank Read Access Wait State Register
   union FOTPWAIT_REG    FOTPWAIT;    // OTP Read Access Wait State Register
};

//---------------------------------------------------------------------------
// System Control External References & Function Declarations:
//
extern volatile struct SYS_CTRL_REGS SysCtrlRegs;
extern volatile struct CSM_REGS CsmRegs;
extern volatile struct CSM_PWL CsmPwl;
extern volatile struct FLASH_REGS FlashRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_SYS_CTRL_H definition

//===========================================================================
// End of file.
//===========================================================================


/* EOF */
