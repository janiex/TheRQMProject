/*******************************************************************************
**                                                                            **
**  SRC-MODULE: Compiler.h                                                    **
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
#ifndef COMPLIER_H_
#define COMPLIER_H_
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/

/* # include "Compiler_Cfg.h" */


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 /* NULL_PTR define with a void pointer to zero definition*/
# ifndef NULL_PTR
   #define NULL_PTR  ((void *)0)
# endif

/* NULL_PTR define with a void pointer to zero definition*/
# ifndef NULL
   #define NULL  ((void *)0)
# endif

#define ISR_NATIVE(x)     interrupt void  x(void)

#endif /*COMPLIER_H_*/

/* EOF */
