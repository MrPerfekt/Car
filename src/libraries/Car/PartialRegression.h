/*!
Copyright 2013 Andreas Gruber
*/

#ifndef PARTIAL_REGRESSION
#define PARTIAL_REGRESSION
#include "DefineLib.h"
class Matrix;
class Vector;

class PartialRegression{
private:
	Matrix *sum;
    double *xsum;
    double *xysum;
    double *solution;
	const uint8_t equationPow;
    const uint16_t n;
	uint8_t solEpot;
public:
    PartialRegression(const uint8_t equationPow);
    ~PartialRegression();
    void addPoint(const Vector &p);
    double* calculate(const uint8_t epot);
	double calculateY(double x);
};

#endif