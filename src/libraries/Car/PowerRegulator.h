/*!
Copyright 2013 Andreas Gruber
*/

#ifndef POWER_REGULATOR
#define POWER_REGULATOR

#include "DefineLib.h"

class PowerRegulator {
public:
	PowerRegulator();
	~PowerRegulator();
	/*!
	Sets the speed of the power device.
	\param speed The speed of the PowerRegulator
	*/
	virtual void setSpeed(uint8_t speed) = 0;
	/*!
	Sets the direction of the power device.
	\param forward True if the power device have to drive forward
	*/
	virtual void setDirection(bool forward) = 0;
	/*!
	Turns the power device on or off
	\param on True turns the PowerRegulator on and False off.
	*/
	virtual void turnOnOff(bool on) = 0;
};

#endif