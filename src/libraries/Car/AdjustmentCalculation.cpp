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