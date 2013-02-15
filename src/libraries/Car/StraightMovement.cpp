/*!
Copyright 2012 Andreas Gruber
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

StraightMovement::StraightMovement()
	:Movement(){
}

void StraightMovement::execute(){
	/*
	bool forward = distance >= 0;
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.getFullMovement().getDistance() + (forward ? distance : -distance);
	setState(forward ? ss_driveStraightForward : ss_driveStraightBackward);
	motorPowerEngine.motorMove(255,forward);*/
}
void StraightMovement::update(){
}
void StraightMovement::invokeOnSteeringManager(SteeringManager &steeringManager){
	steeringManager.driveMovement(*this);
}