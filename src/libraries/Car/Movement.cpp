/*
* Copyright 2012 Andreas Gruber
*/

#include "Movement.h"

Movement::Movement()
:distance(0),angle(0){
}
Movement::Movement(double distance,double angle)
:distance(distance),angle(angle){
}
Movement& Movement::operator+=(const Movement &move){
	this->angle += move.angle;
	this->distance += move.distance;
	return *this;
}