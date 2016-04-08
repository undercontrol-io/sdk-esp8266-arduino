#if defined(MQTT)

WiFiClient wifiClient;
PubSubClient MQQTclient(wifiClient);
char message_buff[100];


void callback(char* topic, byte* payload, unsigned int length) {
  int i = 0;
  char message[length];
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] (lenght: ");
  Serial.print(length);
  Serial.print("): ");
  // create character buffer with ending null terminator (string)
  for(i=0; i<length; i++) {
    message_buff[i] = payload[i];
  } 
  message_buff[i] = '\0';
  Serial.println(message_buff);
  String msgString = String(message_buff); 
  condition(msgString);
}


void reconnectMQTT() {
  // Loop until we're reconnected
  while (MQQTclient.connected() == false) {           //TODO: Set number of attempts
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (MQQTclient.connect("ESP8266Client")) {       
      Serial.println("connected");
      MQQTclient.subscribe(mqttTopicSuscribe);        //resubscribe
    } else {
      Serial.print("failed, rc=");
      Serial.print(MQQTclient.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);                                    // Wait 5 seconds before retrying
    }
  }
}


void sendDataToUndercontrol(float data){
  static char outstr[15];
  long now = millis();
  if (now - lastSentMsg > period) {
    lastSentMsg = now;
    if (MQQTclient.connected() == false) {
      Serial.print("Not connected. Reconnecting");
      reconnectMQTT();
    }
    MQQTclient.loop();
    dtostrf(data,7, 3, outstr);
    Serial.print("Publishing ");
    Serial.print(outstr);
    Serial.print(" to ");
    Serial.println(mqttTopicPublish);
    MQQTclient.publish(mqttTopicPublish, outstr);
  }
}

void readMQTTTopic(){
  if (MQQTclient.connected() == false) {
      Serial.print("Not connected. Reconnecting");
      reconnectMQTT();
  }
  MQQTclient.loop();
}

void startMQTTClient(){
  MQQTclient.setServer(MQTT_SERVER, 1883);
  MQQTclient.setCallback(callback);
}

#endif
