/*
* Copyright 2012 Andreas Gruber
*/

#ifndef WHEEL_ROTATION_SENSORS
#define WHEEL_ROTATION_SENSORS

#include "DefineLib.h"
#include "Sensor.h"
#include "MovementSensor.h"

class WheelSensor;
class Wheel;

static WheelSensor* wheelSensorInstance;
void rotateWheelR();
void rotateWheelL();

class Wheel{
public:
	static const uint wheelSteps = 12;
	static const ulong wheelDistance = 155000;//nm
	static const ulong circumference = 94000;// 6762 / 72 mm = 94 * 1000 nm
	static const ulong stepDistance = circumference / wheelSteps;
	//static const int debounceMinRotTime = -1;//10;//10ms
	
	//Pin definition
	int wheelPin;
	int wheelInt;

	//Variables
	volatile ulong rotationCount;
	volatile ulong lastRotationTime;
	volatile ulong lastRotationPeriod;
	volatile ulong secToLastRotationPeriod;

	Wheel(int wPin);
};

class WheelSensor : public MovementSensor{
private:
	Wheel* wheels[2];
public:
	
	static const byte WR = 0;
	static const byte WL = 1;

	WheelSensor(int wPinWR,int wPinWL);
	void rotateWheel(byte wheel);
	double calculateAngleDeg();
	long calculateAngleMilli();
	ulong calculateDistance();
	uint calculateCurrentSpeed();
};

#endif