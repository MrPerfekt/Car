/*!
Copyright 2013 Andreas Gruber
*/

#ifndef PARTIAL_ADJUSTMENT_CALCULATION
#define PARTIAL_ADJUSTMENT_CALCULATION

#include "DefineLib.h"
#include "AdjustmentCalculation.h"

class PartialAdjustmentCalculation  : public AdjustmentCalculation{
private:
	double currentValue;
	double currentResult;
protected:
	void prepareValue();
public:
	PartialAdjustmentCalculation();
	PartialAdjustmentCalculation(double lowerLimit,double upperLimit);
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