/*!
Copyright 2012 Andreas Gruber
*/

#include "EnvironmentPathPlaner.h"
#include "Coordinates.h"
#include "Path.h"

EnvironmentPathPlaner::EnvironmentPathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor)
	:PathPlaner(positionCalculator,pathExecutor){
}

Path* EnvironmentPathPlaner::calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition){
	return 0;
}

void EnvironmentPathPlaner::update(){
}