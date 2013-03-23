/*!
Copyright 2013 Andreas Gruber
*/

#ifndef SONIC_DISTANCE_SENSOR
#define SONIC_DISTANCE_SENSOR

#include "DefineLib.h"
#include "DistanceSensor.h"

class SonicDistanceSensor : public DistanceSensor{
private:
	const uint8_t pinTrig,pinEcho;
public:
	SonicDistanceSensor(uint8_t sensorNr,PositionCalculator& positionCalculator,EnvironmentKnowledgeBase &environmentKnowledgeBase);
	~SonicDistanceSensor();

	double measureDistance() const;
};
#endif