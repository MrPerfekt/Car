/*!
Copyright 2012 Andreas Gruber
*/

#include "Car.h"
#include "RemoteServer.h"
#include "BluetoothModul.h"
#include "StraightMovement.h"
#include "TurnMovement.h"
#include "PathPlaner.h"
#include "OrientationCoordinates.h"

RemoteServer::RemoteServer(Car& car)
:car(car){
}
RemoteServer::~RemoteServer(){
}
void RemoteServer::update(){
	static Stream &s = car.getMainDataStreem();
	while(s.available()){
		uint8_t cnt = s.readBytesUntil('\n',(char*)buffer,bufferSize-1);
		buffer[cnt] = '\0';
		Serial.write((uint8_t*)buffer,cnt);
		Serial.println();

		switch(buffer[0]){
		case 'S':{//! STOP
			car.getPathPlaner().moveTo(NULL);
			car.getPathExecutor().setPath(NULL);
			car.getSteeringManager().stop();
			break;}

		case 'D':{//! DRIVE
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
			car.getPathPlaner().moveTo(*pos);
			break;}
		case 'R':{ //! Reset
			pinMode(Config::getResetTriggerPin(),OUTPUT);
			digitalWrite(Config::getResetTriggerPin(), LOW);
			break;}
		}
	}
}