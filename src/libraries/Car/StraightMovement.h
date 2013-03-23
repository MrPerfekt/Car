/*!
Copyright 2013 Andreas Gruber
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
	void setDistance(double distance);
	double getAngle() const;
	double getRadius() const;
	
	StraightMovement();
	
	/*Deprecated*/void invokeOnSteeringManager(SteeringManager &steeringManager);
};
#endif