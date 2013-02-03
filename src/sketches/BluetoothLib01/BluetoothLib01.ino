#include <Wire.h>   //Software Serial Port
 

class Bluetooth{
public:
	enum CommandID{
                ci_test = 0
		ci_setName = 1,
		ci_getVersion = 2,
		ci_setBaud = 3,
		ci_test = 4,
	};
	class Command{
	public:
		const char*cmd;
		const uint8_t count;

		Command(const char*cmd,uint8_t count)
		:cmd(cmd),count(count){
		}
	};

	const static Command commandDesc[];
	Stream&stream;

	Bluetooth(Stream&stream)
	:stream(stream)
	{
	}

	/*!
	\param command The command which should be send.
	\param params The parameters which have to be send in the form: "<value>\0...\0<value>\0". They have to be as much pararmeters as required!
	\return The return string
	*/
	String sendCommand(CommandID command, const char*params){//params
		if(stream.available())
			return 0;
                if(command == ci_setBaud && params[0] != '4')
                        return 0;

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
		stream.setTimeout(2000);
		return stream.readString();
	}
};
const Bluetooth::Command Bluetooth::commandDesc[] = {
		/*!
		return: OK
		*/
		Bluetooth::Command("AT\0"), 
		/*!
		param: <name>
		return: OK
		*/
		Bluetooth::Command("AT+NAME\0\0",1), 
		/*! 
		return: OK<Version>   e.a.: OKlinvorV1.6
		*/
		Bluetooth::Command("AT+VERSION\0",0),
		/*!
		Baud Rate Codes
		1 =   1200
		2 =   2400
		3 =   4800
		4 =   9600
		5 =  19200
		6 =  38400
		7 =  57600
		8 = 115200
		9 = 230400
		A = 460800
		param: <baud rate code>
		return: OK<Baudrate>
		*/
		Bluetooth::Command("AT+BAUD\0\0",1),
		/*!
		*/
		Bluetooth::Command("AT+BAUD4\0",0),
	};	
 

SoftwareSerial ss(pinRxD,pinTxD);
Bluetooth bt(ss);
void setup() 
{ 
} 
 
void loop(){
}
	/*
void loop() { 
	char recvChar;
	while(1){
	// A1 used as to sense bluetooth  status: low-disconnected, high-connected.
	if(digitalRead(A1)==HIGH){
		digitalWrite(pinStatus, HIGH);
	}else{
		digitalWrite(pinStatus, LOW);
	}
	if(ser.available()){//check if there's any data sent from the remote bluetooth shield
		recvChar = ser.read();
		Serial.print(recvChar);
	}
	if(Serial.available()){//check if there's any data sent from the local serial terminal, you can add the other applications here
		recvChar  = Serial.read();
		ser.print(recvChar);
	}
	}
} 

void readAll(){
	char recvChar;
	if(ser.available()){
		recvChar  = ser.read();
		Serial.print(recvChar);
	}
}
 
void setupConnection(){
	ser.begin(9600);
	ser.flush();
}

void testModul(){
	ser.print("AT+Reset");
	delay(2000);
	readAll();
}

void reset(){
	ser.print("AT+Reset");
	delay(2000); 
	readAll();
}

void getDeviceName(){
	ser.print("AT+VERSION");
	delay(2000); 
	readAll();
}

void setDeviceName(const char name[]){
	ser.print("AT+NAME");
	ser.print(name);
	delay(2000);
	readAll();
}
*/
