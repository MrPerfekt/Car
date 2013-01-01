/*!
Copyright 2012 Andreas Gruber
*/

#include "ShortestPathPlaner.h"
#include "Coordinates.h"
#include "Path.h"

//! TODO Invoke super constructor
ShortestPathPlaner::ShortestPathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor)
	:PathPlaner(positionCalculator,pathExecutor)
{
}

Path* ShortestPathPlaner::calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition){

	return 0;
}

void ShortestPathPlaner::update(){
}