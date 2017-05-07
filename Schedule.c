/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Schedule.c                                                    **
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
#include "Task.h"
#include "Common.h"



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
StatusType Schedule
(
	void
)
{
	/* \req OSEK_SYS_3.4 The system service StatusType Schedule ( void ) shall
	 ** be defined */

	/* \req OSEK_SYS_3.4.4 Possible return values in Standard mode is E_OK */
	StatusType ret = E_OK;
	TaskType nexttask;
	TaskType actualtask;

	/* \req OSEK_SYS_3.3.5 Extra possible return values in Extended mode are E_OS
	 ** CALLEVEL, E_OS_RESOURCE  */
#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
   if ( ( GetCallingContext() != CONTEXT_TASK ) &&
		  ( GetCallingContext() != CONTEXT_SYS ) )
   {
		/* \req OSEK_SYS_3.3.5 Extra possible return values in Extended mode
		 ** are E_OS_CALLEVEL, E_OS_RESOURCE */
      ret = E_OS_CALLEVEL;
   }
	else if (GetRunningTask() != INVALID_TASK)
	{
		if ( TasksVar[GetRunningTask()].Resources != 0 )
      {
					/* \req OSEK_SYS_3.3.5 Extra possible return values in Extended mode
					 ** are E_OS_CALLEVEL, E_OS_RESOURCE */
               ret = E_OS_RESOURCE;
		}
	}
	else
	{
		/* nothing to check Runngin Task is invalid */
	}

	if (ret == E_OK)
#endif
	{
		/* get actual running task */
		actualtask = GetRunningTask();

		/* get next task */
		nexttask = GetNextTask();

		/* while until one or boths are not more invalid tasks */
		while (	( actualtask == INVALID_TASK ) &&
					( nexttask == INVALID_TASK) )
		{
			/* macro used to indicate the processor that we are in idle time */
			//osekpause();


			/* get next task */
			nexttask = GetNextTask();
			pRunningTask = NULL;
		};

		/* if the actual task is invalid */
		if ( actualtask == INVALID_TASK )
		{
			/* set task state to running */
			TasksVar[nexttask].Flags.State = RUNNING;

			/* set as running task */
			SetRunningTask(nexttask);

			/* set actual context task */
			SetActualContext(CONTEXT_TASK);

#if (HOOK_PRETASKHOOK == ENABLE)
			PreTaskHook();
#endif /* #if (HOOK_PRETASKHOOK == ENABLE) */

			/* jmp tp the next task */


			pRunningTask = TasksVar[nexttask].pTopOfStack;
		}

		else

		{
			/* check priorities */
			/* \req OSEK_SYS_3.4.1 If a task with a lower or equal priority than the
			 ** ceiling priority of the internal resource and higher priority than
			 ** the priority of the calling task is ready */
			if ( TasksConst[nexttask].StaticPriority > TasksVar[actualtask].ActualPriority )
			{

#if (HOOK_POSTTASKHOOK == ENABLE)
				PostTaskHook();
#endif /* #if (HOOK_POSTTASKHOOK == ENABLE) */

				/* \req OSEK_SYS_3.4.1.1 the internal resource of the task shall be
				 ** released */

				ReleaseInternalResources();
				/* \req OSEK_SYS_3.4.1.2 the current task is put into the ready state */
				TasksVar[actualtask].Flags.State = READY;

				/* set the new task to running */
			 	TasksVar[nexttask].Flags.State = RUNNING;

				/* set as running task */
				SetRunningTask(nexttask);
				/* set as running task */
				pRunningTask = TasksVar[nexttask].pTopOfStack;

#if (HOOK_PRETASKHOOK == ENABLE)
				PreTaskHook();
#endif /* #if (HOOK_PRETASKHOOK == ENABLE) */

				/* \req OSEK_SYS_3.4.1.3 its context is saved */
				/* \req OSEK_SYS_3.4.1.4 and the higher-priority task is executed */


				//SaveContext on the actualtask    Krisitan TODO:
				// load the context of the nexttask Krisitan TODO:
				//CallTask(actualtask, nexttask);
			}
			else
			{
				/* \req OSEK_SYS_3.4.2 Otherwise the calling task is continued */


			}

		}

	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-4/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-4/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//	if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_Schedule);
//		SetError_Ret(ret);
//		SetError_Msg("Schedule Task returns != than E_OK");
//		SetError_ErrorHook();
//	}
#endif

	return ret;
}

/* EOF */
