#define F_CPU  8000000
#include <avr/io.h>
#include <util/delay.h>

void init_uart()
{
	//init serial.
	//status regB enable receive and transmit
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	//high byte (baud rate)
	UBRRH = 0x00;
	//low byte (baud rate)
	UBRRL = 0x33;
}

void uart_put(unsigned char data)
{
	//while data bit set wait
	while((UCSRA&0x20)==0x00);
	//transmit data 
	UDR = data;
}

unsigned char uart_getdata(void)
{
	while((UCSRA&0x80)==0x00);
	return UDR;
}
int main(void)
{
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
	init_uart();
	unsigned char uart_byte = 0;
	while(1)
	{
		uart_byte = uart_getdata();
		if(uart_byte)
		{
			uart_put('@');
			uart_put(uart_byte);
		}
		_delay_ms(1000);
	}
	
	return 1;
}
