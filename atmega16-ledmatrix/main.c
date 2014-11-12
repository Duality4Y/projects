#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "font.h"

volatile uint8_t offset = 0;

uint8_t image[] = 
{
	0b11111111,
	0b10000001,
	0b10000001,
	0b10000001,
	0b10000001,
	0b10000001,
	0b10000001,
	0b11100111,
};

static volatile char display_data = ' ';

void initMatrixDisplay(void)
{
	//pins and ports used for the display
	DDRD = 0xFF;
	DDRB = 0xFF;
	
	PORTD = 0x00;
	PORTB = 0x00;
	
	//use timer0 for generating a tick in which it display the thing for the display.
	TCCR0 = (1<<CS02)|(1<<CS00);
	TIMSK = (1<<TOIE0);
	sei();
}

void setPixel(uint8_t x, uint8_t y)
{
	PORTD = ~(1<<x);
	PORTB = (1<<y);
}

void displayImage(uint16_t *image)
{
	int i;
	for(i = 0;i<0x08;i++)
	{
		uint16_t data = image[i]<<7;
		PORTB = (data>>offset);
		PORTD = ~(1<<i);
		_delay_ms(2);
	}
}

void put_c(char character)
{
	uint16_t *temp_char = (font+(8*(character-32) ) );
	displayImage(temp_char);
}

const char name[] = "Martijn";

int main(void)
{
	initMatrixDisplay();
	while(1)
	{
		put_c(display_data);
	}
	return 0;
}

ISR(TIMER0_OVF_vect, ISR_BLOCK)
{
	static unsigned int i;
	static unsigned int isr_count;
	if( !(isr_count%30) )
	{
		offset = 0;
		if(name[i])
		{
			display_data = name[i];
			i++;
		}
		if(!name[i])
			i = 0;
	}
	if( !(isr_count%2) && (offset <= 0xF0))
	{
		offset++;
	}
	isr_count++;
}
