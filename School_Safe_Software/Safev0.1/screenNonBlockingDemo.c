/*
 * Name: Darrel Gri�t
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include <util/delay.h>
#include "libs/safeFunctions.c"

int main(void)
{	
	DDRD |= (1<<PD6); //output on OC1 pin (portb.1)
	initShifter();
	initDisplay();
	initPowerControle();
	initRotary();
	//preset a value to show it actually works.
	//and it will show 1234 on the display.
	pin = 1234;
	while(1)
	{
		//displayNum(ticks);
	}
}
