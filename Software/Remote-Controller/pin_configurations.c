/*
 * File:   pin_configurations.c
 * Author: ElektroNeo
 */


#include "config.h"

void GPIO(void) {
    
    //ANSELx registers  
    ANSELA = 0x00;
    ANSELB = 0x34;
    ANSELC = 0x00;
    ANSELD = 0x32;
    ANSELE = 0x00;

    // TRISx registers
    TRISA |= 0x06;
    TRISB |= 0x34;
    TRISC |= 0x38;
    TRISD |= 0x3E;
    TRISE |= 0x06;
    
    // Set B3 as digital output for control data of MAX485.
    TRISBbits.RB3 = 0;
    PORTBbits.RB3 = 0; // Receiver (MAX485) enable
}