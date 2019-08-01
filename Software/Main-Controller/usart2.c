/*
 * File:   usart1.c
 * Author: ElektroNeo
 *
 * Created on 22 Temmuz 2019 Pazartesi, 01:33
 */

#include "config.h"

void USART2_Init (void) {
    // Set ANSEL bits for i/o
    ANSELDbits.ANSD6 = 0;
    ANSELDbits.ANSD7 = 0;
    
    TRISDbits.RD6 = 1;
    TRISDbits.RD7 = 1;
        
    // Enable Serial Port
    RCSTA2bits.SPEN = 1;

    // Asyncronous operation
    TXSTA2bits.SYNC = 0;
    // Enable receive
    RCSTA2bits.CREN = 1;
    // Enable high speed
    TXSTA2bits.BRGH = 1;
    // Enable 16bit BGR value
    BAUDCON2bits.BRG16 = 1;
    // Set baud rate to 9600
    SPBRG2 = 0xA0;
    SPBRGH2 = 0x01;
    
    // Enable interrupt
    PIE3bits.RC2IE = 1;
    INTCONbits.PEIE = 1;
    INTCONbits.GIE = 1;
}