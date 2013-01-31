/*!
Copyright 2012 Andreas Gruber
*/

#ifndef ORIENTATION_COORDINATES
#define ORIENTATION_COORDINATES

#include "Coordinates.h"

class Movement;

class OrientationCoordinates : public Coordinates{
private:
	double angle;
public:
	double getAngle() const;
	void setAngle(double angle);

	OrientationCoordinates();
	OrientationCoordinates(double x,double y,double angle);
	virtual void operator+= (const OrientationCoordinates &coordinates);
	virtual void operator-= (const OrientationCoordinates &coordinates);
	virtual void operator*= (const Movement &movement);
	virtual bool operator!= (const OrientationCoordinates &movement);
	virtual bool operator== (const OrientationCoordinates &movement);
	void set(double x,double y,double angle);
	void set(const OrientationCoordinates &orientationCoordinates);
};
#endif
