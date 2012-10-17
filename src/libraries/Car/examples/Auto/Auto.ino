//constants
const byte dummy = 0;

//#include <DefineLib.h>
#include <VoltageDivider.h>
#include <MotorTB6612FNG.h>
#include <WheelRotationSensors.h>
#include <Servo.h>
#include <gLCD.h>

//Motor
const int motorPinPMW = 5;  
const int motorPinIn1 = 6;  
const int motorPinIn2 = 4;  
Motor* motor = new Motor(motorPinPMW,motorPinIn1,motorPinIn2);

//Wheel Sensor
const int wheelPinR = 2;  
const int wheelPinL = 2;  
WheelSensor*wheelSensor = new WheelSensor(2,3);

//Supply Voltage Divider
const int svdAPin = 0;  
const unsigned long long svdR1 = 966;
const unsigned long long svdR2 = 1989;
VoltageDivider*voltageDivider = new VoltageDivider(svdAPin,svdR1,svdR2);

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
  double angle = wheelSensor->calculateAngleDeg();
  if(angle < 0) angle *= -1;
  String strR = "r: ";
  strR += (int)angle;
  strR += ".";
  strR += (int)(angle * 100)%100;
  
  ulong distance = wheelSensor->calculateDistance() / 1000;
  String strD = "d: ";
  strD += distance;
  
  uint suplV = voltageDivider->calculateSuplyPotential();
  String strU = "u: ";
  strU += suplV;
  
  uint cSpeed = wheelSensor->calculateCurrentSpeed();
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


const int servoPin = 7;
Servo servo;

//Maximum Ratings
byte posMiddle = 85;
byte posMaxLeft = 138;
byte posLeft = (posMiddle + posMaxLeft) / 2;
byte posMaxRight = 50;
byte posRight = (posMiddle + posMaxRight) / 2;

void setupServo(){
  servo.attach(servoPin);
  servo.write(posMiddle);
}


//==========================
//========== code ==========
//==========================
void setup(){
  //========== Serial Connection ==========
  noInterrupts();
  
  Serial.begin(9600);

  setupDisplay();

  setupServo();
  interrupts();
  
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

void driveTurn(int angle){
  int startAngle = wheelSensor->calculateAngleMilli();
  int currentAngle;
  do{
    currentAngle = wheelSensor->calculateAngleMilli() - startAngle;
    if(currentAngle < 0) currentAngle *= -1;
    updateDisplay();
  }while(currentAngle < angle);
}
void driveStraight(unsigned long distance){
  //distance: in millimeter
  //ahead: true=forwad false=backward
  unsigned long startDistance = wheelSensor->calculateDistance();
  unsigned long finishDistance = startDistance + distance;
  while(wheelSensor->calculateDistance() < finishDistance)
    updateDisplay();
}

void driveTest(){
  servo.write(posMiddle);
  motor->motorMove(255, 0);
  driveStraight((unsigned long)1000000);
  servo.write(posRight);
  driveTurn(1000);
  servo.write(posLeft);
  driveTurn(1000);
  motor->motorBreak();
  servo.write(posMiddle);
}
