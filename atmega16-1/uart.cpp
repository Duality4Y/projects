/*
 * baudrate found @:
 * http://www.wormfood.net/avrbaudcalc.php
 * */

void init_uart()
{
	//init serial.
	//(9600)
	//high byte (baud rate)
	UBRRH = 0x00;
	//low byte (baud rate)
	UBRRL = 0x0A;
	
	//status regB enable receive and transmit
	UCSRB = (1<<RXEN)|(1<<TXEN);
	// no parity, 8 bits data length, 1 stop bit.
	UCSRC = (1<<URSEL)|(1<<UCSZ0)|(1<<UCSZ1)|(0<<USBS); 
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
}

void uart_putdata(unsigned char data)
{
	while((UCSRA&0x20)==0x00);
	//transmit data 
	UDR = data;
}

void uart_put_str(const char *str)
{
	int i = 0;
	do
	{
		uart_putdata(str[i++]);
	}
	while(str[i]);
	
}

unsigned char uart_getdata(void)
{
	while((UCSRA&0x80)==0x00);
	//return recieved data
	return UDR;
}
