#include "DmDisplay/DmDisplay.h"

DmDisplay glcd;

const uint16_t dispCharWidth = 20;
const uint16_t dispCharHeight = 6;
const uint16_t frameBuffSize = dispCharHeight*dispCharWidth;
uint16_t frameBuff[frameBuffSize] = {};

void setup()
{
	//clear screen clear markers. and set half contrast.
	glcd.clear();
	glcd.clearMarkers();
	glcd.setContrast(16);
	glcd.setCursor(0,0);
	glcd.putStr("Some Text");
	glcd.setCursor(0,1);
	glcd.putChar('A');
	glcd.putChar('B');
	//glcd.drawRect(0,0,99,47,glcd.BLACK);
	//glcd.setCursor(0,1);
}
void loop()
{
}
