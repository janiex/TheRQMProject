/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Platform_Types.h                                              **
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
#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

#ifndef TRUE
   #define TRUE              1
#endif

#ifndef FALSE
   #define FALSE             0
#endif

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
 
typedef unsigned char       boolean;        /* for use with TRUE/FALSE        */
typedef unsigned char       BYTE;           /* The smallest Byte like type    */
typedef signed char         sint16;         /*        -128 .. +127            */
typedef unsigned char       uint16;         /*           0 .. 255             */
typedef signed long         sint32;         /* -2147483648 .. +2147483647     */
typedef unsigned long       uint32;         /*           0 .. 4294967295      */
typedef signed long long    sint64;         /* \brief 64-bit unsigned integer */
typedef unsigned long long  uint64;
/* The optimized AUTOSAR          integer     data     types
(<typename>_least) shall have at least the size given by the type name, but the
types shall be implemented in a way that the best performance on the specific
platform is achieved. `Best performance' is defined in this context as `least processor
cycles for variable access as possible'. Example: on a TC1796, uint8_least is
mapped to unsigned int (32 bit) because access to this type requires less
processor cycles than e.g. unsigned char (8 bit).  */                                      
typedef unsigned long       uint8_least;    /* At least 8 bit                 */
typedef signed long         sint8_least;    /* At least 7 bit + 1 bit sign    */
typedef unsigned long       uint16_least;   /* At least 16 bit                */
typedef signed long         sint16_least;   /* At least 15 bit + 1 bit sign   */
typedef unsigned long       uint32_least;   /* At least 32 bit                */
typedef signed long         sint32_least;   /* At least 31 bit + 1 bit sign   */
                                        
typedef float               float32;       /* IEEE 32-bit 1.19 209 290e-38  .. 3.40 282 35e+38 */
typedef long double         float64;       /* IEEE 64-bit 2.22 507 385e-308 .. 1.79 769 313e+308 */
#endif /*PLATFORM_TYPES_H_*/

/* EOF */
