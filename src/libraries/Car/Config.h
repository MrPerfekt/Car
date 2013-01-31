/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CONFIG
#define CONFIG

/*! Pinnumber
0-100 Arduino Hardware Pin
100-255 Extend Pin (Multyplex, Portexpander, Shift Register, ...)
*/

#include "DefineLib.h"
#include "OrientationCoordinates.h"

class SensorConfig{
private:
	const OrientationCoordinates* position;
public:
	const OrientationCoordinates& getPosition() const;
	SensorConfig(const OrientationCoordinates* position);
};
class SonicSensorConfig : public SensorConfig{
private:
	uint8_t pinTrig;
	uint8_t pinEcho;
public:
	const uint8_t getPinTrig() const;
	const uint8_t getPinEcho() const;
	SonicSensorConfig(const OrientationCoordinates* position, const uint8_t pinTrig,const uint8_t pinEcho);
};


class Config{
private:
	//! Sonic sensor configuration
	static const uint16_t sonicSensorValidationRange = 700;
	static const uint8_t sonicSensorCnt = 3;
	static const SonicSensorConfig sonicSensorConfigs[];
	//! Car measures
	static const uint16_t steeringWheelsPosition = 230;
	//! Reset trigger pin
	static const uint8_t resetTriggerPin = 53;
	//! Steering Servo
	static const uint8_t pinSteeringServo = 6;
	static const uint16_t servoAbsAngleMiddleDeg = 85;
	static const uint16_t servoMaxAngleDeg = 40;
	static const uint16_t minSteeringRadius = 500;
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
	static const uint8_t maxSteeringEquationPow = 4;
	//! Power Supplay Voltage Divider
	static const uint8_t pinAVolDivPowerSupplay = 0;
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
	//! Sonic sensor configuration
	static const uint16_t getSonicSensorValidationRange();
	static const uint8_t getSonicSensorCnt();
	static const SonicSensorConfig* getSonicSensorConfigs();
	//! Car measures
	static uint32_t getSteeringWheelsPosition();
	//! Reset trigger pin
	static uint8_t getResetTriggerPin();
	//! Steering Servo
	static const uint8_t getPinSteeringServo();
	static const double getServoAbsAngleMiddleDeg();//! The steering servo angle where the car drives straight
	static const double getServoMaxAngleDeg();//! The maximal angle which can be set to the steering servo
	static const uint16_t getMinSteeringRadius();//! The minimal radius which can be driven by the car
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
	static const uint8_t getWheelSteps();
	static const uint16_t getWheelDistance();
	static const uint16_t getWheelCircumference();
	static const double getWheelStepDistance();
	static const uint8_t getMaxSteeringEquationPow();
	//! Power Supplay Voltage Divider
	static const uint8_t getPinAVolDivPowerSupplay();
	static const uint16_t getVolDivPowerSupplayRes1();
	static const uint16_t getVolDivPowerSupplayRes2();
	//! MouseSensor
	static const uint8_t getPinMouseSensorSCK();
	static const uint8_t getPinMouseSensorSDA();
	static const uint8_t getPinMouseSensorPD();
	static const uint16_t getMouseSensorCenterDistance();
	//! Display
	static const uint8_t getPinDisplayRST();
	static const uint8_t getPinDisplayCS();
	static const uint8_t getPinDisplayClk();
	static const uint8_t getPinDisplayData();
};

#endif

