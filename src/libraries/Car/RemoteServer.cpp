/*!
Copyright 2012 Andreas Gruber
*/

#include "Car.h"
#include "RemoteServer.h"
#include "BluetoothModul.h"
#include "StraightMovement.h"
#include "TurnMovement.h"

RemoteServer::RemoteServer(Car& car)
:car(car){
}
RemoteServer::~RemoteServer(){
}
void RemoteServer::update(){
	static Stream &s = car.getMainDataStreem();
	if(s.available()){
		uint8_t cnt = s.readBytesUntil('\n',(char*)buffer,bufferSize);
		Serial.write((uint8_t*)buffer,cnt);
		Serial.println();

		if(buffer[0] == 'S'/*!STOP*/){
			car.getSteeringManager().stop();
		}else if(buffer[0] == 'D'/*DRIVE*/){
			int8_t steeringSign = (buffer[2] == 'L' ? 1 : -1);
			int8_t powerSign = (buffer[1] == 'F' ? 1 : -1);
			Movement *m;
			if(buffer[2] == 'S')
				StraightMovement(1000 * powerSign).invokeOnSteeringManager(car.getSteeringManager());
			else
			{
				TurnMovement tm = TurnMovement();
				tm.setAngleRadius(
					2*PI * powerSign,
					500 * steeringSign
					);
				tm.invokeOnSteeringManager(car.getSteeringManager());
			}
		}
	}
}