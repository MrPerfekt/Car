/*!
Copyright 2012 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include "DefineLib.h"
#include "MovementSensor.h"
#include "Coordinates.h"
#include "math.h"

class PositionCalculator{
private:
	MovementSensor& movementSensor;
	Coordinates position;
	Movement currentMovement;
public:
	Movement fullMovement;
	Coordinates getCurrentPosition();
	Movement getCurrentMovement();
	PositionCalculator(MovementSensor& movementSensor);
	/*!
	This method updates the position and the currentMovement of the positionCalculator
	Note: Before this method can be used movementSensor.update() have to be invoked.
	*/
	void update();
};

#endif