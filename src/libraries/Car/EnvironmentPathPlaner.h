/*!
Copyright 2012 Andreas Gruber
*/

#ifndef ENVIRONMENT_PATH_PLANER
#define ENVIRONMENT_PATH_PLANER

#include "DefineLib.h"
#include "PathPlaner.h"
class OrientationCoordinates;

class EnvironmentPathPlaner : public PathPlaner{
private:
public:
	/*!
	Set the destination of the car.
	\param position The destination.
	*/
	void moveTo(const OrientationCoordinates position);
	/*!
	This method updates the path to the specified target.
	Before this method can be called moveTo(position) and positionCalculator.update() have to be executed.
	*/
	void update();
};

#endif