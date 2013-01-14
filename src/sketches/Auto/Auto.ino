/*!
Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include "gLCD.h"
#include "Servo.h"
#include "Car.h"
#include "StraightMovement.h"
#include "PathExecutor.h"
#include "Path.h"
#include "PathPlaner.h"
#include "OrientationCoordinates.h"

Car*car = new Car();
ServoProxy servop = car->getServoProxy();
Motor& motor = car->getMotorPowerEngine();
WheelSensor& wheelSensor = car->getWheelSensor();
VoltageDivider& voltageDivider = car->getPowerSupplyVoltageDivider();
PositionCalculator& positionCalculator = car->getPositionCalculator();
SteeringManager& steeringManager = car->getSteeringManager();
PathExecutor& pathExecutor = car->getPathExecutor();
PathPlaner& pathPlaner = car->getPathPlaner();

//========== DISPLAY ==========

const char RST = 8;
const char CS = 9;
const char Clk = 13;
const char Data = 11;

gLCD graphic(RST,CS,Clk,Data,1);

void setupDisplay(){
	graphic.Init(0,2,0,1,1);
	graphic.Contrast(0x2B);//! Range: -0x3F to 0x3F
	graphic.SetBackColour(15,15,15);
	graphic.SetForeColour(0,0,15); 
  
	graphic.Box(10,10,109,109,0B0100);
}

void updateDisplay(){
	int cs = -1;
	
	OrientationCoordinates position = positionCalculator.getCurrentPosition();
	String str0 = "x: ";
	str0 += (int)position.getX();

	String str1 = "y: ";
	str1 += (int)position.getY();

	String str2 = "a: ";
	str2 += (int)position.getAngle();
	str2 += ".";
	str2 += (int)(position.getAngle() * 100)%100;
  
	double suplV = voltageDivider.calculateSuplyPotential();
	String str3 = "u: ";
	str3 += (int)(suplV*1000);

	String str4 = "m: ";
	str4 += freeSRam();
	
	int i = 0;
	int y;
	int x = 20;
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str0,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str1,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str2,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str3,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str4,x,y,0B0000);
}
void updateDisplay0(){
	//Serial.println(positionCalculator.getCurrentPosition().getX());
	//delay(200);
	//return;
	Serial.println("0");
	String str[8];
	int cs = -1;
	
	Serial.println("1");
	OrientationCoordinates position = positionCalculator.getCurrentPosition();
	str[++cs] = "x: ";
	str[cs] += (int)position.getX();
	Serial.println("1.5");

	str[++cs] = "y: ";
	str[cs] += (int)position.getY();
	Serial.println("2");

	str[++cs] = "a: ";
	str[cs] += (int)position.getAngle();
	str[cs] += ".";
	str[cs] += (int)(position.getAngle() * 100)%100;
	Serial.println("3");
  
	double suplV = voltageDivider.calculateSuplyPotential();
	str[++cs] = "u: ";
	str[cs] += (int)(suplV*1000);
	Serial.println("4");

	str[++cs] = "m: ";
	str[cs] += freeSRam();
  
	Serial.println("6");
	for(int i = 0; i <= cs; i++){
		Serial.println("7");
		int y = 15*(i+1);
		int x = 20;
		graphic.Box(x,y,x+8*7,y+7,0B0000);
		Serial.println(i);
		Serial.println("*");
		Serial.println(str[i]);
		graphic.Print(str[i],x,y,0B0000);
		Serial.println("*");
	}
	Serial.println("9");
}



//==========================
//========== code ==========
//==========================
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
	//========== Serial Connection ==========
	//pinMode(pinTestLed, OUTPUT);
	//testSet(LOW);
  
	noInterrupts();
  
	Serial.begin(9600);

	setupDisplay();
  
	Servo* servo = new Servo();
	servo->attach(Config::getPinSteeringServo());
	servop.setSteeringServo(servo);
	interrupts();

	Serial.print("Free SRam: ");
	Serial.println(freeSRam());


	//driveTest();
	
	//pathMemoryTest();
	//itorTest();
	//pathTest();
	
	//OrientationCoordinates pos0 = OrientationCoordinates(15,1331,6.28);
	//OrientationCoordinates pos1 = OrientationCoordinates(0,0,PI);
	//Path* p = pathPlaner.calculatePath(pos0,pos1);
	pathPlanerTest();
}

void loop(){
	car->update();
	updateDisplay();
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
			updateDisplay();
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
		updateDisplay();
	}while(1);
	Serial.println("end");
	delete(p);
}

void driveTest(){
	Serial.println("start");
	updateDisplay();
	
	Serial.println("drive");
	steeringManager.driveStraight(500);
	do{
		car->update();
		updateDisplay();
	}while(!steeringManager.hasFinished());
	Serial.println("turn");
	
	steeringManager.driveTurn(500,PI*2);
	do{
		car->update();
		updateDisplay();
	}while(!steeringManager.hasFinished());
	Serial.println("turn");
	
	steeringManager.driveTurn(-500,PI*2);
	do{
		car->update();
		updateDisplay();
	}while(!steeringManager.hasFinished());
	Serial.println("end");
	steeringManager.stop();
}