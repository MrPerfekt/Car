/*!
Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include "Car.h"
#include "DisplayServer.h"
#include "gLCD.h"
#include "Servo.h"
#include "ServoProxy.h"
#include "OrientationCoordinates.h"
#include "Path.h"
#include "PathExecutor.h"
#include "PathPlaner.h"
#include "RemoteServer.h"
#include "StraightMovement.h"
#include "TurnMovement.h"
#include "VoltageDivider.h"

Car*car = new Car();
ServoProxy servop = car->getServoProxy();
Motor& motor = car->getMotorPowerEngine();
WheelSensor& wheelSensor = car->getWheelSensor();
VoltageDivider& voltageDivider = car->getPowerSupplyVoltageDivider();
PositionCalculator& positionCalculator = car->getPositionCalculator();
SteeringManager& steeringManager = car->getSteeringManager();
PathExecutor& pathExecutor = car->getPathExecutor();
PathPlaner& pathPlaner = car->getPathPlaner();
RemoteServer& remoteServer = car->getRemoteServer();


//!==========================
//!========== code ==========
//!==========================
#if false
const int pinTestLed = 10;
int curState = 0;
void testSet(int state){
  curState = state;
  digitalWrite(pinTestLed,state);
}
void testSetDelay(int state){
  testSet(state);
  delay(1000);
}
void testToogle(){
  curState = !curState;
  testSet(curState ? LOW : HIGH); 
}
void testToogleDelay(){
  testToogle();
  delay(1000);
}
#endif

void setup(){
	noInterrupts();
	Serial.begin(9600);

	Servo* servo = new Servo();
	servo->attach(Config::getPinSteeringServo());
	servop.setSteeringServo(servo);

	interrupts();

	car->getDisplayServer().getGLCD().Init(0,2,0,1,1);
  
	//graphic->Box(10,10,109,109,0B0100);
	
	return;

	/*
	Serial.println("TEST");
	Serial2.begin(9600);
	Serial2.print("AT");
	delay(1000);
	Serial.println(Serial2.readString());
	*/

	//Serial.print("Free SRam: ");
	//Serial.println(freeSRam());

	//driveTest();
	//pathMemoryTest();
	//itorTest();
	//pathTest();
	//pathPlanerTest();
}

void loop(){
	car->update();
}

void pathPlanerTest(){
	const int n = 4;
	OrientationCoordinates pos[n];
	pos[0] = OrientationCoordinates(0,1200,0);
	pos[1] = OrientationCoordinates(0,0,PI);
	pos[2] = OrientationCoordinates(0,1200,PI);
	pos[3] = OrientationCoordinates(0,0,0);
	
	for(int i = 0; i < n; i++){
		pathPlaner.moveTo(pos[i]);
		do{
			car->update();
		}while(!steeringManager.hasFinished());
	}
	steeringManager.stop();
}

void itorTest(){
	Path*p = new Path();
	StraightMovement* m0 = new StraightMovement(1000);
	p->addMovement(m0);
	Serial.print("S  addr: ");
	Serial.println((int)m0);
	TurnMovement* t;
	t = new TurnMovement();
	Serial.print("T0  addr: ");
	Serial.println((int)t);
	t->setAngleRadius(circle,500);
	p->addMovement(t);
	t = new TurnMovement();
	Serial.print("T1  addr: ");
	Serial.println((int)t);
	t->setAngleRadius(circle,-500);
	p->addMovement(t);
	Iterator<Movement*>* i = p->initializeIterator();
	Serial.println("itor");
	while(i->hasNext()){
		StraightMovement*m = (StraightMovement*)i->getCurrent();
		int e = ((StraightMovement*)i->getCurrent())->getDistance();
		Serial.println(e);
	}
	while(1);
}

void pathMemoryTest(){
	while(1){
		Path*p = new Path();
		p->addMovement(new StraightMovement(1000));
		TurnMovement* t;
		t = new TurnMovement();
		t->setAngleRadius(2*PI,500);
		p->addMovement(t);
		t = new TurnMovement();
		t->setAngleRadius(2*PI,-500);
		p->addMovement(t);
		Serial.println("delete");
		delete(p);
		Serial.println("enddelete");
		Serial.println(freeSRam());
	}
}

void pathTest(){
	Serial.println("start");
	Path*p = new Path();
	p->addMovement(new StraightMovement(1000));
	TurnMovement* t;
	t = new TurnMovement();
	t->setAngleRadius(circle,500);
	p->addMovement(t);
	t = new TurnMovement();
	t->setAngleRadius(circle,-500);
	p->addMovement(t);
	Serial.println("setPath");
	pathExecutor.setPath(p);
	Serial.println("drive");
	do{
		car->update();
	}while(1);
	Serial.println("end");
	delete(p);
}

void driveTest(){	
	Serial.println("drive");
	steeringManager.driveStraight(500);
	do{
		car->update();
	}while(!steeringManager.hasFinished());
	Serial.println("turn");
	
	steeringManager.driveTurn(500,PI*2);
	do{
		car->update();
	}while(!steeringManager.hasFinished());
	Serial.println("turn");
	
	steeringManager.driveTurn(-500,PI*2);
	do{
		car->update();
	}while(!steeringManager.hasFinished());
	Serial.println("end");
	steeringManager.stop();
}