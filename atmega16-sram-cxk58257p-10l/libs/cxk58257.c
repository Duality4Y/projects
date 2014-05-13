#include "cxk58257.h"

void initSram()
{
	//initialialy put everything on high impedence
	//except controle lines put them to output.
	SET_DATA_INPUT
	SET_ADDRESS_OUTPUT
	
	//make the controle lines output
	SET_CE_OUTPUT
	SET_OE_OUTPUT
	SET_WE_OUTPUT
	//all controle lines are active low so put the pins high.
	SET_CE
	SET_OE
	SET_WE
}

void setAddress(unsigned int address)
{
	//address lines need to be output.
	SET_ADDRESS_OUTPUT
	//put out the address.
	ADDRESS_PORT_UPPER = (uint8_t)(address>>8);//last 8 bits
	ADDRESS_PORT_LOWER = (uint8_t)(address&0x00FF);
}

uint8_t read(unsigned int address)
{
	static uint8_t readByte = 0;
	setAddress(address);
	SET_DATA_INPUT
	SET_WE
	CLEAR_CE
	CLEAR_OE
	_delay_ms(10);
	readByte = DATA_IN;
	SET_OE
	SET_CE
	return readByte;
}

void write(unsigned int address, uint8_t data)
{
	setAddress(address);
	SET_DATA_OUTPUT
	SET_OE
	CLEAR_CE
	CLEAR_WE
	_delay_ms(10);
	DATA_PORT = data;
	SET_WE 
	SET_CE
}
