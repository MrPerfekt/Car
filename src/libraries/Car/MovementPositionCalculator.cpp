/*!
Copyright 2012 Andreas Gruber
*/

#include "MovementPositionCalculator.h"
#include "Movement.h"
#include "MovementSensor.h"
#include "Coordinates.h"

Movement& MovementPositionCalculator::getLastMovement() const{
	return lastMovement;
}
const OrientationCoordinates& MovementPositionCalculator::getCurrentPosition() const{
	return *position;
}
const GeneralMovement& MovementPositionCalculator::getFullMovement() const{
	return *fullMovement;
}

MovementPositionCalculator::MovementPositionCalculator(MovementSensor& movementSensor)
	:movementSensor(movementSensor),fullMovement(new GeneralMovement()),position(new OrientationCoordinates()),lastMovement(movementSensor.getMovement()){
}
void MovementPositionCalculator::update(){
	lastMovement = movementSensor.getMovement();
	*fullMovement += lastMovement;
	*position *= lastMovement;
}