/*
* Copyright 2012 Andreas Gruber
*/

#include "Car.h"
	
Car::Car(){	
	displayProxy = new DisplayProxy(pinDisplayRST, pinDisplayCS, pinDisplayClk, pinDisplayData);

	mouseSensor = new MouseSensorPan101(pinMouseSensorSCK,pinMouseSensorSDA,pinMouseSensorPD,mouseSensorCenterDistance);
	wheelSensor = new WheelSensor(pinWheelSensorR,pinWheelSensorL);
	movementSensor = mouseSensor;//wheelSensor

	motorPowerEngine = new Motor(pinMotorPMW,pinMotorIn1,pinMotorIn2);
	servoProxy = new ServoProxy(steeringWheelsPosition);
	positionCalculator = new PositionCalculator(*movementSensor);
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

MouseSensorPan101& Car::getMouseSensor(){
	return *mouseSensor;
}

MovementSensor& Car::getMovementSensor(){
	return *movementSensor;
}

VoltageDivider& Car::getPowerSupplyVoltageDivider(){
	return *powerSupplyVoltageDivider;
}