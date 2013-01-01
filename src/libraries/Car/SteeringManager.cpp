/*!
Copyright 2012 Andreas Gruber
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
double SteeringManager::getMinRadius() const{
	return max(getMinRadius(false),getMinRadius(true));
}