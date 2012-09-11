/*
* Copyright 2012 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include <DefineLib.h>
#include <WheelRotationSensors.h>
#include <Coordinates.h>

class PositionCalculator{
private:
	WheelSensor& wheelSensor;
	int angle;
public:
	PositionCalculator(WheelSensor&wheelSensor);
	Coordinates& getPosition(bool rightSteeringSign);
	int getAngle();
	int setSteeringAngle(int angle);
	void update();
};

#endif