/*!
Copyright 2012 Andreas Gruber
*/

#include "MovementPositionCalculator.h"
#include "Movement.h"
#include "MovementSensor.h"
#include "OrientationCoordinates.h"

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
	:movementSensor(movementSensor)
	,fullMovement(new GeneralMovement())
	,position(new OrientationCoordinates(0,0,PI))
	,lastMovement(movementSensor.getMovement()){
}
void MovementPositionCalculator::update(){
	lastMovement = movementSensor.getMovement();
	*fullMovement += lastMovement;
	*position *= lastMovement;
}