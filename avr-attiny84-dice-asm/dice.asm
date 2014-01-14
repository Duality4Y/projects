
.device attiny84

;holds the pin to symbol values.
.equ one 				= (1<<PA3);
.equ two 				= (1<<PA0)|(1<<PA4);
.equ two_two 			= (1<<PA2)|(1<<PA6);
.equ three				= one|two;
.equ three_two			= one|two_two;
.equ four				= two|two_two;
.equ five 				= four|one;
.equ six 				= four|(1<<PA1)|(1<<PA5);
.equ number_of_symbols 	= 8;

.equ button				= (1<<PB2)

.def temp 	= r16
.def count  = r17

.dseg ;everything after here is in ram right ?
	numbers: .byte number_of_symbols+1 ; reserves space for throwing numbers.
.cseg

.org 0x00
	;start count at 0
	ldi count, 0x00
	ldi temp, 0xFF
	out DDRA, temp
	out DDRB, temp

	;Init stack
	ldi temp,low(RAMEND) 
	out SPL,temp 
	ldi temp,high(RAMEND) 
	out SPH,temp
	;==========
	rjmp main

main:
	;check for a button press.
	rcall checkButton
	;always clear led.
	;else if you press once it will stay lit
	rcall clearLed 
	rjmp main


;this checks if the button was pressed.
;if so call button pressed.
checkButton: 
	in temp, PINB
	andi temp, button
	brne buttonPressed
	ret

;this turns on the led if button is pressed.
buttonPressed:
	inc count
	rjmp setLed

;set the leds to patern of count.
setLed:
	out PORTA, count
	ret

;sets all leds on.
setAllLed:
	ldi temp, 0xFF
	out PORTA, temp
	rjmp main

clearLed:
	ldi temp, 0x00
	out PORTA, temp
	rjmp main
