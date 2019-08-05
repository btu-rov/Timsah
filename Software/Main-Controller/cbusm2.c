/*
 * File:   cbusm2.c
 * Author: ElektroNeo
 */

#include "config.h"

uint8_t CBUSM2_GenerateCRC(uint8_t data) {
    return ((data & 0b10101010) ^ (data | 0b10101010));
}

uint8_t CBUSM2_CheckCRC(uint8_t crc, uint8_t data) {
    return (((data & 0b10101010) ^ (data | 0b10101010)) == crc);
}

void CBUSM2_Write(uint8_t reg, uint8_t data) {
    //Set MAX485 to write mode
    PORTAbits.RA1 = 1;
    USART2_PutChar(WRITE_FUNC, 0);
    USART2_PutChar(reg, 0);
    USART2_PutChar(data, 0);
    USART2_PutChar(CBUSM2_GenerateCRC(data), 0);
}

void CBUSM2_Read(uint8_t reg) {
    // Use same reg address in CBUSM2_GetChar() function
    cbusm2Reg = reg;
    // Set MAX485 to write mode
    PORTAbits.RA1 = 1;
    USART2_PutChar(READ_FUNC, 0);
    USART2_PutChar(reg, 0);
    // Set MAX485 to read mode
    PORTAbits.RA1 = 0;
    
    // Delay for responce
    // If connection lost delay 5ms
    for(uint8_t i = 0; i < 5; i++) {
        if(cbusm2ReadyToRead) {
            break;
        }
        __delay_ms(1);
    }
    // Reset the ReadytoRead flag for next read
    cbusm2ReadyToRead = 0;
}

void CBUSM2_GetChar(void) {
    // Check crc flag
    if(!cbusm2ReadyToCrc) {
        // Save data value to cbusm2Data
        cbusm2Data = readedData2;
        // Ready to read crc
        cbusm2ReadyToCrc = 1;
        // Data readed wait for crc
        cbusm2ReadyToRead = 0;
    } else {
        // If data not lost on transfer then save it
        if(CBUSM2_CheckCRC(readedData2, cbusm2Data)) {
            cbusm2Regs[cbusm2Reg] = cbusm2Data;
        }
        // Reset flags
        cbusm2ReadyToCrc = 0;
        // Crc readed cancel delay for loop
        cbusm2ReadyToRead = 1;
    }
}