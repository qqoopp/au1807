#include <ArduinoJson.h>

int data[3];

//arduino
int pin1 = A0;
int pin2 = 1;
int pin3 = 2;

void setup(){
  Serial.begin(9600);
}

void loop(){
  while(1){
    data[0] = random(25,30);
    data[1] = random(50,70);
    
  //Json data generation ============================
  StaticJsonDocument<200> doc;
  JsonObject root = doc.to<JsonObject>();

  root["measuredt"] = "";       
  root["controller"] = "Arduino";        
  root["sensor"] = "DHT";
  root["uptime"] = millis();
  root["temp"] = data[0];
  root["humi"] = data[1];
  root["ip"] = "serial";
  
  serializeJson(root, Serial);
  Serial.println("");
  //============================Json data generation
  /*
    Serial.print("Arduino:");
    Serial.print(data[0]);
    Serial.print(":");
    Serial.print(data[1]);
    Serial.print(":");
    Serial.print(data[2]);
    Serial.println();
  */
    delay(1000);
  }
}

