/*
 * dht11 header file.
 * together with the dht11.c contains working code (none segfaulting) 
 * for reading a dht11.
 * 
 * */

#ifndef DHT11_H
#define DHT11_H

#define BCM2708_PERI_BASE 	0x20000000
#define GPIO_BASE 			(BCM2708_PERI_BASE + 0x200000)

#include <stdio.h>
#include <unistd.h>
#include <bcm2835.h>


#define MAXTIMINGS 1e3

int readDHT(int pin, int *readbuff);

#endif
