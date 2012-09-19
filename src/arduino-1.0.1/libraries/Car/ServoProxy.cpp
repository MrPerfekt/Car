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

int ServoProxy::convertServoToSteeringAngle(int servoAngle){
	return servoAngle;
}
int ServoProxy::convertSteeringToServoAngle(int steeringAngle){
	return steeringAngle;
}

void ServoProxy::setSteeringServo(Servo* newSteeringServo){
	steeringServo = newSteeringServo;
	setSteeringAngle(0);
}

int ServoProxy::getMaxServoAngle(bool rightSteeringSign){
	return rightSteeringSign ? maxAngleLeft : maxAngleRight;
}

int ServoProxy::getMaxServoAngle(int steeringSign){
	return getMaxServoAngle((steeringSign > 0) == (steerRightSign > 0));
}

int ServoProxy::setServoAngle(int angle){
	int returnState = 0;
	if(angle > maxAngleRight * steerRightSign){
		angle = maxAngleRight;
		returnState = steerRightSign;
	}
	if(angle > maxAngleLeft * steerLeftSign){
		angle = maxAngleLeft;
		returnState = steerLeftSign;
	}
	steeringServo->write((int)( 
	(((double)angle+(double)absServoAngleMiddle+(double)500)*(double)180)/(double)1000
	));
}
int ServoProxy::getMaxSteeringAngle(bool rightSteeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(rightSteeringSign));
}
int ServoProxy::getMaxSteeringAngle(int steeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(steeringSign));
}
int ServoProxy::setSteeringAngle(int angle){
	currentSteeringAngle = angle;
	setUpdatedSteeringAngle(angle);
}
int ServoProxy::setUpdatedSteeringAngle(int angle){
	return convertSteeringToServoAngle(setServoAngle(angle));
}
int ServoProxy::correctSteeringAngle(int currentRealAngle){
	setUpdatedSteeringAngle(2 * currentRealAngle - currentRealAngle);
}