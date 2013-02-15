/*!
Copyright 2013 Andreas Gruber
*/

#include "SegmentAdjustmentCalculation.h"
#include "float.h"

SegmentAdjustmentCalculation::SegmentAdjustmentCalculation()
	:AdjustmentCalculation(DBL_MIN,DBL_MAX){
			
}
SegmentAdjustmentCalculation::SegmentAdjustmentCalculation(double lowerLimit,double upperLimit)
	:AdjustmentCalculation(lowerLimit,upperLimit){
}