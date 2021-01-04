/*
 * sev_seg.h
 *
 * Created: 10/4/2020 12:19:01 PM
 *  Author: Rita
 */ 


#ifndef SEV_SEG_H_
#define SEV_SEG_H_

#include "std_macros.h"

/* SEVEN SEGMENT PINS CONNECTION
 * A	PA0
 * B	PA1
 * C	PA2
 * D	PA3
 * E	PA4
 * F	PA5
 * G	PA6
 * EN1	PA7
 * EN2	PD7
 */

/* Set pins direction as output */
#define SEV_SEG_INIT_PORT() DDRA = 0xff; SETBIT(DDRD,7);

/* Apply logic 1 or logic 0 to every segment */
#define A(x) if(x == 0) CLRBIT(PORTA, 0); else SETBIT(PORTA, 0);
#define B(x) if(x == 0) CLRBIT(PORTA, 1); else SETBIT(PORTA, 1);
#define C(x) if(x == 0) CLRBIT(PORTA, 2); else SETBIT(PORTA, 2);
#define D(x) if(x == 0) CLRBIT(PORTA, 3); else SETBIT(PORTA, 3);
#define E(x) if(x == 0) CLRBIT(PORTA, 4); else SETBIT(PORTA, 4);
#define F(x) if(x == 0) CLRBIT(PORTA, 5); else SETBIT(PORTA, 5);
#define G(x) if(x == 0) CLRBIT(PORTA, 6); else SETBIT(PORTA, 6);

/* Seven segment 1 & 2 enable
 * Used for multiplexing
 */
#define EN1(x) if(x == 0) CLRBIT(PORTA, 7); else SETBIT(PORTA, 7);
#define EN2(x) if(x == 0) CLRBIT(PORTD, 7); else SETBIT(PORTD, 7);


/* Responsible for adding time delay to display numbers on seven segment every second */
#ifndef SEV_SEG_TIMER_IN_SEC
#define SEV_SEG_TIMER_IN_SEC	0
#endif

/* Responsible for multiplexing 2 seven segments */
#ifndef SEV_SEG_TWO_DISPLAY
#define SEV_SEG_TWO_DISPLAY		0
#endif


/*
 * Function: Initialize seven segment
 * Parameter: no input
 * Output: no return
 */
void sev_seg_init();

/*
 * Function: Write number on seven segment
 * Parameter: [uint8] number to be displayed
 * Output: no return
 */
void sev_seg_write(uint8_t data);


#endif /* SEV_SEG_H_ */