/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISPLAY_SERVER
#define DISPLAY_SERVER

#include "DefineLib.h"
class gLCD;
class Vehicle;

class DisplayServer{
private:
	Vehicle &car;
	gLCD* graphic;
public:
	gLCD& getGLCD();
	DisplayServer(Vehicle &car);
	~DisplayServer();

	void update();
};

#endif