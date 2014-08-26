#define F_CPU 20000000
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	DDRC=0xFF;            // set portA as out put
	while(1)                     // run forever
	{
		PORTC = ~(PORTC);
	}
	return(0);
}
