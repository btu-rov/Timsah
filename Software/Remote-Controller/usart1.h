/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef USART1
#define	USART1

void USART1_Init (void);
void USART1_PutChar (uint8_t, uint8_t);
void USART1_PutString (uint8_t *);

#endif	/* USART1 */

