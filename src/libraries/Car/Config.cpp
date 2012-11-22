/*!
Copyright 2012 Andreas Gruber
*/

#include "Config.h"
	
//! Car measures
uint32_t Config::getSteeringWheelsPosition(){
	return steeringWheelsPosition;
}
//! Steering Servo
const uint8_t Config::getPinSteeringServo(){
	return pinSteeringServo;
}
//! Motor
const uint8_t Config::getPinMotorPMW(){
	return pinMotorPMW;
}
const uint8_t Config::getPinMotorIn1(){
	return pinMotorIn1;
}
const uint8_t Config::getPinMotorIn2(){
	return pinMotorIn2;
}
//! Wheels
const uint8_t Config::getPinWheelSensorR0(){
	return pinWheelSensorR0;
}
const uint8_t Config::getIntWheelSensorR0(){
	return intWheelSensorR0;
}
const uint8_t Config::getPinWheelSensorR1(){
	return pinWheelSensorR1;
}
const uint8_t Config::getIntWheelSensorR1(){
	return intWheelSensorR1;
}
const uint8_t Config::getPinWheelSensorL0(){
	return pinWheelSensorL0;
}
const uint8_t Config::getIntWheelSensorL0(){
	return intWheelSensorL0;
}
const uint8_t Config::getPinWheelSensorL1(){
	return pinWheelSensorL1;
}
const uint8_t Config::getIntWheelSensorL1(){
	return intWheelSensorL1;
}
const uint32_t Config::getWheelSteps(){
	return wheelSteps;
}
const uint32_t Config::getWheelDistance(){
	return wheelDistance;
}
const uint32_t Config::getWheelCircumference(){
	return wheelCircumference;
}
const double Config::getWheelStepDistance(){
	return (double)getWheelCircumference() / (double)getWheelSteps();
}
//! Power Supplay Voltage Divider
const uint8_t Config::getAPinVolDivPowerSupplay(){
	return apinVolDivPowerSupplay;
}
const uint16_t Config::getVolDivPowerSupplayRes1(){
	return volDivPowerSupplayRes1;
}
const uint16_t Config::getVolDivPowerSupplayRes2(){
	return volDivPowerSupplayRes2;
}
//! MouseSensor
const uint8_t Config::getPinMouseSensorSCK(){
	return pinMouseSensorSCK;
}
const uint8_t Config::getPinMouseSensorSDA(){
	return pinMouseSensorSDA;
}
const uint8_t Config::getPinMouseSensorPD(){
	return pinMouseSensorPD;
}
const uint32_t Config::getMouseSensorCenterDistance(){
	return mouseSensorCenterDistance;
}
//! Display
const uint8_t Config::getPinDisplayRST(){
	return pinDisplayRST;
}
const uint8_t Config::getPinDisplayCS(){
	return pinDisplayCS;
}
const uint8_t Config::getPinDisplayClk(){
	return pinDisplayClk;
}
const uint8_t Config::getPinDisplayData(){
	return pinDisplayData;
}