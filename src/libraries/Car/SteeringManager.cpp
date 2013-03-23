/*!
Copyright 2013 Andreas Gruber
*/

#include "SteeringManager.h"
//#include "Movement.h"
#include "TurnMovement.h"
#include "StraightMovement.h"


void SteeringManager::driveMovement(StraightMovement &movement){
	driveStraight(movement.getDistance());
}
void SteeringManager::driveMovement(TurnMovement &movement){
	driveTurn(movement.getRadius(),movement.getAngle());
}