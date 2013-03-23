/*!
Copyright 2013 Andreas Gruber
*/

#ifndef EXECUTABLE_TURN_MOVEMENT
#define EXECUTABLE_TURN_MOVEMENT

#include "DefineLib.h"
#include "ExecutableMovement.h"
#include "TurnMovement.h"

class ExecutableTurnMovement : public ExecutableMovement{
private:
	double stopConditionAngle;
	TurnMovement &turnMovement;
public:
	ExecutableTurnMovement(TurnMovement &turnMovement, PositionCalculator &positionCalculator, PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator);

	void execute();
	void update();
};
#endif