/*
 * Name: Darrel Griët
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include <util/delay.h>
#include "libs/safeFunctions.c"

unsigned long timer2_Count = 0;

int main(void)
{
	//enable the timer overflow interupt.
	TIMSK2 |= (1<<TOIE2);
	//no prescaler no wave form generation and no pin toggle.
	TCCR2B = (0<<CS22)|(0<<CS21)|(1<<CS20);
	//enable global interrupts.
	sei();
	
	DDRD |= (1<<PD6); //output on OC1 pin (portb.1)
	initShifter();
	initPowerControle();
	initRotary();
	while(1)
	{
		//displayNum(ticks);
	}
} 

ISR(TIMER2_OVF_vect)
{
	timer2_Count += 1;
	if(! (timer2_Count%220))
		ticks = !ticks;
	//ticks+=1;
	displayNum(ticks);
}
