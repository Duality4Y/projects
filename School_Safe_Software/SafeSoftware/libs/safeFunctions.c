/*
 * this file contains functions and variables
 * the safe will use.
 * */
#include <avr/interrupt.h>
#include <util/delay.h>
#include <string.h>
#include "pinDefs.h"
#include "safeVariables.c" //contains safe variables.
#include "uart.c" //include basic uart capability written by Robert.
#include "servo.c" //servo related code
#include "rotary.c" //rotary related code
#include "commandDefs.c" //has rules for talking to micro controller and computer.

//will keep time. using timer2
volatile unsigned long timer2_Count = 0;
unsigned int seconds = 0;

//create a link to the serial buffer to use.
volatile unsigned char* inputStr = uart_buffer;

//will hold formated string
unsigned char prettyString[50];

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
	
	setServoPos(0); //unlock and push door.
	_delay_ms(1000);
	setServoPos(5); //go back half, leave unlocked and be out of the way.
	_delay_ms(1000);
	
	disableServo();
}
void close()
{
	enableServo();
	setServoPos(10);
	_delay_ms(1000);
	disableServo();
}
//could be used to get a pin after a command.
int getPinParameter(volatile unsigned char* inputStr)
{
	int i,temp_pin = 0;
	//clear fifth bit
	uart_clear();
	inputStr[4] = '\0';
	while(!inputStr[4]){}; //wait for the pin to arrive.
	while(i < 4)
	{
		temp_pin *= 10;
		temp_pin += inputStr[i];
		i++;
	}
	return temp_pin;
}
void runSerialInputCommands(volatile unsigned char* inputStr)
{
	
	//if there is any data for debuging purposes print it.
	uart_put_str(inputStr);
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
				default:
					uart_clear();
					break;
			}
		}
		//action that can/need to be taken when not logged in.
		if(!isLoggedIn)
		{
			switch(inputStr[0])
			{
				case LOGIN:
					uart_put_str("got here! \r\n");
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
			}
		}
		//commands available if authorized or not.
		switch(inputStr[0])
		{
			case BTOK:
			uart_put_str("BTOK\r\n");
			uart_clear();
			break;
		}
		//always clear uart
		uart_clear();
	}
}
