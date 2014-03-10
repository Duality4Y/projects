/*
  Name: Darrel Griët
  Date: 15-2-2014
  Project: 3 to 23 pinOut, using 4 shift registers!
*/

//Pin connected to 12 (ST_CP)on shift register
int latchPin = 2;
//Pin connected to 11 (SH_CP)on shift register
int clockPin = 3;
////Pin connected 14 (DS)on  shift register
int dataPin = 4;

int firstShift = {0b00000000};
int secondShift = {0b00000000}; //Connect the first two BCD's to this one
int thirdShift = {0b00000000}; //WARNING: the first bit(the one on the far right :)) will be used as latch pin for the fourth shiftRegister!
int fourthShift = {0b00000000}; //Connect the second two BCD's to this one

void setup() {
  Serial.begin(9600);
  //set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  writeToMain();
  delay(5000);
}
void writeToMain() {
  digitalWrite(latchPin,LOW);
  for (int i=0; i<8;i++) {
    digitalWrite(dataPin, firstShift & 1<<(7-i)); //to invert order do change i to (7-i)
    digitalWrite(clockPin, HIGH);
    digitalWrite(clockPin, LOW);    
  }
  digitalWrite(latchPin, HIGH);
}
void writeToSecond() {
   firstShift = firstShift | (1 << 7);//set latch to HIGH
   firstShift = firstShift ^ (1 << 7);//set latch to LOW
   writeToMain();
   
   for (int i=0;i<8;i++) {
     if (secondShift & 1<<(7-i)) {
       firstShift = firstShift | (i << 6);       
     } else {
       firstShift = firstShift | (i << 6);  
       firstShift = firstShift ^ (i << 6);  
     }
     writeToMain();
     //toggle Clock
     firstShift = firstShift | (i << 5);
     writeToMain();
     firstShift = firstShift ^ (i << 5);
     writeToMain();
   }
   writeToMain();
   firstShift = firstShift ^ (1 << 7);//set latch to LOW
   writeToMain();
}
void writeToThird() {
   firstShift = firstShift | (1 << 4);//set latch to HIGH
   firstShift = firstShift ^ (1 << 4);//set latch to LOW
   writeToMain();
   
   for (int i=0;i<8;i++) {
     if (thirdShift & 1<<(7-i)) {
       firstShift = firstShift | (i << 3);       
     } else {
       firstShift = firstShift | (i << 3);  
       firstShift = firstShift ^ (i << 3);  
     }
     writeToMain();
     //toggle Clock
     firstShift = firstShift | (i << 2);
     writeToMain();
     firstShift = firstShift ^ (i << 2);
     writeToMain();
   }
   writeToMain();
   firstShift = firstShift ^ (1 << 4);//set latch to LOW
   writeToMain();
}
void writeToFourth() {
   thirdShift = thirdShift | (1 << 1);//set latch to HIGH
   thirdShift = thirdShift ^ (1 << 1);//set latch to LOW
   writeToThird();
   
   for (int i=0;i<8;i++) {
     if (fourthShift & 1<<(7-i)) {
       firstShift = firstShift | (i << 1);       
     } else {
       firstShift = firstShift | (i << 1);  
       firstShift = firstShift ^ (i << 1);  
     }
     writeToMain();
     //toggle Clock
     firstShift = firstShift | (i << 0);
     writeToMain();
     firstShift = firstShift ^ (i << 0);
     writeToMain();
   }
   writeToMain();
   thirdShift = thirdShift ^ (1 << 1);//set latch to LOW
   writeToThird();
}
void loop() {
  //count from 0 to 9, for writing the numbers
  for (int j = 0; j < 256; j++) {
    //latchPin to LOW to while doing a transmission
   // digitalWrite(latchPin, LOW);
    
     for (uint8_t i = 0; i < 8; i++)  {
            digitalWrite(dataPin, (j & (1 << (7 - i))));
                  
            digitalWrite(clockPin, HIGH);
            digitalWrite(clockPin, LOW);            
      }
    
    //shiftOut(dataPin, clockPin, MSBFIRST, j);   
    //latchPin to HIGH to end the transmission
    digitalWrite(latchPin, HIGH);
    Serial.println(j);
    delay(100);
  }
}
