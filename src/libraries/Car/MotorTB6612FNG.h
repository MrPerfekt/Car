/*!
Copyright 2013 Andreas Gruber
*/

#ifndef MOTOR_TB6612FNG
#define MOTOR_TB6612FNG

#include "DefineLib.h"

static int mPinSTBY = -1; //standby nicht definiert

void setupMotorSTBY(int pinSTBY);
void motorWriteDriverStandby(boolean stbyState);
void motorDisableStandby();
void motorEnableStandby();

class Motor {
public:
	//Motor States
	enum MotorState{
		msStop = 0,
		msForward = 1,
		msBackward = 2,
		msBreak = 3,
		msWaitDeadTime = 4,
		msUndefined = 5,
	};
private:
	uint8_t pinPWM;
	uint8_t pinIn1;
	uint8_t pinIn2;

	static const uint8_t delayTimeMicroseconds = 10; //230 ns (Datasheet)
	Motor::MotorState motorCalculateState(boolean inPin1, boolean inPin2);
	/*! 
	Wait the dead-time to prevent damaging of the motordriver
	*/
	void waitDeadTime();
public:
	MotorState curMotorState;

	Motor(uint8_t pinPWM, uint8_t pinIn1, uint8_t pinIn2);
	void motorWriteStatus(uint8_t speed, bool inPin1, bool inPin2);
	/*!
	Move specific motor at speed and direction
	param speed: 0 is off, and 255 is full speed
	param direction: true clockwise, false counter-clockwise
	*/
	void motorMove(uint8_t speed, bool direction);
	void motorStop();
	void motorBreak();
	void motorDeadTimeTest();
};
#endif