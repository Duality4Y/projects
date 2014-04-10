/*
 * Author:
 * Robert van der tuuk
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
 * Edited: 24 - 29 - 2014
 * 	implementing noblocking screen displaying.
 * */

#define F_CPU 8000000UL
//include needed libraries.
#include <avr/io.h>
#include <avr/interrupt.h>

#include "libs/safeFunctions.c" //include functions that the safe uses.

int previousTime = 0;
int interval = 2;
void sendNumber(int num)
{
	//uart_put(SEGMENT);
	//int p,i;
	//for(i = 0,p = 1;i<4;p*=10,i++)
	//{
	//	uart_put((num/p)%p);
	//}
	//uart_put(END_OF_TRANSMISSION);
	uart_put(SEGMENT);
	uart_put(1);
	uart_put(3);
	uart_put(3);
	uart_put(8);
	uart_put(15);
}

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
	//initialize display code.
	initDisplay();
	//initialize serial comm
	init_uart();
	//initialize the servo code.
	initServo();
	//initialize time code
	initTime();
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
		//if a 20seconds has elapsed turn safe off.
		if(!(PIND & (1<<ENCODER_BUTTON)))
		{
			sendNumber(1338);
			displayedNum = 1338;
		}
		else
			displayedNum = time/timeScale;
		
	}
	
	return 1;
}

