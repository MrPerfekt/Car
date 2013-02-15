/*!
Copyright 2012 Andreas Gruber
*/

#ifndef EXECUTABLE_STRAIGHT_MOVEMENT
#define EXECUTABLE_STRAIGHT_MOVEMENT

#include "DefineLib.h"
#include "ExecutableMovement.h"
#include "StraightMovement.h"

class ExecutableStraightMovement : public ExecutableMovement, public StraightMovement{
private:
public:
	ExecutableStraightMovement();
	ExecutableStraightMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator);
	
	void execute();
	void update();
};
#endif