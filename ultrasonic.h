/*
 * ultrasonic.h
 *
 * Created: 1/19/2023 3:50:51 PM
 *  Author: user
 */ 


#ifndef _ULTRA_H_
#define _ULTRA_H_

#include<avr/io.h>
#include <avr/interrupt.h>
#include<string.h>
#include <stdlib.h>
#define F_CPU 16000000UL
#include <util/delay.h>
#include "timer.h"


#define   TRIGER_DDR    DDRD
#define   ECHO_DDR      DDRD
#define   TRIGER_PORT   PORTD
#define   ECHO_PULLUP   PORTD
#define   TRIGER        0
#define   ECHO          3
#define   min_allowed_distance 30

/*************************************************
 *  API functions
 *************************************************/

void ultrasonic_init(void);
void enable_ex_interrupt(void);
void ultrasonic_triger(void);
int get_distance(void);

#endif
