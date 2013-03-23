/*!
Copyright 2013 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include "DisplayServer.h"
#include "gLCD.h"
#include "Servo.h"
#include "ServoProxy.h"
#include "UnitTests.h"
#include "Vehicle.h"

Vehicle &vehicle = Vehicle::getInstance();
UnitTests *ut = new UnitTests(Vehicle::getInstance());


//!==========================
//!========== code ==========
//!==========================
void setup(){
	noInterrupts();
	Serial.begin(9600);
	vehicle.init();

	Servo* servo = new Servo();
	servo->attach(Config::getPinSteeringServo());
	vehicle.getServoProxy().setSteeringServo(servo);

	vehicle.getDisplayServer().getGLCD().Init(0,2,0,1,1);

	interrupts();
	
	//ut->regressionTest();
	//ut->powerRegulatorTest();
	//ut->steeringRegulatorTest();
	//ut->steeringPowerRegulatorTest();
	ut->straightMovementExecutionTest();
	while(1);
	ut->turnMovementExecutionTest();
	ut->pathExecutionTest();
}

void loop(){
	//vehicle.update();
}