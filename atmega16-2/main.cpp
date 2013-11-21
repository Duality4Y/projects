//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "DmDisplay.h"

const uint8_t screenWidth =  100;
const uint8_t screenHeight = 40;
const uint8_t screenByteWidth = 100/8;
const uint8_t screenByteHeight = 40/8;
uint16_t screenSize = screenWidth*screenHeight;
uint8_t screenByteSize = screenSize/8;
char screenBuf[screenByteWidth][screenByteHeight];

//for string representation of binary numbers;

char string[21];

DmDisplay lcd;

void setPage(uint8_t col)
{
	
}

void setCol(uint8_t row)
{
	
}

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
	lcd.setRow(1);
	lcd.lcdChar("012345678901234567890");
	lcd.setRow(2);
	lcd.lcdChar("ABCDEFGHIJKLMNPQRSTUV");
	lcd.setRow(3);
	lcd.lcdChar("wxyzabcdefghijklmnopq");
	lcd.setRow(4);
	lcd.lcdChar("  !#$%&'( )@^-");
	lcd.setRow(5);
	lcd.lcdChar("  *+-/<>?;:[]");
	lcd.setRow(6);
	lcd.lcdChar("* AVR rules !! *");
}
void toggleDisplay(int state)
{
	int new_state = (0xAE + state);
	lcd.write(new_state, lcd.INSTRUCT);
}

char *numbToBin(uint8_t number)
{
	itoa(number, string, 2);
	return string;
}

int main(void)
{
	writePixel(0,0);
	writePixel(50,20);
	int col = 80;
	int com0 = 0x80;
	int higher = 0x0F;
	int lower = (col&0x0F)|com0;
	
	//lcd.write(higher, lcd.INSTRUCT);
	//lcd.write(lower, lcd.INSTRUCT);
	
	lcd.setRow(1);
	char formatedText[21];
	sprintf(formatedText, "higher: %s", numbToBin(higher));
	lcd.lcdChar(formatedText);
	//lcd.lcdChar("this is test text");
	while(1)
	{
	}
	return 0;
}
