/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CAR_STEERING_REGULATOR
#define CAR_STEERING_REGULATOR

#include "SteeringRegulator.h"

class ServoProxy;
class AdjustmentCalculation;

class CarSteeringRegulator : public SteeringRegulator{
private:
	ServoProxy *servoProxy;
	AdjustmentCalculation *adjustmentCalculation;
	void correctSteeringServoAngle(double currentRealSteeringServoAngle);
	void setSteeringServoAngle(double steeringServoAngle);
public:
	CarSteeringRegulator();
	~CarSteeringRegulator();
	void turnOnOff(bool on);
	void setRadius(double radius);
	/*!
	Because the steering mechanism can has mechanical tollerances the radius can be updated based on measured values.
	\param currentRadius The real radius of the car
	*/
	void correcRadius(double currentRadius);
	/*!
	Get minimal radius the car can steer.
	\return Minimal Radius
	*/
	const double getMinRadius() const;

	double static convertRadiusToSteeringWheelAngle(double radius);
	double static convertSteeringWheelAngleToRadius(double steeringWheelAngle);
};

#endif