#include <SoftwareSerial.h>   //Software Serial Port
#define RxD 6
#define TxD 7
#define Status 13 // indicate the bluetooth  status.
 
SoftwareSerial blueToothSerial(RxD,TxD);
 
void setup() 
{ 
  Serial.begin(9600);
  pinMode(RxD, INPUT);
  pinMode(TxD, OUTPUT);
  pinMode(Status, OUTPUT);
  setupBlueToothConnection();
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
    if(blueToothSerial.available()){//check if there's any data sent from the remote bluetooth shield
      recvChar = blueToothSerial.read();
      Serial.print(recvChar);
    }
    if(Serial.available()){//check if there's any data sent from the local serial terminal, you can add the other applications here
      recvChar  = Serial.read();
      blueToothSerial.print(recvChar);
    }
  }
} 
 
void setupBlueToothConnection(){
  blueToothSerial.begin(9600); //Set BluetoothBee BaudRate to default baud rate 9600
  
  //Serial.println(blueToothSerial.read());
  Serial.println("The slave bluetooth name is 'AndreasGruber', now is inquirable!");
  blueToothSerial.flush();
}

void setDeviceName(){
  blueToothSerial.print("AT+NAMEAndreasGruber"); //set the bluetooth name as "SeeedBTSlave"
  delay(2000); // This delay is required.
}
