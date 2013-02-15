/*!
Copyright 2013 Andreas Gruber
*/

#include "ExecutableMovement.h"
#include "PositionCalculator.h"
#include "SteeringRegulator.h"
#include "Vehicle.h"

ExecutableMovement::ExecutableMovement()
	:positionCalculator(Vehicle::getInstance().getPositionCalculator())
	,steeringRegulator(Vehicle::getInstance().getSteeringRegulator())	{
}
ExecutableMovement::ExecutableMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator)
	:positionCalculator(positionCalculator)
	,steeringRegulator(steeringRegulator){
}

void ExecutableMovement::setFinished(bool finished){
	if(finished == true) notifyAll();
	this->finished = finished;
}
bool ExecutableMovement::hasFinished() const{
	return finished;
}