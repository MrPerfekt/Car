/*!
Copyright 2012 Andreas Gruber
*/

#ifndef REMOTE_SERVER
#define REMOTE_SERVER

#include "DefineLib.h"
#include "Observer.h"
class Car;

class RemoteServer : public Observer{
private:
	OrientationCoordinates lastPosition;
	Car &car;
	static const uint8_t bufferSize = 50;
	char/*uint8_t*/ buffer[bufferSize];
public:
	RemoteServer(Car& car);
	~RemoteServer();
	void update();
	void getNotified();
};
#endif