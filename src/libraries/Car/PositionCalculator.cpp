/*!
Copyright 2012 Andreas Gruber
*/

#include "PositionCalculator.h"

MovementSensor& PositionCalculator::getMovementSensor() const{
	return movementSensor;
}
const OrientationCoordinates& PositionCalculator::getCurrentPosition() const{
	return *position;
}
const GeneralMovement& PositionCalculator::getFullMovement() const{
	return *fullMovement;
}

PositionCalculator::PositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor){//,fullMovement(new GeneralMovement()){
}
void PositionCalculator::update(){
	Movement& mov = movementSensor.getMovement();
	//*fullMovement += mov;
	*position *= mov;
}