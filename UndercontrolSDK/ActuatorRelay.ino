#if defined(ACTUATOR_RELAY)
#define ACTUATOR
void setRelayHigh(){
  digitalWrite(PIN_RELAY, HIGH); 
}

void setRelayLow(){
  digitalWrite(PIN_RELAY, LOW); 
}

#endif
