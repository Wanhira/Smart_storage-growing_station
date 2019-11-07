#define BLYNK_PRINT Serial
#include <BlynkSimpleSerialBLE.h>

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX

#include <MQUnifiedsensor.h>

#include <SoftwareSerial.h>

#define pin A0 //MQ6
#define type 6 //MQ6

char auth[] = "2KIZLM2SbzlKLzlOJg_PlhJkzcXMwqak";
BlynkTimer timer;
float CO;

SoftwareSerial SerialBLE(10, 11); // RX, TX

MQUnifiedsensor MQ6(pin, type);

void checkGaz()
{
  Blynk.virtualWrite(V1, millis() / 1000);
}

void setup()
{

  Serial.begin(9600);
 
  MQ6.inicializar();
 
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();
  timer.run();
  
  MQ6.update();
  CO =  MQ6.readSensor("CO");
  Serial.print("CO: "); Serial.print(CO, 2); Serial.println(" ppm");
  
  if (CO > 850) {
    int z = 1;
    Blynk.virtualWrite(V0, z);
  }
}
