/*!
Copyright 2012 Andreas Gruber
*/

#include "Car.h"
#include "RemoteServer.h"
#include "BluetoothModul.h"
#include "StraightMovement.h"
#include "TurnMovement.h"

RemoteServer::RemoteServer(Car& car)
:car(car)
,stream(car.getMainDataStreem()){
//,bufferSize(__bufferSize){
}
RemoteServer::~RemoteServer(){
}
void RemoteServer::update(){
	if(stream.available()){
		uint8_t cnt = stream.readBytesUntil('\n',(char*)buffer,bufferSize);
		Serial.write((uint8_t*)buffer,cnt);

		if(buffer[0] == 'S'/*!STOP*/){
			car.getSteeringManager().stop();
		}
		if(buffer[0] == 'D'/*DRIVE*/){
			Movement *m;
			if(buffer[1] == 'S')
				StraightMovement(1000).invokeOnSteeringManager(car.getSteeringManager());
			else
			{
				TurnMovement tm = TurnMovement();
				tm.setAngleRadius(
					2*PI * (buffer[2] == 'L' ? 1 : -1),
					500 * (buffer[1] == 'F' ? 1 : -1)
					);
				tm.invokeOnSteeringManager(car.getSteeringManager());
			}
		}
	}
}