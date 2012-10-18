/*
* Copyright 2012 Andreas Gruber
*/

//Motor
const int STBY = 10; //standby
const int PWMA = 3; //Speed control 
const int AIN1 = 9; //Direction
const int AIN2 = 8; //Direction

int curSpeed = 0;
int rps = 40;

//Sensor
//const int inAPinTrans = 0;  
const int inDPinTrans = 2;  
const int outPPinLed = 5;

int curRps = 0;

void motorStep()
{
  curRps++;
}

void setup(){  
  //Allgemein
  noInterrupts();
  
  //Motor
  pinMode(STBY, OUTPUT);

  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  stop();
  
  //Sensor
  pinMode(outPPinLed, OUTPUT);
  pinMode(inDPinTrans, INPUT);
  Serial.begin(9600);
  
  //Allgemein
  interrupts();
  attachInterrupt(0, motorStep, FALLING);
}

void loop(){
  //Sensor
  //val = analogRead(inAPinTrans);    // read the input pin
  //D: val = digitalRead(inDPinTrans);
  //analogWrite(outPPinLed,val/4);
  //D: digitalWrite(outPPinLed,val);
  curRps = 0;
  interrupts();
  delay(100);
  noInterrupts();
  curRps *= 10;
  curRps /= 6;
  
  if(curRps > rps)
    curSpeed--;
  if(curRps < rps)
    curSpeed++;
  Serial.println(curRps);             // curSpeed
    
  if(curSpeed > 255)
    curSpeed = 255;
  if(curSpeed < 0)
    curSpeed = 0;
  move(curSpeed, 1); //motor 1, full speed, left
}

void move(int speed, int direction){
//Move specific motor at speed and direction
//speed: 0 is off, and 255 is full speed
//direction: 0 clockwise, 1 counter-clockwise

  digitalWrite(STBY, HIGH); //disable standby

  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direction == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }

  digitalWrite(AIN1, inPin1);
  digitalWrite(AIN2, inPin2);
  analogWrite(PWMA, speed);
}

void stop(){
//enable standby  
  digitalWrite(STBY, LOW);
}
