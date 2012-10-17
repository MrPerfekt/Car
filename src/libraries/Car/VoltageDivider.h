/*
* Copyright 2012 Andreas Gruber
*/

#ifndef VOLTAGE_DIVIDER
#define VOLTAGE_DIVIDER

#include <DefineLib.h>

class VoltageDivider {
private:
	//Pin definition
	uint8_t voltagePin;
	uint16_t vdResistor1;
	uint16_t vdResistorGes;
public:	
	//Variables
	VoltageDivider(uint8_t pin,uint16_t r1,uint16_t r2);
	uint16_t calculateSuplyPotential();
};
#endif