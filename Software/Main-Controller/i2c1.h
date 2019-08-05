/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef I2C1
#define	I2C1

void I2C1_Init(uint32_t clock);
void I2C1_Idle(void);
void I2C1_Start(void);
void I2C1_RStart(void);
void I2C1_Stop(void);
void I2C1_Write(uint8_t data);
uint8_t I2C1_Read(uint8_t ack);

#endif	/* I2C1 */

