/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Alarm.h                                                       **
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
#ifndef ALARM_H_
#define ALARM_H_
#include "OS_Types.h"
typedef struct {
	CallbackType CallbackFunction;
	TaskType TaskID;
#if(0 != EVENT_ENABLED)
    EventMaskType Event;
#endif
	CounterType Counter;
} AlarmActionInfoType;

/** \brief Alarm Variable Type */
typedef struct {
	AlarmStateType AlarmState;
	AlarmTimeType AlarmTime;
	AlarmCycleTimeType AlarmCycleTime;
} AlarmVarType;

/** \brief Alarm Constant Type */
typedef struct {
	CounterType Counter;
	AlarmActionType AlarmAction;
	AlarmActionInfoType AlarmActionInfo;
} AlarmConstType;

/** \brief Auto Start Alarm Type */
typedef struct {
	AppModeType Mode;
	AlarmType Alarm;
	AlarmTimeType AlarmTime;
	AlarmCycleTimeType AlarmCycleTime;
} AutoStartAlarmType;
/************************************************************************************
 *                                 EXPORTED FUNCTION                                *
 ************************************************************************************/
extern AlarmVarType AlarmsVar[];
extern const AlarmConstType AlarmsConst[];
extern AlarmIncrementType IncrementAlarm(AlarmType AlarmID, AlarmIncrementType Increment);
extern StatusType SetRelAlarm
(
	AlarmType AlarmID,
	TickType Increment,
	TickType Cycle
);
extern StatusType CancelAlarm
(
	AlarmType AlarmID
);
extern StatusType GetAlarm
(
	AlarmType AlarmID,
	TickRefType Tick
);
extern StatusType SetAbsAlarm
(
	AlarmType AlarmID,
	TickType Start,
	TickType Cycle
);
#endif /*ALARM_H_*/

/* EOF */
