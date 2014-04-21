/*
 * a way of keeping track of time.
 * by darrel 
 * */
#include "safeFunctions.h"
//Time tracking related
volatile unsigned long time = 0; //Stores the time in fifth of seconds
volatile unsigned long timeinSeconds = 0; //stores the time in seconds
const uint8_t timeScale = 122;

void initTime()
{
	//setup to tick once a second.
	//TCCR0A |= (1<<WGM01); //ctc mode
	//TCCR0B |= (1<<CS00)|(1<<CS02); //set prescaler to 1024
	//TIMSK0 |= (1<<OCIE0A); //enable interupt on compare
	//OCR0A = 156;
	//sei(); //enable global interupts.
	
	//TCCR1A |= (1<<WGM12);
	TCCR1B |= (0<<CS12)|(0<<CS11)|(1<<CS10); //with a prescaler of 1024 the timer wil overflow 7812 times a second
	TIMSK1 |= (1<<TOIE1);
	//TIMSK1 |= (1<<OCIE1A);
	//OCR1A = 156;
	sei();
	
}

ISR(TIMER1_OVF_vect)
{
	//load variables in registers.
	unsigned long t = time;
	unsigned long ts = timeinSeconds;
	
	t++;
	ts = t/timeScale; //devide by scale to get seconds
	
	//put the values back in ram
	time = t;
	timeinSeconds = ts;
}
