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
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <linux/spi/spidev.h>

#include <bcm2835.h>
#include "libs/dht11.h"
#include "libs/adc_spi.h"
#include "libs/bmp085.h"

enum 
{
	DAYS=0,MONTHS,DATES,TIMES,YEARS
};
int main(void)
{
	bcm2835_init();
	
	//database directory.
	char database_dir[] = "databases";
	char database_ext[] = "csv";
	char database_filename[40];
	
	//date_time_info[0] = day. 1 = month. 2 = date. 3 = time. 4 = year.
	char *date_time_info[100]; 	
	int date_info_size = 5;
	char *tok;
	
	//buffers for string combining. and format printing.
	char csvLine[100];
	char fullPath[100];
	
	//variables for time keeping
	time_t current_time;
	char* c_time_string;
	
	//file operation variables.
	FILE *csvFile;	
	
	//adc variables adc value, and in and out going data buffers.
	uint16_t adcValue;
	uint8_t adc_receive[3] = {0,0,0};
	uint8_t adc_transmit[3] = {0,0,0};
	
	//dht11 readings.
	int dhtReads[2] = {0,0};
	int dhtTemperature = 0;
	int dhtHumidity = 0;
	
	//bmp085 variables.
	unsigned int temperature, pressure;
	while(1)
	{
		//obtain current time as seconds elapsed since epoch.
		current_time = time(NULL);
		if(current_time == ((time_t)-1))
		{
			fprintf(stderr, "Failure to computer the current time.");
			return EXIT_FAILURE;
		}
		//Convert to local time format.
		c_time_string = ctime(&current_time);
		if(c_time_string == NULL)
		{
			fprintf(stderr, "Failure to convert the current time.");
			return EXIT_FAILURE;
		}
		//print to see what w've got here.
		printf("Current time is: %s \n", c_time_string);
		//get individual time and dates.
		int i = 0;
		tok = strtok(c_time_string, " ");
		while(tok != NULL)
		{
			date_time_info[i++] = tok;
			tok = strtok(NULL, " ");
		}
		//there is a new line on the last item we don't want that so we change it to a '\0';
		date_time_info[YEARS][4] = '\0';
		//desplay items for debugging.
		for(i = 0;i < date_info_size;i++)
			printf("%s\n", date_time_info[i]);
		
		//create filename
		sprintf(database_filename, "%s_%s_%s_%s", date_time_info[DAYS], date_time_info[MONTHS], date_time_info[DATES], date_time_info[YEARS]);
		sprintf(fullPath, "%s/%s.%s", database_dir, database_filename, database_ext);
		//debug path printing it.
		printf("debugpath: %s\n", fullPath);
			
		//create a new file if it's not there. else we can append to it.
		csvFile = fopen(fullPath,"a+");
		//calibrate bmp085
		bmp085_Calibration();
		//read temperature
		temperature = bmp085_GetTemperature(bmp085_ReadUT());
		//divide by 10 to get actual pressure.
		temperature /= 10;
		//read pressure in Pa (Pascal)
		pressure = bmp085_GetPressure(bmp085_ReadUP());
		//print for debuggin purposes the temp and pressure.
		printf("BMP085: \npress:%d Pa, Temp: %d *C\n", pressure, temperature);
		//if the read returns -1, then we don't have valid data.
		while(readDHT(4,dhtReads)==-1);//wait while there is no valid data.
		//put the things we read into seperate values.
		dhtTemperature = dhtReads[0];
		dhtHumidity = dhtReads[1];
		printf("DHT11: \nTemp = %d *C, Hum = %d %%\n", dhtTemperature, dhtHumidity);
		//read in the adc value
		adcValue = adcReadChannel(CHANNEL1, adc_receive, adc_transmit);
		printf("adc val: %d\n", adcValue);
		//average our two temp readings.
		temperature = (temperature + dhtTemperature)/2;
		//create the line we will put into the csv file.
		sprintf(csvLine, "%s, %d, %d, %d, %d\n", date_time_info[TIMES], temperature, pressure, dhtHumidity, adcValue);
		
		if(!fputs(csvLine, csvFile))
		{
			printf("failed to write string to file \n");
		}
		printf("line written in .%s: \n%s\n%s\n", database_ext, csvLine,"time,temp,druk,humi,adc");
		//always close file, to write out the changes.
		printf("closing file\n");
		fclose(csvFile);
		sleep(600);
		//break;
	}
	return 0;
}
