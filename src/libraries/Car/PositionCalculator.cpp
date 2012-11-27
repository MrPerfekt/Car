/*!
Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

Movement& PositionCalculator::getLastMovement() const{
	return lastMovement;
}
const OrientationCoordinates& PositionCalculator::getCurrentPosition() const{
	return *position;
}
const GeneralMovement& PositionCalculator::getFullMovement() const{
	return *fullMovement;
}

PositionCalculator::PositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor),fullMovement(new GeneralMovement()),position(new OrientationCoordinates()),lastMovement(movementSensor.getMovement()){
}
void PositionCalculator::update(){
	lastMovement = movementSensor.getMovement();
	*fullMovement += lastMovement;
	*position *= lastMovement;
}