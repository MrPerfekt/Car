/*
* Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

Coordinates PositionCalculator::getCurrentPosition(){
	return position;
}
Movement PositionCalculator::getCurrentMovement(){
	return currentMovement;
}

PositionCalculator::PositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor),angle(0),distance(0){
}
void PositionCalculator::update(){
	currentMovement = movementSensor.getMovement();
	distance += currentMovement.distance;
	angle += currentMovement.angle;
	//=====================
	Serial.print("d: ");
	Serial.print(distance);
	Serial.print(", a: ");
	Serial.println(angle);
	//=====================
	position.x += currentMovement.distance * sin(currentMovement.angle);//ToDo
	position.y += currentMovement.distance * cos(currentMovement.angle);//ToDo
}