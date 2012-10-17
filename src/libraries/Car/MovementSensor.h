/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT_SENSOR
#define MOVEMENT_SENSOR

#include "Sensor.h"
#include "Movement.h"

class MovementSensor : public Sensor {
public:
	virtual Movement getMovement() = 0;
};

#endif