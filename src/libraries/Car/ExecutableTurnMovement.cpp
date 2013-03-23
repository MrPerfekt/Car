/*!
Copyright 2013 Andreas Gruber
*/

#include "ExecutableTurnMovement.h"
#include "GeneralMovement.h"
#include "PositionCalculator.h"
#include "PowerRegulator.h"
#include "SteeringRegulator.h"


ExecutableTurnMovement::ExecutableTurnMovement(TurnMovement &turnMovement, PositionCalculator &positionCalculator, PowerRegulator &powerRegulator, SteeringRegulator &steeringRegulator)
	:ExecutableMovement(positionCalculator,powerRegulator,steeringRegulator)
	,turnMovement(turnMovement){
}
void ExecutableTurnMovement::execute(){
	getSteeringRegulator().setRadius(turnMovement.getRadius());
	if(turnMovement.getAngle() == 0) return;
	setFinished(false);
	stopConditionAngle = getPositionCalculator().getFullMovement().getAngle() + turnMovement.getAngle();
	getPowerRegulator().setDirection(turnMovement.getDistance() >= 0);
}
void ExecutableTurnMovement::update(){
	if(hasFinished()) return;
	Movement& m = getPositionCalculator().getLastMovement();
	if(m.getDistance() == 0) return;
	getSteeringRegulator().correcRadius(m.getRadius());
	
	bool forward = turnMovement.getDistance() >= 0;
	bool left = turnMovement.getRadius() >= 0;
	if( ( ((left&&forward) || (!left&&!forward)) && stopConditionAngle <= getPositionCalculator().getFullMovement().getAngle()) ||
		( ((!left&&forward) || (left&&!forward)) && stopConditionAngle >= getPositionCalculator().getFullMovement().getAngle()) ){
		   setFinished(true);
	}
}