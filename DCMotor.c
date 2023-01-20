/*
 * DCMotor.c
 *
 * Created: 1/19/2023 3:49:20 PM
 *  Author: user
 */ 
#include "DcMotor.h"
#include <util/delay.h>


void motor_init(void)
{
	DDRC |= 0XFF;
	DDRD |= (1<<PD4); //SET enable pins as output
	DDRC |= (1<<PC1); //SET enable1 as output
}
void motor_1_forward(void)
{
	PORTD |= (1<<PD4); //enable
	
	PORTC |= (1<<PC4);
	PORTC &= ~(1<<PC3);
}
void motor_1_backward(void)
{
	PORTD |= (1<<PD4); //enable

	PORTC |= (1<<PC3);
	PORTC &= ~(1<<PC4);
}
void motor_2_forward(void)
{
	PORTC |= (1<<PC1);
	
	PORTC |= (1<<PC6);
	PORTC &= ~(1<<PC5);
}
void motor_2_backward(void)
{
	PORTC |= (1<<PC1);

	PORTC |= (1<<PC5);
	PORTC &= ~(1<<PC6);
}
void motor_stop(void)
{
	PORTC =0x00;
	//PORTC &= ~(1<<PC3);
	//PORTC &= ~(1<<PC4);
}

void move(void)
{
	motor_1_forward();
	motor_2_forward();
}

void all_backward(void)
{
	motor_1_backward();
	motor_2_backward();
	_delay_ms(200);
	motor_stop();

}

void right(void)
{
	motor_1_forward();
	_delay_ms(500);
	motor_stop();
	
}
void left(void)
{
	motor_2_forward();
	_delay_ms(600);
	motor_stop();
}

