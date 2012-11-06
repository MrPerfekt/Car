/*
* Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

#include <gLCD.h>
#include <Servo.h>
#include <Car.h>
/*
#include <WheelSensors.h>
#include <VoltageDivider.h>
#include <SteeringManager.h>
#include <ServoProxy.h>
#include <Sensor.h>
#include <PositionCalculator.h>
#include <MovementSensor.h>
#include <Movement.h>
#include <MouseSensorPan101BSI.h>
#include <MotorTB6612FNG.h>
#include <MotionLogger.h>
#include <DisplayProxy.h>
#include <DefineLib.h>
#include <Coordinates.h>
#include <Car.h>
#include <BumperSensor.h>
*/

Car*car = new Car();
ServoProxy servop = car->getServoProxy();
Motor& motor = car->getMotorPowerEngine();
WheelSensor& wheelSensor = car->getWheelSensor();
VoltageDivider& voltageDivider = car->getPowerSupplyVoltageDivider();
PositionCalculator& positionCalculator = car->getPositionCalculator();
SteeringManager& steeringManager = car->getSteeringManager();

//========== DISPLAY ==========

const char RST = 8;
const char CS = 9;
const char Clk = 13;
const char Data = 11;

gLCD graphic(RST,CS,Clk,Data,1);

void setupDisplay(){
	graphic.Init(0,2,0,1,1);
	graphic.Contrast(0x2B);//Range: -0x3F to 0x3F
	graphic.SetBackColour(15,15,15);
	graphic.SetForeColour(0,0,15); 
  
	graphic.Box(10,10,109,109,0B0100);
}

void updateDisplay(){  
	int32_t distance = positionCalculator.distance;
	String strD = "d: ";
	strD += distance;

	double angle = positionCalculator.angle;
	if(angle < 0) angle *= -1;
	String strR = "r: ";
	strR += (int)angle;
	strR += ".";
	strR += (int)(angle * 100)%100;
  
	uint16_t suplV = voltageDivider.calculateSuplyPotential();
	String strU = "u: ";
	strU += suplV;
  
	uint16_t cSpeed = wheelSensor.calculateCurrentSpeed();
	String strV = "v: ";
	strV += cSpeed;
  
	graphic.Box(20,20,20+8*7,20+7,0B0000);
	graphic.Print(strD,20,20,0);
	graphic.Box(20,40,20+8*7,40+9,0B0000);
	graphic.Print(strR,20,40,0);
	graphic.Box(20,60,20+8*7,60+7,0B0000);
	graphic.Print(strU,20,60,0);
	graphic.Box(20,80,20+8*7,80+7,0B0000);
	graphic.Print(strV,20,80,0);
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
	servo->attach(7);
	servop.setSteeringServo(servo);
	interrupts();

	Serial.print("Free SRam: ");
	Serial.println(freeSRam());
	driveTest();
}

void loop(){
	delay(100);
	updateDisplay();

#if false
	int val0 = analogRead(0);
	int val1 = analogRead(1);
  
	Serial.print(val0);
	Serial.print("  ");
	Serial.print(val1);
	Serial.print("  ");
	Serial.print(rotationCount[WL]);
	Serial.print(" - ");
	Serial.println(rotationCount[WR]);
	//delay(10);
#endif
}

#if true
void driveTest(){
  updateDisplay();
  
  Serial.println("drive");
  steeringManager.driveStraight(1000);
  int i = 0;
  while(!steeringManager.update()){
	  i++;
	  if(i == 1){
		  updateDisplay();
		  i = 0;
	  }
  }
  Serial.println("turn");
  steeringManager.driveTurn(500,circle);
  while(!steeringManager.update()){
	  i++;
	  if(i == 1){
		  updateDisplay();
		  i = 0;
	  }
  }
  Serial.println("turn");
  steeringManager.driveTurn(-500,circle);
  while(!steeringManager.update()){
	  i++;
	  if(i == 1){
		  updateDisplay();
		  i = 0;
	  }
  }
  Serial.println("end");
  steeringManager.update();
}
#elif
void driveTurn(int angle){
  
  int startAngle = wheelSensor.calculateAngleMilli();
  int currentAngle;
  do{
    currentAngle = wheelSensor.calculateAngleMilli() - startAngle;
    if(currentAngle < 0) currentAngle *= -1;
    updateDisplay();
  }while(currentAngle < angle);
}
void driveStraight(unsigned long distance){
  //distance: in nanometer
  //ahead: true=forwad false=backward
  uint32_t startDistance = wheelSensor.calculateDistance();
  uint32_t finishDistance = startDistance + distance;
  while(wheelSensor.calculateDistance() < finishDistance){
    updateDisplay();
  }
  //testSetDelay(LOW);
}
void driveTest(){
  updateDisplay();
  
  servop.setSteeringAngle(0);
  motor.motorMove(255, 0);  
  driveStraight((unsigned long)1000000);
  
  servop.setSteeringAngle(ServoProxy::recommendedAngleLeft);
  driveTurn(1000);
  
  servop.setSteeringAngle(ServoProxy::recommendedAngleRight);
  driveTurn(1000);
  motor.motorBreak();
  servop.setSteeringAngle(0);
}
#endif
