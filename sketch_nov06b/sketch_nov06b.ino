#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>

//DHT
#include "DHT.h"
#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int pos = 0;

//Servo
#include <Servo.h>
#define servoPin 9
Servo myservo;

#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(10, 11); // RX, TX


char auth[] = "GtPnvmT66tRPHdKDjzq_gZLz4MYoyKp7";

BlynkTimer timer;

void checkTemp()
{
  // You can send any value at any time.
  // Please don't send more that 10 values per second.
  Blynk.virtualWrite(V1, millis() / 1000);
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");

  timer.setInterval(3000L, checkTemp);
  myservo.attach(servoPin);
  dht.begin();

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  if (t > 28) {
    pos = 90;
    myservo.write(pos);
  }
  if (t < 28) {
    pos = 0;
    myservo.write(pos);
  }
  Serial.println(t);
}
