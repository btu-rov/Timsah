/*
 * File:   i2c1.c
 * Author: ElektroNeo
 *
 * Created on 19 Temmuz 2019 Cuma, 01:21
 */

#include <pic18f45k22.h>

#include "config.h"

void I2C1_Init(uint32_t clock)
{
    #if defined (__18F45K22)
        ANSELCbits.ANSC3 = 0;
        ANSELCbits.ANSC4 = 0;
        TRISCbits.RC3 = 1;      // SCK1
        TRISCbits.RC4 = 1;      // SDA1
    #endif
    PIE1bits.SSPIE = 0;
    //Set clock frequency.
    SSP1ADD = (_XTAL_FREQ/(4*clock))-1;
    //SSP1ADD = 0x27;
    // Slew rate control disabled for standard speed mode (100 kHz and 1 MHz)
    SSP1STATbits.SMP = 1;
    // Enable SSP1 Module
    SSP1CON1bits.SSPEN = 1;
    // Master mode
    SSP1CON1bits.SSPM = 0b1000;
    //  Minimum of 300 ns hold time on SDAx after the falling edge of SCLx
    SSP1CON3bits.SDAHT = 1;
    SSP1STATbits.CKE = 1;
    // Clear the Write Collision Detect bit.
	SSPCON1bits.WCOL = 0;
	// Clear the Receive Overflow Indicator bit.
	SSPCON1bits.SSPOV = 0;		
    // Send stop condition, stop any previous communication
	SSPCON2bits.PEN = 1;
	while (SSPCON2bits.PEN == 1);	
}

void I2C1_Idle(void) {
    while ((SSP1CON2 & 0b00011111) | SSP1STATbits.R_W);
}

void I2C1_Start(void) {
    // Start condition
    SSP1CON2bits.SEN = 1;
    while(SSP1CON2bits.SEN);
}

void I2C1_RStart(void) {
    // Repeated Start condition
    SSP1CON2bits.RSEN = 1;
    while(SSP1CON2bits.RSEN);
}

void I2C1_Stop(void) {
    I2C1_Idle();
    // Stop condition
    SSP1CON2bits.PEN = 1;
    while(SSP1CON2bits.PEN);
}

void I2C1_Write(uint8_t data) {
    // Clear the Write Collision Detect bit.
	SSP1CON1bits.WCOL = 0;
    // Send data.
    SSP1BUF = data;
    I2C1_Idle();
    // If slave does not acknowledge...
	if (SSP1CON2bits.ACKSTAT){
		// Send stop bit.
		SSP1CON2bits.PEN = 1;
		while (SSP1CON2bits.PEN == 1);
		return;
	}
}

uint8_t I2C1_Read(uint8_t ack) {
    // Clear the Receive Overflow Indicator bit.
	SSP1CON1bits.SSPOV = 0;
    uint8_t receivedData;
    uint16_t counter = 10000;
    // Receive enable
    SSP1CON2bits.RCEN = 1;
    
    while(!SSP1STATbits.BF) {
        if(--counter == 0) {
            I2C1_Stop();
            return 0;
        }
    }
    
    // Receive data
    receivedData = SSP1BUF;
    // Send ACK=1 to stop receiving.
    SSP1CON2bits.ACKDT = ack;
    SSP1CON2bits.ACKEN = 1;
    //I2C1_Idle();
    while(SSP1CON2bits.ACKEN);
    
    return receivedData;
}