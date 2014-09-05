#define F_CPU 20000000
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "uart.cpp"
/*
 * WE = PD5
 * OE = PD4
 * CE = PD3
 * */

#define WE_PIN				(PD5)
#define OE_PIN				(PD4)
#define CE_PIN				(PD3)
#define PIN_DDR				(DDRD)
#define PIN_PORT			(PORTD)

#define CONTROLE_OUTPUT		(PIN_DDR |= (1<<WE_PIN)|(1<<OE_PIN)|(1<<CE_PIN))
/*
 * becasue the controle lines are active low,
 * well meen by setting a pin pulling it low.
 * and clearing a pin setting that pin high.
 * */
#define SET_WE				(PIN_PORT &= ~(1<<WE_PIN))
#define CLEAR_WE			(PIN_PORT |= (1<<WE_PIN))
#define SET_OE				(PIN_PORT &= ~(1<<OE_PIN))
#define CLEAR_OE			(PIN_PORT |= (1<<OE_PIN))
#define SET_CE				(PIN_PORT &= ~(1<<CE_PIN))
#define CLEAR_CE			(PIN_PORT |= (1<<CE_PIN))

#define DATA_BUS_DDR		(DDRB)
#define DATA_BUS_PORT		(PORTB)
#define DATA_BUS_DPIN		(PINB)

#define DATA_BUS_INPUT		(DDRB = 0x00)
#define DATA_BUS_OUTPUT		(DDRB = 0xFF)
#define DATA_BUS_WRITE(X)	(PORTB = X)
#define DATA_BUS_READ		PINB

#define ADDR_BUS_A_DDR		(DDRA)
#define ADDR_BUS_B_DDR		(DDRC)
#define ADDR_BUS_C_DDR		(DDRD)

#define ADDR_BUS_A_PORT		(PORTA)
#define ADDR_BUS_B_PORT		(PORTC)
#define ADDR_BUS_C_PORT		(PORTD)

#define ADDR_BUS_A_DPIN		(PINA)
#define ADDR_BUS_B_DPIN		(PINC)
#define ADDR_BUS_C_DPIN		(PIND)

/*
 * make seperate inputs outputs for A,B,C
 * like addr_bus_a_input
 * addr_bus_b_input
 * and so on for write output and read.
 * make functions to do the coversion/calculations for
 * what part of the data goes where.
 * */

#define ADDR_BUS_INPUT		(ADDR_BUS_A_DDR = ADDR_BUS_B_DDR = 0x00) (ADDR_BUS_C_DDR |= ( 1<<PD6)|( 1<<PD7));
#define ADDR_BUS_OUTPUT		(ADDR_BUS_A_DDR = ADDR_BUS_B_DDR = 0xFF) (ADDR_BUS_C_DDR &= ~( (1<<PD6)|(1<<PD7) ));

#define ADDR_BUS_WRITE(X)	(ADDR_BUS_A_PORT = (X&0xFF));(ADDR_BUS_B_PORT = (X&0xFF00));( ADDR_BUS_C_PORT = ( X&( ( 1<<PD6)|( 1<<PD7))));
#define ADDR_BUS_READ		(0x00 | (ADDR_BUS_A_DPIN) | (ADDR_BUS_B_DPIN<<8) | (ADDR_BUS_C_DPIN&( ( 1<<PD6)|( 1<<PD7))<<16) )

#define MANUFACTURER_ID

void init_flash_interface()
{
	DATA_BUS_INPUT;
	ADDR_BUS_INPUT;
	CONTROLE_OUTPUT;
	
	CLEAR_CE;
	CLEAR_OE;
	CLEAR_WE;
}

int main(void)
{
	init_uart();
	init_flash_interface();
	while(1)
	{
		unsigned long adder = 0;
		unsigned long limit = 0xFF;
		for(adder = 0;adder < limit;adder++)
		{
			DATA_BUS_INPUT;
			SET_CE;
			SET_OE;
			CLEAR_WE;
			ADDR_BUS_OUTPUT;
			ADDR_BUS_WRITE(adder);
			short readByte = DATA_BUS_READ;
			CLEAR_OE;
			CLEAR_CE;
			ADDR_BUS_INPUT;
			uart_putdata(readByte);
		}
		break;
	}
	return(0);
}
