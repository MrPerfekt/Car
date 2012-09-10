/*
* Copyright 2012 Andreas Gruber
*/

#ifndef MOTOR_TB6612FNG
#define MOTOR_TB6612FNG

#include<DefineLib.h>

static int mPinSTBY = -1; //standby nicht definiert

void setupMotorSTBY(int pinSTBY);
void motorWriteDriverStandby(boolean stbyState);
void motorDisableStandby();
void motorEnableStandby();

class Motor {
private:
	//PINs
	int mPinPWM; //Speed control 
	int mPinIN1; //Direction
	int mPinIN2; //Direction

	byte motorCalculateState(boolean inPin1, boolean inPin2);
	void waitDeadTime();
public:
	//Motor States
	static const byte msStop = 0;
	static const byte msForward = 1;
	static const byte msBackward = 2;
	static const byte msBreak = 3;
	static const byte msWaitDeadTime = 4;
	static const byte msUndefined = 5;

	byte curMotorState;

	Motor(int pinPWM,int pinIN1,int pinIN2);
	void motorWriteStatus(int speed, boolean inPin1, boolean inPin2);
	void motorMove(int speed, int direction);
	void motorStop();
	void motorBreak();
	void motorDeadTimeTest();
};
#endif