/*!
Copyright 2013 Andreas Gruber
*/

#include "CarPowerRegulator.h"
#include "MotorTB6612FNG.h"
#include "Config.h"

uint8_t CarPowerRegulator::getSpeed(){
	return speed;
}
void CarPowerRegulator::setSpeed(uint8_t speed){
	this->speed = speed;
	execute();
}
bool CarPowerRegulator::isOn(){
	return on;
}
void CarPowerRegulator::turnOnOff(bool on){
	this->on = on;
	execute();
}
bool CarPowerRegulator::isTurnForward(){
	return forward;
}
void CarPowerRegulator::setDirection(bool forward){
	this->forward = forward;
	execute();
}


CarPowerRegulator::CarPowerRegulator(){
	m = new Motor(Config::getPinMotorPMW(),Config::getPinMotorIn1(),Config::getPinMotorIn2());
}

void CarPowerRegulator::execute(){
	if(isOn()){
		m->motorMove(getSpeed(),isTurnForward());
	}else{
		m->motorStop();
	}
}