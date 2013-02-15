/*!
Copyright 2013 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"
#include "Observer.h"
/**/#include "SteeringManager.h"
class PositionCalculator;
class SteeringRegulator;

class Movement{//! Interface
private:
protected:
public:
	virtual double getDistance() const = 0;
	virtual double getAngle() const = 0;
};

#endif