/*!
Copyright 2013 Andreas Gruber
*/

#ifndef MATRIX
#define MATRIX

#include "DefineLib.h"

class Matrix{
private:
	const uint8_t n;
	double *d,*dbuf;
	double get(const double* buf,const uint8_t x,const uint8_t y);
	void set(double* buf,const uint8_t x,const uint8_t y,const double val);
public:
	const uint8_t getN();
	double get(const uint8_t x,const uint8_t y);
	void set(const uint8_t x,const uint8_t y,const double val);
	void coppyToBuff();
	void loadFromBuff();
	double getDeterminant(const uint8_t n);
	double getDeterminant();
	Matrix(const uint8_t n);
	~Matrix();
};

#endif