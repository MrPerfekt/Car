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

double AdjustmentCalculation::getValue(double value){
	currentResult = value;
	lastValue = value;
	return lastResult = value;
	//return lastResult;
}
double AdjustmentCalculation::getUpdateValue(){
	return currentResult;
}
void AdjustmentCalculation::correctValue(double value, double result, double measuredResult){
	Serial2.println(currentResult);
	Serial2.println(value);
	Serial2.println(result);
	Serial2.println(measuredResult);
	Serial2.println("=====");
	currentResult += (value-measuredResult);
	if(currentResult > upperLimit)
		currentResult = upperLimit;
	if(currentResult < lowerLimit)
		currentResult = lowerLimit;
}
void AdjustmentCalculation::correctLastValue(double mesuredResult){
	correctValue(lastValue,lastResult,mesuredResult);
}