/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"

class Movement{//! Interface
public:
	virtual double getDistance() const = 0;
	virtual double getAngle() const = 0;
};

class GeneralMovement : public Movement{
private:
	double distance;
	double angle;
public:
	virtual double getDistance() const;
	void setDistance(double distance);
	virtual double getAngle() const;
	void setAngle(double angle);

	void operator+=(const Movement &move);
	
	GeneralMovement();
	GeneralMovement(double distance,double angle);
};

class StraightMovement : public Movement{
private:
	double distance;
public:
	virtual double getDistance() const;
	virtual double getAngle() const;
	void setDistance(double distance);
	
	StraightMovement();
	StraightMovement(double distance);
};


class TurnMovement : public Movement{
private:
	double angle;
	double distance;
	double radius;
	
public:
	static double convertAngleDistanceToRadius(double angle,double distance);
	static double convertAngleRadiusToDistance(double angle,double radius);
	static double convertDistanceRadiusToAngle(double distance,double radius);
	virtual double getAngle() const;
	virtual double getDistance() const;
	virtual double getRadius() const;
	void setAngleDistance(double angle, double distance);
	void setAngleRadius(double angle, double radius);
	void setDistanceRadius(double distance, double radius);
	
	TurnMovement();
};

#endif