/*!
Copyright 2012 Andreas Gruber
*/

#ifndef COORDINATES
#define COORDINATES

class Coordinates{
private:
public:
	double x;
	double y;
	Coordinates();
	Coordinates(double x,double y);
	Coordinates operator+= (const Coordinates &coordinates);
	Coordinates operator-= (const Coordinates &coordinates);
};
#endif
