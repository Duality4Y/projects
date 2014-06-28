;source by: Duality / Robert
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
; this version works. in reads the symbols from memory. with .db en lpm
; I will try to get the next version to work with the tilt switch so that if you 
; shake the dice, it'll throw a number.
; edited: 21 - 1 - 2014
; it now works!
; shake it ! throw it! 
; if you shake it it throws a random number :)
.nolist
.include "tn84def.inc"
.list

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
.equ tiltswitch		= (1<<PB0)|(1<<PB1)

.def temp 			= r16
.def thrown_number 	= r17
.def count 			= r18
.def switch1		= r19
.def switch2 		= r20
	
.cseg
.org 0x00
	;keep symbols in memory.
	numbers: .db one,two,two_two,three,three_two,four,five,six
	;set led pins to output.
	ldi temp, one|six
	out DDRA, temp
	;set button and tilt switch to input
	in temp, DDRB
	andi temp, ~(button|(1<<PB0)|(1<<PB1))
	out DDRB, temp
	;turn on internal pullup for the tilt switch.
	ldi temp, (1<<PB0)|(1<<PB1)
	out PORTB, temp
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


tiltRoutine:
	clr temp ;clear temp just in case.
	tiltLoop:
		inc count ;keep how long the tilt switch is in one position.
		ldi temp, 0x07 
		and count, temp ;together with 0x07 we get the range we want. 0 to 7.
		in temp, PINB ;read the tilt pins.
		andi temp, tiltswitch ;if tilt in different position then we want
		breq tiltLoop ;keep looping till tilt is in desired position.
	ret

buttonPressedRoutine:
	clr temp ;clear temp just in case.
	buttonloop: ;this loop runs while button down
		inc count ;keep how long it was down.
		ldi temp, 0x07 
		and count, temp ;together with 0x07 we get the range we want.
		in temp, PINB ;read the button pin
		andi temp, button ;check if button was pressed.
		brne buttonloop ;while pressed keep looping to buttonloop.
	ret

loadsymbol:
	ldi ZH, high(numbers) ;load pointer to symbol table.
	ldi ZL, low(numbers)
	ldi temp, 0x01 
	add count, temp ;add one so we have a range from 1 to 8 and not 0 to 7.
	loadLoop: ;loop to load the symbol
		lpm thrown_number, Z+ ;load the symbol from memory
		dec count ;and advance to the next for as long as we pressed down.
		brne loadLoop
	ret

main:
	out PORTA, thrown_number;out put the symbol

	;in temp, PINB
	;andi temp, (1<<PB0)|(1<<PB1)
	;mov thrown_number, temp
	;rjmp main

	in temp, PINB ;read tilt switch
	andi temp, tiltswitch
	breq tilt

	in temp, PINB ;read button pin
	andi temp, button ;check if button pin was pressed
	brne buttonPressed ;if pressed, jump to displayRandomNumber.
	rjmp main

	buttonpressed:
		rcall buttonPressedRoutine
	tilt:
		rcall tiltRoutine
	rcall loadsymbol
	rjmp main ;finally run back to main.
