/*
 * Servo.h
 *
 * Created: 1/19/2023 3:48:47 PM
 *  Author: user
 */ 


#ifndef SERVO_H_
#define SERVO_H_

#include <avr/io.h>		/* Include AVR std. library file */
#include <stdio.h>		/* Include std. library file */
#include <util/delay.h>		/* Include Delay header file */



#define Angle180 510
#define Angle90 340
#define Angle0 170
#define min_allowed_distance 35

void servo_init(void);
void servo_move();


#endif /* SERVO_H_ */