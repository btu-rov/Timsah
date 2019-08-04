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

void main(void)
{
    SystemInit();
    uint8_t acc[4];
    while (1) {
        //USART1_PutChar(readedData, 1);
        //__delay_ms(10);
        BNO055_MultiRead(BNO055_ACCEL_DATA_X_LSB_ADDR, acc, 2);
        //__delay_ms(10);
        //PORTB = BNO055_Read(BNO055_TEMP_ADDR);
        //PORTB = BNO055_Read(BNO055_CHIP_ID_ADDR);
        //Motor(0, result1);
    }
}



