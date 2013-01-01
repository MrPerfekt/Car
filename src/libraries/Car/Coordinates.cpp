/*!
Copyright 2012 Andreas Gruber
*/

#include "Coordinates.h"
#include "Movement.h"
	
Coordinates::Coordinates()
:Vector(){
}
Coordinates::Coordinates(double x,double y)
:Vector(x,y){
}
void Coordinates::operator*= (const Movement &movement){
	Vector v;
	v.setToUnitVectorByAngle(movement.getAngle());
	v *= movement.getDistance();
	*this += v;
}