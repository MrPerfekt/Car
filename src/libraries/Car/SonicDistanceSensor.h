/*!
Copyright 2012 Andreas Gruber
*/

#ifndef SONIC_DISTANCE_SENSOR
#define SONIC_DISTANCE_SENSOR

#include "DefineLib.h"
#include "DistanceSensor.h"

class SonicDistanceSensor : public DistanceSensor{
private:
	const uint8_t pinTrig,pinEcho;
public:
	SonicDistanceSensor(uint8_t sensorNr);
	~SonicDistanceSensor();

	double calculateDistance() const;
};
#endif