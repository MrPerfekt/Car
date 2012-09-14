/*
* Copyright 2012 Andreas Gruber
*/

#include "Coordinates.h"
	
Coordinates::Coordinates()
:x(0),y(0){
}
Coordinates::Coordinates(long x,long y)
:x(x),y(y){
}
Coordinates Coordinates::operator-= (const Coordinates &coordinates){
	this->x -= coordinates.x;
	this->y -= coordinates.y;
}
Coordinates Coordinates::operator+= (const Coordinates &coordinates){
	this->x += coordinates.x;
	this->y += coordinates.y;
}