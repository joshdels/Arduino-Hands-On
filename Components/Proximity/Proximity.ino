#include "PROXIMITY.h"

// //  PINS //
// //Proximity
// #define trig_pin 47
// #define echo_pin 46

const int trigPin = 13;
const int echoPin = 12;

PROXIMITY proximity(trigPin, echoPin);

void setup() {
  // put your setup code here, to run once:
  // Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  proximity.get_distance();
}