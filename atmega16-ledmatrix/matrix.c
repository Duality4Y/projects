#include "matrix.h"
#include "font.h"
#include "uart.h"

//the to display text.
volatile char *name = "Tkkrlab";
//offset used in shifting the letters across the display.
volatile uint8_t offset = 0;

//holds data that is displayed on the screen
volatile unsigned char display_char = ' ';

//scroll_speed , how long it takes to scroll by
volatile float scroll_speed = 2;

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

void testShift(volatile uint8_t *image, uint8_t direction)
{
	unsigned int i = 0;
	for(i = 0;i<0x08;i++)
	{
		if(direction)
		{
			image[i] = (image[i]<<7)|(image[i]>>1);
		}
		else
		{
			image[i] = (image[i]<<1)|(image[i]>>7);
		}
	}
}

void display(volatile uint8_t *image)
{
	volatile uint8_t i, data;
	for(i = 0;i<0x08;i++)
	{
		COL_PORT = 0x00;
		ROW_PORT = 0xFF;
		
		data = image[i];
		
		COL_PORT = data;
		ROW_PORT = ~(1<<i);
		_delay_ms(2);
	}
}

void put_c(volatile char character)
{
	uint8_t *temp_char = &(font[(8*(character-32) )] );
	display(temp_char);
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
		if(name[i] && isprint(name[i]))
		{
			display_char = name[i];
			i++;
		}
		if(!name[i])
		{
			i = 0;
		}
	}
	if( !(isr_count%((int)interval/16)) && (offset <= 0x10))
	{
		offset++;
		//testShift(name);
	}
	isr_count++;
}
