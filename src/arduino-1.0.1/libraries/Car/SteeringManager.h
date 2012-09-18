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
	uint32_t stopConditionValue;
	uint8_t state;//TODO: optimice this or implement an enum
public:
	SteeringManager(ServoProxy& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator);
	unsigned int getMaxRadius(bool rightTurn);
	void setAngleOfRadius(int radius);
	void driveTurn(int16_t radius, int16_t angle);
	void driveTurn(uint16_t radius, uint16_t angle, bool forward, bool rightTurn);
	void driveStraight(int32_t distance);
	void driveStraight(int32_t distance,bool forward);
	/*1
	* Update the current steering action
	* If the action has finished update() will return true
	* If update() is executed again after finishing it will stop the motor
	* return true if the current action has finished
	*/
	bool update();
};

#endif