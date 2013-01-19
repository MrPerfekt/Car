/*!
Copyright 2012 Andreas Gruber
*/

#ifndef DISPLAY_SERVER
#define DISPLAY_SERVER

#include "DefineLib.h"
class gLCD;
class Car;

class DisplayServer{
private:
	Car &car;
	gLCD* graphic;
public:
	DisplayServer(Car &car);
	~DisplayServer();

	void update();
};

#endif