#include <SoftwareSerial.h>   //Software Serial Port

const uint8_t pinRxD = 6;
const uint8_t pinTxD = 7;
const uint8_t pinStatus = 13; // indicate the bluetooth  status.
 

class Bluetooth{
public:
	enum CommandID{
		ci_setName = 0,
		ci_getVersion = 1,
		ci_setBaud = 2,
		ci_test = 3,
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
		//new SoftwareSerial(pinRxD,pinTxD)
	}

	/*!
	\param command The command which should be send.
	\param params The parameters which have to be send in the form: "<value>\0...<value>\0". It have to be as much pararmeters as required!
	\return The return string
	*/
	String sendCommand(CommandID command, const char*params){//params
		if(stream.available())
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
	/*
	Serial.begin(9600);
	ss.begin(9600);
	Serial.println(bt.sendCommand(bt.ci_getVersion,""));
	ss.end();
	Serial.println("messung");
	
	uint32_t clock = 189390;
	ss.begin(clock);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock / 2);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock / 4);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock / 8);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock * 2);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock * 4);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");

	ss.begin(clock * 8);
	ss.print("AT+BAUD4");
	delay(2000);
	ss.end();
	Serial.println("end");
	*/
	Serial.begin(9600);
	pinMode(pinRxD, INPUT);
	pinMode(pinTxD, OUTPUT);
	pinMode(pinStatus, OUTPUT);
	bool thstat = LOW;
	bool tstat = LOW;
	bool rstat = HIGH;
	uint32_t tcount = 0;
	uint32_t rcount = 0; 
	Serial.println("begin");
	uint32_t time = millis();
	while(true){
		//digitalWrite(pinStatus,digitalRead(A1) == 0 ? LOW : HIGH);
		if(time + 2000 < millis())
			break;
		bool tnew = digitalRead(pinTxD);
		bool rnew = digitalRead(pinRxD);
		if(tnew != tstat){
			tnew = tstat;
			tcount++;
		}
		if(rnew != rstat){
			rnew = rstat;
			rcount++;
		}
	}
	ss.begin(tcount);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.println(tcount);
	Serial.println(rcount);
	Serial.println("ende");
	Serial.end();
	return;
	/*
	Serial.begin(9600);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(19200);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(38400);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(57600);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(115200);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(230400);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(460800);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	Serial.begin(921600);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.end();
	return;
	*/

	Serial.begin(9600);
	pinMode(pinRxD, INPUT);
	pinMode(pinTxD, OUTPUT);
	pinMode(pinStatus, OUTPUT);
	
#if true
	ss.begin(9600);
	//ss.write("AT+BAUD4");
	ss.println("abcdefghijklmnoprstuvwxyz");
	Serial.println("end");
	delay(2000);
	return;
#else
	ss.begin(88800);
	ss.write("AT+BAUD4");
	delay(2000);
	Serial.println("end");
	return;
#endif

	//Serial.println(bt.sendCommand(bt.ci_getVersion,""));
	//Serial.println(bt.sendCommand(bt.ci_setName,"Fredi"));
	Serial.println(bt.sendCommand(bt.ci_test,""));
	Serial.println("end");

	/*
	setupConnection();
	//testModul();
	//reset();
	getDeviceName();
	//setDeviceName("AndreasGruber");
	*/
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
