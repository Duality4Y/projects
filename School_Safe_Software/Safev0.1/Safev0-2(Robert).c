/*
 * Author:
 * Robert
 * 
 * Note:
 * 	the libs folder contains the .h and .cpp/.c files that 
 * 	you want to include and use.
 * */

#define F_CPU 1000000
//include needed libraries.
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#include "libs/uart.c" //include basic uart capability written by Robert.

//pin defines 
#define POWERCONTROL 	PD6
#define LATCH 			PB0
#define CLOCK 			PB1
#define DATA_OUT		PB2

#define ENCODER_PIN_A 	PD2
#define ENCODER_PIN_B	PD3
#define ENCODER_BUTTON	PD4

volatile uint8_t ticks = 0; //keeps rotary ticks
volatile uint8_t direction = 0; //keeps direction so we can keep track when to jump to the next number.
int pin = 1234;


void shiftOut(uint8_t data)
{
	uint8_t i = 7;
	
	PORTB &= ~( 1<<LATCH ); //pull latch low
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
	//initialize uart
	init_uart();
	//main loop.
	while(1)
	{
		pin = atoi(uart_buffer);
		displayNum(pin);
		/*
		int i;
		for(i = 0;i<10000;i++)
			displayNum(i);
		*/
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
		ticks++;
	}
}
//same for this function only subtracting ticks.
ISR(INT1_vect)
{
	if((PIND & (1<<ENCODER_PIN_A)))
	{
		ticks--;
	}
}
