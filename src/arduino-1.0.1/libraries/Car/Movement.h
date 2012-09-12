/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOVEMENT
#define MOVEMENT

class Movement{
private:
public:
	long distance;
	int angle;
	Movement();
	Movement(long distance,int angle);
	static Movement getMovementByCoordinates(long x,long y);
};

#endif