;routine for setting up timer use
;using timer 1
timerSetup:
	cli
	;interupt on compare value.
	ldi temp, (1<<CS12)
	out TCCR1B, temp
	ldi temp, (1<<TOIE1)
	out TIMSK, temp
	sei
	ret
	
;timer interrupt service routine
timerInterruptRoutine:
	push temp
	;toggle led for debugging
	call toggleLed
	ldi temp, high(32768)
	out TCNT1H, temp
	ldi temp, low(32768)
	out TCNT1L, temp
	pop temp
	reti
