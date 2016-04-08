#if defined(SENSOR_SONAR)

void setupHCSR04(int triggerPin, int echoPin){
  pinMode(PIN_SONAR_TRIGGER, OUTPUT);
  pinMode(PIN_SONAR_ECHO, INPUT);
}

int getDataFromSensor(){          //Get Distance
  int duration = 0;
  int distance = 0;
  digitalWrite(PIN_SONAR_TRIGGER, LOW);  
  delayMicroseconds(2); 
  
  digitalWrite(PIN_SONAR_TRIGGER, HIGH);
  delayMicroseconds(10); 
  
  digitalWrite(PIN_SONAR_TRIGGER, LOW);
  duration = pulseIn(PIN_SONAR_ECHO, HIGH);
  distance = (duration/2) / 29.1;
  
  Serial.print("Sensor-Distance:");
  Serial.print(String(distance));
  Serial.println("cm");
  return distance;
}

#endif


