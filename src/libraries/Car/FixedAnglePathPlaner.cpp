/*!
Copyright 2012 Andreas Gruber
*/

#include "FixedAnglePathPlaner.h"
#include "Path.h"
#include "PositionCalculator.h"

FixedAnglePathPlaner::FixedAnglePathPlaner(PositionCalculator &positionCalculator)
	:positionCalculator(positionCalculator)
	,currentEndPosition(NULL){
}

Path* FixedAnglePathPlaner::calculatePath(const OrientationCoordinates& endPosition){
	return calculatePath(positionCalculator.getCurrentPosition(),endPosition);
}

void FixedAnglePathPlaner::moveTo(const OrientationCoordinates* endPosition){
	currentEndPosition = endPosition;
	update();
}

void FixedAnglePathPlaner::update(){
	if(currentEndPosition != NULL)
		calculatePath(*currentEndPosition)->executeAndDelete();
}