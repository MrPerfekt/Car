/*!
Copyright 2012 Andreas Gruber
*/

#include "WheelSensors.h"

//========== wheels [int] ==========

Wheel::Wheel() {
	rotationCount = 0;
	lastRotationTime = 0;
	lastRotationPeriod = 0;
	secToLastRotationPeriod = 0;
}

WheelSensor::WheelSensor()
:mov(TurnMovement()){
	wheels[WR] = new Wheel();
	wheels[WL] = new Wheel();
	wheelSensorInstance = this;
	
	pinMode(Config::getPinWheelSensorL0(), INPUT);
	pinMode(Config::getPinWheelSensorL1(), INPUT);
	pinMode(Config::getPinWheelSensorR0(), INPUT);
	pinMode(Config::getPinWheelSensorR1(), INPUT);
	attachInterrupt(Config::getIntWheelSensorL0(), rotateWheelL0, CHANGE);
	attachInterrupt(Config::getIntWheelSensorL1(), rotateWheelL1, CHANGE);
	attachInterrupt(Config::getIntWheelSensorR0(), rotateWheelR0, CHANGE);
	attachInterrupt(Config::getIntWheelSensorR1(), rotateWheelR1, CHANGE);
}

void rotateWheelL0(){
	wheelSensorInstance->rotateWheel(WheelSensor::WL);
}
void rotateWheelL1(){
	wheelSensorInstance->rotateWheel(WheelSensor::WL);
}
void rotateWheelR0(){
	wheelSensorInstance->rotateWheel(WheelSensor::WR);
}
void rotateWheelR1(){
	wheelSensorInstance->rotateWheel(WheelSensor::WR);
}

void WheelSensor::rotateWheel(byte wheel){
	unsigned long cTime = millis();
	unsigned long cRotTime = cTime - wheels[wheel]->lastRotationTime;

	wheels[wheel]->rotationCount++;
	wheels[wheel]->secToLastRotationPeriod = wheels[wheel]->lastRotationPeriod;
	wheels[wheel]->lastRotationPeriod = cRotTime;
	wheels[wheel]->lastRotationTime = cTime;
}

double WheelSensor::calculateAngle(){
	return ((double)wheels[WR]->rotationCount - (double)wheels[WL]->rotationCount) * Config::getWheelStepDistance() * circle / (2.0 * Config::getWheelDistance() * M_PI);
}

double WheelSensor::calculateDistance(){
	return (wheels[WR]->rotationCount + wheels[WL]->rotationCount) * Config::getWheelStepDistance() / 2.0;
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

	return (Config::getWheelStepDistance() * 2.0 ) / (double)(minLRPL + minLRPR + minSLRPL + minSLRPR);
}
void WheelSensor::resetData(){
	wheels[WL]->rotationCount = 0;
	wheels[WR]->rotationCount = 0;
}
Movement& WheelSensor::getMovement(){
	mov.setAngleDistance(calculateAngle(),calculateDistance());
	resetData();
	return mov;
}
void WheelSensor::update(){
}