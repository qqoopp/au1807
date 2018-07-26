#include <DHT.h>
#include <Wire.h>
#include <ArduinoJson.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

//GPIO ============
int DHTPIN = D5;
int pinOledSCL = D1;
int pinOldeSDA = D2;
//============ GPIO

// OLED ===============
String printvals = "";
// =============== OLED

String jsonResult;

//temp ******************** 
float prevtemp = 27;
float prevhumi = 70;
//******************** temp

void setup() {
 
  Serial.begin(9600);

  pinMode(DHTPIN,OUTPUT);

  setup_dht();
  setup_Fire();
  setup_oled();
  setup_http();
}

void loop() {
  delay(2000);
  loop_dht(); delay(1000);loop_http();delay(1000);
  loop_Fire();delay(1000);loop_http();delay(1000);
  loop_oled();delay(1000);
}




//isFloat=========================
//check whether tString is numeric or not ( to filter noise data  )
//====================================
boolean isFloat(String tString) {
  String tBuf;
  boolean decPt = false;
  
  if(tString.charAt(0) == '+' || tString.charAt(0) == '-') tBuf = &tString[1];
  else tBuf = tString;  

  for(int x=0;x<tBuf.length();x++)
  {
    if(tBuf.charAt(x) == '.') {
      if(decPt) return false;
      else decPt = true;  
    }    
    else if(tBuf.charAt(x) < '0' || tBuf.charAt(x) > '9') return false;
  }
  return true;
}
//=========================isFloat
