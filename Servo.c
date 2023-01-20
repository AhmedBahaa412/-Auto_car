/*
 * Servo.c
 *
 * Created: 1/19/2023 3:48:34 PM
 *  Author: user
 */ 
#include "Servo.h"
#include "ultrasonic.h"
#include <util/delay.h>

void servo_init(void)
{
	TCNT1 = 0;		/* Set timer1 count zero */
	TCCR1A|=(1<<COM1A1)|(1<<WGM11);        //NON Inverted PWM
	TCCR1B|=(1<<WGM13)|(1<<WGM12)|(1<<CS11)|(1<<CS10); //PRESCALER=64 MODE 14(FAST PWM)

	ICR1=4999;  //fPWM=50Hz (Period = 20ms Standard).

	DDRD|=(1<<PD5);   //PWM Pins as Out
}

void servo_move(int angle)
{
	OCR1A=angle;
}
