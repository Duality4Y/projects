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
#include <string.h>
#include <avr/eeprom.h>
#include <stdio.h>

#include "libs/uart.c" //include basic uart capability written by Robert.

#define true 1
#define false 0

//pin defines 
#define POWERCONTROL 	PD6
#define LATCH 			PB0
#define CLOCK 			PB1
#define DATA_OUT		PB2

#define ENCODER_PIN_A 	PD2
#define ENCODER_PIN_B	PD3
#define ENCODER_BUTTON	PD4

volatile uint8_t ticks = 100; //keeps rotary ticks
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
volatile uint8_t prev_direction = 1;
//keep track of how many times the direction changes.
volatile static uint8_t direction_count = 0;
int pin = 1234; //the actuall pin.
int new_pin = 1234; //currently displayed pin.
uint8_t isLoggedIn = 0;

//will hold formated string
unsigned char prettyString[50];


void shiftOut(uint8_t data)
{
	PORTB &= ~( 1<<LATCH ); //pull latch low
	int i = 7;
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
	uint8_t segment = 1;
	int i,m;
	for(i = 0,m = num;i<4;i++,m/=10)
	{
		//select display/segment
		segment = 0xF0& ~((1<<i)<<4); //this selects the transistor to switch
		shiftOut(segment | m%10); //this all shifts out the data
	}
}

void inputPin()
{
	//if the direction changed 4 times we set pin to zero
	if(direction_count > 4 )
	{
		//reset everything so we can start over entering the number.
		prev_direction = direction = direction_count = pin = new_pin = 0;
		ticks = 100;
	}
	//if the direction changes
	if(direction != prev_direction)
	{
		//when we detect a change in direction increase direction_count.
		direction_count++;
		//make the prev_direction the current one.
		//so we can detect a change again.
		prev_direction = direction;
		ticks = 100; //set ticks to 100 so the first number start at zero (modulo 10)
		new_pin = pin*10; //shift the digit to the left.
	}
	//if the direction doesn't change
	else
	{
		pin = new_pin + (ticks%10);//the pin is the shifted number + the actually change of the first number.
	}
}
void lock(uint8_t isLocked){}
void enterCommandMode(unsigned char* inputStr)
{
	uart_clear();
	uart_put_str("\nentering command mode. \n\r");
	while(strcmp("exit", inputStr) != 0)
	{
		
	}
}
void runSerialInputCommands(unsigned char* inputStr)
{
	//uart_put_str(inputStr);
	//if there is data in the buffer
	if(inputStr[0])
	{
		//parse commands
		if(strcmp("1", inputStr) == 0)
		{
			PORTD &= ~(1<<POWERCONTROL);
			uart_clear();
		}
		else if(strcmp("0", inputStr) == 0)
		{
			PORTD |= (1<<POWERCONTROL);
			uart_clear();
		}
		else if(strcmp("open", inputStr) == 0)
		{
			uart_put_str("\nOpening...\n\r");
			lock(true);
			uart_clear();
		}
		else if(strcmp("close", inputStr) == 0)
		{
			uart_put_str("\nClosing...\n\r");
			lock(false);
			uart_clear();
		}
		else if(strcmp("login", inputStr) == 0)
		{
			uart_clear();
			uart_put_str("enter pin: (exit to leave)\n");
			while(true)
			{
				if(pin == atoi(inputStr))
				{
					uart_put_str("pin matches acces granted.\n");
					uart_clear();
					isLoggedIn = true;
					break;
				}
				if(strcmp("exit", inputStr) == 0)
				{
					uart_put_str("leaving\n");
					uart_clear();
					isLoggedIn = false;
					break;
				}
			}
			uart_clear();
			/*
			if(strcmp(strPin, inputStr) == 0)
			{
				isLoggedIn = true;
				enterCommandMode(inputStr);
			}
			else
			{
				uart_put_str("pin doesn't match\n");
			}*/
		}
		/*
		else if(strcmp("sread", inputStr) == 0)
		{
			uart_put_str("\nServo value: \n\r");
			uart_clear();
		}
		//use strstr and strtok for composite commands.
		else if(strstr("pset", inputStr))
		{
			uart_put_str(inputStr);
			uart_clear();
		}
		else if(strcmp("pread", inputStr) == 0)
		{
			sprintf(prettyString, "\nPIN: %d \n\r", pin);
			uart_put_str(prettyString);
			uart_clear();
		}
		else if(strcmp("sleep", inputStr) == 0)
		{
			//sleep();
		}
		else if(strcmp("logout", inputStr) == 0)
		{
			
		}*/
	}
	else
	{
		uart_clear();
	}
}
int main(void)
{
	//some setup code
	
	//enable internal interupts.
	EICRA |= 	( 1<<ISC01 );//enable INT1 to trigger on falling edge.
	EICRA |= 	( 1<<ISC11 );//enable INT0 to trigger on falling edge.
	EIMSK |= 	( 1<<INT0 )|( 1<<INT1 );
	sei();
	
	DDRD  |= 	( 1<<POWERCONTROL );//power control pin to output.
	PORTD |=   ~( 1<<POWERCONTROL ); //enable internal pullup on POWERCONTROL pin
	//set encoder pins to input.
	DDRD  &=   ~(( 1<<ENCODER_PIN_A )|( 1<<ENCODER_PIN_B )|( 1<<ENCODER_BUTTON ));
	PORTD |= 	 ( 1<<ENCODER_PIN_A )|( 1<<ENCODER_PIN_B )|( 1<<ENCODER_BUTTON ); //set pullups on encoder pins.
	
	DDRB  |= 	 ( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT ); //register pins to output
	PORTB &=   ~(( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT )); //clear register pins.
	
	//main loop.
	init_uart();
	//serial comm
	unsigned char* inputStr = uart_buffer;
	while(1)
	{
		runSerialInputCommands(inputStr);
		//always display pin
		inputPin();
		displayNum(pin);
	}
	
	return 1;
}
//this interupt service routine is entered when pin a is triggered.
ISR(INT0_vect)
{
	//if the pin it's self is low, and pin b is high we now rotation happend
	//and thus add ticks.
	if((PIND & (1<<ENCODER_PIN_B)))
	{
		direction = 1; //keep direction
		ticks--; //update ticks
	}
}
//same for this function only adding ticks.
ISR(INT1_vect)
{
	if((PIND & (1<<ENCODER_PIN_A)))
	{
		direction = 0;
		ticks++;
	}
}


