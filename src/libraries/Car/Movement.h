/*!
Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

#include "DefineLib.h"

class Movement{
public:
	virtual double getDistance() const;// = 0;
	virtual double getAngle() const;// = 0;
	
	Movement();
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
};

class StraightMovement : public Movement{
private:
	double distance;
public:
	double getDistance() const;
	double getAngle() const;
	void setDistance(double distance);
	
	StraightMovement();
	StraightMovement(double distance);
};


class TurnMovement : public Movement{
private:
	double angle;
	double distance;
	double radius;
	
	TurnMovement(double angle,double distance,double radius);
public:
	static double convertAngleDistanceToRadius(double angle,double distance);
	static double convertAngleRadiusToDistance(double angle,double radius);
	static double convertDistanceRadiusToAngle(double distance,double radius);
	double getAngle() const;
	double getDistance() const;
	double getRadius() const;
	void setAngleDistance(double angle, double distance);
	void setAngleRadius(double angle, double radius);
	void setDistanceRadius(double distance, double radius);
	
	TurnMovement();
	TurnMovement(double angle, double distance, double radius, uint8_t ignoreValueNr);
};

#endif