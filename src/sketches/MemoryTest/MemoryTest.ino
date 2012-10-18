/*
* Copyright 2012 Andreas Gruber
*/

//constants
const byte dummy = 0;

uint16_t freeSRam () {
  extern uint16_t __heap_start, *__brkval; 
  uint16_t v; 
  return (uint16_t) &v - (__brkval == 0 ? (uint16_t) &__heap_start : (uint16_t) __brkval); 
}

uint16_t errors = 0,
	i,
	dataSize;
uint8_t *data;
const uint8_t sampleData = 255;
const uint16_t startPoint = 0;

void setup(){
	Serial.begin(9600);
	Serial.print("Memory: ");
	Serial.println(freeSRam());
	dataSize = freeSRam()-50;
	data = (uint8_t*)malloc(dataSize);
	for(i = 0; i < dataSize; i++)
		data[i] = sampleData;
	for(i = 0; i < dataSize; i++){
		if(data[i] != sampleData) {
			errors++;
			Serial.print("A: ");
			Serial.print((uint16_t)(data+i));
			Serial.print(" D: ");
			Serial.print(data[i]);
			Serial.print("   E: ");
			Serial.println(errors);
		}
		else
			//Serial.println(".");
			Serial.println((uint16_t)(data+i));
 	}
}

void loop(){

}