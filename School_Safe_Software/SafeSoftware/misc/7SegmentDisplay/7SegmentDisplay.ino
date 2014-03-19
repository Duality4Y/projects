/*
  Name: Darrel Griët
  Date: 18-2-2014
  Project: 4x7 Segment Displays
*/

//Pin connected to 12 on shift register
int latchPin = 8;
//Pin connected to 11 on shift register
int clockPin = 12;
////Pin connected 14 on  shift register
int dataPin = 11;

int num1;
int num2;
int num3;
int num4;

void setup() {
  Serial.begin(9600);
  //set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  //count from 0 to 9, for writing the numbers
  for (int j=0;j<=10000;j++) {
    num1 = j/1000;
    num2 = (j%1000)/100;
    num3 = (j%100)/10;
    num4 = j%10;
    byte firstByte = num1 | num2<<4;
    byte secondByte = num4 | num3<<4;
    //latchPin to LOW to while doing a transmission
    digitalWrite(latchPin, LOW);
    shiftOut(dataPin, clockPin, MSBFIRST, secondByte);   //This will be shifted to serial out, after the following
    shiftOut(dataPin, clockPin, MSBFIRST, firstByte);   
    //latchPin to HIGH to end the transmission
    digitalWrite(latchPin, HIGH);
    delay(50);
  }
}
