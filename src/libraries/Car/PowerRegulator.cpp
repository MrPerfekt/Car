/*!
Copyright 2012 Andreas Gruber
*/

#include "PowerRegulator.h"

PowerRegulator::PowerRegulator()
	:speed(255)
	,on(false){
}
PowerRegulator::~PowerRegulator(){
}
uint8_t PowerRegulator::getSpeed(){
	return speed;
}
void PowerRegulator::setSpeed(uint8_t speed){
	this->speed = speed;
	execute();
}
bool isOn(){
}
void PowerRegulator::turnOnOff(bool on){
	this->on = on;
	execute();
}