/*
* Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

PositionCalculator::PositionCalculator(WheelSensor& wheelSensor)
	:wheelSensor(wheelSensor){
}

Coordinates& PositionCalculator::getPosition(bool rightSteeringSign){
	return *(new Coordinates(0,0));
}

int PositionCalculator::getAngle(){
}

int PositionCalculator::setSteeringAngle(int angle){
}