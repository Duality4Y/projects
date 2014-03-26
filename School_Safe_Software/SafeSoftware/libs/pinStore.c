/*
 * this code is related to storeing the pincode into eeprom.
 * */

void initPin()
{
	pin = readPin();
}

void storePin(int pin)
{
	uint8_t highByte = (pin>>8);
	uint8_t lowByte = (pin&0xFF);
	eeprom_write_byte(0, highByte);
	eeprom_write_byte((uint8_t *)1, lowByte);
}

int readPin()
{
	uint8_t highByte = eeprom_read_byte((uint8_t *)0);
	uint8_t lowByte = eeprom_read_byte((uint8_t *)1);
	return (highByte<<8) | (lowByte);
}
