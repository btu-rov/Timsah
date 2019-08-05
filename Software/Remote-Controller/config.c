#include "config.h"

void SystemInit(void) {
    // SCS FOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b10;
    
    GPIO();
    USART1_Init();
    ADCInitialize();
    Interrupts();
}