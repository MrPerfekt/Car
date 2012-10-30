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
  //Serial.begin(9600);
}

int c0 = 0, c1 = 0;
void loop(){
#if false
  int a0 = analogRead(A0);
  int a1 = analogRead(A1);
  if(a0 > 200)
    c0++;
  if(a1 < 600)
    c1++;
  Serial.print(a0);
  Serial.print(" ");
  Serial.print(c0);
  Serial.print(" ");
  Serial.print(a1);
  Serial.print(" ");
  Serial.println(c1);
  delay(500);  
#else
  delay(1000);  
  analogWrite(pinLed,255);
  delay(200);  
  analogWrite(pinLed,0);
#endif
}
