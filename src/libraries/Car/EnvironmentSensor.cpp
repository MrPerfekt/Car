/*!
Copyright 2012 Andreas Gruber
*/

#include "EnvironmentSensor.h"
#include "EnvironmentKnowledgeBase.h"
#include "PositionCalculator.h"

uint8_t EnvironmentSensor::getSensorNr(){
	return sensorNr;
}
EnvironmentKnowledgeBase &EnvironmentSensor::getEnvironmentKnowledgeBase(){
	return environmentKnowledgeBase;
}
PositionCalculator &EnvironmentSensor::getPositionCalculator(){
	return positionCalculator;
}

EnvironmentSensor::EnvironmentSensor(uint8_t sensorNr,PositionCalculator& positionCalculator,EnvironmentKnowledgeBase &environmentKnowledgeBase)
	:sensorNr(sensorNr)
	,environmentKnowledgeBase(environmentKnowledgeBase)
	,positionCalculator(positionCalculator){
}
EnvironmentSensor::~EnvironmentSensor(){
}