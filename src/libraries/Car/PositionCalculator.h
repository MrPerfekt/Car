/*!
Copyright 2012 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include "DefineLib.h"
class MovementSensor;
class GeneralMovement;

class PositionCalculator{
private:
	/*
	MovementSensor& movementSensor;
	/*!
	The absolute position of the car
	* /
	OrientationCoordinates* position;
	/*!
	The full movement of the car since the class was loaded.
	* /
	GeneralMovement* fullMovement;
	/*!
	The last movement which was readen out
	* /
	Movement& lastMovement;
	*/
public:
	virtual Movement& getLastMovement() const = 0;
	virtual const OrientationCoordinates& getCurrentPosition() const = 0;
	virtual const GeneralMovement& getFullMovement() const = 0;
	/*!
	This method updates the position and the currentMovement of the positionCalculator
	Note: Before this method can be used movementSensor.update() have to be invoked.
	*/
	virtual void update() = 0;
};

#endif