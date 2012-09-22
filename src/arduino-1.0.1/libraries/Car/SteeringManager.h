/*
* Copyright 2012 Andreas Gruber
*/

#ifndef STEERING_MANAGER
#define STEERING_MANAGER

#include "DefineLib.h"
#include "ServoProxy.h"
#include "MotorTB6612FNG.h"
#include "PositionCalculator.h"
#include "Movement.h"


class SteeringManager {
private:
	enum SteeringState{
		ss_stop,
		ss_driveStraightForward,
		ss_driveStraightBackward,
		ss_driveTurnLeftForward,
		ss_driveTurnLeftBackward,
		ss_driveTurnRightForward,
		ss_driveTurnRightBackward,
	};
	ServoProxy& servoProxy;
	Motor& motorPowerEngine;
	PositionCalculator& positionCalculator;
	int32_t stopConditionValue;
	uint8_t state;
	int32_t steeringWheelsPosition;
	/*!
	* Calculates the angle of the steering wheels
	* param movement From this movement the angle is calculatet
	* return angle of the steering wheels
	*/
	int16_t calculateSteeringWheelAngle(const Movement& movement);
	/*!
	* Calculates the angle of the steering wheels
	* param movement From this driving radius the angle is calculatet
	* return angle of the steering wheels
	*/
	int16_t calculateSteeringWheelAngle(int32_t radius);
	/*!
	* Calculates the radius, the car will drive with this angle of the steering wheels
	* param steeringWheelAngle The angle of the steering wheels
	* return The radius of the cars movement
	*/
	int32_t calculateRadius(int16_t steeringWheelAngle);
	/*!
	* Set the steering angle by the radius the car should drive
	* param radius Radius of the turn
	*/
	void setSteeringAngleByRadius(int16_t radius);
public:
	SteeringManager(ServoProxy& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator,int32_t steeringWheelsPosition);
	/*!
	* Get the maximal radius of the car
	* param leftTurn If the car should drive a left [= true] or a right [= false] turn
	* return The maximal radius 
	*/
	int16_t getMaxRadius(bool leftTurn);
	void driveStraight(int32_t distance);
	void driveStraight(int32_t distance,bool forward);
	void driveTurn(int32_t radius, int16_t angle);
	void driveTurn(int32_t radius, int16_t angle, bool forward, bool leftTurn);
	/*1
	* Update the current steering action
	* If the action has finished update() will return true
	* If update() is executed again after finishing it will stop the motor
	* return true if the current action has finished
	*/
	bool update();
};

#endif