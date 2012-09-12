/*
* Copyright 2012 Andreas Gruber
*/

#include "Movement.h"

Movement::Movement()
:distance(0),angle(0){
}
Movement::Movement(long distance,int angle)
:distance(distance),angle(angle){
}
Movement Movement::getMovementByCoordinates(long x,long y){
	Movement m;
	m.distance = 0;
	m.angle = 0;
}