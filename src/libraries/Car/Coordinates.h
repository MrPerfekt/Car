/*!
Copyright 2012 Andreas Gruber
*/

#ifndef COORDINATES
#define COORDINATES

class Movement;

class Coordinates{
private:
	double x;
	double y;
public:
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	Coordinates();
	Coordinates(double x,double y);
	virtual void operator+= (const Coordinates &coordinates);
	virtual void operator-= (const Coordinates &coordinates);
	virtual void operator*= (const Movement &movement);
};

class OrientationCoordinates : public Coordinates{
private:
	double angle;
public:
	double getAngle() const;
	void setAngle(double angle);

	OrientationCoordinates();
	OrientationCoordinates(double x,double y,double angle);
	virtual void operator+= (const OrientationCoordinates &coordinates);
	virtual void operator-= (const OrientationCoordinates &coordinates);
	virtual void operator*= (const Movement &movement);
};
#endif
