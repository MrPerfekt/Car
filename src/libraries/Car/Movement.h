/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"

class Movement{
private:
public:
	double distance;
	double angle;
	Movement();
	Movement(double distance,double angle);
	Movement& operator+=(const Movement &move);

};

#endif