#include "OS_Types.h"
#include "DSP2833x_I2c.h"
#include "DSP2833x_Device.h"




#ifndef ADXL345_H_
#define ADXL345_H_
#define ADXL345_CHIP_ID         0xE5 // Chip ID should be 0xE5
#define ADXL345_DATA_FORMAT     0x31 // X,Y,Z format of the data
#define ADXL345_DATAX0			0x32 // R   X-Axis Data 0.
#define ADXL345_DATAX1			0x33 // R   X-Axis Data 1.
#define ADXL345_DATAY0			0x34 // R   Y-Axis Data 0.
#define ADXL345_DATAY1			0x35 // R   Y-Axis Data 1.
#define ADXL345_DATAZ0			0x36 // R   Z-Axis Data 0.
#define ADXL345_DATAZ1			0x37 // R   Z-Axis Data 1.
#define SLAVE_ADDR            0x1D //ADXL345 -> if ALT_ADDRESS pin is grounded!
#define CONF_16g_TEST_OFF     0x0B //SELF-TEST O
#define POWER_CTL             0x2D
#define DATA_FORMAT           0x31
#define Register_X0           0x32
#define Register_X1           0x33
#define Register_Y0           0x34
#define Register_Y1           0x35
#define Register_Z0           0x36
#define Register_Z1           0x37
#define Register_device_ID    0x00
/* ADXL345_POWER_CTL definition */
#define ADXL345_PCTL_LINK       (1 << 5)
#define ADXL345_PCTL_AUTO_SLEEP (1 << 4)
#define ADXL345_PCTL_MEASURE    (1 << 3)
#define ADXL345_PCTL_SLEEP      (1 << 2)
#define ADXL345_PCTL_WAKEUP(x)  ((x) & 0x3)
//--------------------------------------------
// Defines
//--------------------------------------------

// Error Messages
#define I2C_ERROR               0xFFFF
#define I2C_ARB_LOST_ERROR      0x0001
#define I2C_NACK_ERROR          0x0002
#define I2C_BUS_BUSY_ERROR      0x1000
#define I2C_STP_NOT_READY_ERROR 0x5555
#define I2C_NO_FLAGS            0xAAAA
#define I2C_SUCCESS             0x0000

// Clear Status Flags
#define I2C_CLR_AL_BIT          0x0001
#define I2C_CLR_NACK_BIT        0x0002
#define I2C_CLR_ARDY_BIT        0x0004
#define I2C_CLR_RRDY_BIT        0x0008
#define I2C_CLR_SCD_BIT         0x0020

// Interrupt Source Messages
#define I2C_NO_ISRC             0x0000
#define I2C_ARB_ISRC            0x0001
#define I2C_NACK_ISRC           0x0002
#define I2C_ARDY_ISRC           0x0003
#define I2C_RX_ISRC             0x0004
#define I2C_TX_ISRC             0x0005
#define I2C_SCD_ISRC            0x0006
#define I2C_AAS_ISRC            0x0007

// I2CMSG structure defines
#define I2C_NO_STOP  0
#define I2C_YES_STOP 1
#define I2C_RECEIVE  0
#define I2C_TRANSMIT 1
#define I2C_MAX_BUFFER_SIZE 16

// I2C Slave State defines
#define I2C_NOTSLAVE      0
#define I2C_ADDR_AS_SLAVE 1
#define I2C_ST_MSG_READY  2

// I2C Slave Receiver messages defines
#define I2C_SND_MSG1 1
#define I2C_SND_MSG2 2

// I2C State defines
#define I2C_IDLE               0
#define I2C_SLAVE_RECEIVER     1
#define I2C_SLAVE_TRANSMITTER  2
#define I2C_MASTER_RECEIVER    3
#define I2C_MASTER_TRANSMITTER 4

// I2C  Message Commands for I2CMSG struct
#define I2C_MSGSTAT_INACTIVE          0x0000
#define I2C_MSGSTAT_SEND_WITHSTOP     0x0010
#define I2C_MSGSTAT_WRITE_BUSY        0x0011
#define I2C_MSGSTAT_SEND_NOSTOP       0x0020
#define I2C_MSGSTAT_SEND_NOSTOP_BUSY  0x0021
#define I2C_MSGSTAT_RESTART           0x0022
#define I2C_MSGSTAT_READ_BUSY         0x0023

// Generic defines
#define I2C_TRUE  1
#define I2C_FALSE 0
#define I2C_YES   1
#define I2C_NO    0
#define I2C_DUMMY_BYTE 0


//--------------------------------------------
// Structures
//--------------------------------------------

// I2C Message Structure
struct I2CMSG {
  uint16 MsgStatus;				// Word stating what state msg is in:
  								//   I2C_MSGCMD_INACTIVE = do not send msg
  								//   I2C_MSGCMD_BUSY = msg start has been sent,
  								//                     awaiting stop
  								//   I2C_MSGCMD_SEND_WITHSTOP = command to send
  								//       master trans msg complete with a stop bit
  								//   I2C_MSGCMD_SEND_NOSTOP = command to send
  								//       master trans msg without the stop bit
  								//   I2C_MSGCMD_RESTART = command to send a restart
  								//       as a master receiver with a stop bit
  uint16 SlaveAddress;			// I2C address of slave msg is intended for
  uint16 NumOfBytes;			// Num of valid bytes in (or to be put in MsgBuffer)
  uint16 MemoryHighAddr;		// EEPROM address of data associated with msg (high byte)
  uint16 MemoryLowAddr;			// EEPROM address of data associated with msg (low byte)
  uint16 MsgBuffer[I2C_MAX_BUFFER_SIZE];	// Array holding msg data - max that
  										    // MAX_BUFFER_SIZE can be is 16 due to
  										    // the FIFO's
};


//*****************************************************************************
// Function Prototypes
//*****************************************************************************
void I2C_Init(void);
void I2C_Write(uint16 reg_address, uint16 data);
uint16 I2C_Read(uint16 reg_address);
void InitI2CGpio(void);
#endif /*ADXL345_H_*/

