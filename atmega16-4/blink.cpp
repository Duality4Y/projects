void blink(void)
{
	DDRD |= (1<<PD7);
	PORTD ^= (1<<PD7);
}
