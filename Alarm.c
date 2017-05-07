/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Alarm.c                                                       **
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
#include "Alarm.h"
#include "Counter.h"
#include "Task.h"

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
#if (ALARMS_COUNT != 0)
AlarmIncrementType IncrementAlarm(AlarmType AlarmID, AlarmIncrementType Increment)
{
	AlarmIncrementType RestIncrements;
	AlarmIncrementType AlarmCount;
	CounterIncrementType CounterIncrement;    

	/* init arlarms count */
	AlarmCount = 0;

	/* check if the increment is smaller than the expiration time */
	if ( AlarmsVar[AlarmID].AlarmTime > Increment )
	{
		/* decrement the alarm*/
		AlarmsVar[AlarmID].AlarmTime -= Increment;

		/* alarm doesn't expires now */
		RestIncrements = AlarmsVar[AlarmID].AlarmTime;
	}
	else
	{
		/* increment is graeter or equal than the alarm time, the alarm may
			expire one or more times */

		/* check if new alarm time has to be set */
		if(AlarmsVar[AlarmID].AlarmCycleTime == 0)
		{
			/* in case of a non cyclic alarm */

			/* alarm has expires 1 time */
			AlarmCount = 1;

			/* set alarm to 0 */
			AlarmsVar[AlarmID].AlarmTime = 0;

			/* disable alarm */
			AlarmsVar[AlarmID].AlarmState = 0;

			/* set rest increments to zero */
			RestIncrements = 0;
		}
		else
		{
			/* the alarm is cyclic */

			/* decrement alarm */
			while ( AlarmsVar[AlarmID].AlarmTime <= Increment )
			{
				/* add cycle time */
				AlarmsVar[AlarmID].AlarmTime += AlarmsVar[AlarmID].AlarmCycleTime;

				/* increment Alarms expiration times */
				AlarmCount++;
			}

			/* decrement the increments of this alarm */
			AlarmsVar[AlarmID].AlarmTime -= Increment;

			/* store the rest increments */
			RestIncrements = AlarmsVar[AlarmID].AlarmTime;
		}

		if (AlarmsConst[AlarmID].AlarmAction == INCREMENT)
		{
			/* call counter function */
			CounterIncrement = IncrementCounter(AlarmsConst[AlarmID].AlarmActionInfo.Counter, AlarmCount);

			/* re-calculate the rest of the increments */
			RestIncrements += AlarmsVar[AlarmID].AlarmCycleTime * ( CounterIncrement-1 );
		}
		else
		{
			/* execute the alarm so many times as needed */
			for ( ;AlarmCount > 0; AlarmCount--)
			{
				/* check alarm actions differents to INCREMENT */
				switch(AlarmsConst[AlarmID].AlarmAction)
				{
					case ACTIVATETASK:
						/* activate task */
                        ActivateTask(AlarmsConst[AlarmID].AlarmActionInfo.TaskID);
						break;
					case ALARMCALLBACK:
						/* callback */
						if(AlarmsConst[AlarmID].AlarmActionInfo.CallbackFunction != NULL)
						{
							AlarmsConst[AlarmID].AlarmActionInfo.CallbackFunction();
						}
						break;
#if (EVENT_ENABLED == ENABLED)
					case SETEVENT:
                        // TODO: Kristian enable this, when task is ready.
                        /* set event */
						// SetEvent(AlarmsConst[AlarmID].AlarmActionInfo.TaskID, AlarmsConst[AlarmID].AlarmActionInfo.Event);
						break;
#endif /* #if (EVENT_ENABLED == ENABLED) */
					default:
						/* some error */
						/* possibly TODO, report an error */
						break;
				}
			}
		}
	}

	return RestIncrements;
}
#endif /* #if (ALARMS_COUNT != 0) */
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
StatusType SetRelAlarm
(
	AlarmType AlarmID,
	TickType Increment,
	TickType Cycle
)
{
	/* \req OSEK_SYS_3.21 The system service StatusType
	 ** SetRelAlarm ( AlarmType AlarmID, TickType Increment, TickType Cycle )
	 ** shall be defined */

	/* \req OSEK_SYS_3.21.3-1/2 Possible return values in Standard mode are
	 ** E_OK, E_OS_STATE */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check if the alarm id is in range */
	if(AlarmID >= ALARMS_COUNT)
	{
		/* \req OSEK_SYS_3.21.4-1/2 Extra possible return values in Extended mode are
		 ** E_OS_ID, E_OS_VALUE */
		ret = E_OS_ID;
	}
	/* check that increment and cycle are in range */
	else if( (Increment > CountersConst[AlarmsConst[AlarmID].Counter].MaxAllowedValue) ||
				( ( Cycle != 0 ) && 
				  ( (Cycle > CountersConst[AlarmsConst[AlarmID].Counter].MaxAllowedValue) ||
				    (Cycle < CountersConst[AlarmsConst[AlarmID].Counter].MinCycle) ) ) )
	{
		/* \req OSEK_SYS_3.21.4-2/2 Extra possible return values in Extended mode are
		 ** E_OS_ID, E_OS_VALUE */
		ret = E_OS_VALUE;
	}
	else
#endif
	/* check if the alarm is disable */
	if(AlarmsVar[AlarmID].AlarmState != 0)
   {
		/* \req OSEK_SYS_3.21.3-2/2 Possible return values in Standard mode are
		** E_OK, E_OS_STATE */
		ret = E_OS_STATE;
	}
	else
	{
		IntSecure_Start();

		/* enable alarm */
		AlarmsVar[AlarmID].AlarmState = 1;

		/* set alarm */
		AlarmsVar[AlarmID].AlarmTime = Increment;
		AlarmsVar[AlarmID].AlarmCycleTime = Cycle;

		IntSecure_End();
	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-13/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-13/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_SetRelAlarm);
//      SetError_Param1(AlarmID);
//		SetError_Param2(Increment);
//		SetError_Param3(Cycle);
//      SetError_Ret(ret);
//      SetError_Msg("SetRelAlarm returns != than E_OK");
//      SetError_ErrorHook();
//   }
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
StatusType SetAbsAlarm
(
	AlarmType AlarmID,
	TickType Start,
	TickType Cycle
)
{
	/* \req OSEK_SYS_3.22 The system service StatusType
	 ** SetAbsAlarm ( AlarmType AlarmID, TickType Start, TickType Cycle )
	 ** shall be defined */

	/* \req OSEK_SYS_3.22.3-1/2 Possible return values in Standard mode are E_OK,
	 ** E_OS_STATE */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check if the alarm id is in range */
	if(AlarmID >= ALARMS_COUNT)
	{
		/* \req OSEK_SYS_3.22.4-1/2 Extra possible return values in Extended mode
		 ** are E_OS_ID, E_OS_VALUE */
		ret = E_OS_ID;
	}
	/* check that increment and cycle are in range */
	else if( (Start > CountersConst[AlarmsConst[AlarmID].Counter].MaxAllowedValue) ||
				( ( Cycle != 0 ) &&
					( (Cycle > CountersConst[AlarmsConst[AlarmID].Counter].MaxAllowedValue) ||
						(Cycle < CountersConst[AlarmsConst[AlarmID].Counter].MinCycle) ) ) )
	{
		/* \req OSEK_SYS_3.22.4-2/2 Extra possible return values in Extended mode
		 ** are E_OS_ID, E_OS_VALUE */
		ret = E_OS_VALUE;
	}
	else
#endif
	/* check if the alarm is disable */
	if(AlarmsVar[AlarmID].AlarmState != 0)
   {
		/* \req OSEK_SYS_3.22.3-2/2 Possible return values in Standard mode are E_OK,
		 ** E_OS_STATE */
      ret = E_OS_STATE;
   }
	else
	{

		IntSecure_Start();

		/* enable alarm */
		AlarmsVar[AlarmID].AlarmState = 1;

		/* set abs alarm */
		AlarmsVar[AlarmID].AlarmTime = GetCounter(AlarmsConst[AlarmID].Counter) + Start;
		AlarmsVar[AlarmID].AlarmCycleTime = Cycle;

		IntSecure_End();
	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-14/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-14/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_SetAbsAlarm);
//		SetError_Param1(AlarmID);
//		SetError_Param2(Start);
//		SetError_Param3(Cycle);
//		SetError_Ret(ret);
//		SetError_Msg("SetAbsAlarm returns != than E_OK");
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
StatusType GetAlarmBase
(
	AlarmType AlarmID,
	AlarmBaseRefType Info
)
{
	/* \req OSEK_SYS_3.19 The system service StatusType
	 ** GetAlarmBase ( AlarmType AlarmID, AlarmBaseRefType Info )
	 ** shall be defined. */

	/* \req OSEK_SYS_3.19.2 Possible return values in Standard mode is E_OK */
	StatusType ret = E_OK;

	CounterType counter;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check that the AlarmID is in range */
	if(AlarmID >= ALARMS_COUNT)
	{
		/* \req OSEK_SYS_3.19.: Extra possible return values in Extended mode
		 ** is E_OS_ID */
		ret = E_OS_ID;
	}
	else
#endif
	{
		/* get counter of this alarm */
		counter = AlarmsConst[AlarmID].Counter;

		/* \req OSEK_SYS_3.19.1 The system service GetAlarmBase reads the alarm base
		 ** characteristics. The return value Info is a structure in which the
		 ** information of data type AlarmBaseType is stored */
		Info->maxallowedvalue = CountersConst[counter].MaxAllowedValue;
		Info->ticksperbase = CountersConst[counter].TicksPerBase;
		Info->mincycle = CountersConst[counter].MinCycle;
	}

#if ( (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) && \
	 	(HOOK_ERRORHOOK == ENABLE) )
	/* \req OSEK_ERR_1.3-12/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-12/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
	if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
	{
		SetError_Api(OSServiceId_GetAlarmBase);
		SetError_Param1(AlarmID);
		SetError_Param2((uint32)Info);
		SetError_Ret(ret);
		SetError_Msg("GetAlarmBase returns != than E_OK");
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
StatusType GetAlarm
(
	AlarmType AlarmID,
	TickRefType Tick
)
{
	/* \req OSEK_SYS_3.20 The system service StatusType
	 ** GetAlarm ( AlarmType AlarmID, TickRefType Tick) shall be defined */

	/* \req OSEK_SYS_3.20.2 Possible return values in Standard mode is E_OK */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)
	/* check if it handle of a valid AlarmID */
	if (AlarmID >= ALARMS_COUNT)
	{
		/* \req OSEK_SYS_3.20.3-1/2 Extra possible return values in Extended mode
		 ** are E_OS_NOFUNC, E_OS_ID */
		ret = E_OS_ID;
	}
	else
#endif /* #if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED) */
	/* check if the alarm is running */
	if(AlarmsVar[AlarmID].AlarmState == 0)
	{
		/* \req OSEK_SYS_3.20.3-2/2 Extra possible return values in Extended mode
		 ** are E_OS_NOFUNC, E_OS_ID */
		ret = E_OS_NOFUNC;
	}
	else

	{
		/* \req OSEK_SYS_3.20.1 The system service GetAlarm shall return the
		 ** relative value in ticks before the alarm AlarmID expires */
		*Tick = AlarmsVar[AlarmID].AlarmTime;
	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-12/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-12/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_GetAlarm);
//      SetError_Param1(AlarmID);
//		SetError_Param2((uint32)Tick);
//      SetError_Ret(ret);
//      SetError_Msg("GetAlarm returns != than E_OK");
//      SetError_ErrorHook();
//   }
#endif /* #if (HOOK_ERRORHOOK == ENABLE) */
	
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
StatusType CancelAlarm
(
	AlarmType AlarmID
)
{
	/* \req OSEK_SYS_3.23 The system service StatusType
	 ** CancelAlarm ( AlarmType AlarmID ) shall be defined */

	/* \req OSEK_SYS_3.23.2-1/2 Possible return values in Standard mode are
	 ** E_OK, E_OS_NOFUNC */
	StatusType ret = E_OK;

#if (ERROR_CHECKING_TYPE == ERROR_CHECKING_EXTENDED)	
	/* check if alarm id is in the valid range */
	if(AlarmID >= ALARMS_COUNT)
	{
		/* \req SEK_SYS_3.23.3: Extra possible return values in Extended mode ar
		 **  E_OS_ID */
		ret = E_OS_ID;
	}
	else
#endif
	if(AlarmsVar[AlarmID].AlarmState == 0)
	{
		/* \req OSEK_SYS_3.23.2-2/2 Possible return values in Standard mode are
		 ** E_OK, E_OS_NOFUNC */
		ret = E_OS_NOFUNC;
	}
	else
	{
		/* \req OSEK_SYS_3.23.1 The system service shall cancel the alarm AlarmID */
		AlarmsVar[AlarmID].AlarmState = 0;
	}

#if (HOOK_ERRORHOOK == ENABLE)
	/* \req OSEK_ERR_1.3-15/xx The ErrorHook hook routine shall be called if a
	 ** system service returns a StatusType value not equal to E_OK.*/
	/* \req OSEK_ERR_1.3.1-15/xx The hook routine ErrorHook is not called if a
	 ** system service is called from the ErrorHook itself. */
//   if ( ( ret != E_OK ) && (ErrorHookRunning != 1))
//	{
//		SetError_Api(OSServiceId_CancelAlarm);
//		SetError_Param1(AlarmID);
//		SetError_Ret(ret);
//		SetError_Msg("CancelAlarm returns != than E_OK");
//		SetError_ErrorHook();
//	}
#endif
	
	return ret;
}


/* EOF */
