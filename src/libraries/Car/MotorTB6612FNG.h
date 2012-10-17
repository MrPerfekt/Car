/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOTOR_TB6612FNG
#define MOTOR_TB6612FNG

#include "DefineLib.h"
#include "Movement.h"

static int mPinSTBY = -1; //standby nicht definiert

void setupMotorSTBY(int pinSTBY);
void motorWriteDriverStandby(boolean stbyState);
void motorDisableStandby();
void motorEnableStandby();

class Motor {
private:
	//PINs
	uint8_t mPinPWM; //Speed control 
	uint8_t mPinIN1; //Direction
	uint8_t mPinIN2; //Direction

	uint8_t motorCalculateState(boolean inPin1, boolean inPin2);
	void waitDeadTime();
public:
	//Motor States
	static const uint8_t msStop = 0;
	static const uint8_t msForward = 1;
	static const uint8_t msBackward = 2;
	static const uint8_t msBreak = 3;
	static const uint8_t msWaitDeadTime = 4;
	static const uint8_t msUndefined = 5;

	uint8_t curMotorState;

	Motor(uint8_t pinPWM,uint8_t pinIN1,uint8_t pinIN2);
	void motorWriteStatus(uint8_t speed, bool inPin1, bool inPin2);
	/*!
	* Move specific motor at speed and direction
	* param speed: 0 is off, and 255 is full speed
	* param direction: true clockwise, false counter-clockwise
	*/
	void motorMove(uint8_t speed, bool direction);
	void motorStop();
	void motorBreak();
	void motorDeadTimeTest();
};
#endif