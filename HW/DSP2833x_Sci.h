/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DSP2833x_Sci.h                                                **
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
// Checkin $Date: March 1, 2007   15:57:02 $
//###########################################################################
//
// FILE:	DSP2833x_Sci.h
//
// TITLE:	DSP2833x Device SCI Register Definitions.
//
//###########################################################################
// $TI Release: DSP2833x/DSP2823x C/C++ Header Files V1.31 $
// $Release Date: August 4, 2009 $
//###########################################################################

#ifndef DSP2833x_SCI_H
#define DSP2833x_SCI_H


#ifdef __cplusplus
extern "C" {
#endif

//---------------------------------------------------------------------------
// SCI Individual Register Bit Definitions

//----------------------------------------------------------
// SCICCR communication control register bit definitions:
//

struct  SCICCR_BITS {        // bit    description
   uint16 SCICHAR:3;         // 2:0    Character length control        
   uint16 ADDRIDLE_MODE:1;   // 3      ADDR/IDLE Mode control
   uint16 LOOPBKENA:1;       // 4      Loop Back enable
   uint16 PARITYENA:1;       // 5      Parity enable   
   uint16 PARITY:1;          // 6      Even or Odd Parity
   uint16 STOPBITS:1;        // 7      Number of Stop Bits
   uint16 rsvd1:8;           // 15:8   reserved
}; 


union SCICCR_REG {
   uint16              all;
   struct SCICCR_BITS  bit;
};

//-------------------------------------------
// SCICTL1 control register 1 bit definitions:
//
                       
struct  SCICTL1_BITS {       // bit    description
   uint16 RXENA:1;           // 0      SCI receiver enable
   uint16 TXENA:1;           // 1      SCI transmitter enable
   uint16 SLEEP:1;           // 2      SCI sleep  
   uint16 TXWAKE:1;          // 3      Transmitter wakeup method
   uint16 rsvd:1;            // 4      reserved
   uint16 SWRESET:1;         // 5      Software reset   
   uint16 RXERRINTENA:1;     // 6      Recieve interrupt enable
   uint16 rsvd1:9;           // 15:7   reserved

}; 

union SCICTL1_REG {
   uint16               all;
   struct SCICTL1_BITS  bit;
};

//---------------------------------------------
// SCICTL2 control register 2 bit definitions:
// 

struct  SCICTL2_BITS {       // bit    description
   uint16 TXINTENA:1;        // 0      Transmit interrupt enable    
   uint16 RXBKINTENA:1;      // 1      Receiver-buffer break enable
   uint16 rsvd:4;            // 5:2    reserved
   uint16 TXEMPTY:1;         // 6      Transmitter empty flag
   uint16 TXRDY:1;           // 7      Transmitter ready flag  
   uint16 rsvd1:8;           // 15:8   reserved

}; 

union SCICTL2_REG {
   uint16               all;
   struct SCICTL2_BITS  bit;
};

//---------------------------------------------------
// SCIRXST Receiver status register bit definitions:
//

struct  SCIRXST_BITS {       // bit    description
   uint16 rsvd:1;            // 0      reserved
   uint16 RXWAKE:1;          // 1      Receiver wakeup detect flag
   uint16 PE:1;              // 2      Parity error flag
   uint16 OE:1;              // 3      Overrun error flag
   uint16 FE:1;              // 4      Framing error flag
   uint16 BRKDT:1;           // 5      Break-detect flag   
   uint16 RXRDY:1;           // 6      Receiver ready flag
   uint16 RXERROR:1;         // 7      Receiver error flag

}; 

union SCIRXST_REG {
   uint16               all;
   struct SCIRXST_BITS  bit;
};

//----------------------------------------------------
// SCIRXBUF Receiver Data Buffer with FIFO bit definitions:
// 

struct  SCIRXBUF_BITS {      // bits   description
   uint16 RXDT:8;            // 7:0    Receive word
   uint16 rsvd:6;            // 13:8   reserved
   uint16 SCIFFPE:1;         // 14     SCI PE error in FIFO mode
   uint16 SCIFFFE:1;         // 15     SCI FE error in FIFO mode
};

union SCIRXBUF_REG {
   uint16                all;
   struct SCIRXBUF_BITS  bit;
};

//--------------------------------------------------
// SCIPRI Priority control register bit definitions:
// 
//
                                                   
struct  SCIPRI_BITS {        // bit    description
   uint16 rsvd:3;            // 2:0    reserved
   uint16 FREE:1;            // 3      Free emulation suspend mode
   uint16 SOFT:1;            // 4      Soft emulation suspend mode
   uint16 rsvd1:3;           // 7:5    reserved
}; 

union SCIPRI_REG {
   uint16              all;
   struct SCIPRI_BITS  bit;
};

//-------------------------------------------------
// SCI FIFO Transmit register bit definitions:
// 
//
                                                  
struct  SCIFFTX_BITS {       // bit    description
   uint16 TXFFIL:5;          // 4:0    Interrupt level
   uint16 TXFFIENA:1;        // 5      Interrupt enable
   uint16 TXFFINTCLR:1;      // 6      Clear INT flag
   uint16 TXFFINT:1;         // 7      INT flag
   uint16 TXFFST:5;          // 12:8   FIFO status
   uint16 TXFIFOXRESET:1;    // 13     FIFO reset
   uint16 SCIFFENA:1;        // 14     Enhancement enable
   uint16 SCIRST:1;          // 15     SCI reset rx/tx channels 

}; 

union SCIFFTX_REG {
   uint16               all;
   struct SCIFFTX_BITS  bit;
};

//------------------------------------------------
// SCI FIFO recieve register bit definitions:
// 
//
                                               
struct  SCIFFRX_BITS {       // bits   description
   uint16 RXFFIL:5;          // 4:0    Interrupt level
   uint16 RXFFIENA:1;        // 5      Interrupt enable
   uint16 RXFFINTCLR:1;      // 6      Clear INT flag
   uint16 RXFFINT:1;         // 7      INT flag
   uint16 RXFFST:5;          // 12:8   FIFO status
   uint16 RXFIFORESET:1;     // 13     FIFO reset
   uint16 RXFFOVRCLR:1;      // 14     Clear overflow
   uint16 RXFFOVF:1;         // 15     FIFO overflow

}; 

union SCIFFRX_REG {
   uint16               all;
   struct SCIFFRX_BITS  bit;
};

// SCI FIFO control register bit definitions:
struct  SCIFFCT_BITS {     // bits   description
   uint16 FFTXDLY:8;         // 7:0    FIFO transmit delay
   uint16 rsvd:5;            // 12:8   reserved
   uint16 CDC:1;             // 13     Auto baud mode enable
   uint16 ABDCLR:1;          // 14     Auto baud clear
   uint16 ABD:1;             // 15     Auto baud detect
};

union SCIFFCT_REG {
   uint16               all;
   struct SCIFFCT_BITS  bit;
};

//---------------------------------------------------------------------------
// SCI Register File:
//
struct  SCI_REGS {
   union SCICCR_REG     SCICCR;     // Communications control register
   union SCICTL1_REG    SCICTL1;    // Control register 1
   uint16               SCIHBAUD;   // Baud rate (high) register
   uint16               SCILBAUD;   // Baud rate (low) register
   union SCICTL2_REG    SCICTL2;    // Control register 2
   union SCIRXST_REG    SCIRXST;    // Recieve status register
   uint16               SCIRXEMU;   // Recieve emulation buffer register
   union SCIRXBUF_REG   SCIRXBUF;   // Recieve data buffer  
   uint16               rsvd1;      // reserved
   uint16               SCITXBUF;   // Transmit data buffer 
   union SCIFFTX_REG    SCIFFTX;    // FIFO transmit register
   union SCIFFRX_REG    SCIFFRX;    // FIFO recieve register
   union SCIFFCT_REG    SCIFFCT;    // FIFO control register
   uint16               rsvd2;      // reserved
   uint16               rsvd3;      // reserved
   union SCIPRI_REG     SCIPRI;     // FIFO Priority control   
};

//---------------------------------------------------------------------------
// SCI External References & Function Declarations:
//
extern volatile struct SCI_REGS SciaRegs;
extern volatile struct SCI_REGS ScibRegs;
extern volatile struct SCI_REGS ScicRegs;

#ifdef __cplusplus
}
#endif /* extern "C" */

#endif  // end of DSP2833x_SCI_H definition

//===========================================================================
// End of file.
//===========================================================================


/* EOF */
