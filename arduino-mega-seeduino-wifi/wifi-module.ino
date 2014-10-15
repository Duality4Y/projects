#define WIFI_BAUD 115200
#define SERIAL_BAUD 115200

#define WIFI_SERIAL Serial3

void setup()
{
	Serial.begin(115200);
	WIFI_SERIAL.begin(115200);
}
void loop()
{
	if(Serial.available() > 0)
		WIFI_SERIAL.write(Serial.read());
	if(WIFI_SERIAL.available() > 0)
		Serial.write(WIFI_SERIAL.read());
}
