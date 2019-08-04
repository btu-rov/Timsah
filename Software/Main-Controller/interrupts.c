/*
 * File:   interrupts.c
 * Author: ElektroNeo
 *
 * Created on 01 A?ustos 2019 Per?embe, 12:26
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
        if (RCSTA2bits.OERR) {
        // Disable receive
        RCSTA2bits.CREN = 0;
        // Enable receive
        RCSTA2bits.CREN = 1;
        }
        readedData = RCREG2;
    }
}
