/*
 * this file contains functions and variables
 * the safe will use.
 * */
#include <avr/interrupt.h>
#include <util/delay.h>
#include "pinDefs.h"
#include "uart.c" //include basic uart capability written by Robert.

#define true 1
#define false 0


uint8_t ticks = 0; //keeps rotary ticks
volatile uint8_t tick_count = 0; //keeps actual count entered.
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
uint8_t prev_direction = 1;
//keep track of how many times the direction changes.
uint8_t direction_count = 0;

//will keep time. using timer2
volatile unsigned long timer2_Count = 0;
unsigned int seconds = 0;

int pin = 8888; //the actuall pin.
int new_pin = 8888; //currently displayed pin.

//keep track of wheter someone is logged in or not.
uint8_t isLoggedIn = 0;
//create a link to the serial buffer to use.
volatile unsigned char* inputStr = uart_buffer;

//will hold formated string
unsigned char prettyString[50];

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
}

void initShifter()
{
	DDRB  |= 	 ( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT ); //register pins to output
	PORTB &=   ~(( 1<<LATCH )|( 1<<CLOCK )|( 1<<DATA_OUT )); //clear register pins.
}

void initRotary()
{
	//enable internal interupts.
	EICRA |= 	(0 << ISC00 )|( 1<<ISC01 );//enable INT1 to trigger on rising edge.
	EICRA |= 	(0 << ISC10 )|( 1<<ISC11 );//enable INT0 to trigger on rising edge.
	EIMSK |= 	( 1<<INT0 )|( 1<<INT1 );
	sei();
	
	//set encoder pins to input.
	DDRD  &=   ~(( 1<<ENCODER_PIN_A )|( 1<<ENCODER_PIN_B )|( 1<<ENCODER_BUTTON ));
	//enable pullups
	PORTD |= 	 ( 1<<ENCODER_PIN_A )|( 1<<ENCODER_PIN_B )|( 1<<ENCODER_BUTTON ); //set pullups on encoder pins.
}

//inits the power control pin.
void initPowerControle()
{
	DDRD  |= 	( 1<<POWERCONTROL );//power control pin to output.
	PORTD |=   ~( 1<<POWERCONTROL ); //enable internal pullup on POWERCONTROL pin
}

/*
 * the check in setServoPos() allows you to easily switch from closed to open
 * closed by passing it a 0 (the servo will close the door)
 * open by passeing it a 0-1 if uint8_t it wil pass 255, and open the door. 
 * */
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
//this function powers on the elecktronics.
void powerOn()
{
	PORTD &= ~(1<<POWERCONTROL);
	DDRB |= (1<<LATCH)|(1<<CLOCK)|(1<<DATA_OUT);
}
//this function wil power of the elecktronics.
void powerOff()
{
	
	PORTD |= (1<<POWERCONTROL);
	DDRB &= ~( (1<<LATCH)|(1<<CLOCK)|(1<<DATA_OUT));
}
//this function shifts out data.
void shiftOut(uint8_t data)
{
	PORTB &= ~( 1<<LATCH ); //pull latch low
	volatile int i = 7;
	while(i >= 0)
	{
		//check i'th bit against data, shift it by I to the right.
		//and then shift it by DATA_OUT to the left. so the port becomes the value of the
		//i'th bit.
		PORTB |= (( (data & ( 0x01<<i )) >> i ) << DATA_OUT );
		//toggle the clock.
		PORTB |= ( 1<<CLOCK );
		PORTB &= ~( 1<<CLOCK );
		//then clear the bit on the pin.
		PORTB &= ~(( (data & ( 0x01<<i )) >>i ) << DATA_OUT );
		i--;//decrement counter
	}//decrementing counter meens msb first.
	PORTB |= ( 1<<LATCH ); //pull latch high
}
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

void inputPinCode()
{
	pin = (ticks);
}
void lock(uint8_t isLocked){}
void enterCommandMode(unsigned char* inputStr)
{
	uart_clear();
	uart_put_str("\nentering command mode. \n\r");
	while(strcmp("exit", inputStr) != 0)
	{
		
	}
}
void runSerialInputCommands(volatile unsigned char* inputStr)
{
	//uart_put_str(inputStr);
	//if there is data in the buffer
	if(inputStr[0])
	{
		//parse commands
		if(strcmp("1", inputStr) == 0)
		{
			powerOn();
			uart_clear();
		}
		else if(strcmp("0", inputStr) == 0)
		{
			powerOff();
			uart_clear();
		}
		else if(strcmp("open", inputStr) == 0)
		{
			uart_put_str("\nOpening...\n\r");
			lock(true);
			uart_clear();
		}
		else if(strcmp("close", inputStr) == 0)
		{
			uart_put_str("\nClosing...\n\r");
			lock(false);
			uart_clear();
		}
		else if(strcmp("login", inputStr) == 0)
		{
			uart_clear();
			uart_put_str("enter pin: (exit to leave)\n");
			while(true)
			{
				if(pin == atoi(inputStr))
				{
					uart_put_str("pin matches acces granted.\n");
					uart_clear();
					isLoggedIn = true;
					break;
				}
				if(strcmp("exit", inputStr) == 0)
				{
					uart_put_str("leaving\n");
					uart_clear();
					isLoggedIn = false;
					break;
				}
			}
			uart_clear();
		}
		else if(strcmp("BT") == 0)
		{
			uart_put_str("\n\rBTOK\n");
			uart_clear();
		}
		/*
		else if(strcmp("sread", inputStr) == 0)
		{
			uart_put_str("\nServo value: \n\r");
			uart_clear();
		}
		//use strstr and strtok for composite commands.
		else if(strstr("pset", inputStr))
		{
			uart_put_str(inputStr);
			uart_clear();
		}
		else if(strcmp("pread", inputStr) == 0)
		{
			sprintf(prettyString, "\nPIN: %d \n\r", pin);
			uart_put_str(prettyString);
			uart_clear();
		}
		else if(strcmp("sleep", inputStr) == 0)
		{
			//sleep();
		}
		else if(strcmp("logout", inputStr) == 0)
		{
			
		}*/
	}
	else
	{
		uart_clear();
	}
}

//this interupt service routine is entered to set the off period.
ISR(TIMER2_COMPB_vect)
{
	SERVO_PORT &= ~(1<<SERVO_PIN);
}
//this interupt service routine is entered to set the on period
//when this interupt service routine is enterd (at which time) will also determine the frequentie.
ISR(TIMER2_COMPA_vect)
{
	TCNT2 = 0;
	SERVO_PORT |= (1<<SERVO_PIN);
}

//this interupt service routine is entered when pin a is triggered.
ISR(INT0_vect, ISR_NOBLOCK)
{
	//if the pin it's self is low, and pin b is high we now rotation happend
	//and thus add ticks.
	_delay_ms(1);
	if((PIND & (1<<ENCODER_PIN_B)))
	{
		direction = 1; //keep direction
		ticks--; //update ticks
	}
}
//same for this function only adding ticks.
ISR(INT1_vect,ISR_NOBLOCK)
{
	_delay_ms(1);
	if((PIND & (1<<ENCODER_PIN_A)))
	{
		direction = 0;
		ticks++;
	}
}
