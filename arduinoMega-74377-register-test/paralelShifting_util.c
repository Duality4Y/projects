#include <stdio.h>
#include <avr/io.h>

#define BUS_DDR			DDRK
#define BUS_PORT		PORTK
#define BUS_PIN			PINK
#define BUS_INPUT		(BUS_DDR = 0x00)
#define BUS_OUTPUT		(BUS_DDR = 0xFF)
#define BUS_READ(x)		(x = BUS_PIN)
#define BUS_WRITE(x)	(BUS_PORT = x)

typedef struct
{
	/*controle line port and ddr*/
	volatile uint8_t *p_port;
	volatile uint8_t *p_ddr;
	/*controle lines.*/
	//write enable
	uint8_t we_pin;
	//clock pin
	uint8_t sck_pin;
} regData_t;

void setupRegister(regData_t*);
void paralelWrite(regData_t*, uint8_t data);

/*initializes pins to a default state. chip disabled.
 * and the clock in a low state.
 * */
void setupRegister(regData_t* reg)
{
	/*DDR to output*/
	*(reg->p_ddr) |= (1<< (reg->we_pin))|(1<< (reg->sck_pin));
	/* we_pin active low thus make it high by default.
	 * sck_pin triggers on rising, thus make it low by default.
	 * */
	 *(reg->p_port) |= (1<< (reg->we_pin));
	 *(reg->p_port) &= ~(1<< (reg->sck_pin));
	 /*clear the register once.*/
	 paralelWrite(reg, 0x00);
}

void paralelWrite(regData_t* reg, uint8_t data)
{
	/*put the bus to output.*/
	BUS_OUTPUT;
	/*put the data on the buss*/
	BUS_WRITE(data);
	/*enable the register.*/
	*(reg->p_port) &= ~(1<< (reg->we_pin));
	/*clock the data in*/
	*(reg->p_port) |= (1<< (reg->sck_pin));
	*(reg->p_port) &= ~(1<< (reg->sck_pin));
	/*disable the register*/
	*(reg->p_port) |= (1<< (reg->we_pin));
	/*clear the bus*/
	BUS_WRITE(0x00);
}

