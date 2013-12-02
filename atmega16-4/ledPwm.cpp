#define F_CPU 8000000

#include <avr/io.h>

int main(void)
{
	//led on PD7, set as output.
	DDRD |= (1<<PD7);
	//set prescaler 1
	TCCR1B |= (1<<CS10)|(1<<CS11);
	while(1)
	{
		if(TCNT1 >= 15624)
		{
			PORTB ^= (1<<0);
			
			TCNT1 = 0;
		}
	}
	return 1;
}
