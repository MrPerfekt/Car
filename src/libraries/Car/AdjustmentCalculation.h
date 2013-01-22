/*!
Copyright 2013 Andreas Gruber
*/

#ifndef ADJUSTMENT_CALCULATION
#define ADJUSTMENT_CALCULATION

#include "DefineLib.h"

class AdjustmentCalculation {
private:
	double upperLimit;
	double lowerLimit;
	double lastValue;
	double lastResult;
	double currentResult;
public:
	AdjustmentCalculation();
	AdjustmentCalculation(double lowerLimit,double upperLimit);
	/*!
	param value The input value
	return The wanted result
	*/
	double getValue(double value);
	/*!
	return The wanted result of the last getValue command
	*/
	double getUpdateValue();
	/*!
	param value The input value
	param measuredResult The result of the value.
	param measuredResult The correct result of the value.
	*/
	void correctValue(double value, double result, double measuredResult);
	/*!
	Corrects the last value at the pararmeter of getValue
	*/
	void correctLastValue(double mesuredResult);
};

#endif