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
int16_t ServoProxy::getMaxServoAngle(bool leftSteeringSign){
	return leftSteeringSign ? maxAngleLeft : maxAngleRight;
}
int16_t ServoProxy::getMaxServoAngle(int steeringSign){
	return getMaxServoAngle((steeringSign > 0) == (steerRightSign > 0));
}
uint8_t ServoProxy::setServoAngle(int angle){
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
uint8_t ServoProxy::setUpdatedSteeringAngle(int angle){
	return setServoAngle(convertSteeringToServoAngle(angle));
}

void ServoProxy::setSteeringServo(Servo* newSteeringServo){
	steeringServo = newSteeringServo;
	setSteeringAngle(0);
}
int16_t ServoProxy::getMaxSteeringAngle(bool leftSteeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(leftSteeringSign));
}
int16_t ServoProxy::getMaxSteeringAngle(int steeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(steeringSign));
}
uint8_t ServoProxy::setSteeringAngle(int angle){
	currentSollAngle = angle;
	currentSteeringAngle = angle;
	setUpdatedSteeringAngle(angle);
}
uint8_t ServoProxy::correctSteeringAngle(int16_t currentRealAngle){
	setUpdatedSteeringAngle(currentSollAngle + (currentSteeringAngle - currentRealAngle));
}