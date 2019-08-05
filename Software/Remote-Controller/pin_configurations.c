/*
 * File:   pin_configurations.c
 * Author: ElektroNeo
 */


#include "config.h"

void GPIO(void) {
    //ANSELx registers  
    
    ANSELD = 0x00;
    ANSELC = 0x0C;
    ANSELB = 0x0F;
    ANSELE = 0x00;
    ANSELA = 0x01;
    
    // Set A0 as digital output for control data of MAX485.
    TRISAbits.RA0 = 0;
    PORTAbits.RA0 = 0; // Receiver (MAX485) enable
    
    TRISA |= 0x02;
    TRISB |= 0x0F;
    TRISC |= 0x0C;
    TRISD |= 0xFF;
}