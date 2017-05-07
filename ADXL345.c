//#include "DSP2833x_Device.h"     // DSP2833x Headerfile Include File
//#include "DSP2833x_Examples.h"   // DSP2833x Examples Include File
#include "ADXL345.h"


#ifdef __cplusplus
#pragma DATA_SECTION("I2caRegsFile")
#else
#pragma DATA_SECTION(I2caRegs,"I2caRegsFile");
#endif
volatile struct I2C_REGS I2caRegs;
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
void InitI2CGpio(void)
{
	 EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0;           // GPIO15 ... GPIO0 = General Puropse I/O
    GpioCtrlRegs.GPAMUX2.all = 0;           // GPIO31 ... GPIO16 = General Purpose I/O

    GpioCtrlRegs.GPBMUX1.all = 0;           // GPIO47 ... GPIO32 = General Purpose I/O
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1;    // GPIO32 = I2C - SDA
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1;    // GPIO33 = I2C - SCL

    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0;    // Enable pull-up for GPIO32 (SDAA)
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0;    // Enable pull-up for GPIO33 (SCLA)

    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3;       // Asynch input GPIO32 (SDAA)
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3;   // Asynch input GPIO33 (SCLA)

    GpioCtrlRegs.GPBMUX2.all = 0;           // GPIO63 ... GPIO48 = General Purpose I/O

    GpioCtrlRegs.GPCMUX1.all = 0;           // GPIO79 ... GPIO64 = General Purpose I/O
    GpioCtrlRegs.GPCMUX2.all = 0;           // GPIO87 ... GPIO80 = General Purpose I/O


    GpioCtrlRegs.GPADIR.all = 0;            // GPIO0 to 31 as inputs
    GpioCtrlRegs.GPADIR.bit.GPIO9 = 1;      // GPIO9 = LED LD1
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 1;     // GpIO11 = LED LD2

    GpioCtrlRegs.GPBDIR.all = 0;            // GPIO63-32 as inputs
    GpioCtrlRegs.GPBDIR.bit.GPIO34 = 1;     // peripheral explorer: LED LD3 at GPIO34
    GpioCtrlRegs.GPBDIR.bit.GPIO49 = 1;     // peripheral explorer: LED LD4 at GPIO49

    GpioCtrlRegs.GPCDIR.all = 0;            // GPIO87-64 as inputs
    EDIS;
}
/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
void I2C_Init(void)
{
   // Initialize I2C
   I2caRegs.I2CMDR.all 	= 0x0020;
   I2caRegs.I2CSAR = SLAVE_ADDR;// Slave address - EEPROM control code
  /*****************************************************************************
  The I2C module clock determines the frequency at which the I2C module operates. 
  A pro-grammable pre-scaler in the I2C module divides down the I2C input clock to 
  produce the module clock. To specify the divide-down value, initialize the IPSC 
  field of the pre-scaler register, I2CPSC. The resulting frequency should be in 
  the range of 7 - 12 MHz and is given by:
  
  I2C_MODULE_CLOCK = SYSCLKOUT/(IPSC+1)
  10MHz = 150MHz/(14+1)
  ******************************************************************************/
   						             // Default - For 150MHz SYSCLKOUT
        I2caRegs.I2CPSC.all = 14;   // Prescaler - need 7-12 Mhz on module clk (150/15 = 10MHz)

/*********************************************************************************************
 * 150MHz                      50KHz     100KHz    400KHz
 * ICCL / ICCH                 95/95     45/45      10/5
 * *******************************************************************************************/
 
  I2caRegs.I2CCLKL = 700;           // NOTE: must be non zero
  I2caRegs.I2CCLKH = 700;            // NOTE: must be non zero
 
  I2caRegs.I2CMDR.all = 0x0020;    // Take I2C out of reset
                                    // Stop I2C when suspended
                                    // I2caRegs.I2CMDR.all = 0000 0010 0000 0000
   I2caRegs.I2CFFTX.all = 0x6000;   // Enable FIFO mode and TXFIFO
   I2caRegs.I2CFFRX.all = 0x2040;   // Enable RXFIFO, clear RXFFINT,
   return;
}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/

void I2C_Write(uint16 reg_address, uint16 data)
{
	I2caRegs.I2CSTR.bit.SCD = 1;
	I2caRegs.I2CMDR.bit.IRS = 1; 			// reset I2C
	
	I2caRegs.I2CSAR = SLAVE_ADDR;           // I2C slave address
	while (I2caRegs.I2CSTR.bit.BB == 1);	// still busy?
	
    I2caRegs.I2CCNT = 2;					// assume register address = 1 byte, and data is 1 byte
	
    I2caRegs.I2CDXR = reg_address;			// register address of the sensor (1 byte)
    I2caRegs.I2CDXR = data;					// data to be sent (1 byte)
	
	I2caRegs.I2CMDR.all = 0x2E20; 			// start, stop, no rm, reset i2c
	
	I2caRegs.I2CMDR.bit.STP = 1;  			// stop bit when CNT=0
    
    while(!I2caRegs.I2CSTR.bit.SCD);       // wait for STOP condition

	
	return;

}

/*******************************************************************************
**                                                                            **
** FUNC-NAME     :                                                            **
**                                                                            **
** DESCRIPTION   :                                                            **
**                                                                            **
** PRECONDITIONS :                                                            **
**                                                                            **
** PARAMETER     :                                                            **
**                                                                            **
** RETURN        :                                                            **
**                                                                            **
** REMARKS       :                                                            **
**                                                                            **
*******************************************************************************/
uint16 I2C_Read(uint16 reg_address)
{
	uint16 tempdata;

	I2caRegs.I2CMDR.bit.IRS = 1; 				// reset I2C
	
	// Make sure I2C is not busy and has stopped
	I2caRegs.I2CMDR.bit.IRS = 1; 				// reset I2C
	while (I2caRegs.I2CSTR.bit.BB == 1);		// busy loop
	I2caRegs.I2CSTR.bit.SCD = 1;				// Clear the SCD bit (stop condition bit)
	while(I2caRegs.I2CMDR.bit.STP == 1);		// stop bit loop
	
	I2caRegs.I2CSAR 	= SLAVE_ADDR;			// I2C slave address

	while (I2caRegs.I2CSTR.bit.BB == 1);		// still busy?
	
	I2caRegs.I2CMDR.all = 0x2620;				// start, no stop bit, master, tx, reset I2C
	I2caRegs.I2CCNT		= 1;					// assume register address is one byte
	I2caRegs.I2CDXR		= reg_address;			// register address of the sensor (1 byte)

	while(!I2caRegs.I2CSTR.bit.ARDY);			// all ready?

	I2caRegs.I2CMDR.all = 0x2C20;				// start, stop bit when CNT =0, master, rx, reset I2C
	I2caRegs.I2CCNT		= 1;					// only read one byte data

	if(I2caRegs.I2CSTR.bit.NACK == 1)
	{
		 I2caRegs.I2CSTR.all = I2C_CLR_NACK_BIT; 	// 0x0002
	}
	I2caRegs.I2CMDR.bit.STP = 1;					// stop bit when CNT=0

	while(!I2caRegs.I2CSTR.bit.SCD);				// stop bit detected?

				
	tempdata	= I2caRegs.I2CDRR;					// read one byte data


	return(tempdata);
}

// EOF
