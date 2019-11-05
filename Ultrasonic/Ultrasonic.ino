#include <Ultrasonic.h>

#define Trig 12
#define Echo 13

Ultrasonic ult(Trig, Echo);
int distance;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Pass INC as a parameter to get the distance in inches
  distance = ult.read();
  
  Serial.print("Distance in CM: ");
  Serial.println(distance);
  delay(1000);
}
