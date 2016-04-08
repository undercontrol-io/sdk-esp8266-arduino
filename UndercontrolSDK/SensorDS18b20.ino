#if defined(SENSOR_TEMPERATURE)

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire); 

float getDataFromSensor() {         //Get Temperature
  float temp;
  char buffer[10];
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0);
  char* tempS = dtostrf(temp, 4, 1, buffer);
  return temp;
}

#endif
