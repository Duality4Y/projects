/*
 * Author:
 * Robert van der tuuk
 * 
 * Had some help from Darrel
 * he helped on keeping track of time.
 * and with servo code.
 * 
 * also together we decided on a protocol to talk over,
 * which can be found in Commands.txt
 * 
 * another note though is that this code is not yet finished!
 * it is still a work in progress, but it has got alot working already!
 * like sending and recieving serial command
 * controlling the display.
 * reading the rotary.
 * and controlling the servo.
 * making sure the right pin is entered is implemented,
 * and storing and modifing this pin is implemented.
 * turning the whole safe on and off is implemented.
 * 
 * what is left to implement is that 
 * 
 * Note:
 * 	the libs folder contains the .h and .cpp/.c files that 
 * 	you want to include and use.
 * servo uses timer 2
 * time uses timer 0
 * display uses timer 1
 * 
 * Edited: 10 - 03 - 2014
 * 	wil try implementing entering a number with rotary encoder.
 * 	implemented rotary
 * Edited: 24 - 03 - 2014
 * 	implemented command parsing.
 * 	implemented servo disable.
 * Edited: 24 - 03 - 2014
 * 	implementing noblocking screen displaying.
 * */

#define F_CPU 8000000UL
//include needed libraries.
#include <avr/io.h>
#include <avr/interrupt.h>

#include "libs/safeFunctions.c" //include functions that the safe uses.

int previousTime = 0;
int interval = 2;

int main(void)
{
	//some setup code
	//storePin(1337); //only once needed
	initPincode();
	//initizialize power controle pins
	initPowerControle();
	//initizialize rotary.
	initRotary();
	//initialize shifter.
	initShifter();
	//initialize display code.
	initDisplay();
	//initialize serial comm
	init_uart();
	//initialize the servo code.
	initServo();
	//initialize time code
	initTime();
	//main loop.
	DDRB  |= (1<<PB4)|(1<<PB5);
	PORTB |= (1<<PB5)|(1<<PB4);
	while(1)
	{
		//get the input from user for pincode
		getInputPinCode();
		//if there is new data we check to see the commands.
		if(serial_available)
		{
			serial_available = 0;
			runSerialInputCommands(inputStr);
		}
		//check the servo state, disable it when it's active
		//for longer then a second.7
		if(isServoActive) //check to see if the state of the servo is active.
		{
			if(time-previousServo > timeScale)//see if a second has passed
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
		
		//send number if logged in and ticks changed and rotary has turned.
		//to prevent spam
		if(rotary_has_turned && ticks != previous_ticks && isLoggedIn)
		{
			previous_ticks = ticks;
			rotary_has_turned = 0;
			sendNumber(pin);
		}
		//if pin is correctly set set green led, els red on.
		if(pin == 1337)
		{
			PORTB |= (1<<PB5);
			PORTB &= ~(1<<PB4);
		}
		else
		{
			PORTB |= (1<<PB4);
			PORTB &= ~(1<<PB5);
		}
		
		//toggle pins for debug.
		//if(!(time%timeScale))
		//	PORTB ^= (1<<PB4)|(1<<PB5);
		
	}
	
	return 1;
}

