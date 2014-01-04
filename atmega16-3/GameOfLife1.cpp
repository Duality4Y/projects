/*
 * author: Robert van der Tuuk
 * Edited on: 27 Nov 2013
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
#include "DmDisplay.h"

//display write location.
int x,y = 0;
//create a display instance
DmDisplay lcd;
//number it takes to survive and to reproduce/become alife.
#define surviveAbility 2
#define reproductiveNumber 3
//parameters that define how big the field is. and how big a buffer to use.
#define fieldWidth 20
#define fieldHeight 5
#define fieldSize (fieldWidth*fieldHeight)
uint8_t field[fieldSize];
//also create a buffer for holding all the changes.
uint8_t buffer[fieldSize];
//and include with functions that make the game of life go.
#include "life.cpp"
//variables for determining wether we are is a steady state or still evolving.
uint8_t currentState = 0; 	//keeps current state.
uint8_t previousState = 0; 	//keeps previous field state.
uint8_t changeCount = 0; 	//how many iterations. the field is the same.
uint8_t holdingNumber = 10; //when to deside to change field.
//(holding number). how many iterations it takes before desiding that there is no evolution happening anymore.
//for holding how many iterations it took.
uint8_t iterations = 0;
//keeps position in field.
uint8_t position = 0;
//-------------------

// field
uint8_t stable[fieldSize] = {
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
	};

//put a costume "pattern" onto the playing field.
void insert_field(uint8_t *pattern, uint8_t *field)
{
	int size = fieldSize;
	while(size--)field[size] = pattern[size];
}
void switch_back_buffer(uint8_t *buffer, uint8_t *field)
{
	int size = fieldSize;
	while(size--) buffer[size] = field[size];
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
void writeFormated(int val, const char *aString)
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
//display the field with position.
void showField(uint8_t *field, int position)
{
	//calculate x and y location from position.
	x = position%fieldWidth;
	if(!(position%fieldWidth))
	{
		y++;
		if(y>(fieldHeight-1))
		{
			y=0;
		}
	}
	//set this location.
	lcd.setCursor(x,y);
	//draw a cell if there is a 1 at this position.
	//else draw a empty block.
	if(field[position])
	{
		writeCell();
	}
	else
	{
		writeBlock();
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
	//randomly generate a playing field.
	//createRandomField(field);
	//put a pattern we created onto the field.
	insert_field(stable, field);
	
	//set contrast.
	lcd.setContrast(20);
	//make sure to start at location 0,0
	lcd.setCursor(0,0);
	
	//position is field size, I refresh the screen Backwards.
	position = fieldSize;
	while(position--)
	{
		//display field with current position
		showField(field, position);
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
		switch_back_buffer(field, buffer);
		//position keeps position in the field array,
		//and at the same time drawing location on
		//screen.
		if(position == 0)
		{
			//reset position to 0
			position = fieldSize;
			//set delay with a potmeter aka frame rate :)
			//could be done with a adc Interrupt ?
			//and set value that way?
			
			//if(adc_read(1)>100)
			//{
			//	delay(adc_read(1)/2);
			//}
			delay(200);
			//check wether we are in a steady state or just still evolving.
			currentState = checkField(field);
			//change field if field the same a while, or iterations goes above a certain number which meens it's probaly in a loop
			if(changeCount == holdingNumber || iterations > 1000)
			{
				//reset changeCount
				changeCount = 0;
				//reset iteration count.
				iterations = 0;
				//create a random playing field.
				createRandomField(field);
				//put a pattern we created onto the field.
				//insert_field(stable, field);
				
				//is blocking button won't work because it blocks interrupts,
				//and it will then also not be able to listen to button.
				delay(2000);
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
