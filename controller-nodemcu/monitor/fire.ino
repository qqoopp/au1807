void setup_Fire(){
  Wire.begin();
}

void loop_Fire(){
  int a = analogRead(A0);

  StaticJsonDocument<200> doc;
  JsonObject root = doc.to<JsonObject>();
  root["measuredt"] = "";
  root["controller"] = "nodemcu";
  root["sensor"] = "FIRE";
  root["Fire"] = a;
  root["ip"] = myIP.toString();

  serializeJson(root, jsonResult);
  serializeJson(root, Serial);
  Serial.println("");

  printvals += "Fire : " + String(a) + " \n"; 
}
