/*
 * File: Compiler.h
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

#ifndef RTW_HEADER_Compiler_h_
#define RTW_HEADER_Compiler_h_

/*
 *
 * This file contains dummy implementations of the AUTOSAR functions
 * used by this model for testing the code generated from Simulink.
 * Simulink invokes the generated code through its S-Function API.
 * Note that this file is replaced with the real implementation
 * when deploying the generated code outside of Simulink.
 *
 */

/*
 *
 * This header file specifies macros for the abstraction of compiler specific
 * keywords used for addressing data and code within declarations and
 * definitions.  This is used to overcome problems caused by the limited 16 bit
 * addressing range.
 *
 * For SIL/PIL macros behave as identity operators.
 *
 */

/* Compiler Abstractions for PC */
#define FUNC(type, memclass)           type
#define P2VAR(ptrtype, memclass, ptrclass) ptrtype *
#define P2CONST(ptrtype, memclass, ptrclass) const ptrtype *
#define CONST(consttype, memclass)     const consttype
#define VAR( type, memclass )          type
#endif                                 /* RTW_HEADER_Compiler_h_ */

/*
 * File trailer for Real-Time Workshop generated code.
 *
 * [EOF]
 */
