/*!
Copyright 2012 Andreas Gruber
*/

#include "RegularSteeringManager.h"
#include "SteeringManager.h"
#include "MotorTB6612FNG.h"
#include "PositionCalculator.h"
#include "Movement.h"
#include "ServoProxy.h"

RegularSteeringManager::SteeringState RegularSteeringManager::getState(){
	return state;
}
void RegularSteeringManager::setState(SteeringState steeringState){
	state = steeringState;
}

/*!
@return If the current steering action has finnished.
*/
bool RegularSteeringManager::hasFinished(){
	return getState() == ss_stop;
}

/*!
Get the maximal radius of the car
\param leftTurn If the car should drive a left [= true] or a right [= false] turn
\return The maximal radius 
*/
double RegularSteeringManager::getMaxRadius(bool leftTurn){
	servoProxy.getMaxRadius(leftTurn);
}

RegularSteeringManager::RegularSteeringManager(ServoProxy& servoProxy,Motor& motorPowerEngine,PositionCalculator& positionCalculator)
	:servoProxy(servoProxy)
	,motorPowerEngine(motorPowerEngine)
	,positionCalculator(positionCalculator)
	,state(ss_stop){
}

const double RegularSteeringManager::calculateRadiusByMovement(const Movement& movement) const{
	return movement.getDistance() * circle / movement.getAngle() / (2*M_PI)/*calculates radius*/;
}

void RegularSteeringManager::driveStraight(double distance){
	bool forward = distance >= 0;
	servoProxy.setSteeringAngle(0);
	stopConditionValue = positionCalculator.getFullMovement().getDistance() + (forward ? distance : -distance);
	setState(forward ? ss_driveStraightForward : ss_driveStraightBackward);
	motorPowerEngine.motorMove(255,forward);
}
void RegularSteeringManager::driveTurn(double radius, double angle){
	bool leftTurn = radius >= 0;
	bool forward = angle >= 0;
	servoProxy.setRadius(radius);
	stopConditionValue = positionCalculator.getFullMovement().getAngle() + angle * /*(forward ? 1 : -1) * */ (leftTurn ? 1 : -1);
	if(leftTurn)
		setState(forward ? ss_driveTurnLeftForward : ss_driveTurnLeftBackward);
	else
		setState(forward ? ss_driveTurnRightForward : ss_driveTurnRightBackward);
	motorPowerEngine.motorMove(255,forward);
}
/*! Optimized for servo steering control */
void RegularSteeringManager::update(){
	Movement& m = positionCalculator.getLastMovement();
	//======
	//Serial.print(m.getAngle());
	//Serial.print("  ");
	//Serial.println(m.getDistance());
	//======
	if(m.getDistance() == 0) return;
	servoProxy.correcRadius(calculateRadiusByMovement(m));
	if((state == ss_driveStraightForward && stopConditionValue <= positionCalculator.getFullMovement().getDistance()) ||
		(state == ss_driveStraightBackward && stopConditionValue >= positionCalculator.getFullMovement().getDistance()) ||
		((state == ss_driveTurnLeftForward || state == ss_driveTurnRightBackward) && stopConditionValue <= positionCalculator.getFullMovement().getAngle()) ||
		((state == ss_driveTurnLeftBackward || state == ss_driveTurnRightForward) && stopConditionValue >= positionCalculator.getFullMovement().getAngle()) ){
		setState(ss_stop);
	}
}
void RegularSteeringManager::stop(){
	state = ss_stop;
	motorPowerEngine.motorBreak();
}