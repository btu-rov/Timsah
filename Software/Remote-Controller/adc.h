/* 
 * File:   adc.h
 * Author: ElektroNeo
 * Comments: 
 * Revision history: v1.0
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADC
#define	ADC

#define CH_AN0     0
#define CH_AN1     1
#define CH_AN2     2
#define CH_AN3     3
#define CH_AN4     4
#define CH_AN5     5
#define CH_AN6     6
#define CH_AN7     7
#define CH_AN8     8
#define CH_AN9     9
#define CH_AN10    10
#define CH_AN11    11
#define CH_AN12    12
#define CH_AN13    13
#define CH_AN14    14
#define CH_AN15    15
#define CH_AN16    16
#define CH_AN17    17
#define CH_AN18    18
#define CH_AN19    19
#define CH_AN20    20
#define CH_AN21    21
#define CH_AN22    22
#define CH_AN23    23
#define CH_AN24    24
#define CH_AN25    25
#define CH_AN26    26
#define CH_AN27    27
#define CH_CTMU    29
#define CH_DAC     30
#define CH_FVR_BUF2 31     

void ADCInitialize(void);
uint16_t ADCGetConversion(uint8_t ch, uint16_t out_min, uint16_t out_max);

#endif	/* ADC */
