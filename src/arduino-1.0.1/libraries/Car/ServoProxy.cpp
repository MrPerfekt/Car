/*
* Copyright 2012 Andreas Gruber
*/

#include "ServoProxy.h"
#include <Servo.h>
	
Servo* steeringServo;
ServoProxy::ServoProxy(/*int pinSteeringServo*/){
	//steeringServo = new Servo();
	//steeringServo.attach(7);
	//setSteeringAngle(0);
}

void ServoProxy::setSteeringServo(Servo* newSteeringServo){
	steeringServo = newSteeringServo;
	setSteeringAngle(0);
}

int ServoProxy::getMaxAngle(bool rightSteeringSign){
	return rightSteeringSign ? maxAngleLeft : maxAngleRight;
}

int ServoProxy::getMaxAngle(int steeringSign){
	return getMaxAngle((steeringSign > 0) == (steerRightSign > 0));
}

int ServoProxy::setSteeringAngle(int angle){
	int returnState = 0;
	if(angle < maxAngleRight){
		angle = maxAngleRight;
		returnState = 1;
	}
	if(angle > maxAngleLeft){
		angle = maxAngleLeft;
		returnState = 2;
	}
	steeringServo->write((int)( 
	(((double)angle+(double)absAngleMiddle+(double)500)*(double)180)/(double)1000
	));
}