/*!
Copyright 2013 Andreas Gruber
*/

#include "RegressionAdjustmentCalculation.h"
#include "PartialRegression.h"
#include "float.h"

RegressionAdjustmentCalculation::RegressionAdjustmentCalculation()
:AdjustmentCalculation()
,regression(new PartialRegression(Config::getMaxSteeringEquationPow())){
}
RegressionAdjustmentCalculation::RegressionAdjustmentCalculation(double lowerLimit,double upperLimit)
:AdjustmentCalculation(lowerLimit,upperLimit)
,regression(new PartialRegression(Config::getMaxSteeringEquationPow())){
}

void RegressionAdjustmentCalculation::setValue(double value){
	currentValue = value;
}
double RegressionAdjustmentCalculation::getResult(){
	double currentResult = NAN;
	for(int i = Config::getMaxSteeringEquationPow(); i >= 0; i--){
		regression->calculate(i);
		currentResult = regression->calculateY(currentValue);
		if(!isnan(currentResult))
			break;
	}
	if(isnan(currentResult))
		currentResult = 0;
	if(currentResult > upperLimit)
		currentResult = upperLimit;
	if(currentResult < lowerLimit)
		currentResult = lowerLimit;
	return currentResult;
}
void RegressionAdjustmentCalculation::correctValue(double value, double measuredResult){
	Vector v = Vector(currentValue,measuredResult);
	regression->addPoint(v);
}
void RegressionAdjustmentCalculation::correctLastValue(double mesuredResult){
	correctValue(currentValue,mesuredResult);
}