/*!
Copyright 2013 Andreas Gruber
*/

#ifndef STEERING_REGULATOR
#define STEERING_REGULATOR

class SteeringRegulator {
private:
protected:
public:
	/*!
	Set the power state of the steering device.
	\param on True if the steering have to be power-on
	*/
	virtual void turnOnOff(bool on) = 0;
	/*!
	Set the new radius which the vehicle has to steer.
	\param radius The new radius
	*/
	virtual void setRadius(double radius) = 0;
	/*!
	Get minimal radius the vehicle can steer.
	\return Minimal Radius
	*/
	virtual const double getMinRadius() const = 0;
	/*!
	Because the steering mechanism has mechanical tollerances the radius of the vehicle can be updated based on measured values.
	\param currentRadius The real radius of the car
	*/
	virtual void correcRadius(double currentRadius) = 0;
};

#endif