#define F_CPU 8000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "uart.cpp"

void set_pwm(uint8_t duty)
{
	OCR0 = duty;
}

int main(void)
{
	//fast pwm, prescaler 1024, non inverted pwm.
	//wgm is 
	//com is mode. in this case set to bottom on output compare.
	//cs is prescaler, none used (cs00);
	TCCR0 |= (1<<WGM00)|(1<<WGM01)|(1<<CS00)|(1<<COM01);
	//OC0 as output (PB3)
	DDRB |= (1<<PB3);
	init_uart();
	int i = 0;
	int dir = 1;
	while(1)
	{
		set_pwm(i);
		i += dir;
		if(i == 255 || i == 0)
			dir *= -1;
		uart_put(i);
		uart_put('\n');
	}
	main();
}
