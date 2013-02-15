/*!
Copyright 2012 Andreas Gruber
*/

#include "CarPowerRegulator.h"
#include "MotorTB6612FNG.h"
#include "Config.h"

CarPowerRegulator::CarPowerRegulator(){
	m = new Motor(Config::getPinMotorPMW(),Config::getPinMotorIn1(),Config::getPinMotorIn2());
}

void CarPowerRegulator::execute(){
	if(isOn()){
		bool forward = speed >= 0;
		if(!forward)
			speed = -1 * speed;
		m->motorMove(direction,forward);
	}else{
		m->motorStop();
	}
}