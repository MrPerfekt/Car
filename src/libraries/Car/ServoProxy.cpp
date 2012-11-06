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

double ServoProxy::convertServoToSteeringAngle(double servoAngle){
	return servoAngle;
}
double ServoProxy::convertSteeringToServoAngle(double steeringAngle){
	return steeringAngle;
}
double ServoProxy::getMaxServoAngle(bool leftSteeringSign){
	return leftSteeringSign ? maxAngleLeft : maxAngleRight;
}
double ServoProxy::getMaxServoAngle(int steeringSign){
	return getMaxServoAngle((steeringSign > 0) == (steerRightSign > 0));
}
uint8_t ServoProxy::setServoAngle(double angle){
	uint16_t servoAngle = (angle/circle*360.0 + absServoAngleMiddle);
	//===========
	angle *= 0;
	angle += 85;
	Serial.println(angle);
	//===========
	int returnState = 0;
	if(servoAngle > maxAngleRight * steerRightSign){
		angle = maxAngleRight;
		returnState = steerRightSign;
	}
	if(servoAngle > maxAngleLeft * steerLeftSign){
		angle = maxAngleLeft;
		returnState = steerLeftSign;
	}
	steeringServo->write((int)servoAngle);
	return returnState;
}
uint8_t ServoProxy::setUpdatedSteeringAngle(double angle){
	return setServoAngle(convertSteeringToServoAngle(angle));
}

void ServoProxy::setSteeringServo(Servo* newSteeringServo){
	steeringServo = newSteeringServo;
	setSteeringAngle(0);
}
double ServoProxy::getMaxSteeringAngle(bool leftSteeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(leftSteeringSign));
}
double ServoProxy::getMaxSteeringAngle(int steeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(steeringSign));
}
uint8_t ServoProxy::setSteeringAngle(double angle){
	currentSollAngle = angle;
	currentSteeringAngle = angle;
	setUpdatedSteeringAngle(angle);
}
uint8_t ServoProxy::correctSteeringAngle(double currentRealAngle){
	/*
	if(currentSollAngle > currentRealAngle)
		currentSteeringAngle++;
	if(currentSollAngle < currentRealAngle)
		currentSteeringAngle--;
	setUpdatedSteeringAngle(currentSteeringAngle);
	*/

	currentSteeringAngle += (currentRealAngle - currentSollAngle);
	setUpdatedSteeringAngle(currentSteeringAngle);
	
	//setUpdatedSteeringAngle(currentSteeringAngle += (currentRealAngle - currentSollAngle));
	//setUpdatedSteeringAngle(currentSollAngle + (currentSteeringAngle - currentRealAngle));
}