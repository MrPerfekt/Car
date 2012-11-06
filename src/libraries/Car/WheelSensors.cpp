/*
* Copyright 2012 Andreas Gruber
*/

#include "WheelSensors.h"

//========== wheels [int] ==========

Wheel::Wheel(int wPin)
:wheelPin(wPin) {
	if(wPin == 2)
		wheelInt = 0;
	else if(wPin == 3)
		wheelInt = 1;
	//else
		//this shouldn't happen
	rotationCount = 0;
	lastRotationTime = 0;
	lastRotationPeriod = 0;
	secToLastRotationPeriod = 0;
}

WheelSensor::WheelSensor(uint8_t wPinWR,uint8_t wPinWL){
	wheels[WR] = new Wheel(wPinWR);
	wheels[WL] = new Wheel(wPinWL);
	wheelSensorInstance = this;

	pinMode(wheels[WR]->wheelPin, INPUT);
	pinMode(wheels[WL]->wheelPin, INPUT);
	attachInterrupt(wheels[WR]->wheelInt, rotateWheelR, CHANGE);
	attachInterrupt(wheels[WL]->wheelInt, rotateWheelL, CHANGE);
}

void rotateWheelR(){
	wheelSensorInstance->rotateWheel(WheelSensor::WR);
}

void rotateWheelL(){
	wheelSensorInstance->rotateWheel(WheelSensor::WL);
}

void WheelSensor::rotateWheel(byte wheel){
	unsigned long cTime = millis();
	unsigned long cRotTime = cTime - wheels[wheel]->lastRotationTime;

	// Serial.println(wheel);
	// if(cRotTime > Wheel::debounceMinRotTime) return;//debouncing

	wheels[wheel]->rotationCount++;
	wheels[wheel]->secToLastRotationPeriod = wheels[wheel]->lastRotationPeriod;
	wheels[wheel]->lastRotationPeriod = cRotTime;
	wheels[wheel]->lastRotationTime = cTime;
}

double WheelSensor::calculateAngle(){
	return ((double)wheels[WR]->rotationCount - (double)wheels[WL]->rotationCount) * Wheel::stepDistance() * circle / (2 * (double)Wheel::wheelDistance * M_PI);
}

double WheelSensor::calculateDistance(){
	return (wheels[WR]->rotationCount + wheels[WL]->rotationCount) * Wheel::stepDistance() / 2.0;
}

double WheelSensor::calculateCurrentSpeed(){
	//nm/ms = mm/s;
	uint32_t cTime = millis();
	uint32_t cRotTimeL = cTime - wheels[WL]->lastRotationTime;
	uint32_t cRotTimeR = cTime - wheels[WR]->lastRotationTime;

	if(cRotTimeL > 1000 && cRotTimeR > 1000) return 0;

	uint32_t minLRPL = cRotTimeL > wheels[WL]->lastRotationPeriod * 2 ? cRotTimeL : wheels[WL]->lastRotationPeriod;
	uint32_t minLRPR = cRotTimeR > wheels[WR]->lastRotationPeriod * 2 ? cRotTimeR : wheels[WR]->lastRotationPeriod;
	uint32_t minSLRPL = cRotTimeL > wheels[WL]->secToLastRotationPeriod * 2 ? cRotTimeL : wheels[WL]->secToLastRotationPeriod;
	uint32_t minSLRPR = cRotTimeR > wheels[WR]->secToLastRotationPeriod * 2 ? cRotTimeR : wheels[WR]->secToLastRotationPeriod;

	return (Wheel::stepDistance() * 2 ) / (double)(minLRPL + minLRPR + minSLRPL + minSLRPR);
}
void WheelSensor::resetData(){
	wheels[WL]->rotationCount = 0;
	wheels[WR]->rotationCount = 0;
}
Movement WheelSensor::getMovement(){
	Movement mov(calculateDistance(),calculateAngle());
	resetData();
	return mov;
}