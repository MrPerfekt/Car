/*
* Copyright 2012 Andreas Gruber
*/

#ifndef SERVO_STEERING_DRIVER
#define SERVO_STEERING_DRIVER

#include "DefineLib.h"

class Servo;

//The servo steering direction is against proportional to the steering wheels.
//The next thing is, that the servo rotates against the mathematical angle.
//So the software kan believ that the servo rotates in the mathematical angle and the angle is proportional to the steering wheels.
class ServoProxy {
private:
	static double convertServoToSteeringAngle(double servoAngle);
	static double convertSteeringToServoAngle(double steeringAngle);
	double getMaxServoAngle(bool rightSteeringSign);
	double getMaxServoAngle(int steeringSign);
	uint8_t setServoAngle(double angle);
	uint8_t setUpdatedSteeringAngle(double angle);
public:
	static const int absServoAngleMiddle = 85;
	static const int steerLeftSign = 1;
	static const int steerRightSign = -1;
	static const int maxAngleLeft = steerLeftSign*35 + absServoAngleMiddle;//138°
	static const int recommendedAngleLeft = maxAngleLeft-steerLeftSign*10;//(posMiddle + posMaxLeft) / 2;
	static const int maxAngleRight = steerRightSign*53 + absServoAngleMiddle;//50°
	static const int recommendedAngleRight = maxAngleRight-steerRightSign*10;			//(posMiddle + posMaxRight) / 2;
	double currentSollAngle;
	double currentSteeringAngle;

	ServoProxy(/*int pinSteeringServo*/);
	void setSteeringServo(Servo* newSteeringServo);
	double getMaxSteeringAngle(bool rightSteeringSign);
	double getMaxSteeringAngle(int steeringSign);
	uint8_t setSteeringAngle(double angle);
	uint8_t correctSteeringAngle(double currentRealAngle);
};

#endif