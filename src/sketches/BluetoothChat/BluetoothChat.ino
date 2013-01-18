/*
* Copyright 2012 Andreas Gruber
*/

//==========================
//========== code ==========
//==========================
void setup(){
  Serial.begin(9600);
  Serial1.begin(9600);
  //Serial1.println("AT+NAMEandreas");
  delay(1000);
}

void loop(){
  char incomingByte = 0;
  if (Serial1.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial1.read();
    Serial.write(incomingByte);
  }
  if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.read();
    Serial1.write(incomingByte);
  }
}
