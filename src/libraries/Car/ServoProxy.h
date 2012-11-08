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
	static const int absServoAngleMiddle = 85;
	static const int steerLeftSign = 1;
	static const int steerRightSign = -1;
	static const int maxAngleLeft = steerLeftSign*30 + absServoAngleMiddle;//138°
	static const int recommendedAngleLeft = maxAngleLeft-steerLeftSign*20;//(posMiddle + posMaxLeft) / 2;
	static const int maxAngleRight = steerRightSign*35 + absServoAngleMiddle;//50°
	static const int recommendedAngleRight = maxAngleRight-steerRightSign*20;			//(posMiddle + posMaxRight) / 2;
	double currentSollAngle;
	double currentSteeringAngle;
	double steeringWheelsPosition;

	double getMaxServoAngle(bool rightSteeringSign);
	double getMaxServoAngle(int steeringSign);
	uint8_t setServoAngle(double angle);
	uint8_t setUpdatedSteeringAngle(double angle);
	
	//================Convert================
	/*!
	Convert the servo angle to the steering angle.
	\param servoAngle Servo angle
	\return Steering angle
	*/
	static double convertServoToSteeringAngle(double servoAngle);
	/*!
	Convert steering angle to servo angle.
	\param steeringAngle Steering angle
	\return Servo angle
	*/
	static double convertSteeringToServoAngle(double steeringAngle);

	/*!
	Convert driving radius to steering wheel angle.
	\param radius From this driving radius the angle is calculated
	\return Angle of the steering wheels
	*/
	double convertRadiusToSteeringWheelAngle(double radius);
	/*!
	Convert steering wheel angle to driving radius.
	\param steeringWheelAngle The angle of the steering wheels
	\return The radius the car will drive
	*/
	double convertSteeringWheelAngleToRadius(double steeringWheelAngle);

	/*!
	Convert driving radius to servo angle.
	\param radius Radius
	\return Servo angle
	*/
	double convertRadiusToServoAngle(double radius);
	/*!
	Convert driving radius to servo angle.
	\param servoAngle Servo angle
	\return Radius
	*/
	double convertServoAngleToRadius(double servoAngle);
public:
	//================Get max angle================
	double getMaxSteeringAngle(bool rightSteeringSign);
	double getMaxSteeringAngle(int steeringSign);
	/*!
	Get maximal radius the car can steer.
	\param steeringSign >0 left, <0 right
	\return Maximal Radius
	*/
	double getMaxRadius(int steeringSign);
	//================Constructor================
	/*!
	Initialices the ServoProxy.
	After creating a new ServoProxy setSteeringServo have to be called.
	\param steeringWheelsPosition Position of the Steering wheels to the drive axle.
	*/
	ServoProxy(double steeringWheelsPosition);
	/*!
	Sets the steering servo which have to be used to control the car. 
	\param newSteeringServo The steering servo
	*/
	void setSteeringServo(Servo* newSteeringServo);
	//================Set Methods================
	/*!
	Set the radius the car have to stear
	\param radius Radius
	*/
	uint8_t setRadius(double radius);
	uint8_t setSteeringAngle(double angle);
	//================Correct Methods================
	/*!
	Because the steering mechanism can has mechanical tollerances the radius can be updated based on measured values.
	\param currentRadius The real radius of the car
	*/
	uint8_t correcRadius(double currentRadius);
	uint8_t correctSteeringAngle(double currentRealAngle);
};

#endif