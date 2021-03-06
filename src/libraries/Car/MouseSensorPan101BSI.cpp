/*!
Copyright 2013 Andreas Gruber
*/

#include "MouseSensorPan101BSI.h"
#include "math.h"

MouseCoordinates::MouseCoordinates()
:mov(TurnMovement()),x(0),y(0){
}
MouseCoordinates::MouseCoordinates(int32_t x,int32_t y)
:mov(TurnMovement()),x(x),y(y){
}
Movement& MouseCoordinates::getMovement(uint16_t resolution){
	mov.setAngleDistance(
		x * 25.4 * /*zoll -> mm*/ circle /*360°*/ / resolution /*res*/ / (2.0 * Config::getMouseSensorCenterDistance() * M_PI) /* u */,
		y * 25.4 / resolution//zoll -> mm
		);
	return mov;
}
MouseCoordinates MouseCoordinates::operator+= (const MouseCoordinates &coordinates){
	this->x += coordinates.x;
	this->y += coordinates.y;
}


MouseSensorPan101::MouseSensorPan101()
	:pinSCK(Config::getPinMouseSensorSCK()),pinSDA(Config::getPinMouseSensorSDA()),pinPD(Config::getPinMouseSensorPD()){
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
void MouseSensorPan101::writeByte(uint8_t data){
	pinMode(pinSDA, OUTPUT);
	for (int8_t i=7; i>=0; i--){
		digitalWrite(pinSCK,LOW);
		digitalWrite(pinSDA,(data & (1<<i)) == 0 ? LOW : HIGH); //Bit schreiben
		digitalWrite(pinSCK,HIGH); //Sensor uebernimmt auf steigender Flanke
		delayMicroseconds(3/*1*/); //Sensor Zeit lassen um Bit zu holen
	}
	pinMode(pinSDA, INPUT);
	digitalWrite(pinSDA,LOW); //HI-Z state
}
uint8_t MouseSensorPan101::readByte(){
	pinMode(pinSDA, INPUT);
	uint8_t data=0;
	delayMicroseconds(3);	//IC Zeit lassen um die Daten aus dem Register zu holen
	for (signed char i=7; i>-1; i--){
		digitalWrite(pinSCK,LOW); //IC bereitet Daten auf fallender Flanke vor !
		delayMicroseconds(1); //IC kurz Zeit lassen
		digitalWrite(pinSCK,HIGH); //Daten lesen  auf steigender Flanke		
		data |= (digitalRead(pinSDA) << i);
	}
	return data;
}
void MouseSensorPan101::writeToAddress(uint8_t adr, uint8_t data){
	adr |= 1<<7; //rl MSB muss 1 sein für Write Operation
	writeByte(adr);  
	writeByte(data);
}
uint8_t MouseSensorPan101::readFromAddress(uint8_t adr){
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
uint8_t MouseSensorPan101::readProductID(){
	return readFromAddress(r_productID);
}
uint8_t MouseSensorPan101::readOperationMode(){
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
MouseCoordinates MouseSensorPan101::getMovementMouseCoordinates(){
	MouseCoordinates coordinates;
	uint8_t ino = readFromAddress(r_motionStatus);
	//wenn 7tes bit vom Register 0x16 gesetzt ist wurde die Maus bewegt => Bewegungsdaten abfragen
	if(ino&(1<<ms_motion)){
		//read delta position
		coordinates.x = (int8_t)readFromAddress(r_deltaX);
		coordinates.y = (int8_t)readFromAddress(r_deltaY);
		//Check overflow
		if(ino&(1<<ms_dxovf))
			coordinates.x += coordinates.x < 0 ? -128 : 128;
		if(ino&(1<<ms_dyovf))
			coordinates.y += coordinates.y < 0 ? -128 : 128;
	}
	return coordinates;
}
void MouseSensorPan101::update(){
	currentMouseCoordinates += getMovementMouseCoordinates();
}
Movement& MouseSensorPan101::getMovement(){
	Movement& m = currentMouseCoordinates.getMovement(getResolution());
	currentMouseCoordinates = MouseCoordinates();
	return m;
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
uint16_t MouseSensorPan101::getResolution(){
	return getPreference(p_lowResolution) ? 400 : 800;
}