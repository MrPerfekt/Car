/*!
Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

const Coordinates PositionCalculator::getCurrentPosition(){
	return position;
}
const Movement PositionCalculator::getCurrentMovement(){
	return currentMovement;
}
const GeneralMovement PositionCalculator::getFullMovement(){
	return fullMovement;
}

PositionCalculator::PositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor),fullMovement(GeneralMovement()){
}
void PositionCalculator::update(){
	currentMovement = movementSensor.getMovement();
	fullMovement += currentMovement;
	position *= currentMovement;
}