/*
 * Author:
 * Robert
 * 
 * Note:
 * 	the libs folder contains the .h and .cpp/.c files that 
 * 	you want to include and use.
 * 
 * Edited: 10 - 03 - 2014
 * 	wil try implementing entering a number with rotary encoder.
 * 	implemented rotary
 * Edited: 24 - 03 - 2014
 * 	implemented command parsing.
 * 	implemented servo disable.
 * */

#define F_CPU 1000000UL
//include needed libraries.
#include <avr/io.h>
#include <avr/interrupt.h>

#include "libs/safeFunctions.c" //include functions that the safe uses.


int main(void)
{
	//some setup code
	storePin(1337);
	initPin();
	//initizialize power controle pins
	initPowerControle();
	//initizialize rotary.
	initRotary();
	//initialize shifter.
	initShifter();
	//initialize serial comm
	init_uart();
	//initialize the servo code.
	initServo();
	//main loop.
	while(1)
	{
	
		//if there is any data for debuging purposes print it.
		//uart_put_str(inputStr);
		//if there is new data we check to see the commands.
		if(serial_available)
		{
			serial_available = 0;
			runSerialInputCommands(inputStr);
		}
		//check the servo state, disable it when it's active
		//for longer then a second.
		if(isServoActive) //check to see if the state of the servo is active.
		{
			if(time-previousServo > 4)//see if 5 ticks have passed and thus a second has passed.
			{
				if(finalServoPos != getCurrentServoState())
				{
					setServoPos(finalServoPos);
				}
				else
				{
					disableServo();
				}
			}
		}
		//displays pin
		displayNum(pin);
	}
	
	return 1;
}


