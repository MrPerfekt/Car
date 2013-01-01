/*!
Copyright 2012 Andreas Gruber
*/

#ifndef VECTOR
#define VECTOR

class Vector{
private:
	double x;
	double y;
public:
	double getX() const;
	void setX(double x);
	double getY() const;
	void setY(double y);

	Vector();
	Vector(double x,double y);
	virtual void operator+= (const Vector &v);
	virtual void operator-= (const Vector &v);
	virtual void operator*= (const double d);
	virtual void operator/= (const double d);
	virtual double operator* (const Vector &v) const; //!dotProduct
	
    double getLength() const;
    void makeNormal(const bool left);
    void makeUnit();
    double angleBetween(const Vector &v) const;
    void set(const double x, const double y);
    void set(const Vector &v);
    Vector clone() const;
};
#endif