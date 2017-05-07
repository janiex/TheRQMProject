/*******************************************************************************
**                                                                            **
**  SRC-MODULE: OS_Cfg.h                                                      **
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

#ifndef _OS_CFG_
#define _OS_CFG_

#define DISABLE                         0
#define ENABLE                          1

#define PREEMPTIVE						1
#define NON_PREMPTIVE					0

/** rief ERROR_CHECKING_STANDARD */
#define ERROR_CHECKING_STANDARD         1
/** rief ERROR_CHECKING_EXTENDED */
#define ERROR_CHECKING_EXTENDED         2

/*****************************************************************************
 *                     OS MODES OF OPERATION                                 *
 *****************************************************************************/
#define OS_NORMAL_MODE        0
#define OS_NUMBER_OF_MODES    1
/*****************************************************************************
 *                        OS OBJECTS COUNT                                   *
 *****************************************************************************/
#define COUNTER_COUNT         1
#define ALARMS_COUNT          2
#define TASKS_COUNT           4
#define COUNTER_SYS_ALARMS_COUNT        2
#define ALARM_AUTOSTART_COUNT 2
#define TASKS_AUTOSTART_COUNT 2
#define READYLISTS_COUNT         TASKS_COUNT
#define TASKS_MAX_NUMBER         TASKS_COUNT

/*****************************************************************************
 *                            COUNTERS                                       *
 *****************************************************************************/
#define COUNTER_SYS    0
#define COOUNTERS_FOR_TIMER_A    1

/*****************************************************************************
 *                              ALARMS                                       *
 *****************************************************************************/
#define    ALARM_ACC    0
#define    ALARM_ISO2631    1
/*****************************************************************************
 *                              TASKS                                        *
 *****************************************************************************/
#define    TASK_ACC   0
#define    TASK_ISO2631   1
#define    TASK_Init   2
#define    Task_IDLE    3
/*****************************************************************************
 *                        TASKS STACK SIZES                                  *
 *****************************************************************************/
#define    StackSizeTask0    256
#define    StackSizeTask1    2048
#define    StackSizeTask2    256
#define    SystemStackSize     256
/*****************************************************************************
 *                      GENERAL CONDITIONS                                   *
 *****************************************************************************/
#define     NO_EVENTS                       DISABLE
/* The hooks and function at user disposal */

#define ShutdownOs_Arch()
#define ShutdownHook()
#define EnableOSInterrupts()		_BIS_SR(GIE)
#define SuspendAllInterrupts()
#define IntSecure_Start()
#define ResumeAllInterrupts()
#define IntSecure_End()
#define HOOK_ERRORHOOK                  DISABLE
#define ERROR_CHECKING_TYPE             DISABLE
#define HOOK_STARTUPHOOK				  ENABLE
#define UART_INTERFACE				  ENABLE
#define APPLICATION_MODE				(1)
#endif /* _OS_CFG_ */

/* EOF */
