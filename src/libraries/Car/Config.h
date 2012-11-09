#ifndef _CONFIGURATION_h
#define _CONFIGURATION_h
#include "DefineLib.h"

class Config{
private:
	/*!
	Contains the angle of a full circle.
	E.c. deg=360, rad=2*pi, grd=400, ...
	*/
	static const double circle = 360;//= 2*M_PI;
public:
	static double getCircle();
};

#endif

