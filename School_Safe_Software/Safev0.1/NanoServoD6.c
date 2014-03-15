/*
 * Name: Darrel Griët
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include <util/delay.h>
#include "libs/safeFunctions.c"

int main(void)
{
	TIMSK0 |= (1<<TOIE0);
	sei();
	
	TCCR0B = (0<<CS02)|(0<<CS01)|(1<<CS00);
	
	DDRD |= (1<<PD6); //output on OC1 pin (portb.1)
	TCNT0 = 250;
	initShifter();
	initPowerControle();
	initRotary();
	while(1)
	{
		//displayNum(ticks);
	}
} 

ISR(TIMER0_OVF_vect)
{
	//ticks+=1;
	displayNum(ticks);
}
