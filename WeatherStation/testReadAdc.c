/*
 * this is testing code for reading out a adc (mcp3208 12bit adc)
 * */

//we will only be sending and receiving 3 bytes.
#define SPI_BUFFER_SIZE 3

#include "libs/spi.h"
#include <stdio.h>

#define START_BIT_POS		(18)
#define START_BIT			(1<<2)
#define SINGLE_ENDED_SEL	(1<<1)
#define DIFFRENTIAL_SEL		(0<<1)
#define CHAN0_SEL			(0<<0)
#define CHAN1_SEL			(1<<0)
#define CHAN2_SEL			(1<<1)
#define CHAN3_SEL			((1<<1)|(1<<0))
#define CHAN4_SEL			(1<<2)
#define CHAN5_SEL			((1<<2)|(1<<0))
#define CHAN6_SEL			((1<<2)|(1<<1))

#define MODE_SEL SINGLE_ENDED_SEL

// Configuration bits for single-ended channel selection
//16 shift represent first byte out. 8 shifts is second byte out no shifts first byte out.
/*
#define CHANNEL0 (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(CHAN0_SEL << (START_BIT_POS-2))
#define CHANNEL1
#define CHANNEL2
#define CHANNEL3
#define CHANNEL4
#define CHANNEL5
#define CHANNEL6
#define CHANNEL7
* */

#define CHANNEL0 0x060000   // Channel 0
#define CHANNEL1 0x064000   // Channel 1
#define CHANNEL2 0x068000   // Channel 2
#define CHANNEL3 0x06C000   // Channel 3
#define CHANNEL4 0x070000   // Channel 4
#define CHANNEL5 0x074000   // Channel 5
#define CHANNEL6 0x078000   // Channel 6
#define CHANNEL7 0x07C000   // Channel 7

int main(void)
{
	int spid;
	int ret = 0,i;
	uint16_t adcValue;
	uint32_t channel = CHANNEL0;
	//we will be sending and receiving 3 bytes.
	uint8_t adc_receive[3];
	uint8_t adc_transmit[3];
	
	for(i = 0;i<3;i++)
	{
		adc_transmit[3-i-1] = channel%256;
		channel >>= 8;
	}
	while(1)
	{
		spid = spiOpen("/dev/spidev0.0");
		spi_init(spid);
		
		transfer(spid, adc_transmit, adc_receive);
		
		adcValue = (adc_receive[1] << 8) + adc_receive[2];
		adcValue &= 0xFFF;
		printf("Received Values: %02X, %02X \n", adc_receive[1], adc_receive[2]);
		printf("ADC = %5X (hex)\n", adcValue);
		printf("ADC = %5d (dec)\n", adcValue);
		printf("ADC Voltage = %g mV\n", (float) adcValue *3300/4096); 
		
		spiClose(spid);
		sleep(1);
	}
	return ret;
}
