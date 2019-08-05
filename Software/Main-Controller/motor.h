/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef MOTOR
#define	MOTOR

#define MODE1           0x00
#define MODE2           0x01
#define PRE_SCALE       0xFE
#define MODE1_FOR_FREQ  0b00010001
#define MODE1_FOR_PWM   0b00000001

#define UP_RIGHT        0
#define UP_LEFT         1
#define FRONT_RIGHT     2
#define FRONT_LEFT      3
#define BACK_RIGHT      4
#define BACK_LEFT       5
#define GRIPPER         6
#define CAMERA          7

void Motor_Init(void);
void Motor(uint8_t num, uint16_t speed);
void Motor_Write(uint8_t address, uint8_t reg, uint8_t data);
uint8_t Motor_ReadByte(uint8_t address, uint8_t reg);

#endif	/* MOTOR */

