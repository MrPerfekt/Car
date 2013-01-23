/*!
Copyright 2012 Andreas Gruber
*/

#include "EnvironmentSensor.h"

uint8_t EnvironmentSensor::getSensorNr(){
	return sensorNr;
}

EnvironmentSensor::EnvironmentSensor(uint8_t sensorNr)
	:sensorNr(sensorNr){
	//Config
}
EnvironmentSensor::~EnvironmentSensor(){
}