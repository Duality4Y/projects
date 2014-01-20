;source by: Dualit / Robert
;Edited 18 - 1 - 2014
;Edited 19 - 1 - 2014
;working to get symbols stored in ram, and used to be displayed.
;this version works! a random throw with the push of a button.
;Edited 20 - 1 - 2014
;this version will store the symbols in flash.
;and wil use the .db directive to store.
;and lpm to read them from program memory.
;.db
;lpm

.include "tn84def.inc"

;holds the pin to symbol values.
.equ one 				= (1<<PA3);
.equ two 				= (1<<PA0)|(1<<PA4);
.equ two_two 			= (1<<PA2)|(1<<PA6);
.equ three				= one|two;
.equ three_two			= one|two_two;
.equ four				= two|two_two;
.equ five 				= four|one;
.equ six				= (four|(1<<PA1)|(1<<PA5));
.equ number_of_symbols 	= 8;

.equ button			= (1<<PB2)

.def temp 			= r16
.def count 			= r18
.def thrown_number 	= r17
	
.cseg
.org 0x00
	;keep symbols in memory.
	numbers: .db one,two,two_two,three,three_two,four,five,six
	;setup the pins.
	ldi temp, 0xFF
	out DDRA, temp
	ldi temp, 0x00
	out DDRB, temp

	;init stack
	ldi temp, low(RAMEND)
	out SPL, temp
	ldi temp, high(RAMEND)
	out SPH, temp
	;set count to 0
	ldi count, 0x00
	;start by displaying a six
	ldi thrown_number, six
	;jump to the main loop
	rjmp main

main:
	out PORTA, count
	in temp, PINB
	andi temp, button
	breq main
	buttonloop:
		inc count
		ldi temp, 0x07
		and count, temp
		in temp, PINB
		andi temp, button
		brne buttonloop

	ldi ZH, high(numbers)
	ldi ZL, low(numbers)
	rjmp main