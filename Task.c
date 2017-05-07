/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Task.c                                                        **
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
#include "OS_Types.h"
#include "Task.h"
#include "OS_cfg.h"
#include "common.h"
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
void AddReady(TaskType TaskID)
{
//#if 0
	TaskPriorityType    priority;
	TaskRefType         readylist;
	TaskTotalType       maxtasks;
	TaskTotalType       position;

	/* get task priority */
	priority = TasksConst[TaskID].StaticPriority;

	/* set the start priority for this task */
	TasksVar[TaskID].ActualPriority = priority;

	/* conver the priority to the array index */
	/* do not remove the -1 is needed. for example if READYLIST_COUNT is 4
	* the valida entries for this array are between 0 and 3, so the -1 is needed
	* since the lower priority is 0.
	*/
	priority = (TASKS_COUNT-1)-priority;

	/* get ready list */
	readylist = ReadyConst[priority].TaskRef;
	/* get max number of entries */
	maxtasks = ReadyConst[priority].ListLength;

	/* get position incrementtion */
	position = ReadyVar[priority].ListStart + ReadyVar[priority].ListCount;

	/* go arround maxtasks */
	/* this if works like  % instruction */
	if (position >= maxtasks)
	{
		position =  (TaskTotalType)(position - maxtasks);
	}

	/* set the task id in ready the list */
	readylist[position] = TaskID;
	/* increment the list counter */
	ReadyVar[priority].ListCount++;
//#endif
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
StatusType ActivateTask(TaskType TaskID)
{

	/* \req OSEK_SYS_3.1 The system service StatusType
	 * ActivateTask ( TaskType TaskID ) shall be defined. */

	/* \req OSEK_SYS_3.1.3 The service may be called from interrupt category 2
    * level and from task level. */
	/* nothing to do for this req. */

	/* \req OSEK_SYS_3.1.7-1/3 Possible return values in Standard mode are E_OK or E_OS_LIMIT */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check if the task id is valid */
	if ( TaskID >= TASKS_COUNT )
	{
		/* if an invalid task id return E_OS_ID */
		/* \req OSEK_SYS_3.1.5-1/3 If other than E_OK is returned the activation
		 * is ignored */
		/* \req OSEK_SYS_3.1.8 Added possible return values in Extended mode is
		 * E_OS_ID */
		ret = E_OS_ID;
	}
	else
#endif
	{
		IntSecure_Start();

		/* check if the task is susspended */
		/* \req OSEK_SYS_3.1.1-1/2 The task TaskID shall be transferred from the
		 * suspended state into the ready state. */
		if ( TasksVar[TaskID].Flags.State == SUSPENDED )
		{
			/* increment activation counter */
			TasksVar[TaskID].Activations++;
			/* if the task was suspended set it to ready */
			/* OSEK_SYS_3.1.1-2/2 The task TaskID shall be transferred from the
			 * suspended state into the ready state.*/
			TasksVar[TaskID].Flags.State = READY;
			/* clear all events */
			/* \req OSEK_SYS_3.1.6 When an extended task is transferred from
			 * suspended state into ready state all its events are cleared. */
			TasksVar[TaskID].Events = 0;
			/* add the task to the ready list */
			AddReady(TaskID);
		}
		else
		{
			/* task is not suspended */

			/* check if the task is a extended task */
			if ( TasksConst[TaskID].ConstFlags.Extended )
			{
				/* return E_OS_LIMIT */
				/* \req OSEK_SYS_3.1.5-2/3 If other than E_OK is returned the activation
				 * is ignored */
				/* \req OSEK_SYS_3.1.7-2/3 Possible return values in Standard mode are
				 * E_OK or E_OS_LIMIT */
				ret = E_OS_LIMIT;
			}
			else
			{
				/* check if more activations are allowed */
				if ( TasksVar[TaskID].Activations < TasksConst[TaskID].MaxActivations )
				{
					/* increment activation counter */
					TasksVar[TaskID].Activations++;
					/* add the task to the ready list */
					AddReady(TaskID);
				}
				else
				{
					/* maximal activation reached, return E_OS_LIMIT */
					/* \req OSEK_SYS_3.1.5-3/3 If other than E_OK is returned the
					 * activation is ignored */
					/* \req OSEK_SYS_3.1.7-3/3 Possible return values in Standard mode are
					 * E_OK or E_OS_LIMIT */
					ret = E_OS_LIMIT;
				}
			}
		}

		IntSecure_End();
#if (NON_PREEMPTIVE == DISABLE)

		
		if ( ( TasksConst[GetRunningTask()].ConstFlags.Preemtive ) &&
			  ( ret == E_OK )	)
		{
			/* \req OSEK_SYS_3.1.4 Rescheduling shall take place only if called from a
			 * preemptable task. */
			(void)Schedule();
		}
		
#endif /* #if (NON_PREEMPTIVE == DISABLE) */
	}

	return ret;
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
TaskType GetNextTask(void)
{
	BYTE loopi;
	boolean found = FALSE;
	TaskType ret = INVALID_TASK;

	/* check in all ready lists */
	for (loopi = 0; ( loopi < TASKS_COUNT ) && (!found) ; loopi++)
	{
		/* if one or more tasks are ready */
		if (ReadyVar[loopi].ListCount > 0)
		{
			/* return the first ready task */
			ret = ReadyConst[loopi].TaskRef[ReadyVar[loopi].ListStart];

			/* set found true */
			found = TRUE;
		}
	}

	return ret;
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
void RemoveTask(TaskType TaskID)
{
	TaskPriorityType priority;
	TaskTotalType maxtasks;

	/* get task priority */
	priority = TasksConst[TaskID].StaticPriority;
	/* conver the priority to the array index */
	/* do not remove the -1 is needed. for example if READYLIST_COUNT is 4
	* the valida entries for this array are between 0 and 3, so the -1 is needed
	* since the lower priority is 0.
	*/
	priority = (TASKS_COUNT-1)-priority;
	/* get max number of entries */
	maxtasks = ReadyConst[priority].ListLength;

	/* increment the ListStart */
	ReadyVar[priority].ListStart = ReadyVar[priority].ListStart + 1;

	/* go arround maxtasks */
	/* this if works like a % instruction */
	if (ReadyVar[priority].ListStart >= maxtasks)
	{
		ReadyVar[priority].ListStart -= maxtasks;
	}

	/* decrement the count of ready tasks */
	ReadyVar[priority].ListCount--;
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
StatusType TerminateTask(void)
{
	/* \req OSEK_SYS_3.2 The system service StatusType TerminateTask ( void )
	 ** shall be defined. */

	StatusType ret = E_OK;

	/* \req OSEK_SYS_3.2.4 If the version with extended status is used, the
	 ** service returns in case of error, and provides a status which can be
	 ** evaluated in the application. */
#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	if ( GetCallingContext() != CONTEXT_TASK )
	{
		/* \req OSEK_SYS_3.2.7-1/2 Possibly return values in Extended mode are
		 ** E_OS_RESOURCE or E_OS_CALLEVEL */
		ret = E_OS_CALLEVEL;
	}

#if ( (RESOURCES_COUNT != 0) || (NO_RES_SCHEDULER == DISABLE) )
	/* check if on or more resources are ocupied */
	else if (
#if (RESOURCES_COUNT != 0)
				 ( TasksVar[GetRunningTask()].Resources != 0 )
#endif /* #if (RESOURCES_COUNT != 0) */
#if ( (RESOURCES_COUNT != 0) && (NO_RES_SCHEDULER == DISABLE) )
					||
#endif /* #if ( (RESOURCES_COUNT != 0) && (NO_RES_SCHEDULER == DISABLE) ) */
#if (NO_RES_SCHEDULER == DISABLE)
				 ( TasksVar[GetRunningTask()].ActualPriority == TASK_MAX_PRIORITY )
#endif /* #if (NO_RES_SCHEDULER == DISABLE) */
			  )
	{
		/* \req OSEK_SYS_3.2.7-2/2 Possibly return values in Extended mode are
		 ** E_OS_RESOURCE or E_OS_CALLEVEL */
		ret = E_OS_RESOURCE;
	}
#endif /* #if ( (RESOURCES_COUNT != 0) || (NO_RES_SCHEDULER == DISABLE) ) */
	else
#endif /* #if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) */
	{

#if (HOOK_POSTTASKHOOK == ENABLE)
		PostTaskHook();
#endif /* #if (HOOK_POSTTASKHOOK == ENABLE) */

		IntSecure_Start();

		/* release internal resources */
		/* \req OSEK_SYS_3.2.2 If an internal resource is assigned to the calling
		 ** task, it is automatically released. */
		ReleaseInternalResources();

		/* There is a bug here - Activations become -1 Krisitan TODO:*/
		if (TasksVar[GetRunningTask()].Activations > 0)
			/* decrement activations for this task */
		{
			TasksVar[GetRunningTask()].Activations--;
		}
		//else
		//{while(1);}
		if (TasksVar[GetRunningTask()].Activations == 0)
		{
			/* if no more activations set state to suspended */
			/* \req OSEK_SYS_3.2.1 The calling task shall be transferred from the
			 ** running state into the suspended state. */
			TasksVar[GetRunningTask()].Flags.State = SUSPENDED;
			/* remove ready list */
			RemoveTask(GetRunningTask());
		}
		else
		{
			/* if more activations set state to ready */
			TasksVar[GetRunningTask()].Flags.State = READY;
		}

		/* set entry point for this task again */
		/* \req OSEK_SYS_3.1.2-3/3 The operating system shall ensure that the task
		 ** code is being executed from the first statement. */
		//SetEntryPoint(GetRunningTask()); //Kristian

		/* set running task to invalid */
		SetRunningTask(INVALID_TASK);
		/* set actual context SYS */
		SetActualContext(CONTEXT_SYS);

		IntSecure_End();

		/* call scheduler, never returns */
		/* \req OSEK_SYS_3.2.3 If the call was successful, TerminateTask does not
		 ** return to the call level and the status can not be evaluated. */
		/* \req OSEK_SYS_3.2.5 If the service TerminateTask is called
		 ** successfully, it enforces a rescheduling. */
		/* \req OSEK_SYS_3.2.6 This function will never returns in Standard
		 ** mode. */
		(void)Schedule();
	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-2/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-2/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//	if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_TerminateTask);
//		SetError_Ret(ret);
//		SetError_Msg("Terminate Task returns != than E_OK");
//		SetError_ErrorHook();
//	}
#endif

	return ret;
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
StatusType GetTaskState
(
	TaskType TaskID,
	TaskStateRefType State
)
{
	/* \req OSEK_SYS_3.6 The system service StatusType
	 ** GetTaskState ( TaskType TaskID, TaskStateRefType State ) shall be
	 ** defined. */

	/* \req OSEK_SYS_3.6.3Possible return values in Standard mode is E_OK */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check if TaskID is in a valid range */
	if ( TaskID >= TASKS_COUNT )
	{
		/* TaskID is out of range */
		/* return E_OS_ID */
		/* \req OSEK_SYS_3.6.4 Extra possible return values in Extended mode is
		 ** E_OS_ID */
		ret = E_OS_ID;

		/* set invalid task value to the state */
		*State = INVALID_STATE;
	}
	else
#endif
	{

		/* \req OSEK_SYS_3.6.1 The service shall returns the state of a task
		 ** (running, ready, waiting, suspended) at the time of calling
		 ** GetTaskState */
		/* \req OSEK_SYS_3.6.2 When the service is called for a task, which is
		 ** activated more than once, the state is set to running if any instance
		 ** of the task is running. */
		*State = (TaskStateType) TasksVar[TaskID].Flags.State;
	}

#if ( (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) && \
		(HOOK_ERRORHOOK == ENABLE) )
	/* \req OSEK_ERR_1.3-5/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-5/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
	{
		SetError_Api(OSServiceId_GetTaskState);
		SetError_Param1(TaskID);
		SetError_Param2((unsigned int)State);
		SetError_Ret(ret);
		SetError_Msg("GetTaskState returns != than E_OK");
		SetError_ErrorHook();
	}
#endif

	return ret;
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
StatusType GetTaskID
(
	TaskRefType TaskID
)
{
	/* \req OSEK_SYS_3.5 The system service StatusType
	 ** GetTaskID ( TaskRefType TaskID ) shall be defined */

	/* \req OSEK_SYS_3.5.1 Shall returns the information about the TaskID of
	 ** the task which is currently running */
	/* \req OSEK_SYS_3.5.2 If no task is currently running, the service returns
	 ** INVALID_TASK as TaskType */
	*TaskID = GetRunningTask();

	/* \req OSEK_SYS_3.5.3 This function returns always E_OK */
	return E_OK;
}

/* EOF */
