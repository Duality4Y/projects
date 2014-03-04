#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

#define ser_clock (1<<PB1)
#define reg_clock (1<<PB2)
#define ser_in	  (1<<PB3)


//shifts a byte out.
void shiftOut(unsigned long data){
	PORTB &= ~(1<<reg_clock);
	int i = 7;
	while(i--)
	{
		PORTB &= ~(1<<ser_clock);
		PORTB |= ((data >> i) & 1) << PB3;
		PORTB |= (1<< ser_clock);
	}
	PORTB |= (1<< reg_clock);
}

int main(void)
{
	/*
	 * PB1 = serial clock
	 * PB2 = register clock
	 * PB3 = serial in
	 * */
	enum 
	{
		a,b,c,d,e,f,g //these symbolize the pin outs on the 7 segment display
	};
	uint8_t one = 0xFF;
	//set shift pins to output
	DDRB = 0xFF;
	//clear port
	PORTB = 0xFF;
	while(1)
	{
		shiftOut(0xF0);
	}
	return 1;
}
