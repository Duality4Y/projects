/*
 * this is code for reading a bmp085 with your raspberry pi.
 * written by Duality/Robert
 * github.com/duality4y
 * 
 * comment header original source:
 * 
 * Raspberry Pi Bosch BMP085 communication code.
 * By:      John Burns (www.john.geek.nz)
 * Date:    01 August 2012
 * License: CC BY-SA v3.0 - http://creativecommons.org/licenses/by-sa/3.0/
 *
 * This is a derivative work based on:
 *   BMP085 Extended Example Code
 *   by: Jim Lindblom
 *   SparkFun Electronics
 *   date: 1/18/11
 *   license: CC BY-SA v3.0 - http://creativecommons.org/licenses/by-sa/3.0/
 *   Source: http://www.sparkfun.com/tutorial/Barometric/BMP085_Example_Code.pde*
 *
 * Compile with: gcc -Wall -o testBMP085 ./smbus.c ./testBMP085.c
 *
 *
 * Circuit detail:
 *   Using a Spark Fun Barometric Pressure Sensor - BMP085 breakout board
 *   link: https://www.sparkfun.com/products/9694
 *   This comes with pull up resistors already on the i2c lines.
 *   BMP085 pins below are as marked on the Sparkfun BMP085 Breakout board
 *
 *   SDA   -    P1-03 / IC20-SDA
 *   SCL   -    P1-05 / IC20_SCL
 *   XCLR   -    Not Connected
 *   EOC   -   Not Connected
 *   GND   -   P1-06 / GND
 *   VCC   -    P1-01 / 3.3V
 *   
 *   Note: Make sure you use P1-01 / 3.3V NOT the 5V pin.
 * 
 * */

#ifndef BMP085_H
#define BMP085_H

#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>

#define BMP085_I2C_ADDRESS 0x77

extern const unsigned char BMP085_OVERSAMPLING_SETTING;

// Calibration values - These are stored in the BMP085
short int ac1;
short int ac2;
short int ac3;
unsigned short int ac4;
unsigned short int ac5;
unsigned short int ac6;
short int b1;
short int b2;
short int mb;
short int mc;
short int md;
int b5;

int bmp085_i2c_Begin();
__s32 bmp085_i2c_Read_Int(int, __u8);
void bmp085_i2c_Write_Byte(int, __u8, __u8);
void bmp085_i2c_Read_Block(int fd, __u8 address, __u8 length, __u8 *values);
void bmp085_Calibration();
unsigned int bmp085_ReadUT();
unsigned int bmp085_ReadUP();
unsigned int bmp085_GetPressure(unsigned int);
unsigned int bmp085_GetTemperature(unsigned int);
unsigned int bmp085_Altitude(float);


#endif
