/*!
Copyright 2012 Andreas Gruber
*/

#include "OrientationCoordinates.h"
#include "Movement.h"

double OrientationCoordinates::getAngle() const{
	return angle;
}
void OrientationCoordinates::setAngle(double angle){
	this->angle = angle;
}
OrientationCoordinates::OrientationCoordinates()
:Coordinates(),angle(0){
}
OrientationCoordinates::OrientationCoordinates(double x,double y,double angle)
:Coordinates(x,y),angle(angle){
}
void OrientationCoordinates::operator+= (const OrientationCoordinates &coordinates){
	Coordinates::operator+=(coordinates);
	setAngle(getAngle() + coordinates.getAngle());
}
void OrientationCoordinates::operator-= (const OrientationCoordinates &coordinates){
	Coordinates::operator-=(coordinates);
	setAngle(getAngle() - coordinates.getAngle());
}
void OrientationCoordinates::operator*= (const Movement &movement){
	Coordinates::operator*=(movement);
	setAngle(getAngle() + movement.getAngle());
}