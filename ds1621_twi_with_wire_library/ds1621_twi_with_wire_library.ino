/*

Code for controling a ds1621
reading tempratures with a Arduino
using the Wire library.

author: Duality / Robert
edited: 1-12-2013
*/

//make use of Wire library.
#include <Wire.h>


//create a class for easely work with multiple sensors if we wanted to.

class DS1621
{
  public:
    uint8_t address;
    
    uint8_t config_acces;
    uint8_t continuousMode;
    uint8_t oneShotMode;
    uint8_t startConversion;
    uint8_t read_temp;
    uint8_t oneShot;
    
    uint8_t control;
    uint8_t dev_id;
    
    DS1621(uint8_t);
    void init_continuous();
    void init_oneShot();
    float readTemperature();
    float readFarenheit();
};

DS1621::DS1621(uint8_t address_)
{
  address = address_;
  
  //setup usage variables.
  config_acces = 0xAC;
  
  continuousMode = 0x00; //there are no flags zet.
  oneShotMode = 0x01; //sets oneshot flag to 1.
  
  startConversion = 0xEE;
  oneShot = false;
  read_temp = 0xAA;
  
  control = 0x90;
  dev_id = (control>>1)|address;  //created a device id.
}

//this function initializes the ds1621.
//by setting its configuration register.
//and starting conversions.
void DS1621::init_continuous()
{
  Wire.begin();                   //join the i2c buss.
  Wire.beginTransmission(dev_id); //connect to ds1621
  Wire.write(config_acces);       //acces config
  Wire.write(continuousMode);     //set ds1621 in continuous Mode.
  Wire.beginTransmission(dev_id); //restart i2c
  Wire.write(startConversion);    //start conversions
  Wire.endTransmission();         //give back the i2c buss.
}

void DS1621::init_oneShot()
{
  Wire.begin();                    //join the i2c buss.
  Wire.beginTransmission(dev_id);  //connect to ds1621.
  Wire.write(config_acces);        //acces config
  Wire.write(oneShotMode);         //set ds1621 in oneShotMode.
  Wire.beginTransmission(dev_id);  //reset the i2c buss.
  Wire.write(startConversion);
  Wire.endTransmission();          //give back the i2c buss.
  oneShot = true;
}

//returns the temperature in celcius.
float DS1621::readTemperature()
{
  int temperature = 0;
  int precision = 0;
  
  //give the ds1621 time to measure.
  
  if(oneShot)
  {
    Wire.beginTransmission(dev_id);
    Wire.write(startConversion);
    Wire.endTransmission(dev_id);
    //need to wait aprox 750ms for a conversion.
    delay(750);
  }
  Wire.beginTransmission(dev_id); //connect to ds1621
  Wire.write(read_temp);  //tell the ds1621 that we want a reading.
  Wire.endTransmission(); //give back the i2c buss.
  
  //request two bytes. first is the temperature in celcius.
  //the second byte is the precision. if it is 0x80 its + 0.5
  //else it is just .0
  
  Wire.requestFrom((int)dev_id, 2); //cast dev_id to int, because requestFrom() wants a int.
  temperature = Wire.read(); //read first byte, being temperature.
  precision = Wire.read(); //read second byte, being the precision.
  //apply and return values.
  //if second byte (precision) == 0x80, append 0.5.
  if(precision == 0x80)
  {
    return temperature+0.5;
  }
  else
  {
    return temperature;
  }
}
//returns the temperature in farenheit.
float DS1621::readFarenheit()
{
  int temperature = readTemperature();
  return (temperature*9)/5+32;
}

//create an instance of ds1621
DS1621 tempSensor(0x04);

//for timing purposes.
unsigned long current = 0;
unsigned long previous = 0;
int interval = 1000;

//for measuring purposes.
float celcius = 0;
float farenHeit = 0;

void setup()
{
  //serial print temperature.
  Serial.begin(9600);
  //init the temp chip.
  tempSensor.init_continuous();
}
void loop()
{
  //collect readings
  celcius = tempSensor.readTemperature();
  farenHeit = tempSensor.readFarenheit();
  //print readings ones a second.
  current = millis();
  if((current - previous) >= interval)
  {
    previous = current;
    Serial.print("Celcius: ");
    Serial.print(celcius);
    Serial.print(" FarenHeit: ");
    Serial.println(farenHeit);
  }
}
