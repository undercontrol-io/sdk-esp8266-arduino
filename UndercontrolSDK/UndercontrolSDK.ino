/**************************************************************************************************************************
 * Undercontrol.io ESP8266 SDK © Copyright www.undercontrol.io
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 *
 * IDE download    : https://www.arduino.cc/en/Main/Software
 * ESP8266 Package : https://github.com/esp8266/Arduino
 *
 * Source Code     : https://github.com/undercontrol-io/sdk-esp8266-arduino
 * Support         : 
 *
/*************************************************************************************************************************/
// Application
/*************************************************************************************************************************/
//***Set your API Key and time between each time data is sended to Undercontrol
const char* apiKey = "crbGyesxwvHcl4gIGX8io011mik";
const int period = 500;
//***Turn off for disabling Serial messages
#define DEBUG true                //Flag to turn on/off debugging
/*************************************************************************************************************************/
//***Uncomment the application you are using
//#define ACTUATOR_RELAY    
#define ACTUATOR_RGB_LED      

//#define SENSOR_SONAR            
//#define SENSOR_TEMPERATURE      
//#define SENSOR_CLAP             
/*************************************************************************************************************************/
//***Uncomment the protocol you want to use
//#define HTTP
#define MQTT

/*************************************************************************************************************************/
//  Libraries
/*************************************************************************************************************************/
#include <ESP8266WiFi.h>
#include <DNSServer.h>            //Local DNS Server used for redirecting all requests to the configuration portal
#include <ESP8266WebServer.h>     //Local WebServer used to serve the configuration portal
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager WiFi Configuration Magic
#include <PubSubClient.h>
#include <ArduinoJson.h>

/*************************************************************************************************************************/
//  Parameters
/*************************************************************************************************************************/
#define Serial if(DEBUG)Serial 
#define POST_ADDRESS  "/api/v1/things/measurements HTTP/1.1"
const char* MQTT_SERVER = "mqtt.undercontrol.io";
const char* MQTT_TOPIC_PUBLISH_SENSOR = "sensors/";
const char* MQTT_TOPIC_SUBSCRIBE_STATE = "states/";
char mqttTopicPublish[40];
char mqttTopicSuscribe[40];

/*************************************************************************************************************************/
//  Pin definition
/*************************************************************************************************************************/
//Inputs:
#if defined(ACTUATOR_RELAY)
  #define PIN_RELAY               2
#endif

#if defined(ACTUATOR_RGB_LED)
  #define PIN_RED                 12
  #define PIN_GREEN               13
  #define PIN_BLUE                14
#endif


#if defined(SENSOR_SONAR)
  #define PIN_SONAR_TRIGGER       2
#endif

//Outputs:
#if defined(SENSOR_TEMPERATURE)
  #define ONE_WIRE_BUS            0
#endif

#if defined(SENSOR_CLAP)
  #define PIN_CLAP                0
#endif

#if defined(ACTUATOR_RELAY)
  #define PIN_SONAR_ECHO          0
#endif

/*************************************************************************************************************************/
//  Variables
/*************************************************************************************************************************/
long lastSentMsg = 0;
char msg[50];
int value = 0;

/*************************************************************************************************************************/
//  Miscelaneous Functions
/*************************************************************************************************************************/
void condition(String message);
void startMQTTClient(void);
void setAPIKey(void);

const char* parseJson(String message, char* requiredObject){
  StaticJsonBuffer<200> jsonBuffer;
  JsonObject& root = jsonBuffer.parseObject(message);
  const char* object = root[requiredObject];
  return object;
}

/*************************************************************************************************************************/
//  Connectivity Functions
/*************************************************************************************************************************/
void connectToWifi(){
  setAPIKey();
  WiFiManager wifiManager;
  wifiManager.autoConnect("Undercontrol Setup");          //Generate Hotspot to setup WiFi credentials
  #if defined(MQTT)
    startMQTTClient();
  #endif
  
}

void setAPIKey()
{
  strcpy(mqttTopicPublish,MQTT_TOPIC_PUBLISH_SENSOR);
  strcat(mqttTopicPublish,apiKey);
  strcpy(mqttTopicSuscribe,MQTT_TOPIC_SUBSCRIBE_STATE);
  strcat(mqttTopicSuscribe,apiKey);
}

String getAPIKey()
{
  return apiKey;
}
