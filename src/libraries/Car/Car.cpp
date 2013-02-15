/*!
Copyright 2012 Andreas Gruber
*/

#include "BluetoothModul.h"
#include "Car.h"
//#include "Config.h"
#include "DisplayProxy.h"
#include "DisplayServer.h"
#include "EnvironmentKnowledgeBase.h"
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
#include "VoltageDivider.h"
#include "WheelSensors.h"

WheelSensor& Car::getWheelSensor(){	
	return *wheelSensor;
}
	
Car::Car(){
}

void Car::init(){
#if true
	wheelSensor = new WheelSensor();
	setMovementSensor(wheelSensor);
#else
	mouseSensor = new MouseSensorPan101();
	setMovementSensor(mouseSensor);
#endif
	Vehicle::init();
}