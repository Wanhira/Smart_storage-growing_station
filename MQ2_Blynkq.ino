#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>

#include <SoftwareSerial.h>
//SoftwareSerial SwSerial(10, 11); // RX, TX
SoftwareSerial SerialBLE(10, 11); // RX, TX

#include <TroykaMQ.h>

#define pinMQ A0 //MQ6
MQ6 mq6(pinMQ);


char auth[] = "2KIZLM2SbzlKLzlOJg_PlhJkzcXMwqak";


void setup()
{

  Serial.begin(9600);

  mq6.calibrate();
  Serial.print("Ro = ");
  Serial.println(mq6.getRo());

  SerialBLE.begin(9600);

  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();

  Serial.print(mq6.readRatio());
  // выводим значения газов в ppm
  Serial.print(" LPG: ");
  Serial.print(mq6.readLPG()); //Бутан и пропан
  Serial.println(" ppm ");

  if (mq6.readLPG() > 650) {
    int z = 1;
    Blynk.virtualWrite(V0, z);
  }
}
