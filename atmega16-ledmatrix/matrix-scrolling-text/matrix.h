#ifndef _MATRIX_H_
#define _MATRIX_H_

#define F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile unsigned char display_char;
volatile uint8_t offset;
volatile float scroll_speed;

//sets up the timer and ports/pins that are used.
void initMatrixDisplay(void);

//allows you to set a single pixel
void setPixel(uint8_t, uint8_t);

//puts a asscii character onto the display.
//put_c calculates font offset. and 
//displayAscii actually puts it on the display
void displayAscii(uint16_t *);

void put_c(volatile char);

//defines for controlling which is the rows or collumn ddr registers.
#define ROW_DDR			DDRD
#define COLLUMN_DDR		DDRB

//defines for controlling the row and collumn pins.
#define ROW_PORT			PORTD
#define COL_PORT			PORTB

//defines for enabling the scrolling timer or disabling it.
#define DISABLE_TIMER0_TICK		(TCCR0 = (0<<CS02)|(0<<CS01)|(0<<CS00))
#define ENABLE_TIMER0_TICK		(TCCR0 = (1<<CS02)|(0<<CS01)|(0<<CS00))


#endif
