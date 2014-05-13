;source by: Duality / Robert
;Edited 13 - 5 - 2014
;	start working on implementing intterupts in assembly.
;	will make a walking light with interrupts timmers and leds.
;	note a rjmp(relative jump) can't jump as far as a jmp (jump)
;	but is faster, where jmp is slower.
;	rjmp can only jump 2047 up or down.
;	implementing timer interrupt and making it toggle a led. 
.include "m16def.inc"

;.def's are symbolic names for registers.
;.equ's are symbolic names for constant value's.

.def temp = r16

;interrupts have to be handled in line of priority.
;for button interrupt routine
.org INT0addr
	jmp buttonInterruptRoutine
;for interrupt handeling timer routine
.org OC1Aaddr
	jmp timer1InterruptRoutine

;data segment
.dseg
	.org SRAM_START
	;everything here is in ram. like lists and such.
	val_count: .BYTE 1

;code segment
.cseg
.org 0x00
	;initialize registers to zero if needed
	;initialize status registers if needed
	sei ;enalbe interrupts
	;initialize pins
	
	;initialize the stack
	ldi r16, low(RAMEND)
	out SPL, r16
	ldi r16, high(RAMEND)
	out SPH, r16
	
	;setup timer
	rjmp timerSetup
	;setup led use
	rjmp setupDebugLed
	;setup button use
	rjmp buttonSetup
	;jump to main routine.
	rjmp main

main:
	rjmp main

setupDebugLed:
	ret
toggleLed:
	ret

;routing for setting up the button.
buttonSetup:
	ret
;button interrupt service routine.
buttonInterruptRoutine:
	reti

;routine for setting up timer use
;using timer 1
timerSetup:
	;interupt on compare value.
	ldi temp, (1<<CS12)|(1<<CS10)|(1<<WGM12);prescaler of 1024 and ctc mode.
	out TCCR1B, temp
	ldi temp, (1<<OCIE1A)
	out TIMSK, temp
	;compare on value of 781 for a pulse a second.
	ldi temp, low(781)
	out OCR1AL, temp
	ldi temp, high(781)
	out OCR1AH, temp
	sei
	ret
	
;timer interrupt service routine
timer1InterruptRoutine:
	;toggle led for debugging
	jmp toggleLed
	;load pointer to value
	ldi ZL, low(val_count)
	ldi ZH, high(val_count)
	;load count value into temp
	ld temp, Z
	inc temp ;increment temp;
	st Z, temp;store value back in ram
	reti
