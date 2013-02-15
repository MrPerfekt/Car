/*!
Copyright 2013 Andreas Gruber
*/

#ifndef POSITION_CALCULATOR
#define POSITION_CALCULATOR

#include "DefineLib.h"
class MovementSensor;
class GeneralMovement;
class OrientationCoordinates;

class PositionCalculator{
private:
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