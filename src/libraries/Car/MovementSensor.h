/*!
Copyright 2013 Andreas Gruber
*/

#ifndef MOVEMENT_SENSOR
#define MOVEMENT_SENSOR

#include "Sensor.h"
#include "Movement.h"

/*!
This sensor-class is the interface of all sensors which can meassure a movement.
*/
class MovementSensor : public Sensor {
public:
	/*!
	This method will return the movement since the last execution of this method.
	But it will return the same instance as the last execution but it will update the data.
	@return The movement
	*/
	virtual Movement& getMovement() = 0;
	/*!
	This method will update the sensor and cache the result in a variable until getMovement() is executed
	*/
	virtual void update() = 0;
};

#endif