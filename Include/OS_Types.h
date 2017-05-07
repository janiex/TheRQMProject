/*******************************************************************************
**                                                                            **
**  SRC-MODULE: OS_Types.h                                                    **
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
#ifndef OS_TYPES_H_
#define OS_TYPES_H_
/**********************************************************************************************************************
 * ==================+ OS DEFINITIONS +==========================================================================
 *********************************************************************************************************************/
 /**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
/**********************************************************************************************************************
 * STANDARD TYPES
 *********************************************************************************************************************/
typedef uint16 *pStackPtr; /* Stack pointer type */
typedef void (*pFunc)(void); /* Task like function type */
typedef void (* EntryPointType)(void);
typedef void (* CallbackType)(void);
/** \brief Type definition of AppModeType
 **
 ** This type is used to represent an Application Mode
 **/
typedef BYTE AppModeType;
/** \brief Type definition of AlarmType
 **
 ** This type is used to represent references to Alarms
 **/
typedef BYTE AlarmType; 
/** \brief Type definition of TickType
 **
 ** This type is used to represent references to Ticks
 **/
typedef uint32 TickType;
/** \brief Type definition of AlarmBaseType
 **
 ** This type is used to represent references to AlarmBase
 **/
typedef struct {
	TickType maxallowedvalue;
	TickType ticksperbase;
	TickType mincycle;
} AlarmBaseType;
/** \brief Type definition of AlarmBaseRefType
 **
 ** This type is used to represent references to AlarmBase
 **/
typedef AlarmBaseType* AlarmBaseRefType;
/** \brief Type definition of TickRefType
 **
 ** This type is used to represent references to TickType
 **/
typedef TickType* TickRefType;
/** \brief Alarm State
 **
 ** This type defines the possibly states of one alarm which are:
 ** 0 disable
 ** 1 enable
 **/
typedef BYTE AlarmStateType;

/** \brief Alarm Time */
typedef uint32 AlarmTimeType;
/** \brief Alarm Cycle Time */
typedef uint32 AlarmCycleTimeType;
/** \brief Counter Type */
typedef BYTE CounterType;
/** \brief Counter Increment Type */
typedef uint32 CounterIncrementType;
/** \brief Alarm Increment Type */
typedef uint32 AlarmIncrementType;
/** \brief Alarm Action Type */
typedef enum {
	ALARMCALLBACK = 0,
	SETEVENT = 1,
	ACTIVATETASK = 2,
	INCREMENT = 3
} AlarmActionType;
/** \brief Type definition of Event Mask
 **
 ** This type is used to represent Events
 **/
typedef uint32 EventMaskType;
/** \brief Type definition of EventMaskRefType
 **
 ** This type is used to represent references to Events
 **/
typedef EventMaskType* EventMaskRefType;
typedef unsigned char TaskPriorityType;

typedef struct {
   unsigned int Extended : 1;
   unsigned int Preemtive : 1;
   unsigned int State : 2;
} TaskFlagsType;
/** \brief Type definition of TaskType
 **
 ** This type is used to represent the Task IDs
 **/
 typedef BYTE TaskType;
 typedef BYTE TaskTotalType;
typedef const  TaskType* const TaskRefConstType;
/** \brief Type definition of TaskRefType
 **
 ** This type is used to represent a pointer to a Task ID Type
 **/
typedef TaskType* TaskRefType;
/** \brief Type definition of TaskStateType
 **
 ** This type is used to represent the State of a Task
 **/
typedef unsigned char TaskStateType;
/** \brief Type definition of TaskStateRefType
 **
 ** This type is used to represent a pointer to a TaskStateType
 **/
typedef TaskStateType* TaskStateRefType;
/**************************************************************************
 *                                ReadyList                               *
 **************************************************************************/
/** \brief Ready List Constatn Type
 **
 ** \param ListLength Lenght of the Ready List
 ** \param TaskRef Reference to the Ready Array for this Priority
 **/
typedef struct {
	TaskTotalType ListLength;
	TaskRefType TaskRef;
} ReadyConstType;

/** \brief Ready List Variable Type
 **
 ** \param ListStart first valid componet on the list
 ** \param ListCount count of valid components on this list
 **/

typedef struct {
	TaskTotalType ListStart;
	TaskTotalType ListCount;
} ReadyVarType;
typedef BYTE TaskActivationsType;

typedef uint32 TaskEventsType;

typedef uint32 TaskResourcesType;

typedef uint16* StackPtrType;

typedef uint16 StackSizeType;
/**************************************************************************
 *                                Context                                 *
 **************************************************************************/
/** \brief ContextType
 **
 ** Type used to represent the actual context
 **/
typedef BYTE ContextType;
/* \brief Invalid Context */
#define CONTEXT_INVALID ((ContextType)0U)
/** \brief Task Context */
#define CONTEXT_TASK ((ContextType)1U)
/** \brief ISR Category 1 Context */
#define CONTEXT_ISR1 ((ContextType)2U)
/** \brief ISR Category 2 Context */
#define CONTEXT_ISR2 ((ContextType)3U)
/** \brief SYS Context */
#define CONTEXT_SYS	((ContextType)4U)
/** \brief DBG Context */
#define CONTEXT_DBG	((ContextType)5U)

/** \brief Definition return value E_OS_ACCESS */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_ACCESS			((StatusType)1U)
/** \brief Definition return value E_OS_CALLEVEL */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_CALLEVEL		((StatusType)2U)
/** \brief Definition return value E_OS_ID */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_ID				((StatusType)3U)
/** \brief Definition return value E_OS_LIMIT */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_LIMIT			((StatusType)4U)
/** \brief Definition return value E_OS_NOFUNC */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_NOFUNC			((StatusType)5U)
/** \brief Definition return value E_OS_RESOURCE */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_RESOURCE		((StatusType)6U)
/** \brief Definition return value E_OS_STATE */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_STATE			((StatusType)7U)
/** \brief Definition return value E_OS_VALUE */
/* \req OSEK_SYS_1.1.1 */
#define E_OS_VALUE			((StatusType)8U)

/**************************************************************************
 *                                TASK                                    *
 **************************************************************************/
#define INVALID_TASK  ((TaskType)~0)
/** \brief SUSPEND Task State */
#define SUSPENDED 0U
/** \brief READY Task State */
#define READY 1U
/** \brief RUNNING Task State */
#define RUNNING 2U
/** \brief WAITING Task State */
#define WAITING 3U
/** \brief INVALID Task State */
#define INVALID_STATE 4U
#endif /*OS_TYPES_H_*/

/* EOF */
