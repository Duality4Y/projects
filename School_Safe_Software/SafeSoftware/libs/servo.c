/*
 * the check in setServoPos() allows you to easily switch from closed to open
 * closed by passing it a 0 (the servo will close the door)
 * open by passeing it a 0-1 if uint8_t it wil pass 255, and open the door. 
 * */
 
//variables used to track the time the servo has started moving, and when to turn it off
volatile uint8_t isServoActive = false; //Simple boolean to know if the servo is active
volatile int finalServoPos = -1; //Stores the final position the servo has to get to, used when opening the safe
volatile int previousServo = 0; //Keeps track for when we enabled the servo

//this function takes a value between 0 and 10. and sets the servo to the position accordingly.
void setServoPos(uint8_t position)
{
	//check if value in range.
	if(position > 10)
		position = 10;
	if(position < 0)
		position = 0;
	//set the position.
	OCR2B = position+4;
	//this particular servo ranges from 4 for OCR2B to 14
}

void enableServo()
{
	//keep track of the state the servo is in.
	isServoActive = true;
	//also keep track of the current time.
	previousServo = time;
	//enable servo by renabling the servo interupt.
	TIMSK2 |= (1<<OCIE2A)|(1<<OCIE2B);
}

void disableServo()
{
	//set servo to inactive.
	isServoActive = false;
	//disable servo by disabling the servo related interupt.
	TIMSK2 &= ~((1<<OCIE2A)|(1<<OCIE2B));
}

void initServo()
{
	//initialize timer 2 with a prescaler of 1024 and wave form generation ctc.
	TCCR2A |= (1<<WGM21); 
	TCCR2B |= (1<<CS20)|(1<<CS21)|(1<<CS22);
	TIMSK2 |= (1<<OCIE2A)|(1<<OCIE2B); //enable compare interupst.
	OCR2A = 158; // 8000000/1024/50 = 156.25 but the scope shows 158 closer to 20ms pulse.
	OCR2B = 0; //period controle.
	sei(); //enable global interups.
	
	SERVO_DDR |= (1<<SERVO_PIN);
	//always start in the locked position.
	setServoPos(10);
	//always turn the servo off.
	disableServo();
}

//this interupt service routine is entered to set the off period.
ISR(TIMER2_COMPB_vect)
{
	SERVO_PORT &= ~(1<<SERVO_PIN);
}
//this interupt service routine is entered to set the on period
ISR(TIMER2_COMPA_vect)
{
	SERVO_PORT |= (1<<SERVO_PIN);
}

