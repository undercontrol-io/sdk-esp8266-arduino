float data;

void setup() {
  Serial.begin(115200);   
  connectToWifi();
}

void loop() {
  readActionFromUndercontrol();                 //Get Actions triggered by Undercontrol
  data = getDataFromSensor();                   //Get Sensor Data  
  sendDataToUndercontrol(data);                 //Send Data to Undercontrol (The period is defined in UndercontrolSDK)
}
