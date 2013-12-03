#define F_CPU 1000000

#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= (1<<PB0);
	TIMSK |= (1<<TOIE1);
	TCCR1B |= (1<<CS11);
	sei();
	while(1){}
}

ISR(TIMER1_OVF_vect)
{
	PORTB ^= (1<<PB0);
}
