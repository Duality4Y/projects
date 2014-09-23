%define ASCII_NUM_OFFSET		0x30					;this+number will generate a asci number for it
%define ASCII_LETTER_OFFSET		0x41					;this+number will generate the hex letter for it.
%define HEX_OUT_OFFSET			(HEX_OUT+0x02)			;because first 2 characters are 0x and starts at 0
%define HEX_OUT_END				(HEX_OUT+0x05)			;end of the hexout buffer
%define HEX_LETTER_OFFSET		0x0A 					;offset for letters all letters are values > 10 so we have to subtract to get the right numbers out.

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
	
	mov cx, 0 					;cx wil hold a counter value.
	
	shiftLoop:
		mov ax, dx 				;ax is our accumulator register
		and ax, 0x000F			;we want to get only the four least significant bits.
		cmp ax, 0x0009			;we compare the 4 bits with 0x09 to see if it's < 10 
		jle makeAsciiNumber		;if ax < 0x09 then write push a ascii number representation on the stack
		jmp makeAsciiLetter	;else push a ascii letter representation on the stack
		
		makeAsciiLetter:		;add a ascii offset minus the hex_letter_offset to get the actual value/letter representation
		add  ax, ASCII_LETTER_OFFSET-HEX_LETTER_OFFSET
		push ax
		jmp  print_hex_shift
		
		makeAsciiNumber:		;add a ascii offset to get the actual value representation in ascii
		add  ax, ASCII_NUM_OFFSET
		push ax
		jmp  print_hex_shift
		
		print_hex_shift:
		shr dx, 4				;shift dx to the right by 4 to get the next part of the number
		inc cx					;increment cx
		cmp cx, 4 				;compare cx to 4
		jne shiftLoop			;if cx != 4 then go on with the loop
								;else we just go on to the next part of the code
	
	mov cx, 0					;clear the count register - start at 0
	mov si, HEX_OUT_OFFSET		;load address of the string buffer into si register
	
	load_hex_string_loop:
		pop ax					;pop/remove the character from the stack
		mov [si], ax			;put the character in the string buffer
		inc si					;increment the address to make it ready for the next letter
		inc cx					;increment the count register
		cmp cx, 4				;compare the count register to 4
		jne load_hex_string_loop;while cx != 4 load next character and put it in the string buffer and so on.
	
	mov bx, HEX_OUT				;enter the HEX_OUT "buffer" as a parameter
	jmp print_string			;print the string (the hex value in string representation)
	
	popa
	ret

HEX_OUT: db '0x0000', 0
