.device attiny84

;holds the pin to symbol values.
.equ one 				= (1<<PA3);
.equ two 				= (1<<PA0)|(1<<PA4);
.equ two_two 			= (1<<PA2)|(1<<PA6);
.equ three				= one|two;
.equ three_two			= one|two_two;
.equ four				= two|two_two;
.equ five 				= four|one;
.equ size 				= four|(1<<PA1)|(1<<PA5);
.equ number_of_symbols 	= 8;

.def i = r17
.def temp = r16

.dseg ;everything after here is in ram right ?
	numbers: .byte number_of_symbols+1 ; reserves space for throwing numbers.
.cseg
.org 0x00
;whole port as output.
ldi temp, 0xFF
out DDRA, temp
reset:
	rjmp main

main:
	;set a number to the output.
	ldi temp, four
	out PORTA, temp
	rjmp main
