/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR

#include "DefineLib.h"

class MotionLogger;
class PathExecutor;
class PathPlaner;
class DisplayProxy;
class Motor;
class ServoProxy;
class WheelSensor;
class VoltageDivider;
class MouseSensorPan101;
class SteeringManager;
class PositionCalculator;
class MovementSensor;
class RemoteServer;

class Car {
private:	
	DisplayProxy* displayProxy;
	MotionLogger* motionLogger;
	Motor* motorPowerEngine;
	MouseSensorPan101* mouseSensor;
	MovementSensor* movementSensor;
	PathExecutor* pathExecutor;
	PathPlaner* pathPlaner;
	PositionCalculator* positionCalculator;
	RemoteServer* remoteServer;
	ServoProxy* servoProxy;
	SteeringManager* steeringManager;
	VoltageDivider* powerSupplyVoltageDivider;
	WheelSensor* wheelSensor;
public: 
	DisplayProxy& getDisplayProxy();
	MotionLogger& getMotionLogger();
	Motor& getMotorPowerEngine();
	MouseSensorPan101& getMouseSensor();
	MovementSensor& getMovementSensor();
	PathExecutor& getPathExecutor();
	PathPlaner& getPathPlaner();
	PositionCalculator& getPositionCalculator();
	RemoteServer& getRemoteServer();
	ServoProxy& getServoProxy();
	SteeringManager& getSteeringManager();
	VoltageDivider& getPowerSupplyVoltageDivider();
	WheelSensor& getWheelSensor();

	Car();

	/*!
	It is recomendet to invoke this method in a loop because it handle the full activity of the car.
	*/
	void update();
};
#endif