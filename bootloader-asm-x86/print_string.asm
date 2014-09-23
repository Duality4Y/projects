%define ASCII_NUM_OFFSET		0x30 ;this+number will generate a asci number for it
%define ASCII_LETTER_OFFSET		0x41 ;this+number will generate the hex letter for it.
%define HEX_OUT_OFFSET			(HEX_OUT+0x02) ;because first 2 characters are 0x and starts at 0
%define HEX_OUT_END				(HEX_OUT+0x05) ;end of the hexout buffer

print_string:
	pusha
	loop:
		mov al, [bx] 		;load the first character to be printed
		cmp al, 0 			;compare value in al with 0 to find the null terminator.
		je print_string_end	;if it is the 0 terminator jmp to end.
		
		mov ah, 0x0E 		;tell bios we want teletype
		int 0x10 			;call interupt to write it to screen
		inc bx				;add 1 for next character (next address for next character)
		jmp loop
	;else return
	
	print_string_end:
	popa
	ret

print_hex:
	pusha
	
	mov cx, dx
	and cx, 0x000F
	cmp cx, 0x0009
	jle makeAsciiNumber
	jg makeAsciiLetter
	
	makeAsciiLetter:
	add cx, ASCII_LETTER_OFFSET-13
	jmp print_hex_end
	
	makeAsciiNumber:
	add cx, ASCII_NUM_OFFSET
	jmp print_hex_end
	
	print_hex_end:
	
	mov si, HEX_OUT_OFFSET
	mov [si], cx
	
	mov bx, HEX_OUT
	jmp print_string
	
	popa
	ret

HEX_OUT: db '0x0000', 0
