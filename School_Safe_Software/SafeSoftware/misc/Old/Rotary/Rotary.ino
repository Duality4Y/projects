//From bildr article: http://bildr.org/2012/08/rotary-encoder-arduino/

//these pins can not be changed 2/3 are special pins
int encoderPin1 = 2;
int encoderPin2 = 3;
int encoderSwitchPin = 4; //push button switch

volatile int lastEncoded = 0;
volatile uint8_t changeEncoded = 0;
volatile uint8_t dir = 0;
volatile uint8_t sens =3;
volatile uint8_t senss =3;
volatile uint8_t s =3;
volatile uint8_t ss =3;

unsigned long previous = 0;

void setup() {
  Serial.begin (9600);

  pinMode(encoderPin1, INPUT); 
  pinMode(encoderPin2, INPUT);

  pinMode(encoderSwitchPin, INPUT);


  digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
  digitalWrite(encoderPin2, HIGH); //turn pullup resistor on

  digitalWrite(encoderSwitchPin, HIGH); //turn pullup resistor on


  //call updateEncoder() when any high/low changed seen
  //on interrupt 0 (pin 2), or interrupt 1 (pin 3) 
  attachInterrupt(0, updateEncoder, CHANGE); 
  attachInterrupt(1, updateEncoder, CHANGE);

}

void loop(){ 
  //Do stuff here
  if(digitalRead(encoderSwitchPin)){
    //button is not being pushed
  }else{
    Serial.println("PUSH!");
    //button is being pushed
  }
  if (changeEncoded) {
    if (ss<=0) {
      ss = s;
    } else if (ss==s) {
      ss--;
      Serial.println(millis());
    } else {
      ss--;
    }
    changeEncoded = 0;
  }
  //delay(1000); //just here to slow down the output, and show it will work  even during a delay
}


void updateEncoder(){
  cli();
  delay(20);
  int MSB = digitalRead(encoderPin1); //MSB = most significant bit
  int LSB = digitalRead(encoderPin2); //LSB = least significant bit

  int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single number
  int sum  = (lastEncoded << 2) | encoded; //adding it to the previous encoded value

  if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011) {
    if (dir ==1) {
      changeEncoded = 1;
      senss=sens;
     // Serial.println("0RIGHT");      
    } else if (senss==0) {
      dir=1;
      senss=sens;
 //     Serial.println("1RIGHT");
    } else {
      senss--;
    }
  } else if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000) {
    if (dir ==2) {
      changeEncoded = 1;
      senss=sens;
   //   Serial.println("0LEFT");      
    } else if (senss==0) {
      dir=2;
      senss=sens;
   //   Serial.println("1LEFT");
    } else {
      senss--;
    }
  }
  lastEncoded = encoded; //store this value for next time
  sei();
}
