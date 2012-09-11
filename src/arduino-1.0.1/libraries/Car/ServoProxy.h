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
public:
	static const int steerLeftSign = 1;
	static const int steerRightSign = -1;
	
	static const int absAngleMiddle = -16;					//85°
	static const int maxAngleLeft = 280 - absAngleMiddle;	//138°
	static const int recommendedAngleLeft = 200;			//(posMiddle + posMaxLeft) / 2;
	static const int maxAngleRight = -260 - absAngleMiddle;//50°
	static const int recommendedAngleRight = -200;			//(posMiddle + posMaxRight) / 2;

	ServoProxy(/*int pinSteeringServo*/);
	void setSteeringServo(Servo* newSteeringServo);
	int getMaxAngle(bool rightSteeringSign);
	int getMaxAngle(int steeringSign);
	int setSteeringAngle(int angle);
};

#endif