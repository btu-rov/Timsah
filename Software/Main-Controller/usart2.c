/*
 * File:   usart2.c
 * Author: ElektroNeo
 *
 * Created on 22 Temmuz 2019 Pazartesi, 01:33
 */

#include "config.h"

void USART2_Init(void) {
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
}

void USART2_Read(void) {
    // If overrun error occured reset receiver
    if (RCSTA2bits.OERR) {
    // Disable receive
    RCSTA2bits.CREN = 0;
    // Enable receive
    RCSTA2bits.CREN = 1;
    }
    // If framing error occured reset USART
    if(RCSTA2bits.FERR2) {
        RCSTA2bits.SPEN2 = 0;
        RCSTA2bits.SPEN2 = 1;
    }
    readedData2 = RCREG2;
}

void USART2_PutChar(uint8_t data, uint8_t newLine) {
    // Enable transmission
    TXSTA2bits.TXEN = 1;
    // Send data
    TXREG2 = data;
    while(!TXSTA2bits.TRMT);
    // Send new line char if needed
    if(newLine){
        TXREG2 = '\n';
        while(!TXSTA2bits.TRMT);
    }
    // Disable transmission
    TXSTA2bits.TXEN = 0;
}

void USART2_PutString(uint8_t *datas, uint8_t newLine) {
    // Enable transmission
    TXSTA2bits.TXEN = 1;
    // Send chars untill NULL terminated
    for(uint8_t i = 0; datas[i] != NULL; i++) {
        TXREG2 = datas[i];
        while(!TXSTA2bits.TRMT);
    }
    // Send new line char if needed
    if(newLine){
        TXREG2 = '\n';
        while(!TXSTA2bits.TRMT);
    }
    // Disable transmission
    TXSTA2bits.TXEN = 0;
}