/*
 * this file contains functions and variables
 * the safe will use.
 * */
 
#include <avr/interrupt.h>
#include <avr/eeprom.h>

#include "pinDefs.h"
#include "safeConstants.c" 		//contains constants related to safe funtioning.
#include "safeVariables.c" 		//contains safe variables.
#include "time.c"				//contains code related to keeping track of time.
#include "uart.c" 				//include basic uart capability written by Robert.
#include "servo.c" 				//servo related code
#include "rotary.c" 			//rotary related code
#include "pinStore.c"			//code for storing the pin in eeprom.

//create a link to the serial buffer to use.
volatile unsigned char* inputStr = uart_buffer;

void initShifter()
{
	DDRB  |= 	 ( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT ); //register pins to output
	PORTB &=   ~(( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT )); //clear register pins.
}

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
//this function shifts out data.
void shiftOut(uint8_t data)
{
	PORTB &= ~( 1<<LATCH ); //pull latch low
	volatile int i = 7;
	while(i >= 0)
	{
		//check i'th bit against data, shift it by I to the right.
		//and then shift it by DATA_OUT to the left. so the port becomes the value of the
		//i'th bit.
		PORTB |= (( (data & ( 0x01<<i )) >> i ) << DATA_OUT );
		//toggle the clock.
		PORTB |= ( 1<<CLOCK );
		PORTB &= ~( 1<<CLOCK );
		//then clear the bit on the pin.
		PORTB &= ~(( (data & ( 0x01<<i )) >>i ) << DATA_OUT );
		i--;//decrement counter
	}//decrementing counter meens msb first.
	PORTB |= ( 1<<LATCH ); //pull latch high
}
//this function wil display a number onto the 7 segment display.
void displayNum(int num)
{
	/*
	 * the variable m is kind of like a mask.
	 * the first time in the loop m = 1234
	 * then when we display it does 1234%10 which is 4
	 * for the next itteration m = 123
	 * and when we display the next number on the next display
	 * we do 123%10 and that displays 3
	 * and so on and so on.
	 * we repeat it so fast the numbers appears one by one on the display
	 * */
	 
	 //quick check to see if the nummber is out of range
	 if(num > 9999 || num < 0)
		num = 0;
	 
	uint8_t segment = 1; //keep track of which segment is selected
	//i is used to determine which segment is selected.
	//and m is sed to determine which 10 power of num we display.
	int i,m; 
	for(i = 0,m = num;i<4;i++,m/=10)
	{
		//select display/segment
		segment = 0xF0 & ~((1<<i)<<4); //this selects the transistor to switch
		shiftOut(segment | m%10); //this all shifts out the data
	}
}

void inputPinCode(){};

void open()
{
	enableServo();
	
	setServoPos(0); //unlock and push the door out.
	finalServoPos = SERVO_OPENED; //set the final state to be open.
	
	//signal the java program that we have done ar requested.
	uart_put(OPENED);
	uart_put_str("\r\n");
}
void close()
{
	enableServo();
	
	setServoPos(10); //lock the door
	finalServoPos = SERVO_CLOSED; //set the final state to be closed.
	
	//signal the java program that we have closed or are closing the door.
	uart_put(CLOSED);
	uart_put_str("\r\n");
}
//could be used to get a pin after a command.
int getPinParameter(volatile unsigned char* inputStr)
{
	int i,temp_pin = 0;
	uart_clear();
	//clear fifth byte
	inputStr[4] = '\0';
	while(!inputStr[4]){}; //wait for the pin to arrive.
	//disable interupts as to prevent the data from being changed while processed.
	cli();
	while(i < 4)
	{
		temp_pin *= 10;
		temp_pin += inputStr[i];
		i++;
	}
	sei();
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
				if(pin == getPinParameter(inputStr))
				{
					isLoggedIn = true;
					uart_put_str("SACCES\r\n");
				}
				else
				{
					isLoggedIn = false;
					uart_put_str("SDENIED\r\n");
				}
				uart_clear();
				break;
			case BTOK:
				uart_put_str("BTOK\r\n");
				uart_clear();
				break;
			default:
				uart_clear();
				break;
		}
	}
}
