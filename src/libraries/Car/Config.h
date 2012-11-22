/*!
Copyright 2012 Andreas Gruber
*/

#ifndef _CONFIGURATION_h
#define _CONFIGURATION_h
#include "DefineLib.h"

class Config{
private:
	//! Car measures
	static const uint32_t steeringWheelsPosition = 230;
	//! Steering Servo
	static const uint8_t pinSteeringServo = 7;
	//! Motor
	static const uint8_t pinMotorPMW = 7; //! Speed control
	static const uint8_t pinMotorIn1 = 22; //! Direction
	static const uint8_t pinMotorIn2 = 23; //! Direction
	//! Wheels
	static const uint8_t pinWheelSensorR0 = 18;
	static const uint8_t intWheelSensorR0 = 5;
	static const uint8_t pinWheelSensorR1 = 19;
	static const uint8_t intWheelSensorR1 = 4;
	static const uint8_t pinWheelSensorL0 = 20;
	static const uint8_t intWheelSensorL0 = 3;
	static const uint8_t pinWheelSensorL1 = 21;
	static const uint8_t intWheelSensorL1 = 2;
	static const uint32_t wheelSteps = 24;//4*6
	static const uint32_t wheelDistance = 180;
	static const uint32_t wheelCircumference = 94;//! 6762 / 72 mm = 94
	// static double wheelStepDistance(){return (double)circumference / (double)wheelSteps;}
	//! Power Supplay Voltage Divider
	static const uint8_t apinVolDivPowerSupplay = 0;
	static const uint16_t volDivPowerSupplayRes1 = 966;
	static const uint16_t volDivPowerSupplayRes2 = 1989;
	//! MouseSensor
	static const uint8_t pinMouseSensorSCK = 255;//! Not connected
	static const uint8_t pinMouseSensorSDA = 255;//! Not connected
	static const uint8_t pinMouseSensorPD = 255;//! Not connected
	static const uint32_t mouseSensorCenterDistance = 0;
	//! Display
	static const uint8_t pinDisplayRST = 8;
	static const uint8_t pinDisplayCS = 9;
	static const uint8_t pinDisplayClk = 13;
	static const uint8_t pinDisplayData = 11;
public:
	//! Car measures
	static uint32_t getSteeringWheelsPosition();
	//! Steering Servo
	static const uint8_t getPinSteeringServo();
	//! Motor
	static const uint8_t getPinMotorPMW();
	static const uint8_t getPinMotorIn1();
	static const uint8_t getPinMotorIn2();
	//! Wheels
	static const uint8_t getPinWheelSensorR0();
	static const uint8_t getIntWheelSensorR0();
	static const uint8_t getPinWheelSensorR1();
	static const uint8_t getIntWheelSensorR1();
	static const uint8_t getPinWheelSensorL0();
	static const uint8_t getIntWheelSensorL0();
	static const uint8_t getPinWheelSensorL1();
	static const uint8_t getIntWheelSensorL1();
	static const uint32_t getWheelSteps();
	static const uint32_t getWheelDistance();
	static const uint32_t getWheelCircumference();
	static const uint32_t getWheelStepDistance();
	//! Power Supplay Voltage Divider
	static const uint8_t getAPinVolDivPowerSupplay();
	static const uint16_t getVolDivPowerSupplayRes1();
	static const uint16_t getVolDivPowerSupplayRes2();
	//! MouseSensor
	static const uint8_t getPinMouseSensorSCK();
	static const uint8_t getPinMouseSensorSDA();
	static const uint8_t getPinMouseSensorPD();
	static const uint32_t getMouseSensorCenterDistance();
	//! Display
	static const uint8_t getPinDisplayRST();
	static const uint8_t getPinDisplayCS();
	static const uint8_t getPinDisplayClk();
	static const uint8_t getPinDisplayData();
};

#endif

