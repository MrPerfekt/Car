/*!
Copyright 2013 Andreas Gruber
*/

#include "StraightAdjustmentCalculation.h"

StraightAdjustmentCalculation::StraightAdjustmentCalculation()
	:AdjustmentCalculation(){
			
}
StraightAdjustmentCalculation::StraightAdjustmentCalculation(double lowerLimit,double upperLimit)
	:AdjustmentCalculation(lowerLimit,upperLimit){
}

void StraightAdjustmentCalculation::setValue(double value){
	currentResult = value;
	currentValue = value;
	//return lastResult;
}
double StraightAdjustmentCalculation::getResult(){
	return currentResult;
}
void StraightAdjustmentCalculation::correctValue(double value, double measuredResult){
	currentResult += (value-measuredResult);
	if(currentResult > upperLimit)
		currentResult = upperLimit;
	if(currentResult < lowerLimit)
		currentResult = lowerLimit;
}
void StraightAdjustmentCalculation::correctLastValue(double mesuredResult){
	correctValue(currentValue,mesuredResult);
}