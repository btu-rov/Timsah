/*
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef USART2
#define	USART2

uint8_t readedData2 = 0;

void USART2_Init (void);
void USART2_Read(void);
void USART2_PutChar(uint8_t data, uint8_t newLine);
void USART2_PutString(uint8_t *datas, uint8_t newLine);

#endif	/* USART2 */

