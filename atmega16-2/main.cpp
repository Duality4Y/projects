//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>
#include <stdio.h>
#include "DmDisplay.h"

const uint8_t screenWidth =  100;
const uint8_t screenHeight = 40;
const uint8_t screenByteWidth = 100/8;
const uint8_t screenByteHeight = 40/8;
uint16_t screenSize = screenWidth*screenHeight;
uint8_t screenByteSize = screenSize/8;
char screenBuf[screenByteWidth][screenByteHeight];

DmDisplay lcd;

void setCol(int col)
{
	int high = col/16;
	int low = col%16;
	lcd.write(0x10+high, lcd.INSTRUCT);
	lcd.write(0x00+low, lcd.INSTRUCT);
}

void setCursor(uint8_t x, uint8_t y)
{
	lcd.setRow(y);
	setCol(x);
}

void writePixel(uint8_t x, uint8_t y)
{
	setCursor(x,y);
	lcd.write((1<<(y/8)), lcd.DATA);
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

int main(void)
{
	writePixel(0,0);
	writePixel(50,20);
	while(1)
	{
		
	}	
	return 0;
}
