/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C
#define	I2C

void I2C_Init(uint32_t);
void I2C_Ready(void);
void I2C_Start(void);
void I2C_Stop(void);
void I2C_Write(uint8_t);
uint8_t I2C_Read(uint8_t);

#endif	/* I2C */

