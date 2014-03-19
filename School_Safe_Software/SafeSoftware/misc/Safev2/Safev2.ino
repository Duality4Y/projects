/*
  Name: Darrel Griët
  Date: 20-2-2014
  Project: Safe control v0.1 pre-alpha
  (Size: 9,900 bytes)
  Release Notes:
    0.1:
        IT WORKS ! :)
*/
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include <EEPROM.h>
#include <Servo.h>
//Create object
Servo lockServo;
//define pins
#define pinServo 7
//define pins for the shiftregisters
#define pin5V 6
//Pin connected to 12 on shift register
#define latchPin 8
//Pin connected to 11 on shift register
int clockPin = 9;
////Pin connected 14 on  shift register
int dataPin = 10;
//define pins for the rotary encoders

//these pins can not be changed 2/3 are interrupt pins
#define encoderPin1 2
#define encoderPin2 3
#define encoderSwitchPin 4 //push button switch
//end define pins

//numbers for to write to the seven segment displays,
int num[4];
// num3 is the one on the most right
uint8_t num0;
uint8_t num1;
uint8_t num2;
uint8_t num3;

//define variables for the rotary encoder
volatile int lastEncoded = 0;
volatile uint8_t changeEncoded = 0;

volatile uint8_t dir = 0;
volatile uint8_t lastDir = 0;
volatile uint8_t sensDir =3;
volatile const uint8_t sensCDir =3;
volatile uint8_t sens =3;
volatile const uint8_t sensC =3;

//Cross variables
int currNum = 0;
unsigned int currPin = 0;
unsigned int pin = 0; //define PIN
uint8_t lockState=0;//lockState 0= closed, 1=Open

//variables used for the timers, DON'T EVER USE DELAY()!
unsigned long rtNullPrevious = 0;
unsigned long rtPrevious = 0;
unsigned long btnPrevious = 0;
uint8_t btnDelay = 50;
boolean btnLast=LOW;

//Serial acces stuff:
uint8_t sAcces;

void setup()
{
  //Initialize serial communication, WHEN USING BLUETOOTH THIS NEEDS A CHANGE
  Serial.begin(4800);
  //attach servo pin to lockServo
  lockServo.attach(pinServo);
  lockServo.write(130);
  //turn of LED 13 to safe on battery life
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  //initialize pin5V, used to control the 5v pin out, using a transistor
  pinMode(pin5V, OUTPUT);
  digitalWrite(pin5V, LOW);
  //initialize shift register pins as output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  pinMode(encoderPin1, INPUT_PULLUP); 
  pinMode(encoderPin2, INPUT_PULLUP);
  pinMode(encoderSwitchPin, INPUT_PULLUP);
  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
  
  //Reset seven segment displays;
  writeNum();
  pin = pinRead();
  Serial.println(pin);
}
unsigned int pinWrite() {
  byte MSB = currPin>>8;
  byte LSB = currPin;
  EEPROM.write(0, MSB);
  EEPROM.write(1, LSB);
}
unsigned int pinRead() {
  byte MSB = EEPROM.read(0);
  byte LSB = EEPROM.read(1);
  return MSB<<8|LSB;
}
void sleep() {
  digitalWrite(pin5V, HIGH);
  sleep_enable();
  attachInterrupt(0, pin2_isr, LOW);
  attachInterrupt(1, pin2_isr, LOW);
  /* 0, 1, or many lines of code here */
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
  cli();
  sei();
  sleep_cpu();
  /* wake up here */
  sleep_disable();
}
void pin2_isr()
{
  sleep_disable();
  detachInterrupt(0);
  detachInterrupt(1);
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);
  digitalWrite(pin5V, HIGH);
}
void sleep1() {
  //Delay before sleep, to show serial message :)
  Serial.println("Entering sleep mode");
  Serial.println("WARNING: BlueTooth will be stopped!");
  delay(100);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);   // sleep mode is set here, the most efficient one
  sleep_enable();
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);  
  digitalWrite(pin5V, HIGH);// turn off 5v power line
  sleep_mode();            // here the device is actually put to sleep
  digitalWrite (pin5V, LOW);   // turn on the 5v power line
  writeNum();
  Serial.println("Left sleep mode");// It's good to be back ;)  
}
String getSerial(){
  String serial = "";
  char character;

  while(Serial.available()) {
      character = Serial.read();
      serial+=character;
      delay(5);
  }
  if (serial == "") {
    return NULL;
  }
  return serial;
}
void writeNum() {
  for (int i=0;i<4;i++) {
     byte secondByte = 0b00000000;
    //latchPin to LOW to while doing a transmission
    digitalWrite(latchPin, LOW);
    for (int j=0;j<4;j++) {
      if (i==j) {
      } else {
        secondByte |= 1<<(3-j+4);
      }
    }
    secondByte |=num[i];
    shiftOut(dataPin, clockPin, MSBFIRST, secondByte);   //This will be shifted to serial out, after the following
    //latchPin to HIGH to end the transmission
    digitalWrite(latchPin, HIGH);    
  }
}
void writeNum1() {
    byte firstByte = num0 | num1<<4;
    byte secondByte = num3 | num2<<4;
    //latchPin to LOW to while doing a transmission
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, secondByte);   //This will be shifted to serial out, after the following
    shiftOut(dataPin, clockPin, MSBFIRST, firstByte);   
    //latchPin to HIGH to end the transmission
    digitalWrite(latchPin, HIGH);
}

void updateEncoder(){
  digitalWrite (pin5V, LOW);   // turn on the 5v power line
  sleep_disable();
  
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
    if (dir ==1) {
      changeEncoded = 1;
      sensDir=sensCDir;
     // Serial.println("0RIGHT");      
    } else if (sensDir==0) {
      dir=1;
      sensDir=sensCDir;
 //     Serial.println("1RIGHT");
    } else {
      sensDir--;
    }
  } else if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
    if (dir ==2) {
      changeEncoded = 1;
      sensDir=sensCDir;
  //    Serial.println("0LEFT");      
    } else if (sensDir==0) {
      dir=2;
      sensDir=sensCDir;
   //   Serial.println("1LEFT");
    } else {
      sensDir--;
    }
  }
  lastEncoded = encoded; //store this value for next time
}
void setNum(int num_) {
  num[currNum] = num_;
  switch(currNum) {
    case 0:
      num0 = num_;      
      Serial.print("num0 ");
      Serial.println(num0);
      break;
    case 1:
      num1 = num_;
      Serial.print("num1 ");
      Serial.println(num1);
      break;
    case 2:
      num2 = num_;
      Serial.print("num2 ");
      Serial.println(num2);
      break;
    case 3:
      num3 = num_;
      Serial.print("num3 ");
      Serial.println(num3);
      break;
  }
  writeNum();
}
void addNum() {
  if (num[currNum]>=9) {
    num[currNum] = 0;
  } else {
    num[currNum]++;
  }
  switch(currNum) {
    case 0:
      if (num0>=9) {
        num0=0;
      } else {
        num0++;
      }  
      Serial.print("num0 ");
      Serial.println(num0);
      break;
    case 1:
      if (num1>=9) {
        num1=0;
      } else {
        num1++;
      }  
      Serial.print("num1 ");
      Serial.println(num1);
      break;
    case 2:
      if (num2>=9) {
        num2=0;
      } else {
        num2++;
      }  
      Serial.print("num2 ");
      Serial.println(num2);
      break;
    case 3:
      if (num3>=9) {
        num3=0;
      } else {
        num3++;
      }  
      Serial.print("num3 ");
      Serial.println(num3);
      break;     
  }
  writeNum();
}
void lock(boolean doLock) {
  if (!doLock) {
    lockState = 1;
    if (lockServo.read()!=72) {
      lockServo.write(72);
    }
    Serial.println("open");
  } else {
    lastDir = 0;
    lockState = 0;
    currNum = 0;
    num[0] = 0;
    num[1] = 0;
    num[2] = 0;
    num[3] = 0;
    num0 = 0;
    num1 = 0;
    num2 = 0;
    num3 = 0;
    writeNum();
    if (lockServo.read()!=130) {
      lockServo.write(130);
    }
    Serial.println("locked");
  }
}
void resetDisplay(boolean goOff) {
  dir = 0;
  lastDir = 0;
  sensDir = sensCDir;
  sens = sensC;
  
  num[0] = 15;
  num[1] = 15;
  num[2] = 15;
  num[3] = 15;
  num0 = 15;
  num1 = 15;
  num2 = 15;
  num3 = 15;
  writeNum();
  if (!goOff) {    
  delay(500);
  num[0] = 0;
  num[1] = 0;
  num[2] = 0;
  num[3] = 0;
  num0 = 0;
  num1 = 0;
  num2 = 0;
  num3 = 0;
  writeNum();
  }
}
void loop()
{
  writeNum();
  String serial = getSerial();
  if (serial!=NULL) {
    if (sAcces) {
      if (serial=="1") {
        digitalWrite(pin5V, LOW);
        writeNum();
      } else if (serial=="0") {
        digitalWrite(pin5V, HIGH);
      } else if (serial=="open") {
        Serial.println("Opening...");
        resetDisplay(true);
        lock(false);
      } else if (serial=="close") {
        Serial.println("Closing...");
        lock(true);
      } else if (serial=="sread") {
        Serial.print("Servo value: ");
        Serial.println(lockServo.read());
      } else if (serial=="pread") {
        Serial.print("PIN: ");
        Serial.println(pin);
      } else if (serial.indexOf("pin ")!=-1) {
        serial.replace("pin ", "");
        currPin = serial.toInt();
        pin  = currPin;
        pinWrite();
      } else if (serial=="sleep") {
        sleep();
      } else if (serial=="logout") {
        sAcces=false;        
      } else if(serial.indexOf("login ")!=-1) {
        serial.replace("login ", "");
        if (serial.toInt()==pin) {
          sAcces=true;
          Serial.println("SACCES");
        } else {
          sAcces=false;
          Serial.println("SDENIED");
        }
      } else {
        Serial.println("unknown");
      }      
    } else if(serial.indexOf("login ")!=-1) {
      serial.replace("login ", "");
      if (serial.toInt()==pin) {
        sAcces=true;
        Serial.println("SACCES");
      } else {
          sAcces=false;
        Serial.println("SDENIED");
      }
    } else if(serial=="BT") {
      Serial.println("BTOK");
    } else {
      Serial.println("SDENIED");
    }
  }
  if (millis()-btnPrevious > btnDelay) {
    boolean btnState = digitalRead(encoderSwitchPin);
    if(btnState!=btnLast){
      if (btnState==LOW) {
        if (lockState) {
          lock(true);
        } else {
          setNum(0);
        }
      }
    }
    btnLast = btnState;
  }
    if (lastDir!=dir) {
      if (lastDir!=0) {
        if (currNum==3) {
          currPin = (num0*1000)+(num1*100)+(num2*10)+num3;
          Serial.println("confirm");
          if (currPin == pin) {
            Serial.println("ACCES");
            resetDisplay(true);
            lock(false);
          } else {
            Serial.println("DENIED");
            resetDisplay(false);
            lock(true);
          }
          currNum = 0;
        } else {
          if (!lockState) {
            currNum++;
          }
        }
      }
      lastDir = dir;
    }
    if (changeEncoded) {
      if (sens<=0) {
        sens = sensC;
      } else if (sens==sensC) {
        sens--;
        if (!lockState) {          
          if (dir==1) {
            Serial.println("rot 1");
          } else if (dir==2) {
            Serial.println("rot 2");
          }
          addNum();
        }
      } else {
        sens--;
      }
      changeEncoded = 0;
    } else {
      if (millis()-rtNullPrevious>100) {
        rtNullPrevious = millis();
        Serial.println("rot 0");
      }
    }
}
