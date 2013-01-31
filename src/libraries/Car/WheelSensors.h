/*!
Copyright 2012 Andreas Gruber
*/

#ifndef WHEEL_ROTATION_SENSORS
#define WHEEL_ROTATION_SENSORS

#include "DefineLib.h"
//#include "Sensor.h"
#include "MovementSensor.h"
#include "TurnMovement.h"
//class TurnMovement;

class WheelSensor;
class Wheel;

static WheelSensor* wheelSensorInstance;
void rotateWheelL0();
void rotateWheelL1();
void rotateWheelR0();
void rotateWheelR1();

struct Wheel{
	//Variables
	volatile int32_t rotationCount;
	volatile uint32_t lastRotationTime;
	volatile uint32_t lastRotationPeriod;
	volatile uint32_t secToLastRotationPeriod;
	
	Wheel();
};

class WheelSensor : public MovementSensor{
private:
	TurnMovement mov;
	Wheel* wheels[2];
public:
	static const byte WR = 0;
	static const byte WL = 1;

	WheelSensor();
	void rotateWheel(uint8_t wheel,uint8_t sensorNr);
	double calculateAngle();
	double calculateDistance();
	double calculateCurrentSpeed();
	void resetData();
	Movement& getMovement();
	void update();
};

#endif