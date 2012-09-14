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
	return angle;
}
int PositionCalculator::getDistance(){
	return distance;
}
void PositionCalculator::update(){
	Movement mov = movementSensor.getMovement();
	distance += mov.distance;
	angle += mov.angle;
	position.x += mov.distance * cos(mov.angle);//ToDo
	position.y += mov.distance * sin(mov.angle);//ToDo
}