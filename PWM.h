/*
 * pwm.h
 *
 * Created: 10/14/2020 11:46:38 AM
 *  Author: Rita
 */ 


#ifndef PWM_H_
#define PWM_H_

#include "std_macros.h"

/*
 * Function: Initialize Timer1 peripheral
 * Parameter: no input
 * Output: no return
 */
void PWM_init_timer1_oc1a();

/*
 * Function: Set duty cycle & output it on OC1A pin
 * Parameter: [uint8] duty cycle in percentage
 * Output: no return
 */
void PWM_set_duty_timer1_oc1a(uint8_t duty);



#endif /* PWM_H_ */