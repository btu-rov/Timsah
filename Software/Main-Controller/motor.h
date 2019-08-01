/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
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

// TODO Insert appropriate #include <>

// TODO Insert C++ class definitions if appropriate

// TODO Insert declarations

// Comment a function and leverage automatic documentation with slash star star
/**
    <p><b>Function prototype:</b></p>
  
    <p><b>Summary:</b></p>

    <p><b>Description:</b></p>

    <p><b>Precondition:</b></p>

    <p><b>Parameters:</b></p>

    <p><b>Returns:</b></p>

    <p><b>Example:</b></p>
    <code>
 
    </code>

    <p><b>Remarks:</b></p>
 */
// TODO Insert declarations or function prototypes (right here) to leverage 
// live documentation

void Motor_Init(void);
void Motor(uint8_t, uint16_t);
void Motor_Write(uint8_t, uint8_t, uint8_t);
//uint8_t Motor_ReadByte(uint8_t, uint8_t);

#endif	/* MOTOR */

