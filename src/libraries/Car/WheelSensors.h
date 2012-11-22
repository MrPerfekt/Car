/*!
Copyright 2012 Andreas Gruber
*/

#ifndef WHEEL_ROTATION_SENSORS
#define WHEEL_ROTATION_SENSORS

#include "DefineLib.h"
#include "Sensor.h"
#include "MovementSensor.h"

class WheelSensor;
class Wheel;

static WheelSensor* wheelSensorInstance;
void rotateWheelL0();
void rotateWheelL1();
void rotateWheelR0();
void rotateWheelR1();

class Wheel{
public:
	//Variables
	volatile uint32_t rotationCount;
	volatile uint32_t lastRotationTime;
	volatile uint32_t lastRotationPeriod;
	volatile uint32_t secToLastRotationPeriod;
	
	Wheel();
};

class WheelSensor : public MovementSensor{
private:
	Wheel* wheels[2];
public:
	static const byte WR = 0;
	static const byte WL = 1;

	WheelSensor();
	void rotateWheel(byte wheel);
	double calculateAngle();
	double calculateDistance();
	double calculateCurrentSpeed();
	void resetData();
	Movement getMovement();
	void update();
};

#endif