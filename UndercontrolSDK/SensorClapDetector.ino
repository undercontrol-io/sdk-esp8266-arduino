#if defined(SENSOR_CLAP)

int claps = 0;
unsigned long lastClap = 0;
unsigned long now = 0;
int debounceTime = 60000;

boolean debounce(){                   // Return true if clap is detected
  if (lastClap + debounceTime < now){
    return true;
  }
  else{
    return false;
  }  
}

int getDataFromSensor()     //Get Claps
{
  now = micros();
  if (digitalRead(PIN_CLAP) == 1){
    if (debounce()){
      claps++;
      lastClap = now; 
      Serial.print(now);
      Serial.print(":Clap ");
      Serial.println(claps);
    }
  }
  if (claps > 0){
    if (lastClap + 1000000 < now){
      int auxClaps = claps;
      claps = 0;
      return auxClaps;
    }
  }
  return 0;
}

#endif
