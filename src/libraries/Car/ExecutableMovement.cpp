/*!
Copyright 2013 Andreas Gruber
*/

#include "ExecutableMovement.h"
#include "PositionCalculator.h"
#include "SteeringRegulator.h"
#include "Vehicle.h"

void ExecutableMovement::setFinished(bool finished){
	this->finished = finished;
	if(finished) {
		Vehicle::getInstance().setCurrentExecutingMovement(NULL);
		notifyAll();
	}else
		Vehicle::getInstance().setCurrentExecutingMovement(this);
}
bool ExecutableMovement::hasFinished() const{
	return finished;
}
PositionCalculator & ExecutableMovement::getPositionCalculator(){
	return positionCalculator;
}
PowerRegulator & ExecutableMovement::getPowerRegulator(){
	return powerRegulator;
}
SteeringRegulator & ExecutableMovement::getSteeringRegulator(){
	return steeringRegulator;
}
void ExecutableMovement::stop(){
	setFinished(true);
}

ExecutableMovement::ExecutableMovement(PositionCalculator &positionCalculator,PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator)
	:positionCalculator(positionCalculator)
	,powerRegulator(powerRegulator)
	,steeringRegulator(steeringRegulator){
}