/*!
Copyright 2013 Andreas Gruber
*/

#include "GeneralMovement.h"
#include "Movement.h"


double GeneralMovement::getDistance() const{
	return distance;
}
void GeneralMovement::setDistance(double distance){
	this->distance = distance;
}
double GeneralMovement::getAngle() const{
	return angle;
}
void GeneralMovement::setAngle(double angle){
	this->angle = angle;
}
GeneralMovement::GeneralMovement()
	:distance(0)
	,angle(0){
}
GeneralMovement::GeneralMovement(double distance,double angle)
	:distance(distance)
	,angle(angle){
}
void GeneralMovement::operator+=(const Movement &movement){
	distance += movement.getDistance();
	angle += movement.getAngle();
}
void GeneralMovement::operator+=(const GeneralMovement &movement){
	distance += movement.getDistance();
	angle += movement.getAngle();
}
