#include "matrix.h"
#include "font.h"

//the to display text.
const char name[] = "Martijn";

//offset used in shifting the letters across the display.
volatile uint8_t offset = 0;

//holds data that is displayed on the screen
volatile unsigned char display_char = ' ';

//scroll_speed is how many letters scroll by per second.
volatile float scroll_speed = 0.6372;

void initMatrixDisplay(void)
{
	//pins and ports used for the display
	
	//make the ports output
	ROW_DDR = 0xFF;
	COLLUMN_DDR = 0xFF;
	
	//clear the data on them
	ROW_PORT = 0x00;
	COL_PORT = 0x00;
	
	//timer0 used for scrolling effect, and displaying the image.
	TCCR0 = (1<<CS02)|(0<<CS01)|(0<<CS00);
	TIMSK = (1<<TOIE0);
	
	sei();
}

void setPixel(uint8_t x, uint8_t y)
{
	ROW_PORT = ~(1<<x);
	COL_PORT = (1<<y);
}

void displayAscii(uint16_t *image)
{
	int i;
	for(i = 0;i<0x08;i++)
	{
		uint16_t data = image[i]<<7;
		COL_PORT = (data>>offset);
		ROW_PORT = ~(1<<i);
		_delay_ms(2);
	}
}

void put_c(volatile char character)
{
	uint16_t *temp_char = &(font[(8*(character-32) )] );
	displayAscii(temp_char);
}

ISR(TIMER0_OVF_vect, ISR_NOBLOCK)
{
	static unsigned int i;
	static unsigned int isr_count;
	static float interval;
	interval = (63*2)*scroll_speed;
	
	if( !(isr_count%(int)interval) )
	{
		offset = 0;
		if(name[i])
		{
			display_char = name[i];
			i++;
		}
		if(!name[i])
		{
			i = 0;
		}
	}
	if( !(isr_count%((int)interval/15)) && (offset <= 0xF0))
	{
		offset++;
	}
	isr_count++;
}
