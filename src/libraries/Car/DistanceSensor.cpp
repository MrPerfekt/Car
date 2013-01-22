/*!
Copyright 2012 Andreas Gruber
*/

#include "DistanceSensor.h"


DistanceSensor::DistanceSensor(uint8_t sensorNr)
:sensorNr(sensorNr){
	//Config
}
DistanceSensor::~DistanceSensor(){
}

void update();