#include "uart.h"

void uart_init(void)
{
	/* set the baud rate*/
	UBRRH = 0x00;//(unsigned char)(MY_UBRR>>8);
	UBRRL = 0x00;//(unsigned char)(MY_UBRR);
	/*enable recieving and transmitting*/
	UCSRB = (1<<RXEN)|(1<<TXEN);
	/*frame format: 8data, 2stop */
	UCSRC = (1<<URSEL)|(1<<USBS)|(1<<UCSZ0)|(1<<UCSZ1);
	
	/*rx as input and tx as output*/
	DDRD |= (1<<PD1);
	DDRD &= ~(1<<PD0);
	
	/*enable intterupt on receive*/
	UCSRB |= (1<<RXCIE);
	sei();
}

void uart_put_str(volatile char *data)
{
	volatile char *temp = data;
	while(*temp)
	{
		uart_send(*temp);
		temp++;
	}
}

void uart_send(volatile char data)
{
	/*wait for empty transmit buffer*/
	while( !(UCSRA&(1<<UDRE)) );
	
	/*put data into buffer, sends the data*/
	UDR = data;
}

unsigned char uart_receive(void)
{
	/*wait for data to be received*/
	while( !(UCSRA&(1<<RXC)) );
	
	/*get and return the received data from buffer*/
	return UDR;
}

ISR(USART_RXC_vect)
{
	uart_data[uart_data_index++] = uart_receive();
	if(uart_data_index > UART_BUFFER_SIZE)
	{
		uart_data_index = 0;
	}
}
