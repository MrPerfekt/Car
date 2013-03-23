/*!
Copyright 2013 Andreas Gruber
*/

#include "CarSteeringRegulator.h"

#include "AdjustmentCalculation.h"
#include "Config.h"
#include "PartialAdjustmentCalculation.h"
#include "RegressionAdjustmentCalculation.h"
#include "ServoProxy.h"
#include "StraightAdjustmentCalculation.h"

CarSteeringRegulator::CarSteeringRegulator()
	:servoProxy(new ServoProxy())
	,adjustmentCalculation(new StraightAdjustmentCalculation(-PI/2,PI/2))
	//,adjustmentCalculation(new PartialAdjustmentCalculation(-PI/2,PI/2))
	//,adjustmentCalculation(new RegressionAdjustmentCalculation(-PI/2,PI/2))
{
}
CarSteeringRegulator::~CarSteeringRegulator(){
	delete servoProxy;
}

const double CarSteeringRegulator::getMinRadius() const{
	return Config::getMinSteeringRadius();
}

void CarSteeringRegulator::turnOnOff(bool on){
}



double CarSteeringRegulator::convertRadiusToSteeringWheelAngle(double radius){
	return atan(Config::getSteeringWheelsPosition()/radius); //! ToDo: Test with *(-1)
}
double CarSteeringRegulator::convertSteeringWheelAngleToRadius(double steeringWheelAngle){
	return Config::getSteeringWheelsPosition()/tan(steeringWheelAngle); //! ToDo: Test with *(-1)
}

void CarSteeringRegulator::setRadius(double radius){
	setSteeringServoAngle(convertRadiusToSteeringWheelAngle(radius)); //! This is not correct but the best existing solution.
}
void CarSteeringRegulator::setSteeringServoAngle(double angle){
	adjustmentCalculation->setValue(angle);
	servoProxy->setServoAngle(adjustmentCalculation->getResult());
}
//!================Correct Methods================
void CarSteeringRegulator::correcRadius(double currentRadius){
	correctSteeringServoAngle(convertRadiusToSteeringWheelAngle(currentRadius)); //! This is not correct but the best existing solution.
}
void CarSteeringRegulator::correctSteeringServoAngle(double currentRealSteeringAngle){
	adjustmentCalculation->correctLastValue(currentRealSteeringAngle);
	servoProxy->setServoAngle(adjustmentCalculation->getResult());
}