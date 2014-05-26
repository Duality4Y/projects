setupDebugLed:
	ldi temp, 0xFF
	out DDRA, temp
	ret
	
toggleLed:
	in temp, PORTA
	eor eorRegister, temp
	out PORTA, eorRegister
	ret
