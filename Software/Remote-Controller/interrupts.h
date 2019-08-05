/* 
 * File:   
 * Author: ElektroNeo
 * Comments:
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef INTERRUPTS
#define	INTERRUPTS

void Interrupts(void);
void __interrupt() ISR(void);

#endif	/* INTERRUPTS */

