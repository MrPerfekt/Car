/*!
Copyright 2013 Andreas Gruber
*/

#ifndef REGRESSION_ADJUSTMENT_CALCULATION
#define REGRESSION_ADJUSTMENT_CALCULATION

#include "DefineLib.h"
#include "AdjustmentCalculation.h"
class PartialRegression;

class RegressionAdjustmentCalculation : public AdjustmentCalculation{
private:

	double currentValue;
	double *regResults;
	PartialRegression *regression;
public:
	RegressionAdjustmentCalculation();
	RegressionAdjustmentCalculation(double lowerLimit,double upperLimit);
	/*!
	param value The input value
	return The wanted result
	*/
	void setValue(double value);
	/*!
	return The wanted result of the last getValue command
	*/
	double getResult();
	/*!
	param value The input value
	param measuredResult The result of the value.
	param measuredResult The correct result of the value.
	*/
	void correctValue(double value, double measuredResult);
	/*!
	Corrects the last value at the pararmeter of getValue
	*/
	void correctLastValue(double mesuredResult);
};

#endif