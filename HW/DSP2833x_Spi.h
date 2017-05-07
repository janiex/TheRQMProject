/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_Spi.h                                                **
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
// TI File $Revision: /main/3 $
// Checkin $Date: April 17, 2008   11:08:27 $
//###########################################################################
//
// FILE:   DSP2833x_Spi.h
//
// TITLE:  DSP2833x Device SPI Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_SPI_H
#define DSP2833x_SPI_H


#ifdef __cplusplus
extern "C" {
#endif


//---------------------------------------------------------------------------
// SPI Individual Register Bit Definitions:
//
// SPI FIFO Transmit register bit    definitions:
struct  SPIFFTX_BITS {       // bit    description
   uint16 TXFFIL:5;          // 4:0    Interrupt level
   uint16 TXFFIENA:1;        // 5      Interrupt enable
   uint16 TXFFINTCLR:1;      // 6      Clear INT flag
   uint16 TXFFINT:1;         // 7      INT flag
   uint16 TXFFST:5;          // 12:8   FIFO status
   uint16 TXFIFO:1;          // 13     FIFO reset
   uint16 SPIFFENA:1;        // 14     Enhancement enable
   uint16 SPIRST:1;          // 15     Reset SPI
};

union SPIFFTX_REG {
   uint16               all;
   struct SPIFFTX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO recieve register bit definitions:
//
//
struct  SPIFFRX_BITS {       // bits   description
   uint16 RXFFIL:5;          // 4:0    Interrupt level
   uint16 RXFFIENA:1;        // 5      Interrupt enable
   uint16 RXFFINTCLR:1;      // 6      Clear INT flag
   uint16 RXFFINT:1;         // 7      INT flag
   uint16 RXFFST:5;          // 12:8   FIFO status
   uint16 RXFIFORESET:1;     // 13     FIFO reset
   uint16 RXFFOVFCLR:1;      // 14     Clear overflow
   uint16 RXFFOVF:1;         // 15     FIFO overflow

};

union SPIFFRX_REG {
   uint16               all;
   struct SPIFFRX_BITS  bit;
};

//--------------------------------------------
// SPI FIFO control register bit definitions:
//
//
struct  SPIFFCT_BITS {       // bits   description
   uint16 TXDLY:8;           // 7:0    FIFO transmit delay
   uint16 rsvd:8;            // 15:8   reserved
};

union SPIFFCT_REG {
   uint16               all;
   struct SPIFFCT_BITS  bit;
};

//---------------------------------------------
// SPI configuration register bit definitions:
//
//
struct  SPICCR_BITS {        // bits   description
   uint16 SPICHAR:4;         // 3:0    Character length control
   uint16 SPILBK:1;          // 4      Loop-back enable/disable
   uint16 rsvd1:1;           // 5      reserved
   uint16 CLKPOLARITY:1;     // 6      Clock polarity
   uint16 SPISWRESET:1;      // 7      SPI SW Reset
   uint16 rsvd2:8;           // 15:8   reserved
};

union SPICCR_REG {
   uint16              all;
   struct SPICCR_BITS  bit;
};

//-------------------------------------------------
// SPI operation control register bit definitions:
//
//
struct  SPICTL_BITS {        // bits   description
   uint16 SPIINTENA:1;       // 0      Interrupt enable
   uint16 TALK:1;            // 1      Master/Slave transmit enable
   uint16 MASTER_SLAVE:1;    // 2      Network control mode
   uint16 CLK_PHASE:1;       // 3      Clock phase select
   uint16 OVERRUNINTENA:1;   // 4      Overrun interrupt enable
   uint16 rsvd:11;           // 15:5   reserved
};

union SPICTL_REG {
   uint16              all;
   struct SPICTL_BITS  bit;
};

//--------------------------------------
// SPI status register bit definitions:
//
//
struct  SPISTS_BITS {        // bits   description
   uint16 rsvd1:5;           // 4:0    reserved
   uint16 BUFFULL_FLAG:1;    // 5      SPI transmit buffer full flag
   uint16 INT_FLAG:1;        // 6      SPI interrupt flag
   uint16 OVERRUN_FLAG:1;    // 7      SPI reciever overrun flag
   uint16 rsvd2:8;           // 15:8   reserved
};

union SPISTS_REG {
   uint16              all;
   struct SPISTS_BITS  bit;
};

//------------------------------------------------
// SPI priority control register bit definitions:
//
//
struct  SPIPRI_BITS {        // bits   description
   uint16 rsvd1:4;           // 3:0    reserved
   uint16 FREE:1;            // 4      Free emulation mode control
   uint16 SOFT:1;            // 5      Soft emulation mode control
   uint16 rsvd2:1;           // 6      reserved
   uint16 rsvd3:9;           // 15:7   reserved
};

union SPIPRI_REG {
   uint16              all;
   struct SPIPRI_BITS  bit;
};

//---------------------------------------------------------------------------
// SPI Register File:
//
struct  SPI_REGS {
   union SPICCR_REG     SPICCR;      // Configuration register
   union SPICTL_REG     SPICTL;      // Operation control register
   union SPISTS_REG     SPISTS;      // Status register
   uint16               rsvd1;       // reserved
   uint16               SPIBRR;      // Baud Rate
   uint16               rsvd2;       // reserved
   uint16               SPIRXEMU;    // Emulation buffer
   uint16               SPIRXBUF;    // Serial input buffer
   uint16               SPITXBUF;    // Serial output buffer
   uint16               SPIDAT;      // Serial data
   union SPIFFTX_REG    SPIFFTX;     // FIFO transmit register
   union SPIFFRX_REG    SPIFFRX;     // FIFO recieve register
   union SPIFFCT_REG    SPIFFCT;     // FIFO control register
   uint16               rsvd3[2];    // reserved
   union SPIPRI_REG     SPIPRI;      // FIFO Priority control
};

//---------------------------------------------------------------------------
// SPI External References & Function Declarations:
//
extern volatile struct SPI_REGS SpiaRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_SPI_H definition

//===========================================================================
// End of file.
//===========================================================================


/* EOF */
