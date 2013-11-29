#define F_CPU  8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#include "blink.cpp"

#define BUFFERSIZE 20
volatile int string_index = 0;
char buffer[BUFFERSIZE];

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
	while((UCSRA&0x20)==0x00);
	//transmit data 
	UDR = data;
}

unsigned char uart_getdata(void)
{
	while((UCSRA&0x80)==0x00);
	//return recieved data
	return UDR;
}
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
		//set zero to get new commands?
		//string_index = 0;
		
		if(!strcmp(buffer, "led"))
		{
			PORTD |= (1<<PD7);
		}
		else
		{
			PORTD &= ~(1<<PD7);
		}
		
		int index = 0;
		while(buffer[index] != '\0')
		{
			uart_put(buffer[index]);
			index++;
		}
		uart_put('\n');
	}
	
	return 1;
}

ISR(USART_RXC_vect)
{
	unsigned char data = uart_getdata();
	if(string_index == BUFFERSIZE-1)
	{
		string_index = 0;
		buffer[string_index] = '\0';
	}
	buffer[string_index++] = data;
	buffer[string_index] = '\0';
	
	//blink();
}
