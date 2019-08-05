/*
 * File:   bno055.c
 * Author: ElektroNeo
 */

#include "config.h"

void BNO055_Init(void) {
    uint8_t id = BNO055_Read(BNO055_CHIP_ID_ADDR);
    if(id != BNO055_ID) {
        __delay_ms(1000);
        id = BNO055_Read(BNO055_CHIP_ID_ADDR);
        if(id != BNO055_ID) {
            return;
        }
    }
    
    BNO055_Write(BNO055_OPR_MODE_ADDR, OPERATION_MODE_CONFIG);
    BNO055_Write(BNO055_SYS_TRIGGER_ADDR, 0x20);
    __delay_ms(30);
    
    while(BNO055_Read(BNO055_CHIP_ID_ADDR) != BNO055_ID) {
        __delay_ms(10);
    }
    __delay_ms(50);

    BNO055_Write(BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
    __delay_ms(10);
    
    BNO055_Write(BNO055_PAGE_ID_ADDR, 0);
    BNO055_Write(BNO055_SYS_TRIGGER_ADDR, 0);
    __delay_ms(10);
    
    BNO055_Write(BNO055_OPR_MODE_ADDR, OPERATION_MODE_NDOF);
    // Switching time = From CONFIGMODE to Any operation mode is 7ms
    // Switching time = From Any operation mode to CONFIGMODE is 19ms
    __delay_ms(20);
}

void BNO055_Write(uint8_t regAdd, uint8_t data) {
    I2C1_Start();
    // Set to write
    I2C1_Write((BNO055_ADD<<1) | 0);
    I2C1_Write(regAdd);
    I2C1_Write(data);
    I2C1_Stop();
}

void BNO055_MultiRead(uint8_t regAdd, uint8_t *datas, uint8_t numOfData) {
    I2C1_Start();
    // Set to write
    I2C1_Write((BNO055_ADD<<1) | 0);
    I2C1_Write(regAdd);
    I2C1_RStart();
    // Set to read
    I2C1_Write((BNO055_ADD<<1) | 1);
    
    for(uint8_t i = 0; i < numOfData-1; i++) {
        datas[i] = I2C1_Read(0);
    }
    
    datas[numOfData-1] = I2C1_Read(1);
    I2C1_Stop();
}

uint8_t BNO055_Read(uint8_t regAdd) {
    I2C1_Start();
    // Set to write
    I2C1_Write((BNO055_ADD<<1) | 0);
    I2C1_Write(regAdd);
    I2C1_RStart();
    // Set to read
    I2C1_Write((BNO055_ADD<<1) | 1);
    
    uint8_t data = I2C1_Read(1);
    I2C1_Stop();
    
    return data;
}
