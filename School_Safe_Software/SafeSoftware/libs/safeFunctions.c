/*
 * this file contains functions and variables
 * the safe will use.
 * */
 
#include <avr/interrupt.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>

#include "pinDefs.h"
#include "safeConstants.c" 		//contains constants related to safe funtioning.
#include "safeVariables.c" 		//contains safe variables.
#include "time.c"				//contains code related to keeping track of time.
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

void inputPinCode(){}
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
	uart_put_str("\r\n");
}
void close()
{
	setServoPos(SERVO_CLOSED); //lock the door
	finalServoPos = SERVO_CLOSED; //set the final state to be closed.
	
	//signal the java program that we have closed or are closing the door.
	uart_put(CLOSED);
	uart_put_str("\r\n");
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
					uart_clear();
					break;
				case ON:
					powerOn();
					uart_clear();
					break;
				case OPEN:
					open();
					uart_clear();
					break;
				case CLOSE:
					close();
					uart_clear();
					break;
				case SETPIN:
					pin = getPinParameter(inputStr);
					uart_clear();
					break;
				case LOGOUT:
					isLoggedIn = false;
					uart_put(DISCONNECTED);
					uart_put_str("\r\n");
					uart_clear();
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
					uart_put_str("\r\n");
				}
				else
				{
					isLoggedIn = false;
					uart_put(SERIAL_DENIED);
					uart_put_str("\r\n");
				}
				uart_clear();
				break;
			case BT:
				uart_put(BTOK);
				uart_put_str("\r\n");
				uart_clear();
				break;
			default:
				uart_clear();
				break;
		}
	}
}
