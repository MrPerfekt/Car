/*!
Copyright 2012 Andreas Gruber
*/

#include "Car.h"
//#include "Config.h"
#include "DisplayProxy.h"
#include "DisplayServer.h"
#include "MotionLogger.h"
#include "MotorTB6612FNG.h"
#include "MouseSensorPan101BSI.h"
#include "MovementSensor.h"
#include "MovementPositionCalculator.h"
#include "PathExecutor.h"
#include "PathPlaner.h"
#include "PositionCalculator.h"
#include "RegularSteeringManager.h"
#include "RemoteServer.h"
#include "ServoProxy.h"
#include "ShortestPathPlaner.h"
#include "SteeringManager.h"
#include "VoltageDivider.h"
#include "WheelSensors.h"

DisplayProxy& Car::getDisplayProxy(){
	return *displayProxy;
}
DisplayServer& Car::getDisplayServer(){
	return *displayServer;
}
Motor& Car::getMotorPowerEngine(){
	return *motorPowerEngine;
}
MotionLogger& Car::getMotionLogger(){
	return *motionLogger;
}
MouseSensorPan101& Car::getMouseSensor(){
	return *mouseSensor;
}
MovementSensor& Car::getMovementSensor(){
	return *movementSensor;
}
PathExecutor& Car::getPathExecutor(){
	return *pathExecutor;
}
PathPlaner& Car::getPathPlaner(){
	return *pathPlaner;
}
PositionCalculator& Car::getPositionCalculator(){
	return *positionCalculator;
}
RemoteServer& Car::getRemoteServer(){
	return *remoteServer;
}
ServoProxy& Car::getServoProxy(){
	return *servoProxy;
}
SteeringManager& Car::getSteeringManager(){
	return *steeringManager;
}
VoltageDivider& Car::getPowerSupplyVoltageDivider(){
	return *powerSupplyVoltageDivider;
}
WheelSensor& Car::getWheelSensor(){	
	return *wheelSensor;
}
	
Car::Car(){	
	//displayProxy = new DisplayProxy();

	//mouseSensor = new MouseSensorPan101();
	wheelSensor = new WheelSensor();
#if true
	movementSensor = wheelSensor;
#else
	movementSensor = mouseSensor;
#endif
	motorPowerEngine = new Motor();
	servoProxy = new ServoProxy();
	positionCalculator = new MovementPositionCalculator(*movementSensor);
	steeringManager = new RegularSteeringManager(*servoProxy,*motorPowerEngine,*positionCalculator);
	powerSupplyVoltageDivider = new VoltageDivider(Config::getPinAVolDivPowerSupplay(),Config::getVolDivPowerSupplayRes1(),Config::getVolDivPowerSupplayRes2());

	motionLogger = new MotionLogger(*positionCalculator);
	pathExecutor = new PathExecutor(*steeringManager);
	pathPlaner = new ShortestPathPlaner(*positionCalculator,*pathExecutor);

	remoteServer = new RemoteServer(*this);
}

void Car::update(){
	movementSensor->update();
	positionCalculator->update();
	movementSensor->update();
	steeringManager->update();
	movementSensor->update();
	pathExecutor->update();
	movementSensor->update();
	
	//motionLogger->update();
	//displayProxy->update();
}