/*
 * File: rtwtypes.h
 *
 * Real-Time Workshop code generated for Simulink model ISO2631_All_GenerationTemplate.
 *
 * Model version                        : 1.17
 * Real-Time Workshop file version      : 7.6  (R2010b)  03-Aug-2010
 * Real-Time Workshop file generated on : Sat Sep 06 13:19:54 2014
 * TLC version                          : 7.6 (Jul 13 2010)
 * C/C++ source code generated on       : Sat Sep 06 13:19:55 2014
 *
 * Target selection: autosar.tlc
 * Embedded hardware selection: Texas Instruments->C2000
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_rtwtypes_h_
#define RTW_HEADER_rtwtypes_h_
#ifndef __RTWTYPES_H__
#define __RTWTYPES_H__
#ifndef TRUE
# define TRUE                          (1U)
#endif

#ifndef FALSE
# define FALSE                         (0U)
#endif

#ifndef __TMWTYPES__
#define __TMWTYPES__
#include <limits.h>

/*=======================================================================*
 * Target hardware information
 *   Device type: Texas Instruments->C2000
 *   Number of bits:     char:  16    short:   16    int:  16
 *                       long:  32      native word size:  16
 *   Byte ordering: LittleEndian
 *   Signed integer division rounds to: Zero
 *   Shift right on a signed integer as arithmetic shift: on
 *=======================================================================*/

/*=======================================================================*
 * Fixed width word size data types:                                     *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *   real32_T, real64_T           - 32 and 64 bit floating point numbers *
 *                                                                       *
 *                                                                       *
 *   Note:  Because the specified hardware does not have native support  *
 *          for all data sizes, some data types are actually typedef'ed  *
 *          from larger native data sizes.  The following data types are *
 *          not in the ideal native data types:                          *
 *                                                                       *
 *          int8_T, uint8_T                                              *
 *=======================================================================*/
typedef int int8_T;
typedef unsigned int uint8_T;
typedef int int16_T;
typedef unsigned int uint16_T;
typedef long int32_T;
typedef unsigned long uint32_T;
typedef float real32_T;
typedef double real64_T;

/*===========================================================================*
 * Generic type definitions: real_T, time_T, boolean_T, int_T, uint_T,       *
 *                           ulong_T, char_T and byte_T.                     *
 *===========================================================================*/
typedef double real_T;
typedef double time_T;
typedef unsigned int boolean_T;
typedef int int_T;
typedef unsigned int uint_T;
typedef unsigned long ulong_T;
typedef char char_T;
typedef unsigned char uchar_T;
typedef char_T byte_T;

/*=======================================================================*
 * Min and Max:                                                          *
 *   int8_T, int16_T, int32_T     - signed 8, 16, or 32 bit integers     *
 *   uint8_T, uint16_T, uint32_T  - unsigned 8, 16, or 32 bit integers   *
 *=======================================================================*/
#define MAX_int8_T                     ((int8_T)(127))
#define MIN_int8_T                     ((int8_T)(-128))
#define MAX_uint8_T                    ((uint8_T)(255U))
#define MIN_uint8_T                    ((uint8_T)(0U))
#define MAX_int16_T                    ((int16_T)(32767))
#define MIN_int16_T                    ((int16_T)(-32768))
#define MAX_uint16_T                   ((uint16_T)(65535U))
#define MIN_uint16_T                   ((uint16_T)(0U))
#define MAX_int32_T                    ((int32_T)(2147483647))
#define MIN_int32_T                    ((int32_T)(-2147483647-1))
#define MAX_uint32_T                   ((uint32_T)(0xFFFFFFFFU))
#define MIN_uint32_T                   ((uint32_T)(0U))

/* Logical type definitions */
#if (!defined(__cplusplus)) && (!defined(__true_false_are_keywords))
#  ifndef false
#   define false                       (0U)
#  endif

#  ifndef true
#   define true                        (1U)
#  endif
#endif

/*
 * Real-Time Workshop assumes the code is compiled on a target using a 2's compliment representation
 * for signed integer values.
 */
#if ((SCHAR_MIN + 1) != -SCHAR_MAX)
#error "This code must be compiled using a 2's complement representation for signed integer values"
#endif

/* This ID is used to detect inclusion of an incompatible rtwtypes.h */
#define RTWTYPES_ID_C16S16I16L32N16F1
#else                                  /* __TMWTYPES__ */
#define TMWTYPES_PREVIOUSLY_INCLUDED
#endif                                 /* __TMWTYPES__ */

/* Block D-Work pointer type */
typedef void * pointer_T;

/* Simulink specific types */
#ifndef __SIMSTRUC_TYPES_H__
#define __SIMSTRUC_TYPES_H__

/* Trigger directions: falling, either, and rising */
typedef enum {
  FALLING_ZERO_CROSSING = -1,
  ANY_ZERO_CROSSING = 0,
  RISING_ZERO_CROSSING = 1
} ZCDirection;

/* Previous state of a trigger signal */
typedef uint8_T ZCSigState;

/* Initial value of a trigger zero crossing signal */
#define UNINITIALIZED_ZCSIG            0x03U
#define NEG_ZCSIG                      0x02U
#define POS_ZCSIG                      0x01U
#define ZERO_ZCSIG                     0x00U

/* Current state of a trigger signal */
typedef enum {
  FALLING_ZCEVENT = -1,
  NO_ZCEVENT = 0,
  RISING_ZCEVENT = 1
} ZCEventType;

#endif                                 /* __SIMSTRUC_TYPES_H__ */
#endif                                 /* __RTWTYPES_H__ */
#endif                                 /* RTW_HEADER_rtwtypes_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
