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

uint16_t freeSRam ();

#endif