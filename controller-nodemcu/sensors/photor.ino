//GPIO******************** 
int pinlds = A0;
//********************GPIO 

//photorvalue******************** 
int photorvalue;
//********************photorvalue

//setup========================
void setup_photor(){
  
}
//========================setup

//loop========================
void loop_photor(){
  photorvalue = analogRead(pinPhotor);

  //======================
  // testdata ============
  if (isTest == 1) {
    if (photorvalue == 0){ photorvalue = random(0,1023);}
  }
  // testdata ============
  //======================


  //Json data generation ============================
  StaticJsonDocument<200> doc;
  JsonObject root = doc.to<JsonObject>();

  root["measuredt"] = "";       
  root["controller"] = controllerid;        
  root["sensor"] = "PHOTOR";
  root["uptime"] = millis();
  root["light"] = photorvalue;
  root["ip"] = myIP.toString();
  
  serializeJson(root, jsonResult);
  serializeJson(root, Serial);
  Serial.println("");
  //============================Json data generation
    
  //Serial.println(photorvalue);
}
//========================loop


