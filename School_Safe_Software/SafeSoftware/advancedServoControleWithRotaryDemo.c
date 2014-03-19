/*
 * Name: Robert van der Tuuk
 * Project: Servo code
 * Date: March-19-2014
 * 
 * this code works.
 * 
 * basicly there are to interupst that are called,
 * with OCR2A you set the freq.
 * and with OCR2B you set the on period.
 */

#define F_CPU 8000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include "libs/safeFunctions.c"

int main(void)
{
	//initialize timer 2 with a prescaler of 1024 and wave form generation ctc.
	TCCR2A |= (1<<WGM21); 
	TCCR2B |= (1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK2 |= (1<<OCIE2A)|(1<<OCIE2B); //enable compare interupst.
	OCR2A = 158; // 8000000/1024/50 = 156.25 but the scope shows 158 closer to 20ms pulse.
	OCR2B = 0; //period controle.
	sei(); //enable global interups.
	
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


//this interupt service routine is entered to set the off period.
ISR(TIMER2_COMPB_vect)
{
	PORTD &= ~(1<<PD6);
}
//this interupt service routine is entered to set the on period
//when this interupt service routine is enterd (at which time) will also determine the frequentie.
ISR(TIMER2_COMPA_vect)
{
	TCNT2 = 0;
	PORTD |= (1<<PD6);
}

