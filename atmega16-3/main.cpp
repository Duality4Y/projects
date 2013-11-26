//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>
#include "DmDisplay.h"

//variables and stuff
int x,y = 0;
//create a display instance
DmDisplay lcd;

#define surviveAbility 2
#define reproductiveNumber 3

#define fieldWidth 20
#define fieldHeight 5
#define fieldSize (fieldWidth*fieldHeight)
uint8_t field[fieldSize];
#include "life.cpp"
//-------------------

void init_analog(void)
{
	//select 5v analog reference.
	ADMUX = (1<<REFS0);
	ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
	//enable adc and use a prescaler of 128
}

uint16_t adc_read(uint8_t ch)
{
	ch &= 0x07; //keep value between 0 and 7;
	ADMUX = (ADMUX & 0xF8)|ch; //clear first 3 bits before ORring
	//start conversion
	ADCSRA |= (1<<ADSC);
	
	//wait for it to complete.
	while(ADCSRA & (1<<ADSC));
	return (ADC);
}
void writeFormated(const char *aString)
{
	lcd.lcdChar(aString);
}
void writeFormated(int val, const char *aString)
{
	char str[21];
	sprintf(str, "%s: %d   ", aString, val);
	lcd.lcdChar(str);
}

void writePixelData(uint8_t data)
{
	lcd.write(data, lcd.DATA);
}

void fillField(uint8_t *field, int position)
{
	uint16_t randomVal = rand()%2;
	field[position] = (bool)randomVal;
}
void writeBlack5x7Block(void)
{
	writePixelData(0xFF);
	writePixelData(0x81);
	writePixelData(0x81);
	writePixelData(0x81);
	writePixelData(0xFF);
}

void writeBlock(void)
{
	for(int i = 0;i<5;i++)
	{
		lcd.write(0x00, lcd.DATA);
	}
}

void showField(uint8_t *field, int position)
{
	x = position%fieldWidth;
	if(!(position%fieldWidth))
	{
		y++;
		if(y>(fieldHeight-1))
		{
			y=0;
		}
	}
	lcd.setCursor(x,y);
	if(field[position])
	{
		writeBlack5x7Block();
	}
	else
	{
		writeBlock();
	}
}
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
int main(void)
{
	//init analog if needed
	init_analog();
	srand(adc_read(0));
	
	//pin 0 on portb output
	DDRB |= _BV(PB0);
	//pin 2 on portb input
	DDRB &= ~(_BV(PB2));
	//turn on interupt on int2
	GICR |= (1<<INT2);
	SREG |= (1<<7);
	//trigger on rising edge
	MCUCSR |= (1<<ISC2);
	sei();
	
	for(int i = 0;i<fieldSize;i++)
		fillField(field, i);
	lcd.setContrast(16);
	lcd.setCursor(0,0);
	
	int position = fieldSize;
	while(1)
	{
		showField(field, position);
		if(field[position])
		{
			if(totalAround(field, position)==surviveAbility)
			{
				field[position]=1;
			}
			else if(totalAround(field, position)==surviveAbility+1)
			{
				field[position]=1;
			}
			else
			{
				field[position]=0;
			}
		}
		else
		{
			if(totalAround(field, position)==reproductiveNumber)
			{
				field[position]=1;
			}
		}
		position--;
		if(position == 0)
		{
			position = fieldSize;
			//set location and nicely print something.
			lcd.setCursor(0,5);
			writeFormated("Game of Life");
			//set delay with a potmeter aka frame rate :)
			delay(adc_read(1));	
			//read out pin 6, write pin 7a with state pin 6a
			//lets see if we can do this with an interupt 0.o :)
			/*if(PINB & (1<<PB1))
			{
				for(int i = 0;i<fieldSize;i++)
					fillField(field, i);
				while(PINB & (1<<PB1))
					PORTB |= (1<<PB0);
				PORTB &= ~(1<<PB0);
			}*/
		}
		if(PINB & (1<<PB2))
		{
			PORTB |= (1<<PB0);
		}
		else
		{
			PORTB &= ~(1<<PB0);
		}
	}
	return 0;
}

//our pin change interrupt.
ISR(INT2_vect)
{
	//PORTB |= (1<<PB0);
	for(int i = 0;i<fieldSize;i++)
		fillField(field, i);
	//dit is blocking
	//while(PINB & (1<<PB2));
	//PORTB &= ~(1<<PB0);
}
