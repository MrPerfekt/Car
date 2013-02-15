/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR

#include "Vehicle.h"

class BluetoothModul;
class DisplayProxy;
class DisplayServer;
class MotionLogger;
class Motor;
class MouseSensorPan101;
class MovementSensor;
class PathExecutor;
class PathPlaner;
class PositionCalculator;
class PowerRegulator;
class RemoteServer;
class ServoProxy;
class SteeringManager;
class SteeringRegulator;
class Stream;
class VoltageDivider;
class WheelSensor;
class SonicDistanceSensor;
class EnvironmentKnowledgeBase;

class Car : public Vehicle{
private:
	WheelSensor* wheelSensor;
protected:
public:
	WheelSensor& getWheelSensor();

	void init();
	
	/*!
	Do not call this constructor!
	Call Vehicle::getInstance() instead;
	*/
	Car();
};
#endif