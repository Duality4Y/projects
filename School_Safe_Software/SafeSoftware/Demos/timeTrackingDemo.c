/*
 * Name: Darrel Griët
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include "libs/safeFunctions.c"

int main(void)
{
	//initialize timer 2 with a prescaler of 1024 and wave form generation ctc.
	TCCR2A |= (1<<WGM21);
	TCCR2B |= (1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK2 |= (1<<OCIE2A)|(1<<OCIE2B);
	OCR2A = 158;
	OCR2B = 0;
	sei();
	
	DDRD |= (1<<PD6);
	//initialize everything we are going to use.
	initShifter();
	initPowerControle();
	initRotary();
	//init_uart();
	ticks = 4;
	while(1)
	{
		displayNum(ticks);
		OCR2B = ticks;
		if(ticks > 14)
			ticks = 14;
		if(ticks < 4)
			ticks = 4;
	}
}

ISR(TIMER2_COMPB_vect)
{
	PORTD &= ~(1<<PD6);
}
ISR(TIMER2_COMPA_vect)
{
	PORTD |= (1<<PD6);
	//PORTD |= (1<<PD6);
	//OCR2A = ticks;
	//int final = (ticks/100);
	//PORTD ^= (1<<PD6);displayNum(ticks);
}

