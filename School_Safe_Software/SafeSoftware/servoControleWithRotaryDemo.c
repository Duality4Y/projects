/*
 * Name: Darrel Griët
 * Project: Servo test on port D pin 3(PWM OC2B)
 * Date: March-8-2014
 */

#define F_CPU 1000000UL //This speed is used standard on the Arduino Nano v3.0

#include <avr/io.h>
#include <util/delay.h>
#include "libs/safeFunctions.c"

void stopPWM() {
	//turn of PWM / reset Timer1 register
	TCCR0A = 0;
	TCCR0B = 0;	
}

int main(void)
{

	// Set timer2 TOP=OCR2A clear on compare(COM2B1), and fast PWM(using WGM20, WGM21 and WGM22)
	// Set prescale to 1024(using CS20, CS21 and CS22)
	TCCR0A = (1<<COM0A1) |(1<<WGM01) | (1<<WGM00);     
	TCCR0B = (0<<WGM02) | (1<<CS00) |(1<<CS01) |(0<<CS02);
	DDRD |= (1<<PIND6); //output on OC1 pin (portb.1)
	//stopPWM();
	//while(1){} //Prevents the next loop from starting. Servos can sometimes be annoying
	initShifter();
	initPowerControle();
	initRotary();
	OCR0A = ticks = 19;
	while(1)
	{
		//The value's here a completely guess based, except the number 26, this is just
		// the average of 42 and 9 :)
		OCR0A = ticks; //set to 0 degrees
		displayNum(ticks);
		/*
		if(ticks>30)
			ticks = 30;
		if(ticks < 8)
			ticks = 8;
			* */
	}

} 
