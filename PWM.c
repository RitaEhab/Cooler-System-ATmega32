/*
 * pwm.c
 *
 * Created: 10/14/2020 11:46:31 AM
 *  Author: Rita
 */ 

#include "PWM.h"

/*
 * Function: Initialize Timer1 peripheral
 * Parameter: no input
 * Output: no return
 */
void PWM_init_timer1_oc1a(){
	SETBIT(DDRD,5);										// Set OC1A pin (PD5) as output
	TCCR1A = (1<<COM1A1) | (1<<WGM10) | (1<<WGM11);		// non-inverting
	TCCR1B = 1<<WGM12 | 1<<CS10;						// Fast PWM 10bit, no prescaler
}

/*
 * Function: Set duty cycle & output it on OC1A pin
 * Parameter: [uint8] duty cycle in percentage
 * Output: no return
 */
void PWM_set_duty_timer1_oc1a(uint8_t duty){
	OCR1A = duty* 10.23;								// duty = (ocr1a / 1023) * 100
}

