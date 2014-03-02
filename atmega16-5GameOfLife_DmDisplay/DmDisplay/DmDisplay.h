#ifndef DMDISPLAY_H
#define DMDISPLAY_H

#include <avr/io.h>
#include <util/delay.h>
#include <string.h>
#include "font5x7.h"
#include "pinDefs.h"

#undef abs 
#define abs(x, y) 		((x>y) ?  (x-y) : (y-x))
#define swap(a, b) 		do{a = a+b;b = a - b;a = a-b;}while(0);

class DmDisplay
{
	public:
		//constants.
		static const uint8_t WIDTH = 100;
		static const uint8_t HEIGTH = 48; //width and height in pixels.
		static const uint8_t MAXCONTRAST = 32; //maximum contrast value.
		static const uint8_t BLACK = 1;
		static const uint8_t WHITE = 0;
		//function prototypes.
		//for creating a instance.
		DmDisplay(void);
		//functions relating to putting text on display.
		void setMarker(uint8_t, bool);
		void lcdChar(const char *);
		void setCursor(uint8_t, uint8_t);
		void clear(void);
		void home(void);
		void setContrast(uint8_t);
		void clearMarkers(void);
		//was for debugging.
		void toggleEnable(void);
		uint8_t read();
		//graphical functions.
		void invertDisplay(bool);
		void writePixel(uint8_t, uint8_t, uint8_t);
		void drawArc(float, float, int, float, float);
		void drawCircle(uint8_t, uint8_t, uint8_t);
		void drawCircle(uint8_t, uint8_t, uint8_t, uint8_t);
		void drawLine(uint8_t, uint8_t, uint8_t, uint8_t);
		void drawLine(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawRect(uint8_t, uint8_t, uint8_t, uint8_t);
		void drawRect(uint8_t, uint8_t, uint8_t, uint8_t, uint8_t);
		void drawRoundRect(uint8_t, uint8_t, uint8_t , uint8_t, uint8_t, uint8_t);
		
		
		enum
		{
			INSTRUCT,DATA
		};
		
		void init(void);
		void toggleDisplayOnOff(bool);
		void blinkControlLines(void);
		void setCol(uint8_t col);
		void setRow(uint8_t);
		void resetRowAdress(void);
		void resetColumnAdress(void);
		void write(uint8_t, uint8_t);
		void setWriteReadAddres(uint8_t columnAddr, uint8_t page);
};

#include "DmDisplay.cpp"

#endif
