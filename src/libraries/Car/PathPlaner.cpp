/*!
Copyright 2012 Andreas Gruber
*/

#include "PathPlaner.h"
#include "Coordinates.h"
class Path;

PathPlaner::PathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor)
	:positionCalculator(positionCalculator)
	,pathExecutor(pathExecutor){
}

void PathPlaner::moveTo(const OrientationCoordinates position){
}
