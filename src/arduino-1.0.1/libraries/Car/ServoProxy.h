/*
* Copyright 2012 Andreas Gruber
*/

#ifndef SERVO_STEERING_DRIVER
#define SERVO_STEERING_DRIVER

#include "DefineLib.h"

class Servo;

//all angles are in milli angle 
//1000 = 360°
class ServoProxy {
private:
	static const int absServoAngleMiddle = -16;					//85°
	static int convertServoToSteeringAngle(int servoAngle);
	static int convertSteeringToServoAngle(int steeringAngle);
	int getMaxServoAngle(bool rightSteeringSign);
	int getMaxServoAngle(int steeringSign);
	int setServoAngle(int angle);
	int setUpdatedSteeringAngle(int angle);
public:
	static const int steerLeftSign = 1;
	static const int steerRightSign = -1;
	static const int maxAngleLeft = 280 - absServoAngleMiddle;	//138°
	static const int recommendedAngleLeft = 200;			//(posMiddle + posMaxLeft) / 2;
	static const int maxAngleRight = -260 - absServoAngleMiddle;//50°
	static const int recommendedAngleRight = -200;			//(posMiddle + posMaxRight) / 2;
	int currentSteeringAngle;

	ServoProxy(/*int pinSteeringServo*/);
	void setSteeringServo(Servo* newSteeringServo);
	int getMaxSteeringAngle(bool rightSteeringSign);
	int getMaxSteeringAngle(int steeringSign);
	int setSteeringAngle(int angle);
	int correctSteeringAngle(int currentRealAngle);
};

#endif