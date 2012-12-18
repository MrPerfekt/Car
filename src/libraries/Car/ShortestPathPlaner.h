/*!
Copyright 2012 Andreas Gruber
*/

#ifndef SHORTEST_PATH_PLANER
#define SHORTEST_PATH_PLANER

#include "DefineLib.h"
class OrientationCoordinates;


class ShortestPathPlaner{
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