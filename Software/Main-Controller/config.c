#include "config.h"

void SystemInit(void) {
    // SCS FOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b10;
    OSCCONbits.OSTS = 0;
    
    GPIO();
    I2C1_Init(100000);
    BNO055_Init();
    Motor_Init();
    USART1_Init();
    USART2_Init();
    Interrupts();
}