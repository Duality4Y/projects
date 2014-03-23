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
 * */

#define F_CPU 8000000UL
//include needed libraries.
#include <avr/io.h>
#include <avr/interrupt.h>

#include "libs/pinDefs.h" //inlucde pindefinitions.
#include "libs/safeFunctions.c" //include functions that the safe uses.


int main(void)
{
	//some setup code
	
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
		//if there is new data we check to see the commands.
		if(serial_available)
		{
			serial_available = 0;
			runSerialInputCommands(inputStr);
		}
		//lets the user input the pincode.
		inputPinCode();
		//displays pin
		displayNum(pin);
	}
	
	return 1;
}


