/*!
Copyright 2013 Andreas Gruber
*/

#include "BluetoothModul.h"
#include "Car.h"
//#include "Config.h"
#include "DisplayProxy.h"
#include "DisplayServer.h"
#include "EnvironmentKnowledgeBase.h"
#include "ExecutableMovement.h"
#include "MotionLogger.h"
#include "MotorTB6612FNG.h"
#include "MouseSensorPan101BSI.h"
#include "MovementSensor.h"
#include "MovementPositionCalculator.h"
#include "PathExecutor.h"
#include "PathPlaner.h"
#include "PositionCalculator.h"
#include "PowerRegulator.h"
#include "RegularSteeringManager.h"
#include "RemoteServer.h"
#include "ServoProxy.h"
#include "ShortestPathPlaner.h"
#include "SonicDistanceSensor.h"
#include "SteeringManager.h"
#include "SteeringRegulator.h"
#include "Vehicle.h"
#include "VoltageDivider.h"
#include "WheelSensors.h"


BluetoothModul& Vehicle::getBluetoothModul(){
	return *bluetoothModul;
}
DisplayProxy& Vehicle::getDisplayProxy(){
	return *displayProxy;
}
DisplayServer& Vehicle::getDisplayServer(){
	return *displayServer;
}
EnvironmentKnowledgeBase& Vehicle::getEnvironmentKnowledgeBase(){
	return *environmentKnowledgeBase;
}
void Vehicle::setCurrentExecutingMovement(ExecutableMovement *currentExecutingMovement){
	this->currentExecutingMovement = currentExecutingMovement;
}
ExecutableMovement & Vehicle::getCurrentExecutingMovement(){
	return *currentExecutingMovement;
}
Motor& Vehicle::getMotorPowerEngine(){
	return *motorPowerEngine;
}
MotionLogger& Vehicle::getMotionLogger(){
	return *motionLogger;
}
MouseSensorPan101& Vehicle::getMouseSensor(){
	return *mouseSensor;
}
MovementSensor& Vehicle::getMovementSensor(){
	return *movementSensor;
}
void Vehicle::setMovementSensor(MovementSensor *movementSensor){
	this->movementSensor = movementSensor;
}
PathExecutor& Vehicle::getPathExecutor(){
	return *pathExecutor;
}
PathPlaner& Vehicle::getPathPlaner(){
	return *pathPlaner;
}
PositionCalculator& Vehicle::getPositionCalculator(){
	return *positionCalculator;
}
PowerRegulator& Vehicle::getPowerRegulator(){
	return *powerRegulator;
}
void Vehicle::setPowerRegulator(PowerRegulator *powerRegulator){
	this->powerRegulator = powerRegulator;
}
RemoteServer& Vehicle::getRemoteServer(){
	return *remoteServer;
}
ServoProxy& Vehicle::getServoProxy(){
	return *servoProxy;
}
SonicDistanceSensor** Vehicle::getSonicDistanceSensors(){
	return sonicDistanceSensors;
}
SteeringManager& Vehicle::getSteeringManager(){
	return *steeringManager;
}
SteeringRegulator& Vehicle::getSteeringRegulator(){
	return *steeringRegulator;
}
void Vehicle::setSteeringRegulator(SteeringRegulator *steeringRegulator){
	this->steeringRegulator = steeringRegulator;
}
Stream& Vehicle::getMainDataStreem(){
	return *mainDataStreem;
}
VoltageDivider& Vehicle::getPowerSupplyVoltageDivider(){
	return *powerSupplyVoltageDivider;
}
	
Vehicle::Vehicle(){
}

void Vehicle::init(){
	powerSupplyVoltageDivider = new VoltageDivider(Config::getPinAVolDivPowerSupplay(),Config::getVolDivPowerSupplayRes1(),Config::getVolDivPowerSupplayRes2());
	//displayProxy = new DisplayProxy();
	
	Serial2.begin(9600);
	mainDataStreem = &Serial2;
	bluetoothModul = new BluetoothModul(Serial2);

	motorPowerEngine = new Motor(Config::getPinMotorPMW(),Config::getPinMotorIn1(),Config::getPinMotorIn2());
	servoProxy = new ServoProxy();
	positionCalculator = new MovementPositionCalculator(getMovementSensor());
	steeringManager = new RegularSteeringManager(getServoProxy(),getMotorPowerEngine(),getPositionCalculator());
	
	environmentKnowledgeBase = new EnvironmentKnowledgeBase();
	for(uint8_t i = 0; i < Config::getSonicSensorCnt();i++)
		sonicDistanceSensors[i] = new SonicDistanceSensor(i,getPositionCalculator(),getEnvironmentKnowledgeBase());

	motionLogger = new MotionLogger(getPositionCalculator());
	pathExecutor = new PathExecutor(getSteeringManager());
	pathPlaner = new ShortestPathPlaner(getPositionCalculator(),getPathExecutor());
	
	remoteServer = new RemoteServer(*this);
	displayServer = new DisplayServer(*this);
}

Vehicle& Vehicle::getInstance(){
	static Vehicle *instance = new Car();
	return *instance;
}

void Vehicle::update(){
	//for(uint8_t i = 0; i < Config::getSonicSensorCnt();i++)
	//	sonicDistanceSensors[i]->update();
	remoteServer->update();
	displayServer->update();
	movementSensor->update();
	positionCalculator->update();
	remoteServer->update();
	displayServer->update();
	movementSensor->update();
	if(currentExecutingMovement != NULL) currentExecutingMovement->update();
	remoteServer->update();
	displayServer->update();
	movementSensor->update();
	if(currentExecutingMovement != NULL) currentExecutingMovement->update();
	remoteServer->update();
	displayServer->update();
	movementSensor->update();
	
	//motionLogger->update();
	//displayProxy->update();
}