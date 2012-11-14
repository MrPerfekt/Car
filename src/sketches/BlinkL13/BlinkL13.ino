/*
* Copyright 2012 Andreas Gruber
*/

/*
Coppyright Andreas Gruber
*/
const int pinLed = 13;

//==========================
//========== code ==========
//==========================
void setup(){
  pinMode(pinLed,OUTPUT);
}

int c0 = 0, c1 = 0;
void loop(){
  delay(1000);  
  analogWrite(pinLed,255);
  delay(200);  
  analogWrite(pinLed,0);
}
