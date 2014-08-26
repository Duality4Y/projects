#include "paralelShifting_util.c"
/*setup connections to the first register.*/
regData_t msb_reg = {&PORTA, &DDRA, PA0, PA2};
regData_t lsb_reg = {&PORTA, &DDRA, PA1, PA2};

#define RAM_PORT	(PORTA)
#define RAM_DDR		(DDRA)

#define RAM_CE		(PA5)
#define RAM_OE		(PA4)
#define RAM_WE		(PA3)

#define RAM_OUTPUT	(RAM_DDR |= (1<<RAM_CE)|(1<< RAM_OE)|(1<< RAM_WE))

#define SET_CE_HIGH	(RAM_PORT |= (1<<RAM_CE))
#define SET_CE_LOW	(RAM_PORT &= ~(1<<RAM_CE))
#define SET_OE_HIGH	(RAM_PORT |= (1<<RAM_OE))
#define SET_OE_LOW	(RAM_PORT &= ~(1<<RAM_OE))
#define SET_WE_HIGH	(RAM_PORT |= (1<<RAM_WE))
#define SET_WE_LOW	(RAM_PORT &= ~(1<<RAM_WE))

void setupRam()
{
	RAM_OUTPUT;
	SET_CE_HIGH;
	SET_OE_HIGH;
	SET_WE_HIGH;
}
//sets address onto the addres buss.
void setRamAddr(uint16_t address)
{
	//first writes the low order byte, after that the high order byte.
	paralelWrite(&lsb_reg, address&0xFF);
	paralelWrite(&msb_reg, address>>8); 
}
//writes out data.
void writeToRam(uint16_t addr, uint8_t data)
{
	SET_OE_HIGH;
	BUS_OUTPUT;
	setRamAddr(addr);
	SET_CE_LOW;
	BUS_WRITE(data);
	SET_WE_LOW;
	SET_WE_HIGH;
	SET_CE_HIGH;
	BUS_INPUT;
}

uint8_t readRam(uint16_t addr)
{
	setRamAddr(addr);
	BUS_INPUT;
	SET_CE_LOW;
	SET_WE_HIGH;
	SET_OE_LOW;
	asm volatile(
	"nop\n\t"
	::);
	uint8_t byte = PINK;
	SET_OE_HIGH;
	SET_CE_HIGH;
	return byte;
}

void writeRam(uint8_t byte, uint16_t addr)
{
	while(readRam(addr) != byte)
	{
		writeToRam(addr, byte);
	}
}

char test[] = "\nthis is a string\n";

int i = 0;
unsigned long current = 0;
void setup()
{
	Serial.begin(9600);
	setupRam();
	setupRegister(&msb_reg);
	setupRegister(&lsb_reg);
	Serial.print("writing current millis: ");
	Serial.println(current = millis());
	for(int i = 0;i<32767;i++)
	{
		//Serial.print(i);
		writeRam(i,i);
	}
	current = millis()-current;
	Serial.print("writing took: ");
	Serial.println(current);
	Serial.println("Reading: ");
	byte check = 0x00;
	for(int i = 0;i<32767;i++)
		check ^= (readRam(0xFF));
	current = millis()-current;
	Serial.print("reading took: ");
	Serial.println(current);
	Serial.print("check byte: ");
	Serial.println(check, HEX);
}
void loop()
{
}
