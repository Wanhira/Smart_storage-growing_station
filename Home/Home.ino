#include "DHT.h"
#include <Ultrasonic.h>
#include <MQUnifiedsensor.h>
#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>
#include <Servo.h>
Servo myservo;

#define DHTPIN 2
#define DHTTYPE DHT22
#define pin A0 //MQ2
#define type 2 //MQ2
#define Trig 12
#define Echo 13
#define BLYNK_PRINT Serial
char auth[] = "2KIZLM2SbzlKLzlOJg_PlhJkzcXMwqak";
SoftwareSerial SerialBLE(10, 11); // RX, TX

DHT dht(DHTPIN, DHTTYPE);
Ultrasonic ult(echoPin, trigPin);
MQUnifiedsensor MQ2(pin, type);
int distance;
float CO;
int pos = 0;    // variable to store the servo position
int servoPin = 9;
float t = dht.readTemperature();
float h = dht.readHumidity();

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  dht.begin();
  MQ2.inicializar();
  myservo.attach(servoPin);

  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");

}

void loop() {
  void Oneroom(){
  Blynk.run();
  if (isnan(t)) {                                                  // овощи + окно
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  for (t > 25, pos <= 180, pos += 10) {
    myservo.write(pos);
    delay(15);
  }
  for (t < 30; pos >= 0; pos -= 10) {
    myservo.write(pos);
    delay(15);
  }
  MQ2.update();
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");

  

}
}
}
