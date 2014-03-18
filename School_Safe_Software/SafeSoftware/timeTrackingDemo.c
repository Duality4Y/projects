/*
 * Name: Darrel Griët
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include <util/delay.h>
#include "libs/safeFunctions.c"

#include <stdio.h>

int main(void)
{
	//initialize everything we are going to use.
	initShifter();
	initDisplay();
	initPowerControle();
	initRotary();
	init_uart();
	unsigned int previous = 0;
	while(1)
	{
		//pin = getSecondsPassed();
		unsigned int current = getSecondsPassed();
		if(current-previous > 1)
		{
			previous = current;
			pin += 1;
		}
		else
		{
			uart_put_str("ticks");
		}
	}
}
