const uint8_t pinStrobe = 4;
const uint8_t pinData = 3;
const uint8_t pinClock = 2;

const uint8_t delayTime = 15;

uint8_t bout[] = {0B01010101,0B01010101};
uint8_t bcount = 2;


void setup()
{
	Serial.begin(9600);
    pinMode(pinStrobe, OUTPUT);
    pinMode(pinData, OUTPUT);
    pinMode(pinClock, OUTPUT);
}

void loop()
{
	for(uint8_t i = 0; i < bcount;i++)
		bout[i] = ~bout[i];
	shiftRegsWrite(bout,bcount);
	delay(1000);
}

void shiftRegsWrite(uint8_t* bytes,uint8_t size){
	for(uint8_t i = 0; i < size;i++)
		shiftRegWrite(bytes[i]);
    digitalWrite(pinStrobe, LOW);
    delayMicroseconds(delayTime); 
    digitalWrite(pinStrobe, HIGH);
    delayMicroseconds(delayTime); 
    digitalWrite(pinStrobe, LOW);
    delayMicroseconds(delayTime); 
}

void shiftRegWrite (uint8_t byte){
	//i must be a int, if you put a byte if crash on the uC
	for (uint8_t i = 0 ; i < 8; i++){
		Serial.println((byte & B10000000) == 0 ? LOW : HIGH);
		digitalWrite(pinData,(byte & B10000000) == 0 ? LOW : HIGH);
		byte <<= 1;
		digitalWrite(pinClock, LOW);
		delayMicroseconds(delayTime); 
		digitalWrite(pinClock, HIGH);
		delayMicroseconds(delayTime); 
	}
}