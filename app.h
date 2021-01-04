/*
 * app.h
 *
 * Created: 12/24/2020 1:55:06 AM
 *  Author: Rita
 */ 


#ifndef APP_H_
#define APP_H_

#include "std_macros.h"
#include "adc.h"
#include "LCD.h"
#include "PWM.h"
#include "sev_seg.h"

/* LED PD0 */
#define LED_INIT()		SETBIT(DDRD, 0)
#define LED_ON()		SETBIT(PORTD, 0)
#define LED_OFF()		CLRBIT(PORTD, 0)


/*
 * Function: Initialize system modules
 * Parameter: no input
 * Output: no return
 */
void System_init();

/*
 * Function: Get current temperature
 * Parameter: no input
 * Output: [uint8] measured temperature
 */
uint8_t getTemp();

/*
 * Function: Get speed corresponding to the current temperature
 * Parameter: [uint8] measured temperature
 * Output: [uint8] speed of motor in percentage
 */
uint8_t checkTempGetSpeed(uint8_t temp);

/*
 * Function: Increase/decrease motor speed according to measured temperature
 * Parameter: [uint8] speed of motor in percentage
 * Output: no return
 */
void applySpeedOnMotor(uint8_t speed);

/*
 * Function: Display temperature on seven segment and on LCD. Also display speed in second line of LCD.
 * Parameter: [uint8] measured temperature, [uint8] speed of motor in percentage
 * Output: no return
 */
void displayTempAndSpeed(uint8_t temp, uint8_t speed);

#endif /* APP_H_ */