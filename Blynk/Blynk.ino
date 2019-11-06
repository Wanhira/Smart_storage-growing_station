#define BLYNK_PRINT Serial

#include <SoftwareSerial.h>
SoftwareSerial SwSerial(10, 11); // RX, TX
#include <BlynkSimpleSerialBLE.h>
#include <SoftwareSerial.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "2KIZLM2SbzlKLzlOJg_PlhJkzcXMwqak";

SoftwareSerial SerialBLE(10, 11); // RX, TX

void setup()
{
  // Debug console
  Serial.begin(9600);
  SerialBLE.begin(9600);
  Blynk.begin(SerialBLE, auth);

  Serial.println("Waiting for connections...");
}

void loop()
{
  Blynk.run();

}
