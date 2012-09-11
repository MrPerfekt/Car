/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT_SENSOR
#define MOVEMENT_SENSOR

#include "Sensor.h"
#include "Coordinates.h"

class MovementSensor : public Sensor{
	Coordinates getMovement();
};

#endif