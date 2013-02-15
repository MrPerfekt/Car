/*!
Copyright 2013 Andreas Gruber
*/

#ifndef EXECUTABLE_MOVEMENT
#define EXECUTABLE_MOVEMENT

#include "DefineLib.h"
#include "Movement.h"
#include "Observer.h"

class PositionCalculator;
class SteeringRegulator;

class ExecutableMovement : public SingleObservable{
private:
	bool finished;
	PositionCalculator &positionCalculator;
	SteeringRegulator &steeringRegulator;
protected:
	void setFinished(bool finished);
public:
	ExecutableMovement();
	ExecutableMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator);
	virtual void execute() = 0;
	virtual void update() = 0;
	bool hasFinished() const;
};

#endif