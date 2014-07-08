#include <ctype.h>
#include "DmDisplay/DmDisplay.h"

DmDisplay glcd;

uint8_t buttonPin = 12;
uint8_t tick = 0;

const uint8_t dispWidth = 20;
const uint8_t dispHeight = 6;
const uint8_t frameBuffSize = dispHeight*dispWidth;
uint8_t frameBuff[frameBuffSize+1] = 
{
" ___     _          "
"| _ \\___| |__  ___  "
"|   / _ \\ '_ \\/ -_) "
"|_|_\\___/_.__/\\___| "
"                    "
"                    "
};

uint8_t printBuf[dispWidth] = "";

uint8_t textIndex = 0;
const uint8_t textBuffSize = frameBuffSize*2;
char textBuff[textBuffSize]="";

uint8_t stackIndex = 0;
const uint8_t stackSize = frameBuffSize*2;
uint8_t stack[stackSize] = "";

int displayBuffOnScreen(uint8_t *buffer, int size)
{
	static long previous = 0;
	static long current = 0;
	const static uint8_t interval = 20;
	
	int index = 0;
	
	current = millis();
	
	if(current - previous >= interval)
	{
		previous = current;
		for(int j = 0;j<6;j++)
		{
			for(int i = 0;i<20;i++)
			{
				glcd.setCursor(i,j);
				glcd.putChar(buffer[index]-32);
				index++;
			}
		}
		return 1;
	}
	return 0;
}


void readSerialToFrameBuffer()
{
	static int frame_index=0;
	while(Serial1.available() > 0)
	{
		uint8_t inbyte = Serial1.read();
		if(inbyte == 128)
		{
			glcd.setCursor(0,0);
			frame_index = 0;
		}
		else if(!iscntrl(inbyte))
		{
			Serial1.write(inbyte);
			frameBuff[frame_index++] = inbyte;
			if(frame_index == frameBuffSize) frame_index = 0;
		}
	}
}
//source is a line placed in dest, at line number linenum.
void setLine(uint8_t linenum, uint8_t *dest, uint8_t *source)
{
	uint8_t length = strlen((const char*)source);
	memcpy(dest+(linenum*dispWidth), source, length);
}

void serialEvent1()
{
	uint8_t inbyte = Serial1.read();
	Serial1.write(inbyte);
	if(!iscntrl(inbyte))
	{
		textBuff[textIndex++] = inbyte;
		if(textIndex == textBuffSize) textIndex = 0;
	}
}

uint8_t pop()
{
	uint8_t temp = 0;
	if(stackIndex > 0)
	{
		temp = stack[--stackIndex];
		stack[stackIndex] = '\0';
		return temp;
	}
	else
	{
		return NULL;
	}
}

void* push(uint8_t item)
{
	if(stackIndex < stackSize)
	{
		stack[stackIndex++] = item;
		stack[stackIndex] = '\0';
		return 0;
	}
	else
	{
		return NULL;
	}
}


void printStats()
{
	static int i = 0;
	sprintf((char*)printBuf, "i: %d", i);
	setLine(0, frameBuff, printBuf);
	sprintf((char*)printBuf, "textBuf: %s", textBuff);
	setLine(1, frameBuff, printBuf);
	sprintf((char*)printBuf, "tick: %d", tick);
	setLine(2, frameBuff, printBuf);
	sprintf((char *)printBuf, "stack: %s", stack);
	setLine(3, frameBuff, printBuf);
	i++;
}
//buss port
#define BUS_DDR					DDRA
#define BUS_PORT				PORTA
#define BUS_PORT_IN				PINA

#define BUS_INPUT				(BUS_DDR = 0x00)
#define BUS_OUTPUT				(BUS_DDR = 0xFF)

#define BUS_WRITE(X)			(PORTA = X)
#define BUS_READ				(PINA)

//pin defs for the buss
/*Controle lines*/
#define CONTROLE_LINE_DDR		DDRJ
#define CONTROLE_LINE_PORT		PORTJ

/*enable pins.*/
#define LSB_REG_ENABLE_PIN		PJ5
#define LSB_REG_CP_PIN			PJ2

#define LSB_REG_CP_INPUT		(CONTROLE_LINE_DDR &= ~(1<<LSB_REG_CP_PIN))
#define LSB_REG_ENABLE_INPUT	(CONTROLE_LINE_DDR &= ~(1<<LSB_REG_CP_PIN))
#define LSB_REG_CP_OUTPUT		(CONTROLE_LINE_DDR |= (1<<LSB_REG_CP_PIN))
#define LSB_REG_ENABLE_OUTPUT	(CONTROLE_LINE_DDR |= (1<<LSB_REG_ENABLE_PIN))
//clock is on rising edge
#define LSB_REG_SET_CP 			(CONTROLE_LINE_PORT |= (1<<LSB_REG_CP_PIN))
#define LSB_REG_CLEAR_CP		(CONTROLE_LINE_PORT &= ~(1<<LSB_REG_CP_PIN))
//enable is active low.
#define LSB_REG_SET_ENABLE		(CONTROLE_LINE_PORT &= ~(1<<LSB_REG_ENABLE_PIN))
#define LSB_REG_CLEAR_ENABLE	(CONTROLE_LINE_PORT |= (1<<LSB_REG_ENABLE_PIN))

/*clock pins.*/
#define MSB_REG_ENABLE_PIN		PJ4
#define MSB_REG_CP_PIN			PJ3

#define MSB_REG_CP_INPUT		(CONTROLE_LINE_DDR &= ~(1<<MSB_REG_CP_PIN))
#define MSB_REG_ENABLE_INPUT	(CONTROLE_LINE_DDR &= ~(1<<MSB_REG_ENABLE_PIN))
#define MSB_REG_CP_OUTPUT		(CONTROLE_LINE_DDR |= (1<<MSB_REG_CP_PIN))
#define MSB_REG_ENABLE_OUTPUT	(CONTROLE_LINE_DDR |= (1<<MSB_REG_ENABLE_PIN))
//clock is on rising edge
#define MSB_REG_SET_CP			(CONTROLE_LINE_PORT |= (1<<MSB_REG_CP_PIN))
#define MSB_REG_CLEAR_CP		(CONTROLE_LINE_PORT &= ~(1<<MSB_REG_CP_PIN))
//enable is active low.
#define MSB_REG_SET_ENABLE		(CONTROLE_LINE_PORT &= ~(1<<MSB_REG_ENABLE_PIN))
#define MSB_REG_CLEAR_ENABLE	(CONTROLE_LINE_PORT |= (1<<MSB_REG_ENABLE_PIN))

/*ram controle lines.*/
#define WRITE_ENABLE_PIN		PJ7
#define OUTPUT_ENABLE_PIN		PJ6

#define WRITE_ENABLE_OUTPUT		(CONTROLE_LINE_DDR |= (1<<WRITE_ENABLE_PIN))
#define WRITE_ENABLE_INPUT		(CONTROLE_LINE_DDR &= ~(1<<OUTPUT_ENABLE_PIN))
#define OUTPUT_ENABLE_OUTPUT
#define OUTPUT_ENABLE_INPUT
/*both writeEnable and outputEnable are active low*/
#define SET_WRITE_ENABLE 
#define CLEAR_WRITE_ENABLE
#define SET_OUTPUT_ENABLE
#define CLEAR_OUTPUT_ENABLE

void writeLsbRegister(uint8_t data)
{
	/*first setup the bus to output*/
	BUS_OUTPUT;
	/*controle lines to output*/
	LSB_REG_CP_OUTPUT;
	LSB_REG_ENABLE_OUTPUT;
	/*put lsb of address into buss and put it in lsb register.*/
	BUS_PORT = data;
	/*enable the chip*/
	LSB_REG_SET_ENABLE;
	/*clock the data in*/
	LSB_REG_SET_CP;
	LSB_REG_CLEAR_CP;
	LSB_REG_CLEAR_ENABLE;
}
void writeMsbRegister(uint8_t data)
{
	/*first setup the bus to output*/
	BUS_OUTPUT;
	/*controle lines to output*/
	LSB_REG_CP_OUTPUT;
	LSB_REG_ENABLE_OUTPUT;
	/*put lsb of address into buss and put it in lsb register.*/
	BUS_PORT = data;
	/*enable the chip*/
	LSB_REG_SET_ENABLE;
	/*clock the data in*/
	LSB_REG_SET_CP;
	LSB_REG_CLEAR_CP;
	LSB_REG_CLEAR_ENABLE;
}

void writeRamData(uint16_t address, uint8_t data)
{
	/*write the data for lsb address part*/
	writeLsbRegister(address&0xFF);
	/*write the data for msb address part*/
	writeMsbRegister(address&0xFF);
	
	/*set ram chip controle lines in the right mode*/
	WRITE_ENABLE_OUTPUT;
	OUTPUT_ENABLE_OUTPUT;
	CLEAR_OUTPUT_ENABLE; //keep read pin high
	/*put the ram chip in the correct mode*/
	SET_WRITE_ENABLE;
}

uint8_t readRamData(uint16_t address)
{
	
}

void setupRamPins()
{
	//all pins to input.
	
}

void setup()
{
	Serial1.begin(115200);
	Serial1.println(">> Start \n");
	Serial.begin(9600);
	
	pinMode(12, INPUT);
	digitalWrite(12, HIGH);
	
	//clear screen clear markers. and set half contrast.
	glcd.clear();
	glcd.clearMarkers();
	glcd.setContrast(16);
	glcd.setCursor(0,0);
	
	//make sure we atleast display it once (looks nice)
	while(!displayBuffOnScreen(frameBuff, frameBuffSize));
	delay(1000);
	//clear framebuffer
	memset(frameBuff, ' ', frameBuffSize);
	//clear text buffer
	memset(textBuff, '\0', textBuffSize);
	
}

void loop()
{
	
}

/*
void loop()
{
	printStats();
	
	//parse the text buffer.
	//uint8_t index = 0;
	//while(textBuff[index] != '\0');
	if(!digitalRead(12))
	{
		tick++;
		while(!digitalRead(12));
	}
	displayBuffOnScreen(frameBuff, frameBuffSize);
}
*/
