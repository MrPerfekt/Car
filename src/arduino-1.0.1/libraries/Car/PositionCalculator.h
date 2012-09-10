/*
* Copyright 2012 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include <DefineLib.h>
#include <WheelRotationSensors.h>
#include <ServoSteeringDriver.h>
#include <MotorTB6612FNG.h>

class Coordinate{
private:
	long x;
	long y;
public:
	Coordinate(long x,long y);
};

class PositionCalculator{
private:
	WheelSensor& wheelSensor;
	Motor& motorPowerEngine;
	ServoSteeringDriver& servoSteeringDriver;
	int angle;
public:
	PositionCalculator(WheelSensor&wheelSensor,Motor& motorPoserEngine,ServoSteeringDriver& servoSteeringDriver);
	Coordinate& getPosition(bool rightSteeringSign);
	int getAngle();
	int setSteeringAngle(int angle);
	void update();
};

#endif