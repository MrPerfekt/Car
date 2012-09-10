/*
* Copyright 2012 Andreas Gruber
*/

#include "Car.h"
	
Car::Car(){
	motorPowerEngine = new Motor(pinMotorPMW,pinMotorIn1,pinMotorIn2);

	servoSteeringDriver = new ServoSteeringDriver(pinSteeringServo);

	wheelSensor = new WheelSensor(pinWheelSensorR,pinWheelSensorL);
	positionCalculator = new PositionCalculator(*wheelSensor,*motorPowerEngine,*servoSteeringDriver);

	steeringManager = new SteeringManager(*servoSteeringDriver,*motorPowerEngine,*positionCalculator);

	powerSupplyVoltageDivider = new VoltageDivider(apinVolDivPowerSupplay,volDivPowerSupplayRes1,volDivPowerSupplayRes2);
}

Motor& Car::getMotorPowerEngine(){
	return *motorPowerEngine;
}

ServoSteeringDriver& Car::getServoSteeringDriver(){
	return *servoSteeringDriver;
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