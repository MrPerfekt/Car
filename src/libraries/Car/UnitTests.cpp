/*!
Copyright 2012 Andreas Gruber
*/

#include "UnitTests.h"

#include "Car.h"
#include "DefineLib.h"
#include "ExecutableStraightMovement.h"
#include "ExecutableTurnMovement.h"
#include "Servo.h"
#include "ServoProxy.h"
#include "OrientationCoordinates.h"
#include "PartialRegression.h"
#include "Path.h"
#include "PathExecutor.h"
#include "PathPlaner.h"
#include "PowerRegulator.h"
#include "SteeringRegulator.h"
#include "StraightMovement.h"
#include "TurnMovement.h"

UnitTests::UnitTests(Car& car)
	:car(car){
}
UnitTests::~UnitTests(){
}

bool UnitTests::assert(bool b){
	if(!b)
		Serial.println("Failed");
	return b;
}
bool UnitTests::assertEqual(double a, double b){
	if(!assert(fabs(a - b) < 0.0001)){
		Serial.print("   ");
		Serial.print(a);
		Serial.print(" != ");
		Serial.println(b);
	}
}





void UnitTests::straightMovementExecutionTest(){
	ExecutableStraightMovement* m = new ExecutableStraightMovement();
	m->setDistance(1000);
	m->execute();
	delete m;
}
void UnitTests::turnMovementExecutionTest(){
	ExecutableTurnMovement* m = new ExecutableTurnMovement();
	m->setAngleRadius(PI*2,500);
	m->execute();
	delete m;
}
void UnitTests::pathExecutionTest(){
	Path*p = new Path();
	ExecutableStraightMovement *sm = new ExecutableStraightMovement();
	sm->setDistance(1000);
	p->addMovement(sm);
	ExecutableTurnMovement* t;
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,500);
	p->addMovement(t);
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,-500);
	p->addMovement(t);
	p->executeAndDelete();
	do{
		car.update();
	}while(p->hasFinished());
}
void UnitTests::steeringPowerRegulatorTest(){
	car.getPowerRegulator().turnOnOff(true);
	steeringRegulatorTest();
	car.getPowerRegulator().turnOnOff(false);
}
void UnitTests::steeringRegulatorTest(){
	car.getSteeringRegulator().setRadius(car.getSteeringRegulator().getMinRadius());
	delay(500);
	car.getSteeringRegulator().setRadius(0);
	delay(500);
	car.getSteeringRegulator().setRadius(-car.getSteeringRegulator().getMinRadius());
	delay(500);
	car.getSteeringRegulator().setRadius(0);
}
void UnitTests::powerRegulatorTest(){
	car.getPowerRegulator().turnOnOff(true);
	delay(500);
	car.getPowerRegulator().turnOnOff(false);
	delay(500);
	car.getPowerRegulator().setSpeed(150);
	car.getPowerRegulator().turnOnOff(true);
	delay(500);
	car.getPowerRegulator().setSpeed(255);
	delay(500);
	car.getPowerRegulator().setSpeed(0);
	delay(500);
	car.getPowerRegulator().turnOnOff(false);
	car.getPowerRegulator().setSpeed(255);
}
void UnitTests::regressionTest(){
	PartialRegression* partReg = new PartialRegression(1);
	partReg->addPoint(Vector(2,2));
	partReg->calculate(1);
	assertEqual(partReg->calculateY(1),2);
}









void UnitTests::pathPlanerTest(){
	const int n = 4;
	OrientationCoordinates pos[n];
	pos[0] = OrientationCoordinates(0,1200,0);
	pos[1] = OrientationCoordinates(0,0,PI);
	pos[2] = OrientationCoordinates(0,1200,PI);
	pos[3] = OrientationCoordinates(0,0,0);
	
	for(int i = 0; i < n; i++){
		car.getPathPlaner().moveTo(pos[i]);
		do{
			car.update();
		}while(!car.getSteeringManager().hasFinished());
	}
	car.getSteeringManager().stop();
}
void UnitTests::itorTest(){
	Path*p = new Path();
	ExecutableStraightMovement* m0 = new ExecutableStraightMovement();
	m0->setDistance(1000);
	p->addMovement(m0);
	ExecutableTurnMovement* t;
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,500);
	p->addMovement(t);
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,-500);
	p->addMovement(t);
	Iterator<ExecutableMovement*>* i = p->initializeIterator();
	while(i->hasNext()){
		ExecutableStraightMovement*m = (ExecutableStraightMovement*)i->getCurrent();
		int e = ((ExecutableStraightMovement*)i->getCurrent())->getDistance();
	}
}
void UnitTests::pathMemoryTest(){
	double lastFreeSRam = -1,curFreeSram;
	for(int i = 0; i < 100; i++){
		Path*p = new Path();
		ExecutableStraightMovement *sm = new ExecutableStraightMovement();
		sm->setDistance(1000);
		p->addMovement(sm);
		ExecutableTurnMovement* t;
		t = new ExecutableTurnMovement();
		t->setAngleRadius(2*PI,500);
		p->addMovement(t);
		t = new ExecutableTurnMovement();
		t->setAngleRadius(2*PI,-500);
		p->addMovement(t);
		delete(p);
		curFreeSram = freeSRam();
		if(lastFreeSRam != -1)
			assertEqual(lastFreeSRam, curFreeSram);
		lastFreeSRam = curFreeSram;
	}
}
void UnitTests::pathTest(){
	Path*p = new Path();
	ExecutableStraightMovement *sm = new ExecutableStraightMovement();
	sm->setDistance(1000);
	p->addMovement(sm);
	ExecutableTurnMovement* t;
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,500);
	p->addMovement(t);
	t = new ExecutableTurnMovement();
	t->setAngleRadius(circle,-500);
	p->addMovement(t);
	car.getPathExecutor().setPath(p);
	do{
		car.update();
	}while(car.getSteeringManager().hasFinished());
	car.getSteeringManager().stop();
	car.getPathExecutor().setPath(NULL);
	delete(p);
}
void UnitTests::driveTest(){
	car.getSteeringManager().driveStraight(500);
	do{
		car.update();
	}while(!car.getSteeringManager().hasFinished());
	
	car.getSteeringManager().driveTurn(500,PI*2);
	do{
		car.update();
	}while(!car.getSteeringManager().hasFinished());
	
	car.getSteeringManager().driveTurn(-500,PI*2);
	do{
		car.update();
	}while(!car.getSteeringManager().hasFinished());
	car.getSteeringManager().stop();
}