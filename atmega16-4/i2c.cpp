#define F_CPU  8000000
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <util/twi.h>
#include "blink.cpp"

void init_TWI(void)
{
	//set SCL to 100khz
	TWSR = 0x00;
	TWBR = 0x0C;
	//enable two wire
	TWCR = (1<<TWEN);
}

void TWI_start(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
}

void TWI_stop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
}

void write_TWI(uint8_t data)
{
	TWDR = data;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
}

uint8_t read_ack_TWI(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

uint8_t read_nack_TWI(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while((TWCR & (1<<TWINT)) == 0);
	return TWDR;
}

uint8_t get_status_TWI(void)
{
	return (TWSR & 0xF8);
}

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

void writeTWIbyte(uint8_t byte, uint8_t address)
{
	TWI_start();
	write_TWI(address);
	write_TWI(byte);
	TWI_stop();
}
uint8_t readTWIbyte(uint8_t address)
{
	uint8_t data = 0;
	TWI_start();
	write_TWI(address);
	write_TWI(0x00);
	TWI_start();
	write_TWI(0x01);
	data = read_nack_TWI();
	TWI_stop();
	return data;
}

int main(void)
{
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
	//led pin as output
	//DDRD |= (1<<PD7);
	//init the uart
	init_uart();
	//enable global interrupts
	sei();
	//enable uart recieve interupt.
	UCSRB |= (1<<RXCIE);
	
	//init two wire.
	init_TWI();
	//device address 0x06
	uint8_t ds1621_address = 0x07;
	
	writeTWIbyte(0xAA, ds1621_address);
	readTWIbyte(ds1621_address);
	
	while(1)
	{
	}
	return 1;
}

//ISR(USART_RXC_vect)
//{
	//uart_put(uart_getdata());
	//blink();
//}
