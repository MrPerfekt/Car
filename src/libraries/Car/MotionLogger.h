/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOTION_LOGGER
#define MOTION_LOGGER

#include "DefineLib.h"
#include "PositionCalculator.h"
#include "Coordinates.h"
#include "math.h"

class MotionLogger{
private:
	PositionCalculator& positionCalculator;
public:
	MotionLogger(PositionCalculator& positionCalculator);
	void update();
};

#endif