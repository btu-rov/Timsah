/**
  Generated Main Source File

  Company:
    Microchip Technology Inc.

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.76
        Device            :  PIC18F45K22
        Driver Version    :  2.00
*/

#include "config.h"

uint16_t map(uint16_t x, uint16_t in_min, uint16_t in_max, uint16_t out_min, uint16_t out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

uint8_t readedData = 'a';

void __interrupt() USART2_ISR(void) {
    if(PIE3bits.RC2IE && PIR3bits.RC2IF) {
        if (RCSTA2bits.OERR) {
        // Disable receive
        RCSTA2bits.CREN = 0;
        // Enable receive
        RCSTA2bits.CREN = 1;
        }
        readedData = RCREG2;
    }
}

void main(void)
{
    // SCS FOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b10;
    
    // Initialize the device
    /**
    ANSELx registers
    */
    ANSELD = 0x00;
    ANSELC = 0x00;
    ANSELB = 0x00;
    ANSELE = 0x00;
    ANSELA = 0x00;
    
    //I2C_Init(100000);
    //Motor_Init();
    USART1_Init();
    USART2_Init();
    
    // Set A0 as digital output for control data of MAX485.
    TRISAbits.RA0 = 0;
    ANSELAbits.ANSA0 = 0;
    // Set A1 as digital output for control data of MAX485.
    TRISAbits.RA1 = 0;
    ANSELAbits.ANSA1 = 0;
    
    // Configuration of MAX485 to receiver/transmitter
    PORTAbits.RA0 = 1;
    PORTAbits.RA1 = 0;
    
    TRISBbits.RB0 = 0;
        
    while (1) {
        USART1_PutChar(readedData, 1);
        __delay_ms(10);
        //Motor(0, result1);
    }
}



