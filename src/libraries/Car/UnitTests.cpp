/*!
Copyright 2013 Andreas Gruber
*/

#include "UnitTests.h"

#include "vehicle.h"
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

UnitTests::UnitTests(Vehicle& vehicle)
	:vehicle(vehicle){
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
	}else
		Serial.println("OK");
}






void UnitTests::pathExecutionTest(){
	Path*p = new Path();
	StraightMovement *sm = new StraightMovement();
	ExecutableStraightMovement *esm = new ExecutableStraightMovement(*sm,vehicle.getPositionCalculator(),vehicle.getPowerRegulator(),vehicle.getSteeringRegulator());
	sm->setDistance(1000);
	p->addMovement(esm);
	TurnMovement *t0 = new TurnMovement();
	ExecutableTurnMovement* et0 = new ExecutableTurnMovement(*t0,vehicle.getPositionCalculator(),vehicle.getPowerRegulator(),vehicle.getSteeringRegulator());
	t0->setAngleRadius(circle,500);
	p->addMovement(et0);
	TurnMovement *t1 = new TurnMovement();
	ExecutableTurnMovement* et1 = new ExecutableTurnMovement(*t1,vehicle.getPositionCalculator(),vehicle.getPowerRegulator(),vehicle.getSteeringRegulator());
	t1->setAngleRadius(circle,-500);
	p->addMovement(et1);
	p->executeAndDelete();
	do{
		vehicle.update();
	}while(!p->hasFinished());
}
void UnitTests::straightMovementExecutionTest(){
	StraightMovement *m = new StraightMovement();
	ExecutableStraightMovement* em = new ExecutableStraightMovement(*m,vehicle.getPositionCalculator(),vehicle.getPowerRegulator(),vehicle.getSteeringRegulator());
	m->setDistance(200);
	em->execute();
	vehicle.getPowerRegulator().setSpeed(255);
	vehicle.getPowerRegulator().turnOnOff(true);
	do{
		vehicle.update();
	}while(!em->hasFinished());
	Serial.println("end");
	vehicle.getPowerRegulator().turnOnOff(false);
	delete m;
}
void UnitTests::turnMovementExecutionTest(){
	TurnMovement *m = new TurnMovement();
	ExecutableTurnMovement* em = new ExecutableTurnMovement(*m,vehicle.getPositionCalculator(),vehicle.getPowerRegulator(),vehicle.getSteeringRegulator());
	m->setAngleRadius(PI*2,500);
	em->execute();
	do{
		vehicle.update();
	}while(!em->hasFinished());
	delete m;
}
void UnitTests::steeringPowerRegulatorTest(){
	vehicle.getPowerRegulator().turnOnOff(true);
	steeringRegulatorTest();
	vehicle.getPowerRegulator().turnOnOff(false);
}
void UnitTests::steeringRegulatorTest(){
	const uint16_t stepDuration = 1000;
	vehicle.getSteeringRegulator().setRadius(vehicle.getSteeringRegulator().getMinRadius());
	delay(stepDuration);
	vehicle.getSteeringRegulator().setRadius(0);
	delay(stepDuration);
	vehicle.getSteeringRegulator().setRadius(-vehicle.getSteeringRegulator().getMinRadius());
	delay(stepDuration);
	vehicle.getSteeringRegulator().setRadius(0);
}
void UnitTests::powerRegulatorTest(){
	const uint16_t stepDuration = 1000;
	vehicle.getPowerRegulator().turnOnOff(true);
	delay(stepDuration);
	vehicle.getPowerRegulator().turnOnOff(false);
	delay(stepDuration);
	vehicle.getPowerRegulator().setSpeed(200);
	vehicle.getPowerRegulator().turnOnOff(true);
	delay(stepDuration);
	vehicle.getPowerRegulator().setSpeed(255);
	delay(stepDuration);
	vehicle.getPowerRegulator().setSpeed(0);
	delay(stepDuration);
	vehicle.getPowerRegulator().turnOnOff(false);
	vehicle.getPowerRegulator().setSpeed(255);
}
void UnitTests::regressionTest(){
	PartialRegression* partReg = new PartialRegression(1);
	partReg->addPoint(Vector(2,2));
	partReg->calculate(1);
	assertEqual(partReg->calculateY(1),2);
}








/*
void UnitTests::pathPlanerTest(){
	const int n = 4;
	OrientationCoordinates pos[n];
	pos[0] = OrientationCoordinates(0,1200,0);
	pos[1] = OrientationCoordinates(0,0,PI);
	pos[2] = OrientationCoordinates(0,1200,PI);
	pos[3] = OrientationCoordinates(0,0,0);
	
	for(int i = 0; i < n; i++){
		vehicle.getPathPlaner().moveTo(pos[i]);
		do{
			vehicle.update();
		}while(!vehicle.getSteeringManager().hasFinished());
	}
	vehicle.getSteeringManager().stop();
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
	vehicle.getPathExecutor().setPath(p);
	do{
		vehicle.update();
	}while(vehicle.getSteeringManager().hasFinished());
	vehicle.getSteeringManager().stop();
	vehicle.getPathExecutor().setPath(NULL);
	delete(p);
}
void UnitTests::driveTest(){
	vehicle.getSteeringManager().driveStraight(500);
	do{
		vehicle.update();
	}while(!vehicle.getSteeringManager().hasFinished());
	
	vehicle.getSteeringManager().driveTurn(500,PI*2);
	do{
		vehicle.update();
	}while(!vehicle.getSteeringManager().hasFinished());
	
	vehicle.getSteeringManager().driveTurn(-500,PI*2);
	do{
		vehicle.update();
	}while(!vehicle.getSteeringManager().hasFinished());
	vehicle.getSteeringManager().stop();
}
*/