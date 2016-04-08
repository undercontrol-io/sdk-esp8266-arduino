# sdk-esp8266-arduinof

This SDK allows users to easily connect their devices to the Undercontrol Platform.

To use it:

1.- Set you API Key (Register and create a Thing in http://undercontrol.io and set the time between sending measurements.
const char* apiKey = "you_api_key";
const int period = 5000;

2- Uncomment the application you will use in the file UndercontrolSDK.ino. So far we have these:
//#define ACTUATOR_RELAY          
//#define SENSOR_SONAR            
//#define SENSOR_TEMPERATURE      
//#define SENSOR_CLAP  

3- Uncomment the protocol you want to use in the file UndercontrolSDK.ino.
//#define HTTP
//#define MQTT

  
