/*
* Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR

#include "DefineLib.h"
#include "Coordinates.h"
#include "MouseSensorPan101BSI.h"
#include "ServoProxy.h"
#include "WheelSensors.h"
#include "VoltageDivider.h"
#include "MotorTB6612FNG.h"
#include "PositionCalculator.h"
#include "SteeringManager.h"
#include "DisplayProxy.h"

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
	//MouseSensor
	static const int pinMouseSensorSCK = 12;
	static const int pinMouseSensorSDA = 10;
	static const int pinMouseSensorPD = A1;
	static const long mouseSensorCenterDistance = 300000;
	//Display
	static const char pinDisplayRST = 8;
	static const char pinDisplayCS = 9;
	static const char pinDisplayClk = 13;
	static const char pinDisplayData = 11;
	
	Motor* motorPowerEngine;
	ServoProxy* servoProxy;
	SteeringManager* steeringManager;
	PositionCalculator* positionCalculator;
	WheelSensor* wheelSensor;
	VoltageDivider* powerSupplyVoltageDivider;
	MouseSensorPan101* mouseSensor;
	DisplayProxy* displayProxy;

public:
	Motor& getMotorPowerEngine();
	ServoProxy& getServoProxy();
	SteeringManager& getSteeringManager();
	PositionCalculator& getPositionCalculator();
	WheelSensor& getWheelSensor();
	VoltageDivider& getPowerSupplyVoltageDivider();
	MouseSensorPan101& getMouseSensor();

	Car();
};
#endif