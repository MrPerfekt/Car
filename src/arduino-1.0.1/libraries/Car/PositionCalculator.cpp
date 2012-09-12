/*
* Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

PositionCalculator::PositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor){
}
Coordinates& PositionCalculator::getPosition(bool leftSteeringSign){
	return *(new Coordinates(0,0));
}
int PositionCalculator::getAngle(){
}
int PositionCalculator::getDistance(){
}
void PositionCalculator::update(){
}