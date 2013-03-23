/*!
Copyright 2013 Andreas Gruber
*/

#ifndef STEERING_MANAGER
#define STEERING_MANAGER

#include "DefineLib.h"
//#include "ServoProxy.h"
//#include "MotorTB6612FNG.h"
//#include "PositionCalculator.h"
//#include "Movement.h"
class StraightMovement;
class TurnMovement;

class SteeringManager {
public:
	/*!
	@return If the current steering action has finnished.
	*/
	virtual bool hasFinished() const = 0;
	//SteeringManager(ServoProxy& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator);
	/*!
	Drive a straight movement.
	\param distance Distance.
	*/
	virtual void driveStraight(double distance) = 0;
	/*!
	Implements the drive aktion for StraightMovements.
	\param movement Movement
	*/
	void driveMovement(StraightMovement& movement);
	/*!
	Drive a turnmovement
	\param radius Radius
	\param angle angle
	*/
	virtual void driveTurn(double radius, double angle) = 0;
	/*!
	Drive a turnmovement
	\param movement Movement
	*/
	void driveMovement(TurnMovement& movement);
	/*!
	Update the current steering action.
	This means that the current movement which is calculated by the PositionCalculator become analysed.
	The result of this analyse is used to redefine the task of the steering servo.
	The progress or the state of the steering action can be called with getState().
	Note: Before this method can be executed PositionCalculator.update() have to be invoked.
	*/
	virtual void update() = 0;
	/*!
	Stop all motors and finish all steering actions.
	This mehtod have to be called after the last task for the steeringManager.
	*/
	virtual void stop() = 0;
};

#endif