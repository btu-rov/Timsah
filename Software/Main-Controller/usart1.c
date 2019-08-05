/*
 * File:   usart1.c
 * Author: ElektroNeo
 */


#include "config.h"

void USART1_Init(void) {
    // Set ANSEL bits for i/o
    ANSELCbits.ANSC6 = 0;
    ANSELCbits.ANSC7 = 0;
    
    TRISCbits.RC6 = 1;
    TRISCbits.RC7 = 1;
        
    // Enable Serial Port
    RCSTA1bits.SPEN = 1;

    // Asyncronous operation
    TXSTA1bits.SYNC = 0;
    // Disable receive
    RCSTA1bits.CREN = 0;
    // Enable high speed
    TXSTA1bits.BRGH = 1;
    // Enable 16bit BGR value
    BAUDCON1bits.BRG16 = 1;
    // Set baud rate to 9600
    SPBRG1 = 0xA0;
    SPBRGH1 = 0x01;
}

void USART1_PutChar(uint8_t data, uint8_t newLine) {
    // Enable transmission
    TXSTA1bits.TXEN = 1;
    // Send data
    TXREG1 = data;
    while(!TXSTA1bits.TRMT);
    // Send new line char if needed
    if(newLine){
        TXREG1 = '\n';
        while(!TXSTA1bits.TRMT);
    }
    // Disable transmission
    TXSTA1bits.TXEN = 0;
}

void USART1_PutString(uint8_t *datas) {
    // Enable transmission
    TXSTA1bits.TXEN = 1;
    // Send chars untill NULL terminated
    for(uint8_t i = 0; datas[i] != NULL; i++) {
        TXREG1 = datas[i];
        while(!TXSTA1bits.TRMT);
    }
    // Send new line char
    TXREG1 = '\n';
    while(!TXSTA1bits.TRMT);
    // Disable transmission
    TXSTA1bits.TXEN = 0;
}



