/*!
Copyright 2012 Andreas Gruber
*/

#ifndef ENVIRONMENTSENSOR
#define ENVIRONMENTSENSOR

#include "Sensor.h"
#include "DefineLib.h"
class EnvironmentKnowledgeBase;
class PositionCalculator;

class EnvironmentSensor:public Sensor{
	uint8_t sensorNr;
	EnvironmentKnowledgeBase &environmentKnowledgeBase;
	PositionCalculator &positionCalculator;
public:
	uint8_t getSensorNr();
	EnvironmentKnowledgeBase &getEnvironmentKnowledgeBase();
	PositionCalculator &getPositionCalculator();
	EnvironmentSensor(uint8_t sensorNr,PositionCalculator& positionCalculator,EnvironmentKnowledgeBase &environmentKnowledgeBase);
	~EnvironmentSensor();
};
#endif