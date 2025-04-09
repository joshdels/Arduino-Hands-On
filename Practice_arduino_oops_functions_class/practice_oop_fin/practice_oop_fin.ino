#include "LED.h"

//Create blueprints
LED led1(13);
LED led2(12);
LED led3(11);
LED sound(10);

void setup() {

}

void loop() {
  led1.led_blinking();
  led2.led_blinking();
  sound.led_blinking();
}
