/*******************************************************************************
**                                                                            **
**  SRC-MODULE: OS_gen.h                                                      **
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
#if(MAGIC_NUMBER != 30511208)
    #error "Inplausible genereted source files"
#endif /* (MAGIC_NUMBER != 30511208 */
#ifndef OS_GEN_H_
#define OS_GEN_H_
#include "Counter.h"
#include "OS_Cfg.h"
#include "Alarm.h"
#include "Task.h"

extern void TASK_ACC_code(void);
extern void TASK_ISO2631_code(void);
extern void TASK_Init_code(void);
extern void Task_IDLE_code(void);

uint16 TaskStack0[StackSizeTask0];
uint16 TaskStack1[StackSizeTask1];
uint16 TaskStack2[StackSizeTask2];
uint16 TaskIdleStack[64];
volatile uint16 SystemStack[SystemStackSize];


/******************************************************************************
 *                         TIMER_A associated counters                        *
 ******************************************************************************/
CounterType Timer_A_Counters[COOUNTERS_FOR_TIMER_A]=
{
/* Counters connected to TIMER_A */
    COUNTER_SYS,
};

/******************************************************************************
 *                         COUNTERS DATA                                      *
 ******************************************************************************/

/* these alarms have to be incremented with COUNTER_SYS*/
const AlarmType COUNTER_SYS_LIST[COUNTER_SYS_ALARMS_COUNT]=
{
   ALARM_ACC,
   ALARM_ISO2631,
};

/******************************************************************************
 *                Variable descriptors for the counters                       *
 ******************************************************************************/
CounterVarType CountersVar[COUNTER_COUNT]=
{
    /* COUNTER_SYS */
    {0},
};

/******************************************************************************
 *                Constant descriptors for the counters                       *
 ******************************************************************************/
const CounterConstType CountersConst[COUNTER_COUNT]=
{
    /* COUNTER_SYS */
    {
        COUNTER_SYS_ALARMS_COUNT, /* number of alarms associated with the counter*/
        (AlarmType*)COUNTER_SYS_LIST,
        1000000, /*  max allowed value */
        1, /* min cycle */
        1000, /*ticks per base */
    },
};
/******************************************************************************
 *                Variable descriptors for the alarms                         *
 ******************************************************************************/
AlarmVarType AlarmsVar[ALARMS_COUNT]=
{
    {
        /* ALARM_ACC */
        (AlarmStateType)0, /* Alarm state */
        (AlarmTimeType)0, /* Alarm Time */
        (AlarmCycleTimeType)0, /*Alarm Cyclic Time*/
    },
    {
        /* ALARM_ISO2631 */
        (AlarmStateType)0, /* Alarm state */
        (AlarmTimeType)0, /* Alarm Time */
        (AlarmCycleTimeType)0, /*Alarm Cyclic Time*/
    },
};

/******************************************************************************
 *                Constant descriptors for the alarms                         *
 ******************************************************************************/
const AlarmConstType AlarmsConst[ALARMS_COUNT]=
{
    /* ALARM_ACC */
    COUNTER_SYS, /* Associated Counter */
    ACTIVATETASK, /* Alarm action */
    {
        (CallbackType )NULL, /* no callback */
        TASK_ACC, /* Task associated with the alarm */
#if(0 != EVENT_ENABLED)
        (EventMaskType)0, /* No Event is assiciated with the alarm */
#endif /* (0 != EVENT_ENABLED) */
        (AlarmType)0, /* Reserved field... */
    },
    /* ALARM_ISO2631 */
    COUNTER_SYS, /* Associated Counter */
    ACTIVATETASK, /* Alarm action */
    {
        (CallbackType )NULL, /* no callback */
        TASK_ISO2631, /* Task associated with the alarm */
#if(0 != EVENT_ENABLED)
        (EventMaskType)0, /* No Event is assiciated with the alarm */
#endif /* (0 != EVENT_ENABLED) */
        (AlarmType)0, /* Reserved field... */
    },
};
/******************************************************************************
 *             Constant descriptors for auto-start alarms                     *
 ******************************************************************************/

const AutoStartAlarmType AutoStartAlarm[ALARM_AUTOSTART_COUNT]=
{
    /* ALARM_ACC is set to autostart */
    {
         0, /* Active for this application mode */
         ALARM_ACC, /* Alarm ID */
         5, /* Alarm Time */
         5, /* Cyclic Period */
    },
    /* ALARM_ISO2631 is set to autostart */
    {
         0, /* Active for this application mode */
         ALARM_ISO2631, /* Alarm ID */
         23, /* Alarm Time */
         20, /* Cyclic Period */
    },
};
/******************************************************************************
 *                Constant descriptors for the TASKS                          *
 ******************************************************************************/
const TaskConstType TasksConst[TASKS_COUNT] =
{
    /* TASK_ACC */
    {
        TASK_ACC_code, /* Task entry point */
        (StackPtrType )&TaskStack0, /* Pointer to Task's stack area*/
        StackSizeTask0, /* stack size */
        2, /*Task Priority (90) */
        1, /* task max activations */
        {
            0, /* BASIC Task */
            0, /* NON Pre-emptive Task */
            0, /* Task initial state - SUSPENDED */
        },  /* task const flags */
        (EventMaskType)0,/* Task's events mask */
        0,/* Task's resource mask */
    },
    /* TASK_ISO2631 */
    {
        TASK_ISO2631_code, /* Task entry point */
        (StackPtrType )&TaskStack1, /* Pointer to Task's stack area*/
        StackSizeTask1, /* stack size */
        1, /*Task Priority (50) */
        1, /* task max activations */
        {
            0, /* BASIC Task */
            0, /* NON Pre-emptive Task */
            0, /* Task initial state - SUSPENDED */
        },  /* task const flags */
        (EventMaskType)0,/* Task's events mask */
        0,/* Task's resource mask */
    },
    /* TASK_Init */
    {
        TASK_Init_code, /* Task entry point */
        (StackPtrType )&TaskStack2, /* Pointer to Task's stack area*/
        StackSizeTask2, /* stack size */
        3, /*Task Priority (99) */
        1, /* task max activations */
        {
            0, /* BASIC Task */
            0, /* NON Pre-emptive Task */
            0, /* Task initial state - SUSPENDED */
        },  /* task const flags */
        (EventMaskType)0,/* Task's events mask */
        0,/* Task's resource mask */
    },
    /* Task_IDLE */
    {
        Task_IDLE_code, /* Task entry point */
        (StackPtrType )&TaskIdleStack, /* Pointer to Task's stack area*/
        64, /* stack size */
        0, /* Idle task has lowest pirority in the system - 0 */
        1, /* task max activations */
        {
            0, /* BASIC Task */
            1, /* Idle Task is always pre-emptive */
            0, /* Idle task initial state - SUSPENDED */
        },  /* task const flags */
        (EventMaskType)0,/* No events for Idle Task */
        0/* No Resources for Idle Task */
    }
};

/******************************************************************************
 *                Variable descriptors for the TASKS                          *
 ******************************************************************************/
TaskVariableType TasksVar[TASKS_COUNT]; /* Initialized during the start-up phase */

/******************************************************************************
 *                Static queue for tasks in READY state                       *
 ******************************************************************************/
TaskType ReadyList0[1];
TaskType ReadyList1[1];
TaskType ReadyList2[1];
TaskType ReadyList3[1];
ReadyVarType ReadyVar[TASKS_COUNT]=
{
    {
        0, /* List Start - empty */
        0 /* List Count - empty */
    },
    {
        0, /* List Start - empty */
        0 /* List Count - empty */
    },
    {
        0, /* List Start - empty */
        0 /* List Count - empty */
    },
    {
        0, /* List Start - empty */
        0 /* List Count - empty */
    },
};


const ReadyConstType ReadyConst[TASKS_COUNT] =
{
    {
        1, /*  Length of this ready list */
        ReadyList3, /*  Pointer to the Ready List */
    },
    {
        1, /*  Length of this ready list */
        ReadyList2, /*  Pointer to the Ready List */
    },
    {
        1, /*  Length of this ready list */
        ReadyList1, /*  Pointer to the Ready List */
    },
    {
        1, /*  Length of this ready list */
        ReadyList0, /*  Pointer to the Ready List */
    },
};


/******************************************************************************
 *           Constant descriptors for the auto-start TASKS                    *
 ******************************************************************************/
const TaskType AutoStartReadyList[TASKS_AUTOSTART_COUNT] = 
{
    TASK_Init,
    Task_IDLE
};
const AutoStartType AutoStart[OS_NUMBER_OF_MODES] = 
{
    TASKS_AUTOSTART_COUNT,
    AutoStartReadyList
};


#endif /* OS_GEN_H_ */

/* EOF */
