//blink.c

#include <bcm2835.h>

#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
	if(!bcm2835_init())
		return 1;
	bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);
	while(1)
	{
		bcm2835_gpio_write(PIN, HIGH);
		delay(500);
		bcm2835_gpio_write(PIN, LOW);
		delay(500);
	}
}
