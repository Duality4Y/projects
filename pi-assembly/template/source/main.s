.section .init
.globl _start
_start:
	@set led pin ACT to output
	mov r1, #1
	lsl r1, #18
	str r1, [r0, #4]
	@turn ACT on
	mov r1, #1
	lsl r1, #16
	str r1, [r0, #40]
	
@happily ever after ! :D
loop$:
	b loop$
