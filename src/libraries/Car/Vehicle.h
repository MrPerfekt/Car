/*!
Copyright 2012 Andreas Gruber
*/

#ifndef VEHICLE
#define VEHICLE

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

class Vehicle {
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
	PowerRegulator* powerRegulator;
	RemoteServer* remoteServer;
	ServoProxy* servoProxy;
	SonicDistanceSensor* sonicDistanceSensors[3];//Config::getSonicSensorCnt()];
	SteeringManager* steeringManager;
	SteeringRegulator* steeringRegulator;
	Stream* mainDataStreem;
	VoltageDivider* powerSupplyVoltageDivider;
protected:
	Vehicle();

	void setMovementSensor(MovementSensor *movementSensor);
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
	PowerRegulator& getPowerRegulator();
	RemoteServer& getRemoteServer();
	ServoProxy& getServoProxy();
	SonicDistanceSensor** getSonicDistanceSensors();
	SteeringManager& getSteeringManager();
	SteeringRegulator& getSteeringRegulator();
	Stream& getMainDataStreem();
	VoltageDivider& getPowerSupplyVoltageDivider();

	static Vehicle& getInstance();
	
	/*!
	This method have to be invoked after the initialisation.
	*/
	virtual void init();
	/*!
	It is recomendet to invoke this method in a loop because it handle the full activity of the car.
	*/
	void update();
};
#endif