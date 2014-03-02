/*
 * author: Duality / Robert van der Tuuk
 * Edited on: 27 Nov 2013
 * 
 * Edited on: 4 Jan 2014
 * - created a system with to arrays, in one the change is stored, and the other the field is.
 *   this makes it work finally,
 *   gliders work oscilators work.
 *   hack even the lightweight glider works.
 * 
 * Edited on: 6 Jan 2014
 * - Created a way to reset the field by pushing a button.
 * - going to try and implement shapes that are stored in pagemem.
 *   Keep shapes in stucts so you don't need a whole field with a few
 *   cells in it. It wil also contain it's max width and max height. and size of the shape.
 * 
 * - I have added a few shapes. like the glider, and ligthweight spaceship.
 * - able to set contrast with potmeter.
 * 
 * Edited on: 28 Jan 2014
 * 	- been working on a system for calculating x and y form a position (position in array)
 *    ok just got it working! :)
 *    this wil help lots.
 * */

//clock speed 8mhz
#define F_CPU 8000000

//needed libraries
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

//the code for working with the display. 
#include "DmDisplay/DmDisplay.h"
//contains life forms.
#include "lifeForms.h"

//number it takes to survive and to reproduce/become alife.
#define surviveAbility 2
#define reproductiveNumber 3
//parameters that define how big the field is. and how big a buffer to use.
#define fieldWidth 16
#define fieldHeight 16
#define fieldSize (fieldWidth*fieldHeight)
uint8_t field[fieldSize];
//also create a buffer for holding all the changes.
uint8_t buffer[fieldSize];
//and include with functions that make the game of life go.
#include "life.cpp"
//display write location.
int x,y = 0;
//create a display instance
DmDisplay lcd;
//variables for determining wether we are is a steady state or still evolving.
uint8_t currentState = 0; 	//keeps current state.
uint8_t previousState = 0; 	//keeps previous field state.
uint8_t changeCount = 0; 	//how many iterations. the field is the same.
uint8_t holdingNumber = 15; //when to deside to change field.
//(holding number). how many iterations it takes before desiding that there is no evolution happening anymore.
//for holding how many iterations it took.
int iterations = 0;
//keeps position in field.
unsigned int position = 0;
//-------------------
//select mode, RANDOM, or HOUSE
#define HOUSE
// a pattern
uint8_t lightweight_spaceship[fieldSize] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

uint8_t form[fieldSize] = {
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
	};

uint8_t house[fieldSize] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

//for example copying a buffer into field.
void copy_buffer(uint8_t *buffer, uint8_t *field)
{
	int size = fieldSize;
	while(size--) field[size] = buffer[size];
}
//put a costume "pattern" onto the playing field.
void insert_pattern(uint8_t *pattern, uint8_t *field, LifeForm lifeForm, int position)
{
	int patternX = 0;
	int patternY = 0;
	if(fieldHeight-(position*fieldWidth) <= 0)
	{
		return;
	}
	else
	{
		if(position < fieldWidth){}
		for(int i = 0;i<lifeForm.size;i++)
		{
			
		}
	}
}
void insert_pattern(uint8_t *field, uint8_t *pattern)
{
	copy_buffer(pattern, field);
}
//init analog
void init_analog(void)
{
	//select 5v analog reference.
	ADMUX = (1<<REFS0);
	//enable adc and use a prescaler of 128
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
}
//adc returns a 10bit int so uint8_t isn't going to do it for us.
uint16_t adc_read(uint8_t ch)
{
	//only check for 3 first bits, or else we would select other options.
	ch &= 0x07;
	//clear first 3 bits before ORring, just incase.
	ADMUX = (ADMUX & 0xF8)|ch;
	//start conversion
	ADCSRA |= (1<<ADSC);
	//wait for it to complete.
	while(ADCSRA & (1<<ADSC));
	//return the value.
	return (ADC);
}
//writeFormated() for nicely printing things onto the screen.
void writeFormated(const char *aString)
{
	lcd.lcdChar(aString);
}
void writeFormated(uint8_t val, const char *aString)
{
	char str[21];
	sprintf(str, "%s%d", aString, val);
	lcd.lcdChar(str);
}
void writeFormated(int val, int val2, const char *aString)
{
	char str[21];
	sprintf(str, "%s%d, %d  ", aString, val, val2);
	lcd.lcdChar(str);
}
//write pixel data not instructions.
void writePixelData(uint8_t data)
{
	lcd.write(data, lcd.DATA);
}
//randomly create cells at position in field.
void random_fillField(uint8_t *field, int position)
{
	uint16_t randomVal = rand()%2;
	field[position] = (bool)randomVal;
}
//make a random playing field.
void createRandomField(uint8_t *field)
{
	for(int i = 0;i<fieldSize;i++)
		random_fillField(field, i);
}
void clearArray(uint8_t *buffer)
{
	int size = fieldSize;
	while(size--)buffer[size] = 0;
}
//used to draw a lifing cell with a box
void writeCell(void)
{
	//made a box out of the top of my head :)
	writePixelData(0xFF);
	writePixelData(0x81);
	writePixelData(0x81);
	writePixelData(0x81);
	writePixelData(0xFF);
}
//this actually is the same as lcd.lcdChar(" ");
//cause it just writes 5 empty bytes.
void writeBlock(void)
{
	for(int i = 0;i<5;i++)
	{
		lcd.write(0x00, lcd.DATA);
	}
}

void calcXY(int position, volatile int &x, volatile int &y)
{
	x = position%fieldWidth;
	if(!(x))
	{
		y++;
		if(y>=(fieldHeight))
		{
			y=0;
		}
	}
}

//display the field with position. (ascii cells)
void showField(uint8_t *field, int position)
{
	//calculate x and y location from position.
	calcXY(position,x, y);
	//set this location.
	lcd.setCursor(x,y);
	//draw a cell if there is a 1 at this position.
	//else draw a empty block.
	if(field[position])
	{
		//writeCell();
		lcd.writePixel(x,y,1);
	}
	else
	{
		lcd.writePixel(x,y,0);
	}
}
//my implementation of delay, it's blocking.
//_delay_ms(); requires a constant for an argument.
void delay(int n)
{
	while(n--)
	{
		_delay_ms(1);
	}
}
/*
void printDebug()
{
	lcd.setCursor(0,0);
	writeLCDvalue(position%fieldWidth, ">>Width");
	lcd.setCursor(0,1);
	writeLCDvalue(y, ">>Height");
	lcd.setCursor(0,2);
	writeLCDvalue(position,">>Position");
}*/
uint8_t checkField(uint8_t *field)
{
	uint8_t countCels = 0;
	for(int i = 0;i<fieldSize;i++)
	{
		if(field[i])
			countCels++;
	}
	return countCels;
}
int main(void)
{
	lcd.clearMarkers();
	//init analog if needed
	init_analog();
	srand(adc_read(0));
	
	//pin 0 on portb output. 
	//led stays on if iterations between fields are the same (same number of cells)
	DDRB |= _BV(PB0);
	
	//clear the buffer.
	clearArray(buffer);
	
	//if house define insert that.
	#ifdef HOUSE
		insert_pattern(field, house);
	#endif
	//else random field.
	#ifdef RANDOM
		createRandomField(field);
	#endif
	
	//set contrast.
	lcd.setContrast(17);
	//make sure to start at location 0,0
	lcd.setCursor(0,0);
	
	//position is field size, I refresh the screen Backwards.
	position = fieldSize;
	while(position--)
	{
		//display field with current position
		showField(field, fieldSize-position);
		//here the rules of the game of life are checked.
		//if a position has a cell (1),
		//then look how many around,
		//if 2 or 3 around it lives, else it dies.
		if(field[position])
		{
			if(totalAround(field, position)==surviveAbility)
			{
				buffer[position]=1;
			}
			else if(totalAround(field, position)==surviveAbility+1)
			{
				buffer[position]=1;
			}
			else
			{
				buffer[position]=0;
			}
		}
		else
		{
			//but if a position in the field is empty
			//and it has 3 around, that position becomes alife.
			
			if(totalAround(field, position)==reproductiveNumber)
			{
				buffer[position] = 1;
			}
			else
			{
				buffer[position] = 0;
			}
		}
		//position keeps position in the field array,
		//and at the same time drawing location on
		//screen.
		if(position == 0)
		{
			//insert changes into the field.
			copy_buffer(buffer, field);
			//reset position to 0
			position = fieldSize;
			//set frame rate with a blocking delay..
			delay(0); //worst way to do things
			//check wether we are in a steady state or just still evolving.
			currentState = checkField(field);
			//set contrast with pot meter on analog pin 1 (not 0)
			lcd.setContrast(adc_read(1)/32);
			//change field if field the same a while, or iterations goes above a certain number which meens it's probaly in a loop
			//check if button is pressed and create a new field.
			if(changeCount == holdingNumber || (iterations > 1000) || (PINB & (1<<PB2)))
			{
				//reset changeCount
				changeCount = 0;
				//reset iteration count.
				iterations = 0;
				//create a random playing field.
				createRandomField(field);
				//put a pattern we created onto the field.
				//insert_field(stable, field);
				
			}
			//if the field states stay the same.
			else if(currentState == previousState)
			{
				PORTB |= (1<<PB0);
				changeCount++;
			}
			//if the field states are different.
			else
			{
				PORTB &= ~(1<<PB0);
				previousState = currentState;
				//that is why setting it to zero.
				iterations++;
				//changeCount shouldn't change if the inbetween states happen te be the same.
				changeCount = 0;
			}
		//set location and nicely print something.
		lcd.setCursor(0,5);
		writeFormated(iterations,changeCount,"Game of Life:");
		}
	}
	return 0;
}
