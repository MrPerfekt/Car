/*!
Copyright 2013 Andreas Gruber
*/

#ifndef EXECUTABLE_STRAIGHT_MOVEMENT
#define EXECUTABLE_STRAIGHT_MOVEMENT

#include "DefineLib.h"
#include "ExecutableMovement.h"
#include "StraightMovement.h"

class ExecutableStraightMovement : public ExecutableMovement{
private:
	double stopConditionDistance;
	StraightMovement &straightMovement;
public:
	ExecutableStraightMovement(StraightMovement &straightMovement,PositionCalculator &positionCalculator, PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator);
	
	void execute();
	void update();
};
#endif