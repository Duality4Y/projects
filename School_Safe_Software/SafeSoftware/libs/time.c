/*
 * a way of keeping track of time.
 * by darrel 
 * */

//Time tracking related
unsigned long time = 0; //Stores the time in fifth of seconds
unsigned long timeinSeconds = 0; //stores the time in seconds

void initTime()
{
	//setup to tick once a second.
	TCCR0A |= (1<<WGM01); //ctc mode (clear on timer compare)
	TCCR0B |= (1<<CS00)|(1<<CS02); //set prescaler to 1024
	TIMSK0 |= (1<<OCIE0A); //enable interupt on compare
	OCR0A = 198;
	sei(); //enable global interupts.
}

ISR(TIMER0_COMPA_vect)
{
	//increment every 1/5 a second.
	unsigned long t = time;
	unsigned long ts = timeinSeconds;
	
	t++;
	ts = t/5;
	
	time = t;
	timeinSeconds = ts;
}
