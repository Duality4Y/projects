#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>

#define ser_clock (1<<PB1)
#define reg_clock (1<<PB2)
#define ser_in	  (1<<PB3)


//shifts a byte out.
void shiftOut(uint8_t data){
	PORTB &= ~(1 << reg_clock); 				// Set the register-clock pin low
	int i;
	for (i = 0; i < (8); i++){	// Now we are entering the loop to shift out 8+ bits
		PORTB |= (1 << ser_clock); 			// Set the serial-clock pin high
		PORTB |= (((data&(0x01<<i))>>i) << ser_in ); 	// Go through each bit of data and output it
		PORTB &= ~(1 << ser_clock); 			// Set the serial-clock pin low
		PORTB &= ~(((data&(0x01<<i))>>i) << ser_in );	// Set the datapin low again	
	}
	PORTB |= (1 << reg_clock);
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
	PORTB = 0x00;
	while(1)
	{
		shiftOut(0x0F);
	}
	return 1;
}
