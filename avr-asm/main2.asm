;source by: Duality / Robert
;Edited 13 - 5 - 2014
;	start working on implementing intterupts in assembly.
;	will make a walking light with interrupts timmers and leds.
;	note a rjmp(relative jump) can't jump as far as a jmp (jump)
;	but is faster, where jmp is slower.
;	rjmp can only jump 2047 up or down.
;	implementing timer interrupt and making it toggle a led.
;	timer works! going to main2.asm
.nolist
.include "m16def.inc"
.list
;.def's are symbolic names for registers.
;.equ's are symbolic names for constant value's.

.def temp = r16
.def eorRegister = r17

;data segment
.dseg
	.org SRAM_START
	;everything here is in ram. like lists and such.
	val_count: .BYTE 1

;code segment
.cseg
.org 0x00
	rjmp start
	;interrupts have to be handled in line of priority.
	;for interrupt handeling timer routine
	.org OVF1addr
		call timerInterruptRoutine
	
	start:
	;initialize registers to zero if needed
	ldi eorRegister, 0xFF
	;initialize status registers if needed
	sei ;enalbe interrupts
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
	;rjmp main

main:
	nop
	;call toggleLed
	rjmp main

setupDebugLed:
	ldi temp, 0xFF
	out DDRA, temp
	out PORTA, temp
	ret
	
toggleLed:
	in temp, PORTA
	ldi eorRegister, 0xFF
	eor temp, eorRegister
	out PORTA, temp
	ret

;routing for setting up the button.
buttonSetup:
	;use INT0
	ldi temp, (1<<INT0);enable INT0
	out GICR, temp
	ldi temp, (1<<ISC01) ;trigger on falling edge
	out MCUCR, temp
	sei
	ret
;button interrupt service routine.
buttonInterruptRoutine:
	;toggle led for debugging
	call toggleLed
	reti

;routine for setting up timer use
;using timer 1
timerSetup:
	;interupt on compare value.
	ldi temp, (1<<CS10);
	out TCCR1B, temp
	ldi temp, (1<<TOIE1)
	out TIMSK, temp
	sei
	ret
	
;timer interrupt service routine
timerInterruptRoutine:
	cli
	push eorRegister
	push temp
	in temp, sreg
	push temp
	;toggle led for debugging
	call toggleLed
	;load pointer to value
	;ldi ZL, low(val_count)
	;ldi ZH, high(val_count)
	;load count value into temp
	;ld temp, Z
	;inc temp ;increment temp;
	;st Z, temp;store value back in ram
	;reset the timer
	;ldi temp, 0x00
	;out TCNT1H, temp
	;ldi temp, 0x00
	;out TCNT1L, temp
	pop temp
	out sreg,r16
	pop temp 
	pop eorRegister
	sei
	reti
