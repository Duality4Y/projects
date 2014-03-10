/*
 * Safev0.c
 *
 * 	Created: 5-3-2014 11:22:45
 *  Co-Authors: 
 * 	Darrel
 * 	Robert
 */ 

#define F_CPU 1000000UL
#include <avr/io.h>
#include <avr/interrupt.h>

#define pin5v PIND6
#define pinLatch PINB0
#define pinClock PINB1
#define pinData PINB2

#define pinEncoder0 PIND2
#define pinEncoder1 PIND3
#define pinEncoderButton PIND4

#define rotSens 3

void refreshDisplay();
void groundAll();
void resetPins();
void updateEncoder();
void changed();

uint8_t sleepMode;
int lastButtonState;
int num[4];

volatile int lastEncoded;
volatile uint8_t dir = 0;
volatile uint8_t lastDir = 0;
volatile uint8_t sensDir =3;
volatile const uint8_t sensCDir =3;
volatile uint8_t sens;
int main(void)
{	
	//initialize interrupts
	DDRD &= ~(1<<PIND2) &~(1<<PIND3); //make pin 2 & 3 an input
	PORTD |= (1<<PIND2) |(1<<PIND3); //pull-up pin 2 & 3
	
	EICRA |= (1<<ISC10) |(1<<ISC00); //Set interrupt on any logic change
	EIMSK |= (1<<INT0) |(1<<INT1); //Turn on INT0 and INT1
	sei();
	//end initialize interrupts
	
	DDRD |= 1<<pin5v;
	DDRD &= ~(1<<pinEncoder0) &~(1<<pinEncoder1) &~(1<<pinEncoderButton);
	
	PORTD &= ~(1<<pin5v);
	PORTD |= (1<<pinEncoder0) |(1<<pinEncoder1) |(1<<pinEncoderButton); //pull-up input pins
	//PORTD |= (1<<pinEncoderButton); //pull-up input pins
	
	DDRB |= 1<<pinLatch |1<<pinClock |1<<pinData;
	PORTB |= 0b00000000;
	
	num[0] = 2;
	num[1] = 1;
	num[2] = 9;
	num[3] = 3;
	
    while(1)
    {
		if (sleepMode==0) {
			refreshDisplay();			
		}
		if (bit_is_clear(PIND, pinEncoderButton)) {
			if (lastButtonState!=1) {
				if (sleepMode) {
					sleepMode = 0;	
					resetPins();				
				} else {
					sleepMode = 1;
					groundAll();
				}
			}
			lastButtonState = 1;
		} else {
			lastButtonState = 0;
		}
		
		
    }
}
void groundAll() {
	PORTD |= 1<<pin5v;
	PORTB &= ~(1<<pinLatch);
	PORTB &= ~(1<<pinClock);
	PORTB &= ~(1<<pinData);	
}
void resetPins() {
	PORTD &= ~(1<<pin5v);	
}
void refreshDisplay() {
	int i, j;
	for (i=0;i<4;i++) {
		PORTB &= ~(1<<pinLatch); //turn latch pin LOW
		
		for (j=0;j<4;j++) {
			if (i==j) {
				PORTB &= ~(1<<pinData);
				} else {
				PORTB |= 1<<pinData;
			}
			PORTB |= 1<<pinClock; //turn clock pin HIGH
			PORTB &= ~(1<<pinClock); //turn clock pin LOW
		}
		for (j=0;j<4;j++) {
			if ((num[i] & 1<<(3-j))==0) {
				PORTB &= ~(1<<pinData);
				} else {
				PORTB |= 1<<pinData;
			}
			PORTB |= 1<<pinClock; //turn clock pin HIGH
			PORTB &= ~(1<<pinClock); //turn clock pin LOW
		}
		PORTB |= 1<<pinLatch; //turn latch pin HIGH
	}	
}

ISR(INT0_vect) {
	updateEncoder();
	refreshDisplay();
}
ISR(INT1_vect) {
	updateEncoder();
	refreshDisplay();
}

void updateEncoder() {
	int MSB = bit_is_clear(PIND, pinEncoder0); //MSB = most significant bit
	int LSB = bit_is_clear(PIND, pinEncoder1); //LSB = least significant bit

	int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
	int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

	if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
		if (dir ==1) {
			//changeEncoded = 1;
			
			sensDir=sensCDir;
			// Serial.println("0RIGHT");
		} else if (sensDir==0) {
			dir=1;
			sensDir=sensCDir;
			//     Serial.println("1RIGHT");
		} else {
			sensDir--;
		}
	} else if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
		if (dir==2) {
			//changeEncoded = 1;
			sensDir=sensCDir;
			//    Serial.println("0LEFT");
		} else if (sensDir==0) {
			dir=2;
			sensDir=sensCDir;
			//   Serial.println("1LEFT");
		} else {
			sensDir--;
		}
	} else {
		lastEncoded = encoded; //store this value for next time
		return; // return, no change will be made to the numbers
	}
	if (sens<=0) {
		sens = rotSens;
		} else if (sens==rotSens) {
		sens--;
		if (num[0]>=9) {
			num[0] = 0;
		} else {
			num[0]++;
		}	
	} else {
		sens--;
		if(lastDir!=dir)
		{
			if(lastDir!=0)
			{
				if(currNum == 3)
				{
					currentNum = 0;
				}
				else
				{
					currentNum++;
				}
			}
			lastDir = dir;
		}
		if(num[currNum] >= 9)
		{
			num[currNum] = 0;
		}
		else
		{
			num[currNum]++;
		}
	}
	else
	{
		sens--;
	}
	
	lastEncoded = encoded; //store this value for next time
}
