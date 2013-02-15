/*!
Copyright 2012 Andreas Gruber
*/

#ifndef POWER_REGULATOR
#define POWER_REGULATOR

#include "DefineLib.h"

class PowerRegulator {
private:
	uint8_t speed;
	bool on;
protected:
	uint8_t getSpeed();
	bool isOn();
	virtual void execute() = 0;
public:
	PowerRegulator();
	~PowerRegulator();
	/*!
	Sets the speed of the power device.
	\param speed The speed of the PowerRegulator
	*/
	void setSpeed(uint8_t speed);
	/*!
	Turns the power device on or off
	\param on True turns the PowerRegulator on and False off.
	*/
	void turnOnOff(bool on);
};

#endif