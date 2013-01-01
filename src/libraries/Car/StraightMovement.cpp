/*!
Copyright 2012 Andreas Gruber
*/

#include "StraightMovement.h"

StraightMovement::StraightMovement(){
}
StraightMovement::StraightMovement(double distance)
	:distance(distance){
}
void StraightMovement::setDistance(double distance){
	this->distance = distance;
}
double StraightMovement::getDistance() const{
	return distance;
}
double StraightMovement::getAngle() const{
	return 0;
}
void StraightMovement::invokeOnSteeringManager(SteeringManager &steeringManager){
	steeringManager.driveMovement(*this);
}