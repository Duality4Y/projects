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
	//initialize everyting we are going to use.
	initShifter();
	initDisplay();
	initPowerControle();
	//preset a value to show it actually works.
	//and it will show 1234 on the display.
	pin = 1234;
	/*
	 * if everything works the display wil show pin.
	 * */
	while(1)
	{
		//displayNum(ticks);
	}
}
