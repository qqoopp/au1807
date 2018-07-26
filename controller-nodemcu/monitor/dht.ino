#include <DHT.h>

//DHT******************** 
typedef enum
{
    DHTTYPE_DHT11         = DHT11, // DHT 11
    DHTTYPE_DHT22         = DHT22, // DHT 22, AM2302, AM2321
    DHTTYPE_DHT21         = DHT21 // DHT 21, AM2301
} DHTTYPE;
DHT dht(DHTPIN, DHTTYPE_DHT11);

void setup_dht(){
  dht.begin();
}

void loop_dht(){
  delay(2000);
  float t = dht.readTemperature();
  float h = dht.readHumidity();  
  
  String strtemp = String(t);
  String strhumi = String(h);

  if ( !isFloat(strtemp) ) { 
    strtemp = String(prevtemp); 
    t = prevtemp;
    strhumi = String(prevhumi); 
    h = prevhumi;
  }
  else {
    prevtemp = t;
    prevhumi = h;
  }
  
  
  //Json data generation ============================
  StaticJsonDocument<200> doc;
  JsonObject root = doc.to<JsonObject>();

  root["measuredt"] = "";       
  root["controller"] = "nodemcu";        
  root["sensor"] = "DHT";
  root["uptime"] = millis();
  root["temp"] = t;
  root["humi"] = h;
  root["ip"] = myIP.toString();
  
  serializeJson(root, jsonResult);
  serializeJson(root, Serial);
  Serial.println("");
  //============================Json data generation

  printvals += "temp : " + strtemp + " C\n" + "humi : " + strhumi + " %\n"; 
}

