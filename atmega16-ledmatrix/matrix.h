#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <ctype.h>

volatile unsigned char display_char;
volatile uint8_t offset;
volatile float scroll_speed;
volatile char *name;

//sets up the timer and ports/pins that are used.
void initMatrixDisplay(void);

//allows you to set a single pixel
void setPixel(uint8_t, uint8_t);

//puts a asscii character onto the display.
//put_c calculates font offset. and 
//displayAscii actually puts it on the display
void displayAscii(volatile uint16_t *);
void display(volatile char *);

void put_c(volatile char);

//defines for controlling which is the rows or collumn ddr registers.
#define ROW_DDR			DDRA
#define COLLUMN_DDR		DDRB

//defines for controlling the row and collumn pins.
#define ROW_PORT			PORTA
#define COL_PORT			PORTB

//defines for enabling the scrolling timer or disabling it.
#define DISABLE_TIMER0_TICK		(TCCR0 = (0<<CS02)|(0<<CS01)|(0<<CS00))
#define ENABLE_TIMER0_TICK		(TCCR0 = (1<<CS02)|(0<<CS01)|(0<<CS00))


#endif
