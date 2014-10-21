/*
 * Author: Duality/Robert
 * Edited: 17-10-2014
 * 
 * testing the wifi modules and writing some code. 
 * ultimate goal! to have it connect to irc. (the dev board)
 * 
 * */
#define WIFI_MODULE_UART_SERIAL Serial3

#define SSID 				"www.tkkrlab.nl"
#define PASS 				"hax4or2the2paxor3"
#define PORT 				"23"

#define COM(X) 				(X"\r\n")

#define AT_OK 				COM("AT")
#define AT_RST				COM("AT+RST")
#define AT_GMR 				COM("AT+GMR")

#define AT_CWJAP(S,P)		COM("AT+CWJAP=\""S"\",\""P"\"") //complicated .. :D
#define AT_CWMODE(X)		COM("AT+CWMODE="X)
#define AT_CWLAP 			COM("AT+CWLAP")

#define AT_CIFSR 			COM("AT+CIFSR")
#define AT_CIPSTATUS		COM("AT+CIPSTATUS")
#define AT_CIPSTART			COM("AT+CIPSTART")
#define AT_CIPSEND			COM()
#define AT_CIPCLOSE			COM()
#define AT_CIPMUX()			COM()

char module_ready[] = "ready";
char module_ok[] = "OK";
char module_error[] = "ERROR";

const int inStr_size = 400;
char inputString[inStr_size];

void printDebug()
{
	while(Serial.available() > 0)
		Serial3.write(Serial.read());
	while(Serial3.available() > 0)
		Serial.write(Serial3.read());
}

/*Function what waits till it finds a keyword. for example, waiting for a ready.*/
void waitFor(char* str)
{
	while( !(Serial3.find(str)) );
}

void waitFor(char *str, void(*fp)())
{
	if( (fp) != NULL)
	{
		while(!(Serial3.find(str))) (*fp)();
	}
	else
	{
		return;
	}
}

void error_handle(void)
{
	Serial.println("no ip");
	delay(100);
	return;
}

void serial_clear(void)
{
	while(Serial.read() > 0) delay(100);
	while(Serial3.read() > 0) delay(100);
	return;
}

void setup()
{
	Serial.begin(115200);
	Serial3.begin(115200);
	
	serial_clear();
	Serial3.print(AT_RST);
	waitFor(module_ready);
	Serial.println("module ready");
	serial_clear();
	
	Serial3.print(AT_CWLAP);
}

void loop()
{
	while(Serial.available() > 0)
	{
		Serial3.write(Serial.read());
	}
	while(Serial3.available() > 0)
	{
		Serial.write(Serial3.read());
	}
}
