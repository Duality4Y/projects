uint8_t ticks = 0; //keeps rotary ticks
volatile uint8_t tick_count = 0; //keeps actual count entered.
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
uint8_t prev_direction = 1;
//keep track of how many times the direction changes.
uint8_t direction_count = 0;

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

//this interupt service routine is entered when pin a is triggered.
ISR(INT0_vect, ISR_BLOCK)
{
	sleep_disable();
	//if the pin it's self is low, and pin b is high we now rotation happend
	//and thus add ticks.
	if((PIND & (1<<ENCODER_PIN_B)))
	{
		direction = 1; //keep direction
		ticks--; //update ticks
	}
}
//same for this function only adding ticks.
ISR(INT1_vect,ISR_BLOCK)
{
	sleep_disable();
	if((PIND & (1<<ENCODER_PIN_A)))
	{
		direction = 0;
		ticks++;
	}
}
