#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= (1<<0);
	TIMSK0 |= (1<<TOIE1);
	sei();
	TCNT1 = 49911;
	TCCR1B |- ((1<<CS10)|(1<<CS11));
	for(;;)
	{
	}
	return 0;
}

ISR(TIMER1_OVF_vect)
{
	PORTB ^= (1<<0);
	TCNT1 = 49911;
}
