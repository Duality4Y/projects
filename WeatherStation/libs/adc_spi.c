#include "adc_spi.h"

int selectChannel(int chan)
{
	printf("chan: %d\n", chan);
	return (START_BIT << START_BIT_POS)|(MODE_SEL << (START_BIT_POS-1))|(chan << (START_BIT_POS-4));
}

uint16_t adcReadChannel(int chan, uint8_t *inData, uint8_t *outData)
{
	uint16_t adcValue;
	int spid,byte;
	//count to three, for three bytes.
	for(byte = 0;byte<3;byte++)
	{
		outData[3-byte-1] = chan%256; //get the value in least significant byte
		chan >>= 8; //shift by a byte
	}
	//open a connection to the spi
	spid = spiOpen("/dev/spidev0.0");
	spi_set_speed(spid, 4e6);
	//init with basic settings.
	spi_init(spid);
	//transmit our command bytes. and put what we receive in inData.
	transfer(spid, outData, inData);
	//always close your connection
	spiClose(spid);
	
	adcValue = (inData[1] << 8) + inData[2]; //get value out of received bytes. (second byte and third byte.)
	adcValue &= 0xFFF;//mask for a 12bit value.
	return adcValue;
}
