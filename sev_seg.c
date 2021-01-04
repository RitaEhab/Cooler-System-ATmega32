/*
 * sev_seg.c
 *
 * Created: 10/4/2020 12:33:31 PM
 *  Author: Rita
 */ 

#include "sev_seg.h"


/*
 * Function: Initialize seven segment
 * Parameter: no input
 * Output: no return
 */
void sev_seg_init()
{
	SEV_SEG_INIT_PORT();				// Initialize pins used for seven segment
}

/*
 * Function: Write number on seven segment
 * Parameter: [uint8] number to be displayed
 * Output: no return
 */
void sev_seg_write(uint8_t data)
{
	#if SEV_SEG_TWO_DISPLAY == 1			// Multiplex 2 seven segments
	EN1(0);						// Enable left seven segment & disable right seven segment
	EN2(1);
	convert(data/10);				// Display tens digit of the number
	_delay_ms(10);
	#if SEV_SEG_TIMER_IN_SEC == 1			// Add time delay to display numbers on seven segment every second
	_delay_ms(200);
	#endif
	#endif
	
	EN1(1);						// Enable right seven segment & disable left seven segment
	EN2(0);
	convert(data%10);				// Display units digit of the number
	_delay_ms(10);
	#if SEV_SEG_TIMER_IN_SEC == 1			// Add time delay to display numbers on seven segment every second
	_delay_ms(200);
	#endif
}

/*
 * Function: Map numbers to their equivalent segments
 * Parameter: [uint8] number to be displayed
 * Output: no return
 */
void convert(uint8_t data){
	switch(data){
		case 0: A(1); B(1); C(1); D(1); E(1); F(1); G(0); break;		// Display 0
		case 1: A(0); B(1); C(1); D(0); E(0); F(0); G(0); break;		// Display 1
		case 2: A(1); B(1); C(0); D(1); E(1); F(0); G(1); break;		// Display 2
		case 3: A(1); B(1); C(1); D(1); E(0); F(0); G(1); break;		// Display 3
		case 4: A(0); B(1); C(1); D(0); E(0); F(1); G(1); break;		// Display 4
		case 5: A(1); B(0); C(1); D(1); E(0); F(1); G(1); break;		// Display 5
		case 6: A(1); B(0); C(1); D(1); E(1); F(1); G(1); break;		// Display 6
		case 7: A(1); B(1); C(1); D(0); E(0); F(0); G(0); break;		// Display 7
		case 8: A(1); B(1); C(1); D(1); E(1); F(1); G(1); break;		// Display 8
		case 9: A(1); B(1); C(1); D(1); E(0); F(1); G(1); break;		// Display 9
	}
}
