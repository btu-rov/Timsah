/*
 * File:   cbuss1.c
 * Author: ElektroNeo
 *
 * Created on 04 A?ustos 2019 Pazar, 13:56
 */

#include "config.h"

uint8_t CBUSS1_GenerateCRC(uint8_t data) {
    return ((data & 0b10101010) ^ (data | 0b10101010));
}

uint8_t CBUSS1_CheckCRC(uint8_t crc, uint8_t data) {
    return (((data & 0b10101010) ^ (data | 0b10101010)) == crc);
}

void CBUSS1_Write(uint8_t reg) {
    // Set MAX485 to write mode
    PORTAbits.RA0 = 1;
    USART1_PutChar(cbuss1Regs[reg], 0);
    USART1_PutChar(CBUSS1_GenerateCRC(cbuss1Regs[reg]), 0);
    // Set MAX485 to read mode
    PORTAbits.RA0 = 0;
}

void CBUSS1_Read(void) {
    // Set MAX485 to read mode
    PORTAbits.RA0 = 0;
    
    // If mode not selected then read mode
    if(cbuss1Mode == 0) {
        if(readedData1 == READ_FUNC) {
            cbuss1Mode = READ_FUNC;
        } else {
            cbuss1Mode = WRITE_FUNC;
        }
        // Mode has been selected
        cbuss1Mode = 1;
    } else if ((cbuss1Mode == 1) && (cbuss1Mode == READ_FUNC)) {
        // Write data of requested register
        CBUSS1_Write(readedData1);
        // Clear mode flag
        cbuss1Mode = 0;
    } else if ((cbuss1Mode == 1) && (cbuss1Mode == WRITE_FUNC)) {
        // If register not selected
        // Note: Register must be nonzero.
        if(!cbuss1Reg)
            cbuss1Reg = readedData1;
        else {
            // If data not get
            if(!cbuss1Data) {
                // Get data
                cbuss1Data = readedData1;
            } else {
                // Check data with crc for error
                if(CBUSS1_CheckCRC(readedData1, cbuss1Data)) {
                    // Write data to selected register
                    cbuss1Regs[cbuss1Reg] = readedData1;
                    cbuss1Reg = 0;
                    // Clear mode flag
                    cbuss1Mode = 0;
                } else {
                    cbuss1Reg = 0;
                    // Clear mode flag
                    cbuss1Mode = 0;
                }
            }
        }

    } 
}