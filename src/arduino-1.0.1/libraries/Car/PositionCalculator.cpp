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
void PositionCalculator::update(){
	currentMovement = movementSensor.getMovement();
	distance += currentMovement.distance;
	angle += currentMovement.angle;
	position.x += currentMovement.distance * sin(currentMovement.angle);//ToDo
	position.y += currentMovement.distance * cos(currentMovement.angle);//ToDo
}