# include <SoftwareSerial.h>

SoftwareSerial Serial_wifi(2,3);

void setup(){
  Serial.begin(9600);
  Serial_wifi.begin(9600);
  Serial_wifi.setTimeout(5000);


}

void loop(){
  if(Serial.available()){
    Serial_wifi.write(Serial.read());
  }
    if(Serial_wifi.available()){
    Serial.write(Serial_wifi.read());
  }
}
