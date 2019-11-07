
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
#define servoPin 12
Servo myservo;

#include <SoftwareSerial.h>
SoftwareSerial SerialBLE(10, 11); // RX, TX


char auth[] = "2KIZLM2SbzlKLzlOJg_PlhJkzcXMwqak";

BlynkTimer timer;

BLYNK_READ(V2) {
  float t = dht.readTemperature();
  float h = dht.readHumidity();
  if (isnan(t) || isnan(h)) {
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
  
  Blynk.virtualWrite (V2, t);
}

void setup()
{
  // Debug console
  Serial.begin(9600);
  pinMode(servoPin, OUTPUT);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  myservo.attach(servoPin);
  dht.begin();
}

void loop()
{
  while (!Blynk.connected()) {
    delay(500);
    Blynk.connect();
    digitalWrite(13, LOW);
  }
  Blynk.run();
  timer.run(); // Initiates BlynkTimer
}
