/*!
Copyright 2012 Andreas Gruber
*/

#include "Arduino.h"
#include "Car.h"
#include "ExecutableStraightMovement.h"
#include "ExecutableTurnMovement.h"
#include "RemoteServer.h"
#include "BluetoothModul.h"
#include "StraightMovement.h"
#include "TurnMovement.h"
#include "PathPlaner.h"
#include "OrientationCoordinates.h"
#include "EnvironmentKnowledgeBase.h"

RemoteServer::RemoteServer(Vehicle& vehicle)
:vehicle(vehicle){
	vehicle.getEnvironmentKnowledgeBase().addObserver(this);
}
RemoteServer::~RemoteServer(){
}
void RemoteServer::update(){
	Stream &s = vehicle.getMainDataStreem();
	const OrientationCoordinates &pos = vehicle.getPositionCalculator().getCurrentPosition();
	if(lastPosition != pos){
		s.print("P");
		s.print(pos.getX());
		s.print("/");
		s.print(pos.getY());
		s.print("/");
		s.print(pos.getAngle());
		s.print(";");
	}
	
	
	while(s.available()){
		uint8_t cnt = s.readBytesUntil('\n',(char*)buffer,bufferSize-1);
		buffer[cnt] = '\0';
		Serial.write((uint8_t*)buffer,cnt);
		Serial.println();

		switch(buffer[0]){
		case 'S':{//! STOP
			vehicle.getPathPlaner().moveTo(NULL);
			vehicle.getPathExecutor().setPath(NULL);
			vehicle.getSteeringManager().stop();
			break;}

		case 'D':{//! DRIVE
			int8_t steeringSign = (buffer[2] == 'L' ? 1 : -1);
			int8_t powerSign = (buffer[1] == 'F' ? 1 : -1);
			Movement *m;
			if(buffer[2] == 'S'){
				ExecutableStraightMovement sm = ExecutableStraightMovement();
				sm.setDistance(1000 * powerSign);
				sm.execute();
			}
			else
			{
				ExecutableTurnMovement tm = ExecutableTurnMovement();
				tm.setAngleRadius(
					2*PI * powerSign,
					100 * steeringSign
					);
				tm.execute();
			}
			break;}
		case 'T':{ //! Target
			char* pos0 = buffer+1;
			char* pos1 = strchr(pos0+1,'/')+1;
			char* pos2 = strchr(pos1+1,'/')+1;
			char* c;
			while((c = strchr(buffer, ',')) != NULL)
				*c = '.';
			static OrientationCoordinates* pos = new OrientationCoordinates();
			pos->set(atof(pos0),atof(pos1),atof(pos2));
			vehicle.getPathPlaner().moveTo(*pos);
			break;}
		case 'R':{ //! Reset
			pinMode(Config::getResetTriggerPin(),OUTPUT);
			digitalWrite(Config::getResetTriggerPin(), LOW);
			break;}
		}
	}
}

void RemoteServer::getNotified(){
	Stream &s = vehicle.getMainDataStreem();
	s.print("O");
	s.print(vehicle.getEnvironmentKnowledgeBase().getLastObject().getX());
	s.print("/");
	s.print(vehicle.getEnvironmentKnowledgeBase().getLastObject().getY());
	s.print(";");
	return;
}