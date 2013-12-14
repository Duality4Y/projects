//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>
#include <stdio.h>
#include "DmDisplay.h"

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
	//set to screen size.
	if(x > 100)
		x = 100;
	if(y > 48)
		y = 48;
	//set write location for pixel data
	//if y/8 > 8 that would meen we go of screen since only 48/8 6 big
	//we make it 6 big if bigger.
	//also read pixel data in so we can OR it with the already existing data.
	uint8_t y_temp = 0;
	if(y/8 > 6)
	{
		//lcd.setWriteReadAddres(x, 6);
		y_temp = 6;
	}
	else
	{
		//lcd.setWriteReadAddres(x, (y/8));
		y_temp = y/8;
	}
	
	//set right read/write address, and read pixel data.
	lcd.setWriteReadAddres(x, y_temp);
	pixelData = read(x, y_temp);
	
	//determine what pixel in the pixel column to set.
	uint8_t pixelByteCol = (1<<(y%8));
	//write data and or it with what was already there.
	lcd.write(pixelByteCol|pixelData, lcd.DATA);
	//reset adress to 0,0
	lcd.resetColumnAdress();
	lcd.resetRowAdress();
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

int main(void)
{
	uint8_t state = 0;
	while(1)
	{
		lcd.home();
		lcd.setContrast(15);
		//for(int x = 0;x<48;x++)
		//{
		//	writePixel(x,x);
		//}
		for(int x = 0;x<100;x++)
			writePixel(x, 0);
		for(int y = 0;y<48;y++)
			writePixel(0,y);
		for(int x = 0;x<100;x++)
			writePixel(x, 47);
		for(int y = 0;y<48;y++)
			writePixel(99,y);
		lcd.invertDisplay(state);
		_delay_ms(1000);
		state = ~state;
	}
	return 0;
}
