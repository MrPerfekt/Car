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

WheelSensor::WheelSensor(int wPinWR,int wPinWL){
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

double WheelSensor::calculateAngleDeg(){
	return (double)calculateAngleMilli()/1000.0*360.0;
}
long WheelSensor::calculateAngleMilli(){
	//1000 = 360°
	return ((long)wheels[WR]->rotationCount - (long)wheels[WL]->rotationCount) * (long)Wheel::stepDistance * (long)1000 / (2 * Wheel::wheelDistance * pi);
}

ulong WheelSensor::calculateDistance(){
	//nm
	return (wheels[WR]->rotationCount + wheels[WL]->rotationCount) * Wheel::stepDistance / 2;
}

uint WheelSensor::calculateCurrentSpeed(){
	//nm/ms = mm/s;
	ulong cTime = millis();
	ulong cRotTimeL = cTime - wheels[WL]->lastRotationTime;
	ulong cRotTimeR = cTime - wheels[WR]->lastRotationTime;

	if(cRotTimeL > 1000 && cRotTimeR > 1000) return 0;

	ulong minLRPL = cRotTimeL > wheels[WL]->lastRotationPeriod * 2 ? cRotTimeL : wheels[WL]->lastRotationPeriod;
	ulong minLRPR = cRotTimeR > wheels[WR]->lastRotationPeriod * 2 ? cRotTimeR : wheels[WR]->lastRotationPeriod;
	ulong minSLRPL = cRotTimeL > wheels[WL]->secToLastRotationPeriod * 2 ? cRotTimeL : wheels[WL]->secToLastRotationPeriod;
	ulong minSLRPR = cRotTimeR > wheels[WR]->secToLastRotationPeriod * 2 ? cRotTimeR : wheels[WR]->secToLastRotationPeriod;

	return (uint)((Wheel::stepDistance * 2 ) / (minLRPL + minLRPR + minSLRPL + minSLRPR));
}
