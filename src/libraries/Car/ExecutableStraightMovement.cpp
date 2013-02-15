/*!
Copyright 2012 Andreas Gruber
*/

#include "ExecutableStraightMovement.h"

ExecutableStraightMovement::ExecutableStraightMovement()
	:ExecutableMovement(){
}
ExecutableStraightMovement::ExecutableStraightMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator)
	:ExecutableMovement(positionCalculator,steeringRegulator){
}

void ExecutableStraightMovement::execute(){
	/*bool forward = distance >= 0;
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.getFullMovement().getDistance() + (forward ? distance : -distance);
	setState(forward ? ss_driveStraightForward : ss_driveStraightBackward);
	motorPowerEngine.motorMove(255,forward);*/
}
void ExecutableStraightMovement::update(){
}