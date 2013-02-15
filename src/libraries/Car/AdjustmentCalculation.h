/*!
Copyright 2013 Andreas Gruber
*/

#ifndef ADJUSTMENT_CALCULATION
#define ADJUSTMENT_CALCULATION

#include "DefineLib.h"

class AdjustmentCalculation {
private:
	double currentValue;
	double upperLimit;
	double lowerLimit;
protected:
	/*!
	This method get invoked when the currentValue has changed;
	*/
	virtual void prepareValue() = 0;
	const double getCurrentValue() const;
	const double getUpperLimit() const;
	const double getLowerLimit() const;
public:
	AdjustmentCalculation();
	AdjustmentCalculation(double lowerLimit,double upperLimit);
	/*!
	param value The input value
	*/
	void setValue(const double value);
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
	void correctLastValue(double measuredResult);
};

#endif