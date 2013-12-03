void init_uart()
{
	//init serial.
	//status regB enable receive and transmit
	UCSRB |= (1<<RXEN)|(1<<TXEN);
	//(9600)
	//high byte (baud rate)
	UBRRH = 0x00;
	//low byte (baud rate)
	UBRRL = 0x33;
	
	//set rx as input (PD0)
	DDRD &= ~(1<<PD0);
	//set tx as output (PD1)
	DDRD |= (1<<PD1);
	//enable global interrupts
	sei();
	//enable uart recieve interupt.
	UCSRB |= (1<<RXCIE);
}

void uart_put(unsigned char data)
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
		uart_put(str[i++]);
	}
	while(str[i]);
	
}

unsigned char uart_getdata(void)
{
	while((UCSRA&0x80)==0x00);
	//return recieved data
	return UDR;
}
