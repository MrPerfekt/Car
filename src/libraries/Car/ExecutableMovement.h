/*!
Copyright 2013 Andreas Gruber
*/

#ifndef EXECUTABLE_MOVEMENT
#define EXECUTABLE_MOVEMENT

#include "DefineLib.h"
#include "Movement.h"
#include "Observer.h"

class PositionCalculator;
class PowerRegulator;
class SteeringRegulator;

class ExecutableMovement : public SingleObservable{
private:
	bool finished;
	PositionCalculator &positionCalculator;
	PowerRegulator &powerRegulator;
	SteeringRegulator &steeringRegulator;
protected:
	void setFinished(bool finished);
	PositionCalculator & getPositionCalculator();
	PowerRegulator & getPowerRegulator();
	SteeringRegulator & getSteeringRegulator();
public:
	ExecutableMovement(PositionCalculator &positionCalculator,PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator);
	virtual void execute() = 0;
	virtual void update() = 0;
	virtual void stop();
	bool hasFinished() const;
};

#endif