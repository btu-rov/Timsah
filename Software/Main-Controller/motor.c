/*
 * File:   motor.c
 * Author: ElektroNeo
 *
 * Created on 19 Temmuz 2019 Cuma, 01:23
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