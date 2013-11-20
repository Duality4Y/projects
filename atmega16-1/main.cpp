//clock speed 8mhz
#define F_CPU 8000000

#include <avr/io.h>
#include <util/delay.h>

#include <string.h>
#include <stdio.h>
#include "DmDisplay.h"

DmDisplay lcd;

void writeLCDcontrast(int contrastVal)
{
	char str[21];
	sprintf(str, " -> Contrast: %d    ", contrastVal);
	lcd.lcdChar(str);
}
void writeSomeTestText()//DmDisplay display)
{
	lcd.setRow(1);
	lcd.lcdChar("012345678901234567890");
	lcd.setRow(2);
	lcd.lcdChar("ABCDEFGHIJKLMNPQRSTUV");
	lcd.setRow(3);
	lcd.lcdChar("wxyzabcdefghijklmnopq");
	lcd.setRow(4);
	lcd.lcdChar("  !#$%&'( )@^-");
	lcd.setRow(5);
	lcd.lcdChar("  *+-/<>?;:[]");
	lcd.setRow(6);
	lcd.lcdChar("* AVR rules !! *");
}

int main(void)
{
	//while(1)
	//{
		//writeSomeTestText();
		//_delay_ms(2000);
		//for (int l = 0; l <= 3; l++)
		//{
			//for (uint8_t i = 1; i <= 6; i++) 
			//{
				//lcd.setMarker(i, true);
				//_delay_ms(400);
				//lcd.setMarker(i, false);
				//_delay_ms(100);
			//}
		//}
		//lcd.setRow(6);
		//for(uint8_t j = 1; j <= 4; j++) 
		//{
			//lcd.invertDisplay(true);
			//_delay_ms(800);
			//lcd.lcdChar("*-*-LCD REVERSED-*-*");
			//lcd.invertDisplay(false);
			//_delay_ms(800);
			//lcd.resetColumnAdress();
			//lcd.lcdChar("#-#-#-LCD NORMAL-#-#");
			//lcd.invertDisplay(true);
		//}


		//for (int k = 0; k < 32; k++)
		//{
			//writeLCDcontrast(k);
			//lcd.setContrast(k);
			//_delay_ms(250);
		//}
		//for (int k = 31; k >= 0; k --) {
			//writeLCDcontrast(k);
			//lcd.setContrast(k);
			//_delay_ms(250);
		//}
			//writeLCDcontrast(16);
			//lcd.setContrast(16);
	//}
	while(1)
	{
		lcd.write(0xFF, lcd.DATA);
	}
	return 0;
}
