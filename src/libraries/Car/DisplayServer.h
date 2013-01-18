/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISPLAY_SERVER
#define DISPLAY_SERVER

#include "DefineLib.h"
#include "gLCD.h"

class DisplayServer{
private:
	Car &car;
	gLCD* d;//! Display driver
public:
	DisplayServer(Car &car);
	~DisplayServer();

	void update();
};

#endif