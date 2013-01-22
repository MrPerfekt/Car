/*!
Copyright 2012 Andreas Gruber
*/

#include "Vector.h"
#include "math.h"
	
double Vector::getX() const{
	return x;
}
void Vector::setX(double x){
	this->x = x;
}
double Vector::getY() const{
	return y;
}
void Vector::setY(double y){
	this->y = y;
}

Vector::Vector()
:x(0)
,y(0){
}
Vector::Vector(double x,double y)
:x(x)
,y(y){
}
void Vector::operator+= (const Vector &v){
	x += v.x;
	y += v.y;
}
void Vector::operator-= (const Vector &v){
	x -= v.x;
	y -= v.y;
}
void Vector::operator*= (const double d){
	x *= d;
	y *= d;
}
void Vector::operator/= (const double d){
	x /= d;
	y /= d;
}
double Vector::operator* (const Vector &v) const{
    return x*v.x+y*v.y;
}
	
double Vector::getLength() const{
    return sqrt(x*x+y*y);
}
void Vector::makeNormal(const bool left){
    double sX = x;
    x = y*(left ? -1 : 1);
    y = sX*(left ? 1 : -1);
}
void Vector::makeUnit(){
    *this /= getLength();
}
double Vector::angleBetween(const Vector &v) const{
    return acos((*this * v) / getLength() / v.getLength());
}
void Vector::set(const double x, const double y){
	setX(x);
	setY(y);
}
void Vector::set(const Vector &v){
	this->x = v.x;
	this->y = v.y;
}
void Vector::setToUnitVectorByAngle(double angle){
    set(cos(angle),sin(angle));
}
Vector Vector::clone() const{
	return Vector(x,y);
}