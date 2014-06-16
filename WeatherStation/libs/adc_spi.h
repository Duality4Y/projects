#ifndef ADC_SPI_H
#define ADC_SPI_H
/*
 * code for reading out mcp3208,
 * with a spi library written by me.
 * */

//we will only be sending and receiving 3 bytes.
#define SPI_BUFFER_SIZE 3
#include "spi.h"
#include <stdio.h>

#define START_BIT_POS		(18)
#define START_BIT			(1)
#define SINGLE_ENDED_SEL	(1)
#define DIFFRENTIAL_SEL		(0)

#define CHAN0_SEL			(0)
#define CHAN1_SEL			(1)
#define CHAN2_SEL			(2)
#define CHAN3_SEL			(3)
#define CHAN4_SEL			(4)
#define CHAN5_SEL			(5)
#define CHAN6_SEL			(6)
#define CHAN7_SEL			(7)

#define MODE_SEL SINGLE_ENDED_SEL

// Configuration bits for single-ended channel selection
#define CHANNEL0 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN0_SEL << (START_BIT_POS-4))
#define CHANNEL1 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN1_SEL << (START_BIT_POS-4))
#define CHANNEL2 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN2_SEL << (START_BIT_POS-4))
#define CHANNEL3 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN3_SEL << (START_BIT_POS-4))
#define CHANNEL4 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN4_SEL << (START_BIT_POS-4))
#define CHANNEL5 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN5_SEL << (START_BIT_POS-4))
#define CHANNEL6 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN6_SEL << (START_BIT_POS-4))
#define CHANNEL7 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN7_SEL << (START_BIT_POS-4))

int selectChannel(int);
uint16_t adcReadChannel(int, uint8_t *, uint8_t *);

#endif
