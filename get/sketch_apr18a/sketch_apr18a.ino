#include <SoftwareSerial.h>

//https://makejoa.tistory.com/32

#define ssid "dlink-6A94"

#define password "xhfuq65281"



SoftwareSerial espSerial(2, 3);

int cmdSize = 0;

long previousMillis = 0;



void setup(void)

{

  Serial.begin(9600);

  espSerial.begin(9600);

  connectWifi();

}

 

void loop(void)

{

  long currentMillis = millis();

  if(currentMillis - previousMillis >= 7000)

  {

    previousMillis = currentMillis;

    requestBusInfo();

  }



  if(espSerial.available())

  {

    Serial.write(espSerial.read());

  }

}



void connectWifi()

{

  espSerial.println("AT+CWMODE=1");

  while(espSerial.available()){

    Serial.write(espSerial.read());

  }

  delay(500);

  espSerial.println("AT+CIPMUX=0");

  while(espSerial.available()){

    Serial.write(espSerial.read());

  }

  delay(500);

  espSerial.print("AT+CWJAP=\"");

  espSerial.print(ssid);

  espSerial.print("\",\"");

  espSerial.print(password);

  espSerial.println("\"");

  while(espSerial.available()){

    Serial.write(espSerial.read());

  }

}



void requestBusInfo(){

  cmdSize = strlen("GET /api/74588f2cba914dc7b943/COOKRCP01/json/1/100/ HTTP/1.1")

              + strlen("Host:openapi.foodsafetykorea.go.kr\r\n\r\n") + 2;

  espSerial.println("AT+CIPSTART=\"TCP\",\"openapi.foodsafetykorea.go.kr\",80");

  delay(500);

  espSerial.print("AT+CIPSEND=");

  delay(100);

  espSerial.println(cmdSize);

  delay(100);

  espSerial.println("GET /api/74588f2cba914dc7b943/COOKRCP01/json/1/2/ HTTP/1.1");

  espSerial.println("Host:openapi.foodsafetykorea.go.kr\r\n\r\n");

} 