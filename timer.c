/*
 * timer.c
 *
 * Created: 1/19/2023 3:50:14 PM
 *  Author: user
 */ 
#include "timer.h"

void timer0_init(void)
{
	/* Disable Timer 0 */
	TCCR0 = DISABLE_MODULE_VALUE;
	/* Setting pre scaler */
	TCCR0 = (PRESCLR1_VALUE);
	/* Initializing the timer with zero */
	TCNT0 = ZER0_INITIALIZER;
	/* Timer overflow interrupt enable*/
	TIMSK |=(1<<TOIE0);

	return;
}
