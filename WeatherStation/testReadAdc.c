#define SPI_BUFFER_SIZE 3

#include "libs/spi.c"
#include <stdio.h>
// Configuration bits for single-ended channel selection
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
	uint8_t adc_receive[SPI_BUFFER_SIZE];
	uint8_t adc_transmit[SPI_BUFFER_SIZE];
	
	for(i = 0;i<SPI_BUFFER_SIZE;i++)
	{
		adc_transmit[SPI_BUFFER_SIZE-i-1] = channel%256;
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
