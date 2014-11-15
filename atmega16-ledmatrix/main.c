#include "matrix.h"
#include "uart.h"
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	initMatrixDisplay();
	//DISABLE_TIMER0_TICK;
	uart_init();
	name = uart_data;
	while(1)
	{
		//put_c(display_char);
		display(name);
	}
	return 0;
}
