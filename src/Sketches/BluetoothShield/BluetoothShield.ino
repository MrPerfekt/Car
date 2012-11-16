#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 6
#define TxD 7
#define Status 13 // indicate the bluetooth  status.
 
SoftwareSerial ser(RxD,TxD);
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(Status, OUTPUT);
  setupConnection();
  setDeviceName("hallo");
} 
 
void loop() 
{ 
  char recvChar;
  while(1){
    // A1 used as to sense bluetooth  status: low-disconnected, high-connected.
    if(digitalRead(A1)==HIGH){
      digitalWrite(Status, HIGH);
    }else{
      digitalWrite(Status, LOW);
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
 
void setupConnection(){
  ser.begin(9600);
  Serial.println("The slave bluetooth is now inquirable!");
  ser.flush();
}

void setDeviceName(const char name[]){
  ser.print("AT+NAME");
  ser.print(name);
  delay(2000); // This delay is required.
}
