/*******************************************************************************
**                                                                            **
**  SRC-MODULE: common.h                                                      **
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
#ifndef COMMON_H_
#define COMMON_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "OS_Types.h"


/**********************************************************************************************************************
 * VARIABLES DECLARATION
 *********************************************************************************************************************/
extern ContextType ActualContext;
extern TaskType RunningTask;
extern AppModeType ApplicationMode;
extern pStackPtr volatile pRunningTask;
/**********************************************************************************************************************
 * ACCESS MACROS
 *********************************************************************************************************************/
 /** param[in] newcontext valid values are:
 **               - CONTEXT_INVALID
 **               - CONTEXT_TASK
 **               - CONTEXT_ISR1
 **               - CONTEXT_ISR2
 **/
#define SetActualContext(newcontext)        \
	{										\
		ActualContext = (newcontext);		\
	}
#define GetCallingContext()   (ActualContext)
#define GetRunningTask()   (RunningTask)
#define SetRunningTask(newtask)  (RunningTask = (newtask) )
#define ReleaseInternalResources()							\
	{																	\
		/* set the priority to the normal value */		\
		TasksVar[GetRunningTask()].ActualPriority =		\
		TasksConst[GetRunningTask()].StaticPriority;		\
	}
#define GetCounter_Arch(CounterID) (CountersVar[CounterID].Time)
#define GetCounter(CounterID) GetCounter_Arch(CounterID)	
#define PostTaskHook()
#define PreTaskHook()	
#endif /*COMMON_H_*/

/* EOF */
