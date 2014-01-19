;source by: Dualit / Robert
;Edited 18 - 1 - 2014
;Edited 19 - 1 - 2014
;working to get symbols stored in ram, and used to be displayed.
;this version works! a random throw with the push of a button.

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
.def count  		= r18
.def thrown_number	= r17
.dseg
.org 0x0060
	;everything after here is in ram
	;numbers: .byte number_of_symbols+1 ; reserves space for throwing numbers.
	numbers: .byte number_of_symbols
.cseg
.org 0x00
    ldi count, 0x00
    ldi thrown_number, 0x00
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
    ;load symbols into memory
    rcall loadSymbols
    ;-----
    rjmp main

loadSymbols:
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
    ;since it includes 8.  (the number of dice sides.)
    out PORTA, thrown_number
    in temp, PINB
    andi temp, button
    breq main ;if button is not pressed jump to main else run button loop
    buttonloop:;loop runs while button down.
        inc count ;how long was the button pressed
        ldi temp, 0x07
        and count, temp ;only the first 8 symbols we want.
        ;(not actually measure of time but yea.)
        in temp, PINB;
        andi temp, button;check if button was pressed
        brne buttonloop
    ;load the symbol into thrown number and display.
    ;we want to display the number all the time, but only retrieve the symbol once.
    ;so we do this after the button code has run.
    ;and will not happen till button is pressed again.
    ldi ZH, high(numbers)
    ldi ZL, low(numbers)
    ;add 1 to count or we won't get zero ?
    ldi temp, 0x01
    add count, temp
    loadLoop:
        ld thrown_number, Z+
        dec count
        brne loadLoop
    rjmp main