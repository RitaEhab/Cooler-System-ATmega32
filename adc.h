/*
 * adc.h
 *
 * Created: 10/14/2020 12:59:14 PM
 *  Author: Rita
 */ 


#ifndef ADC_H_
#define ADC_H_


#include "std_macros.h"

/* Channel of ADC is ADC0 */
#define ADC_CHANNEL 0

/*
 * Function: Initialize ADC peripheral
 * Parameter: no input
 * Output: no return
 */
void ADC_init();

/*
 * Function: Get data from ADC
 * Parameter: no input
 * Output: [uint16] data read from ADC
 */
uint16_t ADC_read();


#endif /* ADC_H_ */