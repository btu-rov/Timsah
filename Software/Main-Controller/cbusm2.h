/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef CBUSM2
#define	CBUSM2

#define READ_FUNC   0x01
#define WRITE_FUNC  0x02

#define DATA_X          1
#define DATA_Y          2
#define DATA_XD         3
#define DATA_YD         4
#define DATA_GRIPPER    5
#define DATA_CAMERA     6
#define DATA_SPECIAL    7

uint8_t cbusm2Data = 0;
uint8_t cbusm2Reg = 0;
uint8_t cbusm2Regs[10];
uint8_t cbusm2ReadyToRead = 0;
uint8_t cbusm2ReadyToCrc = 0;

uint8_t CBUSM2_GenerateCRC(uint8_t data);
uint8_t CBUSM2_CheckCRC(uint8_t crc, uint8_t data);
void CBUSM2_Write(uint8_t reg, uint8_t data);
void CBUSM2_Read(uint8_t reg);
void CBUSM2_GetChar(void);

#endif	/* CBUSM2 */

