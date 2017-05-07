/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Task.h                                                        **
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
#ifndef TASK_H_
#define TASK_H_
#include "OS_Types.h"
/** \brief Task Constant type definition
 **
 ** This structure defines all constants and constant pointers
 ** needed to manage a task
 **
 ** \param EntryPoint pointer to the entry point for this task
 ** \param Priority static priority of this task
 ** \param MaxActivations maximal activations for this task
 **/
typedef struct {
	EntryPointType          EntryPoint;	
	StackPtrType            StackPtr;
	StackSizeType           StackSize;
	TaskPriorityType        StaticPriority;
	TaskActivationsType     MaxActivations;
	TaskFlagsType           ConstFlags;
	TaskEventsType          EventsMask;
	TaskResourcesType       ResourcesMask;
} TaskConstType;
/** \brief Task Variable type definition
 **
 ** This structure defines all variables needed to manage a task
 **
 ** \param ActualPriority actual priority of this task
 ** \param Activations actual activations on this task
 ** \param Flags flags variable of this task
 ** \param Events of this task
 ** \param Resource of this task
 **/
typedef struct {
	pStackPtr			pTopOfStack;
	TaskPriorityType    ActualPriority;
	TaskActivationsType Activations;
	TaskFlagsType       Flags;
	TaskEventsType      Events;
	TaskEventsType      EventsWait;
	TaskResourcesType   Resources;
} TaskVariableType;

/** \brief Auto Start Structure Type
 **
 ** \param Total taks on this application mode
 ** \param Reference to the tasks on this Application Mode
 **/
typedef struct {
	const TaskTotalType TotalTasks;
	TaskRefConstType TasksRef;
} AutoStartType;

extern const TaskConstType TasksConst[];
extern TaskVariableType TasksVar[];
extern void AddReady(TaskType TaskID);

extern ReadyVarType ReadyVar[];
extern const ReadyConstType ReadyConst[];
extern StatusType ActivateTask(TaskType TaskID);
extern void RemoveTask(TaskType TaskID);
extern TaskType GetNextTask(void);
extern StatusType GetTaskID (TaskRefType TaskID);
extern StatusType TerminateTask(void);
#endif /*TASK_H_*/

/* EOF */
