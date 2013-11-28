#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>



int main(void)
{
	DDRD |= 0xFF;
	PORTD |= 0xFF;
	while(1)
	{
		PORTD |= 0xFF;
		_delay_ms(1000);
		PORTD &= 0X00;
		_delay_ms(1000);
	}
	return 0;
}
