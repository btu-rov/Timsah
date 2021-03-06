/*
 * File:   interrupts.c
 * Author: ElektroNeo
 */

#include "config.h"

void Interrupts(void) {
    // Enable interrupt for USART2 receive module.
    PIE3bits.RC2IE = 1;
    // Enable peripheral interrupts.
    INTCONbits.PEIE = 1;
    // Enable all unmasked interrupts.
    INTCONbits.GIE = 1;
}

void __interrupt() ISR(void) {
    // USART2 Module
    if(PIE3bits.RC2IE && PIR3bits.RC2IF) {
        // Read data using usart module
        USART2_Read();
        // Get char for CBUS
        CBUSM2_GetChar();
        // Clear interrupt flag
        PIR3bits.RC2IF = 0;
    }
}
