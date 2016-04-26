#if defined(ACTUATOR_RGB_LED)
#define ACTUATOR
void setRedHigh(){
  digitalWrite(PIN_RED, HIGH); 
}

void setRedLow(){
  digitalWrite(PIN_RED, LOW); 
}

void setGreenHigh(){
  digitalWrite(PIN_GREEN, HIGH); 
}

void setGreenLow(){
  digitalWrite(PIN_GREEN, LOW); 
}

void setBlueHigh(){
  digitalWrite(PIN_BLUE, HIGH); 
}

void setBlueLow(){
  digitalWrite(PIN_BLUE, LOW); 
}
#endif
