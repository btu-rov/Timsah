#include "config.h"

void main(void){
    SystemInit();
    //uint8_t acc[4];
    while (1) {
        //USART1_PutChar('b', 0);
        //BNO055_MultiRead(BNO055_ACCEL_DATA_X_LSB_ADDR, acc, 2);
        //__delay_ms(10);
        //PORTB = BNO055_Read(BNO055_TEMP_ADDR);
        //PORTB = BNO055_Read(BNO055_CHIP_ID_ADDR);
        //Motor(0, result1);
        
        for(uint8_t i = 1; i < 9; i++) {
            CBUSM2_Read(i);
        }
        PORTB = cbusm2Regs[7];
    }
}



