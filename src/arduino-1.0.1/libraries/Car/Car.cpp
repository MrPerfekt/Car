/*
* Copyright 2012 Andreas Gruber
*/

#include "Car.h"
	
Car::Car(){
	motorPowerEngine = new Motor(pinMotorPMW,pinMotorIn1,pinMotorIn2);

	servoProxy = new ServoProxy(/*pinSteeringServo*/);

	wheelSensor = new WheelSensor(pinWheelSensorR,pinWheelSensorL);
	positionCalculator = new PositionCalculator(*wheelSensor);

	steeringManager = new SteeringManager(*servoProxy,*motorPowerEngine,*positionCalculator);

	powerSupplyVoltageDivider = new VoltageDivider(apinVolDivPowerSupplay,volDivPowerSupplayRes1,volDivPowerSupplayRes2);
}

Motor& Car::getMotorPowerEngine(){
	return *motorPowerEngine;
}

ServoProxy& Car::getServoProxy(){
	return *servoProxy;
}

SteeringManager& Car::getSteeringManager(){
	return *steeringManager;
}

PositionCalculator& Car::getPositionCalculator(){
	return *positionCalculator;
}

WheelSensor& Car::getWheelSensor(){
	return *wheelSensor;
}

VoltageDivider& Car::getPowerSupplyVoltageDivider(){
	return *powerSupplyVoltageDivider;
}