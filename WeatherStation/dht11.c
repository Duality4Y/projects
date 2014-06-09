#define BCM2708_PERI_BASE 	0x20000000
#define GPIO_BASE 			(BCM2708_PERI_BASE + 0x200000)

#include <stdio.h>
#include <unistd.h>
#include <bcm2835.h>


#define MAXTIMINGS 1e3

int readDHT(int pin);

int readDHT(int pin)
{
	int counter = 0;
	int laststate = HIGH;
	int bits[250];
	int data[100];
	int bitidx = 0;
	int j = 0;
	
	//set gpio to output
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_OUTP);
	
	bcm2835_gpio_write(pin, HIGH);
	usleep(500000);
	bcm2835_gpio_write(pin, LOW);
	usleep(20000);
	
	bcm2835_gpio_fsel(pin, BCM2835_GPIO_FSEL_INPT);
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
	
	//wait for pin to drop
	while(bcm2835_gpio_lev(pin) == 1)
	{
		usleep(1);
	}
	
	//read the data
	int i;
	for(i=0;i<MAXTIMINGS;i++)
	{
		counter = 0;
		while(bcm2835_gpio_lev(pin) == laststate)
		{
			counter++;
			if(counter == 1000) break;
		}
		laststate = bcm2835_gpio_lev(pin);
		if(counter == 1000) break;
		bits[bitidx++] = counter;
		//for every other bit.
		if((i>3) && (i%2 == 0))
		{
			//shove each bit into the storage bytes.
			data[j/8] <<= 1;
			if(counter > 200) data[j/8] |= 1;
			j++;
		}
	}
	
	//printf("Data (%d): 0x%x, 0x%x, 0x%x, 0x%x, 0x%x\n", j, data[0], data[1], data[2], data[3], data[4]);
	if((j>= 39) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) )
	{
		printf("Temp = %d *C, Hum = %d %%\n", data[2], data[0]);
		return 1;
	}
	
	return 0;
}
