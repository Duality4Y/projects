/* 
 * author:
 * Robert
 * 
 * Edited for use with a atmega168 original:
 * https://github.com/Duality4Y/projects/blob/master/atmega16-4/serial_commanding.cpp
 * for use with a atmega16
 * */
#include <avr/io.h>

#define BAUD	4800 //baud rate
#define UBRR	((F_CPU/BAUD/16)-1)

#define BUFFERSIZE 20
volatile serial_available = 0;
volatile uint8_t uart_buffIndex = 0;
volatile unsigned char uart_buffer[BUFFERSIZE];

void init_uart()
{
	//init serial.
	//status regB enable receive and transmit
	UCSR0B |= (1<<RXEN0)|(1<<TXEN0);
	
	//high byte (baud rate)
	UBRR0H = UBRR>>8;
	//low byte (baud rate)
	UBRR0L = UBRR;
	
	//format 8data 1 stop bit
	UCSR0C |= (3<<UCSZ00);
	
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
	//enable uart recieve interupt.
	UCSR0B |= (1<<RXCIE0);
	//enable global interrupts
	sei();
}
//function for transmitting a character on serial.
void uart_put(unsigned char data)
{
	//make certain that there is no data in UDR0
	while ( !( UCSR0A & (1<<UDRE0)) );
	//transmit data 
	UDR0 = data;
}
//function for transmitting a string over serial (must be null terminated)
void uart_put_str(volatile char *str)
{
	//while characters in string, transmit character.
	while(*str)
	{
		uart_put(*str++);
	}
	
}
//function for recieving data.
unsigned char uart_getdata(void)
{
	//make sure that UDR is empty
	while ( !(UCSR0A & (1<<RXC0)) );
	//return recieved data
	return UDR0;
}

void uart_clear()
{
	uart_buffIndex = 0;
	int i = 0;
	for(i = 0;i<BUFFERSIZE;i++)
		uart_buffer[i] = '\0';
}

ISR(USART_RX_vect)
{
	unsigned char data = uart_getdata();
	if(uart_buffIndex == BUFFERSIZE-1)
	{
		uart_buffIndex = 0;
		uart_buffer[uart_buffIndex] = '\0';
	}
	uart_buffer[uart_buffIndex++] = data;
	uart_buffer[uart_buffIndex] = '\0';
	serial_available = 1;
	//for testing if serial data was recieved.
	//blink();
}
