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
	OrientationCoordinates* position;
	/*!
	The full movement of the car since the class was loaded.
	*/
	GeneralMovement* fullMovement;
	/*!
	The last movement which was readen out
	*/
	Movement& lastMovement;
public:
	Movement& getLastMovement() const;
	const OrientationCoordinates& getCurrentPosition() const;
	const GeneralMovement& getFullMovement() const;
	PositionCalculator(MovementSensor& movementSensor);
	/*!
	This method updates the position and the currentMovement of the positionCalculator
	Note: Before this method can be used movementSensor.update() have to be invoked.
	*/
	void update();
};

#endif