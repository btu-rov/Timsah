/*
 * File:   pin_configurations.c
 * Author: ElektroNeo
 *
 * Created on 01 A?ustos 2019 Per?embe, 12:30
 */


#include "config.h"

void GPIO(void) {
    // Initialize the device
    /**
    ANSELx registers
    */
    ANSELD = 0x00;
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELE = 0x00;
    ANSELA = 0x00;
    
    // Set A0 as digital output for control data of MAX485.
    TRISAbits.RA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    // For pot1 analog read
    TRISAbits.RA2 = 1;
    ANSELAbits.ANSA2 = 1;
    
    TRISBbits.RB4 = 0;
    TRISD = 0xff;
    TRISBbits.RB0 = 0;

    PORTAbits.RA0 = 1; // Transmitter (MAX485) enable
}