/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_I2c.h                                                **
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
// TI File $Revision: /main/2 $
// Checkin $Date: March 22, 2007   10:40:22 $
//###########################################################################
//
// FILE:   DSP2833x_I2c.h
//
// TITLE:  DSP2833x Enhanced Quadrature Encoder Pulse Module
//         Register Bit Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_I2C_H
#define DSP2833x_I2C_H


#ifdef __cplusplus
extern "C" {
#endif


//----------------------------------------------------
// I2C interrupt vector register bit definitions */
struct I2CISRC_BITS {         // bits   description
   uint16 INTCODE:3;          // 2:0    Interrupt code
   uint16 rsvd1:13;           // 15:3   reserved
};

union I2CISRC_REG {
   uint16                 all;
   struct I2CISRC_BITS    bit;
};

//----------------------------------------------------
// I2C interrupt mask register bit definitions */
struct I2CIER_BITS {          // bits   description
   uint16 ARBL:1;             // 0      Arbitration lost interrupt
   uint16 NACK:1;             // 1      No ack interrupt
   uint16 ARDY:1;             // 2      Register access ready interrupt
   uint16 RRDY:1;             // 3      Recieve data ready interrupt
   uint16 XRDY:1;             // 4      Transmit data ready interrupt
   uint16 SCD:1;              // 5      Stop condition detection
   uint16 AAS:1;              // 6      Address as slave
   uint16 rsvd:9;             // 15:7   reserved
};

union I2CIER_REG {
   uint16                 all;
   struct I2CIER_BITS     bit;
};

//----------------------------------------------------
// I2C status register bit definitions */
struct I2CSTR_BITS {          // bits   description
   uint16 ARBL:1;             // 0      Arbitration lost interrupt
   uint16 NACK:1;             // 1      No ack interrupt
   uint16 ARDY:1;             // 2      Register access ready interrupt
   uint16 RRDY:1;             // 3      Recieve data ready interrupt
   uint16 XRDY:1;             // 4      Transmit data ready interrupt
   uint16 SCD:1;              // 5      Stop condition detection
   uint16 rsvd1:2;            // 7:6    reserved
   uint16 AD0:1;              // 8      Address Zero
   uint16 AAS:1;              // 9      Address as slave
   uint16 XSMT:1;             // 10     XMIT shift empty
   uint16 RSFULL:1;           // 11     Recieve shift full
   uint16 BB:1;               // 12     Bus busy
   uint16 NACKSNT:1;          // 13     A no ack sent
   uint16 SDIR:1;             // 14     Slave direction
   uint16 rsvd2:1;            // 15     reserved
};

union I2CSTR_REG {
   uint16                 all;
   struct I2CSTR_BITS     bit;
};


//----------------------------------------------------
// I2C mode control register bit definitions */
struct I2CMDR_BITS {          // bits   description
   uint16 BC:3;               // 2:0    Bit count
   uint16 FDF:1;              // 3      Free data format
   uint16 STB:1;              // 4      Start byte
   uint16 IRS:1;              // 5      I2C Reset not
   uint16 DLB:1;              // 6      Digital loopback
   uint16 RM:1;               // 7      Repeat mode
   uint16 XA:1;               // 8      Expand address
   uint16 TRX:1;              // 9      Transmitter/reciever
   uint16 MST:1;              // 10     Master/slave
   uint16 STP:1;              // 11     Stop condition
   uint16 rsvd1:1;            // 12     reserved
   uint16 STT:1;              // 13     Start condition
   uint16 FREE:1;             // 14     Emulation mode
   uint16 NACKMOD:1;          // 15     No Ack mode
};

union I2CMDR_REG {
   uint16                 all;
   struct I2CMDR_BITS     bit;
};

//----------------------------------------------------
// I2C pre-scaler register bit definitions */
struct I2CPSC_BITS {         // bits   description
   uint16 IPSC:8;            // 7:0    pre-scaler
   uint16 rsvd1:8;           // 15:8   reserved
};


union I2CPSC_REG {
   uint16                 all;
   struct I2CPSC_BITS     bit;
};


//----------------------------------------------------
// TX FIFO control register bit definitions */
struct I2CFFTX_BITS {         // bits   description
   uint16 TXFFIL:5;           // 4:0    FIFO interrupt level
   uint16 TXFFIENA:1;         // 5      FIFO interrupt enable/disable
   uint16 TXFFINTCLR:1;       // 6      FIFO clear
   uint16 TXFFINT:1;          // 7      FIFO interrupt flag
   uint16 TXFFST:5;           // 12:8   FIFO level status
   uint16 TXFFRST:1;          // 13     FIFO reset
   uint16 I2CFFEN:1;          // 14     enable/disable TX & RX FIFOs
   uint16 rsvd1:1;            // 15     reserved

};

union I2CFFTX_REG {
   uint16                 all;
   struct I2CFFTX_BITS    bit;
};

//----------------------------------------------------
// RX FIFO control register bit definitions */
struct I2CFFRX_BITS {         // bits   description
   uint16 RXFFIL:5;           // 4:0    FIFO interrupt level
   uint16 RXFFIENA:1;         // 5      FIFO interrupt enable/disable
   uint16 RXFFINTCLR:1;       // 6      FIFO clear
   uint16 RXFFINT:1;          // 7      FIFO interrupt flag
   uint16 RXFFST:5;           // 12:8   FIFO level
   uint16 RXFFRST:1;          // 13     FIFO reset
   uint16 rsvd1:2;            // 15:14  reserved
};

union I2CFFRX_REG {
   uint16                 all;
   struct I2CFFRX_BITS    bit;
};


//----------------------------------------------------

struct I2C_REGS {
   uint16              I2COAR;    // Own address register
   union  I2CIER_REG   I2CIER;    // Interrupt enable
   union  I2CSTR_REG   I2CSTR;    // Interrupt status
   uint16              I2CCLKL;   // Clock divider low
   uint16              I2CCLKH;   // Clock divider high
   uint16              I2CCNT;    // Data count
   uint16              I2CDRR;    // Data recieve
   uint16              I2CSAR;    // Slave address
   uint16              I2CDXR;    // Data transmit
   union  I2CMDR_REG   I2CMDR;    // Mode
   union  I2CISRC_REG  I2CISRC;   // Interrupt source
   uint16              rsvd1;     // reserved
   union  I2CPSC_REG   I2CPSC;    // Pre-scaler
   uint16              rsvd2[19]; // reserved
   union  I2CFFTX_REG  I2CFFTX;   // Transmit FIFO
   union  I2CFFRX_REG  I2CFFRX;   // Recieve FIFO
};




//---------------------------------------------------------------------------
// External References & Function Declarations:
//
extern volatile struct I2C_REGS I2caRegs;


#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_I2C_H definition

//===========================================================================
// End of file.
//===========================================================================

/* EOF */
