
compile:
	avr-gcc -mmcu=atmega16 -Wall -Os -o build.elf main.c matrix.c

obj-copy:
	avr-objcopy -j .text -j .data -O ihex build.elf build.hex

upload:
	sudo avrdude -p atmega16 -c usbtiny -e -U flash:w:build.hex

fuses:
	sudo avrdude -c usbtiny -p atmega16 -U lfuse:w:0xa4:m -U hfuse:w:0xd1:m

clean:
	rm *.elf
	rm *.hex

