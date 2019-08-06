/*
 * File:   motor.c
 * Author: ElektroNeo
 */


#include "config.h"

void Motor_Init(void) {
    Motor_Write(0x40, MODE1, MODE1_FOR_FREQ);
    // prescale value = round (osc_clock/(4096*update_rate)) - 1
    Motor_Write(0x40, PRE_SCALE, 0x79);   // Set to 50Hz
    Motor_Write(0x40, MODE1, MODE1_FOR_PWM);
    
    // Start all pwms at 0ms
    for(uint8_t i = 0; i < 16; i++) {
        Motor_Write(0x40, (4*i)+6, 0);
        Motor_Write(0x40, (4*i)+7, 0);
        Motor_Write(0x40, (4*i)+8, 0);
        Motor_Write(0x40, (4*i)+9, 0);
    }
}

void Motor(uint8_t num, uint16_t speed) {
    if(speed > 100)
        speed = 100;
    speed = (speed*205)/100;
    speed += 205;
    Motor_Write(0x40, (num*4)+8, (speed)&0x0ff);
    Motor_Write(0x40, (num*4)+9, ((speed)&0xf00)>>8);
}

void Motor_Write(uint8_t address, uint8_t reg, uint8_t data) {
    // Start condition
    I2C1_Start();
    // Send slave address.
    address = (address << 1) | 0;   // Set to write.
    I2C1_Write(address);
    // Send register address.
    I2C1_Write(reg);
    // Send data.
    I2C1_Write(data);
    // Stop condition
    I2C1_Stop();
}
/************** Not Tested! ****************/
uint8_t Motor_ReadByte(uint8_t address, uint8_t reg) {
    uint8_t receivedData;
    
    Motor_Write(0x40, MODE1, MODE1_FOR_PWM | 0b00100000);
    
    I2C1_Start();
    
    // Send slave address.
    address = (address << 1) | 1;   // Set to read.
    I2C1_Write(address);
    
    for(uint8_t i = 0; i < reg; i++) {
        receivedData = I2C1_Read(0);
    }
    
    receivedData = I2C1_Read(1);
    
    // Stop condition
    I2C1_Stop();
    
    Motor_Write(0x40, MODE1, MODE1_FOR_PWM & 0b11011111);
    
    return receivedData;
}

// For manual controle
void Motor_SimpleMode(void) {
    // If connections are reverset then reverse values
    if(REVERSE_DATA_X)
        cbusm2Regs[DATA_X] = 100 - cbusm2Regs[DATA_X];
    if(REVERSE_DATA_Y)
        cbusm2Regs[DATA_Y] = 100 - cbusm2Regs[DATA_Y];
    if(REVERSE_DATA_XD)
        cbusm2Regs[DATA_XD] = 100 - cbusm2Regs[DATA_XD];
    if(REVERSE_DATA_YD)
        cbusm2Regs[DATA_YD] = 100 - cbusm2Regs[DATA_YD];

    // Forvard speed
    if(cbusm2Regs[DATA_Y] >= (50+DATA_OFFSET)) {
        speedY = map(cbusm2Regs[DATA_Y], 50+DATA_OFFSET, 100, 0, MAX_SPEED);
        Motor(FRONT_RIGHT, speedY);
        Motor(FRONT_LEFT, speedY);
        Motor(BACK_RIGHT, speedY);
        Motor(BACK_LEFT, speedY);
    } 
    else if(cbusm2Regs[DATA_Y] <= (50-DATA_OFFSET)) {
        /* Not featured */
    }

    // Turn right and turn left speeds
    else if(cbusm2Regs[DATA_X] >= (50+DATA_OFFSET)) {
        speedX = map(cbusm2Regs[DATA_X], 50+DATA_OFFSET, 100, 0, MAX_SPEED);
        Motor(FRONT_LEFT, speedX);
        Motor(BACK_LEFT, speedX);
    } 
    else if(cbusm2Regs[DATA_X] <= (50-DATA_OFFSET)) {
        speedX = map((50-DATA_OFFSET)-cbusm2Regs[DATA_X], 0, 50-DATA_OFFSET, 0, MAX_SPEED);
        Motor(FRONT_RIGHT, speedX);
        Motor(BACK_RIGHT, speedX);
    } 
    else {
        Motor(FRONT_RIGHT, 0);
        Motor(FRONT_LEFT, 0);
        Motor(BACK_RIGHT, 0);
        Motor(BACK_LEFT, 0);
    }

    // Dive speed
    if (cbusm2Regs[DATA_YD] >= (50+DATA_OFFSET)) {
        speedYD = map(cbusm2Regs[DATA_YD], 50+DATA_OFFSET, 100, 0, MAX_SPEED);
        Motor(UP_RIGHT, speedYD);
        Motor(UP_LEFT, speedYD);
    }
    else if(cbusm2Regs[DATA_YD] <= (50-DATA_OFFSET)) {
        /* Not featured */
    }
    else if(cbusm2Regs[DATA_XD] >= (50+DATA_OFFSET)) {
        /* Not featured */
    }
    else if(cbusm2Regs[DATA_XD] <= (50-DATA_OFFSET)) {
        /* Not featured */
    }
    else {
        Motor(UP_RIGHT, 0);
        Motor(UP_LEFT, 0);
    }
}

void Motor_Servo(void) {
    if(REVERSE_DATA_GRIPPER)
        cbusm2Regs[DATA_GRIPPER] = 100 - cbusm2Regs[DATA_GRIPPER];
    if(REVERSE_DATA_CAMERA)
        cbusm2Regs[DATA_CAMERA] = 100 - cbusm2Regs[DATA_CAMERA];
    
    Motor(CAMERA, cbusm2Regs[DATA_CAMERA]);
    Motor(GRIPPER, cbusm2Regs[DATA_GRIPPER]);
}

void Motor_Stop(void) {
    Motor(FRONT_RIGHT, 0);
    Motor(FRONT_LEFT, 0);
    Motor(BACK_RIGHT, 0);
    Motor(BACK_LEFT, 0);
    Motor(UP_RIGHT, 0);
    Motor(UP_LEFT, 0);
}

uint8_t Special(uint8_t specialBit) {
    return ((cbusm2Regs[DATA_SPECIAL] >> specialBit) & 0x01);
}

void SpecialSet(uint8_t specialBit) {
    cbusm2Regs[DATA_SPECIAL] |= 1 << specialBit;
}

void SpecialClear(uint8_t specialBit) {
    cbusm2Regs[DATA_SPECIAL] &= !(1 << specialBit);
}