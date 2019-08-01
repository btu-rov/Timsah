/*
 * File:   i2c.c
 * Author: bahti
 *
 * Created on 19 Temmuz 2019 Cuma, 01:21
 */

#include "config.h"

void I2C_Init(uint32_t clock)
{
    ANSELCbits.ANSC3 = 0;
    ANSELCbits.ANSC4 = 0;
    TRISCbits.RC3 = 1;      // SCK1
	TRISCbits.RC4 = 1;      // SDA1
	SSP1STATbits.SMP = 1;
    SSP1CON1bits.SSPEN = 1;
    SSP1CON1bits.SSPM = 0b1000;
    SSP1ADD = _XTAL_FREQ/((4*clock)-1);               /* Set clock frequency */  
}

void I2C_Ready(void) {
    while ((SSP1CON2 & 0b00011111) || (SSP1STAT & 0b00000100));
}

void I2C_Start(void) {
    // Start condition
    SSP1CON2bits.SEN = 1;
    I2C_Ready();
}

void I2C_Stop(void) {
    // Stop condition
    SSP1CON2bits.PEN = 1;
    I2C_Ready();
}

void I2C_Write(uint8_t data) {
    // Send data.
    SSP1BUF = data;
    I2C_Ready();
}

uint8_t I2C_Read(uint8_t stop) {
    uint8_t receivedData;
    // Receive enable
    SSP1CON2bits.RCEN = 1;
    I2C_Ready();
    
    // Receive data
    receivedData = SSP1BUF;
    I2C_Ready();
    
    // Send ACK=1 to stop receiving.
    SSP1CON2bits.ACKDT = stop;
    SSP1CON2bits.ACKEN = 1;
    I2C_Ready();
    
    return receivedData;
}