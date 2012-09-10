/*
* Copyright 2012 Andreas Gruber
*/

#include "SteeringManager.h"

SteeringManager::SteeringManager(ServoSteeringDriver& servoSteeringDriver,Motor& motorPowerEngine,PositionCalculator& positionCalculator)
	:servoSteeringDriver(servoSteeringDriver),motorPowerEngine(motorPowerEngine),positionCalculator(positionCalculator)
{}
unsigned int SteeringManager::getMaxRadius(bool rightTurn){
}
void SteeringManager::setAngleOfRadius(int radius){
}
void SteeringManager::driveTurn(int radius, int angle){
}
void SteeringManager::driveTurn(unsigned int radius, unsigned int angle, bool forward, bool rightTurn){
}
void SteeringManager::driveStraight(long distance){
}
void SteeringManager::driveStraight(unsigned long distance,bool forward){
}







/*
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
*/