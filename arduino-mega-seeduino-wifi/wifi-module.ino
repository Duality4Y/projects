/*
 * Author: Duality/Robert
 * Edited: 17-10-2014
 * 
 * testing the wifi modules and writing some code. 
 * ultimate goal! to have it connect to irc. (the dev board)
 * 
 * */

#define SSID 				"HuisVanDerTuuk"
#define PASS 				"10SamSung@H"
#define PORT 				"23"

#define COM(X) 				(X"\r\n")
#define AT_OK 				COM("AT")
#define AT_RST				COM("AT+RST")
#define AT_GMR 				COM("AT+GMR")
#define AT_CIFSR 			COM("AT+CIFSR")
#define AT_CWLAP 			COM("AT+CWLAP")

void setup()
{
	Serial.begin(115200);
	Serial3.begin(115200);
	Serial3.print(AT_OK);
	Serial3.print(AT_RST);
}
void loop()
{
	if(Serial.available() > 0)
		Serial3.write(Serial.read());
	if(Serial3.available() > 0)
		Serial.write(Serial3.read());
}
