/*!
Copyright 2012 Andreas Gruber
*/

#include "TurnMovement.h"

double TurnMovement::convertAngleDistanceToRadius(double angle,double distance){
	return distance*circle/(2.0*M_PI*angle);
}
double TurnMovement::convertAngleRadiusToDistance(double angle,double radius){
	return 2.0*radius*M_PI*angle/circle;
}
double TurnMovement::convertDistanceRadiusToAngle(double distance,double radius){
	return distance*circle/(2.0*radius*M_PI);
}
double TurnMovement::getDistance() const{
	return distance;
}
double TurnMovement::getAngle() const{
	return angle;
}
double TurnMovement::getRadius() const{
	return radius;
}
void TurnMovement::setAngleDistance(double angle, double distance){
	this->angle = angle;
	this->distance = distance;
	this->radius = convertAngleDistanceToRadius(angle,distance);
}
void TurnMovement::setAngleRadius(double angle, double radius){
	this->angle = angle;
	this->distance = convertAngleRadiusToDistance(angle,radius);
	this->radius = radius;
}
void TurnMovement::setDistanceRadius(double distance, double radius){
	this->angle = convertDistanceRadiusToAngle(distance,radius);
	this->distance = distance;
	this->radius = radius;
}
TurnMovement::TurnMovement()
	:Movement(){
}
void TurnMovement::invokeOnSteeringManager(SteeringManager &steeringManager){
	steeringManager.driveMovement(*this);
}