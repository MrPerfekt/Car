/*!
Copyright 2012 Andreas Gruber
*/

#ifndef ENVIRONMENTSENSOR
#define ENVIRONMENTSENSOR

#include "DefineLib.h"
#include "Sensor.h"

class EnvironmentSensor:public Sensor{
	uint8_t sensorNr;
public:
	uint8_t getSensorNr();
	EnvironmentSensor(uint8_t sensorNr);
	~EnvironmentSensor();
};
#endif