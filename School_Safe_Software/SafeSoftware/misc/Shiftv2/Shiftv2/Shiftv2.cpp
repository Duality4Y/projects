/*
 * Shiftv1.cpp
 *
 * Created: 27-2-2014 19:45:10
 *  Author: Darrel
 */ 
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
int num[4];
int main(void)
{
	DDRD |= 1<<PIND6;
	PORTD &= ~(1<<PIND6);
	DDRB |= 0b00000111;
	PORTB |= 0b00000000;
	
	num[0] = 2;
	num[1] = 1;
	num[2] = 9;
	num[3] = 3;
	
    while(1)
    {
		for (int i=0;i<4;i++) {
			PORTB &= ~(1<<PINB0); //turn latch pin LOW
			
			for (int j=0;j<4;j++) {
				if (i==j) {
					PORTB &= ~(1<<PINB2);					
				} else {
					PORTB |= 1<<PINB2;				
				}
				PORTB |= 1<<PINB1; //turn clock pin HIGH
				PORTB &= ~(1<<PINB1); //turn clock pin LOW
			}			
			for (int j=0;j<4;j++) {
				if ((num[i] & 1<<(3-j))==0) {
					PORTB &= ~(1<<PINB2);
					} else {
					PORTB |= 1<<PINB2;
				}
				PORTB |= 1<<PINB1; //turn clock pin HIGH
				PORTB &= ~(1<<PINB1); //turn clock pin LOW			
			}
			PORTB |= 1<<PINB0; //turn latch pin HIGH			
		}
		
		
			
    }
}