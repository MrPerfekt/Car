/*
* Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR

#include "DefineLib.h"
#include "ServoProxy.h"
#include "WheelRotationSensors.h"
#include "VoltageDivider.h"
#include "MotorTB6612FNG.h"
#include "PositionCalculator.h"
#include "SteeringManager.h"

class Car {
private:
	//Pins
	//Steering Servo
	static const int pinSteeringServo = 7;
	//Motor
	static const int pinMotorPMW = 5;  
	static const int pinMotorIn1 = 6;  
	static const int pinMotorIn2 = 4;  
	//Wheels
	static const int pinWheelSensorR = 2;  
	static const int pinWheelSensorL = 3; 
	//Power Supplay Voltage Divider
	static const int apinVolDivPowerSupplay = 0;  
	static const unsigned long long volDivPowerSupplayRes1 = 966;
	static const unsigned long long volDivPowerSupplayRes2 = 1989;
	
	Motor* motorPowerEngine;
	ServoProxy* servoProxy;
	SteeringManager* steeringManager;
	PositionCalculator* positionCalculator;
	WheelSensor* wheelSensor;
	VoltageDivider* powerSupplyVoltageDivider;
	
public:
	Motor& getMotorPowerEngine();
	ServoProxy& getServoProxy();
	SteeringManager& getSteeringManager();
	PositionCalculator& getPositionCalculator();
	WheelSensor& getWheelSensor();
	VoltageDivider& getPowerSupplyVoltageDivider();

	Car();
};
#endif