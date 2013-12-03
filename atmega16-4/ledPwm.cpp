#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include "uart.cpp"


int main()
{
	TCCR1B |= (1<<CS10)|(1<<CS11);
	DDRB |= (1<<PB0);
	while(1)
	{
		if(TCNT1 >= 65000)
		{
			PORTB ^= (1<<PB0);
			TCNT1 = 0;
		}
	}
	return 0;
}
