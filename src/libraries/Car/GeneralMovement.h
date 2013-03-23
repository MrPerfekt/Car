/*!
Copyright 2013 Andreas Gruber
*/

#ifndef GENERAL_MOVEMENT
#define GENERAL_MOVEMENT

#include "DefineLib.h"
class Movement;

class GeneralMovement{
private:
	double distance;
	double angle;
public:
	double getDistance() const;
	void setDistance(double distance);
	double getAngle() const;
	void setAngle(double angle);
	
	void operator+=(const Movement &move);
	void operator+=(const GeneralMovement &move);
	
	GeneralMovement();
	GeneralMovement(double distance,double angle);
};

#endif