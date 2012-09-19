/*
* Copyright 2012 Andreas Gruber
*/

#include "VoltageDivider.h"

VoltageDivider::VoltageDivider(uint8_t pin,uint16_t r1,uint16_t r2){
	voltagePin = pin;
	vdResistor1 = r1;
	vdResistorGes = r1+r2;
}

uint16_t VoltageDivider::calculateSuplyPotential(){//return mV
	return (uint16_t)((analogRead(voltagePin) * (uint32_t)5000 * vdResistorGes) / 1024 / vdResistor1);
}