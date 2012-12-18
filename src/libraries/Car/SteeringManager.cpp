/*!
Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"
#include "Movement.h"


void SteeringManager::driveMovement(StraightMovement &movement){
	driveStraight(movement.getDistance());
}
void SteeringManager::driveMovement(TurnMovement &movement){
	driveTurn(movement.getRadius(),movement.getAngle());
}