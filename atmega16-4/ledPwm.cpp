#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "uart.cpp"


int main()
{
	//set led as output.
	DDRB |= (1<<PB0);
	//configure timer 1 for ctc mode.
	TIMSK |= (1<<OCIE1A); //enable ctc interrupt.
	sei(); //enable global interupts.
	TCCR1B |= (1<<WGM12); //ctc mode.
	TCCR1B |= (1<<CS10);//|(1<<CS11); //prescaler of 64.
	OCR1A = 15624;
	while(1)
	{
		_delay_ms(20);
	}
	return 0;
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1<<PB0);
}
