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

#define MAX_SPEED               50
#define DATA_OFFSET             5

#define REVERSE_DATA_X          1
#define REVERSE_DATA_Y          1
#define REVERSE_DATA_YD         1
#define REVERSE_DATA_XD         1
#define REVERSE_DATA_GRIPPER    1
#define REVERSE_DATA_CAMERA     1

// Special data bits
#define SPECIAL_FORWARD         0
#define SPECIAL_RIGHT           1
#define SPECIAL_LEFT            2
#define SPECIAL_BACKWARD         3
#define SPECIAL_UP              4
#define SPECIAL_DOWN            5
#define SPECIAL_TURN_BACK       6
#define SPECIAL_OTO_DEPTH       7


uint8_t speedY = 0;
uint8_t speedX = 0;
uint8_t speedYD = 0;

void Motor_Init(void);
void Motor(uint8_t num, uint16_t speed);
void Motor_Write(uint8_t address, uint8_t reg, uint8_t data);
uint8_t Motor_ReadByte(uint8_t address, uint8_t reg);
void Motor_SimpleMode(void);
void Motor_Servo(void);
void Motor_Stop(void);
uint8_t Special(uint8_t specialBit);
void SpecialSet(uint8_t specialBit);
void SpecialClear(uint8_t specialBit);

#endif	/* MOTOR */

