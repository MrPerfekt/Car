/*!
Copyright 2012 Andreas Gruber
*/

#ifndef STEERING_REGULATOR
#define STEERING_REGULATOR

class SteeringRegulator {
private:
public:
	virtual void turnOnOff(bool on) = 0;
	virtual void setRadius(double radius) = 0;
	virtual const double getMinRadius() const = 0;
};

#endif