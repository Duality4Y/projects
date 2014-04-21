/*
 * the check in setServoPos() allows you to easily switch from closed to open
 * closed by passing it a 0 (the servo will close the door)
 * open by passeing it a 0-1 if uint8_t it wil pass 255, and open the door. 
 * */

#include <util/delay.h>

//variables used to track the time the servo has started moving, and when to turn it off
volatile uint8_t isServoActive = false; //Simple boolean to know if the servo is active
volatile int finalServoPos = -1; //Stores the final position the servo has to get to, used when opening the safe
volatile int previousServo = 0; //Keeps track for when we enabled the servo

#define SERVOMAX 			14
#define SERVOMIN 			4
#define SERVORANGE 			(SERVOMAX-SERVOMIN)
#define SERVOCONTROLEREG 	OCR2A

//posible states the servo can have
#define SERVO_CLOSED SERVORANGE
#define SERVO_OPENED SERVORANGE/2
#define SERVO_KICKED 0

void enableServo()
{
	//keep track of the state the servo is in.
	isServoActive = true;
	//also keep track of the current time.
	previousServo = time;
	TCCR2A |= (1<<CS22);//enable timer
	//turn servo power transistor on.
	SERVO_POWER_PORT &= ~(1<<SERVO_POWER_CONTROLE);
	//enable pwm on pin
	SERVO_PORT |= (1<<SERVO_PIN);
}

void disableServo()
{
	//set servo to inactive.
	isServoActive = false;
	TCCR2A &= ~(1<<CS22); //kill timer
	//turn servo power transistor off.
	SERVO_POWER_PORT |= (1<<SERVO_POWER_CONTROLE);
	//kill signal on servo pin
	SERVO_PORT &= ~(1<<SERVO_PIN);
}

//this function takes a value between 0 and 10. and sets the servo to the position accordingly.
void setServoPos(uint8_t position)
{
	enableServo();
	//check if value in range.
	if(position > SERVORANGE)
		position = SERVORANGE;
	if(position < 0)
		position = 0;
	//set the position.
	SERVOCONTROLEREG = position+SERVOMIN;
}


uint8_t getCurrentServoState()
{
	return (OCR2A-SERVOMIN);
}

void initServo()
{
	TCCR2A |= (1<<COM2A1)|(1<<WGM20)|(1<<WGM21);//fast pwm on pb3 (oc2a)
	TCCR2B |= (1<<CS20)|(1<<CS21)|(1<<CS22); //about ~50hz with 1024 prescaler.
	//PB3 as output
	SERVO_DDR |= (1<<SERVO_PIN);
	//powerpin for servo to output.
	SERVO_POWER_DDR |= (1<<SERVO_POWER_CONTROLE);
	//turn servo power transistor on.
	SERVO_POWER_PORT &= ~(1<<SERVO_POWER_CONTROLE);
	//enable and set servo to mid position.
	setServoPos(SERVORANGE/2);
	//make sure finalstate is mid state and then is disable.
	finalServoPos = SERVORANGE/2;
	//enalble global interupts
	sei();
}
