/*
 * ultrasonic.c
 *
 * Created: 1/19/2023 3:50:38 PM
 *  Author: user
 */ 
#include "ultrasonic.h"

uint8_t sensor_working=0;
uint8_t rising_edge=0;
uint32_t timer_counter=0;
uint32_t distance;
uint8_t distance_str[10];

void ultrasonic_init(void){

	TRIGER_DDR|=(1<<TRIGER);
	ECHO_DDR&=~(1<<ECHO);
	ECHO_PULLUP|=(1<<ECHO);
	enable_ex_interrupt();
	timer0_init();
	return;
}

void enable_ex_interrupt(void){

	MCUCR |= (1<<ISC10);		// Trigger INT1 on any logic change.
	GICR  |= (1<<INT1);			// Enable INT1 interrupts.

	return;
}

void ultra_triger(void){
	if(!sensor_working){
		TRIGER_PORT|=(1<<TRIGER);
		_delay_us(50);
		TRIGER_PORT&=~(1<<TRIGER);
		sensor_working=1;
	}
}

ISR(INT1_vect){
	if(sensor_working==1){
		if(rising_edge==0){
			TCNT0=0x00;
			rising_edge=1;
			timer_counter=0;
		}
		else{
			distance=(timer_counter*256+TCNT0)/933;
			_delay_ms(40);
			timer_counter=0;
			rising_edge=0;
		}
	}}

	ISR(TIMER0_OVF_vect){
		timer_counter++;
		if(timer_counter >1460){
			TCNT0=0x00;
			sensor_working=0;
			rising_edge=0;
			timer_counter=0;
		}
	}

	int get_distance(void)
	{
		ultra_triger();
		_delay_ms(15);
		return distance;
	}
