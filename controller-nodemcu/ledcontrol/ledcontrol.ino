#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

String sensors[] = {"LED"};// select connected senssors from supportedsensors and write here
String sensorsstatus[] = {"ON"};// select connected senssors from supportedsensors and write here
String jsonResult;

//GPIO******************** 
int pinLED = D3;
//********************GPIO 

void setup(){
  Serial.begin(9600);
  setup_led();
  setup_http();
}

void loop(){
  loop_http();
  loop_led();
}

