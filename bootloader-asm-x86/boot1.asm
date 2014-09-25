;the offset code testing and such

mov ah, 0x0E
mov al, [the_secret]
int 0x10

mov bx, 0x7C0
mov ds, bx
mov al, [the_secret]
int 0x10

mov al, [es:the_secret]
int 0x10

mov bx, 0x7C0
mov es, bx
mov al, [es:the_secret]
int 0x10

jmp $

DISK_ERROR_MSG: db "Disk read error!", 0

the_secret:
	db "X"

%include "print_string.asm"

;Padding and magic BIOS number.
times 510-($-$$) db 0
dw 0xAA55
