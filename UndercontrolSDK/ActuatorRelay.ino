#if defined(ACTUATOR_RELAY)

void setRelayHigh(){
  digitalWrite(PIN_RELAY, HIGH); 
}

void setRelayLow(){
  digitalWrite(PIN_RELAY, LOW); 
}

#endif
