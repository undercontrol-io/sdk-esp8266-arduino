# sdk-esp8266-arduinof

This SDK allows users to easily connect their devices to the Undercontrol Platform.

To use it:

1.- Set you API Key (Register and create a Thing in http://undercontrol.io and set the time between sending measurements.

<div class="highlight highlight-source-c++"><pre><span class="pl-en">
const char* apiKey = "you_api_key";
const int period = 5000;
</pre></div>


2- Uncomment the application you will use in the file UndercontrolSDK.ino. So far we have these:
<div class="highlight highlight-source-c++"><pre><span class="pl-en">
//#define ACTUATOR_RELAY          
//#define SENSOR_SONAR            
//#define SENSOR_TEMPERATURE      
//#define SENSOR_CLAP  
</pre></div>


3- Uncomment the protocol you want to use in the file UndercontrolSDK.ino.
<div class="highlight highlight-source-c++"><pre><span class="pl-en">
//#define HTTP
//#define MQTT
</pre></div>


4- Wire the circuit. Some examples:

-DS18b20: http://undercontrol.io/ds18b20-temperature-sensor/

  
