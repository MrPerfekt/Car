/*!
Copyright 2012 Andreas Gruber
*/

#ifndef REGRESSION
#define REGRESSION

#include "DefineLib.h"

//! This library contains only settings for a bluetooth modul
class BluetoothModul{
private:
	Stream &stream;
public:
	BluetoothModul(Stream &stream);
	~BluetoothModul();

	enum CommandID{
        ci_test = 0,
		ci_getVersion = 1,
		ci_setName = 2,
		ci_setBaud = 3,
		ci_setPin = 4,
	};

	class Command{
	public:
		const char*cmd;
		const uint8_t count;

		Command(const char*cmd,const uint8_t count);
	};

	const static Command commandDesc[];

	/*!
	\param command The command which should be send.
	\param params The parameters which have to be send in the form: "<value>\0...\0<value>\0". They have to be as much pararmeters as required!
	\return The return string
	*/
	String sendCommand(const CommandID command, const char*params){//params
		if(stream.available())
			return 0;
		//! Specialcondition because this is a very dangerous setting
        if(command == ci_setBaud && params[0] != '4'){
			Serial.println("Not allowed");
			return 0;
		}

		uint8_t count = commandDesc[command].count;
		size_t pos = 0;
		size_t posParam = 0;
		for(uint8_t i = 0; ;i++){
			pos += 1 + stream.print(commandDesc[command].cmd+pos);
			if(i < count)
				posParam += 1 + stream.print(params+posParam);
			else
				break;
		}
		/*! ToDo: save in config */
		stream.setTimeout(500);
		return stream.readString();
	}
};
#endif