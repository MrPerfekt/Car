/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOTION_LOGGER
#define MOTION_LOGGER

#include "DefineLib.h"
class PositionCalculator;

class MotionLogger{
private:
	PositionCalculator& positionCalculator;
public:
	MotionLogger(PositionCalculator& positionCalculator);
	void update();
};

#endif