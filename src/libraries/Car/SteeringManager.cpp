/*!
Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringState SteeringManager::getState(){
	return state;
}

SteeringManager::SteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator)
	:servoProxy(servoProxy),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator),steeringWheelsPosition(steeringWheelsPosition)
{}

double SteeringManager::calculateRadiusByMovement(const Movement& movement){
	return movement.getDistance() * circle / movement.getAngle() / (2*M_PI)/*calculates radius*/;
}

void SteeringManager::driveStraight(double distance){
	bool forward = distance >= 0;
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.getFullMovement().getDistance() + (forward ? distance : -distance);
	state = forward ? ss_driveStraightForward : ss_driveStraightBackward;
	motorPowerEngine.motorMove(255,forward);
}
void SteeringManager::driveTurn(double radius, double angle){
	bool leftTurn = radius >= 0;
	bool forward = angle >= 0;
	servoProxy.setRadius(radius);
	stopConditionValue = positionCalculator.getFullMovement().getAngle() + angle * /*(forward ? 1 : -1) * */ (leftTurn ? 1 : -1);
	if(leftTurn)
		state = forward ? ss_driveTurnLeftForward : ss_driveTurnLeftBackward;
	else
		state = forward ? ss_driveTurnRightForward : ss_driveTurnRightBackward;
	motorPowerEngine.motorMove(255,forward);
}
void SteeringManager::update(){
	Movement& m = positionCalculator.getMovementSensor().getMovement();
	if(m.getDistance() == 0) return;
	servoProxy.correcRadius(calculateRadiusByMovement(m));
	if((state == ss_driveStraightForward && stopConditionValue <= positionCalculator.getFullMovement().getDistance()) ||
		(state == ss_driveStraightBackward && stopConditionValue >= positionCalculator.getFullMovement().getDistance()) ||
		((state == ss_driveTurnLeftForward || state == ss_driveTurnRightBackward) && stopConditionValue <= positionCalculator.getFullMovement().getAngle()) ||
		((state == ss_driveTurnLeftBackward || state == ss_driveTurnRightForward) && stopConditionValue >= positionCalculator.getFullMovement().getAngle()) ){
		state = ss_stop;
	}
}
void SteeringManager::stop(){
	state = ss_stop;
	motorPowerEngine.motorBreak();
}