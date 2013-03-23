/*!
Copyright 2013 Andreas Gruber
*/

#ifndef UNIT_TESTS
#define UNIT_TESTS

class Vehicle;

class UnitTests {
private:
	Vehicle& vehicle;
protected:
	bool assert(bool b);
	bool assertEqual(double a, double b);
public:
	UnitTests(Vehicle& vehicle);
	~UnitTests();
	
	/*!
	Creates a Path and executes the same.
	This path is:
	- straight 1000mm
	- left r: 2PI a: 500mm
	- right r: 2PI a: 500mm
	*/
	void pathExecutionTest();
	/*!
	Creates a StraightMovement with a distance of 1000mm and executes the same.
	*/
	void turnMovementExecutionTest();
	/*!
	The steeringPowerRegulatorTest has the same testcases as the steeringRegulatorText with the diference that the motor is turned on.
	*/
	void straightMovementExecutionTest();
	/*!
	Creates a TurnMovement with a angle of 2Pi and a radian of 500mm and executes the same.
	*/
	void steeringPowerRegulatorTest();
	/*!
	The steeringRegulatorTest has the takt to test the steering device.
	So first the steering device should do the the following list with a step duration of 1000 ms.
	- left
	- straight
	- right
	- straight
	*/
	void steeringRegulatorTest();
	/*!
	The powerRegulatorTest has the takt to test the motor.
	So first the motor should do the the following list with a step duration of 1000 ms.
	- on
	- off
	- slowly on
	- fast on
	- off
	*/
	void powerRegulatorTest();
	/*!
		Create a PartialRegression and calculate a simple example with 1 known point.
		- P(2,2)
		result(1): 2
	*/
	void regressionTest();

	/*
	void pathPlanerTest();
	void itorTest();
	void pathMemoryTest();
	void pathTest();
	void driveTest();
	*/
};

#endif