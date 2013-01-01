/*!
Copyright 2012 Andreas Gruber
*/

#include "Car.h"
#include "MotionLogger.h"
#include "PathExecutor.h"
#include "ShortestPathPlaner.h"

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
MotionLogger& Car::getMotionLogger(){
	return *motionLogger;
}
PathExecutor& Car::getPathExecutor(){
	return *pathExecutor;
}
PathPlaner& Car::getPathPlaner(){
	return *pathPlaner;
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