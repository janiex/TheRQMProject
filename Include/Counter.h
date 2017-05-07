/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Counter.h                                                     **
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
#ifndef COUNTER_H_
#define COUNTER_H_
#include "OS_Types.h"
#include "OS_cfg.h"
#include "common.h"
/************************************************************************************
 *                                 COUNTER TYPES                                    *
 ************************************************************************************/
typedef struct {
	BYTE	AlarmsCount;
	AlarmType* AlarmRef;
	TickType MaxAllowedValue;
	TickType MinCycle;
	TickType TicksPerBase;
} CounterConstType;

typedef struct {
	TickType Time;
}CounterVarType;

/************************************************************************************
 *                                 EXPORTED DATA                                    *
 ************************************************************************************/
extern CounterVarType CountersVar[];
extern const CounterConstType CountersConst[];
/************************************************************************************
 *                                 EXPORTED FUNCTION                                *
 ************************************************************************************/
extern StatusType IAdvanceCounter(CounterType CounterID);
extern AlarmIncrementType IncrementAlarm(AlarmType AlarmID, AlarmIncrementType Increment);
extern CounterIncrementType IncrementCounter(CounterType CounterID, CounterIncrementType Increment);
extern const AlarmType COUNTER_1_LIST[];
extern CounterVarType CountersVar[];
extern const CounterConstType CountersConst[];
#endif /*COUNTER_H_*/

/* EOF */
