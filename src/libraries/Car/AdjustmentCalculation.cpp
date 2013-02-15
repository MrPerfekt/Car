/*!
Copyright 2013 Andreas Gruber
*/

#include "AdjustmentCalculation.h"
#include "float.h"

AdjustmentCalculation::AdjustmentCalculation()
	:lowerLimit(DBL_MIN)
	,upperLimit(DBL_MAX){
			
}
AdjustmentCalculation::AdjustmentCalculation(double lowerLimit,double upperLimit)
	:lowerLimit(lowerLimit)
	,upperLimit(upperLimit){
}
const double AdjustmentCalculation::getUpperLimit() const{
	return upperLimit;
}
const double AdjustmentCalculation::getLowerLimit() const{
	return lowerLimit;
}

void AdjustmentCalculation::setValue(const double value){
	currentValue = value;
	prepareValue();
}
const double AdjustmentCalculation::getCurrentValue() const{
	return currentValue;
}
void AdjustmentCalculation::correctLastValue(const double measuredResult){
	correctValue(getCurrentValue(),measuredResult);
}