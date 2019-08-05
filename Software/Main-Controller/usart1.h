/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef USART1
#define	USART1

void USART1_Init (void);
void USART1_PutChar (uint8_t data, uint8_t newLine);
void USART1_PutString (uint8_t *datas);

#endif	/* USART1 */

