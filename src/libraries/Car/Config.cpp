/*!
Copyright 2013 Andreas Gruber
*/

#include "Config.h"

const OrientationCoordinates& SensorConfig::getPosition() const{
	return *position;
}
SensorConfig::SensorConfig(const OrientationCoordinates* position)
	:position(position){
}	

const uint8_t SonicSensorConfig::getPinTrig() const{
	return pinTrig;
}
const uint8_t SonicSensorConfig::getPinEcho() const{
	return pinEcho;
}
SonicSensorConfig::SonicSensorConfig(const OrientationCoordinates* position, const uint8_t pinTrig,const uint8_t pinEcho)
	:SensorConfig(position)
	,pinTrig(pinTrig)
	,pinEcho(pinEcho){
}

//! Sonic sensor configuration
const uint16_t Config::getSonicSensorValidationRange(){
	return sonicSensorValidationRange;
}
const uint8_t Config::getSonicSensorCnt(){
	return sonicSensorCnt;
}
const SonicSensorConfig Config::sonicSensorConfigs[] = {
	SonicSensorConfig(new OrientationCoordinates(0,310,0),			24,25),
	SonicSensorConfig(new OrientationCoordinates(70,300,PI/2*3),	26,27),
	SonicSensorConfig(new OrientationCoordinates(-70,300,PI/2),		28,29),
};
const SonicSensorConfig* Config::getSonicSensorConfigs(){
	return sonicSensorConfigs;
}
//! Car measures
uint32_t Config::getSteeringWheelsPosition(){
	return steeringWheelsPosition;
}
//! Reset Trigger Pin
uint8_t Config::getResetTriggerPin(){
	return resetTriggerPin;
}
//! Steering Servo
const uint8_t Config::getPinSteeringServo(){
	return pinSteeringServo;
}
const double Config::getServoAbsAngleMiddleDeg(){
	return servoAbsAngleMiddleDeg;
}
const double Config::getServoMaxAngleDeg(){
	return servoMaxAngleDeg;
}
const uint16_t Config::getMinSteeringRadius(){
	return minSteeringRadius;
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
const uint8_t Config::getWheelSteps(){
	return wheelSteps;
}
const uint16_t Config::getWheelDistance(){
	return wheelDistance;
}
const uint16_t Config::getWheelCircumference(){
	return wheelCircumference;
}
const double Config::getWheelStepDistance(){
	return (double)getWheelCircumference() / (double)getWheelSteps();
}
const uint8_t Config::getMaxSteeringEquationPow(){
	return maxSteeringEquationPow;
}
//! Power Supplay Voltage Divider
const uint8_t Config::getPinAVolDivPowerSupplay(){
	return pinAVolDivPowerSupplay;
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
const uint16_t Config::getMouseSensorCenterDistance(){
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