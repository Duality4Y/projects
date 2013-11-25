//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "DmDisplay.h"

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

//create a display instance
DmDisplay lcd;

#define fieldWidth 20
#define fieldHeight 6
#define fieldSize (fieldWidth*fieldHeight)
uint8_t field[fieldSize];

void writeLCDvalue(int contrastVal)
{
	char str[21];
	sprintf(str, " -> Contrast: %d    ", contrastVal);
	lcd.lcdChar(str);
}

void fillField(uint8_t *field)
{
	for(int i = 0;i<fieldSize;i++)
	{
		uint8_t randomVal = (adc_read(0)&0xF0);
		field[i] = (bool)randomVal;
	}
}

void showField(uint8_t *field)
{
	for(int y = 0;y<fieldHeight;y++)
	{
		for(int x = 0;x<fieldWidth;x++)
		{
			lcd.setCursor(x,y);
			if(field[x*y])
			{
				lcd.lcdChar("1");
			}
			else
			{
				lcd.lcdChar(" ");
			}
		}
	}
}

int main(void)
{
	//init analog if needed
	init_analog();
	lcd.setContrast(20);
	while(1)
	{
		fillField(field);
		showField(field);
		//_delay_ms(20);
	}
	return 0;
}
