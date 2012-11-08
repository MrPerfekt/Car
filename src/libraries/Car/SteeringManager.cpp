/*
* Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator)
	:servoProxy(servoProxy),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator),steeringWheelsPosition(steeringWheelsPosition)
{}

double SteeringManager::calculateRadiusByMovement(const Movement& movement){
	return movement.distance * circle / movement.angle / (2*M_PI)/*calculates radius*/;
}

void SteeringManager::driveStraight(double distance){
	bool forward = distance >= 0;
	if(!forward) distance *= -1;

	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.distance + (forward ? distance : -distance);
	state = forward ? ss_driveStraightForward : ss_driveStraightBackward;
	motorPowerEngine.motorMove(255,forward);
}
void SteeringManager::driveTurn(double radius, double angle){
	bool leftTurn = radius >= 0;
	bool forward = angle >= 0;
	servoProxy.setRadius(radius);
	stopConditionValue = positionCalculator.angle + angle * /*(forward ? 1 : -1) * */ (leftTurn ? 1 : -1);
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
	servoProxy.correcRadius(calculateRadiusByMovement(positionCalculator.getCurrentMovement()));
	if((state == ss_driveStraightForward && stopConditionValue <= positionCalculator.distance) ||
		(state == ss_driveStraightBackward && stopConditionValue >= positionCalculator.distance) ||
		((state == ss_driveTurnLeftForward || state == ss_driveTurnRightBackward) && stopConditionValue <= positionCalculator.angle) ||
		((state == ss_driveTurnLeftBackward || state == ss_driveTurnRightForward) && stopConditionValue >= positionCalculator.angle) ){
		state = ss_stop;
		return true;
	}
	return false;
}