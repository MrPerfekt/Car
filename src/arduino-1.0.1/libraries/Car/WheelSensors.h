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
	static const uint16_t wheelSteps = 12;
	static const uint32_t wheelDistance = 155000;//nm
	static const uint32_t circumference = 94000;// 6762 / 72 mm = 94 * 1000 nm
	static const uint32_t stepDistance = circumference / wheelSteps;
	//static const int debounceMinRotTime = -1;//10;//10ms
	
	//Pin definition
	int wheelPin;
	int wheelInt;

	//Variables
	volatile uint32_t rotationCount;
	volatile uint32_t lastRotationTime;
	volatile uint32_t lastRotationPeriod;
	volatile uint32_t secToLastRotationPeriod;

	Wheel(int wPin);
};

class WheelSensor : public MovementSensor{
private:
	Wheel* wheels[2];
public:
	
	static const byte WR = 0;
	static const byte WL = 1;

	WheelSensor(uint8_t wPinWR,uint8_t wPinWL);
	void rotateWheel(byte wheel);
	double calculateAngleDeg();
	int32_t calculateAngleMilli();
	uint32_t calculateDistance();
	uint16_t calculateCurrentSpeed();
	void resetData();
	Movement getMovement();
};

#endif