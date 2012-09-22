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
	static const int absServoAngleMiddle = -16;	//85°
	static int convertServoToSteeringAngle(int servoAngle);
	static int convertSteeringToServoAngle(int steeringAngle);
	int getMaxServoAngle(bool rightSteeringSign);
	int getMaxServoAngle(int steeringSign);
	uint8_t setServoAngle(int angle);
	uint8_t setUpdatedSteeringAngle(int angle);
public:
	static const int steerLeftSign = 1;
	static const int steerRightSign = -1;
	static const int maxAngleLeft = 280 - absServoAngleMiddle;	//138°
	static const int recommendedAngleLeft = 200;			//(posMiddle + posMaxLeft) / 2;
	static const int maxAngleRight = -260 - absServoAngleMiddle;//50°
	static const int recommendedAngleRight = -200;			//(posMiddle + posMaxRight) / 2;
	int16_t currentSollAngle;
	int16_t currentSteeringAngle;

	ServoProxy(/*int pinSteeringServo*/);
	void setSteeringServo(Servo* newSteeringServo);
	int16_t getMaxSteeringAngle(bool rightSteeringSign);
	int16_t getMaxSteeringAngle(int steeringSign);
	uint8_t setSteeringAngle(int angle);
	uint8_t correctSteeringAngle(int currentRealAngle);
};

#endif