/*
 * this file contains functions and variables
 * the safe will use.
 * */
 
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>

#include "time.c"				//contains code related to keeping track of time.
#include "pinDefs.h"
#include "safeFunctions.h"
#include "safeConstants.c" 		//contains constants related to safe funtioning.
#include "safeVariables.c" 		//contains safe variables.
#include "uart.c" 				//include basic uart capability written by Robert.
#include "servo.c" 				//servo related code
#include "rotary.c" 			//rotary related code
#include "pinStore.c"			//code for storing the pin in eeprom.
#include "shifter.c"
#include "display.c"

//create a link to the serial buffer to use.
volatile unsigned char* inputStr = uart_buffer;

//inits the power control pin.
void initPowerControle()
{
	DDRD  |= 	( 1<<POWERCONTROL );//power control pin to output.
	PORTD |=   ~( 1<<POWERCONTROL ); //enable internal pullup on POWERCONTROL pin
}

//this function powers on the elecktronics.
void powerOn()
{
	PORTD &= ~(1<<POWERCONTROL); //switch transistor on
	DDRB |= (1<<LATCH)|(1<<CLOCK)|(1<<DATA_OUT);//turn shifter pins back to original state.
}
//this function wil power of the elecktronics.
void powerOff()
{
	
	PORTD |= (1<<POWERCONTROL); //switch transistor off.
	DDRB &= ~( (1<<LATCH)|(1<<CLOCK)|(1<<DATA_OUT)); //turn shifter pins high impedance.
}
//this function will get the current inputed pincode from left to right;
void getInputPinCode()
{
	
	static int digitPlace = 1000;
	static int temp_pin = 0;
	cli();
	//send directional information for encoder animation.
	//and to go to next digit.
	if(direction != prev_direction)
	{
		//set correct pin.
		if(direction)
			temp_pin += ((ticks%10)+1)*digitPlace;
		else
			temp_pin += ((ticks%10)-1)*digitPlace;
		digitPlace /= 10;
		//if we go off the screen to the right
		if(digitPlace <= 0)
		{
			pin = temp_pin+(ticks%10)*digitPlace;
			temp_pin = 0;
			digitPlace = 1000;
		}
		prev_direction = direction;
		//this will send information for the rotary animation
		if(direction)
		{
			uart_put(ROTARY_LEFT);
		}
		else
		{
			uart_put(ROTARY_RIGHT);
		}
		ticks = 100;
	}
	//also send once a while, to counter mis displays.
	else if(!(time%(timeScale/2)) && isLoggedIn)
	{	
		close();
		sendNumber(temp_pin+(ticks%10)*digitPlace);
	}
	sei();
	//always display
	displayedNum = temp_pin+(ticks%10)*digitPlace;
	//if encoder is pressed clear current digit.
	if(!(PIND & (1<<ENCODER_BUTTON))) // if encoder pin is pressed
	{
		ticks = 100;//pin = (digitPlace*(ticks%10));
	}
}
//this function will make the safe enter sleep mode.
void sleep()
{
	cli();
	sleep_enable();
	/* 0, 1, or many lines of code here */
	set_sleep_mode(SLEEP_MODE_PWR_DOWN);
	sleep_cpu();
	/* wake up here */
	sleep_disable();
	sei();
	powerOn();
}
void open()
{
	setServoPos(SERVO_OPENED); //unlock and push the door out.
	finalServoPos = SERVO_OPENED; //set the final state to be open.
	
	//signal the java program that we have done ar requested.
	uart_put(OPENED);
}
void close()
{
	setServoPos(SERVO_CLOSED); //lock the door
	finalServoPos = SERVO_CLOSED; //set the final state to be closed.
	
	//signal the java program that we have closed or are closing the door.
	uart_put(CLOSED);
}
//could be used to get a pin after a command.
int getPinParameter(volatile unsigned char* inputStr)
{
	int i = 0;
	int temp_pin = i;
	uart_clear();
	//clear fifth byte
	inputStr[4] = '\0';
	while(!inputStr[4]){}; //wait for the pincode to arrive.
	//disable interupts as to prevent the data from being changed while processed.
	//cli();
	while(i < 4)
	{
		temp_pin *= 10;
		temp_pin += inputStr[i];
		i++;
	}
	//sei();
	return temp_pin;
}

void sendNumber(int num)
{
	//uart_put(SEGMENT);
	//int p,i;
	//for(i = 0,p = 1;i<4;p*=10,i++)
	//{
	//	uart_put((num/p)%p);
	//}
	//uart_put(END_OF_TRANSMISSION);
	//easy and dirty way .. 
	uart_put(SEGMENT);
	uart_put(num/1000);
	uart_put((num/100)%10);
	uart_put((num/10)%10);
	uart_put(num%10);
	uart_put(15);
}
void runSerialInputCommands(volatile unsigned char* inputStr)
{
	//see if there is anything in the buffer.
	if(inputStr[0])
	{		
		//actions that can be taken when logged in.
		if(isLoggedIn)
		{
			switch(inputStr[0])
			{
				case OFF:
					powerOff();
					break;
				case ON:
					powerOn();
					break;
				case OPEN:
					open();
					break;
				case CLOSE:
					close();
					break;
				case SETPIN:
					pin = getPinParameter(inputStr);
					break;
				case LOGOUT:
					isLoggedIn = false;
					uart_put(DISCONNECTED);
					break;
				default:
					uart_clear();
					break;
			}
		}
		switch(inputStr[0])
		{
			case LOGIN:
				//pin = getPinParameter(inputStr);
				if(pin == getPinParameter(inputStr))
				{
					isLoggedIn = true;
					uart_put(SERIAL_ACCES);
				}
				else
				{
					isLoggedIn = false;
					uart_put(SERIAL_DENIED);
				}
				break;
			case BT:
				uart_put(BTOK);
				sendNumber(actual_pin);
				break;
			default:
				//uart_clear();
				break;
		}
		uart_clear();
	}
}
