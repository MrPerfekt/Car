/*!
Copyright 2012 Andreas Gruber
*/

#ifndef PATH_PLANER
#define PATH_PLANER

#include "DefineLib.h"
//#include "Coordinates.h"
//#include "PositionCalculator.h"
class OrientationCoordinates;

class PathPlaner{
private:
public:
	/*!
	Set the destination of the car.
	\param position The destination.
	*/
	virtual void moveTo(const OrientationCoordinates position) = 0;
	/*!
	This method updates the path to the specified target.
	Before this method can be called moveTo(position) and positionCalculator.update() have to be executed.
	*/
	virtual void update() = 0;
};

#endif