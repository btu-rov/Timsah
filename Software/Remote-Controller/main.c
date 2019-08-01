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

#include <pic18f45k22.h>

#include "config.h"

void main(void)
{
    // SCS FOSC; IRCF 16MHz_HFINTOSC; IDLEN disabled; 
    OSCCONbits.IRCF = 0b111;
    OSCCONbits.SCS = 0b10;
    
    // Disable analog pins.
    ANSELA = 0;
    ANSELB = 0;
    ANSELC = 0;
    ANSELD = 0;
    ANSELE = 0;
    
    uint8_t rxData;
    
    uint16_t pot1, pot2;
    uint8_t potReg1 = 0, potReg2 = 0;

    USART1_Init();
    ADCInitialize();
    
    // Set A0 as digital output for control data of MAX485.
    TRISAbits.RA0 = 0;
    ANSELAbits.ANSA0 = 0;
    
    // For pot1 analog read
    TRISAbits.RA2 = 1;
    ANSELAbits.ANSA2 = 1;
    
    TRISBbits.RB4 = 0;
    TRISD = 0xff;
    TRISBbits.RB0 = 0;

    rxData = 'a';
    PORTAbits.RA0 = 1; // Transmitter (MAX485) enable
    
    while (1)
    {
        pot1 = ADCGetConversion(2, 0, 100);
        //uint16_t result2 = ADCGetConversion(1, 0, 100);
        
        
        //USART1_PutChar('a', 0);
        //__delay_ms(500);
        //USART1_PutChar('b', 0);
        //__delay_ms(500);
        //USART1_PutString("SPD");
        //USART1_PutString("#");
        USART1_PutChar(pot1, 1);
        //USART1_PutString("$$");
        //PORTAbits.RA1 = 0; // Receiver (MAX485) enable
    }
}