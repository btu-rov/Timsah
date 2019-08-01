/* 
 * File:   adc.h
 * Author: ElektroNeo
 * Comments: 
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC
#define	ADC

void ADCInitialize(void);
uint16_t ADCGetConversion(uint8_t ch, uint16_t out_min, uint16_t out_max);

#endif	/* ADC */
