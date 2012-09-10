/*
* Copyright 2012 Andreas Gruber
*/

#include "VoltageDivider.h"

VoltageDivider::VoltageDivider(int pin,int r1,int r2){
	voltagePin = pin;
	vdResistor1 = r1;
	vdResistorGes = r1+r2;
}

uint VoltageDivider::calculateSuplyPotential(){//return mV
	return (unsigned int)((analogRead(voltagePin) * (unsigned long long)5000 * vdResistorGes) / 1024 / vdResistor1);
}