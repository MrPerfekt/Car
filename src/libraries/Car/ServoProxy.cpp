/*!
Copyright 2012 Andreas Gruber
*/

#include "ServoProxy.h"
#include <Servo.h>
	
Servo* steeringServo;

//================Convert================
double ServoProxy::convertServoToSteeringAngle(double servoAngle){
	return servoAngle;
}
double ServoProxy::convertSteeringToServoAngle(double steeringAngle){
	return steeringAngle;
}

double ServoProxy::convertRadiusToSteeringWheelAngle(double radius){
	return atan(Config::getSteeringWheelsPosition()/radius)/(2*M_PI)*circle;
}
double ServoProxy::convertSteeringWheelAngleToRadius(double steeringWheelAngle){
	return Config::getSteeringWheelsPosition()/tan(steeringWheelAngle*2*M_PI/circle);
}

double ServoProxy::convertRadiusToServoAngle(double radius){
	return convertSteeringToServoAngle(convertRadiusToSteeringWheelAngle(radius));
}
double ServoProxy::convertServoAngleToRadius(double servoAngle){
	return convertSteeringWheelAngleToRadius(convertServoToSteeringAngle(servoAngle));
}
//================Get max angle================
double ServoProxy::getMaxServoAngle(bool leftSteeringSign){
	return leftSteeringSign ? maxAngleLeft : maxAngleRight;
}
double ServoProxy::getMaxServoAngle(int steeringSign){
	return getMaxServoAngle((steeringSign > 0) == (steerRightSign > 0));
}
double ServoProxy::getMaxSteeringAngle(int steeringSign){
	return convertServoToSteeringAngle(getMaxServoAngle(steeringSign));
}
double ServoProxy::getMaxRadius(int steeringSign){
	return convertServoAngleToRadius(getMaxServoAngle(steeringSign));
}
//================Constructor================
ServoProxy::ServoProxy(){
}
void ServoProxy::setSteeringServo(Servo* newSteeringServo){
	steeringServo = newSteeringServo;
	setSteeringAngle(0);
}
//================Set Methods================
uint8_t ServoProxy::setServoAngle(double angle){
	uint16_t servoAngle = (angle/circle*360.0 + absServoAngleMiddle);

	int returnState = 0;
	if(servoAngle > maxAngleRight * steerRightSign){
		servoAngle = maxAngleRight;
		returnState = steerRightSign;
	}
	if(servoAngle > maxAngleLeft * steerLeftSign){
		servoAngle = maxAngleLeft;
		returnState = steerLeftSign;
	}
	steeringServo->write((int)servoAngle);
	return returnState;
}
uint8_t ServoProxy::setUpdatedSteeringAngle(double angle){
	return setServoAngle(convertSteeringToServoAngle(angle));
}

uint8_t ServoProxy::setSteeringAngle(double angle){
	currentSollAngle = angle;
	currentSteeringAngle = angle;
	return setUpdatedSteeringAngle(angle);
}
uint8_t ServoProxy::setRadius(double radius){
	return setSteeringAngle(convertRadiusToSteeringWheelAngle(radius));
}
//================Correct Methods================
uint8_t ServoProxy::correctSteeringAngle(double currentRealAngle){
	/*
	if(currentSollAngle > currentRealAngle)
		currentSteeringAngle++;
	if(currentSollAngle < currentRealAngle)
		currentSteeringAngle--;
	setUpdatedSteeringAngle(currentSteeringAngle);
	*/

	//currentSteeringAngle += (currentRealAngle - currentSollAngle);
	//setUpdatedSteeringAngle(currentSteeringAngle);
	return setUpdatedSteeringAngle(currentSteeringAngle -= (currentRealAngle - currentSollAngle));
}
uint8_t ServoProxy::correcRadius(double currentRadius){
	return correctSteeringAngle(convertRadiusToSteeringWheelAngle(currentRadius));
}