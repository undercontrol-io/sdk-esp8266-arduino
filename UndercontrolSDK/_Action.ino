void condition(String message){
  const char* stateMessage=parseJson(message, "state");
  Serial.print("Received State: ");
  Serial.println(stateMessage);
  
  if (strcmp(stateMessage, "high") == 0){               //0 means that they are equal
    //setRelayHigh();
  }
  if (strcmp(stateMessage, "low") == 0){                //0 means that they are equal
    //setRelayLow();
  }
}


void readActionFromUndercontrol(){
  #if defined(MQTT)
    readMQTTTopic();
  #endif
  #if defined(HTTP)
    //TODO: Create HTTP Actuator
  #endif
}


