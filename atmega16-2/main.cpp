//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <stdlib.h>
#include <stdio.h>
#include "DmDisplay.h"

//for string representation of binary numbers;

char string[21];

DmDisplay lcd;

void writePixel(uint8_t x, uint8_t y)
{
}

void writeLCDcontrast(int contrastVal)
{
	char str[21];
	sprintf(str, " -> Contrast: %d    ", contrastVal);
	lcd.lcdChar(str);
}
void writeSomeTestText()//DmDisplay display)
{
	lcd.setRow(0);
	lcd.lcdChar("012345678901234567890");
	lcd.setRow(1);
	lcd.lcdChar("ABCDEFGHIJKLMNPQRSTUV");
	lcd.setRow(2);
	lcd.lcdChar("wxyzabcdefghijklmnopq");
	lcd.setRow(3);
	lcd.lcdChar("  !#$%&'( )@^-");
	lcd.setRow(4);
	lcd.lcdChar("  *+-/<>?;:[]");
	lcd.setRow(5);
	lcd.lcdChar("* AVR rules !! *");
}

char *numbToBin(uint8_t number)
{
	itoa(number, string, 2);
	return string;
}
//this is for debugging with sprintf which needs a buffer;
//char formatedText[21];

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
int main(void)
{
	init_analog();
	lcd.setCursor(0,0);
	lcd.setContrast(18);
	DDRA |= (1<<PC1);
	while(1)
	{
		int analogValue = adc_read(0);
		writeLCDcontrast((analogValue*31)/1023);
		lcd.setContrast((analogValue*31)/1023);
		if(analogValue > 900)
		{
			PORTA |= (1<<PC1);
		}
		else
		{
			PORTA &= ~(1<<PC1);
		}
		//_delay_ms(500);
	}
	return 0;
}
