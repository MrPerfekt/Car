/*
* Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

Coordinate::Coordinate(long x,long y)
	:x(x),y(y)
{}

PositionCalculator::PositionCalculator(WheelSensor& wheelSensor,Motor& motorPowerEngine,ServoSteeringDriver& servoSteeringDriver)
	:wheelSensor(wheelSensor),motorPowerEngine(motorPowerEngine),servoSteeringDriver(servoSteeringDriver){
}

Coordinate& PositionCalculator::getPosition(bool rightSteeringSign){
	return *(new Coordinate(0,0));
}

int PositionCalculator::getAngle(){
}

int PositionCalculator::setSteeringAngle(int angle){
}