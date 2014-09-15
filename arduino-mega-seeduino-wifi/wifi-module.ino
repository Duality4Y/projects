#include <avr/io.h>
#include <util/delay.h>

#define SSID "GOGBOT2014"

void setup()
{
	Serial.begin(57600);
	Serial1.begin(57600);
	pinMode(13, OUTPUT);
	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
	pinMode(10, OUTPUT);
	digitalWrite(13, HIGH);
	digitalWrite(12, HIGH);
	digitalWrite(11, HIGH);
	digitalWrite(10, HIGH);
}
void loop()
{
	Serial1.println("AT+RST");
}
