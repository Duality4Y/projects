//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>
#include <stdio.h>
#include "DmDisplay.h"

#define abs(x, y) 		((x>y) ?  (x-y) : (y-x))
#define swap(a, b) 		do{a = a+b;b = a - b;a = a-b;}while(0);

DmDisplay lcd;

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

//toggles Enable
void toggleEnable(void)
{
	SET_ENABLE;
	_delay_us(10);
	CLEAR_ENABLE;
	_delay_us(10);
	SET_ENABLE;
}
//reads pixel data at x,y
uint8_t read(uint8_t x, uint8_t y)
{
	uint8_t data = 0;
	
	//enter read modify write.
	lcd.write(0xE0, lcd.INSTRUCT);
	
	//set port to input.
	DATAPORT_TO_INPUT;
	//clear input port to be sure.
	DATA_INPUT = 0;
	//set apropriate controlle lines. 
	SET_RW;
	SET_A0;
	//toggle enable twice. dummy read+actuall read.
	toggleEnable();
	_delay_us(10);
	toggleEnable();
	_delay_us(10);
	//read in the data.
	data = DATA_INPUT;
	//set the port back to output.
	DATAPORT_TO_OUTPUT;
	//write back data we read (datasheet dummy-read -> read -> write. (read modify write)).
	lcd.write(data, lcd.DATA);
	//leave read modify write.
	lcd.write(0xEE, lcd.INSTRUCT);
	return data;
}

//write a pixel.
void writePixel(uint8_t x, uint8_t y)
{
	//for holding existing pixel data.
	uint8_t pixelData = 0;
	//boundery check. if bigger then screen size
	uint8_t y_temp = 0;
	if(y/8 > 6)
	{
			y_temp = 6;
	}
	else
	{
			y_temp = y/8;
	}
	//set read/write location.
	//also read pixel data in so we can OR it with the already existing data.
	lcd.setWriteReadAddres(x, y_temp);
	pixelData = read(x, y_temp);
	
	//determine what pixel in the pixel column to set.
	uint8_t pixelByteCol = (1<<(y%8));
	//write data and or it with what was already there.
	lcd.write(pixelByteCol|pixelData, lcd.DATA);
	//reset adress to 0,0
	//lcd.resetColumnAdress();
	//lcd.resetRowAdress();
}

void clearMarkers(void)
{
	for(int i = 0;i<7;i++)
		lcd.setMarker(i, 0);
}

void writeLCDcontrast(int contrastVal)
{
	char str[21];
	sprintf(str, "value: %d", contrastVal);
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

//draws a line.
//based on this line drawing function:
//https://code.google.com/p/glcd-arduino/downloads/detail?name=glcd-v3-20111205.zip&can=2&q=
//which source says its actually based on:
//http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
	uint8_t deltax, deltay, x,y, steep;
	int8_t error, ystep;
	
	steep = abs(y1, y2) > abs(x1 ,x2);  

	if (steep)
	{
		swap(x1, y1);
		swap(x2, y2);
	}

	if (x1 > x2)
	{
		swap(x1, x2);
		swap(y1, y2);
	}

	deltax = x2 - x1;
	deltay = abs(y2, y1);  
	error = deltax / 2;
	y = y1;
	if(y1 < y2) ystep = 1;  else ystep = -1;

	for(x = x1; x <= x2; x++)
	{
		if (steep) writePixel(y,x); else writePixel(x,y);
   		error = error - deltay;
		if (error < 0)
		{
			y = y + ystep;
			error = error + deltax;
    	}
	}
}

void drawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
	
}

int main(void)
{
	lcd.clear();
	while(1)
	{
		lcd.home();
		lcd.setContrast(15);
		drawLine(0,0, 100, 47);
		
		drawLine(0,  0,  0,  47);
		drawLine(0,  0,  99, 0);
		drawLine(99, 0,  99, 47);
		drawLine(0,  47, 99, 47);
	}
	return 0;
}
