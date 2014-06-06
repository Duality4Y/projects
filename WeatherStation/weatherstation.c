/*
 * author: Duality/Robert
 * edited: 20-5-2014
 * created a basic implementation.
 * edited: 6-6-2014
 * worked on reading out sensors en implementing outputing
 * into csv files. with date for title.
 * and a time stamp in the file.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "dht11.c"
#include <bcm2835.h>
int main(void)
{
	bcm2835_init();
	
	time_t current_time;
	char* c_time_string;
	while(1)
	{
		while(readDHT(4)==0);
		sleep(1);
	}
	return 0;
}
