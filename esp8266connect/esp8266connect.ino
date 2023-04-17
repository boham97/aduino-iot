#include <Arduino.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>


SoftwareSerial esp(2,3);

String SSID = "dlink-6A94";
String PASSWORD = "xhfuq65281";

void setup(){
  Serial.begin(9600);
  esp.begin(9600);
  esp.setTimeout(5000);

  esp.println("AT+CWMODE=1");
  // AT+CWJAP="dlink-6A94","xhfuq65281"

  
}

void loop(){
  if(Serial.available()){
    esp.write(Serial.read());
  }
    if(esp.available()){
    Serial.write(esp.read());
  }
}
