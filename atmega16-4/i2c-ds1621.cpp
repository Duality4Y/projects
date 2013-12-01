#define F_CPU  8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#include "i2c.cpp"
#include "uart.cpp"
#include "blink.cpp"

int main(void)
{
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
	//led pin as output
	DDRD |= (1<<PD7);
	//init the uart
	init_uart();
	//enable global interrupts
	sei();
	//enable uart recieve interupt.
	UCSRB |= (1<<RXCIE);
	
	while(1)
	{
	}
	return 1;
}

ISR(USART_RXC_vect)
{
	uart_put(uart_getdata());
	blink();
}
