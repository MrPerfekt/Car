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
  Serial.begin(38400);
}

int c0 = 0, c1 = 0;
void loop(){
  int analogResult = analogRead(A1);
  analogWrite(pinLed,analogResult > 300 ? 255 : 0);
  delay(200);
  Serial.println("hallo");
}
