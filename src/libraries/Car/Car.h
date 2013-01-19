/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR

#include "DefineLib.h"

class BluetoothModul;
class DisplayProxy;
class DisplayServer;
class MotionLogger;
class Motor;
class MouseSensorPan101;
class MovementSensor;
class PathExecutor;
class PathPlaner;
class PositionCalculator;
class RemoteServer;
class ServoProxy;
class SteeringManager;
class VoltageDivider;
class WheelSensor;

class Car {
private:	
	BluetoothModul* bluetoothModul;
	DisplayProxy* displayProxy;
	DisplayServer* displayServer;
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
	Stream* mainDataStreem;
	VoltageDivider* powerSupplyVoltageDivider;
	WheelSensor* wheelSensor;
public: 
	BluetoothModul& getBluetoothModul();
	DisplayProxy& getDisplayProxy();
	DisplayServer& getDisplayServer();
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
	Stream& getMainDataStreem();
	VoltageDivider& getPowerSupplyVoltageDivider();
	WheelSensor& getWheelSensor();

	Car();

	/*!
	It is recomendet to invoke this method in a loop because it handle the full activity of the car.
	*/
	void update();
};
#endif