/*
* Copyright 2012 Andreas Gruber
*/

#ifndef STEERING_MANAGER
#define STEERING_MANAGER

#include <DefineLib.h>
#include <ServoSteeringDriver.h>
#include <MotorTB6612FNG.h>
#include "PositionCalculator.h"


class SteeringManager {
private:
	ServoSteeringDriver& servoSteeringDriver;
	Motor& motorPowerEngine;
	PositionCalculator& positionCalculator;
public:
	SteeringManager(ServoSteeringDriver& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator);
	unsigned int getMaxRadius(bool rightTurn);
	void setAngleOfRadius(int radius);
	void driveTurn(int radius, int angle);
	void driveTurn(unsigned int radius, unsigned int angle, bool forward, bool rightTurn);
	void driveStraight(long distance);
	void driveStraight(unsigned long distance,bool forward);
};

#endif