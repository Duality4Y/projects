%define ASCII_NUM_OFFSET		0x30 ;this+number will generate a asci number for it
%define ASCII_LETTER_OFFSET		0x41 ;this+number will generate the hex letter for it.
%define HEX_OUT_OFFSET			0x02 ;because first 2 characters are 0x and starts at 0
%define HEX_OUT_END				0x06 ;end of the hexout buffer

print_string:
	pusha
	loop:
	
	mov al, [bx] ;load the first character to be printed
	cmp al, 0 ;compare value in al with 0 to find the null terminator.
	je end;if it is the 0 terminator jmp to end.
	
	mov ah, 0x0E ;tell bios we want teletype
	int 0x10 ;call interupt to write it to screen
	add bx, 1 ;add 1 for next character (next address for next character)
	jmp loop
	;else return
	
	end:
	popa
	ret

print_hex:
	pusha
	
	mov ax, 0							;ax for index start 0 till 4
	loop_shift:							;shifting loop
		mov cx, dx						;copy value of dx in cx for use.
		and cx, 0x0F					;check for the four first bits.
		cmp cx, 0x09 
		jg putoutLetter					;if cx > 9 put a letter in the hex string
		jmp putoutNumber				;else putout a number in the hex string
	putoutLetter:						;puts a letter into the "buffer"
		add cx, ASCII_LETTER_OFFSET		;to get the ascii value for a letter
		push cx 						;store that value on the stack
		jmp shift
	putoutNumber:						;puts a number into the "buffer"
		add cx, ASCII_NUM_OFFSET		;to get the ascii value for a number
		push cx							;stor that value on the stack
		jmp shift
	shift:
		shr dx, 4						;shift dx so we can get the next 4 bits
		inc ax							;inc ax to keep track where we are.
		cmp ax, 3						;compare ax with 3 to see if we looped 4 times.
		jne loop_shift					;if ax != 3 jump to loop_shift
	
										;after all this 4 values will be stored on the stack
										;pop four times and put them in HEX_OUT
	
	mov ax, 0							;will hold ascii data
	mov esi, (HEX_OUT+HEX_OUT_END)		;will hold index will count back from the last digit.
										;the first char we pop is the last we want to print.
	loop_write_data:
		pop ax							;value is now in ax
		mov [esi], ax					;put value in ax in address of si
		dec esi							;dec address for writing char to 
		cmp esi, (HEX_OUT+HEX_OUT_OFFSET);if we reach HEX_OUT+HEX_OUT_OFFSET we have no more numbers.
		jne loop_write_data				;while we have not reached the end keep looping
	
	mov bx, HEX_OUT
	call print_string
	
	popa
	ret

HEX_OUT: db '0x0000', 0
