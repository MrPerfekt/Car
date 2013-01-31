/*!
Copyright 2013 Andreas Gruber
*/

#ifndef ADJUSTMENT_CALCULATION
#define ADJUSTMENT_CALCULATION

#include "DefineLib.h"

class AdjustmentCalculation {
private:
public:
	double upperLimit;
	double lowerLimit;
	AdjustmentCalculation();
	AdjustmentCalculation(double lowerLimit,double upperLimit);
	/*!
	param value The input value
	return The wanted result
	*/
	virtual void setValue(double value) = 0;
	/*!
	return The wanted result of the last getValue command
	*/
	virtual double getResult() = 0;
	/*!
	param value The input value
	param measuredResult The measured result of the value.
	*/
	virtual void correctValue(double value, double measuredResult) = 0;
	/*!
	Corrects the last value at the pararmeter of getValue
	*/
	virtual void correctLastValue(double mesuredResult) = 0;
};

#endif