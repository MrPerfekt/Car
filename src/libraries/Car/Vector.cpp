/*!
Copyright 2012 Andreas Gruber
*/

#include "Coordinates.h"
#include "Movement.h"
	
double Coordinates::getX() const{
	return x;
}	
void Coordinates::setX(double x){
	this->x = x;
}
double Coordinates::getY() const{
	return y;
}
void Coordinates::setY(double y){
	this->y = y;
}

Coordinates::Coordinates()
:x(0),y(0){
}
Coordinates::Coordinates(double x,double y)
:x(x),y(y){
}
void Coordinates::operator-= (const Coordinates &coordinates){
	this->x -= coordinates.x;
	this->y -= coordinates.y;
}
void Coordinates::operator+= (const Coordinates &coordinates){
	this->x += coordinates.x;
	this->y += coordinates.y;
}
void Coordinates::operator*= (const Movement &movement){
	setX(getX() + movement.getDistance() * sin(movement.getAngle()));//ToDo
	setY(getY() + movement.getDistance() * cos(movement.getAngle()));//ToDo
}



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