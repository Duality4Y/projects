#ifndef PINDEFS_H
#define PINDEFS_H

//pin defines.
#include <avr/io.h>
/*
 * note:
 * black wire is CE  (Chip Enable aka clock)
 * brown wire is OE  (Output Enable)
 * yellow wire is WE (Write Enable)
 * 
 * address ports are:
 * PORTB and PORTC
 * PORTB is MSB
 * PORTC is LSB
 * */
 
//controle line port defines.
#define CE_PIN					PD7
#define WE_PIN					PD5
#define OE_PIN					PD6

#define CE_PORT 				PORTD
#define WE_PORT					PORTD
#define OE_PORT					PORTD

#define CE_DDR					DDRD
#define WE_DDR					DDRD
#define OE_DDR					DDRD

//defines for controling the controle lines.
#define CLEAR_OE 				(OE_PORT &= ~OE_PIN);
#define SET_OE   				(OE_PORT |= OE_PIN);

#define CLEAR_WE  				(WE_PORT &= ~WE_PIN);
#define SET_WE    				(WE_PORT |= WE_PIN);

#define CLEAR_CE				(CE_PORT &= ~CE_PIN);
#define SET_CE					(CE_PORT |= CE_PIN);

//set controle pins to output.
#define SET_WE_OUTPUT 			(WE_DDR |= WE_PIN);
#define SET_CE_OUTPUT 			(CE_DDR |= CE_PIN);
#define SET_OE_OUTPUT			(OE_DDR |= OE_PIN);

//set controle pins to input (though might not be needed just for good measure)
#define SET_WE_INPUT			(WE_DDR &= ~(WE_PIN));
#define SET_CE_INPUT			(CE_DDR &= ~(CE_PIN));
#define SET_OE_INPUT			(OE_DDR &= ~(OE_PIN));

//defines for ports.
#define DATA_PORT 				PORTC
#define ADDRESS_PORT_UPPER 		PORTB
#define ADDRESS_PORT_LOWER		PORTA

#define DATA_IN					PINC
#define ADDRESS_IN_UPPER		PINB
#define ADDRESS_IN_LOWER		PINA

#define DATA_DDR				DDRC
#define ADDRESS_UPPER_DDR		DDRB
#define ADDRESS_LOWER_DDR		DDRA

//setting port modes like input and output
#define SET_DATA_INPUT			(DATA_DDR = 0x00);
#define SET_DATA_OUTPUT			(DATA_DDR = 0xFF);

#define SET_ADDRESS_INPUT		(ADDRESS_UPPER_DDR = 0x00);(ADDRESS_LOWER_DDR = 0x00);
#define SET_ADDRESS_OUTPUT		(ADDRESS_UPPER_DDR = 0xFF);(ADDRESS_LOWER_DDR = 0xFF);
#endif
