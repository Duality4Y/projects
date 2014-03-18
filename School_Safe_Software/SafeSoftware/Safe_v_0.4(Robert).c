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

#define F_CPU 1000000
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
	//initialize display
	//initDisplay();
	//initialize serial comm
	init_uart();	
	//main loop.
	while(1)
	{
		runSerialInputCommands(inputStr);
		//uart_put_str(inputStr);
		//always display pin
		inputPin();
		pin = ticks;
		displayNum(pin);
	}
	
	return 1;
}


