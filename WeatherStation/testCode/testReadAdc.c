/*
 * this is testing code for reading out a adc (mcp3208 12bit adc)
 * */
#include <stdio.h>
#include "libs/adc_spi.h"
int main(void)
{
	uint16_t adcValue;
	//we will be sending and receiving 3 bytes.
	uint8_t adc_receive[3] = {0,0,0};
	uint8_t adc_transmit[3] = {0,0,0};
	while(1)
	{
		//read a value from channel 1 (second pin) and display the value.
		adcValue = adcReadChannel(CHANNEL1,adc_receive,adc_transmit);
		printf("Received Values: %02X, %02X\n", adc_receive[1], adc_receive[2]);
		printf("ADC = %5X (hex)\n", adcValue);
		printf("ADC = %5d (dec)\n", adcValue);
		printf("ADC Voltage = %g mV\n", (float) adcValue *3300/4096);
		sleep(1);
	}
	return 0;
}
