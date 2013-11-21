#include "DmDisplay.h"

DmDisplay::DmDisplay()
{
	FUNCTIONPORT_TO_OUTPUT;
	DATAPORT_TO_OUTPUT;
	
	CLEAR_POWER;
	_delay_ms(100);
	SET_POWER;
	_delay_ms(100);
	init();
	_delay_ms(100);
}

void DmDisplay::init()
{
	write(0xE2, INSTRUCT);
	_delay_ms(1000);
	write(0xA1, INSTRUCT);
	write(0xA2, INSTRUCT);
	write(0x2C, INSTRUCT);
	write(0x2E, INSTRUCT);
	write(0x2F, INSTRUCT);
	write(0xA6, INSTRUCT);
	write(0x8F, INSTRUCT);
	write(0xA4, INSTRUCT);
	write(0xAF, INSTRUCT);
	write(0x40, INSTRUCT);
}

//type = wheter it's instruction/command or data.
void DmDisplay::write(uint8_t data, int type)
{
	DATA_PORT &= 0x00;
	if(type == DATA)
	{
		CLEAR_RW;
		SET_A0;
		
		DATA_PORT = data;
		
		SET_ENABLE;
		_delay_us(10);
		CLEAR_ENABLE;
		_delay_us(10);
		SET_ENABLE;
	}
	else if(type == INSTRUCT)
	{
		CLEAR_RW;
		CLEAR_A0;
		
		DATA_PORT = data;
		
		SET_ENABLE;
		_delay_us(10);
		CLEAR_ENABLE;
		_delay_us(10);
		SET_ENABLE;
	}
}
void DmDisplay::setContrast(uint8_t contrast)
{
	write(0x80+contrast, INSTRUCT);
}

void DmDisplay::setMarker(uint8_t marker, bool state)
{
	uint8_t heighNibble, lowNibble;
	uint8_t lcd_marker = 0;
	
	switch(marker)
	{
		case 1:
			lcd_marker = 20;
			break;
		case 2:
			lcd_marker = 31;
			break;
		case 3:
			lcd_marker = 32;
			break;
		case 4:
			lcd_marker = 57;
			break;
		case 5:
			lcd_marker = 69;
			break;
		case 6:
			lcd_marker = 78;
			break;
	}
	
	lowNibble = lcd_marker & 0xF;
	heighNibble = lcd_marker;
	heighNibble = (heighNibble >> 4);
	heighNibble |= 0x10;
	
	write(0xB6, INSTRUCT);
	write(heighNibble, INSTRUCT);
	write(lowNibble, INSTRUCT);
	
	write((state?1:0), DATA);
}

void DmDisplay::invertDisplay(bool reverse)
{
	write(0xA6+(!reverse), INSTRUCT);
}

void DmDisplay::setRow(uint8_t row)
{
	uint8_t page = 0xB0 + (row-1);
	
	write(page, INSTRUCT);
	write(0x10, INSTRUCT);
	write(0x00, INSTRUCT);
	
	lcdChar("                    ");
	
	write(page, INSTRUCT);
	write(0x10, INSTRUCT);
	write(0x00, INSTRUCT);
}

void DmDisplay::lcdChar(const char *str)
{
	int charCount = strlen(str);
	
	//if there are more chars then 
	//there is room on a line.
	if(charCount > 20)
	{
		charCount = 20;
	}
	
	//start read-modify-write
	write(0xE0, INSTRUCT);
	for(int i = 0;i<charCount;i++)
	{
		uint8_t currentChar = str[i];
		uint8_t lcd_char = currentChar-32;
		for(uint8_t byte = 0;byte<5;byte++)
		{
			write(Font[lcd_char][byte], DATA);
		}
	}
	//end of read-modify-write
	write(0xEE, INSTRUCT);
	//reset column address
	resetColumnAdress();
}

void DmDisplay::resetColumnAdress()
{
	write(0x10, INSTRUCT);
	write(0x00, INSTRUCT);
}

//for testing purposes
void DmDisplay::blinkControlLines()
{
	SET_A0;
	SET_ENABLE;
	SET_RW;
	_delay_ms(250);
	CLEAR_A0;
	CLEAR_ENABLE;
	CLEAR_RW;
	_delay_ms(250);
}
