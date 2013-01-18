/*!
Copyright 2012 Andreas Gruber
*/

#ifndef REMOTE_SERVER
#define REMOTE_SERVER

#include "DefineLib.h"
class Car;

class RemoteServer{
private:
	Car& car;
public:
	RemoteServer(Car& car);
	~RemoteServer();

	void start();
	void update();
};
#endif