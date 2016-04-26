#if defined(ACTUATOR)
void condition(String message){
  const char* stateMessage=parseJson(message, "state");
  Serial.print("Received State: ");
  Serial.println(stateMessage);
  
  if (strcmp(stateMessage, "high") == 0){               //0 means that they are equal
    setRedHigh();
    setGreenLow();  
    setBlueLow();
  }
  if (strcmp(stateMessage, "low") == 0){                //0 means that they are equal
    setRedLow();
    setGreenLow();
    setBlueHigh();
  }
  if (strcmp(stateMessage, "normal") == 0){                //0 means that they are equal
    setRedLow();
    setGreenHigh();
    setBlueLow();
  }
}
#endif




