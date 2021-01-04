/*
 * app.c
 *
 * Created: 12/24/2020 1:54:55 AM
 *  Author: Rita
 */ 

#include "app.h"

void System_init()
{
	ADC_init();
	LED_INIT();
	lcd_init();
	PWM_init_timer1_oc1a();
	sev_seg_init();
}

uint8_t getTemp()
{
	uint16_t adc_value = ADC_read();						// Get temp from temp sensor on ADC0
	uint8_t temp = 20 + (30.0 * (++adc_value/1024.0));		// 30 = 5volt * 6deg/volt (res = 30deg/5volt) & 20 is base temp
	return temp;
}

uint8_t checkTempGetSpeed(uint8_t temp)
{
	uint8_t duty_cycle;
	if (temp <= 35)
	{
		LED_OFF();			// Indicates temp is less than 35 degree
		duty_cycle = 0;		// Motor speed = zero
	}
	else
	{
		LED_ON();			// Indicates temp is more than 35 degree
		if		((temp >  35 ) && (temp < 38 ))		duty_cycle = 50;
		else if ((temp >= 38 ) && (temp < 40 ))		duty_cycle = 60;
		else if ((temp >= 40 ) && (temp < 42 ))		duty_cycle = 70;
		else if ((temp >= 42 ) && (temp < 45 ))		duty_cycle = 80;
		else if ((temp >= 45 ) && (temp < 48 ))		duty_cycle = 90;
		else										duty_cycle = 100;
	}
	return duty_cycle;
}

void applySpeedOnMotor(uint8_t speed)
{
	PWM_set_duty_timer1_oc1a(speed);
}

void displayTempAndSpeed(uint8_t temp, uint8_t speed)
{
	sev_seg_write(temp);				// Display temp on seven segment
	lcd_write_command(CLEAR_DISPLAY);
	lcd_write_string("Temp: ");
	lcd_write_num(temp);				// Display temp in first row of LCD
	lcd_write_command(NEXT_LINE);
	lcd_write_string("Motor speed: ");
	lcd_write_num(speed);				// Display motor speed in percentage in second row of LCD
	_delay_ms(100);
}