/*!
Copyright 2013 Andreas Gruber
*/

#include "ExecutableStraightMovement.h"
#include "GeneralMovement.h"
#include "PositionCalculator.h"
#include "PowerRegulator.h"
#include "SteeringRegulator.h"

ExecutableStraightMovement::ExecutableStraightMovement(StraightMovement &straightMovement,PositionCalculator &positionCalculator, PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator)
	:ExecutableMovement(positionCalculator,powerRegulator,steeringRegulator)
	,straightMovement(straightMovement){
}

void ExecutableStraightMovement::execute(){
	getSteeringRegulator().setRadius(0);
	if(straightMovement.getDistance() == 0) return;
	setFinished(false);
	stopConditionDistance = getPositionCalculator().getFullMovement().getDistance() + straightMovement.getDistance();
	getPowerRegulator().setDirection(straightMovement.getDistance() >= 0);
}
void ExecutableStraightMovement::update(){
	if(hasFinished()) return;
	Movement& m = getPositionCalculator().getLastMovement();
	if(m.getDistance() == 0) return;
	getSteeringRegulator().correcRadius(m.getRadius());
	bool forward = straightMovement.getDistance() >= 0;
	if((forward && stopConditionDistance <= getPositionCalculator().getFullMovement().getDistance()) ||
	   (!forward && stopConditionDistance >= getPositionCalculator().getFullMovement().getDistance()))
		   setFinished(true);
}