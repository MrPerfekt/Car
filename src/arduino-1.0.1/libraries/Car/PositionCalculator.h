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
public:
	int16_t angle;
	int32_t distance;
	Coordinates position;
	Movement currentMovement;
	PositionCalculator(MovementSensor& movementSensor);
	void update();
};

#endif