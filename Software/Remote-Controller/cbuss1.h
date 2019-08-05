/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

#ifndef CBUSS1
#define	CBUSS1

#define READ_FUNC   0x01
#define WRITE_FUNC  0x02

#define DATA_X          1
#define DATA_Y          2
#define DATA_XD         3
#define DATA_YD         4
#define DATA_GRIPPER    5
#define DATA_CAMERA     6
#define DATA_SPECIAL    7

uint8_t cbuss1Data = 0;
uint8_t cbuss1Reg = 0;
uint8_t cbuss1Regs[10];
uint8_t cbuss1Mode = 0;

uint8_t CBUSS1_GenerateCRC(uint8_t data);
uint8_t CBUSS1_CheckCRC(uint8_t crc, uint8_t data);
void CBUSS1_Write(uint8_t reg);
void CBUSS1_Read(void);

#endif	/* CBUSS1 */

