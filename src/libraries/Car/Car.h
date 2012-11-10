/*!
Copyright 2012 Andreas Gruber
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
#include "MotionLogger.h"

class Car {
private:	
	DisplayProxy* displayProxy;
	Motor* motorPowerEngine;
	ServoProxy* servoProxy;
	SteeringManager* steeringManager;
	PositionCalculator* positionCalculator;
	WheelSensor* wheelSensor;
	VoltageDivider* powerSupplyVoltageDivider;
	MouseSensorPan101* mouseSensor;
	MovementSensor* movementSensor;
	MotionLogger* motionLogger;
public: 
	Motor& getMotorPowerEngine();
	ServoProxy& getServoProxy();
	SteeringManager& getSteeringManager();
	PositionCalculator& getPositionCalculator();
	WheelSensor& getWheelSensor();
	VoltageDivider& getPowerSupplyVoltageDivider();
	MouseSensorPan101& getMouseSensor();
	MovementSensor& getMovementSensor();
	MotionLogger& getMotionLogger();

	/*!
	It is recomendet to invoke this method in a loop because it handle the full activity of the car.
	*/
	Car();

	void update();
};
#endif