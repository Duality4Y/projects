/*
Raspberry Pi Bosch BMP085 communication code.
By:      John Burns (www.john.geek.nz)
Date:    01 August 2012
License: CC BY-SA v3.0 - http://creativecommons.org/licenses/by-sa/3.0/

This is a derivative work based on:
   BMP085 Extended Example Code
   by: Jim Lindblom
   SparkFun Electronics
   date: 1/18/11
   license: CC BY-SA v3.0 - http://creativecommons.org/licenses/by-sa/3.0/
   Source: http://www.sparkfun.com/tutorial/Barometric/BMP085_Example_Code.pde

Compile with: gcc -Wall -o testBMP085 ./smbus.c ./testBMP085.c


Circuit detail:
   Using a Spark Fun Barometric Pressure Sensor - BMP085 breakout board
   link: https://www.sparkfun.com/products/9694
   This comes with pull up resistors already on the i2c lines.
   BMP085 pins below are as marked on the Sparkfun BMP085 Breakout board

   SDA   -    P1-03 / IC20-SDA
   SCL   -    P1-05 / IC20_SCL
   XCLR   -    Not Connected
   EOC   -   Not Connected
   GND   -   P1-06 / GND
   VCC   -    P1-01 / 3.3V
   
   Note: Make sure you use P1-01 / 3.3V NOT the 5V pin.
*/

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include "libs/bmp085.h"

//will hold the good values.
unsigned int temperature, pressure, altitude;

int main(int argc, char **argv)
{

	bmp085_Calibration();

	temperature = bmp085_GetTemperature(bmp085_ReadUT());
	pressure = bmp085_GetPressure(bmp085_ReadUP());
	altitude = bmp085_Altitude(pressure);

	printf("Temperature\t%0.1f *F\n", ((double)temperature)/10 * 1.8 + 32);
	printf("Pressure\t%0.2f hPa\n", ((double)pressure)/100);
	printf("Altitude\t%0.1f Feet\n", ((double)altitude)*3.280839895);

	return 0;
}
