volatile uint8_t ticks = 128; //keeps rotary ticks
volatile uint8_t previous_ticks = 0;
volatile uint8_t direction = 1; //keeps direction so we can keep track when to jump to the next number.
volatile uint8_t rotary_has_turned = 0;
uint8_t prev_direction = 0;

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
	uint8_t temp_ticks = ticks;
	//sleep_disable();
	//if the pin it's self is low, and pin b is high we now rotation happend
	//and thus add ticks.
	if((PIND & (1<<ENCODER_PIN_B)) && !(PIND & (1<<ENCODER_PIN_A)))
	{
		rotary_has_turned = 1;
		direction = 1; //keep direction
		temp_ticks--; //update ticks
	}
	ticks = temp_ticks;
}
//same for this function only adding ticks.
ISR(INT1_vect,ISR_BLOCK)
{
	uint8_t temp_ticks = ticks;
	//sleep_disable();
	if((PIND & (1<<ENCODER_PIN_A)) && !(PIND & (1<<ENCODER_PIN_B)))
	{
		rotary_has_turned = 1;
		direction = 0;
		temp_ticks++;
	}
	ticks = temp_ticks;
}
