#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include <stdio.h>

#include "uart.cpp"

char formated[21];
int main(void)
{
	DDRB |= 0xFF;
	//default baud I use is 9600
	init_uart();
	
	TCCR1B |= (1<<CS10);
	
	int pwmMax = 255;
	int pwmOn = 10;
	
	while(1)
	{
		if(TCNT1 > 0)
		{
			PORTB |= 0xFF;
		}
		else
		{
			PORTB |= 0xFF;
		}
		sprintf(formated, "OCR1A: %d TCNT1: %d \n", OCR1A, TCNT1);
		uart_put_str(formated);
	}
}

ISR(USART_RXC_vect)
{
}
