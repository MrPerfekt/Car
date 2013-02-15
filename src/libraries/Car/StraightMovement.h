/*!
Copyright 2012 Andreas Gruber
*/

#ifndef STRAIGHT_MOVEMENT
#define STRAIGHT_MOVEMENT

#include "DefineLib.h"
#include "Movement.h"
#include "ExecutableMovement.h"

class StraightMovement : public Movement{
private:
	double distance;
public:
	double getDistance() const;
	double getAngle() const;
	void setDistance(double distance);
	
	StraightMovement();
	
	void execute();
	void update();
	/**/void invokeOnSteeringManager(SteeringManager &steeringManager);
};
#endif