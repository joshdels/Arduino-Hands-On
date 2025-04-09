#include "PROXIMITY.h"
#include "Arduino.h"

PROXIMITY::PROXIMITY(int trigPin, int echoPin){
  trig = trigPin;
  echo = echoPin;

  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  thresholdDistance = 10;
}
// methods or function needs to update
void PROXIMITY::get_distance(){
  Serial.begin(9600);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the time it takes for the pulse to return to the echoPin
  long duration = pulseIn(echo, HIGH);

  // Calculate the distance in centimeters
  long distance = duration * 0.0344 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");


  // Wait a bit before the next measurement
  delay(500);
}
