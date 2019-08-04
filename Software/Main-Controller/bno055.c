/*
 * File:   bno055.c
 * Author: Msi
 *
 * Created on 03 A?ustos 2019 Cumartesi, 21:21
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
    /*
    Normal Mode
    In normal mode all sensors required for the selected operating mode 
    (see section 3.3) are always switched ON. The register map and the 
    internal peripherals of  the  MCU  are  always operative in this mode.
    */
    BNO055_Write(BNO055_PWR_MODE_ADDR, POWER_MODE_NORMAL);
    __delay_ms(10);
    /*
    NDOF 
    This is a fusion mode with 9 degrees of freedom where the fused 
    absolute orientation data is calculated  from  accelerometer,  gyroscope  
    and  the  magnetometer. The  advantages  of combining all three sensors 
    are a fast calculation, resulting in high output data rate, and high 
    robustness from magnetic field distortions. In this mode the Fast 
    Magnetometer calibration is  turned  ON  and  thereby  resulting  in  
    quick  calibration  of  the  magnetometer  and  higher output  data  
    accuracy.  The  current  consumption  is slightly higherin  comparison  
    to  the NDOF_ FMC_ OFF fusion mode.
    */
    BNO055_Write(BNO055_PAGE_ID_ADDR, 0);
    BNO055_Write(BNO055_SYS_TRIGGER_ADDR, 0);
    __delay_ms(10);
    BNO055_Write(BNO055_OPR_MODE_ADDR, OPERATION_MODE_NDOF);
    // Switching time = From CONFIGMODE to Any operation mode is 7ms
    // Switching time = From Any operation mode to CONFIGMODE is 19ms
    __delay_ms(50);
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
