/*
 * File:   adc.c
 * Author: ElektroNEO
 *
 * Created on 28 August 2017 Monday, 14:27
 */

#include "config.h"

void ADCInitialize(void) {
    // ADFM right; ACQT 12; ADCS FOSC/16;
    ADCON2bits.ACQT = 0b101;
    ADCON2bits.ADCS = 0b101;
    ADCON2bits.ADFM = 1; // Right justified
}

uint16_t ADCGetConversion(uint8_t ch, uint16_t out_min, uint16_t out_max) {
    // Select the A/D channel
    ADCON0bits.CHS = ch;
    // Turn on the ADC module
    ADCON0bits.ADON = 1;
    __delay_us(10);
    // Start the conversion
    ADCON0bits.GO_nDONE = 1;
    // Wait until conversion done
    while(ADCON0bits.GO_nDONE);
    // Turn off the ADC module
    ADCON0bits.ADON = 0;
    
    // Get mapped result
    return (uint32_t)(((ADRESH & 0b11) << 8) | ADRESL) * (out_max - out_min) / (1023) + out_min;
}