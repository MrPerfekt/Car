/*!
Copyright 2012 Andreas Gruber
*/

#include "Config.h"
#include "DistanceSensor.h"
#include "EnvironmentKnowledgeBase.h"
#include "OrientationCoordinates.h"
#include "PositionCalculator.h"


DistanceSensor::DistanceSensor(uint8_t sensorNr,PositionCalculator& positionCalculator, EnvironmentKnowledgeBase &environmentKnowledgeBase)
	:EnvironmentSensor(sensorNr,positionCalculator,environmentKnowledgeBase){
}
DistanceSensor::~DistanceSensor(){
}
//DistanceSensor::
void DistanceSensor::update(){
	double distance = measureDistance();
	//Serial.println(distance);
	if(distance > Config::getSonicSensorValidationRange()) return;
	const OrientationCoordinates& carPos = getPositionCalculator().getCurrentPosition();
	const OrientationCoordinates& sensorPos = Config::getSonicSensorConfigs()[getSensorNr()].getPosition();

	Coordinates pos = Coordinates();
	pos.setToUnitVectorByAngle(PI / 2 + sensorPos.getAngle());
	pos *= distance;
	pos += sensorPos;
	pos.rotate(carPos.getAngle());
	pos += carPos;
	
	getEnvironmentKnowledgeBase().detectPoint(pos);
}