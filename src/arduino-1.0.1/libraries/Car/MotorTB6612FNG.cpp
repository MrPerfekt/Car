/*
* Copyright 2012 Andreas Gruber
*/

#include "MotorTB6612FNG.h"

void setupMotorSTBY(int pinSTBY){
	mPinSTBY = pinSTBY;
}

void motorWriteDriverStandby(boolean stbyState){
	if(mPinSTBY != -1)
	  digitalWrite(mPinSTBY, stbyState);//LOW=enable / HIGH=disable   standby
}

void motorDisableStandby(){
	motorWriteDriverStandby(HIGH);
}

void motorEnableStandby(){
	motorWriteDriverStandby(LOW);
}


//== class Motor ==
Motor::Motor(int pinPWM,int pinIN1,int pinIN2){
	mPinPWM = pinPWM;
	mPinIN1 = pinIN1;
	mPinIN2 = pinIN2;
	curMotorState = msUndefined;

	pinMode(mPinPWM, OUTPUT);
	pinMode(mPinIN1, OUTPUT);
	pinMode(mPinIN2, OUTPUT);
}

byte Motor::motorCalculateState(boolean inPin1, boolean inPin2){
	return (inPin1 ? 1 : 0) + (inPin2 ? 2 : 0);
}

void Motor::waitDeadTime(){
	//Wait the dead-time to prevent damaging of the motordriver
	if(curMotorState != msWaitDeadTime){
		//Serial.println("Wait Dead Time");
		curMotorState = msWaitDeadTime;
		motorStop();
		delay(10);
	}
}

void Motor::motorWriteStatus(int speed, boolean inPin1, boolean inPin2){
	/*
	Serial.print(speed);
	Serial.println(" ");
	Serial.print(inPin1);
	Serial.println(" ");
	Serial.print(inPin2);
	Serial.println("write");
	*/
	byte newMotorState = motorCalculateState(inPin1,inPin2);
	if(curMotorState != newMotorState){
		waitDeadTime();
		curMotorState = newMotorState;
		digitalWrite(mPinIN1, inPin1);
		digitalWrite(mPinIN2, inPin2);
	}
	motorDisableStandby();
	analogWrite(mPinPWM, speed);
}

void Motor::motorMove(int speed, int direction){
	//Move specific motor at speed and direction
	//motor: 0 for B 1 for A
	//speed: 0 is off, and 255 is full speed
	//direction: 0 clockwise, 1 counter-clockwise
	boolean inPin1;
	boolean inPin2;
	if(direction == 0){      
	  inPin1 = HIGH;
	  inPin2 = LOW;
	}else{
	  inPin1 = LOW;
	  inPin2 = HIGH;
	}
	motorWriteStatus(speed,inPin1,inPin2);
}

void Motor::motorStop(){
	motorWriteStatus(0,LOW,LOW);
}

void Motor::motorBreak(){
	motorWriteStatus(0,HIGH,HIGH);
}

void Motor::motorDeadTimeTest(){
	Serial.println("=== Motor Dead Time Test ===");
	Serial.println("3");
	delay(1000);
	Serial.println("2");
	delay(1000);
	Serial.println("1");
	delay(1000);
	Serial.println("0");

	//=====================================
	Serial.println("motorMove(255,0);");
	Serial.print("== ");
	motorMove(255,0);
	delay(700);
	//=====================================
	Serial.println("motorMove(100,0);");
	motorMove(100,0);
	delay(700);
	//=====================================
	Serial.println("motorMove(255,1);");
	Serial.print("== ");
	motorMove(255,1);
	delay(700);
	//=====================================
	Serial.println("motorMove(100,1);");
	motorMove(100,1);
	delay(700);
	//=====================================
	Serial.println("motorBreak();");
	Serial.print("== ");
	motorBreak();
	delay(700);
	//=====================================
	Serial.println("motorStop();");
	Serial.print("== ");
	motorStop();
	delay(700);
	//=====================================
	Serial.println("motorBreak();");
	Serial.print("== ");
	motorBreak();
	delay(700);
	//=====================================
	Serial.println("motorMove(255,1);");
	Serial.print("== ");
	motorMove(255,1);
	delay(700);
	//=====================================
	Serial.println("motorBreak();");
	Serial.print("== ");
	motorBreak();
	delay(700);
	//=====================================
	Serial.println("motorMove(255,1);");
	Serial.print("== ");
	motorMove(255,1);
	delay(700);
	//=====================================
	Serial.println("motorMove(100,1);");
	motorMove(100,1);
	delay(700);
	//=====================================
	Serial.println("motorBreak();");
	Serial.print("== ");
	motorBreak();
	delay(700);
	//=====================================
	motorEnableStandby();
}