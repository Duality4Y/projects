/*
 * this code will display numbers nonblocking and interupt based.
 * */

volatile int displayedNum = 0;
int displayed = 0;

//this function wil display a number onto the 7 segment display.
void displayNum(int num)
{
	/*
	 * the variable m is kind of like a mask.
	 * the first time in the loop m = 1234
	 * then when we display it does 1234%10 which is 4
	 * for the next itteration m = 123
	 * and when we display the next number on the next display
	 * we do 123%10 and that displays 3
	 * and so on and so on.
	 * we repeat it so fast the numbers appears one by one on the display
	 * */
	 
	 //quick check to see if the nummber is out of range
	 if(num > 9999 || num < 0)
		num = 0;
	 
	uint8_t segment = 1; //keep track of which segment is selected
	//i is used to determine which segment is selected.
	//and m is sed to determine which 10 power of num we display.
	int i,m;
	for(i = 0,m = num;i<4;i++,m/=10)
	{
		//select display/segment
		segment = 0xF0 & ~((1<<i)<<4); //this selects the transistor to switch
		shiftOut(segment | m%10); //this all shifts out the data
	}
}

void initDisplay()
{
	TCCR1B |= (0<<CS12)|(0<<CS11)|(1<<CS10)|(1<<WGM12);
	TIMSK1 |= (1<<OCIE1A);
	OCR1A = 7000;//5950;
	sei();
}

ISR(TIMER1_COMPA_vect)
{
	int temp = displayedNum;
	displayNum(temp);
	TCNT1 = 0;
}
