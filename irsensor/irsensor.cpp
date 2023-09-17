#include <ESP8266WiFi.h>

const int irSensorPin = D1;               // IR sensor input pin
const int threshold = 800;                // Adjust this threshold based on IR sensor and parking setup

bool isParkingOccupied = false;

/*
void setup() {
  Serial.begin(115200);
  pinMode(irSensorPin, INPUT);
}
*/

void irsensor() {
   // Read IR sensor value
  int irSensorValue = analogRead(irSensorPin);
  
  // Update parking status
  if (irSensorValue < threshold) {
    isParkingOccupied = true;
  } else {
    isParkingOccupied = false;
  }
  
  delay(1000); // Adjust the delay as needed
}

/*
void loop() {
  irsensor()
}
*/
