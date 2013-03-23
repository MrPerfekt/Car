/*!
Copyright 2013 Andreas Gruber
*/

#include "Coordinates.h"
#include "Movement.h"
	
Coordinates::Coordinates()
:Vector(){
}
Coordinates::Coordinates(double x,double y)
:Vector(x,y){
}
void Coordinates::set(double x, double y){
	Vector::set(x,y);
}
void Coordinates::set(const Coordinates &coordinates){
	Vector::set(coordinates);
}