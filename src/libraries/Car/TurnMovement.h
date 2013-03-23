/*!
Copyright 2013 Andreas Gruber
*/

#ifndef TURN_MOVEMENT
#define TURN_MOVEMENT

#include "DefineLib.h"
#include "Movement.h"

class TurnMovement : public Movement{
private:
	double angle;
	double distance;
	double radius;
	
public:
	static double convertAngleDistanceToRadius(double angle,double distance);
	static double convertAngleRadiusToDistance(double angle,double radius);
	static double convertDistanceRadiusToAngle(double distance,double radius);
	double getAngle() const;
	double getDistance() const;
	double getRadius() const;
	void setAngleDistance(double angle, double distance);
	void setAngleRadius(double angle, double radius);
	void setDistanceRadius(double distance, double radius);
	
	TurnMovement();
};
#endif