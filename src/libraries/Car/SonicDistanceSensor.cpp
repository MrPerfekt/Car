/*!
Copyright 2012 Andreas Gruber
*/

#include "SonicDistanceSensor.h"
#include "Config.h"

SonicDistanceSensor::SonicDistanceSensor(uint8_t sensorNr,PositionCalculator& positionCalculator,EnvironmentKnowledgeBase &environmentKnowledgeBase)
	:DistanceSensor(sensorNr,positionCalculator,environmentKnowledgeBase)
	,pinTrig(Config::getSonicSensorConfigs()[getSensorNr()].getPinTrig())
	,pinEcho(Config::getSonicSensorConfigs()[getSensorNr()].getPinEcho()){
		pinMode(pinEcho, INPUT);
		pinMode(pinTrig, OUTPUT);
}
SonicDistanceSensor::~SonicDistanceSensor(){
}

double SonicDistanceSensor::measureDistance() const{
	//! Start Ranging
	digitalWrite(pinTrig, LOW);
	delayMicroseconds(2);
	digitalWrite(pinTrig, HIGH);
	delayMicroseconds(10);
	digitalWrite(pinTrig, LOW);
	//! Compute distance
	double distance = pulseIn(pinEcho, HIGH) / 58.0 * 10; //! (29.154519 * 2)
	//Serial.println(distance);
	return distance;
}