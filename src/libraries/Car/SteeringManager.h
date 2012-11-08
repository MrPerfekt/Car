/*
* Copyright 2012 Andreas Gruber
*/

#ifndef STEERING_MANAGER
#define STEERING_MANAGER

#include "DefineLib.h"
#include "ServoProxy.h"
#include "MotorTB6612FNG.h"
#include "PositionCalculator.h"
#include "Movement.h"


class SteeringManager {
private:
	enum SteeringState{
		ss_stop,
		ss_driveStraightForward,
		ss_driveStraightBackward,
		ss_driveTurnLeftForward,
		ss_driveTurnLeftBackward,
		ss_driveTurnRightForward,
		ss_driveTurnRightBackward,
	};
	ServoProxy& servoProxy;
	Motor& motorPowerEngine;
	PositionCalculator& positionCalculator;
	double stopConditionValue;
	uint8_t state;
	double steeringWheelsPosition;
	/*!
	*/
	double calculateRadiusByMovement(const Movement& movement);
	/*!
	Set the steering angle by the radius the car should drive
	\param radius Radius of the turn
	*/
	void setSteeringAngleByRadius(double radius);
	/*!
	Calculates the radius of the circle the car drive with this movement
	\param movement From this movement the radius is calculated
	\return Radius
	*/
	double calculateSteeringWheelAngle(const Movement& movement);
public:
	SteeringManager(ServoProxy& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator);
	/*!
	Get the maximal radius of the car
	\param leftTurn If the car should drive a left [= true] or a right [= false] turn
	\return The maximal radius 
	*/
	double getMaxRadius(bool leftTurn);
	void driveStraight(double distance);
	void driveStraight(double distance,bool forward);
	void driveTurn(double radius, double angle);
	void driveTurn(double radius, double angle, bool forward, bool leftTurn);
	/*!
	Update the current steering action
	If the action has finished update() will return true
	If update() is executed again after finishing it will stop the motor
	\return true if the current action has finished
	*/
	bool update();
};

#endif