/*!
Copyright 2012 Andreas Gruber
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
	,adjustmentCalculation(new StraightAdjustmentCalculation())
	//,adjustmentCalculation(new PartialAdjustmentCalculation())
	//,adjustmentCalculation(new RegressionAdjustmentCalculation())
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
/*!
Because the steering mechanism can has mechanical tollerances the radius can be updated based on measured values.
\param currentRadius The real radius of the car
*/
void CarSteeringRegulator::correcRadius(double currentRadius){
	correctSteeringServoAngle(convertRadiusToSteeringWheelAngle(currentRadius)); //! This is not correct but the best existing solution.
}
void CarSteeringRegulator::correctSteeringServoAngle(double currentRealSteeringAngle){
	adjustmentCalculation->correctLastValue(currentRealSteeringAngle);
	servoProxy->setServoAngle(adjustmentCalculation->getResult());
}