/*!
Copyright 2012 Andreas Gruber
*/

#ifndef _CONFIGURATION_h
#define _CONFIGURATION_h
#include "DefineLib.h"

class Config{
private:
	//Car measures
	static const uint32_t steeringWheelsPosition = 230;
	//Steering Servo
	static const uint8_t pinSteeringServo = 7;
	//Motor
	static const uint8_t pinMotorPMW = 5; //! Speed control
	static const uint8_t pinMotorIn1 = 6; //! Direction
	static const uint8_t pinMotorIn2 = 4; //! Direction
	//Wheels
	static const uint8_t pinWheelSensorR = 2;
	static const uint8_t pinWheelSensorL = 3;
	//Power Supplay Voltage Divider
	static const uint8_t apinVolDivPowerSupplay = 0;
	static const uint16_t volDivPowerSupplayRes1 = 966;
	static const uint16_t volDivPowerSupplayRes2 = 1989;
	//MouseSensor
	static const uint8_t pinMouseSensorSCK = 12;
	static const uint8_t pinMouseSensorSDA = 10;
	static const uint8_t pinMouseSensorPD = A1;
	static const uint32_t mouseSensorCenterDistance = 300;
	//Display
	static const uint8_t pinDisplayRST = 8;
	static const uint8_t pinDisplayCS = 9;
	static const uint8_t pinDisplayClk = 13;
	static const uint8_t pinDisplayData = 11;
public:
	//Car measures
	static uint32_t getSteeringWheelsPosition();
	//Steering Servo
	static const uint8_t getPinSteeringServo();
	//Motor
	static const uint8_t getPinMotorPMW();
	static const uint8_t getPinMotorIn1();
	static const uint8_t getPinMotorIn2();
	//Wheels
	static const uint8_t getPinWheelSensorR();
	static const uint8_t getPinWheelSensorL();
	//Power Supplay Voltage Divider
	static const uint8_t getAPinVolDivPowerSupplay();
	static const uint16_t getVolDivPowerSupplayRes1();
	static const uint16_t getVolDivPowerSupplayRes2();
	//MouseSensor
	static const uint8_t getPinMouseSensorSCK();
	static const uint8_t getPinMouseSensorSDA();
	static const uint8_t getPinMouseSensorPD();
	static const uint32_t getMouseSensorCenterDistance();
	//Display
	static const uint8_t getPinDisplayRST();
	static const uint8_t getPinDisplayCS();
	static const uint8_t getPinDisplayClk();
	static const uint8_t getPinDisplayData();
};

#endif

