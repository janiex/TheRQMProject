/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Macros.h                                                      **
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
#ifndef MACROS_H_
#define MACROS_H_
#define TRIM_STACK(a) a=(pStackPtr)(a - (pStackPtr)0x24)
#define StartIdle()\
	asm("          MOV AL, @_pRunningTask");\
	asm("          MOV SP,AL");\
	asm("          IRET");
	
	
#define RESTORE_CONTEXT()\
    asm("          MOV32      R7H, *--SP, UNCF");\
    asm("          MOV32      R6H, *--SP, UNCF");\
    asm("          MOV32      R5H, *--SP, UNCF");\
    asm("          MOV32      R4H, *--SP, UNCF");\
    asm("          MOV32      R3H, *--SP, UNCF");\
    asm("          MOV32      R2H, *--SP, UNCF");\
    asm("          MOV32      R1H, *--SP, UNCF");\
    asm("          MOV32      R0H, *--SP, UNCF");\
    asm("          MOV32      STF, *--SP");\
    asm("          MOVL       XAR7,*--SP");\
    asm("          MOVL       XAR6,*--SP");\
    asm("          MOVL       XAR5,*--SP");\
    asm("          MOVL       XAR4,*--SP");\
    asm("          MOVL       XAR3,*--SP");\
    asm("          MOVL       XAR2,*--SP");\
    asm("          MOVL       XT,*--SP");\ 
    asm("          POP        AR1H:AR0H");\
    asm("          POP        RB");\
    asm("          NASP");\
    asm("          IRET");
    
    
    #define LOAD_SYSTEM_CONTEXT()\
    asm("          MOV AL, #_SystemStack");\
    asm("          MOV SP,AL");
#endif /*MACROS_H_*/

/* EOF */
