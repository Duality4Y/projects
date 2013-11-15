//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <stdio.h>
#include <stdlib.h>

class Blink
{
	public:
		Blink()
		{
			//set everything on port a to output.
			DDRA = 0xFF;
		}
		void blinkLed();
};

void Blink::blinkLed()
{
	PORTA |= (1<<0);
	_delay_ms(250);
	PORTA &= ~(1<<0);
	_delay_ms(250);
}

int main(void)
{
	Blink blink;
	while(1)
	{
		blink.blinkLed();
	}
	return 0;
}
