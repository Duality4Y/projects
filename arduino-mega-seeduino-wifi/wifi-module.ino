/*
 * Author: Duality/Robert
 * Edited: 17-10-2014
 * 
 * testing the wifi modules and writing some code. 
 * ultimate goal! to have it connect to irc. (the dev board)
 * 
 * */
#define WIFI_MODULE_UART_SERIAL Serial3

#define SSID 				"HuisVanDerTuuk"
#define PASS 				"10SamSung@H"
#define PORT 				"23"

#define COM(X) 				(X"\r\n")
#define AT_CWJAP(S,P)		COM("AT+CWJAP=\""S"\",\""P"\"") //complicated .. :D
#define AT_CWMODE(X)		COM("AT+CWMODE="X)
#define AT_OK 				COM("AT")
#define AT_RST				COM("AT+RST")
#define AT_GMR 				COM("AT+GMR")
#define AT_CIFSR 			COM("AT+CIFSR")
#define AT_CWLAP 			COM("AT+CWLAP") //sending this somehow makes the wifi module stuck ?
#define AT_CIPSTATUS		COM("AT+CIPSTATUS")

char module_ready[] = "ready";
char module_ok[] = "OK";

/*Function what waits till it finds a keyword. for example, waiting for a ready.*/
void waitFor(char* str)
{
	//while(!Serial3.find((char*)"ready")){Serial.println("pass");};
	while( !(WIFI_MODULE_UART_SERIAL.find(str) ) );
}

void setup()
{
	Serial.begin(115200);
	Serial3.begin(115200);
	
	//Serial.print(AT_RST);
	//Serial.print(AT_CWJAP(SSID, PASS));
	//Serial.print(AT_CIFSR);
	
	Serial3.print(AT_RST);
	waitFor(module_ready);
	Serial.println("Resetted Module");
	Serial3.print(AT_CWJAP(SSID, PASS));
	waitFor(module_ok);
	Serial.println("Connected to ssid:");
	Serial.println(SSID);
}

void loop()
{
	
	while(Serial.available() > 0)
		Serial3.write(Serial.read());
	while(Serial3.available() > 0)
		Serial.write(Serial3.read());
}
