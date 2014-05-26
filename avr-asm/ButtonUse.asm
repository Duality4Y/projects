;routing for setting up the button.
buttonSetup:
	;use INT0
	ldi temp, (1<<INT0);enable INT0
	out GICR, temp
	ldi temp, (1<<ISC01) ;trigger on falling edge
	out MCUCR, temp
	ret
;button interrupt service routine.
buttonInterruptRoutine:
	;toggle led for debugging
	call toggleLed
	reti

