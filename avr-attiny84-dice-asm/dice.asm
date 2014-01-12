
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

.dseg ;everything after here is in ram right ?
	numbers: .byte number_of_symbols+1 ; reserves space for throwing numbers.
.cseg

;macro that loads the numbers/symbols into the reserved byte space.
setup_symbol_array:
	ldi xl, low(number_of_symbols);
test:
	rjmp test;
