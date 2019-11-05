#include "DHT.h"

#define DHTPIN 3
#define DHTTYPE DHT11
DHT dht11(DHTPIN, DHTTYPE);


void setup() {
Serial.begin(9600);
dht11.begin();
}

void loop() { 
  delay(2000);
  float h = dht11.readHumidity();
  float t = dht11.readTemperature();
  if(isnan(h)|| isnan(t)) {
  Serial.println ("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.println(" %\t\t");
  
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C\n");

  }
