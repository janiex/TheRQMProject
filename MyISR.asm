;/******************************************************************************
;**                                                                           **
;**  SRC-MODULE: MyISR.asm                                                   **
;**                                                                           **
;**  Copyright (C) none (open standard)                                       **
;**                                                                           **
;**  TARGET    : Delfino TMS320F28335                                        **
;**                                                                           **
;**  COMPILER  : CCS                                                          **
;**                                                                           **
;**  PROJECT   : Open Source OSEK                                             **
;**                                                                           **
;**  AUTHOR    : Kristian Dilov                                               **
;**                                                                           **
;**  PURPOSE   : Scientific Research                                          **
;**                                                                           **
;**  REMARKS   : None                                                         **
;**                                                                           **
;**  PLATFORM DEPENDANT [yes/no]: yes                                         **
;**                                                                           **
;**  TO BE CHANGED BY USER [yes/no]: no                                       **
;**                                                                           **
;******************************************************************************/
;/******************************************************************************
;**                      Author Identity                                      **
;*******************************************************************************
;**                                                                           **
;** Initials     Name                       Organization                      **
;** --------     -------------------------  ----------------------------------**
;** KD           Kristian Dilov             TU-Sofia                          **
;**                                                                           **
;******************************************************************************/
;/*******************************************************************************
;** This file is genereted on: 9.3.2017 22:04:47                              **
;**                                                                            **
;*******************************************************************************/
; C Variables, used by the ISR.   
    .ref _SystemStack
    .ref _pRunningTask
    .global _Dispatch
    .text
		.sect "ramfuncs"
		; cpu_timer0_isr interrupt handler
		.def	_os_time_tick
_os_time_tick:

;*****************************************************
; The implementation follows the [R1] : 
; http://e2e.ti.com/support/microcontrollers/c2000/f/171/p/216045/1179541.aspx#1179541
;*****************************************************
    ASP
;*****************************************************
;                 START OF :
;                 SAVE CONTEXT
;*****************************************************
    PUSH       RB
    PUSH       AR1H:AR0H
    MOVL       *SP++,XT   ;according to [R1]
    MOVL       *SP++,XAR2
    MOVL       *SP++,XAR3
    MOVL       *SP++,XAR4
    MOVL       *SP++,XAR5
    MOVL       *SP++,XAR6
    MOVL       *SP++,XAR7
    MOV32      *SP++, STF ;according to [R1]
    MOV32      *SP++, R0H
    MOV32      *SP++, R1H
    MOV32      *SP++, R2H
    MOV32      *SP++, R3H
    MOV32      *SP++, R4H
    MOV32      *SP++, R5H
    MOV32      *SP++, R6H
    MOV32      *SP++, R7H
;*****************************************************
;                 END OF :
;                 SAVE CONTEXT
;*****************************************************
    SETFLG     RNDF32=1,RNDF64=1
    CLRC       OVM,PAGE0
    CLRC       AMODE
; This is the complete cycle of save context according to the documentation.
;*****************************************************
;                 START OF :
;PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
;*****************************************************
    MOVW       DP,#0x0033
    MOVB       @33,#0x01,UNC
;*****************************************************
;                 END OF :
;PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
;*****************************************************
; 1) Save the task's stack 
	MOV AL, SP
	MOV AR0, #_pRunningTask
	MOV *+XAR0[0],AL
; 2) We have to switch to the system stack
	MOV AL, #_SystemStack
	MOV SP,AL
; 3) Call the dispatch function. After its execution,
;pRunningTask shall carry the task to be activated.
	LCR        #_Dispatch
; 4) Load the stack pointer with the context of pRunningTask 
	MOV AL, @_pRunningTask
	MOV SP,AL
;*****************************************************
;                 START OF :
;                 RESTORE CONTEXT
;*****************************************************      
    MOV32      R7H, *--SP, UNCF
    MOV32      R6H, *--SP, UNCF
    MOV32      R5H, *--SP, UNCF
    MOV32      R4H, *--SP, UNCF
    MOV32      R3H, *--SP, UNCF
    MOV32      R2H, *--SP, UNCF
    MOV32      R1H, *--SP, UNCF
    MOV32      R0H, *--SP, UNCF
    MOV32      STF, *--SP ;according to [R1]
    MOVL       XAR7,*--SP
    MOVL       XAR6,*--SP
    MOVL       XAR5,*--SP
    MOVL       XAR4,*--SP
    MOVL       XAR3,*--SP
    MOVL       XAR2,*--SP
    MOVL       XT,*--SP ;according to [R1]
    POP        AR1H:AR0H
    POP        RB
;*****************************************************
;                 END OF :
;                 RESTORE CONTEXT
;*****************************************************  
    NASP
    IRET
    ;EOF
    

;/* EOF */
