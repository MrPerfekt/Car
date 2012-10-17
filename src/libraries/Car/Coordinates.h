/*
* Copyright 2012 Andreas Gruber
*/

#ifndef COORDINATES
#define COORDINATES

class Coordinates{
private:
public:
	long x;
	long y;
	Coordinates();
	Coordinates(long x,long y);
	Coordinates operator+= (const Coordinates &coordinates);
	Coordinates operator-= (const Coordinates &coordinates);
};
#endif