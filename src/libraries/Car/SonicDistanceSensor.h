/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISTANCESENSOR
#define DISTANCESENSOR

#include "DefineLib.h"
#include "EnvironmentSensor.h"

class DistanceSensor : public EnvironmentSensor{
private:
	uint8_t sensorNr;
public:
	DistanceSensor(uint8_t sensorNr);
	~DistanceSensor();

	void update();
};
#endif