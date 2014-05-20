;source by: Duality / Robert
;Edited 13 - 5 - 2014
;	start working on implementing intterupts in assembly.
;	will make a walking light with interrupts timmers and leds.
;	note a rjmp(relative jump) can't jump as far as a jmp (jump)
;	but is faster, where jmp is slower.
;	rjmp can only jump 2047 up or down.
;	implementing timer interrupt and making it toggle a led.
;	timer works! going to main2.asm
;Edited 17 - 5 - 2014
;	timer interupt now correctly works.
;   my pin toggeling function wasen't right,
;	had to use in instead of ldi
;	
;	how to calculate
;	fcpu = 8000000
;	scale = 256
;	maxCValue = 2^16 (65536)-1
;	thus fcpu/scale/maxCValue = 0.47hz
;	to get 1hz we preload the timer on interupt with a value of
;	(2^16)/2 tcnt1 = 32768
;	and now the timer will tick once every second.

;.nolist
.include "m16def.inc"
;.list
;.def's are symbolic names for registers.
;.equ's are symbolic names for constant value's.

.def temp = r16
.def eorRegister = r17

;data segment
.dseg
	;everything here is in ram. like lists and such.
	val_count: .BYTE 1

;code segment
.cseg
	.org 0x00
		rjmp start
	;interrupts have to be handled in line of priority.
	;for interrupt handeling timer routine
	.org OVF1addr-1
		reti
	.org OVF1addr
		call timerInterruptRoutine
	start:
	cli
	;initialize registers to zero if needed
	ldi eorRegister, 0xFF
	;initialize status registers if needed
	;initialize pins
	
	;initialize the stack
	ldi temp, low(RAMEND)
	out SPL, temp
	ldi temp, high(RAMEND)
	out SPH, temp
	
	;setup timer
	call timerSetup
	;setup led use
	call setupDebugLed
	;setup button use
	;call buttonSetup
	;jump to main routine.
	sei
	rjmp main

main:
	nop
	;call toggleLed
	jmp main

setupDebugLed:
	ldi temp, 0xFF
	out DDRA, temp
	ret
	
toggleLed:
	in temp, PORTA
	eor eorRegister, temp
	out PORTA, eorRegister
	ret

;routing for setting up the button.
buttonSetup:
	;use INT0
	ldi temp, (1<<INT0);enable INT0
	out GICR, temp
	ldi temp, (1<<ISC01) ;trigger on falling edge
	out MCUCR, temp
	ret
;button interrupt service routine.
buttonInterruptRoutine:
	;toggle led for debugging
	call toggleLed
	reti

;routine for setting up timer use
;using timer 1
timerSetup:
	cli
	;interupt on compare value.
	ldi temp, (1<<CS12)
	out TCCR1B, temp
	ldi temp, (1<<TOIE1)
	out TIMSK, temp
	sei
	ret
	
;timer interrupt service routine
timerInterruptRoutine:
	push temp
	;toggle led for debugging
	call toggleLed
	ldi temp, high(32768)
	out TCNT1H, temp
	ldi temp, low(32768)
	out TCNT1L, temp
	pop temp
	reti
