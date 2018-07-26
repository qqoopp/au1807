//setup========================
void setup_led(){
  pinMode(pinLED, OUTPUT); // on/off
}
//========================setup

//loop========================
void loop_led(){
  if ( getStatus("LED") == "ON"){  
    digitalWrite(pinLED, HIGH);    
  }
  else {
    digitalWrite(pinLED, LOW);    
  }

  //Json data generation ============================
  StaticJsonDocument<200> doc;
  JsonObject root = doc.to<JsonObject>();

  root["measuredt"] = "";       
  root["controller"] = controllerid;        
  root["sensor"] = "LED";
  root["uptime"] = millis();
  root["ip"] = myIP.toString();

  if ( getStatus("LED") == "ON"){  
    root["onoff"] = "ON";
  }
  else {
    root["onoff"] = "OFF";
  }
  
  serializeJson(root, jsonResult);
  serializeJson(root, Serial);
  Serial.println("");
  //============================Json data generation
  
}
//========================loop




