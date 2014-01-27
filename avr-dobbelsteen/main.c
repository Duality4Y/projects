/*
 * Author: Duality
 * Edited: 17-12-2013
 * Edited: 18-12-2013
 * 
 * made a function that displays thrown numbers.
 * made a function that chooses a random function.
 * made a function for rolling the dice.
 * 
 * 18-12
 * 
 * edited tilting discision.
 * made it more reliable.
 *	
 * */
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
//for debugging.
#define debug 
//maps pins to numbers (dice numbers)
#define ONE 			(1<<PA3)
#define TWO_ONE 		(1<<PA0)|(1<<PA4)
#define TWO_TWO 		(1<<PA2)|(1<<PA6)
#define THREE_ONE 		ONE|TWO_ONE
#define THREE_TWO		ONE|TWO_TWO
#define FOUR			TWO_ONE|TWO_TWO
#define FIVE			FOUR|ONE
#define SIX 			FOUR|(1<<PA1)|(1<<PA5)
#define number_of_sides 8
//the number of defined throws + 1, the last keeps the random throw.
uint8_t dice_sides[number_of_sides+1] = 
{
	ONE,TWO_ONE,FOUR,THREE_ONE,TWO_TWO,THREE_TWO,FIVE,SIX,0
};
//delay because _delay_ms() doesn't take variable arguments
void delay(uint16_t delay_val)
{
	while(delay_val--)_delay_ms(1);
}
//throws a number and displays it.
void throw_number(uint8_t number)
{
	if(number < number_of_sides)
	{
		PORTA = dice_sides[number];
	}
	else
	{
		PORTA = dice_sides[dice_sides[number]];
	}
}
//chooses a random side to throw.
void choose_rand_side()
{
	uint8_t random_side = 0;
	random_side = rand()%number_of_sides;
	dice_sides[number_of_sides] = random_side;
}
//throws the dice. aka chooses a random number and displays it.
void throw_dice()
{
	int i;
	choose_rand_side();
	for(i = 0;i<=number_of_sides;i++)
	{
		throw_number(i);
		delay(i*i*20+100);
	}
}
void get_motion(uint8_t *sw1, uint8_t *sw2)
{
	*sw1 = (PINB&(1<<PB0));
	*sw2 = (PINB&(1<<PB1));
}
int main(void)
{
	DDRB &= ~(1<<PB2); //sensor input and button.
	DDRA |= (0xFF);
	srand(20);
	uint8_t sw1 = 0;
	uint8_t sw2 = 0;
	while(1)
	{
		//will be handled with interupt when moved to attiny84
		#ifndef debug
			if(PINB & (1<<PB2))
			{
				while(PINB & (1<<PB2));
					_delay_ms(20);
					throw_dice();
			}
			else if((sw1 | sw2) && !(sw1 & sw2))
			{
				throw_dice();
			}
		#endif
		sw1 = (PINB&(1<<PB0));
		sw2 = (PINB&(1<<PB1));
		//debugging.
		#ifdef debug
			//turns on bottom left led if sw1 is high. else turns it off.
			if(sw1){PORTA |= (1<<PA0);}else{PORTA &= ~(1<<PA0);}
			//does the same for bottom right led.
			if(sw2){PORTA |= (1<<PA6);}else{PORTA &= ~(1<<PA6);}
		#endif
	}
	return 0;
}
