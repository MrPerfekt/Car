/*!
Copyright 2012 Andreas Gruber
*/

#include "PathPlaner.h"
#include "OrientationCoordinates.h"
class Path;

PathPlaner::PathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor)
	:positionCalculator(positionCalculator)
	,pathExecutor(pathExecutor)
	,lastEndPosition(NULL){
}

Path* PathPlaner::calculatePath(const OrientationCoordinates& endPosition){
	return calculatePath(positionCalculator.getCurrentPosition(),endPosition);
}

void PathPlaner::moveTo(const OrientationCoordinates& endPosition){
	lastEndPosition = &endPosition;
	update();
}

void PathPlaner::update(){
	if(lastEndPosition != NULL)
		pathExecutor.setPath(calculatePath(*lastEndPosition));
}