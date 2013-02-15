/*!
Copyright 2013 Andreas Gruber
*/

#include "PartialAdjustmentCalculation.h"

PartialAdjustmentCalculation::PartialAdjustmentCalculation()
	:AdjustmentCalculation(){
}
PartialAdjustmentCalculation::PartialAdjustmentCalculation(double lowerLimit,double upperLimit)
	:AdjustmentCalculation(lowerLimit,upperLimit){
}
void PartialAdjustmentCalculation::prepareValue(){
	currentResult = getCurrentValue();
}
double PartialAdjustmentCalculation::getResult(){
	return currentResult;
}
void PartialAdjustmentCalculation::correctValue(double value, double measuredResult){
	currentResult += (value-measuredResult);
	if(currentResult > getUpperLimit())
		currentResult = getUpperLimit();
	if(currentResult < getLowerLimit())
		currentResult = getLowerLimit();
}
void PartialAdjustmentCalculation::correctLastValue(double mesuredResult){
	correctValue(currentValue,mesuredResult);
}