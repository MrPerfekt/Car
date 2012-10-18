/*
* Copyright 2012 Andreas Gruber
*/

#include <Wire.h>

/*
Coppyright Andreas Gruber
*/
const int expander_addr = B0100000;

//==========================
//========== code ==========
//==========================
void setup(){
    Wire.begin();
}

void loop(){
  delay(1000);  
  expanderWrite(B11111111);
  delay(1000);  
  expanderWrite(B00000000);
}

void expanderWrite(byte data ) {
  Wire.beginTransmission(expander_addr);
  Wire.write(data);
  Wire.endTransmission();
}
 
byte expanderRead() {
  byte data;
  Wire.requestFrom(expander_addr, 1);
  if(Wire.available()) {
    data = Wire.read();
  }
  return data;
}
