#include "config.h"

void main(void)
{
    SystemInit();
    
    uint8_t data[8];
    data[DATA_SPECIAL] = 0;
    
    while (1)
    {
        data[DATA_X] = ADCGetConversion(CH_AN10, 0, 100);
        data[DATA_Y] = ADCGetConversion(CH_AN12, 0, 100);
        data[DATA_XD] = ADCGetConversion(CH_AN9, 0, 100);
        data[DATA_YD] = ADCGetConversion(CH_AN8, 0, 100);
        data[DATA_GRIPPER] = ADCGetConversion(CH_AN15, 0, 100);
        data[DATA_CAMERA] = ADCGetConversion(CH_AN14, 0, 100);
        data[DATA_SPECIAL] = PORTD;
        
        for(uint8_t i = 1; i < 8; i++) {
            cbuss1Regs[i] = data[i];
        }
    }
}