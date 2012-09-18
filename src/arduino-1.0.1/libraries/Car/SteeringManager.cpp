/*
* Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator)
	:servoProxy(servoProxy),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator)
{}
unsigned int SteeringManager::getMaxRadius(bool rightTurn){
}
void SteeringManager::setAngleOfRadius(int radius){
	servoProxy.setSteeringAngle(radius);
}
void SteeringManager::driveTurn(int radius, int angle){
}
void SteeringManager::driveTurn(unsigned int radius, unsigned int angle, bool forward, bool rightTurn){
}
void SteeringManager::driveStraight(long distance){
	bool forward = distance >= 0;
	if(!forward) distance *= -1;
	driveStraight(distance,forward);
}
void SteeringManager::driveStraight(int32_t distance,bool forward){
	stopConditionValue = positionCalculator.distance + (forward ? distance : -distance);
	state = forward ? ss_driveStraightForward : ss_driveStraightBackward;
	servoProxy.setSteeringAngle(0);
	motorPowerEngine.motorMove(255,forward);
}
bool SteeringManager::update(){
	if(state == ss_stop) {
		motorPowerEngine.motorBreak();
		return true;
	}
	positionCalculator.update();
	servoProxy.correctSteeringAngle(positionCalculator.currentMovement.angle);
	if((state == ss_driveStraightForward && stopConditionValue < positionCalculator.distance) ||
		(state == ss_driveStraightBackward && stopConditionValue > positionCalculator.distance) ||
		((state == ss_driveTurnLeftForward || state == ss_driveTurnRightBackward) && stopConditionValue < positionCalculator.angle) ||
		((state == ss_driveTurnLeftBackward || state == ss_driveTurnRightForward) && stopConditionValue > positionCalculator.angle)
		){
		state = ss_stop;
		return true;
	}
	false;
}