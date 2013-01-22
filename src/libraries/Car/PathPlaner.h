/*!
Copyright 2012 Andreas Gruber
*/

#ifndef PATH_PLANER
#define PATH_PLANER

#include "DefineLib.h"
#include "PositionCalculator.h"
#include "PathExecutor.h"
class OrientationCoordinates;
class Path;

class PathPlaner{
private:
	PositionCalculator &positionCalculator;
	PathExecutor &pathExecutor;
	const OrientationCoordinates *lastEndPosition;
protected:
	double getMinRadius() const;
public:
	PathPlaner(PositionCalculator &positionCalculator, PathExecutor &pathExecutor);
	/*!
	Move to the position
	@param endPosition The destination.
	*/
	void moveTo(const OrientationCoordinates& endPosition);
	void moveTo(const OrientationCoordinates* endPosition);
	/*!
	Calculate Path
	@param startPosition The start point
	@param endPosition The destination point
	*/
	virtual Path* calculatePath(const OrientationCoordinates& startPosition, const OrientationCoordinates& endPosition) = 0;
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