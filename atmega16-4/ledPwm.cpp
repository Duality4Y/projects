#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.cpp"

char formated[21] = 0;

int main(void)
{
	DDRB |= (1<<PB0);
	//default baud I use is 9600
	init_uart();
	while(1)
	{
		
	}
}

ISR(TIMER1_OVF_vect)
{
	PORTB ^= (1<<PB0);
}

ISR(USART_RXC_vect)
{
}
