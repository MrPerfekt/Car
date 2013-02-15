/*!
Copyright 2013 Andreas Gruber
*/

#ifndef SEGMENT_ADJUSTMENT_CALCULATION
#define SEGMENT_ADJUSTMENT_CALCULATION

#include "DefineLib.h"
#include "AdjustmentCalculation.h"

class SegmentAdjustmentCalculation : public AdjustmentCalculation {
private:
public:
	double upperLimit;
	double lowerLimit;
	SegmentAdjustmentCalculation();
	SegmentAdjustmentCalculation(double lowerLimit,double upperLimit);
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
	param measuredResult The measured result of the value.
	*/
	void correctValue(double value, double measuredResult);
	/*!
	Corrects the last value at the pararmeter of getValue
	*/
	void correctLastValue(double mesuredResult);
};

#endif