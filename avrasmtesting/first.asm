.include "tn84def.inc" 

.dseg 
.def temp = r16 
.def delay1 = r17 
.def delay2 = r18 
.def delayv = r19 
.equ led = 4 ; PORTD bit number to blink LED on 

.cseg 
.org $000 
rjmp main 

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
ldi temp,low(RAMEND) 
out SPL,temp 
ldi temp,high(RAMEND) 
out SPH,temp 

sbi DDRA, led ; connect PORTD pin 4 to LED 

loop: 
cbi PORTA, led ; turn PD4 high 
rcall delay ; delay for an short bit 
sbi PORTA, led ; turn PD4 low 
rcall delay ; delay again for a short bit 
rjmp loop ; recurse back to the head of loop 
