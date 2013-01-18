/*!
Copyright 2012 Andreas Gruber
*/

#include "DisplayServer.h"


DisplayServer::DisplayServer(Car& car)
:car(car){

}

DisplayServer::~DisplayServer(){
}

void DisplayServer::update(){
	int cs = -1;
	
	OrientationCoordinates position = positionCalculator.getCurrentPosition();
	String str0 = "x: ";
	str0 += (int)position.getX();

	String str1 = "y: ";
	str1 += (int)position.getY();

	String str2 = "a: ";
	str2 += (int)position.getAngle();
	str2 += ".";
	str2 += (int)(position.getAngle() * 100)%100;
  
	double suplV = voltageDivider.calculateSuplyPotential();
	String str3 = "u: ";
	str3 += (int)(suplV*1000);

	String str4 = "m: ";
	str4 += freeSRam();
	
	int i = 0;
	int y;
	int x = 20;
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str0,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str1,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str2,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str3,x,y,0B0000);
	y = 15*++i;
	graphic.Box(x,y,x+8*7,y+7,0B0000);
	graphic.Print(str4,x,y,0B0000);
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