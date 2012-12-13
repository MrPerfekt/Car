/*!
Copyright 2012 Andreas Gruber
*/

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


StraightMovement::StraightMovement(){
}
StraightMovement::StraightMovement(double distance)
	:distance(distance){
}
void StraightMovement::setDistance(double distance){
	this->distance = distance;
}
double StraightMovement::getDistance() const{
	return distance;
}
double StraightMovement::getAngle() const{
	return 0;
}



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
TurnMovement::TurnMovement(){
}