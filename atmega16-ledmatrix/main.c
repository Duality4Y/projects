#include "matrix.h"
#include "uart.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(void)
{
	initMatrixDisplay();
	//DISABLE_TIMER0_TICK;
	uart_init();
	while(1)
	{
		display(uart_data);
	}
	return 0;
}
