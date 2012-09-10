/*
* Copyright 2012 Andreas Gruber
*/

#ifndef VOLTAGE_DIVIDER
#define VOLTAGE_DIVIDER

#include <DefineLib.h>

class VoltageDivider {
private:
	//Pin definition
	int voltagePin;
	uint vdResistor1;
	uint vdResistorGes;
public:	
	//Variables
	VoltageDivider(int pin,int r1,int r2);
	uint calculateSuplyPotential();
};
#endif