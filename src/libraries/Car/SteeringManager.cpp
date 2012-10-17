/*
* Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator,double steeringWheelsPosition)
	:servoProxy(servoProxy),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator),steeringWheelsPosition(steeringWheelsPosition)
{}
double SteeringManager::calculateSteeringWheelAngle(const Movement& movement){
	return calculateSteeringWheelAngle(movement.distance / (movement.angle / circle) / (2*M_PI)/*calculates radius*/);
}
double SteeringManager::calculateSteeringWheelAngle(double radius){
	return atan(steeringWheelsPosition/radius)/(2*M_PI)*circle;
}
double SteeringManager::calculateRadius(double steeringWheelAngle){
	return steeringWheelsPosition/tan(steeringWheelAngle*2*M_PI/circle);
}
void SteeringManager::setSteeringAngleByRadius(double radius){
	servoProxy.setSteeringAngle(calculateSteeringWheelAngle(radius));
}

double SteeringManager::getMaxRadius(bool leftTurn){
	return calculateRadius(servoProxy.getMaxSteeringAngle(leftTurn));
}
void SteeringManager::driveStraight(double distance){
	bool forward = distance >= 0;
	if(!forward) distance *= -1;
	driveStraight(distance,forward);
}
void SteeringManager::driveStraight(double distance,bool forward){
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.distance + (forward ? distance : -distance);
	state = forward ? ss_driveStraightForward : ss_driveStraightBackward;
	motorPowerEngine.motorMove(255,forward);
}
void SteeringManager::driveTurn(double radius, double angle){
	bool forward = angle >= 0;
	if(!forward) angle *= -1;
	bool leftTurn = radius >= 0;
	if(!leftTurn) radius *= -1;
	driveTurn(radius,angle,forward,leftTurn);
}
void SteeringManager::driveTurn(double radius, double angle, bool forward, bool leftTurn){
	setSteeringAngleByRadius(radius * (leftTurn ? 1 : -1) );
	stopConditionValue = positionCalculator.angle + angle * (forward ? 1 : -1) * (leftTurn ? 1 : -1);
	if(leftTurn)
		state = forward ? ss_driveTurnLeftForward : ss_driveTurnLeftBackward;
	else
		state = forward ? ss_driveTurnRightForward : ss_driveTurnRightBackward;
}
bool SteeringManager::update(){
	positionCalculator.update();
	if(state == ss_stop) {
		motorPowerEngine.motorBreak();
		return true;
	}
	servoProxy.correctSteeringAngle(calculateSteeringWheelAngle(positionCalculator.currentMovement));
	if((state == ss_driveStraightForward && stopConditionValue <= positionCalculator.distance) ||
		(state == ss_driveStraightBackward && stopConditionValue >= positionCalculator.distance) ||
		((state == ss_driveTurnLeftForward || state == ss_driveTurnRightBackward) && stopConditionValue <= positionCalculator.angle) ||
		((state == ss_driveTurnLeftBackward || state == ss_driveTurnRightForward) && stopConditionValue >= positionCalculator.angle) ){
		state = ss_stop;
		return true;
	}
	return false;
}