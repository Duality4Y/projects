;example from the interwebs,
;edited by: Duality / Robert

.list
.device ATtiny84 ;a .device for selecting your chip with avrgasm 
;which is pretty cool!! 

.dseg ;data segment
.def temp = r16 
.def delay1 = r17 
.def delay2 = r18 
.def delayv = r19

.cseg ;code segment
.org $000 
	rjmp main 

;subroutines
delay: 
	clr delay1 
	clr delay2 
	ldi delayv, 100 

delay_loop: 
	dec delay2 
	brne delay_loop 
	dec delay1 
	brne delay_loop 
	dec delayv 
	brne delay_loop 
	ret ; go back to where we came from 


main: 
	;apperently the first thing that happens is that the stack pointer is set.
	ldi temp,low(RAMEND) 
	out SPL,temp 
	ldi temp,high(RAMEND) 
	out SPH,temp 
	
	ldi temp, 0xFF;load 0xFF in to r16
	out DDRA, temp;load r16 into DDRA all ports to output.
	;sbi DDRA, 0xFF ; connect PORTD pin 4 to LED 
	loop:
		rcall delay ; delay again for a short bit 
		out PINA, temp;
		rjmp loop ; recurse back to the head of loop 
