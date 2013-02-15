/*!
Copyright 2012 Andreas Gruber
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
	bool direction;
protected:
	void execute();
public:
	CarPowerRegulator();
};

#endif