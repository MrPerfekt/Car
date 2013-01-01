/*!
Copyright 2012 Andreas Gruber
*/

#ifndef SHORTEST_PATH_PLANER
#define SHORTEST_PATH_PLANER

#include "DefineLib.h"
#include "PathPlaner.h"
class OrientationCoordinates;
class Path;
class PositionCalculator;
class PathExecutor;

class ShortestPathPlaner : public PathPlaner{
private:
public:
	ShortestPathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor);
	/*!
	Calculate Path
	@param startPosition The start point
	@param endPosition The destination point
	*/
	Path* calculatePath(const OrientationCoordinates &startPosition, const OrientationCoordinates &endPosition);
};

#endif