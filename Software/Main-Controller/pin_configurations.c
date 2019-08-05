/*
 * File:   pin_configurations.c
 * Author: ElektroNeo
 */

#include "config.h"

void GPIO(void) {
    // ANSELx registers
    ANSELD = 0x00;
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELE = 0x00;
    ANSELA = 0x00;
    
    TRISB = 0x00;
    
    // Set A0 as digital output for control data of MAX485.
    TRISAbits.RA0 = 0;
    // Set A1 as digital output for control data of MAX485.
    TRISAbits.RA1 = 0;
    
    // Configuration of MAX485 to receiver/transmitter
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 0;
}