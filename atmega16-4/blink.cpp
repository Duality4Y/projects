void blink(void)
{
	PORTD ^= (1<<PD7);
}
