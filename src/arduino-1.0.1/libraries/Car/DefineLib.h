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

#define ullong unsigned long long
#define ulong unsigned long
#define uint unsigned int
#define llong long long

static const double pi = 3.14159265; 

#endif