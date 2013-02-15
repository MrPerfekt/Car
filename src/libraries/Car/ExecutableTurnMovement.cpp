/*!
Copyright 2012 Andreas Gruber
*/

#include "ExecutableTurnMovement.h"

ExecutableTurnMovement::ExecutableTurnMovement()
	:ExecutableMovement(){
}
ExecutableTurnMovement::ExecutableTurnMovement(PositionCalculator &positionCalculator, SteeringRegulator &steeringRegulator)
	:ExecutableMovement(positionCalculator,steeringRegulator){
}
void ExecutableTurnMovement::execute(){
}
void ExecutableTurnMovement::update(){
}