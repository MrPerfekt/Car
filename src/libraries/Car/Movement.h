/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"
//class SteeringManager;
#include "SteeringManager.h"

class Movement{//! Interface
public:
	virtual double getDistance() const = 0;
	virtual double getAngle() const = 0;
	//virtual void invokeOnSteeringManager(SteeringManager &steeringManager) const = 0;
};

class GeneralMovement : public Movement{
private:
	double distance;
	double angle;
public:
	double getDistance() const;
	void setDistance(double distance);
	double getAngle() const;
	void setAngle(double angle);

	void operator+=(const Movement &move);
	
	GeneralMovement();
	GeneralMovement(double distance,double angle);

	/*!
	Not Supported
	*/
	void invokeOnSteeringManager(SteeringManager &steeringManager);
};

#endif