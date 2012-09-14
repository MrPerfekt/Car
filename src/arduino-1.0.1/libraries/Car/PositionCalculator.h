/*
* Copyright 2012 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include "DefineLib.h"
#include "MovementSensor.h"
#include "Coordinates.h"
#include "math.h"

class PositionCalculator{
private:
	MovementSensor& movementSensor;
	int angle;
	long distance;
	Coordinates position;
public:
	PositionCalculator(MovementSensor& movementSensor);
	Coordinates& getPosition(bool rightSteeringSign);
	int getAngle();
	int getDistance();
	void update();
};

#endif