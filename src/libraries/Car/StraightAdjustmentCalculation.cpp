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
void StraightAdjustmentCalculation::prepareValue(){
	currentResult = getCurrentValue();
}
double StraightAdjustmentCalculation::getResult(){
	return currentResult;
}
void StraightAdjustmentCalculation::correctValue(double value, double measuredResult){
	currentResult -= measuredResult;
	if(currentResult > getUpperLimit())
		currentResult = getUpperLimit();
	if(currentResult < getLowerLimit())
		currentResult = getLowerLimit();
}