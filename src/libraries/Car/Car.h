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
	//Constants
	//Car measures
	static const uint32_t steeringWheelsPosition = 230;
	//Steering Servo
	static const uint8_t pinSteeringServo = 7;
	//Motor
	static const uint8_t pinMotorPMW = 5;
	static const uint8_t pinMotorIn1 = 6;
	static const uint8_t pinMotorIn2 = 4;
	//Wheels
	static const uint8_t pinWheelSensorR = 2;
	static const uint8_t pinWheelSensorL = 3;
	//Power Supplay Voltage Divider
	static const uint8_t apinVolDivPowerSupplay = 0;
	static const unsigned long long volDivPowerSupplayRes1 = 966;
	static const unsigned long long volDivPowerSupplayRes2 = 1989;
	//MouseSensor
	static const uint8_t pinMouseSensorSCK = 12;
	static const uint8_t pinMouseSensorSDA = 10;
	static const uint8_t pinMouseSensorPD = A1;
	static const uint32_t mouseSensorCenterDistance = 300;
	//Display
	static const uint8_t pinDisplayRST = 8;
	static const uint8_t pinDisplayCS = 9;
	static const uint8_t pinDisplayClk = 13;
	static const uint8_t pinDisplayData = 11;
	
	DisplayProxy* displayProxy;
	Motor* motorPowerEngine;
	ServoProxy* servoProxy;
	SteeringManager* steeringManager;
	PositionCalculator* positionCalculator;
	WheelSensor* wheelSensor;
	VoltageDivider* powerSupplyVoltageDivider;
	MouseSensorPan101* mouseSensor;
	MovementSensor* movementSensor;
public: 
	Motor& getMotorPowerEngine();
	ServoProxy& getServoProxy();
	SteeringManager& getSteeringManager();
	PositionCalculator& getPositionCalculator();
	WheelSensor& getWheelSensor();
	VoltageDivider& getPowerSupplyVoltageDivider();
	MouseSensorPan101& getMouseSensor();
	MovementSensor& getMovementSensor();

	Car();
};
#endif