/*!
Copyright 2012 Andreas Gruber
*/

#ifndef COORDINATES
#define COORDINATES

#include "Vector.h"

class Movement;

class Coordinates : public Vector{
private:
public:
	Coordinates();
	Coordinates(double x,double y);
};
#endif
