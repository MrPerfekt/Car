/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT_POSITION_CALCULATOR
#define MOVEMENT_POSITION_CALCULATOR

#include "DefineLib.h"
#include "PositionCalculator.h"
class MovementSensor;
class Movement;
class GeneralMovement;
class OrientationCoordinates;

class MovementPositionCalculator : public PositionCalculator{
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
	MovementPositionCalculator(MovementSensor& movementSensor);
	/*!
	This method updates the position and the currentMovement of the positionCalculator
	Note: Before this method can be used movementSensor.update() have to be invoked.
	*/
	void update();
};

#endif