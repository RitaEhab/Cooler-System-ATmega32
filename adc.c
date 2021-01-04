/*
 * adc.c
 *
 * Created: 10/14/2020 12:59:03 PM
 *  Author: Rita
 */ 

#include "adc.h"


/*
 * Function: Initialize ADC peripheral
 * Parameter: no input
 * Output: no return
 */
void ADC_init()
{
	#if ADC_CHANNEL == 0
	ADMUX = 0;								// Internal Vref off, Input Channel ADC0
	#elif ADC_CHANNEL == 1
	ADMUX = 1;								// Internal Vref off, Input Channel ADC1
	#elif ADC_CHANNEL == 2
	ADMUX = 2;								// Internal Vref off, Input Channel ADC2
	#elif ADC_CHANNEL == 3
	ADMUX = 3;								// Internal Vref off, Input Channel ADC3
	#elif ADC_CHANNEL == 4
	ADMUX = 4;								// Internal Vref off, Input Channel ADC4
	#elif ADC_CHANNEL == 5
	ADMUX = 5;								// Internal Vref off, Input Channel ADC5
	#elif ADC_CHANNEL == 6
	ADMUX = 6;								// Internal Vref off, Input Channel ADC6
	#else
	ADMUX = 7;								// Internal Vref off, Input Channel ADC7
	#endif
	
	ADCSRA = 0x87;								// prescaler division factor 128 and enable ADC
}

/*
 * Function: Get data from ADC
 * Parameter: no input
 * Output: [uint16] data read from ADC
 */
uint16_t ADC_read()
{
	SETBIT(ADCSRA,6);							// ADC start conversion
	while(READBIT(ADCSRA,6) == 1) {};					// When the conversion is complete, this bit returns to zero
	return ADC;								// return result of conversion
}
