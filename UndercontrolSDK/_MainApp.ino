float data;

void setup() {
  #if defined(ACTUATOR_RGB_LED)
  pinMode(PIN_RED,OUTPUT);
  pinMode(PIN_GREEN,OUTPUT);
  pinMode(PIN_BLUE,OUTPUT);
  #endif
  Serial.begin(115200);   
  connectToWifi();
}

void loop() {
  #if defined(ACTUATOR)
    readActionFromUndercontrol();                 //Get Actions triggered by Undercontrol
  #endif
 // data = getDataFromSensor();                   //Get Sensor Data  
  //data = random(20,30);
  //sendDataToUndercontrol(data);                 //Send Data to Undercontrol (The period is defined in UndercontrolSDK)
}
