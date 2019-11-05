#include <MQUnifiedsensor.h>

#define pin A0 //Analog input 0 of your arduino
#define type 2 //MQ2
//#define calibration_button 13 //Pin to calibrate your sensor

//Declare Sensor
MQUnifiedsensor MQ2(pin, type);

//Variables
float H2, LPG, CO, Alcohol, Propane, Benzene;

void setup() {
  Serial.begin(9600); //Init serial port
  
  //init the sensor
  MQ2.inicializar(); 
  //pinMode(calibration_button, INPUT);
}

  void loop() {
  MQ2.update(); // Update data, the arduino will be read the voltaje in the analog pin
   //Read the sensor and print in serial port
  //Lecture will be saved in lecture variable
  //float lecture =  MQ2.readSensor("", true); // Return LPG concentration
  // Options, uncomment where you need
  H2 =  MQ2.readSensor("H2"); // Return H2 concentration
  LPG =  MQ2.readSensor("LPG"); // Return LPG concentration
  CO =  MQ2.readSensor("CO"); // Return CO concentration
  Alcohol =  MQ2.readSensor("Alcohol"); // Return Alcohol concentration
  Propane =  MQ2.readSensor("Propane"); // Return Propane concentration
   
  Serial.print("H2: ");Serial.print(H2,2);Serial.println(" ppm");
  Serial.print("CO: ");Serial.print(CO,2);Serial.println(" ppm");
  Serial.print("Propane: ");Serial.print(Propane,2);Serial.println(" ppm");
}
