/*
* Copyright 2012 Andreas Gruber
*/

#include<MouseSensorPan101BSI.h>

MouseCoordinates::MouseCoordinates()
:x(0),y(0){
}
MouseCoordinates::MouseCoordinates(long x,long y)
:x(x),y(y){
}
Coordinates MouseCoordinates::getCoordinates(int resolution){
	Coordinates c;
	c.x = x * 2540 / resolution;//zoll -> nm
	c.y = y * 2540 / resolution;//zoll -> nm
	return c;
}


MouseSensorPan101::MouseSensorPan101(int pinSCK,int pinSDA,int pinPD)
:pinSCK(pinSCK),pinSDA(pinSDA),pinPD(pinPD){
	pinMode(pinSCK, OUTPUT);
	pinMode(pinSDA, OUTPUT);
	pinMode(pinPD, OUTPUT);
	digitalWrite(pinSCK,HIGH);
	digitalWrite(pinSDA,HIGH);
	digitalWrite(pinPD,HIGH);
	reset();
	refreshStoredProductID();
	refreshStoredOperationMode();
}
void MouseSensorPan101::writeByte(unsigned char data){
	pinMode(pinSDA, OUTPUT);
	for (signed char i=7; i>=0; i--){
		digitalWrite(pinSCK,LOW);
		digitalWrite(pinSDA,(data & (1<<i)) == 0 ? LOW : HIGH); //Bit schreiben
		digitalWrite(pinSCK,HIGH); //Sensor uebernimmt auf steigender Flanke
		delayMicroseconds(3/*1*/); //Sensor Zeit lassen um Bit zu holen
	}
	pinMode(pinSDA, INPUT);
	digitalWrite(pinSDA,LOW); //HI-Z state
}
unsigned char MouseSensorPan101::readByte(){
	pinMode(pinSDA, INPUT);
	unsigned char data=0;
	delayMicroseconds(3);	//IC Zeit lassen um die Daten aus dem Register zu holen
	for (signed char i=7; i>-1; i--){
		digitalWrite(pinSCK,LOW); //IC bereitet Daten auf fallender Flanke vor !
		delayMicroseconds(1); //IC kurz Zeit lassen
		digitalWrite(pinSCK,HIGH); //Daten lesen  auf steigender Flanke		
		data |= (digitalRead(pinSDA) << i);
	}
	return data;
}
void MouseSensorPan101::writeToAddress(unsigned char adr, unsigned char data){
	adr |= 1<<7; //rl MSB muss 1 sein für Write Operation
	writeByte(adr);  
	writeByte(data);
}
unsigned char MouseSensorPan101::readFromAddress(unsigned char adr){
	writeByte(adr);
	return readByte();
}
void MouseSensorPan101::reset(){
	digitalWrite(pinPD,HIGH);
	delayMicroseconds(10);
	digitalWrite(pinPD,LOW);
	//uploadStoredOperationMode();
}
void MouseSensorPan101::powerDown(){
	digitalWrite(pinPD,HIGH);
}
unsigned char MouseSensorPan101::readProductID(){
	return readFromAddress(r_productID);
}
unsigned char MouseSensorPan101::readOperationMode(){
	return readFromAddress(r_operationMode);
}
void MouseSensorPan101::refreshStoredProductID(){
	productID = readProductID();
}
void MouseSensorPan101::refreshStoredOperationMode(){
	operationMode = readOperationMode();
}
void MouseSensorPan101::uploadStoredOperationMode(){
	writeToAddress(r_operationMode,operationMode);
}

bool MouseSensorPan101::isInSynk(){
	return productID = readProductID();
}
void MouseSensorPan101::checkRepairConnection(){
	if(!isInSynk())
		reset();
}
MouseCoordinates MouseSensorPan101::getMovementInMouseCoordinates(){
	MouseCoordinates curPosition;
	unsigned char ino = readFromAddress(r_motionStatus);
	//wenn 7tes bit vom Register 0x16 gesetzt ist wurde die Maus bewegt => Bewegungsdaten abfragen
	if(ino&(1<<ms_motion)){
		//read delta position
		curPosition.x = (signed char)readFromAddress(r_deltaX);
		curPosition.y = (signed char)readFromAddress(r_deltaY);
		//Check overflow
		if(ino&(1<<ms_dxovf))
			curPosition.x += curPosition.x < 0 ? -128 : 128;
		if(ino&(1<<ms_dyovf))
			curPosition.y += curPosition.y < 0 ? -128 : 128;
	}
	return curPosition;
}
Coordinates MouseSensorPan101::getMovement(){
	return getMovementInMouseCoordinates().getCoordinates(getResolution());
}
void MouseSensorPan101::setPowerSettings(PowerSettings powerSettings){
	writeToAddress(r_operationMode,operationMode | (1 << powerSettings));
}
bool MouseSensorPan101::getPreference(Preferences preference){
	return operationMode & (1 << preference);
}
void MouseSensorPan101::setPreference(Preferences preference,bool value){
	if(value)
		operationMode |= (1 << preference);
	else
		operationMode &= ~(1 << preference);
}
unsigned int MouseSensorPan101::getResolution(){
	return getPreference(p_lowResolution) ? 400 : 800;
}