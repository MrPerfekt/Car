/*
* Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator,int32_t steeringWheelsPosition)
	:servoProxy(servoProxy),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator),steeringWheelsPosition(steeringWheelsPosition)
{}
unsigned int SteeringManager::getMaxRadius(bool rightTurn){
	return calculateSteeringWheelAngle(servoProxy.getMaxSteeringAngle(rightTurn));
}
void SteeringManager::setAngleOfRadius(int radius){
	servoProxy.setSteeringAngle(radius);
}
void SteeringManager::driveTurn(int32_t radius, int16_t angle){
	bool forward = angle >= 0;
	if(!forward) angle *= -1;
	bool leftTurn = radius >= 0;
	if(!leftTurn) radius *= -1;
	driveTurn(radius,angle,forward,leftTurn);
}
void SteeringManager::driveTurn(int32_t radius, int16_t angle, bool forward, bool leftTurn){
	servoProxy.setSteeringAngle(calculateSteeringWheelAngle(radius * (forward ? 1 : -1) ));
	stopConditionValue = angle * (forward ? 1 : -1) * (leftTurn ? 1 : -1);
	if(leftTurn)
		state = forward ? ss_driveTurnLeftForward : ss_driveTurnLeftBackward;
	else
		state = forward ? ss_driveTurnRightForward : ss_driveTurnRightBackward;
}
void SteeringManager::driveStraight(long distance){
	bool forward = distance >= 0;
	if(!forward) distance *= -1;
	driveStraight(distance,forward);
}
void SteeringManager::driveStraight(int32_t distance,bool forward){
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.distance + (forward ? distance : -distance);
	state = forward ? ss_driveStraightForward : ss_driveStraightBackward;
	motorPowerEngine.motorMove(255,forward);
}
int16_t SteeringManager::calculateSteeringWheelAngle(const Movement& movement){
	return calculateSteeringWheelAngle((int32_t)((movement.distance*1000) / (movement.angle*2*M_PI))/*calculates radius*/);
}
int16_t SteeringManager::calculateSteeringWheelAngle(int32_t radius){
	return (int16_t)atan((double)steeringWheelsPosition/radius);
}
bool SteeringManager::update(){
	positionCalculator.update();
	if(state == ss_stop) {
		motorPowerEngine.motorBreak();
		return true;
	}
	servoProxy.correctSteeringAngle(calculateSteeringWheelAngle(positionCalculator.currentMovement));
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