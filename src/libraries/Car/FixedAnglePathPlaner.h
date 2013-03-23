/*!
Copyright 2013 Andreas Gruber
*/

#ifndef FIXED_ANGLE_PATH_PLANER
#define FIXED_ANGLE_PATH_PLANER

#include "DefineLib.h"
#include "PositionCalculator.h"
class OrientationCoordinates;
class Path;

class FixedAnglePathPlaner{
private:
	PositionCalculator &positionCalculator;
	const OrientationCoordinates *currentEndPosition;
protected:
	/*!
	Calculate Path
	@param startPosition The start point
	@param endPosition The destination point
	*/
	virtual Path* calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition) = 0;
public:
	FixedAnglePathPlaner(PositionCalculator &positionCalculator);
	/*!
	Move to the position
	@param endPosition The destination.
	*/
	void moveTo(const OrientationCoordinates* endPosition);
	/*!
	Calculate Path
	StartPosition: The current position
	@param endPosition The destination point
	*/
	Path* calculatePath(const OrientationCoordinates& endPosition);
	/*!
	This method updates the path to the specified target.
	Before this method can be called moveTo(position) and positionCalculator.update() have to be executed.
	*/
	void update();
};

#endif