#if defined(HTTP)

void sendDataToUndercontrol(float data)
{  
  long now = millis();
  if (now - lastSentMsg > period) {
    lastSentMsg = now;
    WiFiClient client;
    if (client.connect("platform.undercontrol.io", 80)) {
      String postStr = "api_key=";
      postStr += apiKey;
      postStr += "&value=";
      postStr += String(data);    
      client.print("POST ");
      client.print(POST_ADDRESS);
      client.print(" HTTP/1.1\n");
      client.print("Host: platform.undercontrol.io\n");
      client.print("Connection: close\n");
      client.print("Content-Type: application/x-www-form-urlencoded\n");
      client.print("Content-Length: ");
      client.print(postStr.length());
      client.print("\n\n");
      client.print(postStr);
      static char outstr[15];
      dtostrf(data,7, 3, outstr);
      Serial.print("Publishing ");
      Serial.print(outstr);
      Serial.println(" by HTTP");
    }
    else{
      Serial.print("Couldn't connect to HTTP Server");
    }
    client.stop();
  }
}

#endif

