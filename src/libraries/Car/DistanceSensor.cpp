/*!
Copyright 2012 Andreas Gruber
*/

#include "DistanceSensor.h"


DistanceSensor::DistanceSensor(uint8_t sensorNr)
:sensorNr(sensorNr){
}
DistanceSensor::~DistanceSensor(){
}

void update();