/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Main.c                                                        **
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
#include "Std_Types.h"
#include "InitHW.h"
#include "OS_cfg.h"
#include "common.h"
#include "OS_gen.h"
#include "Macros.h"
#include "Task.h"
/**********************************************************************************************************************
 *  FUNCTION VARIABLES
 *********************************************************************************************************************/
ContextType ActualContext;
TaskType RunningTask = INVALID_TASK;
pStackPtr volatile pRunningTask = NULL;
AppModeType ApplicationMode; 
/**********************************************************************************************************************
 *  FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 void StartOS(AppModeType Mode);
 static void StartOs_Arch(void);
 static BYTE CreatTask(TaskType TaskID);
 static void StartOs_Arch_Cpu(void);
 static StackPtrType InitialiseStack(StackPtrType pxTopOfStack, pFunc Func);
 #if (HOOK_STARTUPHOOK == ENABLE)
 void StartupHook(void);
 #endif
 void TerminateTsk(void);
/**********************************************************************************************************************
 *  FUNCTIONS 
 *********************************************************************************************************************/
uint32 main(void)
{
	/* 1. Init the necessary HW to Run the OS */
	InitHW();
#if(UART_DEBUG == ENABLE)	
	//SendString("\r\nI've got the power!\r\n");
#endif /* (UART_INTERFACE == ENABLE)	*/
	/* now start the OS */
	StartOS(OS_NORMAL_MODE);
	/* This fragment should never be reached ! */
	return 0;
	
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
void StartOS(AppModeType Mode)
{
	/* \req OSEK_SYS_3.25 The system service void
	 ** StartOS ( AppModeType Mode ) shall be defined */

	/* \req OSEK_SYS_3.25.1 This system service shall starts the operating
	 ** system */
	BYTE loopi;

	IntSecure_Start();

	/* save the aplication mode */
	ApplicationMode = Mode;

	/* StartOs_Arch  - the tasks are initiated with a IRQ like context */
	StartOs_Arch();

	/* set sys context */
	SetActualContext(CONTEXT_SYS);

	/* set actual task to invalid task */
	SetRunningTask(INVALID_TASK);
#if(TASKS_AUTOSTART_COUNT > 0)
	/*************************************************************************
	 * The autostar tasks are just started without other trigger,
	 * than the OS start-up. After that they can be executed by their trigger.
	 * ************************************************************************
	 */
	/* add to ready the corresponding tasks for this
    * Application Mode */
	for (loopi = 0; loopi < AutoStart[Mode].TotalTasks; loopi++)
	{
		/* activate task */
		ActivateTask(AutoStart[Mode].TasksRef[loopi]);
	}
#endif //(TASKS_AUTOSTART_COUNT > 0)
#if (ALARM_AUTOSTART_COUNT > 0)
	/* *************************************************************************
	 * The difference between autostart alarm and general one is
	 * only the starting point. General alarms are started in explicit way.
	 * Autostart alarms are started by the start-up of the system.
	 * *************************************************************************
	 * */
	for (loopi = 0; loopi < ALARM_AUTOSTART_COUNT; loopi++)
	{
		if (AutoStartAlarm[loopi].Mode == Mode)
		{
			(void)SetRelAlarm(AutoStartAlarm[loopi].Alarm, AutoStartAlarm[loopi].AlarmTime, AutoStartAlarm[loopi].AlarmCycleTime);
		}
	}
#endif

#if (HOOK_STARTUPHOOK == ENABLE)
	StartupHook();
#endif

	IntSecure_End();

	//SetRunningTask(GetRunningTask());
	Schedule();
	//SetRunningTask(Task_IDLE);
	/* set actual context task */
	SetActualContext(CONTEXT_TASK);
	
	pRunningTask = TasksVar[GetRunningTask()].pTopOfStack;
	TRIM_STACK(pRunningTask);
	StartIdle()
	/* The system shall never return here ! */ 
	while(1);
}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
static void StartOs_Arch(void)
{
	BYTE loopi;
	/* Init the stack spaces with patterns and water-marks                    */
	/* initialize the stacks of the system */
	/* init every task */
	for( loopi = 0; loopi < TASKS_COUNT; loopi++)
	{
		/* init stack */
		CreatTask(loopi);
	}
	/* Add the idle task into thre ready queue                                */
	//AddReady(Task_IDLE);
	/* call CPU dependent initialisation                                      */
	StartOs_Arch_Cpu();
	return;
}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
BYTE CreatTask(TaskType TaskID)
{
	StatusType result;
	if(TASKS_MAX_NUMBER >  TaskID)
	{
		TasksVar[TaskID].ActualPriority = TasksConst[TaskID].StaticPriority;
		TasksVar[TaskID].Activations    = TasksConst[TaskID].MaxActivations;
		TasksVar[TaskID].Flags          = TasksConst[TaskID].ConstFlags;
		TasksVar[TaskID].Resources      = 0;
		TasksVar[TaskID].Events         = 0; /* TODO */
		TasksVar[TaskID].EventsWait     = 0; /* TODO */
		TasksVar[TaskID].pTopOfStack    = InitialiseStack(
															TasksConst[TaskID].StackPtr,
															TasksConst[TaskID].EntryPoint															
															);
		result = E_OK;															
	}
	else
	{
		result = E_OS_LIMIT;
	}
	
return result;
}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
static void StartOs_Arch_Cpu(void)
{

	/* Set-up the tick timer interrupt										  */
	SetupTimerInterrupt();
	return;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
static StackPtrType InitialiseStack(StackPtrType pxTopOfStack, pFunc Func)
{				
		
		// ST0: for C runtime environment, it is presumed that OVM=0, PM=0
		*pxTopOfStack = 0x0000; 
		pxTopOfStack++;
		// T - upper 16-bit of Multiplicand Register, nothing presumed
		*pxTopOfStack = ( uint16 ) 0x0000; 
		pxTopOfStack++;
		// AL - Accumulator, nothing presumed
		*pxTopOfStack = ( uint16 ) 0x0000; 
		pxTopOfStack++;
		// AH - Accumulator, nothing presumed
		*pxTopOfStack = ( uint16 ) 0x0000; 
		pxTopOfStack++;
		// PL - Product Register, nothing presumed
		*pxTopOfStack = ( uint16 ) 0xAAAA; 
		pxTopOfStack++;
		// PH - Product Register, nothing presumed
		*pxTopOfStack = ( uint16 ) 0xBBBB; 
		pxTopOfStack++;
		// AR0 - Aux Register 0, nothing presumed
		*pxTopOfStack = ( uint16 ) 0xCCCC; 
		pxTopOfStack++;
		// AR1 - Aux Register 0, nothing presumed
		*pxTopOfStack = ( uint16 ) 0xDDDD; 
		pxTopOfStack++;
		// ST1: ARP(15-13) XF(12) M0M1MAP(11) Reserved(10) OBJMODE(9) AMODE(8) IDLESTAT(7)
		//      EALLOW(6) LOOP(5) SPA(4) VMAP(3) PAGE0(2) DBGM(1) INTM(0)
		//      presumed is PAGE0=0
		// 1: M0 and M1 mapping mode bit. The M0M1MAP bit should always remain set to 1 in the C28x object mode.
		// 0: Reserved
		// 1: C28x object mode (OBJMODE == 1)
		// 0: AMODE This bit is set to 0 on reset.
		// 0: IDLESTAT is not restored from the stack.
		// 0: When the CPU services an interrupt, the current value of EALLOW is saved on the
	    //   stack (when ST1 is saved on the stack), and then EALLOW is cleared. Therefore, at the
	    //   start of an interrupt service routine (ISR), access to protected registers is disabled. If the
	    //   ISR must access protected registers, it must include an EALLOW instruction. At the end
	    //   of the ISR, EALLOW can be restored by the IRET instruction.
	    // 0: Upon return from the interrupt, LOOP is not restored from the stack.
	    // 0: SPA = 0 The stack pointer has not been aligned to an even address.
	    // 1: VMAP = For normal operation leave this bit set.
	    // 0: PAGE0 = presumed at 0 by C compiler
	    // 0: DBGM: 0 = Debug events are enabled.
	    // 0: INTM: 0 Maskable interrupts are globally enabled.
	    //****************************************************************
	    // ST1 B: 0000 1010 0000 1000
		pxTopOfStack[0] =  0x8A08U; 		
		pxTopOfStack++;
		// DP - no assumptions made
		*pxTopOfStack = ( uint16 ) 0x0000; 
		pxTopOfStack++;
		// IER - interrupt enable register - probably needs to be passed as a parameter!
		*pxTopOfStack = 0x3001; 
		pxTopOfStack++;
		// DBGSTAT, emulation info - NOT SURE
		*pxTopOfStack = 0x001F; 
		pxTopOfStack++;
		// PCL
		*pxTopOfStack = ( uint16 ) ((unsigned long)Func & 0xFFFF); 
		pxTopOfStack++;
		// PCH
		*pxTopOfStack = ( uint16 ) (((unsigned long)Func >> 16) & 0xFFFF); 
		pxTopOfStack++; 
		// Before stack intro this is the content of the stack so far.
		/*****************************************************************/
		/* This is the top of the stack up to the automatic context save */
		/*****************************************************************/
		// RB low part
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		// RB high part
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		
		//this is like the stack looks like when enter in ISR
		// Remaining ARH0 from XAR0
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		// Remaining ARH1 from XAR1
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		// PUSH XT
		*pxTopOfStack = ( uint16 ) 0x0000;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x0000; 
		pxTopOfStack++;
		// PUSH *SP++,XAR2
		*pxTopOfStack = ( uint16 ) 0x2222;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x2222; 
		pxTopOfStack++;
		// PUSH *SP++,XAR3
		*pxTopOfStack = ( uint16 ) 0x3333;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x3333; 
		pxTopOfStack++;
		// PUSH *SP++,XAR4
		*pxTopOfStack = ( uint16 ) 0x4444;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x4444; 
		pxTopOfStack++;
		// PUSH *SP++,XAR5
		*pxTopOfStack = ( uint16 ) 0x5555;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x5555; 
		pxTopOfStack++;
		// PUSH *SP++,XAR6
		*pxTopOfStack = ( uint16 ) 0x6666;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x6666; 
		pxTopOfStack++;
		// PUSH *SP++,XAR7
		*pxTopOfStack = ( uint16 ) 0x7777;  
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0x7777; 
		pxTopOfStack++;
		// STF low part
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		// STF high part
		*pxTopOfStack = ( uint16 ) 0; 
		pxTopOfStack++;
		
		
		/*************************************/
		/*     FPU Registers                 */
		/*************************************/
		// R0H 
		*pxTopOfStack = ( uint16 ) 0xF0F0; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF0F0; 
		pxTopOfStack++;
		// R1H 
		*pxTopOfStack = ( uint16 ) 0xF1F1; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF1F1; 
		pxTopOfStack++;
		// R2H 
		*pxTopOfStack = ( uint16 ) 0xF2F2; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF2F2; 
		pxTopOfStack++;
		// R3H 
		*pxTopOfStack = ( uint16 ) 0xF3F3; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF3F3; 
		pxTopOfStack++;
		// R4H 
		*pxTopOfStack = ( uint16 ) 0xF4F4; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF4F4; 
		pxTopOfStack++;
		// R5H 
		*pxTopOfStack = ( uint16 ) 0xF5F5; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF5F5; 
		pxTopOfStack++;
		// R6H 
		*pxTopOfStack = ( uint16 ) 0xF6F6; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF6F6; 
		pxTopOfStack++;
		// R7H 
		*pxTopOfStack = ( uint16 ) 0xF7F7; 
		pxTopOfStack++;
		*pxTopOfStack = ( uint16 ) 0xF7F7; 
		pxTopOfStack++;
		return pxTopOfStack;
}
#if (HOOK_STARTUPHOOK == ENABLE)
void StartupHook(void)
{
	/* Start the necessary non autostart alarms                              */
	/* Alarm ID, Initial Offset, Cyclic Period                               */
	//SetRelAlarm(!!! YOU HAVE TO START THE NON AUTOSTART ALARMS HERE !!! );
	
	return;
}
#endif /* HOOK_STARTUPHOOK == ENABLE */
void Dispatch(void)
{
	register int i;
	//update the stack pointer for the task
	TasksVar[GetRunningTask()].pTopOfStack = pRunningTask;
	for(i=0; i<COOUNTERS_FOR_TIMER_A; i++)
	{
		(void)IAdvanceCounter(Timer_A_Counters[i]);	
	}
	// just in case the task is pre-emptive check for higher priority
	if(TasksConst[GetRunningTask()].ConstFlags.Preemtive){
		Schedule();
	}
}


void TerminateTsk(void)
{
	LOAD_SYSTEM_CONTEXT();
	CreatTask(GetRunningTask());
	TerminateTask();
    asm("          MOV AL, @_pRunningTask");
    asm("          MOV SP,AL");
    asm("          MOV32      R7H, *--SP, UNCF");
    asm("          MOV32      R6H, *--SP, UNCF");
    asm("          MOV32      R5H, *--SP, UNCF");
    asm("          MOV32      R4H, *--SP, UNCF");
    asm("          MOV32      R3H, *--SP, UNCF");
    asm("          MOV32      R2H, *--SP, UNCF");
    asm("          MOV32      R1H, *--SP, UNCF");
    asm("          MOV32      R0H, *--SP, UNCF");
    asm("          MOV32      STF, *--SP");
    asm("          MOVL       XAR7,*--SP");
    asm("          MOVL       XAR6,*--SP");
    asm("          MOVL       XAR5,*--SP");
    asm("          MOVL       XAR4,*--SP");
    asm("          MOVL       XAR3,*--SP");
    asm("          MOVL       XAR2,*--SP");
    asm("          MOVL       XT,*--SP"); 
    asm("          POP        AR1H:AR0H");
    asm("          POP        RB");
    asm("          NASP");
    asm("          IRET");
}

/* EOF */
