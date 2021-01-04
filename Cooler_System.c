/*
 * Cooler_System.c
 *
 * Created: 10/21/2020 8:27:03 PM
 *  Author: Rita
 */ 


#include "app.h"

int main(void)
{
	System_init();		// Initialize system modules
    while(1)
    {
		uint8_t temperature = getTemp();					// Get current temperature
		uint8_t speed = checkTempGetSpeed(temperature);		// Get speed corresponding to the current temperature
		applySpeedOnMotor(speed);							// Increase/decrease motor speed according to measured temperature
		displayTempAndSpeed(temperature, speed);			// Display both on screen
	}
}