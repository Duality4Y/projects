//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <math.h>
#include <stdlib.h>
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
//reads pixel data, on location set by setWriteReadAdress.
uint8_t read()
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
	//if((y/8) >= 6)
	//{
		//return;
	//	y_temp = 6;
	//}
	//else
	//{
	//	y_temp = y/8;
	//}
	if((x >= 100)||(y >= 48))
		return;
	if((x < 0) || (y < 0))
		return;
	//set read/write location.
	//also read pixel data in so we can OR it with the already existing data.
	lcd.setWriteReadAddres(x, y/8);
	pixelData = read();
	
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

//draws a line.
//based on this line drawing function:
//https://code.google.com/p/glcd-arduino/downloads/detail?name=glcd-v3-20111205.zip&can=2&q=
//which source says its actually based on:
//http://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
void drawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2)
{
	int deltax, deltay, x,y, steep;
	int error, ystep;
	
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
//drawing a rectangle
void drawRect(uint8_t x, uint8_t y, uint8_t width, uint8_t height)
{
	//upper x line.
	drawLine(x,y, x+width, y);
	//lower x line.
	drawLine(x, y+height, x+width, y+height);
	//left y line.
	drawLine(x,y, x, y+height);
	//right y line.
	drawLine(x+width,y, x+width, y+height);
}
//implementation of bresenham's circle
void drawCircle(uint8_t x0, uint8_t y0, uint8_t radius)
{
	int error = 1 - radius;
	int errorY = 1;
	int errorX = -2 * radius;
	int x = radius, y = 0;
	
	writePixel(x0, y0 + radius);
	writePixel(x0, y0 - radius);
	writePixel(x0 + radius, y0);
	writePixel(x0 - radius, y0);
	
	while(y< x)
	{
		if(error > 0)
		{
			x--;
			errorX += 2;
			error += errorX;
		}
		y++;
		errorY += 2;
		error += errorY;
		
		writePixel(x0 + x, y0 + y);
		writePixel(x0 - x, y0 + y);
		writePixel(x0 + x, y0 - y);
		writePixel(x0 - x, y0 - y);
		writePixel(x0 + y, y0 + x);
		writePixel(x0 - y, y0 + x);
		writePixel(x0 + y, y0 - x);
		writePixel(x0 - y, y0 - x);
	}
}

void drawArc(float x, float y, int r, float start_angle, float end_angle)
{
	// I know the question is tagged c++, but the idea comes clear in javascript
	
	float step = 0.1;
	for(float i = start_angle; i < end_angle; i = i + step)
	{
		float x0 = x+cos(i)*r; 
		float y0 = y+sin(i)*r;
		float x1 = x+cos(i+step)*r;
		float y1 = y+sin(i+step)*r;
		//writePixel(30 + cos(i) * r, 20 + sin(i) * r); // center point is (50,100)
		drawLine(x0, y0, x1, y1);
	}
}

int main(void)
{
	lcd.clear();
	lcd.invertDisplay(0);
	clearMarkers();
	lcd.setContrast(20);
	while(1)
	{
		//writeSomeTestText();
		//for(int i = 0;i<10;i++)
		//{
			//drawCircle(i,i,i*i);
			//drawLine(0,i*i,i*i,0);
			//drawRect(i*i,i*i,i*4,i*i);
		//}
		//drawRect(20,10,30,30);
		uint8_t x = rand()%100;
		uint8_t y = rand()%48;
		uint8_t size = rand()%100;
		while(size < 15) size = rand()%100;
		for(int i = 0;i<size;i++)
		{
			for(int wall = 10;wall>0;wall--)
			{
				drawCircle(x,y,i+wall);
			}
			lcd.clear();
		}
		//delay(1000);
	}
	return 0;
}
