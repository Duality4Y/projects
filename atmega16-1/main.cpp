//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

//class Blink
//{
	//public:
		//Blink()
		//{
			////set everything on port a to output.
			//DDRA = 0xFF;
		//}
		//void blinkLed();
//};

//void Blink::blinkLed()
//{
	//PORTA |= (1<<0);
	//_delay_ms(250);
	//PORTA &= ~(1<<0);
	//_delay_ms(250);
//}

/*
 * using a atmega16
 * with a glcd, this display: http://tkkrlab.nl/wiki/Glcd_48x100
 * 
 * A0, Read/Write and Enable are 
 * connected to port D
 * 
 * A0 is connected to: PD6
 * R/W is connected to: PD5
 * Enable is connected to: PD4
 * */

/* Start of defines for easy line controle
 * 
 * This wil spare me a lot of typing :)
 * 
 * */
#define A0 					_BV(PD6)
#define RW 					_BV(PD5)
#define ENABLE 				_BV(PD4)

#define FUNCTIONPORT 		(PORTD)
#define FUNCTIONDIR 		(DDRD)
#define FUNCTION_TO_OUTPUT	(FUNCTIONDIR |=  (A0|RW|ENABLE))
#define FUNCTION_TO_INPUT 	(FUNCTIONDIR &= ~(A0|RW|ENABLE))

#define SET_A0 				(FUNCTIONPORT |= A0)
#define SET_RW 				(FUNCTIONPORT |= RW)
#define SET_ENABLE 			(FUNCTIONPORT |= ENABLE) 

#define CLEAR_A0			(FUNCTIONPORT &= ~(A0))
#define CLEAR_RW			(FUNCTIONPORT &= ~(RW))
#define CLEAR_ENABLE		(FUNCTIONPORT &= ~(ENABLE))

#define DATA_PORT 			(PORTC)
#define DATA_DIR 			(DDRC)
#define DATAPORT_TO_OUTPUT 	(DATA_DIRECTION = 0xFF)
#define DATAPORT_TO_INPUT	(DATA_DIRECTION = 0x00)

/* End of defines for easy use.*/

class DmDisplay
{
	public:
		DmDisplay();
		void blinkControlLines();
		enum
		{
			INSTRUCT,DATA
		};
		bool backLightState;
		void write(uint8_t, int);
};

DmDisplay::DmDisplay()
{
	backLightState = true;
	FUNCTION_TO_OUTPUT;
}
//type = wether it's instruction or data.
void DmDisplay::write(uint8_t data, int type)
{
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

int main(void)
{
	DmDisplay display;
	display.write(0x10,DATA);
	while(1)
	{
	}
	return 0;
}
