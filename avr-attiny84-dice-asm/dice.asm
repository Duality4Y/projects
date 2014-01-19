;source by: Dualit / Robert
;Edited 18 - 1 - 2014
;Edited 19 - 1 - 2014
;working to get symbols stored in ram, and used to be displayed.

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

.equ button				= (1<<PB2)

.def temp 			= r16
.def count  		= r20
.def thrown_number	= r2
.dseg
.org 0x0060
	;everything after here is in ram
	;numbers: .byte number_of_symbols+1 ; reserves space for throwing numbers.
	numbers: .byte number_of_symbols
.cseg
.org 0x00
	;start count at 7
	ldi count, number_of_symbols
	ldi temp, 0xFF
	out DDRA, temp
	ldi temp, 0x00
	out DDRB, temp

	;Init stack
	ldi temp,low(RAMEND) 
	out SPL,temp 
	ldi temp,high(RAMEND) 
	out SPH,temp
	;==========
	;rcall loadSymbols;load symbols into memory
	ldi ZH,HIGH(numbers) ; Set the MSB
    ldi ZL,LOW(numbers) ; Set the LSB
    ;load symbols one for one into ram.
    ldi temp, one
    st Z+, temp
    ldi temp, two
    st Z+, temp
    ldi temp, two_two
    st Z+, temp
    ldi temp, three
    st Z+, temp
    ldi temp, three_two
    st Z+, temp
    ldi temp, four
    st Z+, temp
    ldi temp, five
    st Z+, temp
    ldi temp, six
    st Z,  temp
	;==========
	rjmp main

loadSymbols:
	;load symbols into memory
	ldi ZH,HIGH(numbers) ; Set the MSB
    ldi ZL,LOW(numbers) ; Set the LSB
    ;load symbols one for one into ram.
    ldi temp, one
    st Z+, temp
    ldi temp, two
    st Z+, temp
    ldi temp, two_two
    st Z+, temp
    ldi temp, three
    st Z+, temp
    ldi temp, three_two
    st Z+, temp
    ldi temp, four
    st Z+, temp
    ldi temp, five
    st Z+, temp
    ldi temp, six
    st Z,  temp

	ret

main:
	;check for a button press.
	rjmp checkButton
	;always clear led.
	;else if you press once it will stay lit
	out PORTA, thrown_number
	;rcall clearLed 
	rjmp main

;this checks if the button was pressed.
;if so call button pressed.
checkButton:
	in temp, PINB ;read pin in register.
	andi temp, button ;check if the pin is set.
	brne buttonPressed ;if pin is set branch to setAllLed.

buttonPressed:
	buttonloop: ;this loop holds while the button is down.
		inc count
		in temp, PINB ;do the same as when we checked button.
		andi temp, button
		rjmp setAllLed
		brne buttonloop

;sets all leds on.
setAllLed:
	;load temp with a number that represent the symbol we want to display.
	;load a value out of ram and display
	ldi ZH, high(numbers)
	ldi ZL, low(numbers)
	andi count, number_of_symbols-1
	loadLoop:
		ld temp, Z+
		dec count
		;out PORTA, temp
		brne loadLoop
	mov thrown_number, temp
	;ldi temp, 0xFF
	;out PORTA, temp	
	
	rjmp main

clearLed:
	ldi temp, 0x00
	out PORTA, temp
	rjmp main

;set the leds to patern of count.
setLed:
	ldi temp, 0xFF
	out PORTA, temp
	rjmp main
