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
	/*!
	The absolute position of the car
	*/
	Coordinates position;
	/*!
	The last movement which was recordet.
	*/
	Movement currentMovement;
	/*!
	The full movement of the car since the class was loaded.
	*/
	GeneralMovement fullMovement;
public:
	const Coordinates getCurrentPosition();
	const Movement getCurrentMovement();
	const GeneralMovement getFullMovement();
	PositionCalculator(MovementSensor& movementSensor);
	/*!
	This method updates the position and the currentMovement of the positionCalculator
	Note: Before this method can be used movementSensor.update() have to be invoked.
	*/
	void update();
};

#endif