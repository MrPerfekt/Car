/*
* Copyright 2012 Andreas Gruber
*/

#include <Servo.h>
#include <MouseSensorPan101BSI.h>

MouseSensorPan101*mouseSensor = new MouseSensorPan101(12,10,A1);

void outputPreferences(){
  mouseSensor->refreshStoredOperationMode();
  Serial.print("enableSleepMode: ");
  Serial.println(mouseSensor->getPreference(MouseSensorPan101::p_enableSleepMode));
  Serial.print("enableSleepMode2: ");
  Serial.println(mouseSensor->getPreference(MouseSensorPan101::p_enableSleepMode2));
  Serial.print("lowResolution: ");
  Serial.println(mouseSensor->getPreference(MouseSensorPan101::p_lowResolution));
  Serial.print("enableQuadratureOutput: ");
  Serial.println(mouseSensor->getPreference(MouseSensorPan101::p_enableQuadratureOutput));
}

void setup()
{ 
  Serial.begin(9600);
  //mouseSensor->setPowerSettings(MouseSensorPan101::ps_sleep2);
  //mouseSensor->setPowerSettings(MouseSensorPan101::ps_sleep1);
  //mouseSensor->setPowerSettings(MouseSensorPan101::ps_normal);
  outputPreferences();
  Serial.println("=======================");
  mouseSensor->setPreference(MouseSensorPan101::p_lowResolution,true);
  mouseSensor->setPreference(MouseSensorPan101::p_enableQuadratureOutput,false);
  mouseSensor->uploadStoredOperationMode();
  outputPreferences();
}

void loop()
{
  mouseSensor->checkRepairConnection();
  MouseCoordinates mc = mouseSensor->updatePosition();
  Serial.print(mc.x);
  Serial.print("  ");
  Serial.print(mc.y);
  Serial.println();
  delay(100);
}
