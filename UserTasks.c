/*******************************************************************************
**                                                                            **
**  SRC-MODULE: UserTasks.c                                                   **
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

#include "Task.h"
/*... Include necessary user includes */
#include "ADXL345.h"

/*****************************************************************************
* Task Name: Task_IDLE_code                                                      **
*****************************************************************************/
void Task_IDLE_code(void)
{
	while(1)
	{} /* Never ending task */

} /* End of Task_IDLE_code */
/*****************************************************************************
* Task Name: TASK_ACC                                                       **
*****************************************************************************/
signed short X_axis;
signed short Y_axis;
signed short Z_axis;
signed short X_axis;
float X_Data;
float Y_Data;
float Z_Data;
void TASK_ACC_code(void)
{
	signed char tempL;
	signed char tempH;
	signed short temp;
	tempL = I2C_Read(ADXL345_DATAX0);
	tempH = I2C_Read(ADXL345_DATAX1);
	X_axis = ((tempH<<8) | tempL);
	X_axis = (X_axis<<2)/4;
	X_Data = X_axis * (float)3.9;
	tempL = I2C_Read(ADXL345_DATAY0);
	tempH = I2C_Read(ADXL345_DATAY1);
	Y_axis = ((tempH<<8) | tempL);
	Y_axis = (Y_axis<<2)/4;
	Y_Data = Y_axis * (float)3.9;
	tempL = I2C_Read(ADXL345_DATAZ0);
	tempH = I2C_Read(ADXL345_DATAZ1);
	Z_axis = ((tempH<<8) | tempL);
	Z_axis = (Z_axis<<2)/4;
	Z_Data = Z_axis * (float)3.9;
    TerminateTsk();
} /* End of TASK_ACC */
/*****************************************************************************
* Task Name: TASK_ISO2631                                                   **
*****************************************************************************/
void TASK_ISO2631_code(void)
{
    TerminateTsk();
} /* End of TASK_ISO2631 */
/*****************************************************************************
* Task Name: TASK_Init                                                      **
*****************************************************************************/
static unsigned char ReadID = 0;
void TASK_Init_code(void)
{
	I2C_Init();
	InitI2CGpio();
	ReadID =  I2C_Read(Register_device_ID);
	if(ADXL345_CHIP_ID != ReadID)
   {
   		while(1);
   }
   	I2C_Write(POWER_CTL,ADXL345_PCTL_MEASURE);
   	I2C_Write(DATA_FORMAT,CONF_16g_TEST_OFF);
    TerminateTsk();
} /* End of TASK_Init */

/* EOF */
