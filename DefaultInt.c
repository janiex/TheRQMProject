/*******************************************************************************
**                                                                            **
**  SRC-MODULE: DefaultInt.c                                                  **
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
#include "Std_types.h"
#include "DSP2833x_Device.h"
ISR_NATIVE(DEFAUTL_ISR) 
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  //asm ("      ESTOP0");
  for(;;);
}
ISR_NATIVE(ILLEGAL_ISR) 
{
  // Insert ISR Code here

  // Next two lines for debug only to halt the processor here
  // Remove after inserting ISR Code
  //asm ("      ESTOP0");
  for(;;);
}
const struct PIE_VECT_TABLE PieVectTableInit = {

      DEFAUTL_ISR,  // 0  Reserved space
      DEFAUTL_ISR,  // 1  Reserved space 
      DEFAUTL_ISR,  // 2  Reserved space 
      DEFAUTL_ISR,  // 3  Reserved space 
      DEFAUTL_ISR,  // 4  Reserved space 
      DEFAUTL_ISR,  // 5  Reserved space 
      DEFAUTL_ISR,  // 6  Reserved space 
      DEFAUTL_ISR,  // 7  Reserved space 
      DEFAUTL_ISR,  // 8  Reserved space 
      DEFAUTL_ISR,  // 9  Reserved space 
      DEFAUTL_ISR,  // 10 Reserved space 
      DEFAUTL_ISR,  // 11 Reserved space 
      DEFAUTL_ISR,  // 12 Reserved space 


// Non-Peripheral Interrupts
	  DEFAUTL_ISR,    // XINT13 or CPU-Timer 1
      DEFAUTL_ISR,    // CPU-Timer2 <- System Tick
      DEFAUTL_ISR,    // Datalogging interrupt
      DEFAUTL_ISR,    // RTOS interrupt
      DEFAUTL_ISR,    // Emulation interrupt
      DEFAUTL_ISR,    // Non-maskable interrupt
      ILLEGAL_ISR,    // Illegal operation TRAP
      DEFAUTL_ISR,    // User Defined trap 1
      DEFAUTL_ISR,    // User Defined trap 2
      DEFAUTL_ISR,    // User Defined trap 3
      DEFAUTL_ISR,    // User Defined trap 4
      DEFAUTL_ISR,    // User Defined trap 5
      DEFAUTL_ISR,    // User Defined trap 6
      DEFAUTL_ISR,    // User Defined trap 7
      DEFAUTL_ISR,    // User Defined trap 8
      DEFAUTL_ISR,    // User Defined trap 9
      DEFAUTL_ISR,    // User Defined trap 10
      DEFAUTL_ISR,    // User Defined trap 11
      DEFAUTL_ISR,    // User Defined trap 12

// Group 1 PIE Vectors
      DEFAUTL_ISR,    // 1.1 ADC  
      DEFAUTL_ISR,    // 1.2 ADC  
      DEFAUTL_ISR,    // 1.3
      DEFAUTL_ISR,    // 1.4     
      DEFAUTL_ISR,    // 1.5
      DEFAUTL_ISR,    // 1.6 ADC
      DEFAUTL_ISR,    // 1.7 Timer 0
      DEFAUTL_ISR,    // 1.8 WD, Low Power

// Group 2 PIE Vectors
     DEFAUTL_ISR,    // 2.1 EPWM-1 Trip Zone
     DEFAUTL_ISR,    // 2.2 EPWM-2 Trip Zone
     DEFAUTL_ISR,    // 2.3 EPWM-3 Trip Zone
     DEFAUTL_ISR,    // 2.4 EPWM-4 Trip Zone
     DEFAUTL_ISR,    // 2.5 EPWM-5 Trip Zone
     DEFAUTL_ISR,    // 2.6 EPWM-6 Trip Zone                        
     DEFAUTL_ISR,    // 2.7
     DEFAUTL_ISR,    // 2.8
      
// Group 3 PIE Vectors
      DEFAUTL_ISR,    // 3.1 EPWM-1 Interrupt
      DEFAUTL_ISR,    // 3.2 EPWM-2 Interrupt
      DEFAUTL_ISR,    // 3.3 EPWM-3 Interrupt
      DEFAUTL_ISR,    // 3.4 EPWM-4 Interrupt
      DEFAUTL_ISR,    // 3.5 EPWM-5 Interrupt
      DEFAUTL_ISR,    // 3.6 EPWM-6 Interrupt                        
      DEFAUTL_ISR,    // 3.7
      DEFAUTL_ISR,    // 3.8
      
// Group 4 PIE Vectors
      DEFAUTL_ISR,    // 4.1 ECAP-1
      DEFAUTL_ISR,    // 4.2 ECAP-2
      DEFAUTL_ISR,    // 4.3 ECAP-3
      DEFAUTL_ISR,    // 4.4 ECAP-4            
      DEFAUTL_ISR,    // 4.5 ECAP-5     
      DEFAUTL_ISR,    // 4.6 ECAP-6          
      DEFAUTL_ISR,    // 4.7      
      DEFAUTL_ISR,    // 4.8      
      
// Group 5 PIE Vectors
      DEFAUTL_ISR,    // 5.1 EQEP-1
      DEFAUTL_ISR,    // 5.2 EQEP-2
      DEFAUTL_ISR,    // 5.3      
      DEFAUTL_ISR,    // 5.4           
      DEFAUTL_ISR,    // 5.5      
      DEFAUTL_ISR,    // 5.6      
      DEFAUTL_ISR,    // 5.7      
      DEFAUTL_ISR,    // 5.8   


// Group 6 PIE Vectors
      DEFAUTL_ISR,    // 6.1 SPI-A
      DEFAUTL_ISR,    // 6.2 SPI-A
      DEFAUTL_ISR,    // 6.3 McBSP-A
      DEFAUTL_ISR,    // 6.4 McBSP-A
      DEFAUTL_ISR,    // 6.5 McBSP-B
      DEFAUTL_ISR,    // 6.6 McBSP-B
      DEFAUTL_ISR,    // 6.7 
      DEFAUTL_ISR,    // 6.8                  

      
// Group 7 PIE Vectors
      DEFAUTL_ISR,    // 7.1  DMA channel 1    
      DEFAUTL_ISR,    // 7.2  DMA channel 2
      DEFAUTL_ISR,    // 7.3  DMA channel 3      
      DEFAUTL_ISR,    // 7.4  DMA channel 4           
      DEFAUTL_ISR,    // 7.5  DMA channel 5      
      DEFAUTL_ISR,    // 7.6  DMA channel 6      
      DEFAUTL_ISR,    // 7.7      
      DEFAUTL_ISR,    // 7.8   

// Group 8 PIE Vectors
      DEFAUTL_ISR,    // 8.1  I2C    
      DEFAUTL_ISR,    // 8.2  I2C
      DEFAUTL_ISR,    // 8.3      
      DEFAUTL_ISR,    // 8.4           
      DEFAUTL_ISR,    // 8.5  SCI-C
      DEFAUTL_ISR,    // 8.6  SCI-C      
      DEFAUTL_ISR,    // 8.7      
      DEFAUTL_ISR,    // 8.8    
      
// Group 9 PIE Vectors     
      DEFAUTL_ISR,    // 9.1 SCI-A
      DEFAUTL_ISR,    // 9.2 SCI-A
      DEFAUTL_ISR,    // 9.3 SCI-B
      DEFAUTL_ISR,    // 9.4 SCI-B
      DEFAUTL_ISR,    // 9.5 eCAN-A
      DEFAUTL_ISR,    // 9.6 eCAN-A
      DEFAUTL_ISR,    // 9.7 eCAN-B
      DEFAUTL_ISR,    // 9.8 eCAN-B
      
// Group 10 PIE Vectors
      DEFAUTL_ISR,    // 10.1      
      DEFAUTL_ISR,    // 10.2
      DEFAUTL_ISR,    // 10.3      
      DEFAUTL_ISR,    // 10.4           
      DEFAUTL_ISR,    // 10.5      
      DEFAUTL_ISR,    // 10.6      
      DEFAUTL_ISR,    // 10.7      
      DEFAUTL_ISR,    // 10.8    
            
// Group 11 PIE Vectors
      DEFAUTL_ISR,    // 11.1      
      DEFAUTL_ISR,    // 11.2
      DEFAUTL_ISR,    // 11.3      
      DEFAUTL_ISR,    // 11.4           
      DEFAUTL_ISR,    // 11.5      
      DEFAUTL_ISR,    // 11.6      
      DEFAUTL_ISR,    // 11.7      
      DEFAUTL_ISR,    // 11.8
        
// Group 12 PIE Vectors
     DEFAUTL_ISR,    // 12.1      
     DEFAUTL_ISR,    // 12.2
     DEFAUTL_ISR,    // 12.3      
     DEFAUTL_ISR,    // 12.4           
     DEFAUTL_ISR,    // 12.5      
     DEFAUTL_ISR,    // 12.6      
     DEFAUTL_ISR,    // 12.7      
     DEFAUTL_ISR,    // 12.8   
};

/* EOF */
