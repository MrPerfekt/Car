/*!
Copyright 2012 Andreas Gruber
*/

#ifndef CAR
#define CAR


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
class RemoteServer;
class ServoProxy;
class SteeringManager;
class VoltageDivider;
class WheelSensor;
class SonicDistanceSensor;
class EnvironmentKnowledgeBase;

class Car {
private:
	BluetoothModul* bluetoothModul;
	DisplayProxy* displayProxy;
	DisplayServer* displayServer;
	EnvironmentKnowledgeBase* environmentKnowledgeBase;
	MotionLogger* motionLogger;
	Motor* motorPowerEngine;
	MouseSensorPan101* mouseSensor;
	MovementSensor* movementSensor;
	PathExecutor* pathExecutor;
	PathPlaner* pathPlaner;
	PositionCalculator* positionCalculator;
	RemoteServer* remoteServer;
	ServoProxy* servoProxy;
	SonicDistanceSensor* sonicDistanceSensors[3];//Config::getSonicSensorCnt()];
	SteeringManager* steeringManager;
	Stream* mainDataStreem;
	VoltageDivider* powerSupplyVoltageDivider;
	WheelSensor* wheelSensor;
public: 
	BluetoothModul& getBluetoothModul();
	DisplayProxy& getDisplayProxy();
	DisplayServer& getDisplayServer();
	EnvironmentKnowledgeBase& getEnvironmentKnowledgeBase();
	MotionLogger& getMotionLogger();
	Motor& getMotorPowerEngine();
	MouseSensorPan101& getMouseSensor();
	MovementSensor& getMovementSensor();
	PathExecutor& getPathExecutor();
	PathPlaner& getPathPlaner();
	PositionCalculator& getPositionCalculator();
	RemoteServer& getRemoteServer();
	ServoProxy& getServoProxy();
	SonicDistanceSensor** getSonicDistanceSensors();
	SteeringManager& getSteeringManager();
	Stream& getMainDataStreem();
	VoltageDivider& getPowerSupplyVoltageDivider();
	WheelSensor& getWheelSensor();

	Car();

	/*!
	It is recomendet to invoke this method in a loop because it handle the full activity of the car.
	*/
	void update();
};
#endif