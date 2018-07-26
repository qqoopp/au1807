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
}
//========================loop




