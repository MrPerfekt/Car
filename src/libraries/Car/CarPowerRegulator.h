/*!
Copyright 2013 Andreas Gruber
*/

#ifndef CAR_POWER_REGULATOR
#define CAR_POWER_REGULATOR

#include "PowerRegulator.h"
#include "DefineLib.h"
class Motor;

class CarPowerRegulator : public PowerRegulator{
private:
	Motor* m;
	uint8_t speed;
	bool on;
	bool forward;
	void execute();
public:
	void setSpeed(uint8_t speed);
	uint8_t getSpeed();
	void setDirection(bool forward);
	bool isTurnForward();
	void turnOnOff(bool on);
	bool isOn();

	CarPowerRegulator();
};

#endif