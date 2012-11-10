/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DEFINE_LIB
#define DEFINE_LIB

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

#include "Config.h"

/*!
Contains the angle of a full circle.
E.c. deg=360, rad=2*pi, grd=400, ...
This is no configuration. So this is not saved in Config.h
*/
static const double circle = 360;

uint16_t freeSRam ();

#endif