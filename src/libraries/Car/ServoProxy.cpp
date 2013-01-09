/*!
Copyright 2012 Andreas Gruber
*/

#include "ServoProxy.h"
#include <Servo.h>
	
Servo* steeringServo;

//================Convert================
double ServoProxy::convertServoToSteeringAngle(double servoAngle){
	//! ToDo: Improve this algorithm
	return servoAngle;
}
double ServoProxy::convertSteeringToServoAngle(double steeringAngle){
	//! ToDo: Improve this algorithm
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
double const ServoProxy::getMaxSteeringAngle(){
	return convertServoToSteeringAngle(Config::getServoMaxAngleDeg()*2.0*PI/360.0);
}
double const ServoProxy::getMinRadius(){
	return Config::getMinSteeringRadius();
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
	static double midDeg = Config::getServoAbsAngleMiddleDeg();
	static double maxDeg = Config::getServoMaxAngleDeg();

	double servoAngle = angle/2.0/PI*360.0;

	int returnState = 0;
	if(servoAngle < -maxDeg){
		servoAngle = -maxDeg;
		returnState = -1;
	}
	if(servoAngle > maxDeg){
		servoAngle = maxDeg;
		returnState = 1;
	}
	servoAngle+= midDeg;

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
	Serial.println("+");
	//! ToDo: Improve this algorithm
	currentSteeringAngle -= (currentRealAngle - currentSollAngle);
	if(currentSteeringAngle > PI)
		currentSteeringAngle = PI;
	if(currentSteeringAngle < -PI)
		currentSteeringAngle = -PI;
	Serial.println("*");
	return setUpdatedSteeringAngle(currentSteeringAngle);
}
uint8_t ServoProxy::correcRadius(double currentRadius){
	return correctSteeringAngle(convertRadiusToSteeringWheelAngle(currentRadius));
}