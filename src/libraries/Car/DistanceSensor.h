/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISTANCE_SENSOR
#define DISTANCE_SENSOR

#include "DefineLib.h"
#include "EnvironmentSensor.h"

class DistanceSensor : public EnvironmentSensor{
private:
public:
	DistanceSensor(uint8_t sensorNr);
	~DistanceSensor();
	virtual double callculateDistance() const = 0;
	void update();
};
#endif