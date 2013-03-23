/*!
Copyright 2013 Andreas Gruber
*/

#include "BluetoothModul.h"

BluetoothModul::Command::Command(const char*cmd,const uint8_t count)
:cmd(cmd),count(count){
}

BluetoothModul::BluetoothModul(Stream &stream)
	:stream(stream){
}
BluetoothModul::~BluetoothModul(){
}
 
const BluetoothModul::Command BluetoothModul::commandDesc[] = {
	/*!
	return: OK
	*/
	BluetoothModul::Command("AT\0",0), 
	/*! 
	return: OK<Version>   e.a.: OKlinvorV1.6
	*/
	BluetoothModul::Command("AT+VERSION\0",0),
	/*!
	param: <name>
	return: OK
	*/
	BluetoothModul::Command("AT+NAME\0\0",1), 
	/*!
	Baud Rate Codes
	1 =   1200
	2 =   2400
	3 =   4800
	4 =   9600 //! Recomendet
	5 =  19200
	6 =  38400
	7 =  57600
	8 = 115200
	9 = 230400
	A = 460800
	param: <baud rate code>
	return: OK<Baudrate>
	*/
	BluetoothModul::Command("AT+BAUD\0\0",1),
	/*!
	param <pin>
	return: OKsetpin
	*/
	BluetoothModul::Command("AT+PIN\0\0",1),
};