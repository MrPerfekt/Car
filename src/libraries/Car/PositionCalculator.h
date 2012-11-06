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
	Coordinates position;
	Movement currentMovement;
public:
	double angle;
	double distance;
	Coordinates getCurrentPosition();
	Movement getCurrentMovement();
	PositionCalculator(MovementSensor& movementSensor);
	void update();
};

#endif