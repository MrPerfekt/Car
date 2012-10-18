/*
* Copyright 2012 Andreas Gruber
*/

const int inAPinTrans = 0;  
const int outPPinLed = 3;

int val = 0;

void setup()
{
  pinMode(outPPinLed, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  val = analogRead(inAPinTrans);    // read the input pin
  analogWrite(outPPinLed,val/4);
  Serial.println(val);             // debug value
  delay(50);
}

