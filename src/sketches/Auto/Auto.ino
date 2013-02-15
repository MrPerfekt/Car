/*!
Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include "Vehicle.h"
#include "DisplayServer.h"
#include "gLCD.h"
#include "Servo.h"
#include "ServoProxy.h"

Vehicle &vehicle = Vehicle::getInstance();


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
}

void loop(){
	vehicle.update();
}