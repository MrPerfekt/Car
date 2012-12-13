/*!
Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include <gLCD.h>
#include <Servo.h>
#include <Car.h>

Car*car = new Car();
ServoProxy servop = car->getServoProxy();
Motor& motor = car->getMotorPowerEngine();
WheelSensor& wheelSensor = car->getWheelSensor();
VoltageDivider& voltageDivider = car->getPowerSupplyVoltageDivider();
PositionCalculator& positionCalculator = car->getPositionCalculator();
SteeringManager& steeringManager = car->getSteeringManager();
PathExecutor& pathExecutor = car->getPathExecutor();

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
	double distance = positionCalculator.getFullMovement().getDistance();
	String strD = "d: ";
	strD += (int)distance;

	double angle = positionCalculator.getFullMovement().getAngle();
	if(angle < 0) angle *= -1;
	String strR = "r: ";
	strR += (int)angle;
	strR += ".";
	strR += (int)(angle * 100)%100;
  
	double suplV = voltageDivider.calculateSuplyPotential();
	String strU = "u: ";
	strU += (int)(suplV*1000);
  
	double cSpeed = wheelSensor.calculateCurrentSpeed();
	String strV = "v: ";
	strV += (int)cSpeed;
  
	graphic.Box(20,20,20+8*7,20+7,0B0000);
	graphic.Print(strD,20,20,0B0000);
	graphic.Box(20,40,20+8*7,40+9,0B0000);
	graphic.Print(strR,20,40,0B0000);
	graphic.Box(20,60,20+8*7,60+7,0B0000);
	graphic.Print(strU,20,60,0B0000);
	graphic.Box(20,80,20+8*7,80+7,0B0000);
	graphic.Print(strV,20,80,0B0000);
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
	pathTest();
	//pathMemoryTest();
	//itorTest();
	TurnMovement *m = new TurnMovement();
}

void loop(){
	delay(100);
	updateDisplay();
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
		t->setAngleRadius(circle,500);
		p->addMovement(t);
		t = new TurnMovement();
		t->setAngleRadius(circle,-500);
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
  
	int i = 0;
	Serial.println("drive");
	steeringManager.driveStraight(1000);
	do{
		car->update();
		updateDisplay();
	}while(steeringManager.getState() != SteeringManager::ss_stop);
	Serial.println("turn");
	steeringManager.driveTurn(500,circle);
	do{
		car->update();
		updateDisplay();
	}while(steeringManager.getState() != SteeringManager::ss_stop);
	Serial.println("turn");
	steeringManager.driveTurn(-1000,circle/4);
	do{
		car->update();
		updateDisplay();
	}while(steeringManager.getState() != SteeringManager::ss_stop);
	Serial.println("end");
	steeringManager.stop();
}