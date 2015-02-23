
compile:
	avr-gcc -mmcu=atmega16 -D F_CPU=8000000UL -Wall -Os main.c matrix.c uart.c -o build.elf

obj-copy:
	avr-objcopy -j .text -j .data -O ihex build.elf build.hex

upload:
	avrdude -p atmega16 -c usbtiny -e -U flash:w:build.hex

fuses:
	sudo avrdude -c usbtiny -p atmega16 -U lfuse:w:0xa4:m -U hfuse:w:0xd1:m

all: compile obj-copy upload

clean:
	rm *.elf
	rm *.hex
	rm *.pyc
