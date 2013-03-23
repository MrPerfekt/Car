/*!
Copyright 2013 Andreas Gruber
*/

#ifndef DISTANCE_SENSOR
#define DISTANCE_SENSOR

#include "DefineLib.h"
#include "EnvironmentSensor.h"

class DistanceSensor : public EnvironmentSensor{
private:
public:
	DistanceSensor(uint8_t sensorNr,PositionCalculator& positionCalculator,EnvironmentKnowledgeBase &environmentKnowledgeBase);
	~DistanceSensor();
	virtual double measureDistance() const = 0;
	void update();
};
#endif