/*
 * File:   interrupts.c
 * Author: ElektroNeo
 */

#include "config.h"

void Interrupts(void) {
    // Enable interrupt for USART2 receive module.
    PIE1bits.RC1IE = 1;
    // Enable peripheral interrupts.
    INTCONbits.PEIE = 1;
    // Enable all unmasked interrupts.
    INTCONbits.GIE = 1;
}

void __interrupt() ISR(void) {
    // USART1 Module
    if(PIE1bits.RC1IE && PIR1bits.RC1IF) {
        // Read data using usart module
        USART1_Read();
        CBUSS1_Read();
        // Clear interrupt flag
        PIR1bits.RC1IF = 0;
    }
}
