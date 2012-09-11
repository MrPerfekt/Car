/*
* Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

Coordinate::Coordinate(long x,long y)
	:x(x),y(y)
{}

PositionCalculator::PositionCalculator(WheelSensor& wheelSensor)
	:wheelSensor(wheelSensor){
}

Coordinate& PositionCalculator::getPosition(bool rightSteeringSign){
	return *(new Coordinate(0,0));
}

int PositionCalculator::getAngle(){
}

int PositionCalculator::setSteeringAngle(int angle){
}