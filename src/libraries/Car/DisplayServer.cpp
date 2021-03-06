/*!
Copyright 2013 Andreas Gruber
*/

#include "DisplayServer.h"
#include "gLCD.h"
#include "OrientationCoordinates.h"
#include "PositionCalculator.h"
#include "Vehicle.h"
#include "VoltageDivider.h"

gLCD& DisplayServer::getGLCD(){
	return *graphic;
}

DisplayServer::DisplayServer(Vehicle& vehicle)
:car(vehicle){
	graphic = new gLCD(Config::getPinDisplayRST(),Config::getPinDisplayCS(),Config::getPinDisplayClk(),Config::getPinDisplayData(),1);//! Display driver
	
	//graphic->Contrast(0x2B);//! Range: -0x3F to 0x3F
	//graphic->SetBackColour(15,15,15);
	//graphic->SetForeColour(0,0,15); 
}

DisplayServer::~DisplayServer(){
}

void DisplayServer::update(){

	static int8_t runnr = -1;
	runnr++;
	runnr %= 5;

	static const OrientationCoordinates &position = car.getPositionCalculator().getCurrentPosition(); //! is a reference
	String str;
	switch(runnr){
	case 0:
		str = "x: ";
		str += (int)position.getX();
		break;
	case 1:
		str = "y: ";
		str += (int)position.getY();
		break;
	case 2:
		str = "a: ";
		str += (int)position.getAngle();
		str += ".";
		str += (int)(position.getAngle() * 100)%100;
		break;
	case 3:{
		double suplV = car.getPowerSupplyVoltageDivider().calculateSuplyPotential();
		str = "u: ";
		str += (int)(suplV*1000);
		break;}
	case 4:
		str = "m: ";
		str += freeSRam();
		break;
	default:
		str = "";
		break;
	}
	
	int y = 15*runnr;
	int x = 20;
	graphic->Box(x,y,x+8*7,y+7,0B0000);
	graphic->Print(str,x,y,0B0000);
}
/*
void DisplayServer::update(){
	//Serial.println(positionCalculator.getCurrentPosition().getX());
	//delay(200);
	//return;
	Serial.println("0");
	String str[8];
	int cs = -1;
	
	Serial.println("1");
	OrientationCoordinates position = positionCalculator.getCurrentPosition();
	str[++cs] = "x: ";
	str[cs] += (int)position.getX();
	Serial.println("1.5");

	str[++cs] = "y: ";
	str[cs] += (int)position.getY();
	Serial.println("2");

	str[++cs] = "a: ";
	str[cs] += (int)position.getAngle();
	str[cs] += ".";
	str[cs] += (int)(position.getAngle() * 100)%100;
	Serial.println("3");
  
	double suplV = voltageDivider.calculateSuplyPotential();
	str[++cs] = "u: ";
	str[cs] += (int)(suplV*1000);
	Serial.println("4");

	str[++cs] = "m: ";
	str[cs] += freeSRam();
  
	Serial.println("6");
	for(int i = 0; i <= cs; i++){
		Serial.println("7");
		int y = 15*(i+1);
		int x = 20;
		graphic.Box(x,y,x+8*7,y+7,0B0000);
		Serial.println(i);
		Serial.println("*");
		Serial.println(str[i]);
		graphic.Print(str[i],x,y,0B0000);
		Serial.println("*");
	}
	Serial.println("9");
}
*/