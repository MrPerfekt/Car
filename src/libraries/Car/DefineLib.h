/*
* Copyright 2012 Andreas Gruber
*/

#ifndef DEFINE_LIB
#define DEFINE_LIB

#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/*!
* Contains the angle of a full circle.
* E.c. deg=360, rad=2*pi, grd=400, ...
*/
static const double circle = 360;//= 2*M_PI;

uint16_t freeSRam ();

#endif