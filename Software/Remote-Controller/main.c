#include "config.h"

void main(void)
{
    SystemInit();
    
    uint8_t data[8];
    uint8_t special;
    
    while (1)
    {
        // Read analog datas
        data[DATA_X] = ADCGetConversion(CH_AN24, 0, 100);
        data[DATA_Y] = ADCGetConversion(CH_AN25, 0, 100);
        data[DATA_XD] = ADCGetConversion(CH_AN11, 0, 100);
        data[DATA_YD] = ADCGetConversion(CH_AN13, 0, 100);
        data[DATA_GRIPPER] = ADCGetConversion(CH_AN8, 0, 100);
        data[DATA_CAMERA] = ADCGetConversion(CH_AN21, 0, 100);
        
        // Special data
        special = 0;
        special |= PORTCbits.RC4 << 0; // Forward
        special |= PORTCbits.RC5 << 1; // Right
        special |= PORTDbits.RD2 << 2; // Left
        special |= PORTDbits.RD3 << 3; // Backward
        special |= PORTEbits.RE1 << 4; // Up
        special |= PORTEbits.RE2 << 5; // Down
        special |= PORTCbits.RC3 << 6; // Turn Back
        special |= PORTAbits.RA2 << 7; // Oto Depth
        data[DATA_SPECIAL] = special;
        
        // Send datas
        for(uint8_t i = 1; i < 8; i++) {
            cbuss1Regs[i] = data[i];
        }
    }
}