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
	//initialize everything we are going to use.
	initShifter();
	initDisplay();
	initPowerControle();
	initRotary();
	init_uart();
	while(1)
	{
		//if a second as elapsed
		if(!(timer2_Count%147))
		{
			pin += 1;
		}
		//pin = timer2_Count;
		//displayNum(ticks);
	}
}
