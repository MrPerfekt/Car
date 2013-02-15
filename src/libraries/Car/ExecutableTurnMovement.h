/*!
Copyright 2012 Andreas Gruber
*/

#ifndef EXECUTABLE_TURN_MOVEMENT
#define EXECUTABLE_TURN_MOVEMENT

#include "DefineLib.h"
#include "ExecutableMovement.h"
#include "TurnMovement.h"

class ExecutableTurnMovement : public ExecutableMovement, public TurnMovement{
private:
public:
	ExecutableTurnMovement();
	ExecutableTurnMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator);

	void execute();
	void update();
};
#endif