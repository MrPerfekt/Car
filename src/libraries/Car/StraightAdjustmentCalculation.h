/*!
Copyright 2013 Andreas Gruber
*/

#ifndef STRAIGHT_ADJUSTMENT_CALCULATION
#define STRAIGHT_ADJUSTMENT_CALCULATION

#include "DefineLib.h"
#include "AdjustmentCalculation.h"

class StraightAdjustmentCalculation  : public AdjustmentCalculation{
private:
	double currentResult;
protected:
	void prepareValue();
public:
	StraightAdjustmentCalculation();
	StraightAdjustmentCalculation(double lowerLimit,double upperLimit);
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
};

#endif