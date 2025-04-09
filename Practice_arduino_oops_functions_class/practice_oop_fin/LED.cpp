#include "LED.h"
#include "Arduino.h"

// Constructin of blueprint and inialization
LED::LED(int ledPin) {
  pin = ledPin;
  pinMode(pin, OUTPUT);
}

// FUNCTIONS 
void LED::led_on(){
  digitalWrite(pin, HIGH);
  delay(1000);
  digitalWrite(pin, LOW);
}

void LED::led_blinking() {
  int i = 0;
  while (i < 10) { 
      digitalWrite(pin, HIGH);
      delay(100);
      digitalWrite(pin, LOW);
      delay(100);
      i++;  
  }
}