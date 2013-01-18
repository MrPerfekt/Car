/*
* Copyright 2012 Andreas Gruber
*/

//==========================
//========== code ==========
//==========================

const uint8_t pinAin = A0;
const uint8_t sensorCnt = 2;
const uint8_t sensorPin[] = {3,2};
const uint8_t ledPin[] = {5,4};

void setup(){
  Serial.begin(9600);
  for(int i = 0; i < sensorCnt;i++){
    pinMode(sensorPin[i],OUTPUT);
    digitalWrite(sensorPin[i],LOW);
    pinMode(ledPin[i],OUTPUT);
    digitalWrite(ledPin[i],LOW);
  }
  pinMode(pinAin,INPUT);
}

void loop(){
  for(int i = 0; i < sensorCnt;i++){
    digitalWrite(sensorPin[i],HIGH);
    int dark = 0;
    for(int r = 0; r < 3;r++){
      delay(1);
      dark += analogRead(pinAin);
    }
    digitalWrite(ledPin[i],HIGH);
    int litUp = 0;
    for(int r = 0; r < 3;r++){
      delay(1);
      litUp += analogRead(pinAin);
    }
    digitalWrite(ledPin[i],LOW);
    digitalWrite(sensorPin[i],LOW);
    
    Serial.print(dark);
    Serial.print(" ");
    Serial.print(litUp);
    Serial.print(" ");
    Serial.println(litUp / (double)dark);
  }
  Serial.println();
  delay(500);
}
