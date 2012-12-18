/*!
Copyright 2012 Andreas Gruber
*/

#ifndef REGULAR_STEERING_MANAGER
#define REGULAR_STEERING_MANAGER

#include "DefineLib.h"
#include "SteeringManager.h"
#include "ServoProxy.h"
class Motor;
class PositionCalculator;
class Movement;

class RegularSteeringManager : public SteeringManager{
public:
	enum SteeringState{
		ss_stop,
		ss_driveStraightForward,
		ss_driveStraightBackward,
		ss_driveTurnLeftForward,
		ss_driveTurnLeftBackward,
		ss_driveTurnRightForward,
		ss_driveTurnRightBackward,
	};
private:
	SteeringState state;
	ServoProxy& servoProxy;
	Motor& motorPowerEngine;
	PositionCalculator& positionCalculator;
	double stopConditionValue;
	/*!
	Calculates the radius by a movement
	*/
	const double calculateRadiusByMovement(const Movement& movement) const;
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
	/*!
	@param state The state of the current steering action.
	*/
	void setState(SteeringState state);
public:
	/*!
	@return If the current steering action has finnished.
	*/
	bool hasFinished();
	/*!
	Get the maximal radius of the car
	\param leftTurn If the car should drive a left [= true] or a right [= false] turn
	\return The maximal radius 
	*/
	double getMaxRadius(bool leftTurn);
	/*!
	@return The state of the current steering action.
	*/
	SteeringState getState();
	RegularSteeringManager(ServoProxy& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator);
	void driveStraight(double distance);
	void driveTurn(double radius, double angle);
	/*!
	Update the current steering action.
	This means that the current movement which is calculated by the PositionCalculator become analysed.
	The result of this analyse is used to redefine the task of the steering servo.
	The progress or the state of the steering action can be called with getState().
	Note: Before this method can be executed PositionCalculator.update() have to be invoked.
	*/
	void update();
	/*!
	Stop all motors and finish all steering actions.
	This mehtod have to be called after the last task for the steeringManager.
	*/
	void stop();
};

#endif