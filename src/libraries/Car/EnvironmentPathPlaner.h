/*!
Copyright 2013 Andreas Gruber
*/

#ifndef ENVIRONMENT_PATH_PLANER
#define ENVIRONMENT_PATH_PLANER

#include "DefineLib.h"
#include "PathPlaner.h"
class OrientationCoordinates;
class PathExecutor;
class PositionCalculator;

class EnvironmentPathPlaner : public PathPlaner{
private:
public:
	EnvironmentPathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor);
	/*!
	Calculate Path
	@param startPosition The start point
	@param endPosition The destination point
	*/
	Path* calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition);
};

#endif