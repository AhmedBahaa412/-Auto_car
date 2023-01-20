/*
 * FinalProject.c
 *
 * Created: 1/19/2023 3:47:53 PM
 * Author : user
 */ 


#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h> /* Include Delay header file */
#define F_CPU 16000000UL


#include "Servo.h"
#include "ultrasonic.h"
#include "DcMotor.h"


uint8_t distance_strr[10];
uint32_t dist;

int main()
{
	servo_init();
	ultrasonic_init();
	motor_init();

	sei(); //enable the global interrupt

	while(1)

	{
		servo_move(Angle90);

		if(get_distance()<min_allowed_distance)
		{
			motor_stop();
			_delay_ms(10);
			all_backward();
			char done=0;
			servo_move(Angle0);
			_delay_ms(1000);

			if(get_distance()>min_allowed_distance)// cm between the ultrasonic and the object
			{
				_delay_ms(200);
				right();//turn right
				done=1;
			}
			else if(1)
			{
				servo_move(Angle180);
				_delay_ms(1000);
				if(get_distance()>min_allowed_distance)// cm between the ultrasonic and the object
				{
					left();//turn left.
					done=1;
				}
			}


			if(done==1)
			{
				servo_move(Angle90);
				move();
				done=0;
			}
			else all_backward();
		}
		else move();
	}
}
