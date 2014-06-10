/*
 * author: Robert/Duality
 * git: github.com/duality4y
 * 
 * source inspired by:
 * http://www.brianhensley.net/2012/07/getting-spi-working-on-raspberry-pi.html
 * 
 * also verry usefull little document:
 * http://lxr.free-electrons.com/source/include/uapi/linux/spi/spidev.h#L52
 * 
 * a rewrite to make it more like a "library"
 * for easier use.
 * 
 * this source is for communicating of the spi. that the raspberrypi offers.
 * 
 * for a test you could run this for example:
 * int main(int argc, char *argv[])
 *{
 *	int spid;
 *	spid = spiOpen(device);
 *	spi_init(spid);
 *	printSpiDetails();
 *	loopbackTest(spid);
 *	transfer(spid,0x13);
 *	transfer(spid,0x37);
 *	spiClose(spid);
 *	return 0;
 *}
 *
 * 
 * */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/spi/spidev.h>

#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))

//static const char *spi_device = "/dev/spidev0.0";
static uint8_t spi_mode = 0;
static uint8_t spi_bits = 8;
static uint32_t spi_speed = 500000;
static uint16_t spi_delay = 0;

static void pabort(const char *s);
static uint8_t transfer(int, uint8_t);
static int spi_set_mode(int, int);
static int spi_set_word(int, int);
static int spi_set_speed(int, int);
static void spi_set_delay(int);
static void loopbackTest(int);
static int spiOpen(const char*);
static void spiClose(int);
static void spi_init(int);
static void printSpiDetails();


