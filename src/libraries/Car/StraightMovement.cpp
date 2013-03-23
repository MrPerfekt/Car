/*!
Copyright 2013 Andreas Gruber
*/

#include "StraightMovement.h"

void StraightMovement::setDistance(double distance){
	this->distance = distance;
}
double StraightMovement::getDistance() const{
	return distance;
}
double StraightMovement::getAngle() const{
	return 0;
}
double StraightMovement::getRadius() const{
	return 1/0;//ToDo: use INFINITY
}

StraightMovement::StraightMovement()
	:Movement(){
}

void StraightMovement::invokeOnSteeringManager(SteeringManager &steeringManager){
	steeringManager.driveMovement(*this);
}