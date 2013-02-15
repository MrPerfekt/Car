/*!
Copyright 2012 Andreas Gruber
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
Motor::Motor(uint8_t pinPWM, uint8_t pinIn1, uint8_t pinIn2)
	:pinPWM(pinPWM)
	,pinIn1(pinIn1)
	,pinIn2(pinIn2){
	curMotorState = msUndefined;

	pinMode(pinPWM, OUTPUT);
	pinMode(pinIn1, OUTPUT);
	pinMode(pinIn2, OUTPUT);
}

Motor::MotorState Motor::motorCalculateState(boolean inPin1, boolean inPin2){
	return (MotorState)((inPin1 ? 1 : 0) + (inPin2 ? 2 : 0));
}

void Motor::waitDeadTime(){
	if(curMotorState != msWaitDeadTime){
		//! Serial.println("Wait Dead Time");
		curMotorState = msWaitDeadTime;//!
		motorStop();
		delayMicroseconds(delayTimeMicroseconds);
	}
}

void Motor::motorWriteStatus(uint8_t speed, bool inPin1, bool inPin2){
	/*
	Serial.print(speed);
	Serial.println(" ");
	Serial.print(inPin1);
	Serial.println(" ");
	Serial.print(inPin2);
	Serial.println("write");
	*/
	MotorState newMotorState = motorCalculateState(inPin1,inPin2);
	if(curMotorState != newMotorState){
		waitDeadTime();
		curMotorState = newMotorState;
		digitalWrite(pinIn1, inPin1);
		digitalWrite(pinIn2, inPin2);
	}
	motorDisableStandby();
	analogWrite(pinPWM, speed);
}

void Motor::motorMove(uint8_t speed, bool clockwise){
	bool inPin1;
	bool inPin2;
	if(clockwise){      
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
/*
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
*/