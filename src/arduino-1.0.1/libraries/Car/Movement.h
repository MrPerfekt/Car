/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"

class Movement{
private:
public:
	int32_t distance;
	int16_t angle;
	Movement();
	Movement(int32_t distance,int16_t angle);
};

#endif